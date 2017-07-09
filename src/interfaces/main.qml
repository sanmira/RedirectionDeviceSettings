import QtQuick 2.7
import QtQuick.Window 2.2
<<<<<<< HEAD
import QtQuick.Controls 2.0
=======
import QtQuick.Controls 2.2
>>>>>>> origin/RedirectionSystemSettings
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.1


ApplicationWindow {
    id: root
    visible: true
<<<<<<< HEAD
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
                    TextInput {
                        font.weight: Font.Bold
                        font.underline: true
                        font.pointSize: 17
                        text: 'Квартира: ' + flatNumber
                    }
                    spacing: 2
                    ColumnLayout {
                        spacing: 10
                        RowLayout {
                            Layout.fillWidth: true
                            Layout.minimumWidth: 50
                            Layout.preferredWidth: 200
                            Layout.maximumWidth: 200
                            Text {
                                id: isFlatEnabled
                                font.pointSize: 15
                                text: "Отключена   "
                            }
                            CheckBox {
                                id: checkIsFlatEnabled
                                enabled: false
                                checked: isEnabled
                                onCheckedChanged: {
                                    isEnabled = checked
                                }
                            }
                        }
                        ColumnLayout {
                            spacing: 0
                            Text {
                                id: readrVariants
                                font.weight: Font.DemiBold
                                font.pointSize: 15
                                text: "Переадресации:"
                            }
                            RowLayout {
                                Layout.fillWidth: true
                                Layout.minimumWidth: 50
                                Layout.preferredWidth: 180
                                Layout.maximumWidth: 180
                                Text {
                                    id: isReadrEnabled
                                    font.pointSize: 13
                                    text: "С задержкой  "
                                }
                                CheckBox {
                                    id: checkIsReadrEnabled
                                    enabled: false
                                    checked: false
//                                    onCheckedChanged: {
//                                        isEnabled = checked
//                                    }
                                }
                            }
                            RowLayout {
                                Layout.fillWidth: true
                                Layout.minimumWidth: 50
                                Layout.preferredWidth: 180
                                Layout.maximumWidth: 180
                                Text {
                                    id: isRelatEnabled
                                    font.pointSize: 13
                                    text: "Без задержки"
                                }
                                CheckBox {
                                    id: checkIsRelatEnabled
                                    enabled: false
                                    checked: false
//                                    onCheckedChanged: {
//                                        isEnabled = checked
//                                    }
                                }
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
                        name: "readrChecked"
                        when: ((checkIsReadrEnabled.checked == true) & (checkIsFlatEnabled.checked == true) & (wrapper.GridView.isCurrentItem))
                        PropertyChanges { target: checkIsRelatEnabled; enabled: false; }
                        PropertyChanges { target: scaleTransform; scale: 1.3; }
                        PropertyChanges { target: wrapperRect; color: "green"; }
                        PropertyChanges { target: isFlatEnabled; text: "Подключена"; }
                        PropertyChanges { target: checkIsFlatEnabled; enabled: true; }
                        PropertyChanges { target: checkIsReadrEnabled; enabled: true; }
                        PropertyChanges { target: number1; enabled: true; }
                        PropertyChanges { target: number2; enabled: true; }
                        PropertyChanges { target: number3; enabled: true; }
                        PropertyChanges { target: number4; enabled: true; }
                        PropertyChanges { target: number5; enabled: true; }
                    },
                    State {
                        name: "relatChecked"
                        when: ((checkIsRelatEnabled.checked == true) & (checkIsFlatEnabled.checked == true) & (wrapper.GridView.isCurrentItem))
                        PropertyChanges { target: checkIsReadrEnabled; enabled: false; }
                        PropertyChanges { target: scaleTransform; scale: 1.3; }
                        PropertyChanges { target: wrapperRect; color: "green"; }
                        PropertyChanges { target: isFlatEnabled; text: "Подключена"; }
                        PropertyChanges { target: checkIsFlatEnabled; enabled: true; }
                        PropertyChanges { target: checkIsRelatEnabled; enabled: true; }
                        PropertyChanges { target: number1; enabled: true; }
                        PropertyChanges { target: number2; enabled: true; }
                        PropertyChanges { target: number3; enabled: true; }
                        PropertyChanges { target: number4; enabled: true; }
                        PropertyChanges { target: number5; enabled: true; }
                    },
                    State {
                        name: "checkedNcurrentItem"
                        when: ((checkIsFlatEnabled.checked == true) & (wrapper.GridView.isCurrentItem))
                        PropertyChanges { target: scaleTransform; scale: 1.3; }
                        PropertyChanges { target: wrapperRect; color: "green"; }
                        PropertyChanges { target: isFlatEnabled; text: "Подключена"; }
                        PropertyChanges { target: checkIsFlatEnabled; enabled: true; }
                        PropertyChanges { target: checkIsReadrEnabled; enabled: true; }
                        PropertyChanges { target: checkIsRelatEnabled; enabled: true; }
                    },
                    State {
                        name: "currentItem"
                        when: wrapper.GridView.isCurrentItem
                        PropertyChanges { target: scaleTransform; scale: 1.3; }
                        PropertyChanges { target: checkIsFlatEnabled; enabled: true; }
                    },
                    State {
                        name: "checked"
                        when: checkIsFlatEnabled.checked == true
                        PropertyChanges { target: wrapperRect; color: "green"; }
                        PropertyChanges { target: isFlatEnabled; text: "Подключена"; }
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
=======
    title: "RedirectionSystemSettings"
    minimumWidth: 640
    minimumHeight: 640

    property bool isWriteMode: false

    Component {
        id: subscribersListDelegate
        SubscriberItem {
        }
    }

    Component {
        id: storagesListDelegate
        StorageItem {
        }
    }

    signal applySubscribersCount(string subCount)
    signal refreshStorages()
    signal createFile(string path)
    signal openFile(string path)

    Connections {
        target: dataStatusInterface
        onReadWriteStatusChanged: {
            if (dataStatusInterface.readWriteStatus === true) {
                mainForm.subscribersNumber.text = subListModel.subCountInModel.toString()
                mainForm.subscribersView.focus = true
                mainForm.statusImage.source = "images/completed-tasks.png"
            } else
            {
                mainForm.subscribersView.focus = true
                mainForm.statusImage.source = "images/file.png"
            }
        }
    }

    MainForm {
        id: mainForm
        applyButton.onClicked: {
            subscribersView.focus = true
            applySubscribersCount(subscribersNumber.text)
            statusImage.source = "images/ok-appproval-acceptance.png"
        }
        subscribersNumber.onAccepted: {
            subscribersView.focus = true
            applySubscribersCount(subscribersNumber.text)
            statusImage.source = "images/ok-appproval-acceptance.png"
        }
        subscribersNumber.onTextChanged: {
            if (parseInt(subscribersNumber.text) > 200)
                subscribersNumber.text = 200
            else if (parseInt(subscribersNumber.text) < 0)
                subscribersNumber.text = 0
            if (parseInt(subscribersNumber.text) === subListModel.subCountInModel)
                statusImage.source = "images/ok-appproval-acceptance.png"
            else
                statusImage.source = "images/sync-circular-arrows.png"
            console.log("here")
            console.log(subListModel.subCountInModel)
            console.log(parseInt(subscribersNumber.text))
        }
        loadButton.onClicked: {
            isWriteMode = false
            storagesList.focus = true
            storagesList.visible = true
            refreshStorages()
        }
        saveButton.onClicked: {
            if (subListModel.subCountInModel === parseInt(subscribersNumber.text)) {
            isWriteMode = true
            storagesList.focus = true
            storagesList.visible = true
            refreshStorages()
            }
        }
        anchors.fill: parent
>>>>>>> origin/RedirectionSystemSettings
    }
}

