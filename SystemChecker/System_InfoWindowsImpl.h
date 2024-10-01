#ifndef SYSTEM_INFOWINDOWSIMPL_H
#define SYSTEM_INFOWINDOWSIMPL_H
#include <QList>
#include <array>
#include "System_InfoImpl.h"

using FILETIME = struct _FILETIME;

class System_InfoWindowsImpl : public System_InfoImpl {
public:
    System_InfoWindowsImpl();
    Q_DISABLE_COPY(System_InfoWindowsImpl);
    ~System_InfoWindowsImpl() = default;

    // Impls
    void   _initWork() override;
    double _cpuLoadAverage() override;
    double _memoryUsed() override;

    struct WindowsTools {
        static qulonglong fromWindowsFileTime(const FILETIME& fileTime);
    };

private:
    struct Labels {
        enum class Label { IDLE = 0, KERN = 1, USER = 2, SIZE };
        static constexpr short to_index(Label l) {
            return static_cast<short>(l);
        }
    };
    void _refreshCPURawData();
    std::array<qulonglong, static_cast<short>(Labels::Label::SIZE)>
        currentCPULoad;
};

#endif  // SYSTEM_INFOWINDOWSIMPL_H
