// COPYRIGHT DASSAULT SYSTEMES  2000
#ifndef CATUExitIO_h
#define CATUExitIO_h


#include "CATBaseUnknown.h"
#include "JS0FILEEXIT.h"


class ExportedByJS0FILEEXIT CATUExitIO : public CATBaseUnknown 
{
  CATDeclareClass;
  
  public :
  
  /** @nodoc */
  CATUExitIO();
  
  /** @nodoc */
  virtual ~CATUExitIO();
};

#endif
