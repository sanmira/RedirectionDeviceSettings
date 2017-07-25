#ifndef SUBLISTMODEL_H
#define SUBLISTMODEL_H

#include <QAbstractListModel>
#include <QList>

#include "subscriber.h"

class SubListModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(int sub_count_in_model READ sub_count_in_model WRITE set_sub_count_in_model NOTIFY sub_count_in_model_changed)
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

    Subscriber get_subscriber(int number);
    int  get_sub_count();

public slots:
    void clear_list();
    void add_subscriber(const Subscriber &subscriber);
    void remove_last_sub();

    int rowCount(const QModelIndex & parent = QModelIndex()) const;

    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
    bool     setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);

protected:
    QHash<int, QByteArray> roleNames() const;

private:
    QList<Subscriber> subscriberList;

public:
    void set_sub_count_in_model(const int &subs) {
        if (subs != m_subCountInModel) {
            m_subCountInModel = subs;
            emit sub_count_in_model_changed();
        }
    }
    int sub_count_in_model() const {
        return m_subCountInModel;
    }
signals:
    void sub_count_in_model_changed();
private:
    int m_subCountInModel;
};
#endif // SUBLISTMODEL_H
