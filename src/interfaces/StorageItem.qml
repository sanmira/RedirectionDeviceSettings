import QtQuick 2.9
import QtQuick.Layouts 1.3

Item {
    id: wrapper
    width: Screen.width; height: 50
    Rectangle {
        id: storageItemRectangle
        height: 50
        color: "#7c8fec"
        Behavior on color { ColorAnimation { duration: 200 }}
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0

        BorderImage {
            id: borderImage
            x: 8
            y: 4
            width: 42
            height: 42
            source: "images/save-button.png"
        }

        Text {
            id: storagePathText
            x: 56
            y: 8
            width: 416
            height: 34
            color: "#ffffff"
            text: storagePath
            font.family: "Tahoma"
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft
            font.pixelSize: 19
        }

        MouseArea {
            id: storageButton
            width: 480
            height: 50
            onClicked: {
                storageItemRectangle.color = "#485387"
                if (isWriteMode) {
                    desktop_create_file(storagePath)
                } else {
                    desktop_open_file(storagePath)
                }
            }
        }
    }
}
