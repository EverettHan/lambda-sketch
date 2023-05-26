/**
 * @level Protected
 * @usage U1
 */
#ifndef CATAdpDWSMappingTableConstraint_H
#define CATAdpDWSMappingTableConstraint_H

#include "CATPLMIntegrationAccess.h"

/**
 * Class representing the constraint specification for a query to run on a DWS Mapping Table.
 * It is dedicated to be used by the <code>CATAdpDWSMappingTableQueryDefinition</code> class.
 * This class must be allocated in the stack.
 * <br><b>Usage:</b>
 * <code>
 *    // retrieve entities whose projection in parent id are in IdList:
 *    CATAdpDWSMappingTableSelect a(WorkspaceId);
 *    a.ComponentsInParentWorkspace(IdList);
 *    // retrieve all entities created, not in design:
 *    CATAdpDWSMappingTableConstraint b;
 *    b.Created();
 *    b.NotInDesign();
 *    CATAdpDWSMappingTableQueryDefinition q(a, b);
 * </code>
 */
class ExportedByCATPLMIntegrationAccess CATAdpDWSMappingTableConstraint
{
  friend class CATAdpProtectedDWSMappingTableQuery;

public:

  /**
   * Constructor.
   * Creates a constraint definition with no constraint at all.
   */
  CATAdpDWSMappingTableConstraint();

  /**
   * Get modified entities.
   */
  void Modified();
  /**
   * Get created entities.
   */
  void Created();
  /**
   * Get deleted entities.
   */
  void Deleted();
  /**
   * Get entities with no status defined.
   */
  void NoStatus();

  /**
   * Ask for synchronization status to be computed
   */
  void ComputeSynchro();


  /**
   * Copy constructor.
   */
  CATAdpDWSMappingTableConstraint(const CATAdpDWSMappingTableConstraint &iCopy);
  /**
   * Destructor.
   */
  ~CATAdpDWSMappingTableConstraint();
  /**
   * Assignment operator.
   */
  CATAdpDWSMappingTableConstraint& operator=(const CATAdpDWSMappingTableConstraint &iCopy);

private:

  bool _StatusModified;
  bool _StatusCreated;
  bool _StatusDeleted;
  bool _StatusEmpty;
  bool _StatusUndefined;
  bool _SynchroUndefined;

  /* forbidden operations */
  int operator==(const CATAdpDWSMappingTableConstraint & iOther) const;
  int operator!=(const CATAdpDWSMappingTableConstraint & iCopy) const;
#ifdef _WINDOWS_SOURCE
  void *operator new(size_t);
  void operator delete(void *);
  void *operator new[](size_t);
  void operator delete[](void *);
#endif

};

#endif
