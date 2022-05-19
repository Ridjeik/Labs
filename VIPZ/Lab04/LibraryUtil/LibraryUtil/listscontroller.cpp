#include <unistd.h>
#include "createrequest.h"
#include "listscontroller.h"
#include "listsfacade.h"
#include "mainwindow.h"


ListsController::ListsController() : context(ListsFacade::getInstance())
{

}

MainWindow *ListsController::getConnectedWindow()
{
    MainWindow* result = new MainWindow(this);
    return result;
}

void ListsController::processRequest(MainWindow *sender, const Request &request)
{
    request.processWithContext(context);
    sendNewViewTo(sender);
}

void ListsController::sendNewViewTo(MainWindow *window)
{
    QTabWidget* newView = new QTabWidget();

    newView->setTabsClosable(true);
    for(auto list : context->getAllLists())
    {
        int currentIndex = newView->addTab(list.toTableView(), list.listName());
        if(list.listName() == context->getCurrentList().listName())
            newView->setCurrentIndex(currentIndex);
    }
    window->onListsChanged(newView);
}



