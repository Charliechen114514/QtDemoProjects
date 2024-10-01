#ifndef MOUSETRACKER_H
#define MOUSETRACKER_H
#include <QMouseEvent>
#include <QPoint>
#include <QtClassHelperMacros>

class MouseTracker {
public:
    using StateTemplate = std::function<QString(const QStringList&)>;
    MouseTracker()      = default;
    Q_DISABLE_COPY(MouseTracker);
    void                           gainMouseState(QMouseEvent* env);
    std::optional<QPoint>          mousePoint() const;
    std::optional<Qt::MouseButton> mouseButton() const;
    QString                        stateString() const;

private:
    QMouseEvent*  env  = nullptr;
    StateTemplate temp = [](const QStringList& l) -> QString {
        return l.size() == 2 ? QString("%1, %2").arg(l.at(0)).arg(l.at(1))
                             : QString();
    };
    static constexpr const char* NO_TRACKING = "No Tracking Mouse!";
};

#endif  // MOUSETRACKER_H
