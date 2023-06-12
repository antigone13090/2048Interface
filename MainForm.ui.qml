import QtQuick 2.6
import QtQuick.Layouts 1.1
import QtQuick.Dialogs 1.1

Rectangle {
    id: rect
    x: 0
    y: 0
    width: 550
    height: 740
    color: "#faf8ef"

    border.width: 0
    radius: 3
    property alias rowLayout: rowLayout
    property alias xobutton16: xobutton16
    property alias xobutton15: xobutton15
    property alias xobutton14: xobutton14
    property alias xobutton13: xobutton13
    property alias xobutton11Label: xobutton11Label
    property alias xobutton12: xobutton12
    property alias xobutton11: xobutton11
    property alias xobutton10: xobutton10
    property alias xobutton9Label: xobutton9Label
    property alias xobutton9: xobutton9
    property alias xobutton8: xobutton8
    property alias xobutton7: xobutton7
    property alias xobutton6Label: xobutton6Label
    property alias xobutton6: xobutton6
    property alias xobutton5: xobutton5
    property alias xobutton4: xobutton4
    property alias xobutton3: xobutton3
    property alias xobutton2: xobutton2
    property alias xobutton1: xobutton1
    property alias gridLayout: gridLayout
    border.color: "#FFFFFF"

    ColumnLayout {
        id: columnLayout
        spacing: 10
        anchors.fill: parent

        RowLayout {
            id: rowLayout1
            y: 20
            width: 100
            height: 100
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            spacing: 250

            Text {
                id: text1
                color: "#e6776e65"
                text: qsTr("2048")
                font.family: "Arial"
                font.wordSpacing: -1
                style: Text.Normal
                font.bold: true
                font.pixelSize: 55
                Text {
                    id: text4
                    x: 1
                    y: 60
                    color: "#e6776e65"
                    text: qsTr(" Toti Frédéric © Mas Thierry ")
                    font.bold: false
                    font.pixelSize: 12
                }
            }

            Text {
                id: text2
                color: "#e6776e65"
                text: qsTr("Score")
                font.bold: true
                font.pixelSize: 25

                Text {
                    id: text3
                    x: 8
                    y: 35
                    color: "#e6776e65"
                    text: grid.score_qml
                    font.bold: true
                    font.pixelSize: 25
                }
            }
        }

        RowLayout {

            id: rowLayout
            x: 371
            y: 40
            anchors.right: parent.right
            width: 0
            height: 40
            anchors.margins: 20
            Layout.columnSpan: 1
            Layout.rowSpan: 1
            spacing: 50
            transformOrigin: Item.Right
            Layout.fillWidth: true

            Rectangle {
                id: rectangle1
                width: 129
                height: 40
                color: "#8f7a66"
                Layout.fillWidth: false
                radius: 3
                Text {
                    id: undo
                    x: 20
                    y: 0
                    color: "#ffffff"
                    text: qsTr("undo")
                    font.bold: false
                    font.pointSize: 25
                }

                MouseArea {
                    id: mouseArea
                    anchors.fill: parent
                    onClicked: {
                        grid.key_press_undo()
                    }
                }
            }

            Rectangle {
                id: rectangle2
                width: 129
                height: 40
                radius: 3
                color: "#8f7a66"
                Text {
                    id: restart
                    x: 18
                    y: 2
                    text: qsTr("restart")
                    horizontalAlignment: Text.AlignLeft
                    color: "#ffffff"
                    font.family: "Arial"
                    font.bold: false
                    font.pointSize: 25
                }
                MouseArea {
                    id: mouseArea1
                    anchors.fill: parent
                    onClicked: {
                        grid.key_press_restart()
                    }
                }
            }
        }

        Rectangle {
            id: rectangle
            y: 200
            width: 500
            height: 500
            color: "#bbada0"
            radius: 6
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

            GridLayout {
                id: gridLayout
                anchors.leftMargin: 10
                anchors.fill: parent
                transformOrigin: Item.Center
                Layout.preferredWidth: 0
                Layout.preferredHeight: 0
                Layout.maximumHeight: 500
                Layout.maximumWidth: 500
                Layout.fillHeight: false
                Layout.fillWidth: false
                Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom
                rows: 4
                columns: 4
                columnSpacing: 0
                rowSpacing: 0 // changed from spacing: 0

                Rectangle {
                    id: xobutton1
                    width: 425 / 4
                    height: 425 / 4
                    radius: 3
                    color: Qt.rgba(238 / 255, 228 / 255, 218 / 255, 0.35)
                    property string label: "?"
                    x: 0
                    y: 0

                    Text {
                        id: xobutton1Label
                        //text : label
                        text: grid.a_0_0
                        color: "#8F7A66"
                        font.family: "Arial"
                        font.bold: true
                        font.pointSize: 35
                        anchors.centerIn: parent
                        focus: true
                    }
                }
                Rectangle {
                    id: xobutton2
                    width: 425 / 4
                    height: 425 / 4
                    radius: 3
                    color: Qt.rgba(238 / 255, 228 / 255, 218 / 255, 0.35)
                    property string label: "?"
                    x: (rect.width) / 4
                    y: 0

                    Text {
                        id: xobutton2Label
                        text: grid.a_0_1
                        color: "#8F7A66"
                        font.family: "Arial"
                        font.bold: true
                        font.pointSize: 35
                        anchors.centerIn: parent
                    }
                }
                Rectangle {
                    id: xobutton3
                    width: 425 / 4
                    height: 425 / 4
                    radius: 3
                    color: Qt.rgba(238 / 255, 228 / 255, 218 / 255, 0.35)
                    property string label: "?"
                    x: 2 * (rect.width) / 4
                    y: 0

                    Text {
                        id: xobutton3Label
                        text: grid.a_0_2
                        color: "#8F7A66"
                        font.family: "Arial"
                        font.bold: true
                        font.pointSize: 35
                        anchors.centerIn: parent
                    }
                }
                Rectangle {
                    id: xobutton4
                    width: 425 / 4
                    height: 425 / 4
                    radius: 3
                    color: Qt.rgba(238 / 255, 228 / 255, 218 / 255, 0.35)
                    property string label: "?"
                    x: 3 * (rect.width) / 4
                    y: 0

                    Text {
                        id: xobutton4Label
                        text: grid.a_0_3
                        color: "#8F7A66"
                        font.family: "Arial"
                        font.bold: true
                        font.pointSize: 35
                        anchors.centerIn: parent
                    }
                }
                Rectangle {
                    id: xobutton5
                    width: 425 / 4
                    height: 425 / 4
                    radius: 3
                    color: Qt.rgba(238 / 255, 228 / 255, 218 / 255, 0.35)
                    property string label: "?"
                    x: 0
                    y: (rect.width) / 4

                    Text {
                        id: xobutton5Label
                        text: grid.a_1_0
                        anchors.verticalCenterOffset: 0
                        anchors.horizontalCenterOffset: 1
                        color: "#8F7A66"
                        font.family: "Arial"
                        font.bold: true
                        font.pointSize: 35
                        anchors.centerIn: parent
                    }
                }
                Rectangle {
                    id: xobutton6
                    width: 425 / 4
                    height: 425 / 4
                    radius: 3
                    color: Qt.rgba(238 / 255, 228 / 255, 218 / 255, 0.35)
                    property string label: "?"
                    x: (rect.width) / 4
                    y: (rect.width) / 4

                    Text {
                        id: xobutton6Label
                        text: grid.a_1_1
                        color: "#8F7A66"
                        font.family: "Arial"
                        font.bold: true
                        font.pointSize: 35
                        anchors.centerIn: parent
                    }
                }
                Rectangle {
                    id: xobutton7
                    width: 425 / 4
                    height: 425 / 4
                    radius: 3
                    color: Qt.rgba(238 / 255, 228 / 255, 218 / 255, 0.35)
                    property string label: "?"
                    x: 2 * (rect.width) / 4
                    y: (rect.width) / 4

                    Text {
                        id: xobutton7Label
                        text: grid.a_1_2
                        color: "#8F7A66"
                        font.family: "Arial"
                        font.bold: true
                        font.pointSize: 35
                        anchors.centerIn: parent
                    }
                }
                Rectangle {
                    id: xobutton8
                    width: 425 / 4
                    height: 425 / 4
                    radius: 3
                    color: Qt.rgba(238 / 255, 228 / 255, 218 / 255, 0.35)
                    property string label: "?"
                    x: 3 * (rect.width) / 4
                    y: (rect.width) / 4

                    Text {
                        id: xobutton8Label
                        text: grid.a_1_3
                        color: "#8F7A66"
                        font.family: "Arial"
                        font.bold: true
                        font.pointSize: 35
                        anchors.centerIn: parent
                    }
                }
                Rectangle {
                    id: xobutton9
                    width: 425 / 4
                    height: 425 / 4
                    radius: 3
                    color: Qt.rgba(238 / 255, 228 / 255, 218 / 255, 0.35)
                    property string label: "?"
                    x: 0
                    y: 2 * (rect.width) / 4

                    Text {
                        id: xobutton9Label
                        text: grid.a_2_0
                        color: "#8F7A66"
                        font.family: "Arial"
                        font.bold: true
                        font.pointSize: 35
                        anchors.centerIn: parent
                    }
                }
                Rectangle {
                    id: xobutton10
                    width: 425 / 4
                    height: 425 / 4
                    radius: 3
                    color: Qt.rgba(238 / 255, 228 / 255, 218 / 255, 0.35)
                    property string label: "?"
                    x: (rect.width) / 4
                    y: 2 * (rect.width) / 4

                    Text {
                        id: xobutton10Label
                        text: grid.a_2_1
                        color: "#8F7A66"
                        font.family: "Arial"
                        font.bold: true
                        font.pointSize: 35
                        anchors.centerIn: parent
                    }
                }
                Rectangle {
                    id: xobutton11
                    width: 425 / 4
                    height: 425 / 4
                    radius: 3
                    color: Qt.rgba(238 / 255, 228 / 255, 218 / 255, 0.35)
                    property string label: "?"
                    x: 2 * (rect.width) / 4
                    y: 2 * (rect.width) / 4

                    Text {
                        id: xobutton11Label
                        text: grid.a_2_2
                        color: "#8F7A66"
                        font.family: "Arial"
                        font.bold: true
                        font.pointSize: 35
                        anchors.centerIn: parent
                    }
                }
                Rectangle {
                    id: xobutton12
                    width: 425 / 4
                    height: 425 / 4
                    radius: 3
                    color: Qt.rgba(238 / 255, 228 / 255, 218 / 255, 0.35)
                    property string label: "?"
                    x: 3 * (rect.width) / 4
                    y: 2 * (rect.width) / 4

                    Text {
                        id: xobutton12Label
                        text: grid.a_2_3
                        color: "#8F7A66"
                        font.family: "Arial"
                        font.bold: true
                        font.pointSize: 35
                        anchors.centerIn: parent
                    }
                }
                Rectangle {
                    id: xobutton13
                    width: 425 / 4
                    height: 425 / 4
                    radius: 3
                    color: Qt.rgba(238 / 255, 228 / 255, 218 / 255, 0.35)
                    property string label: "?"
                    x: 0
                    y: 3 * (rect.width) / 4

                    Text {
                        id: xobutton13Label
                        text: grid.a_3_0
                        color: "#8F7A66"
                        font.family: "Arial"
                        font.bold: true
                        font.pointSize: 35
                        anchors.centerIn: parent
                    }
                }
                Rectangle {
                    id: xobutton14
                    width: 425 / 4
                    height: 425 / 4
                    radius: 3
                    color: Qt.rgba(238 / 255, 228 / 255, 218 / 255, 0.35)
                    property string label: "?"
                    x: (rect.width) / 4
                    y: 3 * (rect.width) / 4

                    Text {
                        id: xobutton14Label
                        text: grid.a_3_1
                        anchors.verticalCenterOffset: 0
                        anchors.horizontalCenterOffset: 1
                        color: "#8F7A66"
                        font.family: "Arial"
                        font.bold: true
                        font.pointSize: 35
                        anchors.centerIn: parent
                    }
                }
                Rectangle {
                    id: xobutton15
                    width: 425 / 4
                    height: 425 / 4
                    radius: 3
                    color: Qt.rgba(238 / 255, 228 / 255, 218 / 255, 0.35)
                    property string label: "?"
                    x: 2 * (rect.width) / 4
                    y: 3 * (rect.width) / 4

                    Text {
                        id: xobutton15Label
                        text: grid.a_3_2
                        anchors.verticalCenterOffset: 0
                        anchors.horizontalCenterOffset: -8
                        color: "#8F7A66"
                        font.family: "Arial"
                        font.bold: true
                        font.pointSize: 35
                        anchors.centerIn: parent
                    }
                }
                Rectangle {
                    id: xobutton16
                    width: 425 / 4
                    height: 425 / 4
                    radius: 3
                    color: Qt.rgba(238 / 255, 228 / 255, 218 / 255, 0.35)
                    property string label: "?"
                    x: 3 * (rect.width) / 4
                    y: 3 * (rect.width) / 4

                    Text {
                        id: xobutton16Label
                        text: grid.a_3_3
                        anchors.verticalCenterOffset: 0
                        anchors.horizontalCenterOffset: -5
                        color: "#8F7A66"
                        font.family: "Arial"
                        font.bold: true
                        font.pointSize: 35
                        anchors.centerIn: parent
                    }
                }
            }
        }
    }

    MessageDialog {
        id: deadMessage
        title: qsTr("Game Over")
        text: qsTr("Game Over!")
        standardButtons: StandardButton.Retry | StandardButton.Abort
        onAccepted: {
            grid.key_press_restart()
        }
        onRejected: grid.key_press_quit()
    }

    MessageDialog {
        id: winMessage
        title: qsTr("You Win")
        text: qsTr("You win! Continue ?")
        standardButtons: StandardButton.Yes | StandardButton.No
        onYes: {
            grid.key_press_restart()
            close()
        }
        onNo: grid.key_press_quit()
        onRejected: {
            grid.key_press_quit()
            close()
        }
    }

    Keys.onPressed: {
        switch (event.key) {
        case Qt.Key_Up:
            grid.key_press_up()
            console.log('up')
            break
        case Qt.Key_Down:
            grid.key_press_down()
            console.log('down')
            break
        case Qt.Key_Right:
            grid.key_press_right()
            console.log('right')
            break
        case Qt.Key_Left:
            grid.key_press_left()
            console.log('left')
            break
        }
    }
}


/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
