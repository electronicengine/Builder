#include "txtbuilder.h"
#include "fileoperations.h"

TXTBuilder::TXTBuilder(QString FileDir, QObject *Parent) : Builder(Parent)
{
    Input_Dir = FileDir;

}



void TXTBuilder::buildXMLFile(const QString &Dir)
{

    QFile file(Input_Dir);
    if (!file.open(QIODevice::ReadOnly)) {
      qDebug() << file.errorString();
    }

    XMLMaker maker;

    maker.setFileName(Dir);

    while (!file.atEnd())
    {
        QString line = file.readLine();

        if(line.contains("Freq(MHz)"))
            continue;

        QStringList pieces = line.split(';');

        double freq = pieces.at(0).toDouble();
        int theta = pieces.at(1).toInt();
        int phi = pieces.at(2).toInt();
        double measurement = pieces.at(3).split(',').at(0).toDouble();

        if(pieces.at(3).split(',').size() >= 2)
            measurement -= (pieces.at(3).split(',').at(1).toDouble() / 100);

        maker.setData(freq, measurement, phi, theta);

    }

    maker.closeFile();

}



double TXTBuilder::findMeasurement(const ComparisonInput &Input)
{
    QFile file(Input_Dir);
    if (!file.open(QIODevice::ReadOnly)) {
      qDebug() << file.errorString();
    }

    while (!file.atEnd())
    {
        QString line = file.readLine();

        if(line.contains("Freq(MHz)"))
            continue;

        QStringList pieces = line.split(';');

        double freq = pieces.at(0).toDouble();
        int theta = pieces.at(1).toInt();
        int phi = pieces.at(2).toInt();
        double measurement = pieces.at(3).split(',').at(0).toDouble();

        if(pieces.at(3).split(',').size() >= 2)
            measurement -= (pieces.at(3).split(',').at(1).toDouble() / 100);


        if(Input.frequency == freq && Input.theta == theta && Input.phi == phi)
            return measurement;

    }

    return -1;

}
