#ifndef CATUExitCrypt_h
#define CATUExitCrypt_h


// COPYRIGHT DASSAULT SYSTEMES  2002

   
#include "CATBaseUnknown.h"
#include "JS0CRYPTEXIT.h"


class ExportedByJS0CRYPTEXIT CATUExitCrypt : public CATBaseUnknown 
{
  CATDeclareClass;
  
  public :
  
  /** @nodoc */
  CATUExitCrypt();
  
  /** @nodoc */
  virtual ~CATUExitCrypt();
};

#endif
