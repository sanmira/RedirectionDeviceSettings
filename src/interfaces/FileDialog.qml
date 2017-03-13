import QtQuick 2.7
import QtQuick.Dialogs 1.2

FileDialog {
    id: fileDialog
    objectName: "filedialog"
    title: "Dialog"
    folder: shortcuts.home
    signal acceptedSignal(url filePath)
    signal canceledSignal()
    onAccepted: {
        console.log("You chose: " + fileDialog.fileUrl)
        acceptedSignal(fileDialog.fileUrl)
    }
    onRejected: {
        console.log("Canceled")
        canceledSignal()
    }
    visible: false
}
