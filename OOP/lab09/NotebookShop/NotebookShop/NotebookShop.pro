QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    BuildInfrastructure/highpricenotebookbuilder.cpp \
    BuildInfrastructure/lowpricenotebookbuilder.cpp \
    BuildInfrastructure/middlepricenotebookbuilder.cpp \
    BuildInfrastructure/notebookbuilder.cpp \
    BuildInfrastructure/notebookproducer.cpp \
    PCComponents/CPUs/intelcorei3.cpp \
    PCComponents/CPUs/intelcorei9.cpp \
    PCComponents/CPUs/intelpentium.cpp \
    PCComponents/Displays/lgdisplay.cpp \
    PCComponents/Displays/samsungdisplay.cpp \
    PCComponents/Displays/tianmadisplay.cpp \
    PCComponents/Motherboards/asusmotherboard.cpp \
    PCComponents/Motherboards/intelmotherboard.cpp \
    PCComponents/RAMs/hyperxram.cpp \
    PCComponents/RAMs/kingstonram.cpp \
    PCComponents/RAMs/samsungram.cpp \
    PCComponents/Storage/samsungssd.cpp \
    PCComponents/Storage/seagatehdd.cpp \
    main.cpp \
    mainwindow.cpp \
    notebook.cpp \
    order.cpp

HEADERS += \
    BuildInfrastructure/highpricenotebookbuilder.h \
    BuildInfrastructure/lowpricenotebookbuilder.h \
    BuildInfrastructure/middlepricenotebookbuilder.h \
    BuildInfrastructure/notebookbuilder.h \
    BuildInfrastructure/notebookproducer.h \
    PCComponents/CPUs/intelcorei3.h \
    PCComponents/CPUs/intelcorei9.h \
    PCComponents/CPUs/intelpentium.h \
    PCComponents/Displays/lgdisplay.h \
    PCComponents/Displays/samsungdisplay.h \
    PCComponents/Displays/tianmadisplay.h \
    PCComponents/Motherboards/asusmotherboard.h \
    PCComponents/Motherboards/intelmotherboard.h \
    PCComponents/Storage/samsungssd.h \
    PCComponents/processor.h \
    PCComponents/RAMs/hyperxram.h \
    PCComponents/RAMs/kingstonram.h \
    PCComponents/RAMs/samsungram.h \
    PCComponents/Storage/seagatehdd.h \
    PCComponents/display.h \
    PCComponents/hardware.h \
    PCComponents/motherboard.h \
    PCComponents/ram.h \
    PCComponents/storage.h \
    includes.h \
    mainwindow.h \
    notebook.h \
    order.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
