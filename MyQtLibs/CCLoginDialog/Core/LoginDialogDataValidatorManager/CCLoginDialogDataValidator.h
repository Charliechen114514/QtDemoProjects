#ifndef CCLOGINDIALOGDATAVALIDATOR_H
#define CCLOGINDIALOGDATAVALIDATOR_H
#include <QString>

class CCLoginDialogDataValidator {
public:
    using ValidationFunctor      = std::function<bool(const QString&)>;
    CCLoginDialogDataValidator() = delete;
    CCLoginDialogDataValidator(ValidationFunctor f) {
        installFunctor(f);
    }
    void installFunctor(const ValidationFunctor& f) {
        functor = f;
    }
    ValidationFunctor getFunctor() const {
        return functor;
    };

    bool validate_this(const QString& value) {
        return functor(value);
    }

    void setTips(const QString& tips) {
        this->tips = tips;
    }

    QString getTips() const {
        return tips;
    }

private:
    ValidationFunctor functor;
    QString           tips{};
};
#endif  // CCLOGINDIALOGDATAVALIDATOR_H
