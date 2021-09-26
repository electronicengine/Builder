#ifndef FILEOPS_H
#define FILEOPS_H

#include <QObject>
#include <QStringList>
#include <QDebug>
#include "jsonbuilder.h"
#include "csvbuilder.h"
#include "txtbuilder.h"


enum FileExtention
{

    json,
    txt,
    csv

};



struct CaseFile
{
    int index;
    FileExtention extantion;
    QString full_name;
    Builder *builder;
};


struct ComparisonOutput
{
    double measurement1;
    double measurement2;
    double diffirence;
};


struct ComparisonInput
{
    double frequency;
    double theta;
    double phi;
};


class FileOperations : public QObject
{

    Q_OBJECT

    CaseFile File_1;
    CaseFile File_2;

    JsonBuilder *Json_Buildier;
    CSVBuilder *CSV_Buildier;
    TXTBuilder *TXT_Buildier;

    FileExtention getExtention(const QString &FullDir);
    void getContent(QStringList &Content);

    QString readFileText();
    std::vector<CaseFile> Case_Files;

public:
    explicit FileOperations(QObject *Parent = nullptr);

    void setFile(const QString&FullDir, int FileNumber);
    ComparisonOutput getComparison(const ComparisonInput &Input);
    void extractXML(const QString &Directory);

};

#endif // FILEOPS_H
