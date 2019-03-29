#ifndef TERMINALWINDOW_H
#define TERMINALWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QtCore>

namespace Ui {
class TerminalWindow;
}

class TerminalWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TerminalWindow(QWidget *parent = nullptr);
    ~TerminalWindow();



private slots:
    void connectDevice();
    // void disconnectDevice();
    void dataAvailable();

private:
    QSerialPort m_serialPort;
    Ui::TerminalWindow *ui;
};

#endif // TERMINALWINDOW_H
