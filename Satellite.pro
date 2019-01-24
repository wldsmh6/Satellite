#-------------------------------------------------
#
# Project created by QtCreator 2018-01-06T16:10:26
#
#-------------------------------------------------

QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = InterfaceFusee
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


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    qcustomplot.cpp \
    objetspacial.cpp \
    planete.cpp \
    RungeKutta.cpp \
    satellite.cpp \
    interface.cpp \
    space.cpp \
    euler.cpp \
    tangenteameliore.cpp

HEADERS += \
    qcustomplot.h \
    objetspacial.hpp \
    planete.hpp \
    RungeKutta.hpp \
    satellite.hpp \
    space.hpp \
    interface.hpp \
    euler.hpp \
    tangenteameliore.hpp \
    mainwindow.hpp

FORMS += \
        mainwindow.ui \
    interface.ui \
    space.ui

RESOURCES += \
    images.qrc
