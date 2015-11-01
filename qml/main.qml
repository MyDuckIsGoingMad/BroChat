import QtQuick 2.5
import QtQuick.Controls 1.4
import QtGraphicalEffects 1.0

ApplicationWindow {
    visible: true
    x: 100
    y: 100
    width: 200
    height: 480
    title: qsTr("BroChat")

    color: "black"

    ListView {
        anchors.fill: parent
        spacing: 10
        model: coreMediator.historyListModel
        delegate: Rectangle {
            anchors.margins: 10
            anchors.left: parent.left
            anchors.right: parent.right
            height: idHeader.height + idMessage.height
            Rectangle {
                id: idHeader
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: parent.top
                height: 40
                color: "#3F51B5"
                Text {
                    anchors.fill: parent
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    text: model.nickname
                    font.pixelSize: 16
                    color: "#FFFFFF"
                }
            }
            DropShadow {
                anchors.fill: idHeader
                horizontalOffset: 3
                verticalOffset: 3
                radius: 8.0
                samples: 16
                color: "#80000000"
                source: idHeader
            }
            Rectangle {
                id: idMessage
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.bottom: parent.bottom
                anchors.top: idHeader.bottom
                height: idMessageText.contentHeight + 24
                color: "#FFFFFF"
                Text {
                    id: idMessageText
                    anchors.margins: 5
                    anchors.left: parent.left
                    anchors.right: parent.right
                    anchors.verticalCenter: parent.verticalCenter
                    verticalAlignment: Text.AlignVCenter
                    wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                    elide: Text.ElideRight
                    text: model.message
                    font.pixelSize: 14
                }
            }
        }

        add: Transition {
            NumberAnimation { property: "opacity"; from: 0; to: 1.0; duration: 400 }
            NumberAnimation { property: "scale"; from: 0; to: 1.0; duration: 400 }
        }

        displaced: Transition {
            NumberAnimation { properties: "x,y"; duration: 400; easing.type: Easing.OutBounce }
        }

        focus: true
    }
}
