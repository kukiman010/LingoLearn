QT -= gui
QT = network

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp \
    sslworker.cpp

HEADERS += \
    sslworker.h



win32 {
    # LIBS += "C:/Program Files/OpenSSL/bin/libcrypto-1_1-x64.dll"
    # LIBS += "C:/Program Files/OpenSSL/bin/libssl-1_1-x64.dll"
    # LIBS += "C:/Program Files/OpenSSL/bin"
    # LIBS += -L"C:/Program Files/OpenSSL/lib" -lssl  -lcrypto-3-x64
    INCLUDEPATH += "C:/Program Files/OpenSSL/include"
    LIBS += -L"C:/Program Files/OpenSSL/lib" -lssl  -lcrypto
} else:unix {
    INCLUDEPATH += "/home/sysadm/qt_project/openssl/include/openssl"
    LIBS += -L"/home/sysadm/qt_project/openssl/lib64" -lssl -lcrypto -ldl -lpthread
}
