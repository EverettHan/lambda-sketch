//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2008
//=============================================================================
/**
 * @level Private
 * @usage U3
 */
#ifndef _VPMIDicSRPatternConstraint_h
#define _VPMIDicSRPatternConstraint_h

#include "VPMIDicInterfaces.h"

#include "CATString.h"
#include "CATBaseUnknown.h"
#include "VPMIDicElement.h"


#ifndef LOCAL_DEFINITION_FOR_IID
extern  ExportedByVPMIDicInterfaces const IID IID_VPMIDicSRPatternConstraint;
#else
extern "C" const IID IID_VPMIDicSRPatternConstraint;
#endif

class VPMIDicPathOfInstances;


/**
 * Interface to manage the VPMIDicSRPatternConstraint.
 */

class  ExportedByVPMIDicInterfaces VPMIDicSRPatternConstraint: public VPMIDicElement
{
    CATDeclareInterface;

    public:

        /**
        * Get the Name property of the current PatternConstraint.
        * @param oName : the Name string
        * @return
        *    <ul>
        *    <li>S_OK     Operation succeeded, an Name was found.</li>
        *    <li>E_FAIL   Operation failed, or no Name was found.</li>
        *    </ul>
        */
//        virtual HRESULT GetName ( CATString & oName ) = 0;

        /**
        * Get the IdCode property of the current PatternConstraint.
        * @param oIdCode : the IdCode string
        * @return
        *    <ul>
        *    <li>S_OK     Operation succeeded, an IdCode was found.</li>
        *    <li>E_FAIL   Operation failed, or no IdCode was found.</li>
        *    </ul>
        */
        virtual HRESULT GetIdCode ( CATString & oIdCode ) const = 0;

        /**
        * Get the ValidityCheck property of the current PatternConstraint.
        * The ValidityCheck is a string expression, which defines a rule that will be evaluated at runtime to get a boolean result, in order to know if the pattern is accessible or not.
        * @param oValidityCheck : the ValidityCheck string
        * @return
        *    <ul>
        *    <li>S_OK     Operation succeeded, a ValidityCheck was found.</li>
        *    <li>E_FAIL   Operation failed, or no ValidityCheck was found.</li>
        *    </ul>
        */
        virtual HRESULT GetValidityCheck ( CATString & oValidityCheck ) const = 0;

        /**
        * Get the LastAuthorizedTypeExpr property of the current PatternConstraint.
        * The LastAuthorizedTypeExpr is a string expression, which defines constraints for the last pointed component.
        * @param oLastAuthorizedTypeExpr : the LastAuthorizedTypeExpr string
        * @return
        *    <ul>
        *    <li>S_OK     Operation succeeded, a LastAuthorizedTypeExpr was found.</li>
        *    <li>E_FAIL   Operation failed, or no LastAuthorizedTypeExpr was found.</li>
        *    </ul>
        */
        virtual HRESULT GetLastAuthorizedTypeExpr ( CATString & oLastAuthorizedTypeExpr ) const = 0;

        /**
        * Retrieve the list of PathOfInstances elements of the current PatternConstraint.
        * @param oPathOfInstancesList : list of oPathOfInstancesList elements
        * @return
        *    <ul>
        *    <li>S_OK     Operation succeeded, the list is not empty.</li>
        *    <li>S_FALSE  Operation succeeded, but the list is empty.</li>
        *    <li>E_FAIL   Operation failed.</li>
        *    </ul>
        */
        // virtual HRESULT GetPathOfInstancesList ( CATLISTP(IUnknown) * oPathOfInstancesList ) = 0;

        /**
        * Get the PathOfInstances element of the current PatternConstraint, if any.
        * @param oDicPathOfInstances : the PathOfInstances [out, CATBaseUnknown#Release]
        * @return
        *    <ul>
        *    <li>S_OK     Operation succeeded, a PathOfInstances was found.</li>
        *    <li>E_FAIL   Operation failed, or no PathOfInstances was found.</li>
        *    </ul>
        */
        virtual HRESULT GetPathOfInstances ( VPMIDicPathOfInstances ** oDicPathOfInstances ) const = 0;
};

CATDeclareHandler( VPMIDicSRPatternConstraint, VPMIDicElement );

#endif
