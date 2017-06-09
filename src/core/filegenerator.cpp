#include "filegenerator.h"

FileGenerator::FileGenerator(MainModel* model, QObject *parent) : QObject(parent),
                                                                  modelHandler(model)
{
    connect(WindowsManager::getQmlRootObjects().first(), SIGNAL(createFile()), this, SLOT(slot_create_file()));
    connect(WindowsManager::getQmlRootObjects().first(), SIGNAL(openFile()), this, SLOT(slot_on_open_clicked()));
}

void FileGenerator::slot_create_file()
{
    if (folderPathContainer.isEmpty())
    {
        return;
    }
    QGuiApplication::processEvents();
    QFile file(folderPathContainer + "/settings.txt");
    if (!file.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text))
    {
        folderPathContainer.clear();
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
            << sub.isEnabled();
        QString telNumber1 = "00000000000000000000";
        telNumber1.replace(0, sub.telNumber1().remove(" ").count(), sub.telNumber1().remove(" "));
        QString telNumber2 = "00000000000000000000";
        telNumber2.replace(0, sub.telNumber2().remove(" ").count(), sub.telNumber2().remove(" "));
        QString telNumber3 = "00000000000000000000";
        telNumber3.replace(0, sub.telNumber3().remove(" ").count(), sub.telNumber3()).remove(" ");
        QString telNumber4 = "00000000000000000000";
        telNumber4.replace(0, sub.telNumber4().remove(" ").count(), sub.telNumber4()).remove(" ");
        QString telNumber5 = "00000000000000000000";
        telNumber5.replace(0, sub.telNumber5().remove(" ").count(), sub.telNumber5()).remove(" ");
        out << sub.telNumber1().remove(" ").count() /10 % 10 << sub.telNumber1().remove(" ").count() % 10 << telNumber1
            << sub.telNumber2().remove(" ").count() /10 % 10 << sub.telNumber2().remove(" ").count() % 10 << telNumber2
            << sub.telNumber3().remove(" ").count() /10 % 10 << sub.telNumber3().remove(" ").count() % 10 << telNumber3
            << sub.telNumber4().remove(" ").count() /10 % 10 << sub.telNumber4().remove(" ").count() % 10 << telNumber4
            << sub.telNumber5().remove(" ").count() /10 % 10 << sub.telNumber5().remove(" ").count() % 10 << telNumber5 << "\n";
    }
    file.close();
    folderPathContainer.clear();
}

void FileGenerator::slot_on_open_clicked()
{
    //WindowsManager::show_file_dialog_window(this, false);
    if (filePathContainer.isEmpty())
    {
        return;
    }
    if (!filePathContainer.contains("settings.txt"))
    {
        //WindowsManager::show_notification_warning("Ошибка. Файл должен называться \"settings.txt\"");
        filePathContainer.clear();
        return;
    }
    QFile file(filePathContainer);
    if (!file.open(QIODevice::ReadOnly))
    {
        return;
    }
    modelHandler->clear_subscribers_list();
    QGuiApplication::processEvents();
    QTextStream in(&file);
    QString firstLine = in.readLine();
    int subNumber = firstLine.toInt();
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
}
