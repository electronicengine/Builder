#include "xmlmaker.h"
#include "builder.h"
#include "csvbuilder.h"

XMLMaker::XMLMaker(QObject *Parent) : QObject(Parent)
{

}

void XMLMaker::setData(double Freq, double Data, int Phi, int Theta)
{
    static int index = 0;

    Xml_Writer->writeStartElement("Data :" + QString::number(index++));

    Xml_Writer->writeTextElement("Frequency:", QString::number(Freq));
    Xml_Writer->writeTextElement("Phi:", QString::number(Phi));
    Xml_Writer->writeTextElement("Theta:", QString::number(Theta));
    Xml_Writer->writeTextElement("Measurement:", QString::number(Data));

    Xml_Writer->writeEndElement();

}


void XMLMaker::setFrequencyData(Frequency &Freq)
{


    Xml_Writer->writeStartElement("Frequency : " + QString::number(Freq.frequency));

    for(int i=0; i<(int)Freq.phi_probe.size(); i++)
    {

        for(int k=0; k<(int)Freq.phi_probe[i].measurement.size(); k++)
        {
            Xml_Writer->writeTextElement("Phi:", QString::number(i*15));
            Xml_Writer->writeTextElement("Theta:", QString::number(k*15));
            Xml_Writer->writeTextElement("Measurement:", QString::number(Freq.phi_probe[i].measurement[k]));
        }

    }

    Xml_Writer->writeEndElement();

}



void XMLMaker::setFileName(const QString &Name)
{

    if(!Xml_File)
        return;

    Xml_File = new QFile(Name);

    Xml_File->open(QIODevice::WriteOnly);

    if(!Xml_Writer)
        return;

    Xml_Writer = new QXmlStreamWriter(Xml_File);

    Xml_Writer->setAutoFormatting(true);
    Xml_Writer->writeStartDocument();

    Xml_Writer->writeStartElement("SAVINGS");
}



void XMLMaker::closeFile()
{
    Xml_Writer->writeEndElement();

    Xml_File->close();

    delete Xml_Writer;
    delete Xml_File;
}




