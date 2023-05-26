#ifndef __CATIPLMTransferToNewProjectError_H
#define __CATIPLMTransferToNewProjectError_H

#include "CATComponentId.h"
#include "CATInputError.h"
#include "ExportedByCATPLMTos.h"

/**
 * see corresponding NLS messages in CATPLMTransferToNewProject.CATNls
 */
enum CATIPLMTransferToNewProjectErrorCode
{
  TTNP_Dirty,
  TTNP_Light,
  TTNP_NoProject,
  TTNP_CurrentProject,
  TTNP_MutipleProjects,
  TTNP_Parent,
  TTNP_Child,
  TTNP_ParentAlreadyCloned,
  TTNP_ChildLost,
  TTNP_PointingOutsideScope,
  TTNP_QueryMapping,
  TTNP_QueryMappingDup,
  TTNP_QueryAttributes,
  TTNP_Open,
  TTNP_NothingToDo,
  TTNP_CannotStartTask,
  TTNP_ServerFork,
  TTNP_MissingForkRecord,
  TTNP_MissingForkImpactRecord,
  TTNP_MissedImpact,
  TTNP_ConcurrentModification,
  TTNP_SessionPreview,
  TTNP_Internal1,
  TTNP_Internal2,
  TTNP_Unspecified
};

/**
 * Errors/warnings related to CATIPLMTransferToNewProject
 */
class ExportedByCATPLMTos CATIPLMTransferToNewProjectError : public CATInputError
{
  CATDeclareClass;
private:
  const CATIPLMTransferToNewProjectErrorCode m_errorCode;
  const CATComponentId m_component;
public:
  CATIPLMTransferToNewProjectError(const char* iNLSKey, CATIPLMTransferToNewProjectErrorCode iErrorCode, const CATComponentId& iComponent);

  /**
   * Retrieve associated component.
   * Warning, can be NULL or a not loaded object
   */
  inline CATComponentId GetAssociatedObject() const { return m_component; }

  /**
   * Retrieve associated error code.
   */
  inline CATIPLMTransferToNewProjectErrorCode GetErrorCode() const { return m_errorCode; }

  ~CATIPLMTransferToNewProjectError();
private:
  CATIPLMTransferToNewProjectError(const CATIPLMTransferToNewProjectError&);
  CATIPLMTransferToNewProjectError& operator=(const CATIPLMTransferToNewProjectError&);
};


#endif
