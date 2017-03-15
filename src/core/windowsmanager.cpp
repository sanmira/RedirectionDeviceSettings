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

void WindowsManager::show_notification_info(const QString& message)
{
    if (isWindowsManagerInitialized == false)
    {
        qWarning("WindowsManager is not initialized");
        return;
    } else
    {
        if (isNotificationInvoked == true)
        {
            qWarning("Cannot show multiple notification windows at same time");
            return;
        }

        QObject* moduleObject = mainViewEngine->rootObjects().first()->findChild<QObject*>(QString("information"), Qt::FindChildrenRecursively);

        moduleObject->setProperty("text", message);
        moduleObject->setProperty("visible", "true");

        QEventLoop localLoop;
        QObject::connect(moduleObject, SIGNAL(closeSignal()), &localLoop, SLOT(quit()));
        localLoop.exec(QEventLoop::DialogExec);

        isNotificationInvoked = false;
    }
}

void WindowsManager::show_notification_warning(const QString& message)
{
    if (isWindowsManagerInitialized == false)
    {
        qWarning("WindowsManager is not initialized");
        return;
    } else
    {
        if (isNotificationInvoked == true)
        {
            qWarning("Cannot show multiple notification windows at same time");
            return;
        }

        QObject* moduleObject = mainViewEngine->rootObjects().first()->findChild<QObject*>(QString("warning"), Qt::FindChildrenRecursively);

        moduleObject->setProperty("text", message);
        moduleObject->setProperty("visible", "true");

        QEventLoop localLoop;
        QObject::connect(moduleObject, SIGNAL(closeSignal()), &localLoop, SLOT(quit()));
        localLoop.exec(QEventLoop::DialogExec);

        isNotificationInvoked = false;
    }
}

void WindowsManager::show_notification_critical(const QString& message)
{
    if (isWindowsManagerInitialized == false)
    {
        qWarning("WindowsManager is not initialized");
        return;
    } else
    {
        if (isNotificationInvoked == true)
        {
            qWarning("Cannot show multiple notification windows at same time");
            return;
        }

        QObject* moduleObject = mainViewEngine->rootObjects().first()->findChild<QObject*>(QString("error"), Qt::FindChildrenRecursively);

        moduleObject->setProperty("text", message);
        moduleObject->setProperty("visible", "true");

        QEventLoop localLoop;
        QObject::connect(moduleObject, SIGNAL(closeSignal()), &localLoop, SLOT(quit()));
        localLoop.exec(QEventLoop::DialogExec);

        isNotificationInvoked = false;
    }
}

void WindowsManager::show_add_subs_window(QObject* receiver)
{
    if (isWindowsManagerInitialized == false)
    {
        qWarning("WindowsManager is not initialized");
        return;
    } else if (isNotificationInvoked == true)
    {
        qWarning("Cannot show multiple notification windows at same time");
        return;
    }
    isNotificationInvoked = true;
    if (isAddSubsLoaded == false)
    {
        addSubsRootObject = mainViewEngine->rootObjects().first()->findChild<QObject*>(QString("addsubs"), Qt::FindChildrenRecursively);
        QObject::connect(addSubsRootObject, SIGNAL(acceptedSignal(const QString&)), receiver, SLOT(slot_add_subs(const QString&)));
        isAddSubsLoaded = true;
    }

    addSubsRootObject->setProperty("visible", "true");
    addSubsRootObject->setProperty("focus", "true");

    QEventLoop localLoop;
    QObject::connect(addSubsRootObject, SIGNAL(acceptedSignal(const QString&)), &localLoop, SLOT(quit()));
    QObject::connect(addSubsRootObject, SIGNAL(canceledSignal()), &localLoop, SLOT(quit()));
    localLoop.exec(QEventLoop::DialogExec);

    isNotificationInvoked = false;
}


void WindowsManager::show_file_dialog_window(QObject *receiver, bool isSearchForFolder)
{
    if (isWindowsManagerInitialized == false)
    {
        qWarning("WindowsManager is not initialized");
        return;
    } else if (isNotificationInvoked == true)
    {
        qWarning("Cannot show multiple notification windows at same time");
        return;
    }

    isNotificationInvoked = true;

    if (isFileDialogLoaded == false)
    {
        fileDialogObject = mainViewEngine->rootObjects().first()->findChild<QObject*>(QString("filedialog"), Qt::FindChildrenRecursively);
        QObject::connect(fileDialogObject, SIGNAL(file(const QUrl&)), receiver, SLOT(slot_file_dialog(const QUrl&)));
        QObject::connect(fileDialogObject, SIGNAL(folder(const QUrl&)), receiver, SLOT(slot_folder_dialog(const QUrl&)));
        isFileDialogLoaded = true;
    }

    if (isSearchForFolder)
        fileDialogObject->setProperty("selectFolder", "true");
    else
        fileDialogObject->setProperty("selectFolder", "false");
    fileDialogObject->setProperty("visible", "true");

    QEventLoop localLoop;
    QObject::connect(fileDialogObject, SIGNAL(file(const QUrl&)), &localLoop, SLOT(quit()));
    QObject::connect(fileDialogObject, SIGNAL(folder(const QUrl&)), &localLoop, SLOT(quit()));
    QObject::connect(fileDialogObject, SIGNAL(canceledSignal()), &localLoop, SLOT(quit()));
    localLoop.exec(QEventLoop::DialogExec);

    isNotificationInvoked = false;
}

