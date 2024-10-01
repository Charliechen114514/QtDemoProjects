#include "CCLoginDialogButtons.h"
#include "ui_CCLoginDialogButtons.h"

CCLoginDialogButtons::CCLoginDialogButtons(QWidget *parent)
    : QWidget(parent), ui(new Ui::CCLoginDialogButtons) {
    ui->setupUi(this);
}

CCLoginDialogButtons::~CCLoginDialogButtons() {
    delete ui;
}

void CCLoginDialogButtons::on_btn_back_clicked() {
    emit this->resumeBack();
}

void CCLoginDialogButtons::on_btn_authentics_clicked() {
    emit this->do_authentics();
}
