#ifndef CATIProjectFlag_H
#define CATIProjectFlag_H
// COPYRIGHT DASSAULT SYSTEMES  1997
//=============================================================================
//
// Interface CATIProjectFlag :
//     
//       Gestion du marquage modele en cxrn
//
//=============================================================================
// Usage Notes:
//
//=============================================================================
// Aout. 97   Creation                                Pascal Guellec
//=============================================================================

/**
 * @level Protected
 * @usage U3
 */

#include "CATBaseUnknown.h"
#include "CATListOfCATUnicodeString.h"

#include "AD0XXBAS.h"
extern ExportedByAD0XXBAS IID IID_CATIProjectFlag;

class ExportedByAD0XXBAS CATIProjectFlag : public CATBaseUnknown
{
  CATDeclareInterface;
  public:
  
  // To Get Project List
  //---------------------------------------------------------------------
  virtual CATListOfCATUnicodeString* GetFlagOnWriteEvent() = 0;
  virtual CATListOfCATUnicodeString* GetFlagOnReadEvent() = 0;
 
} ;

CATDeclareHandler ( CATIProjectFlag, CATBaseUnknown);

#endif
