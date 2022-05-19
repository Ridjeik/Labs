#include "saverequest.h"

SaveRequest::SaveRequest(const QString &filename) : filename(filename)
{}

Request::RequestType SaveRequest::getType() const
{
    return RequestType::SaveRequest;
}

void SaveRequest::processWithContext(ListsFacade *context) const
{
    context->saveCurrentListToFile(filename);
}
