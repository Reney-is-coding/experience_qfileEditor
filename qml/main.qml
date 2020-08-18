import QtQuick 2.2
import QtQuick.Window 2.1
import QtLocation 5.6
import QtPositioning 5.6
import QtQuick.Dialogs 1.0
import QtQuick.Controls 2.2

Window {
    width: Qt.platform.os == "android" ? Screen.width : 512
    height: Qt.platform.os == "android" ? Screen.height : 512
    visible: true


    TextEdit {
        id: name
        text: "text"
        wrapMode: Text.WordWrap

        anchors.left: parent.left
        anchors.right: parent.right

        height: parent.height * 0.9
    }

    Button {
        text: "Save"
        anchors.right: parent.right
        anchors.bottom: parent.bottom

        height: parent.height * 0.1

        onClicked: textModel.writeToFile(name.text)
    }

    Button {
        text: "Open File"
        anchors.left: parent.left
        height: parent.height * 0.1
        anchors.bottom: parent.bottom

        onClicked: fileDialog.visible = true
    }

    FileDialog {
        id: fileDialog
        title: "Please choose a file"
        folder: shortcuts.home
        onAccepted: {
            name.text = textModel.readFromFile(fileDialog.fileUrls)
        }
        onRejected: {
            console.log("Canceled")
        }
        Component.onCompleted: visible = true
    }
}
