#ifndef REQUEST_H
#define REQUEST_H

#include "listsfacade.h"

class Request
{
public:
    enum class RequestType
    {
        SortRequest,
        FilterRequest,
        CreateRequest,
        AddRequest,
        DeleteRequest,
        LoadRequest,
        SaveRequest,
        SwitchRequest,
        LimitRequest
    };

    Request();

    virtual RequestType getType() const = 0;
    virtual void processWithContext(ListsFacade* context) const = 0;
};

#endif // REQUEST_H
