#include "filterrequest.h"

FilterRequest::FilterRequest(ListsFacade::Target filterTarget, ListsFacade::Criterea filterCriteria, const QString& param)
    : filterTarget(filterTarget), filterCriteria(filterCriteria), paramString(param)
{}

Request::RequestType FilterRequest::getType() const
{
    return RequestType::FilterRequest;
}

void FilterRequest::processWithContext(ListsFacade *context) const
{
    context->filterCurrentList(filterTarget, filterCriteria, paramString);
}
