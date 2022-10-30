#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QThread>
#include <QtConcurrent/QtConcurrent>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // connect QFuturewatcher with different slots
    connect(&m_futureWatcher, SIGNAL( started()  ), this, SLOT( computationStarted() )); // compuation of future value begins
    connect(&m_futureWatcher, SIGNAL( canceled() ), this, SLOT( computationEnded() ));
    connect(&m_futureWatcher, SIGNAL( finished() ), this, SLOT( computationEnded() ));
}

MainWindow::~MainWindow()
{
    delete ui;
}

// simulate a slow computational process
int slowFactorial(int n)
{
    int result = 1;
    for( int i = 1; i <= n; i++ )
    {
        result *= i;
        QThread::sleep(1);
    }
    return result;
}

void MainWindow::on_computeButton_clicked()
{
    if( m_futureWatcher.isRunning() )
    {
        return;
    }

    int value = ui->editValue->text().toInt();
    QFuture<int> future = QtConcurrent::run(slowFactorial, value);
    m_futureWatcher.setFuture(future);
}

void MainWindow::computationStarted()
{
    ui->computeButton->setEnabled(true);
    ui->resultLabel->setText("Wait...");
}

void MainWindow::computationEnded()
{
    if( m_futureWatcher.isFinished() )
    {
        ui->resultLabel->setText( QString::number(m_futureWatcher.result() ));
    }
}


