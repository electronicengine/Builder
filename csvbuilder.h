#ifndef CSVBUILDER_H
#define CSVBUILDER_H

#include <QObject>
#include "builder.h"


class ComparisonInput;

class CSVBuilder : public Builder
{

    Q_OBJECT


public:
    explicit CSVBuilder(QString FileDir, QObject *Parent = nullptr);


    void buildXMLFile(const QString&);
    double findMeasurement(const ComparisonInput& );
};

#endif // CSVBUILDER_H
