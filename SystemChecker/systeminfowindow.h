#ifndef SYSTEMINFOWINDOW_H
#define SYSTEMINFOWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class SystemInfoWindow;
}
QT_END_NAMESPACE

class SystemInfoWindow : public QMainWindow {
    Q_OBJECT

public:
    SystemInfoWindow(QWidget *parent = nullptr);
    ~SystemInfoWindow();

private:
    Ui::SystemInfoWindow *ui;
};
#endif  // SYSTEMINFOWINDOW_H
