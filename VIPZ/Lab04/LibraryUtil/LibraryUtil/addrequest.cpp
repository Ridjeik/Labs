#include "addrequest.h"

AddRequest::AddRequest(Book data) : data(data) {}

Request::RequestType AddRequest::getType() const
{
    return RequestType::AddRequest;
}

void AddRequest::processWithContext(ListsFacade *context) const
{
    context->addElement(data);
}
