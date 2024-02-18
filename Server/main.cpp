#include <QCoreApplication>
#include "socketserver.h"

// #include <QUuid>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // QString uuid = QUuid::createUuid().toString(QUuid::WithoutBraces);
    // QString s = QUuid::toString(QUuid::WithoutBraces);


    // qDebug() << id;
    SocketServer * s = new SocketServer();
    s->listen(QHostAddress::Any,1234);

    return a.exec();
}
