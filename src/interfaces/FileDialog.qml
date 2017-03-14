import QtQuick 2.7
import QtQuick.Dialogs 1.2

Item {
    width: 580
    height: 400
    SystemPalette { id: palette }
    clip: true

    FileDialog {
        id: fileDialog
        objectName: "filedialog"
        signal acceptedSignal(url filePath)
        signal canceledSignal()
        onAccepted: {
            fileDialog.acceptedSignal(fileDialog.fileUrl)
        }
        onRejected: {
            fileDialog.canceledSignal()
        }
    }
}
