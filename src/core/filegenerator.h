#ifndef SRCCOREILEGENERATOR_H
#define SRCCOREILEGENERATOR_H

#include <QGuiApplication>
#include <QObject>
#include <QDataStream>
#include <QFile>
#include <QQmlApplicationEngine>
#include <QStorageInfo>

#include "modelsmanager.h"
#include "datastatusinterface.h"

class FileGenerator : public QObject
{
    Q_OBJECT
public:
    explicit FileGenerator(ModelsManager *model, QObject *parent = 0);

private:
    ModelsManager* modelHandler;

public:
    DataStatusInterface dataIface;

public slots:
    void slot_create_file(QString);
    void slot_open_file(QString);
    void slot_set_subscribers(QString);
    void refresh_storages_list();
};

#endif // SRCCOREILEGENERATOR_H
