#ifndef DATASTATUSINTERFACE_H
#define DATASTATUSINTERFACE_H

#include <QObject>

class DataStatusInterface : public QObject
{
    Q_OBJECT
public:
    explicit DataStatusInterface(QObject *parent = 0);

signals:

public slots:
};

#endif // DATASTATUSINTERFACE_H