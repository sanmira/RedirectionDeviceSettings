import QtQuick 2.7
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.1


ApplicationWindow {
    id: root
    visible: true
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
    }
}

