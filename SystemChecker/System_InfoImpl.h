#ifndef SYSTEM_INFOIMPL_H
#define SYSTEM_INFOIMPL_H

#include <QtClassHelperMacros>

/*
    The Actual Action class
    All Bases For Every Possible Operating
    System
*/
class System_InfoImpl {
public:
    System_InfoImpl() = default;
    Q_DISABLE_COPY(System_InfoImpl);
    virtual ~System_InfoImpl() = default;
    // Impl Interfaces
    virtual void   _initWork()       = 0;
    virtual double _cpuLoadAverage() = 0;
    virtual double _memoryUsed()     = 0;
};

#endif  // SYSTEM_INFOIMPL_H
