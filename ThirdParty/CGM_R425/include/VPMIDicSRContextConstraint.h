//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2008
//=============================================================================
/**
 * @level Private
 * @usage U3
 */
#ifndef _VPMIDicSRContextConstraint_h
#define _VPMIDicSRContextConstraint_h

#include "VPMIDicInterfaces.h"

#include "CATString.h"
#include "CATBaseUnknown.h"
#include "VPMIDicElement.h"


#ifndef LOCAL_DEFINITION_FOR_IID
extern  ExportedByVPMIDicInterfaces const IID IID_VPMIDicSRContextConstraint;
#else
extern "C" const IID IID_VPMIDicSRContextConstraint;
#endif

/**
 * Interface to manage the VPMIDicSRContextConstraint.
 */

class  ExportedByVPMIDicInterfaces VPMIDicSRContextConstraint: public VPMIDicElement
{
    CATDeclareInterface;

    public:

        /**
        * Test whether the current ContextConstraint is defined as "Explicit".
        * @return
        *    <ul>
        *    <li>true     the ContextConstraint is "Explicit".</li>
        *    <li>false    the ContextConstraint is "Implicit" or "UserDefined".</li>
        *    </ul>
        */
        virtual boolean IsExplicit ( ) = 0;
        virtual HRESULT IsExplicit ( boolean & oIsExplicit ) = 0;


        /**
        * Test whether the current ContextConstraint is defined as "Implicit"
        * @return
        *    <ul>
        *    <li>true     the ContextConstraint is "Implicit".</li>
        *    <li>false    the ContextConstraint is "Explicit" or "UserDefined".</li>
        *    </ul>
        */
        virtual boolean IsImplicit ( ) = 0;


        /**
        * Test whether the current ContextConstraint is defined as "UserDefined"
        * @return
        *    <ul>
        *    <li>true     the ContextConstraint is "UserDefined".</li>
        *    <li>false    the ContextConstraint is "Explicit" or "Implicit".</li>
        *    </ul>
        */
        virtual boolean IsUserDefined ( ) = 0;


        /**
        * Get the ContextDefinition property of the current ContextConstraint.
        * The ContextDefinition is a string expression, which defines the path from the relationship owner to the pointed object.
        * Note that the ContextDefinition is relevant only if the current ContextConstraint is explicit, i.e. if VPMIDicSRContextConstraint::isExplicit()==true
        * @param oContextDefinition : the ContextDefinition string
        * @return
        *    <ul>
        *    <li>S_OK     Operation succeeded, and length of oContextDefinition is greater than 0.</li>
        *    <li>S_FALSE  Operation succeeded, but length of oContextDefinition is equal to 0.</li>
        *    <li>E_FAIL   Operation failed, or irrelevant call of the method (i.e. this->isEsxplicit==false).</li>
        *    </ul>
        */
        virtual HRESULT GetContextDefinition ( CATString & oContextDefinition ) = 0;


        /**
        * Get the ValidityCheck property of the current ContextConstraint.
        * The ValidityCheck is a string expression, which defines a rule that will be evaluated at runtime to get a boolean result, in order to know if the context is accessible or not.
        * @param oValidityCheck : the ValidityCheck string
        * @return
        *    <ul>
        *    <li>S_OK     Operation succeeded, a ValidityCheck was found.</li>
        *    <li>E_FAIL   Operation failed, or no ValidityCheck was found.</li>
        *    </ul>
        */
        virtual HRESULT GetValidityCheck ( CATString & oValidityCheck ) const = 0;


};
#endif
