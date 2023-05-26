/**
 * @level Protected
 * @usage U5
 */
#ifndef CATIConvertData_H
#define CATIConvertData_H
// COPYRIGHT DASSAULT SYSTEMES  1997
//=============================================================================
//
// Interface CATIConvertData :
//     
//       Gestion de la conversion des documents en cxrn
//
//=============================================================================
// Usage Notes:
//
//=============================================================================
// Octobre. 97   Creation                                Yannick WALLIER
//=============================================================================

#include "CATInterfaceObject.h"

#include "AC0CATPL.h"
extern  ExportedByAC0CATPL IID IID_CATIConvertData ;


class  ExportedByAC0CATPL CATIConvertData : public CATInterfaceObject
{
  CATDeclareInterface;
  
  public:
  
  // Conversion Method 
  //---------------------------------------------------------------------
  virtual int Convert( const int CodePage, const int Real,const int Integer) = 0;
 
} ;

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler(CATIConvertData, CATInterfaceObject);
#endif
