#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::init()
{
  this->tcpSocket=new QTcpSocket(this);
  newTcpConnect();

  QObject::connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(recData()));
  QObject::connect(tcpSocket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(displayError(QAbstractSocket::SocketError)));
  QObject::connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void MainWindow::recData()
{
    QString datas=tcpSocket->readAll();
    ui->lineEdit->setText(datas);

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void MainWindow::newTcpConnect()
{
  tcpSocket->abort();
  tcpSocket->connectToHost("114.229.253.223",6666);

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void MainWindow::displayError(QAbstractSocket::SocketError)
{
  qDebug()<<tcpSocket->errorString();
  tcpSocket->close();

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::on_pushButton_clicked()
{
  this->tcpSocket->write(ui->lineEdit->text().toLatin1());
}













