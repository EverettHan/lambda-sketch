// COPYRIGHT DASSAULT SYSTEMES  2004
#ifndef CATUExitCryptLockBytes_H
#define CATUExitCryptLockBytes_H

#if defined(__JS0CRYPTLBEXIT)
#define ExportedByJS0CRYPTLBEXIT DSYExport
#else
#define ExportedByJS0CRYPTLBEXIT DSYImport
#endif
#include "DSYExport.h"
   
#include "CATBaseUnknown.h"



class ExportedByJS0CRYPTLBEXIT CATUExitCryptedILockBytes : public CATBaseUnknown 
{
  CATDeclareClass;
  
  public :
  
  /** @nodoc */
  CATUExitCryptedILockBytes();
  
  /** @nodoc */
  virtual ~CATUExitCryptedILockBytes();
};

#endif
