#include "src/core/storagelistmodel.h"

StorageListModel::StorageListModel(QObject *parent) : QAbstractListModel(parent)
{
    qRegisterMetaType<Storage>();
}

void StorageListModel::add_storage(const Storage &storage)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    storagesList << storage;
    endInsertRows();
}

Storage StorageListModel::get_storage(int number)
{
    return storagesList.at(number);
}

int StorageListModel::get_storages_count()
{
    return storagesList.count();
}

void StorageListModel::clear_list()
{
    beginResetModel();
    storagesList.clear();
    endResetModel();
}

int StorageListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return storagesList.count();
}

QVariant StorageListModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= storagesList.count())
        return QVariant();
    const Storage &storage = storagesList[index.row()];
    if (role == StoragePath)
        return storage.storagePath();
    return QVariant();
}

bool StorageListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    Storage &storage = storagesList[index.row()];
    if (role == StoragePath)
    {
        storage.m_storagePath = value.toString();
        return true;
    }
    return false;
}

QHash<int, QByteArray> StorageListModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[StoragePath] = "storagePath";
    return roles;
}
