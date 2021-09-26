#ifndef BUILDER_H
#define BUILDER_H

#include <QObject>
#include "xmlmaker.h"

class ComparisonInput;


struct Phi
{
    double phi;
    std::vector<double> measurement;

};


struct Frequency
{
    double frequency;
    std::vector<Phi> phi_probe;

};
class Builder : public QObject
{

    Q_OBJECT




public:
    explicit Builder(QObject *Parent = nullptr);

    virtual void buildXMLFile(const QString&) = 0;
    virtual double findMeasurement(const ComparisonInput&) = 0;


protected:
    QString Input_Dir;

    std::vector<Frequency> Frequencies_;

};

#endif // BUILDER_H
