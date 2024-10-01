#include "system_infolinuximpl.h"
#include <QFile>
#include <sys/types.h>
#include <sys/sysinfo.h>

QByteArray System_InfoLinuxImpl::LinuxTools::fromLinuxStatFile(){
    QFile file("/proc/stat");
    file.open(QIODevice::ReadOnly);
    QByteArray dataLine = file.readLine();
    file.close();
    return dataLine;
}

System_InfoLinuxImpl::System_InfoLinuxImpl() : System_InfoImpl(){

}

void System_InfoLinuxImpl::_initWork(){
    _refreshCPURawData();
}

void System_InfoLinuxImpl::_refreshCPURawData(){
    QByteArray fromFile = LinuxTools::fromLinuxStatFile();
    qulonglong tol_user = 0, userNice = 0, sys = 0, idle = 0;
    std::sscanf(fromFile.data(), "cpu %llu %llu %llu %llu", &tol_user, &userNice, &sys, &idle);

#define FAST_REG(LABEL_NAME, var) \
    currentCPULoad[Labels::to_index(Labels::Label::LABEL_NAME)] = var

    FAST_REG(IDLE, idle);
    FAST_REG(USER, tol_user);
    FAST_REG(USER_NICE, userNice);
    FAST_REG(KERN, sys);

#undef FAST_REG
}

double System_InfoLinuxImpl::_cpuLoadAverage()
{
    std::array<qulonglong, static_cast<short>(Labels::Label::SIZE)> previous =
        currentCPULoad;
    _refreshCPURawData();

#define GET_TIME(LABEL_NAME) \
    currentCPULoad[Labels::to_index(Labels::Label::LABEL_NAME)] - \
        previous[Labels::to_index(Labels::Label::LABEL_NAME)]

    double overall = GET_TIME(USER) + GET_TIME(KERN) + GET_TIME(USER_NICE);
    double tol = overall + GET_TIME(IDLE);

    double per = overall * 100.0 / tol;
    return qBound(0.0, per, 100.0);
}

double System_InfoLinuxImpl::_memoryUsed()
{
    struct sysinfo meminfo;
    sysinfo(&meminfo);

    qulonglong tolMem = meminfo.totalram;
    tolMem += meminfo.totalswap;
    tolMem *= meminfo.mem_unit;

    qulonglong used = meminfo.totalram - meminfo.freeram;
    used += meminfo.totalswap - meminfo.freeswap;
    used *= meminfo.mem_unit;

    double per = used * 100.0 / tolMem;
    return qBound(0.0, per, 100.0);
}




