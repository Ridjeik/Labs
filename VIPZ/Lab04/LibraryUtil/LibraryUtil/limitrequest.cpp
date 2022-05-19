#include "limitrequest.h"

LimitRequest::LimitRequest(size_t limitationNumber) : limitationNumber(limitationNumber)
{

}

Request::RequestType LimitRequest::getType() const
{
    return RequestType::LimitRequest;
}

void LimitRequest::processWithContext(ListsFacade *context) const
{
    context->limitCurrentList(limitationNumber);
}
