import QtQuick 2.15
import QtQuick.Controls 2.15

Rectangle {
    id: rectangle8
    width: 650
    height: 50
    color: "#000000"
    Rectangle {
        id: rectangle9
        x: -60
        y: -30
        width: 100
        height: 50
        color: "#000000"
        rotation: 54
    }

    Rectangle {
        id: rectangle10
        x: 610
        y: -30
        width: 100
        height: 50
        color: "#000000"
        rotation: -54
    }
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

