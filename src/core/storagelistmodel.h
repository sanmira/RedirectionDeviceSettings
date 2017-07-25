#ifndef STORAGELISTMODEL_H
#define STORAGELISTMODEL_H

#include <QAbstractListModel>
#include <QList>

#include "storage.h"

class StorageListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit StorageListModel(QObject *parent = 0);

public:
    enum SubRoles {
        StoragePath
    };

    Storage get_storage(int number);
    int  get_storages_count();

public slots:
    void clear_list();
    void add_storage(const Storage &storage);

    int rowCount(const QModelIndex & parent = QModelIndex()) const;

    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
    bool     setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);

protected:
    QHash<int, QByteArray> roleNames() const;

private:
    QList<Storage> storagesList;
};

#endif // STORAGELISTMODEL_H
