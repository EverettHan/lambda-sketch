#ifndef CATPLMContextualSemanticRelationMigrationServices_H
#define CATPLMContextualSemanticRelationMigrationServices_H

// COPYRIGHT DASSAULT SYSTEMES 2008
/**
* @level Private
* @usage U1
*/
// -----------------------------------------------------------------------------------------------------------
#define AuthorizedModule                       999
#define CATPLMIdentifier                       AuthorizedModule
#define CATOxiContextualSRMigration            AuthorizedModule
#define CATPLMREDataAccessor                   AuthorizedModule
#define CATOxiPLMLinksOnAttributes              AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule
#else
#error Forbidden access to CATPLMID_STREAM_BINARY from a non-infrastructure module
@error 
#endif

#undef AuthorizedModule
#undef CATPLMIdentifier
#undef CATOxiContextualSRMigration
#undef CATPLMREDataAccessor
#undef CATOxiPLMLinksOnAttributes

#include "CATPLMIdentificationAccess.h"
#include "IUnknown.h"
#include "CATUnicodeString.h"

class CATListPtrCATPLMSemanticRelation;

class ExportedByCATPLMIdentificationAccess CATPLMContextualSemanticRelationMigrationServices
{
public:
  /**
  * Migrates Semantic Relations by putting context relations and their input in a unique CATPLMSemanticRelation object.
  * @param iRelationList
  *        The list of relations to migrate.
  * @param oMigratedRelationList 
  *        The list of migrated relations. The life cycle has just to be managed for iRelationList entities.
  *        For a PCS issue, the entities return by oMigratedRelationList are the same than those of iRelationList, 
  *        except that the context relations are excluded and input relations are altered.
  * @return
  *   S_OK if everything went right
  *   E_INVALIDARG if the input lists holds invalid objects (null pointer, etc.)
  *   E_FAIL if an error occured
  */
  static HRESULT MigrateContextualSemanticRelations(CATListPtrCATPLMSemanticRelation & iRelationList, 
                                                    CATListPtrCATPLMSemanticRelation & oMigratedRelationList);

};

#endif
