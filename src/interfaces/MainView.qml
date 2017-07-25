import QtQuick 2.9

Item {
    id: mainView
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

    Connections {
        target: dataStatusInterface
        onReadWriteStatusChanged: {
            if (dataStatusInterface.readWriteStatus === true) {
                mainForm.subscribersNumber.text = subListModel.sub_count_in_model.toString()
                mainForm.storagesList.visible = false
                mainForm.subscribersView.focus = true
                mainForm.statusImage.source = "images/circle-with-check-symbol.png"
            } else
            {
                mainForm.storagesList.visible = false
                mainForm.subscribersView.focus = true
                mainForm.statusImage.source = "images/round-error-symbol.png"
            }
        }
    }

    MainForm {
        id: mainForm
        applyButton.onClicked: {
            subscribersView.focus = true
            apply_subscribers_count(subscribersNumber.text)
            statusImage.source = "images/tick-inside-circle.png"
        }
        subscribersNumber.onAccepted: {
            subscribersView.focus = true
            apply_subscribers_count(subscribersNumber.text)
            statusImage.source = "images/tick-inside-circle.png"
        }
        subscribersNumber.onTextChanged: {
            if (parseInt(subscribersNumber.text) > 200)
                subscribersNumber.text = 200
            else if (parseInt(subscribersNumber.text) < 0)
                subscribersNumber.text = 0
            if (parseInt(subscribersNumber.text) === subListModel.subCountInModel)
                statusImage.source = "images/tick-inside-circle.png"
            else
                statusImage.source = "images/problems-with-synchronization.png"
        }
        loadButton.onClicked: {
            isWriteMode = false
            storagesList.focus = true
            storagesList.visible = true
            open_file()
        }
        saveButton.onClicked: {
            isWriteMode = true
            storagesList.focus = true
            storagesList.visible = true
            create_file()
        }
        anchors.fill: parent
    }
}
