#ifndef SERVICEINFO_H
#define SERVICEINFO_H

#include <QObject>
#include <QString>

class ServiceInfo : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString servNum1 READ servNum1 WRITE setServNum1 NOTIFY servNum1Changed)
    Q_PROPERTY(QString servNum2 READ servNum2 WRITE setServNum2 NOTIFY servNum2Changed)
    Q_PROPERTY(QString servNum3 READ servNum3 WRITE setServNum3 NOTIFY servNum3Changed)

public:
    explicit ServiceInfo(QObject *parent = 0);

    void setServNum1(const QString &a)
    {
        if (a != m_servNum1) {
            m_servNum1 = a;
            emit servNum1Changed();
        }
    }
    void setServNum2(const QString &a)
    {
        if (a != m_servNum2) {
            m_servNum2 = a;
            emit servNum2Changed();
        }
    }
    void setServNum3(const QString &a)
    {
        if (a != m_servNum3) {
            m_servNum3 = a;
            emit servNum3Changed();
        }
    }

    QString servNum1() const
    {
        return m_servNum1;
    }
    QString servNum2() const
    {
        return m_servNum2;
    }
    QString servNum3() const
    {
        return m_servNum3;
    }

private:
    QString m_servNum1;
    QString m_servNum2;
    QString m_servNum3;

signals:
    void servNum1Changed();
    void servNum2Changed();
    void servNum3Changed();

public slots:
};

#endif // SERVICEINFO_H
