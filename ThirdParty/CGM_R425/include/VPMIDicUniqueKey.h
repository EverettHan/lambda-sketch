//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2010
//=============================================================================
/**
* @level Private
* @usage U3
*/
#ifndef _VPMIDicUniqueKey_h
#define _VPMIDicUniqueKey_h

#include "VPMIDicInterfaces.h"
#include "VPMIDicElement.h"
#include "CATLISTV_VPMIDicSimple_var.h"
#include "CATBoolean.h"		

#ifndef LOCAL_DEFINITION_FOR_IID
extern  ExportedByVPMIDicInterfaces const IID IID_VPMIDicUniqueKey;
#else
extern "C" const IID IID_VPMIDicUniqueKey;
#endif

class ExportedByVPMIDicInterfaces VPMIDicUniqueKey : public VPMIDicElement
{
  CATDeclareInterface;

public:
  /**
  * Get the list of Simple attributes contributing to the UniqueKey
  * @param oSimples
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetUKAttributes ( CATLISTV_VPMIDicSimple_var& oDicSimples ) const = 0;

  
  /**
  * Indicates if the key includes the composer of the object
  * @return
  *    <ul>
  *    <li>TRUE this unique key includes the composer of the object.</li>
  *    <li>TRUE this unique key does not include the composer of the object.</li>
  *    </ul>
  */
  virtual CATBoolean IsIncludingComposer () const =0;
 
};

CATDeclareHandler( VPMIDicUniqueKey, VPMIDicElement );

#endif
