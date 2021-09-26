#ifndef TXTBUILDER_H
#define TXTBUILDER_H

#include <QDebug>
#include "builder.h"

class TXTBuilder : public Builder
{

    Q_OBJECT


public:
    explicit TXTBuilder(QString FileDir, QObject *Parent = nullptr);

    void buildXMLFile(const QString&);
    double findMeasurement(const ComparisonInput& );
};

#endif // TXTBUILDER_H
