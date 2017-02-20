import QtQuick 2.5
import WalkSignModule 1.0

Item {
    width: idImg.width
    height: idImg.height

    Image {
        id: idImg
        source: "walk.jpg"
    }

    Rectangle {
        id: idStop
        x: 10
        y: 10
        width: 87
        height: 70
        color: "black"
    }

    Rectangle {
        id: idWalk
        x: 10
        y: 104
        width: 87
        height: 72
        color: "black"
    }

//    onStateChanged: walkSign.iSawYou()

    states: [
        State {
            id: idStateWalk
            name: "WALK"
            when: walkSign.walkState === WalkSign.WALK
            PropertyChanges {
                    target: idStop
                    opacity: 100
            }
            PropertyChanges {
                    target: idWalk
                    opacity: 0
            }            
        },
        State {
            id: idStateDONTWALK
            name: "DONTWALK"
            when: walkSign.walkState === WalkSign.DONTWALK
            PropertyChanges {
                target: idStop
                opacity: 0
            }
            PropertyChanges {
                target: idWalk
                opacity: 100
            }
        },
        State {
            id: idStateFLASHON
            name: "FLASHON"
            when: walkSign.walkState === WalkSign.FLASHON
            PropertyChanges {
                target: idStop
                opacity: 100
            }
            PropertyChanges {
                target: idWalk
                opacity: 0
            }
        },
        State {
            id: idStateFLASHOFF
            name: "FLASHOFF"
            when: walkSign.walkState === WalkSign.FLASHOFF
            PropertyChanges {
                target: idStop
                opacity: 100
            }
            PropertyChanges {
                target: idWalk
                opacity: 100
            }
        }       
    ]

    transitions: [
        Transition {
            id: idTransition
            PropertyAnimation {
                property: "opacity"
                duration: 400
            }
        }
    ]
}
