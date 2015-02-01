#-------------------------------------------------
#
# Project created by QtCreator 2015-02-01T09:41:55
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtUdpEchoClient
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

OTHER_FILES += README.md\
			.gitignore
