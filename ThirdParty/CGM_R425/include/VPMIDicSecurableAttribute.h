//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2006
//=============================================================================
/**
* @level Private
* @usage U3
*/
#ifndef _VPMIDicSecurableAttribute_h
#define _VPMIDicSecurableAttribute_h

#include "VPMIDicInterfaces.h"

#include "VPMIDicElement.h"

class VPMIDicAttribute;
class VPMIDicSecurableAttribute;

#ifndef LOCAL_DEFINITION_FOR_IID
extern  ExportedByVPMIDicInterfaces const IID IID_VPMIDicSecurableAttribute;
#else
extern "C" const IID IID_VPMIDicSecurableAttribute;
#endif

/**
* To manage the definition of a SecurableAttribute object
*/

class  ExportedByVPMIDicInterfaces VPMIDicSecurableAttribute : public VPMIDicElement
{
  CATDeclareInterface;

public:


  /**
  * @deprecated
  */
  virtual HRESULT GetTarget ( VPMIDicAttribute ** oDicAttribute ) = 0;


  /**
  * @deprecated
  */
  virtual HRESULT SetTarget ( const VPMIDicAttribute * iDicAttribute ) = 0;


  /**
  * @deprecated
  */
  virtual boolean IsSecured ( ) const = 0;


  /**
  * @deprecated
  */
  virtual HRESULT SetSecured ( boolean iSecured ) = 0;

};
#endif
