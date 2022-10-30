#include "worker.h"
#include <QDebug>
#include <QThread>

/*
 * CTOR
 */
Worker::Worker(QObject *parent) : QObject(parent)
{
    // empty
}



void Worker::testEvent()
{
    qDebug() << "Test Event occured! Thread-ID: " << QThread::currentThreadId();
}
