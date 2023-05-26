#ifndef CATOmyOpenWrapper_H
#define CATOmyOpenWrapper_H

#include "CATBaseUnknown.h"
#include "CATOMY.h"

class ExportedByCATOMY CATOmyOpenWrapper
{
public:
  virtual HRESULT Open() = 0;
};

#endif
