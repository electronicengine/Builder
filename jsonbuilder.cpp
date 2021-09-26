#include "jsonbuilder.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "fileoperations.h"


JsonBuilder::JsonBuilder(QString FileDir, QObject *Parent) : Builder(Parent)
{
    Input_Dir = FileDir;
}



void JsonBuilder::buildXMLFile(const QString &Dir)
{
    QString val;
    QFile file;
    file.setFileName(Input_Dir);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val = file.readAll();
    file.close();

    QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
    QJsonArray array = d.array();
    XMLMaker maker;

    maker.setFileName(Dir);

    for(int i=0; i<array.size(); i++)
    {
        QJsonObject obj = array.at(i).toObject();
        double freq =  obj.value(QString("Frequency(MHz)")).toDouble();
        int theta = obj.value(QString("Theta")).toDouble();
        int phi = obj.value(QString("Phi")).toDouble();

        QString data = obj.value(QString("Data(dB)")).toString();

        double measurement = data.split(',').at(0).toDouble();

        if(data.split(',').size() >= 2)
            measurement -= (data.split(',').at(1).toDouble() / 100);

        maker.setData(freq, measurement, phi, theta);

    }
}



double JsonBuilder::findMeasurement(const ComparisonInput& Input)
{
    QString val;
    QFile file;
    file.setFileName(Input_Dir);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val = file.readAll();
    file.close();

    QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
    QJsonArray array = d.array();


    for(int i=0; i<array.size(); i++)
    {
        QJsonObject obj = array.at(i).toObject();
        double freq =  obj.value(QString("Frequency(MHz)")).toDouble();
        int theta = obj.value(QString("Theta")).toDouble();
        int phi = obj.value(QString("Phi")).toDouble();

        QString data = obj.value(QString("Data(dB)")).toString();

        double measurement = data.split(',').at(0).toDouble();

        if(data.split(',').size() >= 2)
            measurement -= (data.split(',').at(1).toDouble() / 100);

        if(Input.theta == theta && Input.phi == phi  && Input.frequency == freq)
            return measurement;
    }

    return -1;
}
