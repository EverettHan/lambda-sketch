//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2014/04/09
//===================================================================
// CATIAfrCtxMenuToNewInfra.cpp
// Header definition of class CATIAfrCtxMenuToNewInfra
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2014/04/09 Creation: Code generated by the 3DS wizard
//===================================================================
#ifndef CATIAfrCtxMenuToNewInfra_H
#define CATIAfrCtxMenuToNewInfra_H

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"

extern ExportedByCATAfrItf  IID IID_CATIAfrCtxMenuToNewInfra ;


class ExportedByCATAfrItf CATIAfrCtxMenuToNewInfra: public CATBaseUnknown
{
CATDeclareInterface;

public:

  virtual  void FillFromOldContextMenu(CATBaseUnknown* iAccess, CATBoolean iEditTranslationHeader) = 0;

};

//-----------------------------------------------------------------------

#endif
