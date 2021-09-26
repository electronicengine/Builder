#include "fileoperations.h"




FileOperations::FileOperations(QObject *Parent) : QObject(Parent)
{

}



void FileOperations::setFile(const QString &FullDir, int FileNumber)
{
    CaseFile file;

    file.index = FileNumber;
    file.full_name = FullDir;
    file.extantion = getExtention(FullDir);


    switch(file.extantion)
    {
        case csv:

            file.builder = new CSVBuilder(FullDir);
            break;

        case txt:

            file.builder = new TXTBuilder(FullDir);
            break;

        case json:

            file.builder = new JsonBuilder(FullDir);
            break;

        default:

            file.builder = new TXTBuilder(FullDir);
            break;
    }

    Case_Files.push_back(file);
}



ComparisonOutput FileOperations::getComparison(const ComparisonInput &Input)
{

    ComparisonOutput output;

    if(Case_Files.size() < 2)
    {
        output.measurement1 = 0;
        output.measurement2 = 0;
        return output;
    }

    output.measurement1 = Case_Files[0].builder->findMeasurement(Input);
    output.measurement2 = Case_Files[1].builder->findMeasurement(Input);

    output.diffirence = output.measurement1 - output.measurement2;

    return output;

}


void FileOperations::extractXML(const QString &Directory)
{
    if(Case_Files.size() < 2)
        return;

    Case_Files[0].builder->buildXMLFile(Directory + "/File1.xml");
    Case_Files[1].builder->buildXMLFile(Directory + "/File2.xml");
}


FileExtention FileOperations::getExtention(const QString &FullDir)
{

    QString extention = FullDir.split('.').at(1);

    if(extention == "csv")
        return csv;
    else if(extention == "txt")
        return txt;
    else if(extention == "json")
        return json;

    return txt;

}




