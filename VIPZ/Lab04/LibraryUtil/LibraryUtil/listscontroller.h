#ifndef LISTSCONTROLLER_H
#define LISTSCONTROLLER_H
#include "request.h"

class MainWindow;

class ListsController
{

    ListsFacade* context;

public:
    ListsController();

    MainWindow* getConnectedWindow();
    void processRequest(MainWindow *sender, const Request& request);
    void sendNewViewTo(MainWindow* window);
};

#endif // LISTSCONTROLLER_H
