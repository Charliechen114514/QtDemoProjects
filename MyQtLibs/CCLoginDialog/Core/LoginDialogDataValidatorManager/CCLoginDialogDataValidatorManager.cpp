#include "CCLoginDialogDataValidatorManager.h"
#include "LoginItem/CCLoginDialogItem.h"

void CCLoginDialogDataValidatorManager::installPair(
    CCLoginDialogItem* item, CCLoginDialogDataValidator* validator) {
    _storage_map.insert(item, validator);
}

bool CCLoginDialogDataValidatorManager::tryValidate() const {
    auto it = _storage_map.constBegin();
    while (it != _storage_map.constEnd()) {
        if (!it.value()->validate_this(it.key()->getInputFromLineEdit()))
            return false;
        it++;
    }
    return true;
}

QList<CCLoginDialogItem*> CCLoginDialogDataValidatorManager::validate_all()
    const {
    QList<CCLoginDialogItem*> faults_handles;
    auto                      it = _storage_map.constBegin();
    while (it != _storage_map.constEnd()) {
        if (!it.value()->validate_this(it.key()->getInputFromLineEdit()))
            faults_handles.push_back(it.key());
        it++;
    }
    return faults_handles;
}
