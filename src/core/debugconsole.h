#ifndef DEBUGCONSOLE_H
#define DEBUGCONSOLE_H

#include <QObject>
#include <QString>

class DebugConsole : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString consoleLog READ consoleLog NOTIFY consoleLogStatusChanged)
public:
    explicit DebugConsole(QObject *parent = 0);

public:
    void setConsoleLog(const QString &log) {
        m_consoleLog = log;
        emit consoleLogStatusChanged();
    }
    QString consoleLog() const {
        return m_consoleLog;
    }

signals:
    void consoleLogStatusChanged();
private:
    QString m_consoleLog;
};

#endif // DEBUGCONSOLE_H
