#ifndef CATEndDirectManipulation_h
#define CATEndDirectManipulation_h

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "CATNotification.h"
#include "CATAfrSelection.h"

class ExportedByCATAfrSelection CATEndDirectManipulation : public CATNotification
{
  CATDeclareClass;

  public:
    CATEndDirectManipulation();
    virtual ~CATEndDirectManipulation();
    
};

#endif
