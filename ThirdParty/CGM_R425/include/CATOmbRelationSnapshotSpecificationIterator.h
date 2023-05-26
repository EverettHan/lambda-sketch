// COPYRIGHT Dassault Systemes 2008


#ifndef CATOmbRelationSnapshotSpecificationIterator_H
#define CATOmbRelationSnapshotSpecificationIterator_H

/**
* @level Protected
* @usage U1
*/
#include "CATObjectModelerBase.h"
#include "IUnknown.h"
#include "CATListPtrCATIPLMComponent.h"

class CATIPLMComponent ; 
class CATOmbRelationSnapshotSpecification ;

class ExportedByCATObjectModelerBase CATOmbRelationSnapshotSpecificationIterator
{
public : 


    /** 
     * Get the owner component.
     * @param opiOwner [out, CATBaseUnknown#Release]
     *   The PLM owned component retrived as a pointer (AddRef is done).
     * @return
     *   <code>S_OK</code> if everything ran ok, otherwise associated failure code.
     */
    virtual HRESULT GetOwner (CATIPLMComponent *& opiOwner) = 0 ;

    /** 
     * Get a pointer on the next @href CATOmbRelationSnapshotSpecification.
     * <br><b>Role</b>: If a filter had been associated, this method skip 
     * dismatching @CATOmbRelationSnapshotSpecification.
     * @return IUnknown#Release
     *   A pointer on @href CATOmbRelationSnapshotSpecification.
     *   DO NOT DELETE.
     *   <code>NULL</code> if no more object to browse.
     */
    virtual CATOmbRelationSnapshotSpecification * operator ++ () = 0 ;

    /*
     * Get specified context components (contextual component, with contextual relations).
     * MUST IUnknown#Release each element of oSpecifiedContextComponent.
     * @return
     *   <code>S_OK</code> if everything ran ok.
     *   <code>S_FALSE</code> if no context component is specified.
     *   Otherwise associated failure code.. 
     */
    virtual HRESULT GetSpecifiedContextComponent (CATLISTP (CATIPLMComponent) & oSpecifiedContextComponent) = 0 ;


    /*
     * Set specified context components.
     */
    virtual void SetSpecifiedContextComponent (CATLISTP (CATIPLMComponent) & iSpecifiedContextComponent) = 0 ;

    /**
     * Reset iterator browse
     */
    virtual void Reset () = 0 ;

    /**
     * Destructor
     */
    virtual ~CATOmbRelationSnapshotSpecificationIterator () {} ;
} ;

#endif
