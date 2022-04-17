import QtQuick 6.0
import QtQuick.Window 6.0
import QtQuick.Controls 6.0
import QtQuick.Layouts 6.0


Window {
    id: root
    modality: Qt.ApplicationModal  // окно объявляется модальным
    title: qsTr("Добавление новой звезды")
    minimumWidth: 400
    maximumWidth: 400
    minimumHeight: 200
    maximumHeight: 200

    GridLayout {
        anchors { left: parent.left; top: parent.top; right: parent.right; bottom: buttonCancel.top; margins: 10 }
        columns: 2

        Label {
            Layout.alignment: Qt.AlignRight  // выравнивание по правой стороне
            text: qsTr("Название звезды:")
        }
        TextField {
            id: textName
            Layout.fillWidth: true
            placeholderText: qsTr("Введите название")
        }
        Label {
            Layout.alignment: Qt.AlignRight
            text: qsTr("Название созвездия:")
        }
        TextField {
            id: constellation
            Layout.fillWidth: true
            placeholderText: qsTr("Введите название созвездия")
        }
//        ComboBox {
//            id: constellation
//            Layout.alignment: Qt.AlignRight
//            model: ListModel{
//                id: mm
//                ListElement {text:"Андромеда"}
//                ListElement {text:"Близнецы"}
//                ListElement {text:"Большая Медведица"}
//                ListElement {text:"Большой Пёс"}
//                ListElement {text:"Весы"}
//                ListElement {text:"Водолей"}
//                ListElement {text:"Возничий"}

//            }

//        }
//        Label {
//            Layout.alignment: Qt.AlignRight
//            text: qsTr("Видимая звездная величина:")
//        }
//        TextField {
//            id: constellation
//            Layout.fillWidth: true
//            placeholderText: qsTr("Введите название созвездия")
//        }
        Label {
            Layout.alignment: Qt.AlignRight
            text: qsTr("Видимая звездная величина:")
        }
        TextField {
            id: apparentMagnitude
            Layout.fillWidth: true
            placeholderText: qsTr("Введите видимую звездную величину")
        }
        Label {
            Layout.alignment: Qt.AlignRight
            text: qsTr("Расстояние от Земли:")
        }
        TextField {
            id: distance
            Layout.fillWidth: true
            placeholderText: qsTr("Введите расстояние от Земли:")
        }
        Label {
            Layout.alignment: Qt.AlignRight
            text: qsTr("Координаты на небосклоне:")
        }
        TextField {
            id: coordinates
            Layout.fillWidth: true
            placeholderText: qsTr("Введите координаты")
        }
    }


    Button {
        visible: {textName.length>0 && /*constellation.value!==0*/ constellation.length>0}
        anchors { right: buttonCancel.left; verticalCenter: buttonCancel.verticalCenter; rightMargin: 10 }
        text: qsTr("Добавить в список")
        width: 100
        onClicked: {
            root.hide()
            add(textName.text, /*constellation.currentText,*/constellation.text, apparentMagnitude.text, distance.text, coordinates.text)
        }
    }
    Button {
        id: buttonCancel
        anchors { right: parent.right; bottom: parent.bottom; rightMargin: 10; bottomMargin: 10 }
        text: qsTr("Отменить")
        width: 100
        onClicked: {
             root.hide()
        }
    }

    // изменение статуса видимости окна диалога
    onVisibleChanged: {
      if (visible) {
          textName.text = ""
          constellation.text = ""
          apparentMagnitude.text = ""
          distance.text = ""
          coordinates.text = ""
      }
    }
 }
