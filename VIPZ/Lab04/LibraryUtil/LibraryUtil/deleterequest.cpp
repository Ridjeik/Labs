#include "deleterequest.h"

DeleteRequest::DeleteRequest(const QString &listname) : listname(listname) {}

Request::RequestType DeleteRequest::getType() const
{
    return RequestType::DeleteRequest;
}

void DeleteRequest::processWithContext(ListsFacade *context) const
{
    context->deleteList(listname);
}

