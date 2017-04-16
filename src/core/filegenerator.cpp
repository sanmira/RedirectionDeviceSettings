#include "filegenerator.h"

FileGenerator::FileGenerator(MainModel* model, QObject *parent) : QObject(parent),
                                                                  modelHandler(model),
                                                                  servInfoHandler(&model->servInfo)
{
    connect(WindowsManager::getQmlRootObjects().first(), SIGNAL(onCreateButtonClicked()), this, SLOT(slot_create_file()));
    connect(WindowsManager::getQmlRootObjects().first(), SIGNAL(onOpenButtonClicked()), this, SLOT(slot_on_open_clicked()));
    connect(WindowsManager::getQmlRootObjects().first(), SIGNAL(onAddSubsClicked()), this, SLOT(slot_on_add_subs_clicked()));
    connect(WindowsManager::getQmlRootObjects().first(), SIGNAL(onClearTableClicked()), this, SLOT(slot_on_clear_table_clicked()));
    connect(WindowsManager::getQmlRootObjects().first(), SIGNAL(onAddSubClicked()), this, SLOT(slot_on_add_sub_clicked()));
    connect(WindowsManager::getQmlRootObjects().first(), SIGNAL(onRemSubClicked()), this, SLOT(slot_on_rem_sub_clicked()));
}

void FileGenerator::busy(const QVariant& state)
{
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
    if (!file.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text))
    {
        folderPathContainer.clear();
        WindowsManager::show_notification_warning("Невозможно создать файл в выбранной папке!");
        busy(false);
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
            << sub.isEnabled();
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
    }
    file.close();
    folderPathContainer.clear();
    busy(false);
}

void FileGenerator::slot_on_open_clicked()
{
    busy(true);
    WindowsManager::show_file_dialog_window(this, false);
    if (filePathContainer.isEmpty())
    {
        busy(false);
        return;
    }
    if (!filePathContainer.contains("settings.txt"))
    {
        WindowsManager::show_notification_warning("Ошибка. Файл должен называться \"settings.txt\"");
        filePathContainer.clear();
        busy(false);
        return;
    }
    QFile file(filePathContainer);
    if (!file.open(QIODevice::ReadOnly))
    {
        busy(false);
        return;
    }
    modelHandler->clear_subscribers_list();
    QGuiApplication::processEvents();
    QTextStream in(&file);

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
    for (int i = 0; i < subNumber; i++)
    {
        QString line = in.readLine();
        QString substring;
        Subscriber sub;
        bool isEnabled;
        QString flatNumber1;
        QString flatNumber2;
        QString flatNumber3;
        QString flatNumber4;
        QString flatNumber5;

        substring = line.mid(3, 1);
        isEnabled = substring.toInt();

        substring = line.mid(4, 2);
        int telNumberDigits = substring.toInt();
        if (telNumberDigits > 0)
            flatNumber1 = line.mid(6, telNumberDigits);

        substring = line.mid(26, 2);
        telNumberDigits = substring.toInt();
        if (telNumberDigits > 0)
            flatNumber2 = line.mid(28, telNumberDigits);

        substring = line.mid(48, 2);
        telNumberDigits = substring.toInt();
        if (telNumberDigits > 0)
            flatNumber3 = line.mid(50, telNumberDigits);

        substring = line.mid(70, 2);
        telNumberDigits = substring.toInt();
        if (telNumberDigits > 0)
            flatNumber4 = line.mid(72, telNumberDigits);

        substring = line.mid(92, 2);
        telNumberDigits = substring.toInt();
        if (telNumberDigits > 0)
            flatNumber5 = line.mid(94, telNumberDigits);

        modelHandler->add_new_subscriber(Subscriber(i + 1, isEnabled, flatNumber1, flatNumber2, flatNumber3, flatNumber4, flatNumber5));

    }
    file.close();
    filePathContainer.clear();
    busy(false);
}

void FileGenerator::slot_file_dialog(const QUrl &filePath)
{
    filePathContainer = filePath.toLocalFile();
    qDebug() << "File path:" << filePathContainer;
}

void FileGenerator::slot_folder_dialog(const QUrl &folderPath)
{
    folderPathContainer = folderPath.toLocalFile();
    qDebug() << "Folder path:" << folderPathContainer;
}

void FileGenerator::slot_on_add_subs_clicked()
{
    WindowsManager::show_add_subs_window(this);
}

void FileGenerator::slot_add_subs(const QString& number)
{
    busy(true);
    QGuiApplication::processEvents();
    int startNumOfSubs = modelHandler->getSubscribersCount();
    int currentNumOfSubs = modelHandler->getSubscribersCount();
    for (int i = 0; (i < number.toInt()) && (currentNumOfSubs < 300); i++)
    {
        QGuiApplication::processEvents();
        modelHandler->add_new_subscriber(Subscriber(startNumOfSubs + i + 1, false, "", "", "", "", ""));
        currentNumOfSubs = modelHandler->getSubscribersCount();
    }
    busy(false);
}

void FileGenerator::slot_on_clear_table_clicked()
{
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
}
