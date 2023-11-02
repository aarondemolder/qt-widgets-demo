#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_button = new QPushButton("My Button", this);
    m_button->setGeometry(QRect(QPoint(100, 100), QSize(200, 50)));

    connect(m_button, &QPushButton::released, this, &MainWindow::handleButton);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::handleButton()
{
    QFile file = QFileDialog::getOpenFileName(this, tr("Open Txt"), "", tr("Text Files (*.txt)"));

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&file);
        m_button->setText(stream.readLine());
    }
    file.close();

    m_button->resize(100,100);
}

