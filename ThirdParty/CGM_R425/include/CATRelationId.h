#ifndef _CATRelationId_H
#define _CATRelationId_H
// ----------------------------------------------------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2010
/**
* @level Private
* @usage U1
*/
// ----------------------------------------------------------------------------------------------------------------------

#include "ExportedByCATPLMTos.h"

// SpecialAPI
#include "CATDataType.h"
// System
#include "CATBaseUnknown.h"
// SystemTS
#include "CATBoolean.h"
// CATPLMIdentificationAccess
#include "CATPLMRelationInformation.h"
#include "CATSemanticRelationMetaData.h"

class CATOxRelation;
class CATComponentId;
class CATUnicodeString;

/**
* Access to PLM relations
*/
class ExportedByCATPLMTos CATRelationId
{
public:
  CATRelationId(CATOxRelation & iRelation);
  ~CATRelationId();

  /**
  * SemanticRelation.IDrel attribute
  */
  CATULONG32 GetId() const;

  /**
   * PathType.pathid attribute (WIP)
   */
  class CATPLMPathId GetPathId() const;

  /**
  * see CATOxRelation::IsMinorSensitive
  */
  bool IsMinorSensitive() const;

  /**
  * Retrieves the pointed component of the relation
  * as it was originally built from.
  * @return oPointedComponent
  *   The pointed component of the relation.
  */
  const CATComponentId & GetPointedComponentOnBuild() const;

  /**
  * Retrieves the pointed component of the relation according to Minor sensitivity.
  *  - Minor unsensitive : Dynamic resolution on equivalent minor version
  *  - Minor sensitive   : Static resolution
  *
  * @param oCID
  *   The pointed component of the relation.
  *
  * @return S_OK    : If the returned components are the components on build
  *         S_FALSE : If the returned components are dynamically resolved
  *         E_FAIL  : Otherwise
  */
  HRESULT GetDynamicPointedComponentResolvedInSession(CATComponentId & oCID) const;

  /**
  * Retrieves the pointing component of the relation.
  * @return oPointingComponent
  *   The pointing component of the relation.
  */
  CATComponentId GetPointingComponent() const;

  /**
  * Retrieves the role of the relation.
  * @param iNLSFormat
  *   To retrieve the role in NLS format.
  * @return
  *   The role of the relation.
  */
  const CATUnicodeString & GetRole(CATBoolean iNLSFormat = FALSE) const;

  /**
  * Retrieves the category of the relation.
  * @return
  *   The category of the relation.
  */
  const CATUnicodeString & GetCategory() const;

  /**
  * Returns the role and the category of the relation
  */
  HRESULT GetRoleAndCategory(CATUnicodeString & oRole, CATUnicodeString & oCategory) const;

  /**
  * Returns the NLS role of the relation
  */
  const CATUnicodeString & GetNLSRole() const;

  /**
  * Returns the CATSemanticRelationMetaData of the relation
  */
  const CATSemanticRelationMetaData & GetSemanticRelationMetaData() const;

  /**
  * Retrieves the status of the relation.
  * oStatus
  *      The resolution status.
  * oSynchroStatus
  *      The synchro status.
  * @return
  *    S_OK    if request succeeded
  *    E_FAIL  if request failed
  */
  HRESULT GetSessionStatus(CATPLMRelationSolveStatus & oStatus, CATPLMRelationSynchroStatus & oSynchroStatus) const;

  /**
  * Returns the snapshot of the remote status at import time (Open, Refresh).
  * This information is never updated by PLM Session.
  *
  * oStatus
  *      The remote status.
  * @return
  *    S_OK    if request succeeded
  *    E_FAIL  if request failed
  */
  HRESULT GetRemoteStatus(CATPLMRelationRemoteStatus & oStatus) const;

  /**
  * Get internal object for private usage
  */
  CATOxRelation & GetImpl() const { return _Relation; }

private:

  // Forbidden operators 
  CATRelationId(CATRelationId&);
  CATRelationId& operator=(CATRelationId&);
  void * operator new(size_t, CATRelationId&);

  CATOxRelation & _Relation;
};

#endif
