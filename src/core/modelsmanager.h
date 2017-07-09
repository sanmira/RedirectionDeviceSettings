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
    ModelsManager(QObject* parent = 0);

public: //data
    SubListModel subscribersList;
    StorageListModel storagesList;

public slots: //data slots
    Subscriber getSubscriber(int number);
    void add_new_subscriber(const Subscriber &subscriber);
    void remove_last_subscriber();
    int  getSubscribersCount();
    void clear_subscribers_list();

    Storage getStorage(int number);
    void add_new_storage(const Storage &storage);
    int  getStoragesCount();
    void clear_storages_list();
};

#endif // MAINMODEL_H
