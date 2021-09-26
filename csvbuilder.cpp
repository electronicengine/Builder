#include <QFile>
#include <QStringList>
#include <QDebug>
#include "csvbuilder.h"
#include "fileoperations.h"

CSVBuilder::CSVBuilder(QString FileDir, QObject *Parent) : Builder(Parent)
{
    QFile file(FileDir);
    if (!file.open(QIODevice::ReadOnly)) {
      qDebug() << file.errorString();
    }

    QStringList wordList;
    while (!file.atEnd())
    {
        QString line = file.readLine();
        Frequency freq;

        if(line.contains("Theta Angle"))
            freq.frequency = line.split(';').at(0).toDouble();


        if(line.contains("(dB);Response  (dB)\r\n"))
        {
            for(int i=0; i<24; i++)
            {
                Phi phi_probe;
                QString data_line = file.readLine();
                QStringList list = data_line.split(';');

                phi_probe.phi = list.at(1).toDouble();

                for(int k=2; k<list.size(); k++)
                {
                    double measurement = list.at(k).split('-').at(1).split(',').at(0).toDouble() +
                                        ((double)list.at(k).split('-').at(1).split(',').at(1).toDouble() / 100);

                    measurement *= -1;

                    phi_probe.measurement.push_back(measurement);

                }

                freq.phi_probe.push_back(phi_probe);
            }

            Frequencies_.push_back(freq);
        }

    }

}



void CSVBuilder::buildXMLFile(const QString &Dir)
{

    XMLMaker maker;

    maker.setFileName(Dir);

    for(int i=0; i<(int)Frequencies_.size(); i++)
        maker.setFrequencyData(Frequencies_[i]);

    maker.closeFile();

}



double CSVBuilder::findMeasurement(const ComparisonInput& Input)
{

    for(int i = 0; i < (int) Frequencies_.size(); i++)
    {
        if(Input.frequency == Frequencies_[i].frequency)
        {
            int phi_probe = Input.phi;
            int theta_probe = Input.theta;

            return Frequencies_[i].phi_probe[phi_probe / 15].measurement[theta_probe / 15];
        }
    }

    return -1;

}
