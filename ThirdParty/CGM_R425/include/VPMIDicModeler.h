//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2008
//=============================================================================
/**
 * @level Private
 * @usage U3
 */
#ifndef VPMIDicModeler_h
#define VPMIDicModeler_h

#include "VPMIDicInterfaces.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByVPMIDicInterfaces const IID IID_VPMIDicModeler;
#else
extern "C" const IID IID_VPMIDicModeler;
#endif

class CATUnicodeString;

class ExportedByVPMIDicInterfaces VPMIDicModeler : public CATBaseUnknown
{
    CATDeclareInterface;

public:

    /**
    * Retrieves the name of the Modeler's root Package.
    * @param oRootPackageName : Name of the root Package
    * @return
    *    <ul>
    *    <li>S_OK     Operation succeeded.</li>
    *    <li>E_FAIL   Operation failed.</li>
    *    </ul>
    */
    virtual HRESULT GetRootPackageName( CATUnicodeString& oPackage ) const = 0;
};

#endif /*VPMIDicModeler_h*/
