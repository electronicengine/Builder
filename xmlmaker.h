#ifndef XMLMAKER_H
#define XMLMAKER_H

#include <QObject>
#include <QFileDialog>
#include <QXmlStreamWriter>


struct Frequency;

class XMLMaker : public QObject
{

    Q_OBJECT

    QFile *Xml_File;
    QXmlStreamWriter *Xml_Writer;

public:
    explicit XMLMaker(QObject *Parent = nullptr);

    void setData(double Freq, double Data, int Phi, int Theta);
    void setFrequencyData(Frequency &Freq);
    void setFileName(const QString &Name);
    void closeFile();
    void setFileDir();

};


#endif // XMLMAKER_H
