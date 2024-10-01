#include <QApplication>
#include "System_Info.h"
#include "systeminfowindow.h"
int main(int argc, char *argv[]) {
    // QApplication     a(argc, argv);
    // SystemInfoWindow w;
    // w.show();
    // return a.exec();

    System_Info h;
    qDebug() << h.cpuLoadAverage() << " " << h.memoryUsed();
}
