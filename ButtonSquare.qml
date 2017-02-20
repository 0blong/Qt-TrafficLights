import QtQuick 2.5
import TrafficLightButton 1.0

Rectangle {

    anchors.margins: 10
    Rectangle {
        id: idButtonCross
        radius: 3
        anchors.fill: parent
        anchors.margins: 5
        color: "black"

        Text {
            id: idText
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            color: "white"
            text: "PUSH"
            font.bold: true
        }

        onStateChanged: trafficLightButton.output

        states: [
            State {
                id: idStateWAIT
                name: "WAIT"
                when: trafficLightButton.buttonState === TrafficButton.WAIT
                PropertyChanges {
                    target: idText
                    text: "WAIT"
                }
            },
            State {
                id: idStateCROSS
                name: "CROSS"
                when: trafficLightButton.buttonState === TrafficButton.CROSS
                PropertyChanges {
                    target: idText
                    text: "CROSS"
                }
            },
            State {
                id: idStatePUSH
                name: "PUSH"
                when: trafficLightButton.buttonState === TrafficButton.PUSH
                PropertyChanges {
                    target: idText
                    text: "PUSH"
                }
            },
            State {
                id: idStateOFF
                name: "OFF"
                when: trafficLightButton.buttonState === TrafficButton.OFF
                PropertyChanges {
                    target: idText
                    text: ""
                }
            }
        ]

        transitions: [
            Transition {
                id: idTransition
                PropertyAnimation {
                    property: "text"
                    duration: 100
                }
            }
        ]





        MouseArea {
            anchors.fill: parent
            onClicked: {
                trafficWalk.doLightStateChange()
            }
        }
    }
}
