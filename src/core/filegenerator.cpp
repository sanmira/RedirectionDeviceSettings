#include "filegenerator.h"

FileGenerator::FileGenerator(QObject *parent) : QObject(parent)
{
#ifdef Q_OS_ANDROID
    registerNativeMethods();
    QtAndroid::androidActivity().callMethod<void>("requestStorageRWPermissions");
#else
    //
#endif
}

#ifdef Q_OS_ANDROID
void FileGenerator::io_success(JNIEnv *env, jobject thiz)
{
    Q_UNUSED(env)
    Q_UNUSED(thiz)
    DataStatusInterface::instance().setReadWriteStatus(1);
    qDebug() << "IO success flag set!";
}

void FileGenerator::io_fail(JNIEnv *env, jobject thiz)
{
    Q_UNUSED(env)
    Q_UNUSED(thiz)
    DataStatusInterface::instance().setReadWriteStatus(0);
    qDebug() << "IO fail flag set!";
}

void FileGenerator::clear_subscribers_list(JNIEnv *env, jobject thiz)
{
    Q_UNUSED(env)
    Q_UNUSED(thiz)
    emit ModelsManager::instance().clear_subscribers_list();
    qDebug() << "Subscribers list cleared!";
}

void FileGenerator::add_new_subscriber(JNIEnv *env, jobject thiz, jstring stringLine)
{
    Q_UNUSED(thiz)
    QString line(env->GetStringUTFChars(stringLine, 0));
    QString substring;
    int flatNumber;
    bool isEnabled;
    bool isDirectRedirectionEnabled;
    QString telNumber1;
    QString telNumber2;
    QString telNumber3;
    QString telNumber4;
    QString telNumber5;

    substring = line.mid(0, 3);
    flatNumber = substring.toInt();

    substring = line.mid(3, 1);
    isEnabled = substring.toInt();

    substring = line.mid(4, 1);
    isDirectRedirectionEnabled = substring.toInt();

    substring = line.mid(5, 2);
    int telNumberDigits = substring.toInt();
    if (telNumberDigits > 0)
        telNumber1 = line.mid(7, telNumberDigits);

    substring = line.mid(27, 2);
    telNumberDigits = substring.toInt();
    if (telNumberDigits > 0)
        telNumber2 = line.mid(29, telNumberDigits);

    substring = line.mid(49, 2);
    telNumberDigits = substring.toInt();
    if (telNumberDigits > 0)
        telNumber3 = line.mid(51, telNumberDigits);

    substring = line.mid(71, 2);
    telNumberDigits = substring.toInt();
    if (telNumberDigits > 0)
        telNumber4 = line.mid(73, telNumberDigits);

    substring = line.mid(93, 2);
    telNumberDigits = substring.toInt();
    if (telNumberDigits > 0)
        telNumber5 = line.mid(95, telNumberDigits);

    emit ModelsManager::instance().add_new_subscriber(Subscriber(flatNumber, isEnabled, isDirectRedirectionEnabled, telNumber1, telNumber2, telNumber3, telNumber4, telNumber5));
}

void FileGenerator::registerNativeMethods()
{
    JNINativeMethod methods[] { {"io_success", "()V", reinterpret_cast<void *>(io_success)},
                                {"io_fail", "()V", reinterpret_cast<void *>(io_fail)},
                                {"clear_subscribers_list", "()V", reinterpret_cast<void *>(clear_subscribers_list)},
                                {"new_line", "(Ljava/lang/String;)V", reinterpret_cast<void *>(add_new_subscriber)}};

    QAndroidJniObject javaClass("org/qtproject/qt5/NativeCalls");
    QAndroidJniEnvironment env;
    jclass objectClass = env->GetObjectClass(javaClass.object<jobject>());
    env->RegisterNatives(objectClass, methods, sizeof(methods) / sizeof(methods[0]));;
    env->DeleteLocalRef(objectClass);
} 

void FileGenerator::save_subscribers_to_file()
{
    QString resultText;
    QTextStream out(&resultText);

    out << ModelsManager::instance().get_subscribers_count() / 100 % 10 << ModelsManager::instance().get_subscribers_count() / 10 % 10 << ModelsManager::instance().get_subscribers_count() % 10;
    out << "\r\n";
    Subscriber sub;
    for (int i = 0; i < ModelsManager::instance().get_subscribers_count(); i++)
    {
        sub = ModelsManager::instance().get_subscriber(i);
        out << sub.flatNumber() / 100 % 10 << sub.flatNumber() / 10 % 10 << sub.flatNumber() % 10
            << sub.isEnabled() << sub.isDirectRedirectionEnabled();
        QString telNumber1 = ("00000000000000000000");
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
            << sub.telNumber5().remove(" ").count() /10 % 10 << sub.telNumber5().remove(" ").count() % 10 << telNumber5
            << "\r\n";
    }
    QtAndroid::androidActivity().callMethod<void>("create_file", "(Ljava/lang/String;)V", QAndroidJniObject::fromString(resultText).object<jstring>());
}

void FileGenerator::load_subscribers_from_file()
{
    QtAndroid::androidActivity().callMethod<void>("open_file", "()V");
}
#else
void FileGenerator::desktop_refresh_storages_list()
{
    ModelsManager::instance().clear_storages_list();
    foreach (const QStorageInfo &storage, QStorageInfo::mountedVolumes()) {
        if (storage.isValid() && storage.isReady()) {
            if (!storage.isReadOnly()) {
                    emit ModelsManager::instance().add_new_storage(Storage(storage.rootPath()));
            }
        }
    }
}

void FileGenerator::desktop_create_file(QString filePath)
{
    QFile file(filePath + "/settings.txt");
    if (!file.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text))
    {
        DataStatusInterface::instance().setReadWriteStatus(0);
        return;
    }

    QTextStream out(&file);

    out << ModelsManager::instance().get_subscribers_count() / 100 % 10 << ModelsManager::instance().get_subscribers_count() / 10 % 10 << ModelsManager::instance().get_subscribers_count() % 10;
    out << "\n";

    Subscriber sub;
    for (int i = 0; i < ModelsManager::instance().get_subscribers_count(); i++)
    {
        sub = ModelsManager::instance().get_subscriber(i);
        out << sub.flatNumber() / 100 % 10 << sub.flatNumber() / 10 % 10 << sub.flatNumber() % 10
            << sub.isEnabled() << sub.isDirectRedirectionEnabled();
        QString telNumber1 = ("00000000000000000000");
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
            << sub.telNumber5().remove(" ").count() /10 % 10 << sub.telNumber5().remove(" ").count() % 10 << telNumber5
            << "\n";
        QGuiApplication::processEvents();
    }
    file.close();
    DataStatusInterface::instance().setReadWriteStatus(1);
}

void FileGenerator::desktop_open_file(QString filePath)
{
    QFile file(filePath + "/settings.txt");
    if (!file.open(QIODevice::ReadOnly))
    {
        DataStatusInterface::instance().setReadWriteStatus(0);
        return;
    }
    emit ModelsManager::instance().clear_subscribers_list();
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

        emit ModelsManager::instance().add_new_subscriber(Subscriber(i + 1, isEnabled, isDirectRedirectionEnabled, flatNumber1, flatNumber2, flatNumber3, flatNumber4, flatNumber5));
        QGuiApplication::processEvents();
    }
    file.close();
    DataStatusInterface::instance().setReadWriteStatus(1);
}
#endif

void FileGenerator::set_subscribers(QString subscribersCount)
{
    int currentNumOfSubs = ModelsManager::instance().get_subscribers_count();
    int difference = subscribersCount.toInt() - currentNumOfSubs;
    if (difference > 0)
    {
        for (int i = 0; (i < difference) && (currentNumOfSubs < 201); i++)
        {
            currentNumOfSubs = ModelsManager::instance().get_subscribers_count();
            emit ModelsManager::instance().add_new_subscriber(Subscriber(currentNumOfSubs + 1, false, true, "", "", "", "", ""));
        }
    } else
    {
        difference *= -1;
        for (int i = 0; i < difference; i++)
        {
            ModelsManager::instance().remove_last_subscriber();
        }
    }
}
