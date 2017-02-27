import QtQuick 2.7
import QtQuick.Controls 1.4

Rectangle {
    id: rectangle

    width: 360
    height: 360
    property alias rem1subButton: rem1subButton
    property alias add1subButton: add1subButton
    property alias clearButton: clearButton
    property alias progressBar: progressBar
    property alias addsubsButton: addsubsButton
    property alias createButton: createButton

    GridView {
        id: gridView
        x: 8
        y: 8
        anchors.bottom: progressBar.top
        anchors.bottomMargin: 8
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.left: parent.left
        anchors.leftMargin: 8
        anchors.top: parent.top
        anchors.topMargin: 8
        cellHeight: 240
        delegate: subscribersListDelegate
        cellWidth: 210
        model: subListModel
    }

    Button {
        id: clearButton
        y: 445
        width: 160
        height: 29
        text: qsTr("Очистить таблицу")
        anchors.left: openButton.right
        anchors.leftMargin: 6
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 6
    }

    Button {
        id: rem1subButton
        y: 410
        width: 160
        height: 29
        text: qsTr("-1 абонент")
        anchors.left: createButton.right
        anchors.leftMargin: 6
        anchors.bottom: clearButton.top
        anchors.bottomMargin: 6
    }

    Button {
        id: createButton
        y: 410
        width: 160
        height: 29
        text: qsTr("Создать файл")
        anchors.left: parent.left
        anchors.leftMargin: 8
        anchors.bottom: openButton.top
        anchors.bottomMargin: 6
    }

    Button {
        id: openButton
        y: 445
        width: 160
        height: 29
        text: qsTr("Открыть файл")
        anchors.left: parent.left
        anchors.leftMargin: 8
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 6
    }

    ProgressBar {
        id: progressBar
        y: 410
        height: 64
        indeterminate: false
        anchors.left: addsubsButton.right
        anchors.leftMargin: 6
        anchors.right: parent.right
        anchors.rightMargin: 8
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 6
    }

    Button {
        id: add1subButton
        y: 410
        width: 160
        height: 29
        text: qsTr("+1 абонент")
        anchors.left: rem1subButton.right
        anchors.leftMargin: 6
        anchors.bottom: addsubsButton.top
        anchors.bottomMargin: 6
    }

    Button {
        id: addsubsButton
        y: 445
        width: 160
        height: 29
        text: qsTr("Добавить абонентов")
        anchors.left: clearButton.right
        anchors.leftMargin: 6
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 6
    }
}
