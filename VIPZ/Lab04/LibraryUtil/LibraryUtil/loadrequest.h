#ifndef LOADREQUEST_H
#define LOADREQUEST_H

#include "request.h"

class LoadRequest : public Request
{
    QString filename;
public:
    LoadRequest(const QString& filename);

    RequestType getType() const;
    void processWithContext(ListsFacade *context) const;
};

#endif // LOADREQUEST_H
