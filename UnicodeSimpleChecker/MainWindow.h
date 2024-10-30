#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT
    struct FormatFactory {
        static QString fromFormatChar(const QChar& each) {
            uint16_t unicode = each.unicode();
            return QString("字符: %1, Unicode: %2")
                .arg(each)
                .arg(QString::asprintf("0x%X\n", unicode));
        }
        static QString fromForamtString(const QString& wait) {
            QString res;
            for (const auto& each : wait) {
                res += fromFormatChar(each);
            }
            return res;
        }
    };

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

signals:
    void tellStringUpdate();
    void tellCharCheck();
    // private slots:

private:
    void            updateCharStatus(const QChar& checkee);
    void            updateStringCode(const QString& str);
    void            _handleConnections();
    Ui::MainWindow* ui;
};
#endif  // MAINWINDOW_H
