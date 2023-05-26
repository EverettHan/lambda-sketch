/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2009
//=============================================================================

#ifndef _CATOmbIgrComponentRelationValidity_H
#define _CATOmbIgrComponentRelationValidity_H

/**
* @level Protected
* @usage U1
*/

#include "CATObjectModelerBase.h"
#include "CATBoolean.h"
#include "IUnknown.h"
#include "CATCollec.h"

class CATOmbRelationSnapshotSpecificationIterator;
class CATError;
class CATOmbRelationSnapshotSpecification;
class CATComponentId;
class CATOmbIgrIntegrityGroup;
class CATListPtrCATIPLMComponent;
class CATProxySpace;
class CATListPtrCATIAdpPLMIdentificator;

class ExportedByCATObjectModelerBase CATOmbIgrComponentRelationValidity
{
public:
  /**
  * Test if the relation snapshots specified for a given PLM component are compliant with the component's integrity rules.
  * <br><b>Role</b>: Check if the integrity of a component is verified from a set of specifications over its relations,
  * and inform an error engine of the errors that were detected during the check.
  * @param ipRelationSpecificationIterator [in]
  *  The relation specifications to check (share the same pointing component).
  * @param opError [out, CATBaseUnknown#release]
  *   If integrity rules aren't verified <code>S_OK</code>, a detailed report.
  * @return
  * <code>S_OK</code> The component is valid with the provided relation specifications.
  * <code>S_FALSE</code> No internal integrity rules are broken by the provided relation specifications, but there are other impacted relations
  * which was not specified, and inter-dependant integrity rules.
  * <code>E_FAIL</code> The provided relation specifications break the given component integrity.
  * <code>E_INVALIDARG</code> provided arguments are not consistent.
  */
  static HRESULT IsComponentValid(CATOmbRelationSnapshotSpecificationIterator & ipRelationSpecificationIterator,
                                  CATError *& opError) ;


private:
  static HRESULT IsInGroup(CATListPV & iMap, 
    CATOmbRelationSnapshotSpecification * iSpecification, 
    CATBoolean & oResult, 
    CATOmbIgrIntegrityGroup *& oGroup);


  static HRESULT TreatErrors(const HRESULT & iRC, 
    CATOmbRelationSnapshotSpecification * iSpecification, 
    CATListPV & ioMap);

  static void DestroyMap(CATListPV iMap);


  static unsigned int _RelationGroupId;


};

#endif
