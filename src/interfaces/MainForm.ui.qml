import QtQuick 2.7
import QtQuick.Controls 2.1

Rectangle {
    id: rectangle

    width: 360
    height: 360
    property alias openButton: openButton
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
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 76
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.left: parent.left
        anchors.leftMargin: 8
        anchors.top: progressBar.bottom
        anchors.topMargin: 6
        cellHeight: 350
        delegate: subscribersListDelegate
        cellWidth: 310
        model: subListModel
    }

    Button {
        id: clearButton
        x: 245
        y: 445
        width: 231
        height: 29
        text: qsTr("Очистить таблицу")
    }

    Button {
        id: rem1subButton
        x: 245
        y: 410
        width: 231
        height: 29
        text: qsTr("-1 абонент")
    }

    Button {
        id: createButton
        x: 9
        y: 410
        width: 230
        height: 29
        text: qsTr("Создать файл")
    }

    Button {
        id: openButton
        x: 8
        y: 445
        width: 231
        height: 29
        text: qsTr("Открыть файл")
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

    Button {
        id: add1subButton
        x: 482
        y: 410
        width: 230
        height: 29
        text: qsTr("+1 абонент")
    }

    Button {
        id: addsubsButton
        x: 482
        y: 445
        width: 230
        height: 29
        text: qsTr("Добавить абонентов")
    }
}
