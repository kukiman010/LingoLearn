#include <QCoreApplication>
#include "socketserver.h"

// #include <QUuid>
#include "sslworker.h"
#include <QUdpSocket>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // QString uuid = QUuid::createUuid().toString(QUuid::WithoutBraces);
    // QString s = QUuid::toString(QUuid::WithoutBraces);


    // qDebug() << id;
//    SocketServer * s = new SocketServer();
//    s->listen(QHostAddress::Any,1234);

   // SslWorker sw;
   // sw.test();

//    QUdpSocket udpSocket;
//        udpSocket.writeDatagram("Hello UDP!", QHostAddress::LocalHost, 1234);


//    QTcpServer server;
//    if (!server.listen(QHostAddress::Any, 1234)) {
//        qDebug() << "Server could not start!";
//        return 1;
//    }

//    qDebug() << "Server started on port 1234";

//    QObject::connect(&server, &QTcpServer::newConnection, [&](){
//        QTcpSocket *clientSocket = server.nextPendingConnection();
//        QObject::connect(clientSocket, &QTcpSocket::readyRead, [&](){
//            QByteArray data = clientSocket->readAll();
//            qDebug() << "Received: " << data;
//        });
//    });




    return a.exec();
}
