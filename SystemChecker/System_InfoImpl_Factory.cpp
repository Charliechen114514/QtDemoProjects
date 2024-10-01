#include "System_InfoImpl_Factory.h"
#include <QtGlobal>
#ifdef Q_OS_WIN
#include "System_InfoWindowsImpl.h"

static System_InfoWindowsImpl* instances() {
    return new System_InfoWindowsImpl;
}

#elif defined(Q_OS_LINUX)
#include "system_infolinuximpl.h"
static System_InfoLinuxImpl* instances() {
    return new System_InfoLinuxImpl;
}
#endif

System_InfoImpl* System_InfoImpl_Factory::createImplementInstance() {
    return instances();
}
