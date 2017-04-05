import QtQuick 2.7
import QtQuick.Window 2.2
import QtQuick.Controls 2.1
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.1


ApplicationWindow {
    id: root
    visible: true
    title: "UP_Settings"
    minimumWidth: 720
    minimumHeight: 480
    visibility: Window.Maximized

    property var progressbarState: false
    property var createButtonState: true
    property var openButtonState: true
    property var remSubButtonState: true
    property var clearButtonState: true
    property var addSubButtonState: true
    property var addSubsButtonState: true

    signal onOpenButtonClicked()
    signal onRemSubClicked()
    signal onAddSubClicked()
    signal onClearTableClicked()
    signal onAddSubsClicked()
    signal onCreateButtonClicked()

    function change_ui_state(state)
    {
        if (state === true)
        {
            progressbarState = true
            createButtonState = false
            openButtonState = false
            remSubButtonState = false
            clearButtonState = false
            addSubButtonState = false
            addSubsButtonState = false
        } else
        {
            progressbarState = false
            createButtonState = true
            openButtonState = true
            remSubButtonState = true
            clearButtonState = true
            addSubButtonState = true
            addSubsButtonState = true
        }
    }
    FocusScope {
        id: rootItem
        anchors.fill: parent

        Component {
            id: subscribersListDelegate
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
                        }
                    }

                }
                ColumnLayout {
                    Text {
                        font.weight: Font.Bold
                        font.pointSize: 17
                        text: 'Квартира: ' + flatNumber
                    }
                    spacing: 2
                    RowLayout {
                        Text {
                            id: isEnabledText
                            font.weight: Font.DemiBold
                            font.pointSize: 17
                            text: "Отключена"
                        }
                        CheckBox {
                            id: checkIsEnabled
                            enabled: false
                            checked: isEnabled
                            onCheckedChanged: {
                                isEnabled = checked
                            }
                        }
                    }
                    TextField {
                        id: number1;
                        enabled: false;
                        text: telNumber1
                        font.pointSize: 13
                        validator: DoubleValidator { }
                        inputMethodHints: Qt.ImhDialableCharactersOnly
                        maximumLength: 20
                        selectByMouse: true

                        onTextChanged: {
                            telNumber1 = text
                        }
                    }
                    TextField {
                        id: number2;
                        enabled: false;
                        text: telNumber2
                        font.pointSize: 13
                        validator: DoubleValidator { }
                        inputMethodHints: Qt.ImhDialableCharactersOnly
                        maximumLength: 20
                        selectByMouse: true

                        onTextChanged: {
                            telNumber2 = text
                        }
                    }
                    TextField {
                        id: number3;
                        enabled: false;
                        text: telNumber3
                        font.pointSize: 13
                        validator: DoubleValidator { }
                        inputMethodHints: Qt.ImhDialableCharactersOnly
                        maximumLength: 20
                        selectByMouse: true

                        onTextChanged: {
                            telNumber3 = text
                        }
                    }
                    TextField {
                        id: number4;
                        enabled: false;
                        text: telNumber4
                        font.pointSize: 13
                        validator: DoubleValidator { }
                        inputMethodHints: Qt.ImhDialableCharactersOnly
                        maximumLength: 20
                        selectByMouse: true

                        onTextChanged: {
                            telNumber4 = text
                        }
                    }
                    TextField {
                        id: number5;
                        enabled: false;
                        text: telNumber5
                        font.pointSize: 13
                        validator: DoubleValidator { }
                        inputMethodHints: Qt.ImhDialableCharactersOnly
                        maximumLength: 20
                        selectByMouse: true

                        onTextChanged: {
                            telNumber5 = text
                        }
                    }
                }

                states: [
                    State {
                        name: "checkedNcurrentItem"
                        when: ((checkIsEnabled.checked == true) & (wrapper.GridView.isCurrentItem))
                        PropertyChanges { target: scaleTransform; scale: 1.3; }
                        PropertyChanges { target: wrapperRect; color: "green"; }
                        PropertyChanges { target: isEnabledText; text: "Подключена"; }
                        PropertyChanges { target: checkIsEnabled; enabled: true; }
                        PropertyChanges { target: number1; enabled: true; }
                        PropertyChanges { target: number2; enabled: true; }
                        PropertyChanges { target: number3; enabled: true; }
                        PropertyChanges { target: number4; enabled: true; }
                        PropertyChanges { target: number5; enabled: true; }
                    },
                    State {
                        name: "currentItem"
                        when: wrapper.GridView.isCurrentItem
                        PropertyChanges { target: scaleTransform; scale: 1.3; }
                        PropertyChanges { target: checkIsEnabled; enabled: true; }
                    },
                    State {
                        name: "checked"
                        when: checkIsEnabled.checked == true
                        PropertyChanges { target: wrapperRect; color: "green"; }
                        PropertyChanges { target: isEnabledText; text: "Подключена"; }
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
        }

        Menu {
            id: serviceMenu
            width: 300
            MenuItem {
                TextField {
                    id: serv1;
                    width: 300
                    font.pointSize: 13
                    validator: DoubleValidator { }
                    inputMethodHints: Qt.ImhDialableCharactersOnly
                    maximumLength: 20
                    hoverEnabled: true
                    selectByMouse: true
                    text: servInfo.servNum1

                    onTextChanged: {
                        servInfo.servNum1 = serv1.text
                    }
                }
            }
            MenuItem {
                TextField {
                    id: serv2;
                    width: 300
                    font.pointSize: 13
                    validator: DoubleValidator { }
                    inputMethodHints: Qt.ImhDialableCharactersOnly
                    maximumLength: 20
                    hoverEnabled: true
                    selectByMouse: true
                    text: servInfo.servNum2

                    onTextChanged: {
                        servInfo.servNum2 = serv2.text
                    }
                }
            }
            MenuItem {
                TextField {
                    id: serv3;
                    width: 300
                    font.pointSize: 13
                    validator: DoubleValidator { }
                    inputMethodHints: Qt.ImhDialableCharactersOnly
                    maximumLength: 20
                    hoverEnabled: true
                    selectByMouse: true
                    text: servInfo.servNum3

                    onTextChanged: {
                        servInfo.servNum3 = serv3.text
                    }
                }
            }
        }

        MainForm {
            serviceNumbers.onClicked: {
                serviceMenu.x = 8
                serviceMenu.y = 54
                serviceMenu.open()
            }

            openButton.onClicked: {
                onOpenButtonClicked()
            }

            rem1subButton.onClicked: {
                onRemSubClicked()
            }

            add1subButton.onClicked: {
                onAddSubClicked()
            }

            clearButton.onClicked: {
                onClearTableClicked()
            }

            progressBar.indeterminate: progressbarState

            createButton.enabled: createButtonState
            createButton.highlighted: createButtonState

            openButton.enabled: openButtonState
            openButton.highlighted: openButtonState

            rem1subButton.enabled: remSubButtonState
            rem1subButton.highlighted: remSubButtonState

            clearButton.enabled: clearButtonState
            clearButton.highlighted: clearButtonState

            add1subButton.enabled: addSubButtonState
            add1subButton.highlighted: addSubButtonState

            addsubsButton.enabled: addSubsButtonState
            addsubsButton.highlighted: addSubsButtonState

            addsubsButton.onClicked: {
                onAddSubsClicked()
            }
            createButton.onClicked: {
                onCreateButtonClicked()
            }
            anchors.fill: parent
        }

        FatalMessage {
            visible: false
        }

        WarningMessage {
            visible: false
        }

        InfoMessage {
            visible: false
        }

        AddSubsMessage {
            visible: false
        }

        FileDialog {
            visible: false
        }
    }
}

