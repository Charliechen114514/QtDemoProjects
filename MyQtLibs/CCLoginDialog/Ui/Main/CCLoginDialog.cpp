#include "CCLoginDialog.h"
#include <QMessageBox>
#include "./ui_CCLoginDialog.h"
#include "CCDialogLayoutHolder.h"
#include "LoginButtons/CCLoginDialogButtons.h"
#include "LoginDialogDataValidatorManager/CCLoginDialogDataValidatorManager.h"
#include "LoginItem/CCLoginDialogItem.h"
CCLoginDialog::CCLoginDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::CCLoginDialog) {
    ui->setupUi(this);
    doInit();
}

void CCLoginDialog::doInit() {
    manager      = std::make_shared<CCLoginDialogDataValidatorManager>();
    layoutHolder = std::make_shared<CCDialogDefaultLayoutHolder>();
    _buttons     = std::make_shared<CCLoginDialogButtons>();
    layoutHolder->setAuthenticButtons(_buttons.get());

    connect(_buttons.get(), &CCLoginDialogButtons::do_authentics, this,
            &CCLoginDialog::handle_authentics);
    connect(_buttons.get(), &CCLoginDialogButtons::resumeBack, this,
            &CCLoginDialog::resumeBack);
}

void CCLoginDialog::addItem(const QString &label) {
    auto items = std::make_shared<CCLoginDialogItem>();
    items->setLabelText(label);
    _loginItems.emplaceBack(items);
    _addItemImpl(items.get());
}

void CCLoginDialog::addItem(CCLoginDialogItem *item) {
    _loginItems.emplaceBack(item);
    _addItemImpl(item);
}

void CCLoginDialog::addRestrictedItem(const QString &label, ValidationFunctor f,
                                      const QString tips) {
    auto items = std::make_shared<CCLoginDialogItem>();
    items->setLabelText(label);
    _loginItems.emplaceBack(items);
    _addItemRestrictedImpl(items.get(), f, tips);
}

void CCLoginDialog::addRestrictedItem(CCLoginDialogItem *item,
                                      ValidationFunctor f, const QString tips) {
    _loginItems.emplaceBack(item);
    _addItemRestrictedImpl(item, f, tips);
}

void CCLoginDialog::_addItemImpl(CCLoginDialogItem *item) {
    layoutHolder->addWidget(item);
}

void CCLoginDialog::_addItemRestrictedImpl(CCLoginDialogItem *item,
                                           ValidationFunctor &f,
                                           const QString     &tips) {
    layoutHolder->addWidget(item);
    auto validators = std::make_shared<CCLoginDialogDataValidator>(f);
    validators->setTips(tips);
    _storage_of_validators.emplaceBack(validators);
    manager->installPair(item, validators.get());
}

void CCLoginDialog::initializeUi() {
    this->setLayout(layoutHolder->returnManagedLayOut());
}

void CCLoginDialog::handle_authentics() {
    auto res = manager->validate_all();
    if (res.empty()) {
        emit authentic_success();
        qDebug() << "登录成功";
        return;
    } else {
        emit authentic_failed();
        tell_faileds_authentics(res);
    }
}

void CCLoginDialog::tell_faileds_authentics(
    const QList<CCLoginDialogItem *> &failes) {
    QString warnings = "无法登录: \n";
    for (const auto &each : failes) {
        auto validations = manager->value(each);
        warnings += validations->getTips() + "\n";
    }
    QMessageBox::warning(this, "登陆失败！", warnings);
}

CCLoginDialog::~CCLoginDialog() {
    delete ui;
}
