#include <QCoreApplication>
#include <iostream>
//#include <openssl/ssl.h>
//#include <openssl/err.h>
#include "sslworker.h"

#include <QUdpSocket>
#include <QTcpSocket>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout<< "test\n";

   // SSL_library_init();
   OpenSSL_add_all_algorithms();
   SSL_load_error_strings();

   // Вывод версии OpenSSL
   std::cout << "OpenSSL version: " << SSLeay_version(SSLEAY_VERSION) << std::endl;

//    // Очистка
//    EVP_cleanup();
//    ERR_free_strings();

    SslWorker sl;
//    sl.test();

//    QUdpSocket udpSocket;
//    udpSocket.writeDatagram("Hello UDP!", QHostAddress("127.0.0.1"), 1234);

//    QTcpSocket socket;
//    socket.connectToHost("127.0.0.1", 1234);

//    if(socket.waitForConnected()) {
//        qDebug() << "Connected to server!";
//        socket.write("Hello from client");
//        socket.waitForBytesWritten();
//    } else {
//        qDebug() << "Connection failed!";
//    }




    return a.exec();
}
