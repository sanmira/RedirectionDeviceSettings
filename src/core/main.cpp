#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QSurface>

#include "windowsmanager.h"
#include "mainmodel.h"
#include "filegenerator.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    if (QCoreApplication::arguments().contains(QLatin1String("--coreprofile"))) {
        QSurfaceFormat fmt;
        fmt.setVersion(4, 4);
        fmt.setProfile(QSurfaceFormat::CoreProfile);
        QSurfaceFormat::setDefaultFormat(fmt);
    }

    QQmlApplicationEngine engine;

    WindowsManager winmanager;
    winmanager.initialize(engine);
    MainModel model;

    winmanager.load_main_view(QStringLiteral("qrc:/src/interfaces/main.qml"));

    FileGenerator fGen(&model);

    return app.exec();
}
