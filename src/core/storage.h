#ifndef STORAGE_H
#define STORAGE_H

#include <QObject>
#include <QString>

class Storage
{
public:
    Storage();
    Storage(const QString &storagePath);

    QString storagePath() const;

public:
    QString m_storagePath;
};

Q_DECLARE_METATYPE(Storage)

#endif // STORAGE_H
