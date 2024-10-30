#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    _handleConnections();
}

void MainWindow::_handleConnections() {
    connect(ui->btn_show_check_res, &QPushButton::clicked, this,
            &MainWindow::tellCharCheck);
    connect(ui->btn_see_check, &QPushButton::clicked, this,
            &MainWindow::tellStringUpdate);

    connect(this, &MainWindow::tellCharCheck, [=]() {
        QString res      = ui->lineEdit_Char->text();
        QChar   checking = res[0];
        updateCharStatus(checking);
    });
    connect(this, &MainWindow::tellStringUpdate, [=]() {
        QString res = ui->lineEdit_String->text();
        updateStringCode(res);
    });

    connect(ui->btn_clear, &QPushButton::clicked,
            [=]() { ui->plainTextEdit->clear(); });
}

void MainWindow::updateCharStatus(const QChar& checkee) {
    ui->plainTextEdit->appendPlainText(FormatFactory::fromFormatChar(checkee));
    ui->chk_digit->setChecked(checkee.isDigit());
    ui->check_di_le->setChecked(checkee.isLetterOrNumber());
    ui->checkBox_punct->setChecked(checkee.isPunct());
    ui->checkBox_symbol->setChecked(checkee.isSymbol());
    ui->check_space->setChecked(checkee.isSpace());
    ui->chk_lower->setChecked(checkee.isLower());
    ui->chk_upper->setChecked(checkee.isUpper());
    ui->chk_mark->setChecked(checkee.isMark());
    ui->chk_letter->setChecked(checkee.isLetter());
}

void MainWindow::updateStringCode(const QString& str) {
    ui->plainTextEdit->appendPlainText(FormatFactory::fromForamtString(str));
}

MainWindow::~MainWindow() {
    delete ui;
}
