/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES	2000
#ifndef _CATIIndicator_h
#define _CATIIndicator_h

#include "CATISymbol.h"

class CATNotification;
class CATUnicodeString;

/**
 * Interface to create an indicaot.
 * <b>Role</b>: Call this interface on a CATIISO obejct.
 */
#include "UIModelInterfaces.h"
#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByUIModelInterfaces IID IID_CATIIndicator;
#else
extern "C" const IID IID_CATIIndicator;
#endif
 
class ExportedByUIModelInterfaces CATIIndicator : public CATISymbol
{
public:
  CATDeclareInterface;

  /**
  * Retrieves the edit notification.
  * @return
  * The CATNotification
  */
  virtual CATNotification* GetEditNotification() = 0;

  /**
  * Retrieves the activate notification.
  * @return
  * The CATNotification
  */
  virtual CATNotification* GetActivateNotification() = 0;
  
  /**
  * Retrieves the contextual notification.
  * @return
  * The CATNotification
  */
  virtual CATNotification* GetContextNotification() = 0;
  
};

#endif
