#ifndef CCLOGINDIALOGITEM_H
#define CCLOGINDIALOGITEM_H

#include <QWidget>
class QValidator;
namespace Ui {
class CCLoginDialogItem;
}

class CCLoginDialogItem : public QWidget {
    Q_OBJECT

public:
    explicit CCLoginDialogItem(QWidget *parent = nullptr);
    ~CCLoginDialogItem();
    void    setLabelText(const QString &text);
    QString labelText() const;
    void    setDefaultInputValue(const QString &value);
    QString getInputFromLineEdit() const;
    void    setValidator(const QValidator *validator);

private:
    Ui::CCLoginDialogItem *ui;
};

#endif  // CCLOGINDIALOGITEM_H
