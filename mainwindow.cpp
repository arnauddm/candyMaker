#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->open, SIGNAL(clicked(bool)), this, SLOT(openSerialPort())); //ouvrir le port série USB

    connect(ui->close, SIGNAL(clicked(bool)), this, SLOT(close())); //on ferme l'application
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openSerialPort() {
    usb.setBaudRate(QSerialPort::Baud9600);
    usb.setDataBits(QSerialPort::Data8);
    usb.setParity(QSerialPort::NoParity);
    if(!usb.open(QIODevice::ReadWrite)) {
        QMessageBox::information(this, "Error", "Error to open serial port");
    }
    else {
        QMessageBox::information(this, "Connected", usb.portName());
    }
}

void MainWindow::on_send_clicked()
{
    const char data[]("Hello");
    usb.write(data);
}
