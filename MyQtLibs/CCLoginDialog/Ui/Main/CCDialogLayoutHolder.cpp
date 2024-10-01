#include "CCDialogLayoutHolder.h"
#include "LoginButtons/CCLoginDialogButtons.h"

CCDialogDefaultLayoutHolder::CCDialogDefaultLayoutHolder() {
    _doInit();
}

void CCDialogDefaultLayoutHolder::_doInit() {
    _managed_layout = std::make_unique<QVBoxLayout>();
}

void CCDialogDefaultLayoutHolder::addWidget(QWidget* items) {
    _managed_layout->addWidget(items);
}

void CCDialogDefaultLayoutHolder::removeItem(QLayoutItem* item) {
    _managed_layout->removeItem(item);
}

void CCDialogDefaultLayoutHolder::addItem(QLayoutItem* item) {
    _managed_layout->addItem(item);
}

void CCDialogDefaultLayoutHolder::removeWidget(QWidget* items) {
    _managed_layout->removeWidget(items);
}

void CCDialogDefaultLayoutHolder::setAuthenticButtons(
    CCLoginDialogButtons* buttons) {
    _managed_buttons = buttons;
}

QLayout* CCDialogDefaultLayoutHolder::returnManagedLayOut() {
    if (_managed_buttons) _managed_layout->addWidget(_managed_buttons);
    return _managed_layout.get();
}
