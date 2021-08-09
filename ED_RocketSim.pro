QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Crafts/Components/solidengine.cpp \
    Crafts/missile.cpp \
    Crafts/target.cpp \
    engine.cpp \
    graphicsview.cpp \
    linal.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Crafts/Components/solidengine.h \
    Crafts/missile.h \
    Crafts/target.h \
    Crafts/airvehicle.h \
    engine.h \
    graphicsview.h \
    linal.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
