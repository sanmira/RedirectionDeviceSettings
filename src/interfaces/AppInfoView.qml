import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3

Item {
    id: appInfoView

    Text {
        id: appInfoText
        x: 496
        width: 136
        height: 26
        color: "#bf2856"
        text: qsTr("Information")
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.right: parent.right
        anchors.rightMargin: 8
        font.weight: Font.Black
        horizontalAlignment: Text.AlignRight
        font.family: "Tahoma"
        font.pixelSize: 20
    }

    Image {
        id: infoImage
        x: 170
        y: 107
        width: 300
        height: 300
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        source: "images/rounded-info-button.png"
        opacity: 0.1
    }

    ScrollView {
        id: scrollView
        contentWidth: root.width - 16
        contentHeight: column.height
        anchors.top: parent.top
        anchors.topMargin: 40
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8
        anchors.left: parent.left
        anchors.leftMargin: 8
        anchors.right: parent.right
        anchors.rightMargin: 8
        ScrollBar.horizontal.policy: ScrollBar.AlwaysOff
        ScrollBar.vertical.policy: ScrollBar.AlwaysOn

        ColumnLayout {
            id: column
            y: 2
            height: 430
            spacing: 15
            anchors.right: parent.right
            anchors.rightMargin: 15
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.top: parent.top
            anchors.topMargin: 0

            Text {
                id: infoText
                height: 135
                text: "Приложение предназаначено для настройки устройства переадресации вызова Цифрал. Настройка осуществляется путем создания в корневой директори, подключенного с помощью USB устройства, специального файла с имененем \"settings.txt\"."
                verticalAlignment: Text.AlignVCenter
                font.weight: Font.Medium
                Layout.alignment: Qt.AlignLeft | Qt.AlignTop
                anchors.left: parent.left
                anchors.leftMargin: 0
                anchors.right: parent.right
                anchors.rightMargin: 0
                Layout.fillWidth: true
                Layout.fillHeight: false
                wrapMode: Text.WordWrap
                font.pointSize: 15
                font.family: "Tahoma"
            }

            Text {
                id: infoAttentionText
                height: 135
                text: "Внимание!\nПеред подключением к USB порту убедитесь в отсутствии подачи  напряжения на устройство переадресации. Игнорирование данного предупеждения может привести к повреждению настраивающего устройства!"
                font.bold: true
                font.weight: Font.Medium
                wrapMode: Text.WordWrap
                font.pointSize: 17
                Layout.alignment: Qt.AlignLeft | Qt.AlignTop
                Layout.fillWidth: true
                anchors.right: parent.right
                anchors.left: parent.left
                anchors.leftMargin: 0
                font.family: "Tahoma"
                anchors.rightMargin: 0
                Layout.fillHeight: false
                Rectangle {
                    id: border
                    color: "#00000000"
                    border.width: 3
                    border.color: "#bf2856"
                    anchors.leftMargin: -7
                    anchors.rightMargin: -7
                    anchors.topMargin: -7
                    anchors.bottomMargin: -7
                    anchors.fill: parent
                }
            }

            Column {
                id: column1
                width: 200
                height: 400
                Layout.fillHeight: false

                Text {
                    id: licenseTitle
                    color: "#bf2856"
                    text: qsTr("Лицензия: ")
                    Layout.fillHeight: false
                    verticalAlignment: Text.AlignVCenter
                    font.family: "Tahoma"
                    style: Text.Normal
                    font.weight: Font.DemiBold
                    font.pointSize: 16
                    Layout.alignment: Qt.AlignLeft | Qt.AlignTop
                }

                Text {
                    id: text1
                    text: qsTr("GPLv3")
                    verticalAlignment: Text.AlignVCenter
                    font.pointSize: 13
                    font.family: "Tahoma"
                    font.weight: Font.DemiBold
                }
            }

            Column {
                id: column2
                width: 200
                height: 400
                Layout.fillHeight: false

                Text {
                    id: sourceCodeTitleText
                    color: "#bf2856"
                    text: qsTr("Исходный код: ")
                    font.weight: Font.DemiBold
                    font.pointSize: 16
                    Layout.alignment: Qt.AlignLeft | Qt.AlignTop
                    style: Text.Normal
                    verticalAlignment: Text.AlignVCenter
                    font.family: "Tahoma"
                    Layout.fillHeight: false
                }

                Text {
                    id: text2
                    text: qsTr("https://github.com/sanmira32/RedirectionDeviceSettings")
                    font.weight: Font.DemiBold
                    font.pointSize: 13
                    verticalAlignment: Text.AlignVCenter
                    font.family: "Tahoma"
                }
            }

            Column {
                id: column3
                width: 200
                height: 400
                Layout.fillHeight: false
                Text {
                    id: sourceCodeTitleText1
                    color: "#bf2856"
                    text: qsTr("Авторы:")
                    font.weight: Font.DemiBold
                    font.pointSize: 16
                    Layout.alignment: Qt.AlignLeft | Qt.AlignTop
                    style: Text.Normal
                    verticalAlignment: Text.AlignVCenter
                    font.family: "Tahoma"
                    Layout.fillHeight: false
                }

                Text {
                    id: text3
                    text: qsTr("Cyfral <*@cyfral.ru>")
                    font.weight: Font.DemiBold
                    font.pointSize: 13
                    verticalAlignment: Text.AlignVCenter
                    font.family: "Tahoma"
                }

                Text {
                    id: text4
                    text: qsTr("Evgeny Korochkov <matrix3sai@gmail.com>")
                    font.weight: Font.DemiBold
                    font.pointSize: 13
                    verticalAlignment: Text.AlignVCenter
                    font.family: "Tahoma"
                }

                Text {
                    id: text5
                    text: qsTr("Google Inc <*@google.com>")
                    font.weight: Font.DemiBold
                    font.pointSize: 13
                    verticalAlignment: Text.AlignVCenter
                    font.family: "Tahoma"
                }
            }
        }

    }

}
