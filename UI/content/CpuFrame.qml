import QtQuick 2.8
import backend 1.0
import qdsproject 1.0
import QtQuick.Studio.Components 1.0
import QtQuick.Studio.LogicHelper 1.0

Item {
    id: cpuFrame
    width: 400
    height: 400

    Item {
        id: backgroundElipse
        x: 0
        y: 0
        width: 400
        height: 400
        Image {
            id: backgroundElipse1
            x: 0
            y: 0
            source: "../assets/backgroundElipse1.png"
        }
    }

    Item {
        id: outlineElipse
        x: 0
        y: 0
        width: 400
        height: 400
        Image {
            id: outlineElipse1
            x: 0
            y: 0
            source: "../assets/outlineElipse1.png"

            ArcItem {
                id: arc
                x: 15
                y: 16
                width: 369
                height: 370
                end: rangeMapper.output
                begin: -180
                capStyle: 32
                strokeWidth: 14
                strokeColor: "#e9e755"
                fillColor: "#00000000"
            }
        }
    }

    CpuNumberElement {
        id: timerElement
        x: 59
        y: 115
        width: 282
        height: 194
        _45Text: BackendObject.time
        minutesRemainingText: "CPU Usage"
    }

    RangeMapper {
        id: rangeMapper
        input: BackendObject.percentage
        outputMaximum: 360
    }
}



