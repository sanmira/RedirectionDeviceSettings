import QtQuick 2.7
import QtQuick.Controls 2.1

Rectangle {
    id: rectangle

    width: 360
    height: 360
    property alias toolSeparator: toolSeparator
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
        anchors.bottom: rem1subButton.top
        anchors.bottomMargin: 6
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.left: parent.left
        anchors.leftMargin: 8
        anchors.top: progressBar.bottom
        anchors.topMargin: 6
        cellHeight: 380
        delegate: subscribersListDelegate
        cellWidth: 310
        model: subListModel
    }

    Button {
        id: clearButton
        y: 414
        height: 60
        text: qsTr("Очистить таблицу")
        highlighted: true
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 6
        anchors.right: toolSeparator1.horizontalCenter
        anchors.rightMargin: 13
        anchors.left: toolSeparator.horizontalCenter
        anchors.leftMargin: 13
    }

    Button {
        id: rem1subButton
        y: 328
        height: 60
        text: qsTr("-1 абонент")
        highlighted: true
        anchors.bottom: clearButton.top
        anchors.bottomMargin: 26
        anchors.right: toolSeparator1.horizontalCenter
        anchors.rightMargin: 13
        anchors.left: toolSeparator.horizontalCenter
        anchors.leftMargin: 13
    }

    Button {
        id: createButton
        y: 328
        height: 60
        text: qsTr("Создать файл")
        highlighted: true
        anchors.bottom: openButton.top
        anchors.bottomMargin: 26
        anchors.right: toolSeparator.horizontalCenter
        anchors.rightMargin: 13
        anchors.left: parent.left
        anchors.leftMargin: 8
    }

    Button {
        id: openButton
        y: 414
        height: 60
        text: qsTr("Открыть файл")
        highlighted: true
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 6
        anchors.right: toolSeparator.horizontalCenter
        anchors.rightMargin: 13
        anchors.left: parent.left
        anchors.leftMargin: 8
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
        y: 328
        height: 60
        text: qsTr("+1 абонент")
        highlighted: true
        anchors.bottom: addsubsButton.top
        anchors.bottomMargin: 26
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.left: toolSeparator1.horizontalCenter
        anchors.leftMargin: 13
    }

    Button {
        id: addsubsButton
        y: 414
        height: 60
        text: qsTr("Добавить абонентов")
        highlighted: true
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 6
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.left: toolSeparator1.horizontalCenter
        anchors.leftMargin: 13
    }

    ToolSeparator {
        id: toolSeparator
        y: 328
        height: 146
        anchors.right: parent.horizontalCenter
        anchors.rightMargin: 116
        anchors.left: parent.left
        anchors.leftMargin: 231
        visible: false
        enabled: false
        scale: 1
        transformOrigin: Item.Center
        spacing: 0
    }

    ToolSeparator {
        id: toolSeparator1
        y: 328
        height: 146
        anchors.left: parent.horizontalCenter
        anchors.leftMargin: 114
        anchors.right: parent.right
        anchors.rightMargin: 233
        visible: false
        enabled: false
        scale: 1
        transformOrigin: Item.Center
    }

    ToolSeparator {
        id: toolSeparator2
        x: 352
        y: 50
        width: 14
        height: 702
        enabled: false
        visible: false
        rotation: 90
    }
}
