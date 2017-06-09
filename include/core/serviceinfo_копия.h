#ifndef SERVICEINFO_H
#define SERVICEINFO_H

#include <QObject>

class ServiceInfo : public QObject
{
    Q_OBJECT
public:
    explicit ServiceInfo(QObject *parent = 0);

signals:

public slots:
};

#endif // SERVICEINFO_H