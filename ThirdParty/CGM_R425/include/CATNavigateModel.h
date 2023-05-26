/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 1997
//=============================================================================
//
//  Class CATNavigateModel :
//
//=============================================================================
// Usage Notes:
//
//=============================================================================
//
/**
* @level Private 
* @usage U1
*/
#ifndef CATNavigateModel_H
#define CATNavigateModel_H

#include "CATINavigateModel.h"
#include "CATDocument.h"
#include "AC0CATNAV.h"

class CATListValCATInterfaceObject_var;
class CATListValCATUnicodeString;


class ExportedByAC0CATNAV CATNavigateModel : public CATINavigateModel
{
  public :
  CATDeclareKindOf ;

  // adhesion a CATINavigateObject

  virtual CATListValCATUnicodeString* GetIdentificators();
  virtual CATListValCATInterfaceObject_var* GetChildren();

  CATNavigateModel() ;
  virtual ~CATNavigateModel () {} ;  
} ;   
  

#endif      

    
    
















