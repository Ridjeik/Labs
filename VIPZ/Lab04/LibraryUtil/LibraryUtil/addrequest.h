#ifndef ADDREQUEST_H
#define ADDREQUEST_H

#include "request.h"

class AddRequest : public Request
{
    Book data;
public:
    AddRequest(Book data);

    RequestType getType() const;
    void processWithContext(ListsFacade *context) const;
};

#endif // ADDREQUEST_H
