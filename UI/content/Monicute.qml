import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    width: 1024
    height: 500
    Rectangle{
        width: 1024
        height: 500
        anchors.centerIn: parent

        Text {
            id: text1
            x: 589
            y: 82
            width: 332
            height: 92
            text: qsTr("dday la man hinh lop truong")
            font.pixelSize: 12
        }
    }
}
