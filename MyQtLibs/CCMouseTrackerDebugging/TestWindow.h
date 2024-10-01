#ifndef TESTWINDOW_H
#define TESTWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class TestWindow;
}
QT_END_NAMESPACE
class MouseTracker;

class TestWindow : public QMainWindow {
    Q_OBJECT

public:
    TestWindow(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *env) override;
    void mouseMoveEvent(QMouseEvent *env) override;
    ~TestWindow();

private:
    Ui::TestWindow               *ui;
    std::shared_ptr<MouseTracker> tracker;
};
#endif  // TESTWINDOW_H
