#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "modelsmanager.h"
#include "filegenerator.h"

int main(int argc, char *argv[])
{
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    ModelsManager model;
    FileGenerator fgen(&model);

    engine.rootContext()->setContextProperty("subListModel", QVariant::fromValue(&model.subscribersList));
    engine.rootContext()->setContextProperty("storagesListModel", QVariant::fromValue(&model.storagesList));
    engine.rootContext()->setContextProperty("dataStatusInterface", QVariant::fromValue(&fgen.dataIface));

    engine.load(QStringLiteral("qrc:/src/interfaces/main.qml"));

    QObject::connect(engine.rootObjects().first(), SIGNAL(applySubscribersCount(QString)), &fgen, SLOT(slot_set_subscribers(QString)));
    QObject::connect(engine.rootObjects().first(), SIGNAL(refreshStorages()), &fgen, SLOT(refresh_storages_list()));
    QObject::connect(engine.rootObjects().first(), SIGNAL(createFile(QString)), &fgen, SLOT(slot_create_file(QString)));
    QObject::connect(engine.rootObjects().first(), SIGNAL(openFile(QString)), &fgen, SLOT(slot_open_file(QString)));

    return app.exec();
}
