#include "System_Info.h"
#include "System_InfoImpl.h"
#include "System_InfoImpl_Factory.h"

System_Info::System_Info() {
    impl = System_InfoImpl_Factory::createImplementInstance();
}

double System_Info::cpuLoadAverage() {
    return impl->_cpuLoadAverage();
}

double System_Info::memoryUsed() {
    return impl->_memoryUsed();
}

System_Info::~System_Info() {
    delete impl;
}
