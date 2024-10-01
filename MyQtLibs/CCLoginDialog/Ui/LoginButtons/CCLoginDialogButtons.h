#ifndef CCLOGINDIALOGBUTTONS_H
#define CCLOGINDIALOGBUTTONS_H

#include <QWidget>

namespace Ui {
class CCLoginDialogButtons;
}

class CCLoginDialogButtons : public QWidget {
    Q_OBJECT

public:
    explicit CCLoginDialogButtons(QWidget *parent = nullptr);
    ~CCLoginDialogButtons();
signals:
    void resumeBack();
    void do_authentics();

private slots:
    void on_btn_back_clicked();

    void on_btn_authentics_clicked();

private:
    Ui::CCLoginDialogButtons *ui;
};

#endif  // CCLOGINDIALOGBUTTONS_H
