#ifndef CCLOGINDIALOGDATAVALIDATORMANAGER_H
#define CCLOGINDIALOGDATAVALIDATORMANAGER_H
#include <QMap>
#include <QtClassHelperMacros>
class CCLoginDialogItem;
#include "CCLoginDialogDataValidator.h"

class CCLoginDialogDataValidatorManager {
public:
    CCLoginDialogDataValidatorManager() = default;
    void installPair(CCLoginDialogItem*          item,
                     CCLoginDialogDataValidator* validator);

    CCLoginDialogItem* key(CCLoginDialogDataValidator* validator) const {
        return _storage_map.key(validator, nullptr);
    }

    CCLoginDialogDataValidator* value(CCLoginDialogItem* item) const {
        return _storage_map.value(item, nullptr);
    }

    bool                      tryValidate() const;
    QList<CCLoginDialogItem*> validate_all() const;

private:
    QMap<CCLoginDialogItem*, CCLoginDialogDataValidator*> _storage_map;
};

#endif  // CCLOGINDIALOGDATAVALIDATORMANAGER_H
