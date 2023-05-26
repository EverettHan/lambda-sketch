/**
 * @level Protected
 * @usage U1
 */
#ifndef CATAdpDWSMappingTableQueryDefinition_H
#define CATAdpDWSMappingTableQueryDefinition_H

#include "CATPLMIntegrationAccess.h"
#include "CATAdpDWSMappingTableSelect.h"
#include "CATAdpDWSMappingTableConstraint.h"

/**
 * Class representing the definition of a query on a DWS Mapping Table.
 * This class must be allocated in the stack.
 * <br><b>Usage:</b>
 * <code>
 *    // retrieve all entities in WorkspaceId
 *    CATAdpDWSMappingTableSelect a(WorkspaceId);
 *    CATAdpDWSMappingTableConstraint b;
 *    CATAdpDWSMappingTableQueryDefinition q(a, b);
 * </code>
 * </code>
 */
class ExportedByCATPLMIntegrationAccess CATAdpDWSMappingTableQueryDefinition
{
  friend class CATAdpProtectedDWSMappingTableQuery;
public:

  /**
   * Constructor.
   * <br><b>Role</b>: Creates the query definition with the provided arguments.
   * @param iSelect [in]
   *   The select definition specifying the set of objects to retrieve.
   * @param iConstraint [in]
   *   The constraint definition specifying filter criteria.
   */
  CATAdpDWSMappingTableQueryDefinition(const CATAdpDWSMappingTableSelect & iSelect,
                                       const CATAdpDWSMappingTableConstraint & iConstraint);


  /**
   * Copy constructor.
   */
  CATAdpDWSMappingTableQueryDefinition(const CATAdpDWSMappingTableQueryDefinition &iCopy);
  /**
   * Destructor.
   */
  ~CATAdpDWSMappingTableQueryDefinition();
  /**
   * Assignment operator.
   */
  CATAdpDWSMappingTableQueryDefinition& operator=(const CATAdpDWSMappingTableQueryDefinition &iCopy);

private:

  CATAdpDWSMappingTableSelect _Select;
  CATAdpDWSMappingTableConstraint _Constraint;

  /* forbidden operations */
  CATAdpDWSMappingTableQueryDefinition();
  int operator==(const CATAdpDWSMappingTableQueryDefinition & iOther) const;
  int operator!=(const CATAdpDWSMappingTableQueryDefinition & iCopy) const;
  void *operator new(size_t);
#ifdef _WINDOWS_SOURCE
  void operator delete(void *);
#endif
  void *operator new[](size_t);
  void operator delete[](void *);

};

#endif
