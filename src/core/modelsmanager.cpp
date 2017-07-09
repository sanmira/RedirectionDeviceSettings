#include "modelsmanager.h"

ModelsManager::ModelsManager(QObject *parent) : QObject(parent)
{
    qRegisterMetaType<Subscriber>();
    qRegisterMetaType<Storage>();
}

void ModelsManager::add_new_subscriber(const Subscriber &subscriber)
{
    subscribersList.addSubscriber(subscriber);
}

void ModelsManager::remove_last_subscriber()
{
    subscribersList.removeLastSub();
}

Subscriber ModelsManager::getSubscriber(int number)
{
    return subscribersList.getSubscriber(number);
}

int ModelsManager::getSubscribersCount()
{
    return subscribersList.getSubCount();
}

void ModelsManager::clear_subscribers_list()
{
    subscribersList.clearList();
}

void ModelsManager::add_new_storage(const Storage &storage)
{
    storagesList.addStorage(storage);
}

Storage ModelsManager::getStorage(int number)
{
    return storagesList.getStorage(number);
}

int ModelsManager::getStoragesCount()
{
    return storagesList.getStoragesCount();
}

void ModelsManager::clear_storages_list()
{
    storagesList.clearList();
}

