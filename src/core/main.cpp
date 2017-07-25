#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "modelsmanager.h"
#include "filegenerator.h"

int main(int argc, char *argv[])
{
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    ModelsManager::instance().initialize_models();
    FileGenerator fgen;

    engine.rootContext()->setContextProperty("subListModel", QVariant::fromValue(ModelsManager::instance().get_sublist_model()));
    engine.rootContext()->setContextProperty("storagesListModel", QVariant::fromValue(ModelsManager::instance().get_storagelist_model()));
    engine.rootContext()->setContextProperty("dataStatusInterface", QVariant::fromValue(&DataStatusInterface::instance()));

    engine.load(QStringLiteral("qrc:/src/interfaces/main.qml"));

#ifdef Q_OS_ANDROID
    QObject::connect(engine.rootObjects().first(), SIGNAL(create_file()), &fgen, SLOT(save_subscribers_to_file()));
    QObject::connect(engine.rootObjects().first(), SIGNAL(open_file()), &fgen, SLOT(load_subscribers_from_file()));
#else
    QObject::connect(engine.rootObjects().first(), SIGNAL(create_file()), &fgen, SLOT(desktop_refresh_storages_list()));
    QObject::connect(engine.rootObjects().first(), SIGNAL(open_file()), &fgen, SLOT(desktop_refresh_storages_list()));
    QObject::connect(engine.rootObjects().first(), SIGNAL(desktop_create_file(QString)), &fgen, SLOT(desktop_create_file(QString)));
    QObject::connect(engine.rootObjects().first(), SIGNAL(desktop_open_file(QString)), &fgen, SLOT(desktop_open_file(QString)));
#endif
    QObject::connect(engine.rootObjects().first(), SIGNAL(apply_subscribers_count(QString)), &fgen, SLOT(set_subscribers(QString)));

    return app.exec();
}
