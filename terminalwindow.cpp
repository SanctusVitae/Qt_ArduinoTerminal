#include "terminalwindow.h"
#include "ui_terminalwindow.h"

TerminalWindow::TerminalWindow(QWidget *parent) :
    QMainWindow(parent),
    m_serialPort(new QSerialPort(this)),
    ui(new Ui::TerminalWindow)
{
    ui->setupUi(this);

    ui->buttonSend->setText("Send");
    ui->buttonClose->setText("Disconnect");
    ui->buttonConnect->setText("Connect");
    ui->buttonRecieve->setText("Read");

    ui->boxBaud->addItem(QStringLiteral("9600"), QSerialPort::BaudRate::Baud9600);
    ui->boxBaud->addItem(QStringLiteral("19200"), QSerialPort::BaudRate::Baud19200);
    ui->boxBaud->addItem(QStringLiteral("38400"), QSerialPort::BaudRate::Baud38400);
    ui->boxBaud->addItem(QStringLiteral("57600"), QSerialPort::BaudRate::Baud57600);
    ui->boxBaud->addItem(QStringLiteral("115200"), QSerialPort::BaudRate::Baud115200);

    // QList<QSerialPortInfo> portList;

    for (const QSerialPortInfo &info : QSerialPortInfo::availablePorts())
    {
            QStringList list;
            list << info.portName();
            ui->boxPort->addItem(list.first(), list);
            /*
            << (!description.isEmpty() ? description : blankString)
            << (!manufacturer.isEmpty() ? manufacturer : blankString)
            << info.systemLocation()
            << (info.vendorIdentifier() ? QString::number(info.vendorIdentifier(), 16) : blankString)
            << (info.productIdentifier() ? QString::number(info.productIdentifier(), 16) : blankString);*/
     }

    connect(m_serialPort, &QSerialPort::readyRead, this, TerminalWindow::dataAvailable());

    //connect(this, )
}

TerminalWindow::~TerminalWindow()
{
    delete ui;
}

void TerminalWindow::connectDevice()
{
          //m_serialPort->setPortName(p.name);
          m_serialPort.setBaudRate(9600);
          m_serialPort.setDataBits(QSerialPort::DataBits::Data8);
          m_serialPort.setParity(QSerialPort::Parity::NoParity);
          m_serialPort.setStopBits(QSerialPort::StopBits::OneStop);
          m_serialPort.setFlowControl(QSerialPort::FlowControl::NoFlowControl);

          if (m_serialPort.open(QIODevice::ReadWrite))
          {
              //ui->actionConnect->setEnabled(false);
              //ui->actionDisconnect->setEnabled(true);
              //ui->actionConfigure->setEnabled(false);
              //showStatusMessage(tr("Connected to %1 : %2, %3, %4, %5, %6")
                                //.arg(p.name).arg(p.stringBaudRate).arg(p.stringDataBits)
                                //.arg(p.stringParity).arg(p.stringStopBits).arg(p.stringFlowControl));
          } else {
              //QMessageBox::critical(this, tr("Error"), m_serialPort.errorString());
          }
}
