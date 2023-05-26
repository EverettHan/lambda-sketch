//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2008
//=============================================================================
/**
 * @level Private
 * @usage U3
 */
#ifndef _VPMIDicSemanticRelation_h
#define _VPMIDicSemanticRelation_h

#include "VPMIDicInterfaces.h"

#include "CATString.h"
#include "CATBaseUnknown.h"
#include "VPMIDicElement.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern  ExportedByVPMIDicInterfaces const IID IID_VPMIDicSemanticRelation;
#else
extern "C" const IID IID_VPMIDicSemanticRelation;
#endif

class VPMIDicSRContextConstraint;
class VPMIDicSRPatternConstraint;

/**
 * Interface to manage the VPMIDicSemanticRelation.
 */

class  ExportedByVPMIDicInterfaces VPMIDicSemanticRelation: public VPMIDicElement
{
    CATDeclareInterface;

    public:

        /**
        * Get the AllowedTargetPath property of the current SemanticRelation.
        * The AllowedTargetPath is a string expression, which syntax is one of the following:
        *    <ul>
        *    <li>Simple
        *    <li>Path, i.e. no constraint on the size of the path
        *    <li>Path[nb], i.e. the size of the path must be equal to the intege value "nb"
        *    <li>Path[nb1 op size op nb2], i.e. the size of the path can be within a range, where "size" is a keyword corresponding to the size of the path, nb1 and nb2 are respectively the minimum and the maximum values of the range, and "op" can be "=<" or "<"
        *    </ul>
        * @param oAllowedTargetPath : the AllowedTargetPath string
        * @return
        *    <ul>
        *    <li>S_OK     Operation succeeded, and length of oAllowedTargetPath is greater than 0.</li>
        *    <li>S_FALSE  Operation succeeded, but length of oAllowedTargetPath is equal to 0.</li>
        *    <li>E_FAIL   Operation failed.</li>
        *    </ul>
        */
        virtual HRESULT GetAllowedTargetPath ( CATString & oAllowedTargetPath ) = 0;

        /**
        * Get the (first) ContextConstraint element of the current SemanticRelation, if any.
        * NB: this method should not exist any more now that more than one ContextConstraint can be defined for a SemanticRelation.
        * Any way, for compatibility reason, it still exists with the implicit behavior that it will recover the first ContextConstraint of the list.
        * @param oDicSRContextConstraint : the ContextConstraint [out, CATBaseUnknown#Release]
        * @return
        *    <ul>
        *    <li>S_OK     A ContextContraint was found.</li>
        *    <li>S_FALSE  No ContextContraint was found.</li>
        *    <li>E_FAIL   Operation failed.</li>
        *    </ul>
        */
        virtual HRESULT GetContextConstraint ( VPMIDicSRContextConstraint ** oDicSRContextConstraint ) = 0;

        /**
        * Get the ContextConstraint element of the current SemanticRelation according to its Name.
        * @param iName : the ContextConstraint's Name
        * @param oDicSRContextConstraint : the ContextConstraint [out, CATBaseUnknown#Release]
        * @return
        *    <ul>
        *    <li>S_OK     A ContextContraint was found for the given Name.</li>
        *    <li>S_FALSE  No ContextContraint was found for the given Name.</li>
        *    <li>E_FAIL   Operation failed.</li>
        *    </ul>
        */
        virtual HRESULT GetContextConstraint ( const CATString & iName, VPMIDicSRContextConstraint ** oDicSRContextConstraint ) = 0;

        /**
        * Get the PatternConstraint element of the current SemanticRelation according to its Name.
        * @param iName : the PatternConstraint's Name
        * @param oDicSRPatternConstraint : the PatternConstraint [out, CATBaseUnknown#Release]
        * @return
        *    <ul>
        *    <li>S_OK     A PatternConstraint was found for the given Name.</li>
        *    <li>S_FALSE  No PatternConstraint was found for the given Name.</li>
        *    <li>E_FAIL   Operation failed.</li>
        *    </ul>
        */
        virtual HRESULT GetPatternConstraint ( const CATString & iName, VPMIDicSRPatternConstraint ** oDicSRPatternConstraint ) = 0;

        /**
        * Retrieve the list of ContextConstraint elements of the current SubRelationship.
        * @param oContextConstraintList : list of ContextConstraint elements
        * @return
        *    <ul>
        *    <li>S_OK     Operation succeeded, the list is not empty.</li>
        *    <li>S_FALSE  Operation succeeded, but the list is empty.</li>
        *    <li>E_FAIL   Operation failed.</li>
        *    </ul>
        */
        virtual HRESULT GetContextConstraintList ( CATLISTP(IUnknown) * oContextConstraintList ) = 0;

        /**
        * Retrieve the list of PatternConstraint elements of the current SemanticRelation.
        * @param oPatternConstraintList : list of PatternConstraint elements
        * @return
        *    <ul>
        *    <li>S_OK     Operation succeeded, the list is not empty.</li>
        *    <li>S_FALSE  Operation succeeded, but the list is empty.</li>
        *    <li>E_FAIL   Operation failed.</li>
        *    </ul>
        */
        virtual HRESULT GetPatternConstraintList ( CATLISTP(IUnknown) * oPatternConstraintList ) = 0;

        /**
        * Check whether the current SemanticRelation is sensitive to minor ... (to be completed)
        * @return
        *    <ul>
        *    <li>TRUE   The SemanticRelation is sensitive.</li>
        *    <li>FALSE  The SemanticRelation is not sensitive.</li>
        *    </ul>
        */
        virtual boolean IsMinorSensitive ( ) const = 0;
};

CATDeclareHandler( VPMIDicSemanticRelation, VPMIDicElement );

#endif
