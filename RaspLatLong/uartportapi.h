#ifndef UARTPORTAPI_H
#define UARTPORTAPI_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
class UARTPortAPI : public QObject
{
    Q_OBJECT
private:
    QSerialPort uartPort;
public:
    explicit UARTPortAPI(QObject *parent = nullptr);

signals:
    void locationChanged(int id);

public slots:
};

#endif // UARTPORTAPI_H
