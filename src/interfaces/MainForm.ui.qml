import QtQuick 2.7
import QtQuick.Layouts 1.1
import QtQuick.Controls 2.0

Rectangle {
    id: rectangle

    width: 360
    height: 360
    property alias serviceNumbers: serviceNumbers
    property alias openButton: openButton
    property alias rem1subButton: rem1subButton
    property alias add1subButton: add1subButton
    property alias clearButton: clearButton
    property alias progressBar: progressBar
    property alias addsubsButton: addsubsButton
    property alias createButton: createButton

    GridView {
        id: gridView
        y: 8
        width: 341
        anchors.bottom: gridLayout.top
        anchors.bottomMargin: 6
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.left: parent.left
        anchors.leftMargin: 9
        anchors.top: progressBar.bottom
        anchors.topMargin: 6
        cellHeight: 520
        delegate: subscribersListDelegate
        cellWidth: 315
        model: subListModel
    }

    ProgressBar {
        id: progressBar
        height: 41
        anchors.left: serviceNumbers.right
        anchors.leftMargin: 6
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.top: parent.top
        anchors.topMargin: 8

        Rectangle {
            id: progressBarBorder
            color: "#00000000"
            anchors.fill: parent
            border.color: "#254bff"
            border.width: 3
        }
    }

    GridLayout {
        id: gridLayout
        y: 316
        height: 156
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8
        anchors.right: parent.right
        anchors.rightMargin: 9
        anchors.left: parent.left
        anchors.leftMargin: 9
        columnSpacing: 3
        rowSpacing: 3
        rows: 2
        columns: 3

        Button {
            id: createButton
            height: 60
            text: qsTr("Создать файл")
            Layout.fillHeight: true
            Layout.fillWidth: true
            highlighted: true
        }

        Button {
            id: rem1subButton
            height: 60
            text: qsTr("-1 абонент")
            Layout.fillHeight: true
            Layout.fillWidth: true
            highlighted: true
        }

        Button {
            id: add1subButton
            x: 453
            height: 60
            text: qsTr("+1 абонент")
            Layout.fillHeight: true
            Layout.fillWidth: true
            highlighted: true
        }

        Button {
            id: openButton
            height: 60
            text: qsTr("Открыть файл")
            Layout.fillHeight: true
            Layout.fillWidth: true
            highlighted: true
        }

        Button {
            id: clearButton
            height: 60
            text: qsTr("Очистить таблицу")
            Layout.fillHeight: true
            Layout.fillWidth: true
            highlighted: true
        }

        Button {
            id: addsubsButton
            height: 60
            text: qsTr("Добавить абонентов")
            Layout.fillHeight: true
            Layout.fillWidth: true
            highlighted: true
        }
    }

    Button {
        id: serviceNumbers
        width: 300
        height: 41
        text: qsTr("Сервисные номера")
        highlighted: true
        anchors.left: parent.left
        anchors.leftMargin: 8
        anchors.top: parent.top
        anchors.topMargin: 8
    }
}
