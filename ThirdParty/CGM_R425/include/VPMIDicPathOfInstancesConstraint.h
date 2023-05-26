//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2008
//=============================================================================
/**
 * @level Private
 * @usage U3
 */
#ifndef _VPMIDicPathOfInstancesConstraint_h
#define _VPMIDicPathOfInstancesConstraint_h

#include "VPMIDicInterfaces.h"

#include "CATString.h"
#include "CATBaseUnknown.h"
#include "VPMIDicElement.h"


#ifndef LOCAL_DEFINITION_FOR_IID
extern  ExportedByVPMIDicInterfaces const IID IID_VPMIDicPathOfInstancesConstraint;
#else
extern "C" const IID IID_VPMIDicPathOfInstancesConstraint;
#endif

/**
 * Interface to manage the VPMIDicPathOfInstancesConstraint.
 */

class  ExportedByVPMIDicInterfaces VPMIDicPathOfInstancesConstraint: public VPMIDicElement
{
    CATDeclareInterface;

    public:

        /**
        * Get the AuthorizedTypeExpr property of the current PathOfInstancesConstraint.
        * The LastAuthorizedTypeExpr is a string expression, which defines constraints for the pointed component(s).
        * Depending on whether it is used by a AllInstancesPath sub-element, a InstancePath sub-element or a BeginWithPath sub-element, it may points to one or several component(s).
        * @param oAuthorizedTypeExpr : the AuthorizedTypeExpr string
        * @return
        *    <ul>
        *    <li>S_OK     AuthorizedTypeExpr was found.</li>
        *    <li>S_FALSE  No AuthorizedTypeExpr was found.</li>
        *    <li>E_FAIL   Operation failed.</li>
        *    </ul>
        */
        virtual HRESULT GetAuthorizedTypeExpr ( CATString & oAuthorizedTypeExpr ) const = 0;
};
#endif
