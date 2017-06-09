#include "windowsmanager.h"

#include <QDebug>
#include <QQmlContext>

QQmlApplicationEngine* WindowsManager::mainViewEngine;
bool WindowsManager::isWindowsManagerInitialized = false;
bool WindowsManager::isMainViewLoaded = false;

bool WindowsManager::isInformationLoaded = false;
bool WindowsManager::isWarningLoaded = false;
bool WindowsManager::isErrorLoaded = false;
bool WindowsManager::isAddSubsLoaded = false;
bool WindowsManager::isFileDialogLoaded = false;

bool WindowsManager::isNotificationInvoked = false;

QObject* WindowsManager::addSubsRootObject = NULL;
QObject* WindowsManager::fileDialogObject = NULL;

WindowsManager::WindowsManager()
{

}

void WindowsManager::initialize(QQmlApplicationEngine &engine)
{
    if (isWindowsManagerInitialized == true)
    {
        qWarning("QQmlApplicationEngine already initialized");
        return;
    } else
    {
        mainViewEngine = &engine;
        isWindowsManagerInitialized = true;
    }
}

void WindowsManager::load_main_view(const QUrl &mainViewFilePath)
{
    if (isWindowsManagerInitialized == false)
    {
        qWarning("WindowsManager is not initialized");
        return;
    } else
    if (isMainViewLoaded == true)
    {
        qWarning("QQmlApplicationEngine already loaded");
        return;
    } else
    {
        mainViewEngine->load(mainViewFilePath);
        WindowsManager::isMainViewLoaded = true;
    }
}

void WindowsManager::load_main_view(const QByteArray &mainViewData)
{
    if (isWindowsManagerInitialized == false)
    {
        qWarning("WindowsManager is not initialized");
        return;
    } else
    if (isMainViewLoaded == true)
    {
        qWarning("QQmlApplicationEngine already loaded");
        return;
    } else
    {
        mainViewEngine->loadData(mainViewData);
        WindowsManager::isMainViewLoaded = true;
    }
}

QObject *WindowsManager::getQmlRootObject()
{
    if (isMainViewLoaded == false)
    {
        qWarning("Cannot get qmlRootObject. WindowsManager is not initialized");
        return nullptr;
    } else
    {
        QObject* rootObject = mainViewEngine->rootObjects().first();
        return rootObject;
    }
}

QList<QObject*> WindowsManager::getQmlRootObjects()
{
    if (isMainViewLoaded == false)
    {
        qWarning("Cannot get qmlRootObjects. WindowsManager is not initialized");
        return QList<QObject*>();
    } else
    {
        QList<QObject*> rootObjects = mainViewEngine->rootObjects();
        return rootObjects;
    }
}

QObject *WindowsManager::getQmlObject(const QString &objectName)
{
    if (isMainViewLoaded == false)
    {
        qWarning("Cannot get qmlObject. WindowsManager is not initialized");
        return nullptr;
    } else
    {
        QObject* object = mainViewEngine->rootObjects().first()->findChild<QObject*>(objectName);
        return object;
    }
}

void WindowsManager::setContextProperty(const QString &propertyName, const QVariant &property)
{
    if (isMainViewLoaded == true)
    {
        qWarning("Cannot set property. QQmlApplicationEngine already initialized");
        return;
    } else
    {
        mainViewEngine->rootContext()->setContextProperty(propertyName, property);
    }
}

