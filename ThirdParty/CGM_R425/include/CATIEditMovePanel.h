#ifndef CATIEditMovePanel_h
#define CATIEditMovePanel_h

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "CATAfrSelection.h"
#include "CATBaseUnknown.h"

extern ExportedByCATAfrSelection IID IID_CATIEditMovePanel;

class ExportedByCATAfrSelection CATIEditMovePanel : public CATBaseUnknown
{
  CATDeclareInterface;
public:

  virtual int CanUseMovePanel() = 0;

};

CATDeclareHandler(CATIEditMovePanel, CATBaseUnknown);

#endif
