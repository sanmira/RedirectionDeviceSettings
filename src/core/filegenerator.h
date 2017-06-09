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
    QString filePathContainer;
    QString folderPathContainer;

signals:

public slots:
    void slot_create_file();
    void slot_on_open_clicked();
};

#endif // SRCCOREILEGENERATOR_H
