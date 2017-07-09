#include "filegenerator.h"
//#ifdef Q_OS_ANDROID
//    #include <QAndroidJniEnvironment>
//    #include <QAndroidJniObject>
//#endif

FileGenerator::FileGenerator(ModelsManager* model, QObject *parent) : QObject(parent),
                                                                  modelHandler(model)
{

}

void FileGenerator::slot_create_file(QString filePath)
{
    QFile file(filePath + "/settings.txt");
    if (!file.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text))
    {
        dataIface.setReadWriteStatus(0);
        return;
    }

    QTextStream out(&file);

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
    QString firstLine = in.readLine();
    int subNumber = firstLine.toInt();
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
}
