#include "sublistmodel.h"

SubListModel::SubListModel(QObject *parent) : QAbstractListModel(parent)
{

}

void SubListModel::addSubscriber(const Subscriber &subscriber)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    subscriberList << subscriber;
    endInsertRows();
}

Subscriber SubListModel::getSubscriber(int number)
{
    return subscriberList.at(number);
}

int SubListModel::getSubCount()
{
    return subscriberList.count();
}

void SubListModel::removeLastSub()
{
    beginResetModel();
    subscriberList.removeLast();
    endResetModel();
}

void SubListModel::clearList()
{
    beginResetModel();
    subscriberList.clear();
    endResetModel();
}

int SubListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return subscriberList.count();
}

QVariant SubListModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= subscriberList.count())
        return QVariant();
    const Subscriber &subscriber = subscriberList[index.row()];
    if (role == FlatNumber)
        return subscriber.flatNumber();
    else if (role == IsEnabled)
        return subscriber.isEnabled();
    else if (role == TelNumber1)
        return subscriber.telNumber1();
    else if (role == TelNumber2)
        return subscriber.telNumber2();
    else if (role == TelNumber3)
        return subscriber.telNumber3();
    else if (role == TelNumber4)
        return subscriber.telNumber4();
    else if (role == TelNumber5)
        return subscriber.telNumber5();
    return QVariant();
}

bool SubListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    Subscriber &subscriber = subscriberList[index.row()];
    if (role == FlatNumber)
    {
        subscriber.m_flatNumber = value.toInt();
        return true;
    }
    else if (role == IsEnabled)
    {
        subscriber.m_isEnabled = value.toBool();
        return true;
    }
    else if (role == TelNumber1)
    {
        subscriber.m_telNumber1 = value.toString();
        return true;
    }
    else if (role == TelNumber2)
    {
        subscriber.m_telNumber2 = value.toString();
        return true;
    }
    else if (role == TelNumber3)
    {
        subscriber.m_telNumber3 = value.toString();
        return true;
    }
    else if (role == TelNumber4)
    {
        subscriber.m_telNumber4 = value.toString();
        return true;
    }
    else if (role == TelNumber5)
    {
        subscriber.m_telNumber5 = value.toString();
        return true;
    }

    return false;
}

QHash<int, QByteArray> SubListModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[FlatNumber] = "flatNumber";
    roles[IsEnabled]  = "isEnabled";
    roles[TelNumber1] = "telNumber1";
    roles[TelNumber2] = "telNumber2";
    roles[TelNumber3] = "telNumber3";
    roles[TelNumber4] = "telNumber4";
    roles[TelNumber5] = "telNumber5";
    return roles;
}
