/**
 * @level Protected
 * @usage U1
 */
#ifndef CATAdpDWSMappingTableSelect_H
#define CATAdpDWSMappingTableSelect_H

#include "CATPLMIntegrationAccess.h"
#include "CATListPtrCATIAdpPLMIdentificator.h"
#include "IUnknown.h"

class CATIAdpPLMIdentificator;

/**
 * Class representing the select specification for a query to run on a DWS Mapping Table.
 * It is dedicated to be used by the <code>CATAdpDWSMappingTableQueryDefinition</code> class.
 * It can be used to restrict the returned mapping table entries to those corresponding to
 * components whose id are provided, or to components whose id of the components projected
 * in the parent workspace are provided.
 * The options are exclusive.
 */
class ExportedByCATPLMIntegrationAccess CATAdpDWSMappingTableSelect
{
  friend class CATAdpProtectedDWSMappingTableQuery;

public:

  /**
   * Constructor.
   * <br><b>Role</b>: Creates the select definition without restricting criteria.
   * @param iWorkspace [in]
   *   The identifier of the workspace concerned. It can be null if the workspace is the reference.
   */
  CATAdpDWSMappingTableSelect(CATIAdpPLMIdentificator * iWorkspace);

  /**
   * Select only entities for components whose identifiers are provided.
   * @param iComponents [in]
   *   The list of identificators of the components in the workspace.
   * @return
   *   <ul>
   *   <li><code>S_OK</code> if everything ran ok.</li>
   *   <li><code>E_UNEXPECTED</code> if ComponentsInWorkspace() or ComponentsInParentWorkspace() was previously called.</li>
   *  </ul>
   */
  HRESULT ComponentsInWorkspace(const CATLISTP(CATIAdpPLMIdentificator) & iComponents);

  /**
   * Select only entities for components whose projections in the parent
   * workspace are identified by iComponents.
   * @param iComponents [in]
   *   The list of identificators of the projected components in parent workspace.
   * @return
   *   <ul>
   *   <li><code>S_OK</code> if everything ran ok.</li>
   *   <li><code>E_UNEXPECTED</code> if ComponentsInWorkspace() or ComponentsInParentWorkspace() was previously called.</li>
   *  </ul>
   */
  HRESULT ComponentsInParentWorkspace(const CATLISTP(CATIAdpPLMIdentificator) & iComponents);


  /**
   * Copy constructor.
   */
  CATAdpDWSMappingTableSelect(const CATAdpDWSMappingTableSelect &iCopy);
  /**
   * Destructor.
   */
  ~CATAdpDWSMappingTableSelect();
  /**
   * Assignment operator.
   */
  CATAdpDWSMappingTableSelect& operator=(const CATAdpDWSMappingTableSelect &iCopy);

private:

  CATIAdpPLMIdentificator * _Workspace;
  CATLISTP(CATIAdpPLMIdentificator) _Components;
  bool _Parent;

  /* forbidden operations */
  CATAdpDWSMappingTableSelect();
  int operator==(const CATAdpDWSMappingTableSelect & iOther) const;
  int operator!=(const CATAdpDWSMappingTableSelect & iCopy) const;
  void *operator new(size_t);
#ifdef _WINDOWS_SOURCE
  void operator delete(void *);
#endif
  void *operator new[](size_t);
  void operator delete[](void *);

};

#endif
