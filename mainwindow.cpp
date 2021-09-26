#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(this, SIGNAL(setMeasurement1Text(QString)), ui->measurement1_box, SLOT(setText(QString)));
    connect(this, SIGNAL(setMeasurement2Text(QString)), ui->measurement2_box, SLOT(setText(QString)));
    connect(this, SIGNAL(setDifferenceText(QString)), ui->diffirence_box, SLOT(setText(QString)));
    connect(this, SIGNAL(setFile1Text(QString)), ui->file1_text, SLOT(setText(QString)));
    connect(this, SIGNAL(setFile2Text(QString)), ui->file2_text, SLOT(setText(QString)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

