QT += qml quick
!no_desktop: QT += widgets

#QT += androidextras
android:launchMode="singleInstance"

SOURCES += src/core/main.cpp \
    src/core/sublistmodel.cpp \
    src/core/subscriber.cpp \
    src/core/filegenerator.cpp \
    src/core/serviceinfo.cpp \
    src/core/modelsmanager.cpp \
    src/core/storage.cpp \
    src/core/storagelistmodel.cpp \
    src/core/datastatusinterface.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    src/core/sublistmodel.h \
    src/core/subscriber.h \
    src/core/filegenerator.h \
    src/core/serviceinfo.h \
    src/core/modelsmanager.h \
    src/core/storage.h \
    src/core/storagelistmodel.h \
    src/core/datastatusinterface.h

DISTFILES += \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android
