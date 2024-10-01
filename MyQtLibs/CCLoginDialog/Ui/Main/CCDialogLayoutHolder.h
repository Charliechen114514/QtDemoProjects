#ifndef CCDIALOGLAYOUTHOLDER_H
#define CCDIALOGLAYOUTHOLDER_H
#include <QtClassHelperMacros>

class QWidget;
class QLayout;
class QLayoutItem;
class CCLoginDialogButtons;
class CCDialogLayoutHolder {
public:
    CCDialogLayoutHolder()          = default;
    virtual ~CCDialogLayoutHolder() = default;
    Q_DISABLE_COPY(CCDialogLayoutHolder);

    virtual void     addWidget(QWidget* items)                          = 0;
    virtual void     removeWidget(QWidget* items)                       = 0;
    virtual void     addItem(QLayoutItem* item)                         = 0;
    virtual void     removeItem(QLayoutItem* item)                      = 0;
    virtual void     setAuthenticButtons(CCLoginDialogButtons* buttons) = 0;
    virtual QLayout* returnManagedLayOut()                              = 0;
};

// ---------------- Default Layout ------------------

#include <QLayout>

class CCDialogDefaultLayoutHolder : public CCDialogLayoutHolder {
public:
    CCDialogDefaultLayoutHolder();
    virtual ~CCDialogDefaultLayoutHolder() = default;
    Q_DISABLE_COPY(CCDialogDefaultLayoutHolder);

    void     addWidget(QWidget* items) override;
    void     removeWidget(QWidget* items) override;
    void     addItem(QLayoutItem* item) override;
    void     removeItem(QLayoutItem* item) override;
    QLayout* returnManagedLayOut() override;
    void     setAuthenticButtons(CCLoginDialogButtons* buttons) override;

protected:
    void                         _doInit();
    std::unique_ptr<QVBoxLayout> _managed_layout;
    CCLoginDialogButtons*        _managed_buttons{};
};

#endif  // CCDIALOGLAYOUTHOLDER_H
