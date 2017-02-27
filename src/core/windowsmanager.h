#ifndef WINDOWSMANAGER_H
#define WINDOWSMANAGER_H

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QEventLoop>
#include <QObject>
#include <QUrl>

class WindowsManager
{
public:
    WindowsManager();

public:
    void load_main_view(const QUrl& mainViewFilePath);
    void load_main_view(const QByteArray& mainViewData);

    static void initialize(QQmlApplicationEngine& engine);
    static QObject* getQmlRootObject();
    static QList<QObject*> getQmlRootObjects();
    static QObject* getQmlObject(const QString &objectName);
    static void setContextProperty(const QString& propertyName, const QVariant& property);

    static void show_notification_info(const QString &message);
    static void show_notification_warning(const QString& message);
    static void show_notification_critical(const QString &message);

    static void show_add_subs_window(QObject* receiver);

private:
    static QQmlApplicationEngine* mainViewEngine;
    static bool isWindowsManagerInitialized;
    static bool isMainViewLoaded;

    static bool isInformationLoaded;
    static bool isWarningLoaded;
    static bool isErrorLoaded;
    static bool isAddSubsLoaded;

    static bool isNotificationInvoked;

    static QObject* addSubsRootObject;
};

#endif // WINDOWSMANAGER_H
