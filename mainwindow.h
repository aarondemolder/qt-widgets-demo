#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //our slot for receiving a signal
    void handleButton();
    void handleButton2();

private:
    Ui::MainWindow *ui;

    //button 1 which sets loaded txt to own label
    QPushButton *m_button;

    //button 2 sets button 1 label to counter value
    QPushButton *m_button2;
    int counter = 0;
};
#endif // MAINWINDOW_H
