#include "sortrequest.h"

SortRequest::SortRequest(ListsFacade::Target sortTarget, bool descending) : sortTarget(sortTarget), descending(descending)
{}

Request::RequestType SortRequest::getType() const
{
    return RequestType::SortRequest;
}

void SortRequest::processWithContext(ListsFacade *context) const
{
    context->sortCurrentList(sortTarget, descending);
}
