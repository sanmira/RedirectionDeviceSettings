#ifndef SRCCOREILEGENERATOR_H
#define SRCCOREILEGENERATOR_H

#include <QObject>
#include <QDataStream>
#include <QFile>
#include <QGuiApplication>

#include "windowsmanager.h"
#include "mainmodel.h"

class FileGenerator : public QObject
{
    Q_OBJECT
public:
    explicit FileGenerator(MainModel *model, QObject *parent = 0);

private:
    MainModel* modelHandler;
    ServiceInfo* servInfoHandler;
    QString filePathContainer;
    QString folderPathContainer;
    void busy(const QVariant &state);

signals:

public slots:
    void slot_create_file();
    void slot_on_open_clicked();
    void slot_file_dialog(const QUrl &filePath);
    void slot_folder_dialog(const QUrl &folderPath);
    void slot_on_add_subs_clicked();
    void slot_add_subs(const QString& number);   
    void slot_on_clear_table_clicked();
    void slot_on_add_sub_clicked();
    void slot_on_rem_sub_clicked();
};

#endif // SRCCOREILEGENERATOR_H
