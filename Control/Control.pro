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
    socket.cpp \
    sslworker.cpp

# Default rules for deployment.
# qnx: target.path = /tmp/$${TARGET}/bin
# else: unix:!android: target.path = /opt/$${TARGET}/bin
# !isEmpty(target.path): INSTALLS += target

HEADERS += \
    abstractcommand.h \
    abstractobject.h \
    command.h \
    saved_container.h \
    socket.h \
    sslworker.h


win32 {
    INCLUDEPATH += "C:/Program Files/OpenSSL/include"
    LIBS += -L"C:/Program Files/OpenSSL/lib" -lssl  -lcrypto
} else:unix {
    INCLUDEPATH += "/home/sysadm/qt_project/openssl/include/openssl"
    LIBS += -L"/home/sysadm/qt_project/openssl/lib64" -lssl -lcrypto -ldl -lpthread
}




win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Interface/Interface/release/ -lInterface
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Interface/Interface/debug/ -lInterface
else:unix: LIBS += -L$$OUT_PWD/../Interface/Interface/ -lInterface

INCLUDEPATH += $$PWD/../Interface/Interface
DEPENDPATH += $$PWD/../Interface/Interface

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Interface/Interface/release/libInterface.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Interface/Interface/debug/libInterface.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Interface/Interface/release/Interface.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Interface/Interface/debug/Interface.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../Interface/Interface/libInterface.a
