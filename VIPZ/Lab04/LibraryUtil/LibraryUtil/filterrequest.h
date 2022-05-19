#ifndef FILTERREQUEST_H
#define FILTERREQUEST_H

#include "request.h"

class FilterRequest : public Request
{
    ListsFacade::Target filterTarget;
    ListsFacade::Criterea filterCriteria;
    QString paramString;
public:
    FilterRequest(ListsFacade::Target filterTarget, ListsFacade::Criterea filterCriteria, const QString& param);

    RequestType getType() const;
    void processWithContext(ListsFacade *context) const;
};

#endif // FILTERREQUEST_H
