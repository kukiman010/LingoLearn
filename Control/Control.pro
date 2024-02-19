TARGET      = Control
TEMPLATE    = lib
CONFIG      += staticlib

QT = core network

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    abstractcommand.cpp \
    abstractobject.cpp \
    command.cpp \
    factory.cpp \
    socket.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    abstractcommand.h \
    abstractobject.h \
    command.h \
    factory.h \
    saved_container.h \
    socket.h
