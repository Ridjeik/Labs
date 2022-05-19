#include "switchrequest.h"

SwitchRequest::SwitchRequest(const QString &listname) : listname(listname)
{}

Request::RequestType SwitchRequest::getType() const
{
    return RequestType::SwitchRequest;
}

void SwitchRequest::processWithContext(ListsFacade *context) const
{
    context->setCurrentList(listname);
}
