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

import QtQuick 2.7
import QtQuick.Window 2.2
import QtQuick.Controls 1.4

Window {
    id: addSubsWindow
    objectName: "addsubs"
    title: "Dialog"
    modality: Qt.ApplicationModal
    maximumWidth: 180
    minimumWidth: 180
    maximumHeight: 80
    minimumHeight: 80
    signal acceptedSignal(string number)
    signal canceledSignal()

    Column {
        anchors.fill: parent
        spacing: 7
        Text { text: "Сколько абонентов добавить?"; font.weight: Font.Bold; }
        TextField { id: addSubsField; validator: IntValidator{} inputMethodHints: Qt.ImhFormattedNumbersOnly; width: 125; maximumLength: 3 }
        Row {
            spacing: 7
            Button { text: "Добавить"; onClicked: {
                    addSubsWindow.hide()
                    acceptedSignal(addSubsField.text)
                }
            }
            Button { text: "Отмена"; onClicked: {
                    addSubsWindow.hide()
                    canceledSignal()
                }

            }
        }
    }
    onClosing: {
        canceledSignal()
    }
}
