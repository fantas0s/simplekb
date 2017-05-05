import QtQuick 2.0
import QtQuick.Window 2.2

Item {
    id: keyboardRoot
    visible: true
    width: Screen.width
    height: Screen.height
    x: 0
    y: 0
    signal keyPressed(string key)
    signal keyReleased(string key)
    signal functionkeyPressed(int keyCode, string key)
    signal functionkeyReleased(int keyCode, string key)
    MouseArea {
        id: grasptouch
        height: parent.height * 3 / 4
        width: parent.width
        anchors.top: parent.top
        anchors.left: parent.left
        onPressed: {
            Qt.inputMethod.hide();
            mouse.accepted = false;
        }
    }
    Rectangle {
        height: parent.height - grasptouch.height
        width: parent.width
        anchors.top: grasptouch.bottom
        anchors.left: parent.left
        color: "#202020"
        Column {
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 10
            spacing: 5
            Row {
                anchors.horizontalCenter: parent.horizontalCenter
                spacing: 5
                KeyboardButton {text: "1"}
                KeyboardButton {text: "2"}
                KeyboardButton {text: "3"}
                KeyboardButton {text: "4"}
                KeyboardButton {text: "5"}
                KeyboardButton {text: "6"}
                KeyboardButton {text: "7"}
                KeyboardButton {text: "8"}
                KeyboardButton {text: "9"}
                KeyboardButton {text: "0"}
                KeyboardFunctionButton {text: "<-"}
            }
            Row {
                anchors.horizontalCenter: parent.horizontalCenter
                spacing: 5
                KeyboardButton {text: "Q"}
                KeyboardButton {text: "W"}
                KeyboardButton {text: "E"}
                KeyboardButton {text: "R"}
                KeyboardButton {text: "T"}
                KeyboardButton {text: "Y"}
                KeyboardButton {text: "U"}
                KeyboardButton {text: "I"}
                KeyboardButton {text: "O"}
                KeyboardButton {text: "P"}
                KeyboardButton {text: "Å"}
            }
            Row {
                anchors.horizontalCenter: parent.horizontalCenter
                spacing: 5
                KeyboardButton {text: "A"}
                KeyboardButton {text: "S"}
                KeyboardButton {text: "D"}
                KeyboardButton {text: "F"}
                KeyboardButton {text: "G"}
                KeyboardButton {text: "H"}
                KeyboardButton {text: "J"}
                KeyboardButton {text: "K"}
                KeyboardButton {text: "L"}
                KeyboardButton {text: "Ö"}
                KeyboardButton {text: "Ä"}
            }
            Row {
                anchors.horizontalCenter: parent.horizontalCenter
                spacing: 5
                KeyboardButton {text: "Z"}
                KeyboardButton {text: "X"}
                KeyboardButton {text: "C"}
                KeyboardButton {text: "V"}
                KeyboardButton {text: "B"}
                KeyboardButton {text: "N"}
                KeyboardButton {text: "M"}
                KeyboardButton {text: ","}
                KeyboardButton {text: "."}
            }
            Row {
                anchors.horizontalCenter: parent.horizontalCenter
                spacing: 5
                KeyboardFunctionButton {text: " "}
            }
        }
    }
}
