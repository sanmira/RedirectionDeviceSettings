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

class MainModel : public QObject
{
    Q_OBJECT
public:
    MainModel(QObject* parent = 0);

private: //data
    SubListModel subscriberList;

public slots: //data slots
    void add_new_subscriber(const Subscriber &subscriber);
    Subscriber getSubscriber(int number);
    int  getSubscribersCount();
    void remove_last_subscriber();
    void clear_subscribers_list();
};

#endif // MAINMODEL_H
