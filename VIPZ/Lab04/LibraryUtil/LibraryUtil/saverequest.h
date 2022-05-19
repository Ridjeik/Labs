#ifndef SAVEREQUEST_H
#define SAVEREQUEST_H

#include "request.h"

class SaveRequest : public Request
{
    QString filename;
public:
    SaveRequest(const QString& filename);

    RequestType getType() const;
    void processWithContext(ListsFacade *context) const;
};

#endif // SAVEREQUEST_H
