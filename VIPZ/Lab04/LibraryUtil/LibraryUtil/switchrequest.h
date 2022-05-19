#ifndef SWITCHREQUEST_H
#define SWITCHREQUEST_H

#include "request.h"

class SwitchRequest : public Request
{
    QString listname;
public:
    SwitchRequest(const QString& listname);

    RequestType getType() const;
    void processWithContext(ListsFacade *context) const;
};

#endif // SWITCHREQUEST_H
