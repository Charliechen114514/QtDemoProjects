#ifndef CCLOGINDIALOG_H
#define CCLOGINDIALOG_H
#include <QDialog>
#include "LoginDialogDataValidatorManager/CCLoginDialogDataValidator.h"
class CCLoginDialogItem;
class CCLoginDialogButtons;
class CCLoginDialogDataValidatorManager;
class CCDialogDefaultLayoutHolder;
QT_BEGIN_NAMESPACE
namespace Ui {
class CCLoginDialog;
}
QT_END_NAMESPACE

class CCLoginDialog : public QDialog {
    Q_OBJECT

public:
    using ValidationFunctor = CCLoginDialogDataValidator::ValidationFunctor;
    CCLoginDialog(QWidget *parent = nullptr);
    void addItem(const QString &label);
    void addItem(CCLoginDialogItem *item);
    void addRestrictedItem(const QString &label, ValidationFunctor f,
                           const QString tips);
    void addRestrictedItem(CCLoginDialogItem *item, ValidationFunctor f,
                           const QString tips);
    void initializeUi();
    ~CCLoginDialog();

signals:
    void authentic_success();
    void authentic_failed();
    void resumeBack();

private:
    void doInit();
    void _addItemImpl(CCLoginDialogItem *item);
    void _addItemRestrictedImpl(CCLoginDialogItem *item, ValidationFunctor &f,
                                const QString &tips);
    void handle_authentics();
    void tell_faileds_authentics(const QList<CCLoginDialogItem *> &failes);
    Ui::CCLoginDialog                                 *ui;
    std::shared_ptr<CCLoginDialogDataValidatorManager> manager;
    std::shared_ptr<CCDialogDefaultLayoutHolder>       layoutHolder;
    QList<std::shared_ptr<CCLoginDialogDataValidator>> _storage_of_validators;
    QList<std::shared_ptr<CCLoginDialogItem>>          _loginItems;
    std::shared_ptr<CCLoginDialogButtons>              _buttons;
};
#endif  // CCLOGINDIALOG_H
