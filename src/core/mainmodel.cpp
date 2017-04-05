#include "mainmodel.h"
#include "windowsmanager.h"

MainModel::MainModel(QObject *parent) : QObject(parent)
{
    qRegisterMetaType<Subscriber>();

    WindowsManager::setContextProperty("subListModel", QVariant::fromValue(&subscriberList));
    WindowsManager::setContextProperty("servInfo", QVariant::fromValue(&servInfo));
}

void MainModel::add_new_subscriber(const Subscriber &subscriber)
{
    subscriberList.addSubscriber(subscriber);
}

Subscriber MainModel::getSubscriber(int number)
{
    return subscriberList.getSubscriber(number);
}

int MainModel::getSubscribersCount()
{
    return subscriberList.getSubCount();
}

void MainModel::remove_last_subscriber()
{
    subscriberList.removeLastSub();
}

void MainModel::clear_subscribers_list()
{
    subscriberList.clearList();
}
