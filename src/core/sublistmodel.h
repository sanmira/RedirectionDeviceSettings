#ifndef SUBLISTMODEL_H
#define SUBLISTMODEL_H

#include <QAbstractListModel>
#include <QList>

#include "subscriber.h"

class SubListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit SubListModel(QObject *parent = 0);

public:
    enum SubRoles {
        FlatNumber = Qt::UserRole + 7,
        IsEnabled  = Qt::UserRole + 6,
        TelNumber1 = Qt::UserRole + 5,
        TelNumber2 = Qt::UserRole + 4,
        TelNumber3 = Qt::UserRole + 3,
        TelNumber4 = Qt::UserRole + 1,
        TelNumber5
    };

    void addSubscriber(const Subscriber &subscriber);
    Subscriber getSubscriber(int number);
    int  getSubCount();
    void removeLastSub();
    void clearList();

    int rowCount(const QModelIndex & parent = QModelIndex()) const;

    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
    bool     setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);

protected:
    QHash<int, QByteArray> roleNames() const;

private:
    QList<Subscriber> subscriberList;
};
#endif // SUBLISTMODEL_H
