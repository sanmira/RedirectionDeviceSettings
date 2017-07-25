import QtQuick 2.9
import QtQuick.Window 2.3
import QtQuick.Controls 2.2
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3


ApplicationWindow {
    id: root
    visible: true
    title: "RedirectionSystemSettings"
    minimumWidth: 640
    minimumHeight: 640

    signal apply_subscribers_count(string subCount)
    signal create_file()
    signal open_file()
    signal desktop_create_file(string path)
    signal desktop_open_file(string path)

    SwipeView {
        id: view
        currentIndex: 0
        anchors.fill: parent
        MainView {
            id: mainView
        }
        AppInfoView {
            id: appInfoView
        }
    }
}

