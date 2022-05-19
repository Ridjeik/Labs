#ifndef LISTSFACADE_H
#define LISTSFACADE_H
#include "listmodel.h"
#include <sstream>

class ListsFacade
{
    static ListsFacade* instance;
    ListsFacade();

public:

    enum class Target
    {
        AuthorName,
        AuthorSurname,
        BookTitle,
        PageCount,
        PublicationYear,
        BookPrice
    };

    enum class Criterea
    {
        AboveAverage,
        BelowAverage,
        StartsWith,
        NotStartsWith,
        MoreThan,
        LessThan
    };

    ListsFacade(const ListsFacade& other) = delete;

    static ListsFacade* getInstance();
    size_t getListCount();
    std::vector<ListModel> getAllLists();
    ListModel getCurrentList();
    ListsFacade *setCurrentList(const QString& listname);
    ListsFacade *sortCurrentList(Target sortTarget, bool descending = false);
    ListsFacade *executeRawCommand(const QString& command);
    ListsFacade *filterCurrentList(Target filterTarget, Criterea filterCriteria, const QString& param);
    ListsFacade *limitCurrentList(size_t limitationNumber);
    ListsFacade *loadFromFileToCurrentList(const QString& filename);
    ListsFacade *createNewList(const QString& listname);
    ListsFacade *saveCurrentListToFile(const QString& filename);
    ListsFacade *deleteList(const QString& listname);
    ListsFacade *addElement(const Book& book);
    QString getLastCommandResult();

private:
    std::stringstream buffer;
    static QString ToString(Target target);
    static QString ToString(Criterea criteria);
};

#endif // LISTSFACADE_H
