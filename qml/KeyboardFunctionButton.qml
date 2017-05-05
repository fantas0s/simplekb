import QtQuick 2.0
import QtQuick.Window 2.0
Rectangle {
    id: keyRoot
    property string text: "-"
    property string buttontext: text
    border.color: "#404040"
    radius: 5
    color: "#202020"
    width: keyText.width + 10
    height: keyText.height + 10
    Component.onCompleted: {
        updateButtontext()
    }
    onTextChanged: {
        updateButtontext()
    }
    function updateButtontext() {
        if (" " === keyRoot.text)
            keyRoot.buttontext = "Space"
        else if ("<-" === keyRoot.text)
            keyRoot.buttontext = "\u232B"
        else
            keyRoot.buttontext = text
    }
    function getButtonCode() {
        if (" " === keyRoot.text)
            return Qt.Key_Space
        else if ("<-" === keyRoot.text)
            return Qt.Key_Backspace
        else
            return Qt.Key_unknown
    }
    Text {
        id: keyText
        color: "white"
        anchors.centerIn: parent
        text: keyRoot.buttontext
        font.pixelSize: Screen.height / 50
    }
    MouseArea {
        anchors.fill: parent
        onPressed: {
            keyRoot.color = "#404040"
            keyRoot.border.color = "#202020"
            keyboardRoot.functionkeyPressed(getButtonCode(), keyRoot.text)
        }
        onReleased: {
            keyRoot.color = "#202020"
            keyRoot.border.color = "#404040"
            keyboardRoot.functionkeyReleased(getButtonCode(), keyRoot.text)
        }
    }
}
