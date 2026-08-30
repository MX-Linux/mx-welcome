pragma ComponentBehavior: Bound

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtCore
import "components"

ApplicationWindow {
    id: root

    required property var backend

    visible: true
    width: windowSettings.windowWidth
    height: windowSettings.windowHeight
    minimumWidth: 680
    minimumHeight: 560
    title: qsTr("MX Welcome")
    color: backgroundColor

    readonly property bool wideLayout: width >= 820
    readonly property real baseFontSize: Application.font.pixelSize > 0 ? Application.font.pixelSize : 13

    SystemPalette {
        id: systemPalette
        colorGroup: root.active ? SystemPalette.Active : SystemPalette.Inactive
    }

    readonly property color backgroundColor: systemPalette.window
    readonly property color surfaceColor: systemPalette.base
    readonly property color primaryTextColor: systemPalette.text
    readonly property color accentColor: systemPalette.highlight
    readonly property color highlightedTextColor: systemPalette.highlightedText
    readonly property color mutedTextColor: Qt.alpha(systemPalette.text, 0.68)
    readonly property color borderColor: Qt.alpha(systemPalette.text, 0.18)
    readonly property color accentWash: Qt.alpha(systemPalette.highlight, 0.13)
    readonly property color raisedColor: Qt.alpha(systemPalette.text, 0.055)

    property int currentPage: root.backend.startOnAbout ? 1 : 0

    Settings {
        id: windowSettings
        category: "Window"
        property int windowWidth: 1040
        property int windowHeight: 720
    }

    onClosing: function(close) {
        windowSettings.windowWidth = width
        windowSettings.windowHeight = height
    }

    function showDocument(title, text, richText) {
        documentDialog.title = title
        documentText.textFormat = richText ? TextEdit.RichText : TextEdit.PlainText
        documentText.text = text
        documentDialog.open()
    }

    Connections {
        target: root.backend
        function onErrorOccurred(title, message) {
            errorDialog.title = title
            errorDialog.text = message
            errorDialog.open()
        }
    }

    ColumnLayout {
        anchors.fill: parent
        spacing: 0

        Rectangle {
            Layout.fillWidth: true
            Layout.preferredHeight: root.backend.headerSource.toString().length > 0 ? 112 : 88
            color: root.surfaceColor

            Image {
                anchors.fill: parent
                source: root.backend.headerSource
                fillMode: Image.PreserveAspectCrop
                opacity: 0.22
                visible: source.toString().length > 0
            }

            RowLayout {
                anchors.fill: parent
                anchors.leftMargin: 24
                anchors.rightMargin: 20
                spacing: 14

                Image {
                    Layout.preferredWidth: 56
                    Layout.preferredHeight: 56
                    source: root.backend.logoSource.toString().length > 0
                            ? root.backend.logoSource : "image://icons/mx-welcome"
                    sourceSize: Qt.size(72, 72)
                    fillMode: Image.PreserveAspectFit
                }

                ColumnLayout {
                    Layout.fillWidth: true
                    spacing: 3

                    Text {
                        Layout.fillWidth: true
                        text: qsTr("MX Welcome")
                        color: root.primaryTextColor
                        font.pixelSize: root.baseFontSize + 8
                        font.weight: Font.DemiBold
                        elide: Text.ElideRight
                    }
                    Text {
                        Layout.fillWidth: true
                        text: root.backend.distroTitle
                        color: root.mutedTextColor
                        font.pixelSize: root.baseFontSize
                        elide: Text.ElideRight
                    }
                }

                SecondaryButton {
                    text: qsTr("Manual")
                    visible: root.width >= 760
                    textColor: root.primaryTextColor
                    surfaceColor: root.surfaceColor
                    hoverColor: root.accentWash
                    borderColor: root.borderColor
                    accentColor: root.accentColor
                    onClicked: root.backend.activate("manual")
                }

                SecondaryButton {
                    text: qsTr("About")
                    textColor: root.primaryTextColor
                    surfaceColor: root.surfaceColor
                    hoverColor: root.accentWash
                    borderColor: root.borderColor
                    accentColor: root.accentColor
                    onClicked: aboutDialog.open()
                }
            }

            Rectangle {
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.bottom: parent.bottom
                height: 1
                color: root.borderColor
            }
        }

        Rectangle {
            Layout.fillWidth: true
            Layout.preferredHeight: liveInfoText.implicitHeight + 20
            visible: root.backend.showLiveUserInfo
            color: root.accentWash

            Text {
                id: liveInfoText
                anchors.fill: parent
                anchors.margins: 10
                text: root.backend.liveUserInfo
                color: root.primaryTextColor
                wrapMode: Text.Wrap
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                Accessible.name: text
            }
        }

        RowLayout {
            Layout.fillWidth: true
            Layout.fillHeight: true
            spacing: 0

            Rectangle {
                Layout.fillHeight: true
                Layout.preferredWidth: 206
                visible: root.wideLayout
                color: root.raisedColor

                ColumnLayout {
                    anchors.fill: parent
                    anchors.margins: 14
                    spacing: 5

                    CategoryButton {
                        Layout.fillWidth: true
                        text: qsTr("Welcome")
                        selected: root.currentPage === 0
                        textColor: root.primaryTextColor
                        accentColor: root.accentColor
                        accentWash: root.accentWash
                        borderColor: root.borderColor
                        onClicked: root.currentPage = 0
                    }
                    CategoryButton {
                        Layout.fillWidth: true
                        text: qsTr("About this system")
                        selected: root.currentPage === 1
                        textColor: root.primaryTextColor
                        accentColor: root.accentColor
                        accentWash: root.accentWash
                        borderColor: root.borderColor
                        onClicked: {
                            root.currentPage = 1
                            root.backend.requestSystemInfo()
                        }
                    }

                    Rectangle {
                        Layout.fillWidth: true
                        Layout.topMargin: 8
                        Layout.bottomMargin: 8
                        Layout.preferredHeight: 1
                        color: root.borderColor
                    }

                    Text {
                        Layout.fillWidth: true
                        visible: root.currentPage === 0
                        text: qsTr("Categories")
                        color: root.mutedTextColor
                        font.weight: Font.DemiBold
                        leftPadding: 14
                    }

                    Repeater {
                        model: root.backend.categories
                        CategoryButton {
                            required property int index
                            required property string modelData
                            Layout.fillWidth: true
                            visible: root.currentPage === 0
                            text: modelData
                            selected: root.backend.selectedCategory === modelData
                                      || (index === 0 && root.backend.selectedCategory.length === 0)
                            textColor: root.primaryTextColor
                            accentColor: root.accentColor
                            accentWash: root.accentWash
                            borderColor: root.borderColor
                            onClicked: root.backend.selectedCategory = modelData
                        }
                    }

                    Item { Layout.fillHeight: true }

                    CheckBox {
                        Layout.fillWidth: true
                        visible: !root.backend.liveSession
                        text: qsTr("Show at startup")
                        checked: root.backend.autoStartup
                        onToggled: root.backend.autoStartup = checked
                        Accessible.description: qsTr("Show MX Welcome when you log in")
                    }
                }
            }

            Rectangle {
                Layout.preferredWidth: 1
                Layout.fillHeight: true
                visible: root.wideLayout
                color: root.borderColor
            }

            StackLayout {
                Layout.fillWidth: true
                Layout.fillHeight: true
                currentIndex: root.currentPage

                Item {
                    ColumnLayout {
                        anchors.fill: parent
                        anchors.margins: root.wideLayout ? 22 : 16
                        spacing: 14

                        RowLayout {
                            Layout.fillWidth: true
                            spacing: 10

                            TextField {
                                id: searchField
                                Layout.fillWidth: true
                                placeholderText: qsTr("Search tools and resources")
                                text: root.backend.searchText
                                selectByMouse: true
                                Accessible.name: qsTr("Search tools and resources")
                                onTextEdited: root.backend.searchText = text

                                ToolButton {
                                    anchors.right: parent.right
                                    anchors.verticalCenter: parent.verticalCenter
                                    visible: searchField.text.length > 0
                                    text: "×"
                                    Accessible.name: qsTr("Clear search")
                                    onClicked: {
                                        searchField.clear()
                                        root.backend.searchText = ""
                                        searchField.forceActiveFocus()
                                    }
                                }
                            }

                            ComboBox {
                                Layout.preferredWidth: Math.min(220, root.width * 0.34)
                                visible: !root.wideLayout
                                model: root.backend.categories
                                Accessible.name: qsTr("Category")
                                onActivated: root.backend.selectedCategory = currentText
                            }

                            SecondaryButton {
                                visible: !root.wideLayout
                                text: qsTr("System")
                                textColor: root.primaryTextColor
                                surfaceColor: root.surfaceColor
                                hoverColor: root.accentWash
                                borderColor: root.borderColor
                                accentColor: root.accentColor
                                onClicked: {
                                    root.currentPage = 1
                                    root.backend.requestSystemInfo()
                                }
                            }
                        }

                        GridView {
                            id: actionGrid
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            clip: true
                            model: root.backend.actions
                            property int columnCount: Math.max(1, Math.floor(width / 270))
                            cellWidth: width / columnCount
                            cellHeight: 105
                            boundsBehavior: Flickable.StopAtBounds
                            keyNavigationEnabled: true

                            // Bypass Flickable's wheel momentum so a touchpad can reverse
                            // direction immediately instead of waiting for deceleration.
                            WheelHandler {
                                target: null
                                acceptedDevices: PointerDevice.Mouse | PointerDevice.TouchPad
                                onWheel: function(event) {
                                    actionGrid.contentY = Math.max(0, Math.min(
                                        Math.max(0, actionGrid.contentHeight - actionGrid.height),
                                        actionGrid.contentY - event.angleDelta.y))
                                }
                            }

                            delegate: Item {
                                required property string identifier
                                required property string title
                                required property string description
                                required property string category
                                required property url iconSource
                                required property bool actionEnabled
                                width: actionGrid.cellWidth
                                height: actionGrid.cellHeight

                                ToolCard {
                                    anchors.fill: parent
                                    anchors.margins: 6
                                    actionId: parent.identifier
                                    title: parent.title
                                    description: parent.description
                                    category: parent.category
                                    iconSource: parent.iconSource
                                    enabled: parent.actionEnabled
                                    surfaceColor: root.surfaceColor
                                    primaryTextColor: root.primaryTextColor
                                    mutedTextColor: root.mutedTextColor
                                    accentColor: root.accentColor
                                    accentWash: root.accentWash
                                    borderColor: root.borderColor
                                    onClicked: root.backend.activate(actionId)
                                }
                            }

                            ScrollBar.vertical: ScrollBar { }
                        }

                        Text {
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            visible: actionGrid.count === 0
                            text: qsTr("No tools match your search.")
                            color: root.mutedTextColor
                            font.pixelSize: root.baseFontSize + 2
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                        }

                        CheckBox {
                            Layout.fillWidth: true
                            visible: !root.wideLayout && !root.backend.liveSession
                            text: qsTr("Show this dialog at start up")
                            checked: root.backend.autoStartup
                            onToggled: root.backend.autoStartup = checked
                        }
                    }
                }

                ScrollView {
                    id: systemPage
                    clip: true

                    ColumnLayout {
                        width: Math.max(systemPage.availableWidth, 0)
                        spacing: 18

                        Item { Layout.preferredHeight: 4 }

                        RowLayout {
                            Layout.fillWidth: true
                            Layout.leftMargin: 24
                            Layout.rightMargin: 24

                            Text {
                                Layout.fillWidth: true
                                text: qsTr("About this system")
                                color: root.primaryTextColor
                                font.pixelSize: root.baseFontSize + 7
                                font.weight: Font.DemiBold
                            }
                            SecondaryButton {
                                visible: !root.wideLayout
                                text: qsTr("Welcome")
                                textColor: root.primaryTextColor
                                surfaceColor: root.surfaceColor
                                hoverColor: root.accentWash
                                borderColor: root.borderColor
                                accentColor: root.accentColor
                                onClicked: root.currentPage = 0
                            }
                        }

                        GridLayout {
                            Layout.fillWidth: true
                            Layout.leftMargin: 24
                            Layout.rightMargin: 24
                            columns: root.width >= 760 ? 3 : 1
                            columnSpacing: 12
                            rowSpacing: 12

                            Repeater {
                                model: [
                                    { label: qsTr("MX version"), value: root.backend.distroVersion },
                                    { label: qsTr("Debian version"), value: root.backend.debianVersion },
                                    { label: qsTr("Desktop"), value: root.backend.desktopVersion },
                                    { label: qsTr("Supported until"), value: root.backend.supportedUntil }
                                ]
                                Rectangle {
                                    id: systemDetailCard
                                    required property var modelData
                                    Layout.fillWidth: true
                                    Layout.preferredHeight: 82
                                    radius: 11
                                    color: root.surfaceColor
                                    border.width: 1
                                    border.color: root.borderColor

                                    Column {
                                        anchors.fill: parent
                                        anchors.margins: 14
                                        spacing: 5
                                        Text {
                                            width: parent.width
                                            text: systemDetailCard.modelData.label
                                            color: root.mutedTextColor
                                            font.pixelSize: Math.max(10, root.baseFontSize - 1)
                                            elide: Text.ElideRight
                                        }
                                        Text {
                                            width: parent.width
                                            text: systemDetailCard.modelData.value.length > 0
                                                  ? systemDetailCard.modelData.value : qsTr("Unavailable")
                                            color: root.primaryTextColor
                                            font.weight: Font.DemiBold
                                            elide: Text.ElideRight
                                        }
                                    }
                                }
                            }
                        }

                        Text {
                            Layout.fillWidth: true
                            Layout.leftMargin: 24
                            Layout.rightMargin: 24
                            text: qsTr("Short system report")
                            color: root.primaryTextColor
                            font.pixelSize: root.baseFontSize + 2
                            font.weight: Font.DemiBold
                        }

                        TextArea {
                            Layout.fillWidth: true
                            Layout.leftMargin: 24
                            Layout.rightMargin: 24
                            Layout.minimumHeight: 210
                            text: root.backend.systemInfo.length > 0 ? root.backend.systemInfo : qsTr("Loading system information…")
                            readOnly: true
                            selectByMouse: true
                            wrapMode: TextEdit.Wrap
                            Accessible.name: qsTr("Short system report")
                        }

                        RowLayout {
                            Layout.fillWidth: true
                            Layout.leftMargin: 24
                            Layout.rightMargin: 24
                            spacing: 10

                            SecondaryButton {
                                text: qsTr("Quick-System-Info Full Report")
                                textColor: root.primaryTextColor
                                surfaceColor: root.surfaceColor
                                hoverColor: root.accentWash
                                borderColor: root.borderColor
                                accentColor: root.accentColor
                                onClicked: root.backend.openFullSystemReport()
                            }
                            SecondaryButton {
                                text: qsTr("Terms of Use")
                                textColor: root.primaryTextColor
                                surfaceColor: root.surfaceColor
                                hoverColor: root.accentWash
                                borderColor: root.borderColor
                                accentColor: root.accentColor
                                onClicked: {
                                    const text = root.backend.termsText()
                                    if (text.length > 0)
                                        root.showDocument(qsTr("Terms of Use"), text, false)
                                }
                            }
                            Item { Layout.fillWidth: true }
                        }

                        Text {
                            Layout.fillWidth: true
                            Layout.leftMargin: 24
                            Layout.rightMargin: 24
                            Layout.bottomMargin: 24
                            text: root.backend.termsSummary
                            color: root.mutedTextColor
                            wrapMode: Text.Wrap
                        }
                    }
                }
            }
        }
    }

    Dialog {
        id: aboutDialog
        anchors.centerIn: Overlay.overlay
        width: Math.min(520, root.width - 40)
        modal: true
        title: qsTr("About MX Welcome")
        footer: DialogButtonBox {
            standardButtons: DialogButtonBox.Close
            alignment: Qt.AlignRight
            padding: 12
            background: Item {}
            delegate: SecondaryButton {
                textColor: root.primaryTextColor
                surfaceColor: root.surfaceColor
                hoverColor: root.accentWash
                borderColor: root.borderColor
                accentColor: root.accentColor
            }
            onRejected: aboutDialog.reject()
        }

        ColumnLayout {
            width: parent.width
            spacing: 12
            Image {
                Layout.alignment: Qt.AlignHCenter
                Layout.preferredWidth: 72
                Layout.preferredHeight: 72
                source: root.backend.logoSource.toString().length > 0 ? root.backend.logoSource : "image://icons/mx-welcome"
                fillMode: Image.PreserveAspectFit
            }
            Text {
                Layout.fillWidth: true
                text: qsTr("MX Welcome")
                color: root.primaryTextColor
                font.pixelSize: root.baseFontSize + 7
                font.weight: Font.DemiBold
                horizontalAlignment: Text.AlignHCenter
            }
            Text {
                Layout.fillWidth: true
                text: qsTr("Version: %1").arg(root.backend.version)
                color: root.mutedTextColor
                horizontalAlignment: Text.AlignHCenter
            }
            Text {
                Layout.fillWidth: true
                text: qsTr("Program for displaying a welcome screen in MX Linux")
                color: root.primaryTextColor
                wrapMode: Text.Wrap
                horizontalAlignment: Text.AlignHCenter
            }
            Text {
                Layout.fillWidth: true
                text: qsTr("Copyright (c) MX Linux")
                color: root.mutedTextColor
                horizontalAlignment: Text.AlignHCenter
            }
            RowLayout {
                Layout.alignment: Qt.AlignHCenter
                SecondaryButton {
                    text: qsTr("License")
                    textColor: root.primaryTextColor
                    surfaceColor: root.surfaceColor
                    hoverColor: root.accentWash
                    borderColor: root.borderColor
                    accentColor: root.accentColor
                    onClicked: root.showDocument(qsTr("MX Welcome License"), root.backend.licenseHtml(), true)
                }
                SecondaryButton {
                    text: qsTr("Changelog")
                    textColor: root.primaryTextColor
                    surfaceColor: root.surfaceColor
                    hoverColor: root.accentWash
                    borderColor: root.borderColor
                    accentColor: root.accentColor
                    onClicked: root.showDocument(qsTr("Changelog"), root.backend.changelogText(), false)
                }
            }
        }
    }

    Dialog {
        id: documentDialog
        anchors.centerIn: Overlay.overlay
        width: Math.min(760, root.width - 40)
        height: Math.min(620, root.height - 40)
        modal: true
        footer: DialogButtonBox {
            standardButtons: DialogButtonBox.Close
            alignment: Qt.AlignRight
            padding: 12
            background: Item {}
            delegate: SecondaryButton {
                textColor: root.primaryTextColor
                surfaceColor: root.surfaceColor
                hoverColor: root.accentWash
                borderColor: root.borderColor
                accentColor: root.accentColor
            }
            onRejected: documentDialog.reject()
        }

        ScrollView {
            anchors.fill: parent
            TextArea {
                id: documentText
                readOnly: true
                selectByMouse: true
                wrapMode: TextEdit.Wrap
                onLinkActivated: function(link) { Qt.openUrlExternally(link) }
            }
        }
    }

    Dialog {
        id: errorDialog
        property string text
        anchors.centerIn: Overlay.overlay
        width: Math.min(440, root.width - 40)
        modal: true
        footer: DialogButtonBox {
            standardButtons: DialogButtonBox.Ok
            alignment: Qt.AlignRight
            padding: 12
            background: Item {}
            delegate: SecondaryButton {
                textColor: root.primaryTextColor
                surfaceColor: root.surfaceColor
                hoverColor: root.accentWash
                borderColor: root.borderColor
                accentColor: root.accentColor
            }
            onAccepted: errorDialog.accept()
        }

        Text {
            width: parent.width
            text: errorDialog.text
            color: root.primaryTextColor
            wrapMode: Text.Wrap
        }
    }

    Component.onCompleted: {
        if (currentPage === 1)
            root.backend.requestSystemInfo()
    }
}
