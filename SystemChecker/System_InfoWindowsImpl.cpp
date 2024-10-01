#include "System_InfoWindowsImpl.h"
#include <Windows.h>
System_InfoWindowsImpl::System_InfoWindowsImpl() : System_InfoImpl() {
}

qulonglong System_InfoWindowsImpl::WindowsTools::fromWindowsFileTime(
    const FILETIME& fileTime) {
    ULARGE_INTEGER integer;
    integer.LowPart  = fileTime.dwLowDateTime;
    integer.HighPart = fileTime.dwHighDateTime;
    return integer.QuadPart;
}

void System_InfoWindowsImpl::_initWork() {
    _refreshCPURawData();
}

void System_InfoWindowsImpl::_refreshCPURawData() {
    FILETIME idle, kernel, user;
    ::GetSystemTimes(&idle, &kernel, &user);
    currentCPULoad[Labels::to_index(Labels::Label::IDLE)] =
        WindowsTools::fromWindowsFileTime(idle);

    currentCPULoad[Labels::to_index(Labels::Label::KERN)] =
        WindowsTools::fromWindowsFileTime(kernel);

    currentCPULoad[Labels::to_index(Labels::Label::USER)] =
        WindowsTools::fromWindowsFileTime(user);
}

double System_InfoWindowsImpl::_cpuLoadAverage() {
    std::array<qulonglong, static_cast<short>(Labels::Label::SIZE)> previous =
        currentCPULoad;
    _refreshCPURawData();
#define FAST_CALC(var_name, LABEL_NAME)                               \
    qulonglong var_name =                                             \
        currentCPULoad[Labels::to_index(Labels::Label::LABEL_NAME)] - \
        previous[Labels::to_index(Labels::Label::LABEL_NAME)]
    FAST_CALC(cur_idle, IDLE);
    FAST_CALC(cur_kern, KERN);
    FAST_CALC(cur_user, USER);
#undef FAST_CALC
    qulonglong systems = cur_kern + cur_user;

    double percentage = (systems - cur_idle) * 100.0 / (double)systems;
    return qBound(0.0, percentage, 100.0);
}

double System_InfoWindowsImpl::_memoryUsed() {
    MEMORYSTATUSEX mem;
    mem.dwLength = sizeof(MEMORYSTATUSEX);
    GlobalMemoryStatusEx(&mem);
    return (mem.ullTotalPhys - mem.ullAvailPhys) * 100.0 / mem.ullTotalPhys;
}
