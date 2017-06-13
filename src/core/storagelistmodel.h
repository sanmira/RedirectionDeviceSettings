#ifndef STORAGELISTMODEL_H
#define STORAGELISTMODEL_H

#include <QObject>

class StorageListModel : public QObject
{
    Q_OBJECT
public:
    explicit StorageListModel(QObject *parent = 0);

signals:

public slots:
};

#endif // STORAGELISTMODEL_H