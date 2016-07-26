#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QtNetwork>
#include<QtNetwork/QTcpSocket>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    void init();
    void newTcpConnect();
private:
    Ui::MainWindow *ui;
    QTcpSocket *tcpSocket;
private slots:
    void recData();
    void displayError(QAbstractSocket::SocketError);

    void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
