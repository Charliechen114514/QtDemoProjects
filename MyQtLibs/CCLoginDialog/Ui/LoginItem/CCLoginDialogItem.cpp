#include "CCLoginDialogItem.h"
#include "ui_CCLoginDialogItem.h"

CCLoginDialogItem::CCLoginDialogItem(QWidget* parent)
    : QWidget(parent), ui(new Ui::CCLoginDialogItem) {
    ui->setupUi(this);
}

void CCLoginDialogItem::setLabelText(const QString& text) {
    ui->loginItemLabel->setText(text);
}

QString CCLoginDialogItem::labelText() const {
    return ui->loginItemLabel->text();
}

void CCLoginDialogItem::setDefaultInputValue(const QString& value) {
    ui->loginItemLineEdit->setText(value);
}

QString CCLoginDialogItem::getInputFromLineEdit() const {
    return ui->loginItemLineEdit->text();
}

void CCLoginDialogItem::setValidator(const QValidator* validator) {
    ui->loginItemLineEdit->setValidator(validator);
}

CCLoginDialogItem::~CCLoginDialogItem() {
    delete ui;
}
