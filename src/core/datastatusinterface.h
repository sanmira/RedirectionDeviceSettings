#ifndef DATASTATUSINTERFACE_H
#define DATASTATUSINTERFACE_H

#include <QObject>

class DataStatusInterface : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool readWriteStatus READ readWriteStatus NOTIFY readWriteStatusChanged)
public:
    explicit DataStatusInterface(QObject *parent = 0);

public:
    void setReadWriteStatus(const bool &status) {
        m_readWriteStatus = status;
        emit readWriteStatusChanged();
    }
    bool readWriteStatus() const {
        return m_readWriteStatus;
    }

signals:
    void readWriteStatusChanged();
private:
    bool m_readWriteStatus;
};

#endif // DATASTATUSINTERFACE_H
