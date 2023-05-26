/**
 * @level Protected
 * @usage U1
 */
#ifndef CATAdpDWSMappingTableEntity_H
#define CATAdpDWSMappingTableEntity_H

#include "CATPLMIntegrationAccess.h"
#include "CATPLMCEStamp.h"

class CATIAdpPLMIdentificator;
class CATIAdpPLMIdentificator_var;
class CATPLMID;
/**
 * Class representing an entity of a DWS Mapping Table.
 */
class ExportedByCATPLMIntegrationAccess CATAdpDWSMappingTableEntity
{
  friend class CATAdpDWSMappingTableResult;
  friend class CATDWSMappingTableSynchroRecordParser;

public:

  CATAdpDWSMappingTableEntity();
  ~CATAdpDWSMappingTableEntity();
  CATAdpDWSMappingTableEntity & operator =( const CATAdpDWSMappingTableEntity & );

  /**
   * Definition of the possible values of status for a component into a Designer Workspace.
   * <tt> Possible status:</tt>
   * <dl>
   * @param <tt>CATPLMWorkspaceUndefined</tt> <dd>No status is defined for the object.
   * @param <tt>CATPLMWorkspaceNew</tt>       <dd>Object must be logged as created in Designer Workspace.
   * @param <tt>CATPLMWorkspaceModified</tt>  <dd>Object must be logged as modified in Designer Workspace.
   * @param <tt>CATPLMWorkspaceDeleted</tt>   <dd>Object must be logged as deleted in Designer Workspace.
   * </dl>
   */
  enum CATPLMWorkspaceStatus
  {
    CATPLMWorkspaceStatusUndefined = 0,
    CATPLMWorkspaceStatusNew = 1,
    CATPLMWorkspaceStatusModified = 2,
    CATPLMWorkspaceStatusDeleted = 3
  };
  /**
   * Definition of the possible values of synchronization status for a component into a Designer Workspace.
   * <tt> Possible status:</tt>
   * <dl>
   * @param <tt>CATPLMWorkspaceSynchroUnknown</tt>  <dd>Synchro status is unknown for the object.
   * @param <tt>CATPLMWorkspaceSynchronized</tt>    <dd>Object is synchronized.
   * @param <tt>CATPLMWorkspaceNotSynchronized</tt> <dd>Object is not synchronized.
   * </dl>
   */
  enum CATPLMWorkspaceSynchroStatus
  {
    CATPLMWorkspaceSynchroUnknown = 0,
    CATPLMWorkspaceSynchronized = 1,
    CATPLMWorkspaceNotSynchronized = 2
  };
  /**
   * Definition of the possible values of reservation status for a component into a Designer Workspace.
   * <tt> Possible status:</tt>
   * <dl>
   * @param <tt>CATPLMWorkspaceReservationUnknown</tt>  <dd>Reservation status is unknown for the object.
   * @param <tt>CATPLMWorkspaceReserved</tt>    <dd>Object is reserved by the workspace.
   * @param <tt>CATPLMWorkspaceNotReserved</tt> <dd>Object is not reserved by the workspace.
   * </dl>
   */
  enum CATPLMWorkspaceReservationStatus
  {
    CATPLMWorkspaceReservationUnknown = 0,
    CATPLMWorkspaceReserved = 1,
    CATPLMWorkspaceNotReserved = 2
  };

  /**
   * Gets the identifier of the component in the workspace.
   */
  HRESULT Component(CATIAdpPLMIdentificator_var & oComponent);
  /**
   * Gets the identifier of the projected component in the parent workspace.
   */
  HRESULT ParentComponent(CATIAdpPLMIdentificator_var & oParentComponent);
  /**
   * Gets the identifier of the workspace.
   */
  HRESULT WorkspaceId(CATIAdpPLMIdentificator_var & oWorkspaceId);
  /**
   * Gets the identifier of the parent workspace.
   */
  HRESULT ParentWorkspaceId(CATIAdpPLMIdentificator_var & oParentWorkspaceId);
  /**
   * Gets the status of the component.
   */
  HRESULT Status(CATPLMWorkspaceStatus & oStatus);
  /**
   * Tells if the component is synchronized with its reference.
   * @param oSynchronized [out]
   *   Synchronized, NotSynchronized, or Unknown.
   */
  HRESULT Synchronized(CATPLMWorkspaceSynchroStatus & oSynchronized);
  /**
   * Tells if the component is locally reserved (LOCAL) by the workspace.
   * @param oReservedLocal [out] Reserved, NotReserved, Unknown.
   */
  HRESULT ReservedLocal(CATPLMWorkspaceReservationStatus & oReservedLocal);
  /**
   * Tells if the component is globally reserved (PARENT) by the workspace.
   * @param oReservedParent [out] Reserved, NotReserved, Unknown.
   */
  HRESULT ReservedParent(CATPLMWorkspaceReservationStatus & oReservedParent);

private:

  CATAdpDWSMappingTableEntity(CATPLMID & iComponentId,
                              CATPLMID & iParentComponentId,
                              CATPLMID & iWorkspaceId,
                              CATPLMID & iParentWorkspaceId,
                              CATPLMWorkspaceStatus iStatus,
                              CATPLMWorkspaceReservationStatus iReservedLocal,
                              CATPLMWorkspaceReservationStatus iReservedParent,
                              CATPLMCEStamp & iCEStamp);

  CATIAdpPLMIdentificator * _ComponentId;
  CATIAdpPLMIdentificator * _ParentComponentId;
  CATIAdpPLMIdentificator * _WorkspaceId;
  CATIAdpPLMIdentificator * _ParentWorkspaceId;
  CATPLMWorkspaceStatus _Status;
  CATPLMWorkspaceSynchroStatus _SynchroStatus;
  CATPLMWorkspaceReservationStatus _reservedLocal;
  CATPLMWorkspaceReservationStatus _reservedParent;
  CATPLMCEStamp _CEStamp;

  /* forbidden operations */
  CATAdpDWSMappingTableEntity( const CATAdpDWSMappingTableEntity & );

};

#endif
