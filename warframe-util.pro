#-------------------------------------------------
#
# Project created by QtCreator 2019-05-28T15:25:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = warframe-util
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        Data/mod.cc \
        data/dataentity.cc \
        data/enemy.cc \
        data/location.cc \
        data/prime.cc \
        data/relic.cc \
        datareader.cc \
        main.cc \
        mainwindow.cc \
        misc.cc \
        program.cc \
        programmodel.cc \
        widgets/modslistmodel.cc \
        widgets/searchlistdelegate.cc \
        widgets/searchproxymodel.cc

HEADERS += \
        Data/dataentity.hh \
        Data/mod.hh \
        data/enemy.hh \
        data/location.hh \
        data/prime.hh \
        data/relic.hh \
        datareader.hh \
        interface/datareaderinterface.hh \
        interface/programinterface.hh \
        interface/programmodelinterface.hh \
        mainwindow.hh \
        misc.hh \
        program.hh \
        programmodel.hh \
        widgets/modslistmodel.hh \
        widgets/searchlistdelegate.hh \
        widgets/searchproxymodel.hh

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += $$PWD/widgets \
               $$PWD/interface \
               $$PWD/data
