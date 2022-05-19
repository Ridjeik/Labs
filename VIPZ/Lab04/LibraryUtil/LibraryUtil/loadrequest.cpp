#include "loadrequest.h"

LoadRequest::LoadRequest(const QString &filename) : filename(filename)
{

}

Request::RequestType LoadRequest::getType() const
{
    return RequestType::LoadRequest;
}

void LoadRequest::processWithContext(ListsFacade *context) const
{
    context->loadFromFileToCurrentList(filename);
}


