#include <iostream>
#include "listsfacade.h"
#include "lab10_lib.h"

extern int listCount;
extern List *lists;
extern List *currentList;

ListsFacade* ListsFacade::instance = nullptr;

ListsFacade::ListsFacade()
{}

ListsFacade *ListsFacade::getInstance()
{
    if(!ListsFacade::instance)
       instance = new ListsFacade();

    std::cout.rdbuf(instance->buffer.rdbuf());
    return instance;
}

size_t ListsFacade::getListCount()
{
    return listCount;
}

std::vector<ListModel> ListsFacade::getAllLists()
{
    std::vector<ListModel> result;

    for(size_t i = 0; i < getListCount(); i++)
    {
        result.push_back(ListModel(lists + i));
    }

    return result;
}

ListModel ListsFacade::getCurrentList()
{
    return ListModel(currentList);
}

ListsFacade *ListsFacade::setCurrentList(const QString &listname)
{
    return executeRawCommand("switch \"" + listname + "\"");
}

ListsFacade *ListsFacade::sortCurrentList(Target sortTarget, bool descending)
{
    QString command = "sortby " + ToString(sortTarget) + (descending ? " --descending" : "");
    return executeRawCommand(command);
}

ListsFacade *ListsFacade::executeRawCommand(const QString &command)
{
    buffer.str("");
    char c_command[MAX_LINE_LEN];
    strcpy(c_command, command.toStdString().c_str());
    qDebug() << "Executing command:" << c_command;
    executeLine(c_command);
    return this;
}

ListsFacade *ListsFacade::filterCurrentList(Target filterTarget, Criterea filterCriteria, const QString &param)
{
    QString command = "filter " + ToString(filterTarget) + " " + ToString(filterCriteria) + " " + (filterCriteria == Criterea::AboveAverage || filterCriteria == Criterea::BelowAverage ? "" :  param) + "";
    return executeRawCommand(command);
}

ListsFacade *ListsFacade::limitCurrentList(size_t limitationNumber)
{
    return executeRawCommand("limit " + QString::number(limitationNumber));
}

ListsFacade *ListsFacade::loadFromFileToCurrentList(const QString &filename)
{
    return executeRawCommand("load \"" + filename + "\"");
}

ListsFacade *ListsFacade::createNewList(const QString &listname)
{
    return executeRawCommand("create \"" + listname + "\"");
}

ListsFacade *ListsFacade::saveCurrentListToFile(const QString &filename)
{
    return executeRawCommand("save \"" + filename + "\"");
}

ListsFacade *ListsFacade::deleteList(const QString &listname)
{
    return executeRawCommand("delete " + listname);
}

ListsFacade *ListsFacade::addElement(const Book &book)
{
    ListItem *newLI = (ListItem *)malloc(sizeof(ListItem));
    newLI->data = book;
    newLI->next = nullptr;
    addElementToList(currentList, newLI, getCurrentList().size());
    return this;
}

QString ListsFacade::getLastCommandResult()
{
    return QString(buffer.str().c_str());
}

QString ListsFacade::ToString(Target target)
{
    switch (target) {
    case ListsFacade::Target::AuthorName:
        return "name";
    case ListsFacade::Target::AuthorSurname:
        return "surname";
    case ListsFacade::Target::BookTitle:
        return "title";
    case ListsFacade::Target::PageCount:
        return "pages";
    case ListsFacade::Target::PublicationYear:
        return "year";
    case ListsFacade::Target::BookPrice:
        return "price";
    }
}

QString ListsFacade::ToString(Criterea criteria)
{
    switch (criteria) {
    case ListsFacade::Criterea::AboveAverage:
        return "--aboveaverage";
    case ListsFacade::Criterea::BelowAverage:
        return "--belowaverage";
    case ListsFacade::Criterea::StartsWith:
        return "--startswith";
    case ListsFacade::Criterea::NotStartsWith:
        return "--notstartswith";
    case ListsFacade::Criterea::MoreThan:
        return "--morethan";
    case ListsFacade::Criterea::LessThan:
        return "--lessthan";
    }
}















