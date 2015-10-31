import QtQuick 2.5
import QtQuick.Controls 1.4

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
            anchors.margins: 5
            anchors.left: parent.left
            anchors.right: parent.right
            height: 50
            color: "gray"
            Text {
                text: model.message
            }
        }

    }


}
