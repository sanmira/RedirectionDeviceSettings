import QtQuick 2.7
import QtQuick.Layouts 1.1
import QtQuick.Controls 2.1

Rectangle {
    id: rectangle

    width: 360
    height: 360
    property alias openButton: openButton
    property alias progressBar: progressBar
    property alias createButton: createButton

    GridView {
        id: gridView
        y: 8
        anchors.bottom: rowLayout.top
        anchors.bottomMargin: 6
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.left: parent.left
        anchors.leftMargin: 9
        anchors.top: progressBar.bottom
        anchors.topMargin: 6
        cellHeight: 440
        delegate: subscribersListDelegate
        cellWidth: 315
        model: subListModel
    }

    ProgressBar {
        id: progressBar
        anchors.top: parent.top
        anchors.topMargin: 8
        indeterminate: false
        anchors.left: parent.left
        anchors.leftMargin: 9
        anchors.right: parent.right
        anchors.rightMargin: 9
    }

    RowLayout {
        id: rowLayout
        y: 373
        height: 99
        anchors.left: parent.left
        anchors.leftMargin: 9
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8

        Button {
            id: createButton
            height: 60
            text: qsTr("Создать")
            font.family: "Tahoma"
            font.pointSize: 25
            Layout.fillHeight: true
            Layout.fillWidth: true
            highlighted: false
        }

        Button {
            id: openButton
            height: 60
            text: qsTr("Открыть")
            font.family: "Tahoma"
            font.pointSize: 25
            Layout.fillHeight: true
            Layout.fillWidth: true
            highlighted: false
        }

        TextField {
            id: textField
            text: qsTr("312")
            horizontalAlignment: Text.AlignHCenter
            font.family: "Tahoma"
            font.pointSize: 36
            Layout.fillHeight: true
            Layout.fillWidth: false
        }

        Button {
            id: button
            text: qsTr("Применить")
            font.family: "Tahoma"
            font.pointSize: 25
            Layout.fillHeight: true
            Layout.fillWidth: true
        }
    }
}
