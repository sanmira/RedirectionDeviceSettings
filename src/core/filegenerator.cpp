#include "filegenerator.h"
//#ifdef Q_OS_ANDROID
//    #include <QAndroidJniEnvironment>
//    #include <QAndroidJniObject>
//#endif

<<<<<<< HEAD
FileGenerator::FileGenerator(MainModel* model, QObject *parent) : QObject(parent),
                                                                  modelHandler(model),
                                                                  servInfoHandler(&model->servInfo)
=======
FileGenerator::FileGenerator(ModelsManager* model, QObject *parent) : QObject(parent),
                                                                  modelHandler(model)
>>>>>>> origin/RedirectionSystemSettings
{
}

void FileGenerator::slot_create_file(QString filePath)
{
<<<<<<< HEAD
    QObject* moduleRootObject = WindowsManager::getQmlRootObjects().first();
    QMetaObject::invokeMethod(moduleRootObject, "change_ui_state",
                              Q_ARG(QVariant, state));
}

void FileGenerator::slot_create_file()
{
    busy(true);
    WindowsManager::show_file_dialog_window(this, true);
    if (folderPathContainer.isEmpty())
    {
        busy(false);
        return;
    }
    QGuiApplication::processEvents();
    QFile file(folderPathContainer + "/settings.txt");
=======
    QFile file(filePath + "/settings.txt");
>>>>>>> origin/RedirectionSystemSettings
    if (!file.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text))
    {
        dataIface.setReadWriteStatus(0);
        return;
    }

    QTextStream out(&file);

    QString servNumber1 = "00000000000000000000";
    servNumber1.replace(0, servInfoHandler->servNum1().remove(" ").count(), servInfoHandler->servNum1().remove(" "));
    QString servNumber2 = "00000000000000000000";
    servNumber2.replace(0, servInfoHandler->servNum2().remove(" ").count(), servInfoHandler->servNum2().remove(" "));
    QString servNumber3 = "00000000000000000000";
    servNumber3.replace(0, servInfoHandler->servNum3().remove(" ").count(), servInfoHandler->servNum3().remove(" "));

    out << servInfoHandler->servNum1().remove(" ").count() /10 % 10 << servInfoHandler->servNum1().remove(" ").count() % 10 << servNumber1
        << servInfoHandler->servNum2().remove(" ").count() /10 % 10 << servInfoHandler->servNum2().remove(" ").count() % 10 << servNumber2
        << servInfoHandler->servNum3().remove(" ").count() /10 % 10 << servInfoHandler->servNum3().remove(" ").count() % 10 << servNumber3;
    out << "\n";

    out << modelHandler->getSubscribersCount() / 100 % 10 << modelHandler->getSubscribersCount() / 10 % 10 << modelHandler->getSubscribersCount() % 10;
    out << "\n";
    Subscriber sub;
    for (int i = 0; i < modelHandler->getSubscribersCount(); i++)
    {
        sub = modelHandler->getSubscriber(i);
        out << sub.flatNumber() / 100 % 10 << sub.flatNumber() / 10 % 10 << sub.flatNumber() % 10
            << sub.isEnabled() << sub.isDirectRedirectionEnabled();
        QString telNumber1 = "00000000000000000000";
        telNumber1.replace(0, sub.telNumber1().remove(" ").count(), sub.telNumber1().remove(" "));
        QString telNumber2 = "00000000000000000000";
        telNumber2.replace(0, sub.telNumber2().remove(" ").count(), sub.telNumber2().remove(" "));
        QString telNumber3 = "00000000000000000000";
        telNumber3.replace(0, sub.telNumber3().remove(" ").count(), sub.telNumber3().remove(" "));
        QString telNumber4 = "00000000000000000000";
        telNumber4.replace(0, sub.telNumber4().remove(" ").count(), sub.telNumber4().remove(" "));
        QString telNumber5 = "00000000000000000000";
        telNumber5.replace(0, sub.telNumber5().remove(" ").count(), sub.telNumber5().remove(" "));
        out << sub.telNumber1().remove(" ").count() /10 % 10 << sub.telNumber1().remove(" ").count() % 10 << telNumber1
            << sub.telNumber2().remove(" ").count() /10 % 10 << sub.telNumber2().remove(" ").count() % 10 << telNumber2
            << sub.telNumber3().remove(" ").count() /10 % 10 << sub.telNumber3().remove(" ").count() % 10 << telNumber3
            << sub.telNumber4().remove(" ").count() /10 % 10 << sub.telNumber4().remove(" ").count() % 10 << telNumber4
            << sub.telNumber5().remove(" ").count() /10 % 10 << sub.telNumber5().remove(" ").count() % 10 << telNumber5 << "\n";
        QGuiApplication::processEvents();
    }
    file.close();
    dataIface.setReadWriteStatus(1);
}

void FileGenerator::slot_open_file(QString filePath)
{
    QFile file(filePath + "/settings.txt");
    if (!file.open(QIODevice::ReadOnly))
    {
        dataIface.setReadWriteStatus(0);
        return;
    }
    modelHandler->clear_subscribers_list();
    QTextStream in(&file);
<<<<<<< HEAD

    QString serviceInfoString = in.readLine();
    int servNum1Digits = serviceInfoString.mid(0, 2).toInt();
    servInfoHandler->setServNum1(serviceInfoString.mid(2, servNum1Digits));
    int servNum2Digits = serviceInfoString.mid(22, 2).toInt();
    servInfoHandler->setServNum2(serviceInfoString.mid(24, servNum2Digits));
    int servNum3Digits = serviceInfoString.mid(44, 2).toInt();
    servInfoHandler->setServNum3(serviceInfoString.mid(46, servNum3Digits));

    qDebug() << servInfoHandler->servNum1();
    qDebug() << servInfoHandler->servNum2();
    qDebug() << servInfoHandler->servNum3();

    QString secondLine = in.readLine();
    int subNumber = secondLine.toInt();
    qDebug() << subNumber;
=======
    QString firstLine = in.readLine();
    int subNumber = firstLine.toInt();
>>>>>>> origin/RedirectionSystemSettings
    for (int i = 0; i < subNumber; i++)
    {
        QString line = in.readLine();
        QString substring;
        bool isEnabled;
        bool isDirectRedirectionEnabled;
        QString flatNumber1;
        QString flatNumber2;
        QString flatNumber3;
        QString flatNumber4;
        QString flatNumber5;

        substring = line.mid(3, 1);
        isEnabled = substring.toInt();

        substring = line.mid(4, 1);
        isDirectRedirectionEnabled = substring.toInt();

        substring = line.mid(5, 2);
        int telNumberDigits = substring.toInt();
        if (telNumberDigits > 0)
            flatNumber1 = line.mid(7, telNumberDigits);

        substring = line.mid(27, 2);
        telNumberDigits = substring.toInt();
        if (telNumberDigits > 0)
            flatNumber2 = line.mid(29, telNumberDigits);

        substring = line.mid(49, 2);
        telNumberDigits = substring.toInt();
        if (telNumberDigits > 0)
            flatNumber3 = line.mid(51, telNumberDigits);

        substring = line.mid(71, 2);
        telNumberDigits = substring.toInt();
        if (telNumberDigits > 0)
            flatNumber4 = line.mid(73, telNumberDigits);

        substring = line.mid(93, 2);
        telNumberDigits = substring.toInt();
        if (telNumberDigits > 0)
            flatNumber5 = line.mid(95, telNumberDigits);

        modelHandler->add_new_subscriber(Subscriber(i + 1, isEnabled, isDirectRedirectionEnabled, flatNumber1, flatNumber2, flatNumber3, flatNumber4, flatNumber5));
        QGuiApplication::processEvents();
    }
    file.close();
    dataIface.setReadWriteStatus(1);
}

void FileGenerator::slot_set_subscribers(QString subscribersCount)
{
    int currentNumOfSubs = modelHandler->getSubscribersCount();
    int difference = subscribersCount.toInt() - currentNumOfSubs;
    if (difference > 0)
    {
        for (int i = 0; (i < difference) && (currentNumOfSubs < 201); i++)
        {
            currentNumOfSubs = modelHandler->getSubscribersCount();
            modelHandler->add_new_subscriber(Subscriber(currentNumOfSubs + 1, false, true, "", "", "", "", ""));
        }
    } else
    {
        difference *= -1;
        for (int i = 0; i < difference; i++)
        {
            modelHandler->remove_last_subscriber();
        }
    }
}

void FileGenerator::refresh_storages_list()
{
<<<<<<< HEAD
    busy(true);
    QGuiApplication::processEvents();
    modelHandler->clear_subscribers_list();
    busy(false);
}

void FileGenerator::slot_on_add_sub_clicked()
{
    busy(true);
    QGuiApplication::processEvents();
    int numOfSubs = modelHandler->getSubscribersCount();
    if (numOfSubs < 300)
        modelHandler->add_new_subscriber(Subscriber(numOfSubs + 1, true, "", "", "", "", ""));
    busy(false);
}

void FileGenerator::slot_on_rem_sub_clicked()
{
    busy(true);
    QGuiApplication::processEvents();
    int numOfSubs = modelHandler->getSubscribersCount();
    if (numOfSubs > 0)
        modelHandler->remove_last_subscriber();
    busy(false);
=======
//#ifdef Q_OS_ANDROID
//    modelHandler->clear_storages_list();
//    QAndroidJniObject mediaDir = QAndroidJniObject::callStaticObjectMethod("android/os/Environment", "getExternalStorageDirectory", "()Ljava/io/File;");
//    QAndroidJniObject mediaPath = mediaDir.callObjectMethod( "getAbsolutePath", "()Ljava/lang/String;" );
//    QString dataAbsPath = mediaPath.toString();
//    QAndroidJniEnvironment env;
//    if (env->ExceptionCheck()) {
//            // Handle exception here.
//            env->ExceptionClear();
//    }
//    modelHandler->add_new_storage(Storage(dataAbsPath));
//#else
    modelHandler->clear_storages_list();
    foreach (const QStorageInfo &storage, QStorageInfo::mountedVolumes()) {
        if (storage.isValid() && storage.isReady()) {
            if (!storage.isReadOnly()) {
                    modelHandler->add_new_storage(Storage(storage.rootPath()));
            }
        }
    }
//#endif
>>>>>>> origin/RedirectionSystemSettings
}
