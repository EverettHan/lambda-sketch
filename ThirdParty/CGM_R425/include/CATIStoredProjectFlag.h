/**
 * @level Protected
 * @usage U3
 */
#ifndef CATIStoredProjectFlag_H
#define CATIStoredProjectFlag_H
// COPYRIGHT DASSAULT SYSTEMES  1997
//=============================================================================
//
// Interface CATIStoredProjectFlag :
//     
//       Recuperation du marquage modele en cxrn sauvegarde sur disque
//       (la valuation des cles a ete realisee a la sauvegarde via 
//        CATIProjectFlag)
//
//=============================================================================
// Usage Notes:
//
//=============================================================================
// Jan. 99   Creation                                slg
//=============================================================================

#include "CATBaseUnknown.h"
#include "CATListOfCATUnicodeString.h"

#include "AD0XXBAS.h"
extern ExportedByAD0XXBAS IID IID_CATIStoredProjectFlag;

class ExportedByAD0XXBAS CATIStoredProjectFlag : public CATBaseUnknown
{
  CATDeclareInterface;
  public:
  
  // To Get Project List
  //---------------------------------------------------------------------
  virtual HRESULT GetStoredFlags ( CATListOfCATUnicodeString& StoredFlags ) = 0;
 
} ;

CATDeclareHandler ( CATIStoredProjectFlag, CATBaseUnknown);

#endif
