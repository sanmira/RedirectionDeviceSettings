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
#include "debugconsole.h"
#ifdef Q_OS_ANDROID
    #include <QtAndroid>
    #include <QAndroidJniEnvironment>
    #include <QAndroidJniObject>
#endif

class FileGenerator : public QObject
{
    Q_OBJECT
public:
    explicit FileGenerator(QObject *parent = 0);
#ifdef Q_OS_ANDROID
private:
    void registerNativeMethods();

private:
    static void io_success(JNIEnv *env, jobject thiz);
    static void io_fail(JNIEnv *env, jobject thiz);
    static void clear_subscribers_list(JNIEnv *env, jobject thiz);
    static void add_new_subscriber(JNIEnv *env, jobject thiz, jstring stringLine);

public slots:
    void save_subscribers_to_file();
    void load_subscribers_from_file();
#else
public slots:
    void desktop_create_file(QString);
    void desktop_open_file(QString);
    void desktop_refresh_storages_list();
#endif
    void set_subscribers(QString);
};

#endif // SRCCOREILEGENERATOR_H
