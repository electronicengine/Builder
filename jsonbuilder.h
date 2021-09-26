#ifndef JSONBUILDER_H
#define JSONBUILDER_H

#include <QDebug>
#include "builder.h"

class ComparisonInput;


class JsonBuilder : public Builder
{

    Q_OBJECT

public:
    explicit JsonBuilder(QString FileDir, QObject *Parent = nullptr) ;

    void buildXMLFile(const QString&);
    double findMeasurement(const ComparisonInput& );


};

#endif // JSONBUILDER_H
