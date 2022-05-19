#ifndef SORTREQUEST_H
#define SORTREQUEST_H

#include "request.h"
#include "listsfacade.h"

class SortRequest : public Request
{
    ListsFacade::Target sortTarget;
    bool descending;
public:
    SortRequest(ListsFacade::Target sortTarget, bool descending = false);

    RequestType getType() const;
    void processWithContext(ListsFacade *context) const;
};

#endif // SORTREQUEST_H
