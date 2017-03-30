/*
 * Copyright (c) 2016,2017 sanmira32 <matrix3sai@gmail.com>
 *
 *  This file is part of Project1793.
 *
 *  Project1793 is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Project1793 is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Project1793.  If not, see <http://www.gnu.org/licenses/>.
*/

import QtQuick 2.2
import QtQuick.Controls 2.1
import QtQuick.Dialogs 1.2

Item {
    id: addSubItem
    width: 320
    height: 360
    SystemPalette { id: palette }
    clip: true
    anchors.centerIn: parent

    Dialog {
        id: addSubsWindow
        objectName: "addsubs"
        signal acceptedSignal(string number)
        signal canceledSignal()
        modality: Qt.ApplicationModal
        standardButtons: StandardButton.Apply | StandardButton.Cancel
        onAccepted: {
            addSubsWindow.close()
            addSubsWindow.acceptedSignal(addSubsField.text)
        }
        onApply: {
            addSubsWindow.close()
            addSubsWindow.acceptedSignal(addSubsField.text)
        }
        onRejected: {
            addSubsWindow.close()
            addSubsWindow.canceledSignal()
        }

        Column {
            anchors.fill: parent
            spacing: 7
            Text { text: "Сколько абонентов добавить?"; font.weight: Font.Bold; }
            TextField { id: addSubsField; validator: IntValidator{} inputMethodHints: Qt.ImhFormattedNumbersOnly; maximumLength: 3; font.pointSize: 13 }
        }
        onVisibleChanged: {
            if (!visible)
                rootItem.forceActiveFocus()
            canceledSignal()
        }
    }

}

