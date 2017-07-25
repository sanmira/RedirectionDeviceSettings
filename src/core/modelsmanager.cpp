#include "modelsmanager.h"

ModelsManager::ModelsManager(QObject *parent) : QObject(parent)
{

}

SubListModel *ModelsManager::get_sublist_model()
{
    return &subscribersList;
}

StorageListModel *ModelsManager::get_storagelist_model()
{
    return &storagesList;
}

ModelsManager &ModelsManager::instance()
{
    static ModelsManager s;
    return s;
}

Subscriber ModelsManager::get_subscriber(int number)
{
    return subscribersList.get_subscriber(number);
}

int ModelsManager::get_subscribers_count()
{
    return subscribersList.get_sub_count();
}

Storage ModelsManager::get_storage(int number)
{
    return storagesList.get_storage(number);
}

int ModelsManager::get_storages_count()
{
    return storagesList.get_storages_count();
}

void ModelsManager::initialize_models()
{
    QObject::connect(this, SIGNAL(clear_subscribers_list()), &subscribersList, SLOT(clear_list()));
    QObject::connect(this, SIGNAL(clear_storages_list()), &storagesList, SLOT(clear_list()));

    QObject::connect(this, SIGNAL(add_new_subscriber(Subscriber)), &subscribersList, SLOT(add_subscriber(Subscriber)));
    QObject::connect(this, SIGNAL(add_new_storage(Storage)), &storagesList, SLOT(add_storage(Storage)));

    QObject::connect(this, SIGNAL(remove_last_subscriber()), &subscribersList, SLOT(remove_last_sub()));
}

