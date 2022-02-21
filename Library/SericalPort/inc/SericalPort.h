#ifndef SERICALPORT_H
#define SERICALPORT_H

#include <QSerialPort>
#include <QDebug>


class SerialPort : public QSerialPort
{
    Q_OBJECT
/*
*     setProtocol()，此为模板函数，用来设置串口通信协议，调用时需要指定协议类的类名，它需要接收一个协议对象指针作为参数，
* 且该指针必须通过new操作符创建，若不提供该对象则默认为空指针；若提供，则该对象中必须具有与_protocol_rx()、_protocol_tx()
* 相似的rx()和tx()方法，否则会导致程序运行崩溃，注意：请在应用程序退出时手动销毁该协议对象。
*     setReadSendCb()，用来设置单次通信完成后的回调函数，包括发送完成后和接收完成后，它们都会接收两个参数，
* 第一个参数为该次通信传输的数据，第二个参数为协议校验码，0代表校验成功，其他代表通信异常。
*     setOpenCb()，用来设置串口打开的回调函数，它接收一个打开是否成功标志位。如果未设置该回调函数，
* 则会使用默认的回调函数_openDefaultCb()。
*/

public:

    typedef struct
    {
        QString name;
        BaudRate baudRate;
        DataBits dataBits;
        Parity parity;
        StopBits stopBits;
        FlowControl flowControl;
    } Config;

public:

    SerialPort();

    ~SerialPort();

    void connect(void);

    void disconnect(void);

    void send(const QByteArray& dataBuff);

    template <typename PTC>
    void setProtocol(const PTC* const protocol = nullptr);

    void setPort(const Config& config);

    void setReadSendCb(void (*const readLater)(const QByteArray& data, qint8 code) = nullptr,
                       void (*const sendLater)(const QByteArray& data, qint8 code) = nullptr);

    void setOpenCb(void (*const openCb)(bool isOk) = nullptr);

private:

    void (*_openCb)(bool isOk) = nullptr;

    qint8 (*_protocol_rx)(const QByteArray& data);
    qint8 (*_protocol_tx)(const QByteArray& data);

    void (*_readLater)(const QByteArray& data, qint8 code) = nullptr;
    void (*_sendLater)(const QByteArray& data, qint8 code) = nullptr;

    static void _openDefaultCb(bool isOk);

    static qint8 _default_protocol_rx(const QByteArray& data);
    static qint8 _default_protocol_tx(const QByteArray& data);

private slots:

    void read(void);

};


#endif // SERICALPORT_H
