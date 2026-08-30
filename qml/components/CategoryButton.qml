import QtQuick
import QtQuick.Controls

Button {
    id: control

    required property color textColor
    required property color accentColor
    required property color accentWash
    required property color borderColor
    property bool selected: false

    checkable: true
    checked: selected
    hoverEnabled: true
    leftPadding: 14
    rightPadding: 14
    topPadding: 10
    bottomPadding: 10

    contentItem: Text {
        text: control.text
        color: control.enabled ? control.textColor : Qt.alpha(control.textColor, 0.45)
        font.weight: control.selected ? Font.DemiBold : Font.Normal
        elide: Text.ElideRight
        verticalAlignment: Text.AlignVCenter
    }

    background: Rectangle {
        radius: 9
        color: control.down ? Qt.alpha(control.accentColor, 0.22)
                            : (control.selected || control.hovered ? control.accentWash : "transparent")
        border.width: control.activeFocus ? 2 : (control.selected ? 1 : 0)
        border.color: control.activeFocus ? control.accentColor : control.borderColor

        Behavior on color { ColorAnimation { duration: 100 } }
    }

    Accessible.name: text
    Accessible.role: Accessible.Button
}
