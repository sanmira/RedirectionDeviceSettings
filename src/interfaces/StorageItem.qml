import QtQuick 2.7
import QtQuick.Layouts 1.1
import QtGraphicalEffects 1.0
import QtQuick.Window 2.0

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
            width: 50
            height: 50
            source: "images/hard-disk-outline.png"
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
            font.pixelSize: 28
        }

        MouseArea {
            id: storageButton
            width: 480
            height: 50
            onClicked: {
                storageItemRectangle.color = "#485387"
                if (isWriteMode) {
                    createFile(storagePath)
                } else {
                    openFile(storagePath)
                }
            }
        }
    }
}
