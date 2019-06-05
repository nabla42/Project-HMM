#-------------------------------------------------
#
# Project created by QtCreator 2019-05-12T23:06:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HMM
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES +=\
    choose_user.cpp \
    entrypoint.cpp \
    adminwindow.cpp \
    modelname.cpp \
    starthmmwindow.cpp \
    main.cpp \
    tabpage.cpp \
    waitingforresults.cpp

HEADERS  += \
    choose_user.h \
    entrypoint.h \
    adminwindow.h \
    modelname.h \
    starthmmwindow.h \
    tabpage.h \
    waitingforresults.h

FORMS    += \
    choose_user.ui \
    entrypoint.ui \
    adminwindow.ui \
    modelname.ui \
    starthmmwindow.ui \
    waitingforresults.ui \
    tabpage.ui
