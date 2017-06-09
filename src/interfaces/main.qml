import QtQuick 2.7
import QtQuick.Window 2.2
import QtQuick.Controls 2.1
import QtQuick.Controls.Styles 1.4

ApplicationWindow {
    visible: true
    title: "UP_Settings"
    minimumWidth: 720
    width: 720
    minimumHeight: 480
    height: 480
    visibility: Window.Maximized
    Component {
        id: subscribersListDelegate
        SubscriberItem {

        }
    }
    signal createFile()
    signal openFile()
    MainForm {
        createButton.onClicked: {
            createFile()
        }
        openButton.onClicked: {
            openFile()
        }
        anchors.fill: parent
    }
}
