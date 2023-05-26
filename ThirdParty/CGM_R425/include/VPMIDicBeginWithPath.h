//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2008
//=============================================================================
/**
 * @level Private
 * @usage U3
 */
#ifndef _VPMIDicBeginWithPath_h
#define _VPMIDicBeginWithPath_h

#include "VPMIDicInterfaces.h"

#include "CATString.h"
#include "CATBaseUnknown.h"
#include "VPMIDicPathOfInstancesConstraint.h"


#ifndef LOCAL_DEFINITION_FOR_IID
extern  ExportedByVPMIDicInterfaces const IID IID_VPMIDicBeginWithPath;
#else
extern "C" const IID IID_VPMIDicBeginWithPath;
#endif

/**
 * Interface to manage the VPMIDicBeginWithPath.
 */

class  ExportedByVPMIDicInterfaces VPMIDicBeginWithPath: public VPMIDicPathOfInstancesConstraint
{
    CATDeclareInterface;

    public:

        /**
        * Get the RelationDefinition property of the current BeginWihPath.
        * @param oRelationDefinition : the RelationDefinition string
        * @return
        *    <ul>
        *    <li>S_OK     Operation succeeded, a RelationDefinition was found.</li>
        *    <li>E_FAIL   Operation failed, or no RelationDefinition was found.</li>
        *    </ul>
        */
        virtual HRESULT GetRelationDefinition ( CATString & oRelationDefinition ) const = 0;

        /**
        * This method simply calls the VPMIDicPathOfInstancesConstraint::GetAuthorizedTypeExpr, in order to provide a more suitable naming ("Remaining...") compared to what it is supposed to be used for.
        * @param oAuthorizedTypeExpr : the AuthorizedTypeExpr string
        * @return
        *    <ul>
        *    <li>S_OK     Operation succeeded, an AuthorizedTypeExpr was found.</li>
        *    <li>E_FAIL   Operation failed, or no AuthorizedTypeExpr was found.</li>
        *    </ul>
        */
        virtual HRESULT GetRemainingAuthorizedTypeExpr ( CATString & oAuthorizedTypeExpr ) const = 0;

};
#endif
