QT       += core gui
QT       += printsupport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

VERSION = 0.0.0.1

QMAKE_TARGET_COMPANY = NULP
QMAKE_TARGET_PRODUCT = TextImageEditor
QMAKE_TARGET_DESCRIPTION = "Program for editing text and showing images"
QMAKE_TARGET_COPYRIGHT = artem.marushchak.pz.2021@lpnu.ua

RC_ICONS = editor.ico

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    editorwindow.cpp \
    searchreplacedialog.cpp

HEADERS += \
    editorwindow.h \
    searchreplacedialog.h

FORMS += \
    editorwindow.ui \
    searchreplacedialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    editor.ico
