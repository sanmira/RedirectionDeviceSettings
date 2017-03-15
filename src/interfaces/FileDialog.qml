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
        signal file(url filePath)
        signal folder(url folderPath)
        signal canceledSignal()
        onAccepted: {
            if (fileDialog.selectFolder)
                fileDialog.folder(fileDialog.fileUrl)
            else
                fileDialog.file(fileDialog.fileUrl)
        }
        onRejected: {
            fileDialog.canceledSignal()
        }
    }
}
