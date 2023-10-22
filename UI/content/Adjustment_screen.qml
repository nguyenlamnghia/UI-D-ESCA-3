import QtQuick 2.15
import QtQuick.Controls 2.15
import UI 1.0

Rectangle {
    id: rectangle
    width: Constants.width
    height: Constants.height
    color: Constants.backgroundColor
    NavigationBar {
        id: navBar
        width: 1024
        height: 50
        anchors.bottom: parent.bottom
    }
    TopBar{
        id: topBar
        width: 650
        height: 50
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter

    }

    Image {
        id: image
        x: 6
        y: 4
        width: 45
        height: 74
        source: "../assets/logo-hust.png"
        fillMode: Image.PreserveAspectFit
    }
}
