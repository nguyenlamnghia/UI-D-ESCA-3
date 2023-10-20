/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/

import QtQuick 2.15
import QtQuick.Controls 2.15
import UI 1.0

Rectangle {
    id: rectangle
    width: Constants.width
    height: Constants.height

    color: Constants.backgroundColor

    Rectangle {
        id: rectangle1
        width: 1024
        height: 50
        color: "#000000"
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0

        Rectangle {
            id: rectangle2
            width: 220
            height: 50
            color: "#000000"
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.leftMargin: 0
            anchors.topMargin: 0

            Text {
                id: text1
                color: "#ffffff"
                text: qsTr("Main Menu")
                anchors.verticalCenter: parent.verticalCenter
                font.pixelSize: 20
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }

        Rectangle {
            id: rectangle3
            y: 0
            width: 2
            height: 50
            color: "#ffffff"
            anchors.left: rectangle2.right
        }

        Rectangle {
            id: rectangle4
            width: 220
            height: 50
            color: "#000000"
            anchors.left: rectangle3.right
            Text {
                id: text2
                color: "#ffffff"
                text: qsTr("File Components")
                anchors.verticalCenter: parent.verticalCenter
                font.pixelSize: 20
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }

        Rectangle {
            id: rectangle5
            width: 220
            height: 50
            color: "#000000"
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.topMargin: 0
            Text {
                id: text3
                color: "#ffffff"
                text: qsTr("Adjust Parameter")
                anchors.verticalCenter: parent.verticalCenter
                font.pixelSize: 20
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }

        Rectangle {
            id: rectangle6
            y: 0
            width: 2
            height: 50
            color: "#ffffff"
            anchors.right: rectangle5.left
        }

        Rectangle {
            id: rectangle7
            width: 220
            height: 50
            color: "#000000"
            anchors.right: rectangle6.left
            Text {
                id: text4
                color: "#ffffff"
                text: qsTr("Monitor System")
                anchors.verticalCenter: parent.verticalCenter
                font.pixelSize: 20
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }
    }

    Image {
        id: image
        x: 426
        y: 466
        width: 172
        height: 162
        source: "../assets/robot.png"
        fillMode: Image.PreserveAspectFit
    }

    Rectangle {
        id: rectangle9
        x: 127
        y: -30
        width: 100
        height: 50
        color: "#000000"
        rotation: 54
    }

    Rectangle {
        id: rectangle10
        x: 797
        y: -31
        width: 100
        height: 50
        color: "#000000"
        rotation: -54
    }
    Rectangle {
        id: rectangle8
        width: 650
        height: 50
        color: "#000000"
        anchors.top: parent.top
        anchors.horizontalCenterOffset: 0
        anchors.topMargin: 0
        anchors.horizontalCenter: parent.horizontalCenter

        Text {
            id: text5
            color: "#ffffff"
            text: qsTr("D-ESCA-3")
            anchors.verticalCenter: parent.verticalCenter
            font.pixelSize: 30
            anchors.horizontalCenter: parent.horizontalCenter
            font.bold: true
        }

        Image {
            id: image1
            width: 30
            height: 30
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            source: "../assets/setting-icon.png"
            anchors.verticalCenterOffset: 0
            anchors.leftMargin: 20
            fillMode: Image.PreserveAspectFit
        }

        Rectangle {
            id: rectangle11
            y: 0
            width: 106
            height: 50
            color: "#000000"
            anchors.left: image1.right
            anchors.leftMargin: 28

            Text {
                id: text6
                y: 5
                color: "#ffffff"
                text: qsTr("12:00 PM")
                font.pixelSize: 16
                anchors.horizontalCenterOffset: 0
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Text {
                id: text7
                x: -6
                y: 28
                color: "#ffffff"
                text: qsTr("18/10/2023")
                font.pixelSize: 16
                anchors.horizontalCenterOffset: 0
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }

        Rectangle {
            id: rectangle12
            x: 498
            y: 17
            width: 20
            height: 20
            color: "#00ffc8"
            radius: 10
        }

        Text {
            id: text8
            x: 432
            y: 17
            color: "#ffffff"
            text: qsTr("Running")
            font.pixelSize: 16
        }

        Image {
            id: image2
            x: 544
            y: 13
            width: 30
            height: 30
            anchors.right: image3.left
            source: "../assets/wifi-icon.png"
            anchors.rightMargin: 10
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: image3
            x: 595
            y: 13
            width: 30
            height: 30
            anchors.right: parent.right
            source: "../assets/bluetooth-icon.png"
            anchors.rightMargin: 20
            fillMode: Image.PreserveAspectFit
        }
    }
}
