import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    visible: true
    width: 550
    height: 740 
    title: qsTr("2048")

    MainForm {
        anchors.fill: parent
        /*mouseArea.onClicked: {
            console.log(qsTr('Clicked on background. Text: "' + textEdit.text + '"'))
        }*/
    }
}
