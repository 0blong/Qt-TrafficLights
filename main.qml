import QtQuick 2.5
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Traffic Lights")

    TrafficLight {
        id: idTrafficLight
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.margins: 20
    }

    WalkSign {
        id: idWalkSign
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.margins: 20
    }

    ButtonSquare {
        id: idButtonCross
        anchors.horizontalCenter: idWalkSign.horizontalCenter
        anchors.top: idWalkSign.bottom
        anchors.margins: 40
        width: 60
        height: 60
        radius: 3
        color: "white"
        border.color: "black"
    }
}
