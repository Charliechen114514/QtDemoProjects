#ifndef SYSTEM_INFO_H
#define SYSTEM_INFO_H
#include <QtClassHelperMacros>  // Q_DISABLE_COPY

class System_InfoImpl;

class System_Info {
public:
    System_Info();
    Q_DISABLE_COPY(System_Info);
    ~System_Info();
    // Functions
    double cpuLoadAverage();
    double memoryUsed();

private:
    void             createAccordingPlatform();
    System_InfoImpl* impl;
};

#endif  // SYSTEM_INFO_H
