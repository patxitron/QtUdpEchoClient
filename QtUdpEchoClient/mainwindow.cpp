#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
		:QMainWindow(parent)
		,ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	ui->editReceived->setReadOnly(true);
	sock_.bind(QHostAddress::Any);
	connect(ui->buttonSend, &QPushButton::clicked, [this]() {
		ui->editReceived->clear();
		ui->buttonSend->setDisabled(true);
		sock_.writeDatagram(
			 ui->editTextToSend->text().toUtf8()
			,QHostAddress(ui->editAddress->text())
			,ui->spinPort->value()
		);
		if(sock_.waitForReadyRead(RESPONSE_TIMEOUT)) {
			QByteArray datagram;
			datagram.resize(sock_.pendingDatagramSize());
			sock_.readDatagram(datagram.data(), datagram.size());
			ui->editReceived->setText(QString::fromUtf8(datagram));
		} else {
			ui->editReceived->setText("*TIMEOUT*");
		}
		ui->buttonSend->setDisabled(false);
	});
}

MainWindow::~MainWindow()
{
	delete ui;
}
