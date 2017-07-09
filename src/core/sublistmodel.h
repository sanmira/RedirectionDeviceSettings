#ifndef SUBLISTMODEL_H
#define SUBLISTMODEL_H

#include <QAbstractListModel>
#include <QList>

#include "subscriber.h"

class SubListModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(int subCountInModel READ subCountInModel WRITE setSubCountInModel NOTIFY subCountInModelChanged)
public:
    explicit SubListModel(QObject *parent = 0);

public:
    enum SubRoles {
        FlatNumber                 = Qt::UserRole + 8,
        IsEnabled                  = Qt::UserRole + 7,
        IsDirectRedirectionEnabled = Qt::UserRole + 6,
        TelNumber1                 = Qt::UserRole + 5,
        TelNumber2                 = Qt::UserRole + 4,
        TelNumber3                 = Qt::UserRole + 3,
        TelNumber4                 = Qt::UserRole + 1,
        TelNumber5
    };

    void addSubscriber(const Subscriber &subscriber);
    void removeLastSub();
    Subscriber getSubscriber(int number);
    int  getSubCount();
    void clearList();

    int rowCount(const QModelIndex & parent = QModelIndex()) const;

    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
    bool     setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);

protected:
    QHash<int, QByteArray> roleNames() const;

private:
    QList<Subscriber> subscriberList;

public:
    void setSubCountInModel(const int &subs) {
        if (subs != m_subCountInModel) {
            m_subCountInModel = subs;
            emit subCountInModelChanged();
        }
    }
    int subCountInModel() const {
        return m_subCountInModel;
    }
signals:
    void subCountInModelChanged();
private:
    int m_subCountInModel;
};
#endif // SUBLISTMODEL_H
