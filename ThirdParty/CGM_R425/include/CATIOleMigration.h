/**
 * @level Private
 * @usage U1
 */


 // List of forbidden re-define

#if defined (private) || defined(friend) || defined (protected)
#error Forbidden re-define of 'private', 'friend' or 'protected'
  // Fatal error on solaris
@error
#endif


// List of authorized infrastructure modules 

#define AuthorizedModule                           999
#define AC0WINLNK                                  AuthorizedModule
#define AC0SPBAS                                   AuthorizedModule
#define CATOmbMigrationAccess                      AuthorizedModule
#define CATOmbLinkAccessTestLib                    AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule
#else
#error Forbidden Access To CATIOleMigration
  // Fatal error on solaris
  @error
#endif

#undef AuthorizedModule
#undef AC0WINLNK     
#undef AC0SPBAS 
#undef CATOmbMigrationAccess 
#undef CATOmbLinkAccessTestLib


#ifndef CATIOleMigration_H
#define CATIOleMigration_H

#include "CATBaseUnknown.h"
#include "AC0WINLNK.h"

  extern ExportedByAC0WINLNK IID IID_CATIOleMigration;

/*
 * For FBDI use only.
 */
class ExportedByAC0WINLNK CATIOleMigration : public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /*
   * Migration of a CATOleSite object to embedded format in CATIA V6.
   * <b>Role</b>:<br>
   * Offer to migrate V5 OleSite to V6 embedded OleSite.
   * WARNING : even V5 linked OleSite will be converted to embedded format.
   * @return
   *   S_OK if migration works.
   *   S_FALSE if the OleSite is V6 ready (no need to be migrated). It has just been initialized.
   *   E_INVALIDARG if the current object has no CATOleSite attributes - the migration was not done.
   *   E_FAIL if the migration unrecoverably failed.
   * 
   *   Other returned error code show the migration was done BUT with a degraded behavior.
   *   In this case, the CATOleSite contains data of the whole file and not a sub-selection of it.
   *   For exemple with an Excel file, if data originally contains a couple of cells, 
   *   all cells of the first sheet will then be shown with the degraded migration. 
   *   Known return code are:
   *      MK_E_CANTOPENFILE if the target file could not be attached to the OLE data,
   *      REGDB_E_CLASSNOTREG if OLE data could not recompute the type of the target file,
   *      REGDB_E_KEYMISSING if OLE data could recompute the type BUT is not registered in the Registry - it is an environnement issue
   */
  virtual HRESULT MigrateToEmbedded() = 0;

};


#endif

