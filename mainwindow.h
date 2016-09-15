#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QtSerialPort>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QSerialPort usb; //on déclare l'USB
private slots:
    void openSerialPort();

    void on_send_clicked();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
