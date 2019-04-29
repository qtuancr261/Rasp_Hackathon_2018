#include "uartportapi.h"

UARTPortAPI::UARTPortAPI(QObject* parent)
    : QObject(parent)
    , uartPort{}
{
    uartPort.setPortName("ttyUSB0");
    if (!uartPort.setBaudRate(QSerialPort::Baud9600))
        qDebug() << uartPort.errorString();
    if (!uartPort.setDataBits(QSerialPort::Data8))
        qDebug() << uartPort.errorString();
    if (!uartPort.setParity(QSerialPort::OddParity))
        qDebug() << uartPort.errorString();
    if (!uartPort.setFlowControl(QSerialPort::HardwareControl))
        qDebug() << uartPort.errorString();
    if (!uartPort.setStopBits(QSerialPort::OneStop))
        qDebug() << uartPort.errorString();
    if (!uartPort.open(QIODevice::ReadOnly))
        qDebug() << uartPort.errorString();
    QObject::connect(&uartPort, &QSerialPort::readyRead, [&] {
        //this is called when serial port readyRead() is emitted
        qDebug() << "New data available: " << uartPort.bytesAvailable();
        QByteArray datas = uartPort.readAll();
        qDebug() << datas;
        if (datas == "\x01")
            emit locationChanged(1);
        else if (datas == "\x02")
            emit locationChanged(2);
        else if (datas == "\x03")
            emit locationChanged(3);
        else if (datas == "\x04")
            emit locationChanged(4);
    });
}
