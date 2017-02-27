#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H


#include <QObject>
#include <QString>

class Subscriber
{
public:
    Subscriber();
    Subscriber(const int     &flatNumber,
               const bool    &isEnabled,
               const QString &telNumber1,
               const QString &telNumber2,
               const QString &telNumber3,
               const QString &telNumber4,
               const QString &telNumber5);

    int     flatNumber() const;
    bool    isEnabled()  const;
    QString telNumber1() const;
    QString telNumber2() const;
    QString telNumber3() const;
    QString telNumber4() const;
    QString telNumber5() const;

public:
    int     m_flatNumber;
    bool    m_isEnabled;
    QString m_telNumber1;
    QString m_telNumber2;
    QString m_telNumber3;
    QString m_telNumber4;
    QString m_telNumber5;
};

Q_DECLARE_METATYPE(Subscriber)

#endif // SUBSCRIBER_H
