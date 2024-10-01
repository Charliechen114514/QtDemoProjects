#ifndef SYSTEM_INFOLINUXIMPL_H
#define SYSTEM_INFOLINUXIMPL_H
#include "System_InfoImpl.h"
#include <QByteArray>

class System_InfoLinuxImpl : public System_InfoImpl
{
public:
    System_InfoLinuxImpl();
    Q_DISABLE_COPY(System_InfoLinuxImpl)
    virtual ~System_InfoLinuxImpl() = default;
    // Impls
    void   _initWork() override;
    double _cpuLoadAverage() override;
    double _memoryUsed() override;


private:
    struct LinuxTools{
        static QByteArray fromLinuxStatFile();
    };


    struct Labels {
        enum class Label { IDLE = 0, KERN = 1, USER = 2, USER_NICE = 3, SIZE };
        static constexpr short to_index(Label l) {
            return static_cast<short>(l);
        }
    };
    void _refreshCPURawData();
    std::array<qulonglong, static_cast<short>(Labels::Label::SIZE)>
        currentCPULoad;


};

#endif // SYSTEM_INFOLINUXIMPL_H
