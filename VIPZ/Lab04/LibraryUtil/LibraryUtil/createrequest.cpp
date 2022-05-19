#include "createrequest.h"

void CreateRequest::processWithContext(ListsFacade *context) const
{
    context->createNewList(listname);
}

CreateRequest::CreateRequest(const QString &listname) : listname(listname)
{}

Request::RequestType CreateRequest::getType() const
{
    return RequestType::CreateRequest;
}
