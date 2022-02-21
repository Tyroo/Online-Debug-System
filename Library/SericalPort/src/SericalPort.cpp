#include "./Library/SericalPort/inc/SericalPort.h"



SerialPort::SerialPort()
{
    QObject::connect(this, SIGNAL(readyRead()), this, SLOT(read()));
}

SerialPort::~SerialPort()
{

}

// 串口配置方法
void SerialPort::setPort(const Config& config)
{
    this->setPortName(config.name);
    this->setBaudRate(config.baudRate);
    this->setDataBits(config.dataBits);
    this->setParity(config.parity);
    this->setStopBits(config.stopBits);
    this->setFlowControl(config.flowControl);
}

// 设置串口通信协议
template <typename PTC>
void SerialPort::setProtocol(const PTC* const protocol)
{
    if (protocol == nullptr)
    {
        this->_protocol_rx = _default_protocol_rx;
        this->_protocol_tx = _default_protocol_tx;
        return;
    }

    this->_protocol_rx = protocol->rx;
    this->_protocol_tx = protocol->tx;
}

// 设置接收/发送完成后的回调函数
void SerialPort::setReadSendCb(void (*const readLater)(const QByteArray& data, qint8 code),
                                  void (*const sendLater)(const QByteArray& data, qint8 code))
{
    this->_readLater = readLater;
    this->_sendLater = sendLater;
}

// 设置串口打开回调方法
void SerialPort::setOpenCb(void (*const openCb)(bool isOk))
{
    if (openCb == nullptr)
    {
        this->_openCb = this->_openDefaultCb;
        return;
    }

    this->_openCb = openCb;
}

// 默认的串口打开回调函数
void SerialPort::_openDefaultCb(bool isOk)
{
    qDebug() << "The serial port srarus is" << isOk;
}

// 默认的接收协议
qint8 SerialPort::_default_protocol_rx(const QByteArray& data)
{
    qDebug() << data;
    return 0;
}

// 默认的发送协议
qint8 SerialPort::_default_protocol_tx(const QByteArray& data)
{
    qDebug() << data;
    return 0;
}

// 连接当前的串口
void SerialPort::connect()
{
    this->_openCb(this->open(QIODevice::ReadWrite));
}

// 断开当前的串口连接
void SerialPort::disconnect()
{
    // 关闭串口连接
    this->close();
}

// 串口读数据方法
void SerialPort::read()
{
    // 检测接收的数据是否有效
    if (this->bytesAvailable())
    {
        qint8 checkValue;
        QByteArray dataBuff;

        dataBuff = this->readAll();
        checkValue = this->_protocol_rx(dataBuff);

        if (this->_readLater == nullptr)
            return;

        // 校验完之后的处理逻辑
        this->_readLater(dataBuff, checkValue);
    }
}

// 串口写数据方法
void SerialPort::send(const QByteArray& dataBuff)
{
    bool status;

    status = this->isOpen();
    this->_openCb(status);
    // 判断写入时，串口是否处于打开状态
    if (!status) return;

    // 当发送的数据大小为0时，不发送
    if (dataBuff.size())
    {
        qint8 checkValue;

        checkValue = this->_protocol_tx(dataBuff);
        this->write(dataBuff);

        if (this->_sendLater == nullptr)
            return;

        // 校验完之后的处理逻辑
        this->_sendLater(dataBuff, checkValue);
    }
}
