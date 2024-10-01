#include <QApplication>
#include "CCLoginDialog.h"

bool restrict_f(const QString& h) {
    return h == "1111";
}

int main(int argc, char* argv[]) {
    QApplication  a(argc, argv);
    CCLoginDialog w;
    w.addItem("姓名");
    w.addItem("密码");
    w.addRestrictedItem("验证码", restrict_f, "请输入1111");
    w.initializeUi();
    w.show();
    return a.exec();
}
