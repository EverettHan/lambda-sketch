#ifndef CATIP2PPeerFactory_H
#define CATIP2PPeerFactory_H

// COPYRIGHT DASSAULT SYSTEMES 2002


#include "CATP2PCore.h"
#include "IUnknown.h"
#include "CATBaseUnknown.h"
#include "CATMacForRtti.h"


class CATIP2PPeer;

/** 
 * CATIP2PPeerFactory is the class factory of the class
 * CATIP2PPeer
 *
 */
class  ExportedByCATP2PCore CATIP2PPeerFactory : public IUnknown
{
  CATDeclareClass_Deprec;
  public:
  /**
   * 
   */
  static  CATIP2PPeer* GetLocalPeer();

};

#endif

