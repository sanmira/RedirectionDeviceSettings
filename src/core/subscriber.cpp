#include "subscriber.h"

Subscriber::Subscriber()
{

}

Subscriber::Subscriber(const int     &flatNumber,
                       const bool    &isEnabled,
                       const bool    &isDirectRedirectionEnabled,
                       const QString &telNumber1,
                       const QString &telNumber2,
                       const QString &telNumber3,
                       const QString &telNumber4,
                       const QString &telNumber5) : m_flatNumber(flatNumber),
                                                     m_isEnabled(isEnabled),
                                                     m_isDirectRedirectionEnabled(isDirectRedirectionEnabled),
                                                     m_telNumber1(telNumber1),
                                                     m_telNumber2(telNumber2),
                                                     m_telNumber3(telNumber3),
                                                     m_telNumber4(telNumber4),
                                                     m_telNumber5(telNumber5)
{

}

int Subscriber::flatNumber() const
{
    return m_flatNumber;
}

bool    Subscriber::isEnabled() const
{
    return m_isEnabled;
}

bool    Subscriber::isDirectRedirectionEnabled() const
{
    return m_isDirectRedirectionEnabled;
}

QString Subscriber::telNumber1() const
{
    return m_telNumber1;
}

QString Subscriber::telNumber2() const
{
    return m_telNumber2;
}

QString Subscriber::telNumber3() const
{
    return m_telNumber3;
}

QString Subscriber::telNumber4() const
{
    return m_telNumber4;
}

QString Subscriber::telNumber5() const
{
    return m_telNumber5;
}
