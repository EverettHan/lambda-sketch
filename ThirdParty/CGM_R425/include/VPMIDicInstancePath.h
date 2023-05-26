//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2008
//=============================================================================
/**
 * @level Private
 * @usage U3
 */
#ifndef _VPMIDicInstancePath_h
#define _VPMIDicInstancePath_h

#include "VPMIDicInterfaces.h"

#include "CATString.h"
#include "CATBaseUnknown.h"
#include "VPMIDicPathOfInstancesConstraint.h"


#ifndef LOCAL_DEFINITION_FOR_IID
extern  ExportedByVPMIDicInterfaces const IID IID_VPMIDicInstancePath;
#else
extern "C" const IID IID_VPMIDicInstancePath;
#endif

/**
 * Interface to manage the VPMIDicInstancePath.
 */

class  ExportedByVPMIDicInterfaces VPMIDicInstancePath: public VPMIDicPathOfInstancesConstraint
{
    CATDeclareInterface;

    public:

        /**
        * Get the PositionInPath property of the current InstancePath element.
        * @param oPositionInPath the position in the path
        * @return
        *    <ul>
        *    <li>S_OK     Operation succeeded.</li>
        *    <li>E_FAIL   Operation failed, or no PositionInPath was defined.</li>
        *    </ul>
        */
        virtual HRESULT GetPositionInPath ( int & oPositionInPath ) const = 0;
};
#endif
