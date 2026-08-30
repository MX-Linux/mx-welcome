import QtQuick
import QtQuick.Controls

AbstractButton {
    id: card

    required property string actionId
    required property string title
    required property string description
    required property string category
    required property url iconSource
    required property color surfaceColor
    required property color primaryTextColor
    required property color mutedTextColor
    required property color accentColor
    required property color accentWash
    required property color borderColor

    hoverEnabled: true
    focusPolicy: Qt.StrongFocus

    background: Rectangle {
        radius: 14
        color: card.down ? Qt.alpha(card.accentColor, 0.18)
                         : (card.hovered ? card.accentWash : card.surfaceColor)
        border.width: card.activeFocus ? 2 : 1
        border.color: card.activeFocus ? card.accentColor
                                       : (card.hovered ? Qt.alpha(card.accentColor, 0.55) : card.borderColor)
        scale: card.down ? 0.985 : 1

        Behavior on color { ColorAnimation { duration: 110 } }
        Behavior on border.color { ColorAnimation { duration: 110 } }
        Behavior on scale { NumberAnimation { duration: 80 } }
    }

    contentItem: Item {
        Image {
            id: icon
            anchors.left: parent.left
            anchors.top: parent.top
            width: 48
            height: 48
            source: card.iconSource
            sourceSize: Qt.size(64, 64)
            fillMode: Image.PreserveAspectFit
            asynchronous: true
        }

        Text {
            id: titleText
            anchors.left: icon.right
            anchors.leftMargin: 14
            anchors.right: parent.right
            anchors.top: parent.top
            text: card.title
            color: card.primaryTextColor
            font.pixelSize: Application.font.pixelSize > 0 ? Application.font.pixelSize + 2 : 15
            font.weight: Font.DemiBold
            elide: Text.ElideRight
        }

        Text {
            id: categoryText
            anchors.left: titleText.left
            anchors.right: parent.right
            anchors.top: titleText.bottom
            anchors.topMargin: 4
            text: card.category
            color: card.mutedTextColor
            font.pixelSize: Application.font.pixelSize > 0 ? Math.max(10, Application.font.pixelSize - 1) : 12
            elide: Text.ElideRight
        }

        Text {
            id: descriptionText
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: icon.bottom
            anchors.topMargin: 14
            text: card.description.length > 0 ? card.description : qsTr("Open this tool")
            color: card.mutedTextColor
            font: Application.font
            wrapMode: Text.Wrap
            maximumLineCount: 3
            elide: Text.ElideRight
        }
    }

    leftPadding: 18
    rightPadding: 18
    topPadding: 18
    bottomPadding: 18

    ToolTip.visible: hovered && descriptionText.truncated
    ToolTip.text: descriptionText.text
    ToolTip.delay: 600

    Accessible.name: title
    Accessible.description: description
    Accessible.role: Accessible.Button
}
