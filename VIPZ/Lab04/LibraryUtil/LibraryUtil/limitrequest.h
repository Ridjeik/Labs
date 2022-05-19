#ifndef LIMITREQUEST_H
#define LIMITREQUEST_H

#include "request.h"

class LimitRequest : public Request
{
    size_t limitationNumber;
public:
    LimitRequest(size_t limitationNumber);

    RequestType getType() const;
    void processWithContext(ListsFacade *context) const;
};

#endif // LIMITREQUEST_H
