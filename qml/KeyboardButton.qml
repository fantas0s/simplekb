import QtQuick 2.0
import QtQuick.Window 2.0

Rectangle {
    id: keyRoot
    property string text: "-"
    border.color: "#404040"
    radius: 5
    color: "#202020"
    width: keyText.width + 10
    height: keyText.height + 10
    Text {
        id: keyText
        color: "white"
        anchors.centerIn: parent
        text: keyRoot.text
        font.pixelSize: Screen.height / 50
    }
    MouseArea {
        anchors.fill: parent
        onPressed: {
            keyRoot.color = "#404040"
            keyRoot.border.color = "#202020"
            keyboardRoot.keyPressed(keyRoot.text)
        }
        onReleased: {
            keyRoot.color = "#202020"
            keyRoot.border.color = "#404040"
            keyboardRoot.keyReleased(keyRoot.text)
        }
    }
}
