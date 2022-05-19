#ifndef CREATEREQUEST_H
#define CREATEREQUEST_H

#include "request.h"
#include <QString>

class CreateRequest : public Request
{
    QString listname;
public:
    CreateRequest(const QString& listname);

    RequestType getType() const;
    void processWithContext(ListsFacade *context) const;
};

#endif // CREATEREQUEST_H
