#include "TestWindow.h"
#include "./ui_TestWindow.h"
#include "MouseTracker.h"
TestWindow::TestWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::TestWindow) {
    ui->setupUi(this);
    tracker = std::make_shared<MouseTracker>();
}

void TestWindow::mousePressEvent(QMouseEvent *env) {
    tracker->gainMouseState(env);
    ui->statusbar->showMessage(tracker->stateString());
}

void TestWindow::mouseMoveEvent(QMouseEvent *env) {
    tracker->gainMouseState(env);
    ui->statusbar->showMessage(tracker->stateString());
}

TestWindow::~TestWindow() {
    delete ui;
}
