#include "windowworker.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

WindowWorker::WindowWorker(QWidget *Parent) : MainWindow(Parent)
{


    connect(ui->select_button_1, SIGNAL(clicked()), this, SLOT(selectFile1ButtonClicked()));
    connect(ui->select_button_2, SIGNAL(clicked()), this, SLOT(selectFile2ButtonClicked()));
    connect(ui->extract_xml, SIGNAL(clicked()), this, SLOT(extractXMLButtonCliced()));
    connect(ui->compare_button, SIGNAL(clicked()), this, SLOT(compareButtonClicked()));


}



void WindowWorker::extractXMLButtonCliced()
{
    QString dir = QFileDialog::getExistingDirectory(this);

    File_Ops.extractXML(dir);

}



void WindowWorker::compareButtonClicked()
{
    ComparisonOutput output;
    ComparisonInput input;

    input.frequency = ui->frequency_box->value();
    input.theta = ui->theta_box->value();
    input.phi = ui->phi_box->value();

    output = File_Ops.getComparison(input);

    if(output.measurement1 == 0 && output.measurement2 == 0)
        return;

    emit setMeasurement1Text(QString::number(output.measurement1));
    emit setMeasurement2Text(QString::number(output.measurement2));

    emit setDifferenceText(QString::number(output.diffirence));


}



void WindowWorker::selectFile1ButtonClicked()
{

    QString file_name = QFileDialog::getOpenFileName(this);

    if(file_name != "")
    {
        File_Ops.setFile(file_name, 1);

        emit setFile1Text(file_name);
    }

}



void WindowWorker::selectFile2ButtonClicked()
{

    QString file_name = QFileDialog::getOpenFileName(this);

    File_Ops.setFile(file_name, 2);

    emit setFile2Text(file_name);

}
