#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "windowsmanager.h"
#include "mainmodel.h"
#include "filegenerator.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    WindowsManager winmanager;
    winmanager.initialize(engine);
    MainModel model;

    winmanager.load_main_view(QStringLiteral("qrc:/src/interfaces/main.qml"));

    FileGenerator fGen(&model);

    return app.exec();
}
