// COPYRIGHT Dassault Systemes 2007


#ifndef CATOmbRelationSnapshotIterator_H
#define CATOmbRelationSnapshotIterator_H

/**
* @level Protected
* @usage U1
*/
#include "CATObjectModelerBase.h"
#include "CATOmbRelationSnapshot.h"
#include "CATUnicodeString.h"


/**
* Iterator on @href CATOmbRelationSnapshot.
* <br><b>Role</b>: Allow to browse a set of relation snapshot (representing 
* a model state at a given time).
* <p> This iterator is created by browse services provided by @href CATOmbRelationalBrowseServices.
* A filter (@href CATOmbRelationsFilter) could be associated to the retrived iterator.
* @see CATOmbRelationalBrowseServices, CATOmbRelationSnapshot, CATOmbRelationsFilter
*/
class ExportedByCATObjectModelerBase CATOmbRelationSnapshotIterator
{
public : 

     /** 
     * Get a pointer on the next @href CATOmbRelationSnapshot.
     * <br><b>Role</b>: If a filter had been associated, this method skip 
     * dismatching @hrefCATOmbRelationSnapshot.
     * @return IUnknown#Release
     *   A pointer on @href CATOmbRelationSnapshot.
     *   <code>NULL</code> if no more object to browse.
     */
     virtual CATOmbRelationSnapshot * operator ++ () = 0 ;

     /**
     * Destructor
     */
     virtual ~CATOmbRelationSnapshotIterator () {} ;
} ;

#endif
