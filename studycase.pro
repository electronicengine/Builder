QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    builder.cpp \
    csvbuilder.cpp \
    fileoperations.cpp \
    jsonbuilder.cpp \
    main.cpp \
    mainwindow.cpp \
    txtbuilder.cpp \
    windowworker.cpp \
    xmlmaker.cpp

HEADERS += \
    builder.h \
    csvbuilder.h \
    fileoperations.h \
    jsonbuilder.h \
    mainwindow.h \
    txtbuilder.h \
    windowworker.h \
    xmlmaker.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
