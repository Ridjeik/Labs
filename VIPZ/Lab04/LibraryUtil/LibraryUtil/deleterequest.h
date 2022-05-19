#ifndef DELETEREQUEST_H
#define DELETEREQUEST_H

#include "request.h"

class DeleteRequest : public Request
{
    QString listname;
public:
    DeleteRequest(const QString& listname);

    RequestType getType() const;
    void processWithContext(ListsFacade *context) const;
};

#endif // DELETEREQUEST_H
