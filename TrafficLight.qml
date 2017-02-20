import QtQuick 2.5
import TrafficWalkModule 1.0

Rectangle {
    id: idTrafficLight
    width: 150
    height: 375
    color: "black"

    Rectangle {
        x: 25
        y: 15
        width: 100
        height: 100
        radius: 50
        color: "black"
        border.color: "red"
        Rectangle {
            id: idRedLight
            anchors.fill: parent
            anchors.margins: 3
            color: "red"
            opacity: 0
            radius:50
        }
    }

    Rectangle {
        x: 25
        y: 135
        width: 100
        height: 100
        radius: 50
        color: "black"
        border.color: "orange"
        Rectangle {
            id: idAmberLight
            anchors.fill: parent
            anchors.margins: 3
            color: "orange"
            opacity: 0
            radius:50
        }
    }

    Rectangle {
        x: 25
        y: 255
        width: 100
        height: 100
        radius: 50
        color: "black"
        border.color: "green"
        Rectangle {
            id: idGreenLight
            anchors.fill: parent
            anchors.margins: 3
            color: "green"
            opacity: 0
            radius:50
        }
    }

    states: [
        State {
            id: idStateStop
            name: "STOP"
            when: trafficWalk.lightState === TrafficWalk.STOP || trafficWalk.lightState === TrafficWalk.FLASH
            PropertyChanges {
                target: idRedLight
                opacity: 100
            }
            PropertyChanges {
                target: idAmberLight
                opacity: 0
            }
            PropertyChanges {
                target: idGreenLight
                opacity: 0
            }
        },
        State {
            id: idStateGo
            name: "GO"
            when: trafficWalk.lightState === TrafficWalk.GO
            PropertyChanges {
                target: idRedLight
                opacity: 0
            }
            PropertyChanges {
                target: idAmberLight
                opacity: 0
            }
            PropertyChanges {
                target: idGreenLight
                opacity: 100
            }
        },
        State {
            id: idStateSlow
            name: "SLOW"
            when: trafficWalk.lightState === TrafficWalk.SLOW
            PropertyChanges {
                target: idRedLight
                opacity: 0
            }
            PropertyChanges {
                target: idAmberLight
                opacity: 100
            }
            PropertyChanges {
                target: idGreenLight
                opacity: 0
            }
        }
    ]

    transitions: [
        Transition {
            id: idTransition
            PropertyAnimation {
                property: "opacity"
                duration: 500
            }
        }
    ]
}
