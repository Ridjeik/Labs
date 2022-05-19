QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

RC_ICONS = bookIcon.ico

SOURCES += \
    adddialog.cpp \
    addrequest.cpp \
    constlistiterator.cpp \
    createrequest.cpp \
    deleterequest.cpp \
    filterdialog.cpp \
    filterrequest.cpp \
    lab10_lib.cpp \
    limitrequest.cpp \
    listmodel.cpp \
    listscontroller.cpp \
    listsfacade.cpp \
    loadrequest.cpp \
    main.cpp \
    mainwindow.cpp \
    request.cpp \
    saverequest.cpp \
    sortdialog.cpp \
    sortrequest.cpp \
    switchrequest.cpp

HEADERS += \
    adddialog.h \
    addrequest.h \
    constlistiterator.h \
    createrequest.h \
    deleterequest.h \
    filterdialog.h \
    filterrequest.h \
    lab10_lib.h \
    limitrequest.h \
    listmodel.h \
    listscontroller.h \
    listsfacade.h \
    loadrequest.h \
    mainwindow.h \
    request.h \
    saverequest.h \
    sortdialog.h \
    sortrequest.h \
    switchrequest.h

FORMS += \
    adddialog.ui \
    filterdialog.ui \
    mainwindow.ui \
    sortdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
