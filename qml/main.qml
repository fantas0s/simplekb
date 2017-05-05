import QtQuick 2.0
import QtQuick.Window 2.0

Window {
    width: Screen.width
    height: Screen.height
    visible: true
    color: "blue"
    MouseArea {
        anchors.fill: parent
        onClicked: {
            console.log("Main window clicked");
        }
    }
    KeyboardContainer {
        onKeyPressed: {
            console.log("Key", key ,"pressed")
        }
        onKeyReleased: {
            console.log("Key", key ,"released")
        }
        onFunctionkeyPressed: {
            console.log("Key", key ,"pressed, code", keyCode)
        }
        onFunctionkeyReleased: {
            console.log("Key", key ,"released, code", keyCode)
        }
    }
}
