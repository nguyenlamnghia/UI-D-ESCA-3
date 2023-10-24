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
        anchors.horizontalCenterOffset: 0
        anchors.horizontalCenter: parent.horizontalCenter

    }

    CpuFrame{
        x: 53
        y: 100
        width: 211
        height: 213
    }


}
