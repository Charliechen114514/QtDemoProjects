#include "MouseTracker.h"

class MouseInfoFactory {
public:
    enum class StringIndex { Point, Button };

    static QString createMousePointInfo(QMouseEvent* env) {
        auto point = env->pos();
        return QString("(%1, %2)").arg(point.x()).arg(point.y());
    }
    static QString createMouseButtonInfo(QMouseEvent* env) {
        QString buttonName;
        switch (env->button()) {
            case Qt::NoButton:
                return "no button press";
                break;
            case Qt::LeftButton:
                buttonName = "LeftButton";
                break;
            case Qt::RightButton:
                buttonName = "RightButton";
                break;
            case Qt::MiddleButton:
                buttonName = "MiddleButton";
                break;
            case Qt::BackButton:
                buttonName = "BackButton";
                break;
            case Qt::ForwardButton:
                buttonName = "ForwardButton";
                break;
            case Qt::TaskButton:
                buttonName = "TaskButton";
                break;
            default:
                return "someElse button being pressed!";
                break;
        }
        return QString("with button: %1").arg(buttonName);
    }
    static QString makeFullTemplateInfo(
        QMouseEvent* env, MouseTracker::StateTemplate state_template) {
        QStringList l;
        l << createMousePointInfo(env) << createMouseButtonInfo(env);
        return state_template(l);
    }
};

void MouseTracker::gainMouseState(QMouseEvent* env) {
    this->env = env;
}

std::optional<QPoint> MouseTracker::mousePoint() const {
    auto res = std::nullopt;
    if (!env) return res;
    return {env->pos()};
}

std::optional<Qt::MouseButton> MouseTracker::mouseButton() const {
    auto res = std::nullopt;
    if (!env) return res;
    return {env->button()};
}

QString MouseTracker::stateString() const {
    if (!env) {
        return NO_TRACKING;
    }
    return MouseInfoFactory::makeFullTemplateInfo(env, temp);
}
