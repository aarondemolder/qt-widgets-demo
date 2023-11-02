#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>

//constructor
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    //make sure to setup the UI first, otherwise it covers all the other UI elements
    ui->setupUi(this);

    //add a button
    m_button = new QPushButton("My Button", this);
    //set the position and size of the button
    m_button->setGeometry(QRect(QPoint(100, 100), QSize(200, 50)));
    //attach the button-press to the function
    connect(m_button, &QPushButton::released, this, &MainWindow::handleButton);


    //add another button!
    m_button2 = new QPushButton("Counter", this);
    //set the position and size of the button
    m_button2->setGeometry(QRect(QPoint(400, 100), QSize(200, 50)));
    //attach the button-press to the function
    connect(m_button2, &QPushButton::released, this, &MainWindow::handleButton2);

}

//destructor
MainWindow::~MainWindow()
{
    delete ui;
}

//the function that is called when we click the button
void MainWindow::handleButton()
{
    //adding a file dialog browser to the button press
    QFile file = QFileDialog::getOpenFileName(this, tr("Open Txt"), "", tr("Text Files (*.txt)"));

    //load the text file selected
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&file);

        //set the text of the button to match the line in the txt file
        m_button->setText(stream.readLine());
    }
    file.close();

    //m_button->setText("Clicked!");
    //m_button->resize(100,100);
}

//the function is called when we click the second button
void MainWindow::handleButton2()
{
    QString n = QString::number(counter);
    m_button->setText(n);

    counter++;
}

