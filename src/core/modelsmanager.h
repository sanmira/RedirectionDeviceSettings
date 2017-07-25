#ifndef MAINMODEL_H
#define MAINMODEL_H

#include <QQmlApplicationEngine>
#include <QString>
#include <QStringList>
#include <QByteArray>
#include <QQmlContext>
#include <QVariant>

#include <QDebug>

#include "sublistmodel.h"
#include "storagelistmodel.h"

class ModelsManager : public QObject
{
    Q_OBJECT
public:
    static ModelsManager &instance();

private:
    explicit ModelsManager(QObject* parent = 0);
//data
    SubListModel subscribersList;
    StorageListModel storagesList;

signals:
    void clear_subscribers_list();
    void clear_storages_list();

    void add_new_subscriber(const Subscriber &subscriber);
    void add_new_storage(const Storage &storage);

    void remove_last_subscriber();

public: //data slots
    void initialize_models();

    SubListModel* get_sublist_model();
    StorageListModel* get_storagelist_model();
    Subscriber get_subscriber(int number);
    int  get_subscribers_count();

    Storage get_storage(int number);
    int  get_storages_count();
};

#endif // MAINMODEL_H
