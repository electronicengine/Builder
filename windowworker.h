#ifndef WINDOWWORKER_H
#define WINDOWWORKER_H

#include <QObject>
#include <QDebug>
#include <QFileDialog>
#include "fileoperations.h"
#include "mainwindow.h"

class WindowWorker: public MainWindow
{

    Q_OBJECT

    FileOperations File_Ops;


public:
    explicit WindowWorker(QWidget *Parent = nullptr);

private slots:
    void selectFile1ButtonClicked();
    void selectFile2ButtonClicked();
    void extractXMLButtonCliced();
    void compareButtonClicked();



};

#endif // WINDOWWORKER_H
