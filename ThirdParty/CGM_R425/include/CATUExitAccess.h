#ifndef CATUExitAccess_h
#define CATUExitAccess_h


// COPYRIGHT DASSAULT SYSTEMES  2000

   
#include "CATBaseUnknown.h"
#include "JS0FILEEXIT.h"


class ExportedByJS0FILEEXIT CATUExitAccess : public CATBaseUnknown 
{
  CATDeclareClass;
  
  public :
  
  /** @nodoc */
  CATUExitAccess();
  
  /** @nodoc */
  virtual ~CATUExitAccess();
};

#endif
