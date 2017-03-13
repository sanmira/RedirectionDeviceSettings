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
        } else if (isInformationLoaded == false)
        {
            mainViewEngine->load(QUrl("qrc:/src/interfaces/InfoMessage.qml"));
            isInformationLoaded = true;
        }
        isNotificationInvoked = true;

        QObject* moduleObject;
        for (int i = 0; i < mainViewEngine->rootObjects().count(); i++)
        {
            QString objectName = mainViewEngine->rootObjects().at(i)->objectName();
            if (!objectName.compare("information"))
            {
                moduleObject = mainViewEngine->rootObjects().at(i);
                break;
            }
        }
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
        } else if (isWarningLoaded == false)
        {
            mainViewEngine->load(QUrl("qrc:/src/interfaces/WarningMessage.qml"));
            isWarningLoaded = true;
        }
        isNotificationInvoked = true;

        QObject* moduleObject;
        for (int i = 0; i < mainViewEngine->rootObjects().count(); i++)
        {
            QString objectName = mainViewEngine->rootObjects().at(i)->objectName();
            if (!objectName.compare("warning"))
            {
                moduleObject = mainViewEngine->rootObjects().at(i);
                break;
            }
        }
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
        } else if (isErrorLoaded == false)
        {
            mainViewEngine->load(QUrl("qrc:/src/interfaces/FatalMessage.qml"));
            isErrorLoaded = true;
        }
        isNotificationInvoked = true;

        QObject* moduleObject;
        for (int i = 0; i < mainViewEngine->rootObjects().count(); i++)
        {
            QString objectName = mainViewEngine->rootObjects().at(i)->objectName();
            if (!objectName.compare("error"))
            {
                moduleObject = mainViewEngine->rootObjects().at(i);
                break;
            }
        }
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
    } else
    {
        if (isNotificationInvoked == true)
        {
            qWarning("Cannot show multiple notification windows at same time");
            return;
        } else if (isAddSubsLoaded == false)
        {
            mainViewEngine->load(QUrl("qrc:/src/interfaces/AddSubsMessage.qml"));
            for (int i = 0; i < mainViewEngine->rootObjects().count(); i++)
            {
                QString objectName = mainViewEngine->rootObjects().at(i)->objectName();
                if (!objectName.compare("addsubs"))
                {
                    addSubsRootObject = mainViewEngine->rootObjects().at(i);
                    break;
                }
            }
            QObject::connect(addSubsRootObject, SIGNAL(acceptedSignal(const QString&)), receiver, SLOT(slot_add_subs(const QString&)));
            isAddSubsLoaded = true;
        }
        isNotificationInvoked = true;

        addSubsRootObject->setProperty("visible", "true");

        QEventLoop localLoop;
        QObject::connect(addSubsRootObject, SIGNAL(acceptedSignal(const QString&)), &localLoop, SLOT(quit()));
        QObject::connect(addSubsRootObject, SIGNAL(canceledSignal()), &localLoop, SLOT(quit()));
        localLoop.exec(QEventLoop::DialogExec);

        isNotificationInvoked = false;
    }
}

void WindowsManager::show_file_dialog_window(QObject *receiver)
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
        } else if (isFileDialogLoaded == false)
        {
            mainViewEngine->load(QUrl("qrc:/src/interfaces/FileDialog.qml"));
            for (int i = 0; i < mainViewEngine->rootObjects().count(); i++)
            {
                QString objectName = mainViewEngine->rootObjects().at(i)->objectName();
                if (!objectName.compare("filedialog"))
                {
                    fileDialogObject = mainViewEngine->rootObjects().at(i);
                    break;
                }
            }
            QObject::connect(fileDialogObject, SIGNAL(acceptedSignal(const QUrl&)), receiver, SLOT(slot_file_dialog(const QUrl&)));
            isFileDialogLoaded = true;
        }
        isNotificationInvoked = true;

        fileDialogObject->setProperty("visible", "true");

        QEventLoop localLoop;
        QObject::connect(fileDialogObject, SIGNAL(acceptedSignal(const QUrl&)), &localLoop, SLOT(quit()));
        QObject::connect(fileDialogObject, SIGNAL(canceledSignal()), &localLoop, SLOT(quit()));
        localLoop.exec(QEventLoop::DialogExec);

        isNotificationInvoked = false;
    }
}
