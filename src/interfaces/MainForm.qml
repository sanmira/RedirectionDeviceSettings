import QtQuick 2.7
import QtQuick.Layouts 1.1
import QtQuick.Controls 2.2

Rectangle {
    id: rootBoard

    width: 360
    height: 360
    z: 0
    property alias storagesList: storagesList
    property alias subscribersView: subscribersView
    property alias topBoard: topBoard
    property alias applyButton: applyButton
    property alias subscribersNumber: subscribersNumber
    property alias loadButton: loadButton
    property alias saveButton: saveButton
    property alias statusImage: statusImage

    GridView {
        id: subscribersView
        width: 704
        z: 0
        anchors.right: parent.right
        anchors.rightMargin: 8
        anchors.left: parent.left
        anchors.leftMargin: 8
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8
        anchors.top: topBoard.bottom
        anchors.topMargin: 6
        cellHeight: 340
        delegate: subscribersListDelegate
        cellWidth: 290
        model: subListModel
        ScrollBar.vertical: ScrollBar { }
    }

    Rectangle {
        id: topBoard
        height: 80
        color: "#EA0000"
        Behavior on color { ColorAnimation { duration: 1000 } }
        z: 1
        anchors.top: parent.top
        anchors.topMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 0
        clip: false
        opacity: 1

        TextField {
            id: subscribersNumber
            x: 144
            y: 8
            width: 100
            height: 62
            text: qsTr("0")
            leftPadding: 6
            font.pointSize: 30
            renderType: Text.QtRendering
            font.family: "Tahoma"
            validator: DoubleValidator { }
            inputMethodHints: Qt.ImhDigitsOnly
            maximumLength: 3
            selectByMouse: true
            opacity: 0.9
            horizontalAlignment: Text.AlignHCenter
        }

        BorderImage {
            id: saveImage
            x: 8
            y: 8
            width: 62
            height: 62
            antialiasing: false
            source: "images/floppy-disk-save-button.png"

            MouseArea {
                id: saveButton
                width: 62
                height: 62
            }
        }

        BorderImage {
            id: loadImage
            x: 76
            y: 8
            width: 62
            height: 62
            antialiasing: false
            source: "images/download-arrow.png"

            MouseArea {
                id: loadButton
                width: 62
                height: 62
            }
        }

        BorderImage {
            id: applyImage
            x: 250
            y: 8
            width: 62
            height: 62
            antialiasing: false
            source: "images/round-done-button.png"
            MouseArea {
                id: applyButton
                width: 62
                height: 62
            }
        }
    }

    ListView {
        id: storagesList
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8
        anchors.top: parent.top
        anchors.topMargin: 86
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        visible: false
        z: 0
        spacing: 6
        onActiveFocusChanged: {
            visible = false
        }
        Keys.onBackPressed: {
            visible = false
            subscribersView.focus = true
        }
        Keys.onEscapePressed: {
            visible = false
            subscribersView.focus = true
        }

        model: storagesListModel
        delegate: storagesListDelegate
        add: Transition {
            NumberAnimation { properties: "x,y"; duration: 800; easing.type: Easing.OutBounce }

            // ensure opacity and scale values return to 1.0
            NumberAnimation { property: "opacity"; to: 1.0 }
            NumberAnimation { property: "scale"; to: 1.0 }
        }
    }

    BorderImage {
        id: statusImage
        x: 582
        width: 50
        height: 50
        anchors.top: parent.top
        anchors.topMargin: 90
        anchors.right: parent.right
        anchors.rightMargin: 8
        onSourceChanged: statusImageAnimation.running = true
        SequentialAnimation {
            id: statusImageAnimation
            running: false
            NumberAnimation { target: statusImage; property: "opacity"; from: 1; to: 0; duration: 500 }
            NumberAnimation { target: statusImage; property: "opacity"; from: 0; to: 1; duration: 500 }
        }
    }
}
