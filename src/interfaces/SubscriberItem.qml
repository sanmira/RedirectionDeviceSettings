import QtQuick 2.9
import QtQuick.Controls 2.2


Item {
    id: wrapper
    width: 260; height: 240
    Rectangle {
        id: wrapperRect
        anchors.fill: parent
        color: "red"
        opacity: 0.2
        scale: 0.8
        MouseArea {
            anchors.fill: parent
            onClicked: {
                wrapper.GridView.view.currentIndex = index
                mainForm.subscribersView.focus = true
            }
        }

    }
    Column {
        Text {
            font.weight: Font.Bold
            font.pixelSize: 20
            text: 'Квартира: ' + flatNumber
        }
        spacing: 2

        Row {
            width: 259
            CheckBox {
                id: checkIsEnabled
                width: 40
                enabled: false
                checked: isEnabled
                onCheckedChanged: {
                    isEnabled = checked
                }
            }

            RadioButton {
                id: directRedirection
                enabled: false;
                checked: isDirectRedirectionEnabled
                onCheckedChanged: {
                    if (checked) {
                        isDirectRedirectionEnabled = true
                    } else
                    {
                        isDirectRedirectionEnabled = false
                    }
                }
            }

            BorderImage {
                id: telephoneImage
                width: 40
                height: 40
                source: "images/phone-call-button.png"
            }

            RadioButton {
                id: timingRedirection
                enabled: false;
                checked: !isDirectRedirectionEnabled
            }

            BorderImage {
                id: clockImage
                width: 40
                height: 40
                source: "images/set-timer-button.png"
            }
        }
        TextField {
            id: number1;
            enabled: false;
            text: telNumber1
            font.family: "Tahoma"
            font.pointSize: 15
            validator: DoubleValidator { }
            inputMethodHints: Qt.ImhDialableCharactersOnly
            selectByMouse: true
            maximumLength: 20

            onTextChanged: {
                telNumber1 = text
            }
        }
        TextField {
            id: number2;
            enabled: false;
            text: telNumber2
            font.family: "Tahoma"
            font.pointSize: 15
            validator: DoubleValidator { }
            inputMethodHints: Qt.ImhDialableCharactersOnly
            selectByMouse: true
            maximumLength: 20

            onTextChanged: {
                telNumber2 = text
            }
        }
        TextField {
            id: number3;
            enabled: false;
            text: telNumber3
            font.pointSize: 15
            font.family: "Tahoma"
            validator: DoubleValidator { }
            inputMethodHints: Qt.ImhDialableCharactersOnly
            selectByMouse: true
            maximumLength: 20

            onTextChanged: {
                telNumber3 = text
            }
        }
        TextField {
            id: number4;
            enabled: false;
            text: telNumber4
            font.pointSize: 15
            font.family: "Tahoma"
            validator: DoubleValidator { }
            inputMethodHints: Qt.ImhDialableCharactersOnly
            selectByMouse: true
            maximumLength: 20

            onTextChanged: {
                telNumber4 = text
            }
        }
        TextField {
            id: number5;
            enabled: false;
            text: telNumber5
            font.pointSize: 15
            font.family: "Tahoma"
            validator: DoubleValidator { }
            inputMethodHints: Qt.ImhDialableCharactersOnly
            selectByMouse: true
            maximumLength: 20

            onTextChanged: {
                telNumber5 = text
            }
        }

    }

    states: [
        State {
            name: "checkedNcurrentItem"
            when: ((checkIsEnabled.checked == true) & (wrapper.GridView.isCurrentItem))
            PropertyChanges { target: scaleTransform; scale: 1.1; }
            PropertyChanges { target: wrapperRect; color: "green"; }
            PropertyChanges { target: checkIsEnabled; enabled: true; }
            PropertyChanges { target: directRedirection; enabled: true; }
            PropertyChanges { target: timingRedirection; enabled: true; }
            PropertyChanges { target: number1; enabled: true; }
            PropertyChanges { target: number1; enabled: true; }
            PropertyChanges { target: number2; enabled: true; }
            PropertyChanges { target: number3; enabled: true; }
            PropertyChanges { target: number4; enabled: true; }
            PropertyChanges { target: number5; enabled: true; }
        },
        State {
            name: "currentItem"
            when: wrapper.GridView.isCurrentItem
            PropertyChanges { target: scaleTransform; scale: 1.1; }
            PropertyChanges { target: checkIsEnabled; enabled: true; }
        },
        State {
            name: "checked"
            when: checkIsEnabled.checked == true
            PropertyChanges { target: wrapperRect; color: "green"; }
        }
    ]
    transform: Scale {
        id: scaleTransform
        property real scale: 1
        xScale: scale
        yScale: scale
    }
    transitions: Transition {
        NumberAnimation { properties: "scale"; duration: 300 }
    }
}

