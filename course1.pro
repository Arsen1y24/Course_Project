QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    basicitemtouse.cpp \
    bush.cpp \
    clipsimage.cpp \
    donemessage.cpp \
    flowerbush.cpp \
    graphme.cpp \
    imagehouse.cpp \
    main.cpp \
    mainwindow.cpp \
    markerimage.cpp \
    movingcar.cpp \
    neighbourway.cpp \
    picdrawing.cpp \
    pocket.cpp \
    sprite.cpp \
    spritegoblin.cpp \
    tree.cpp

HEADERS += \
    MyHeaders.h \
    basicitemtouse.h \
    bush.h \
    clipsimage.h \
    donemessage.h \
    flowerbush.h \
    graphme.h \
    imagehouse.h \
    mainwindow.h \
    markerimage.h \
    movingcar.h \
    neighbourway.h \
    picdrawing.h \
    pocket.h \
    sprite.h \
    spritegoblin.h \
    tree.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ItemsToUse.qrc \
    Messages.qrc \
    cursorTake.qrc \
    house.qrc \
    sprites.qrc

DISTFILES +=
