#ifndef CATOmbLinkPrivateServicesForFBDI_H_
#define CATOmbLinkPrivateServicesForFBDI_H_


/**
 * @level Private
 * @usage U1
 * COPYRIGHT DASSAULT SYSTEMES	2006
 */

 // BSFBuildtimeData
#include "CATIAV5Level.h"
// System
#include "CATUnicodeString.h"
// SystemTS
#include "CATBoolean.h"
#include "IUnknown.h"
// ObjectModelerCollection
#include "CATOmxArray.h"
#include "CATOmxDefaultCollecManager.h"
#include "sequence_octet.h"
// CATPLMIdentificationAccess
#include "CATPLMID.h"
// ObjectModelerBase
#include "CATObjectModelerBase.h"


class CATILinkableObject;
class CATIPLMComponent;
class CATDocument;
class CATUnicodeString;
class CATOmxKeyValueBlock;


#if defined (private) || defined(friend) || defined (protected)

#error Forbidden re-define of 'private', 'friend' or 'protected'
// Fatal error on solaris
@error

#endif

#define AuthorizedModule     999

#define CATOmbLinks					         AuthorizedModule
#define CATOmbMigrationAccess        AuthorizedModule
#define CATOmbTBSample				AuthorizedModule
#define CATOmbLinkTrader				AuthorizedModule
#define CATOmbTst_PurgeFalseImpacts				AuthorizedModule
#define CATPLMFstModelBaseServices   				AuthorizedModule // R2012x only, Fastener Ref pubs false impacts handling
#define CATFbdModeler   				AuthorizedModule
#define CAT3DXMLStreamEngine    AuthorizedModule // pour générer le flux xml liens dans 3dxmlv6
#define CATDWCProdDoc    				AuthorizedModule
#define CoexMappingServices   				AuthorizedModule
#define CATPrdPccRelationsPort            AuthorizedModule
#define CkeTestLib                AuthorizedModule
#define CATOmbLinkAccessTestLib   AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule
#else

#error Forbidden access to link services from a non-infrastructure module
// Fatal error on solaris
@error

#endif

#undef  CATOmbLinks
#undef  CATOmbMigrationAccess
#undef	CATOmbTBSample
#undef CATOmbLinkTrader
#undef CATOmbTst_PurgeFalseImpacts
#undef CATFbdModeler
#undef CATPLMFstModelBaseServices
#undef CAT3DXMLStreamEngine
#undef CATDWCProdDoc
#undef CoexMappingServices
#undef AuthorizedModule
#undef CATPrdPccRelationsPort

/**
* Singleton class giving access to link protected services exclusively for FBDI.
*/
class ExportedByCATObjectModelerBase CATOmbLinkPrivateServicesForFBDI
{
public:

  /**
  * Retrieves a new name from a given sequence.
  * @param iOld
  *   old sequence.
  * @param iPLMId
  *   new plmid.
  * @params oNew
  *   new sequence.
  * @return
  * <dl>
  * <dt> E_FAIL if there is no such object.
  * <dt> S_OK otherwise.
  * </dl>
  */
  static HRESULT GetNewName(const SEQUENCE(octet) & iOld, const  CATPLMID & iPLMId, SEQUENCE(octet) & oNew);

  /**
  * Retrieves a new name from a given sequence
  * @param iOld
  *   old sequence
  * @param iUUID
  *   new UUID
  * @param iPLMId
  *   new plmid
  * @param oNew
  *  new sequence
  * @return
  * <dl>
  * <dt> E_FAIL if there is no such object
  * <dt> S_OK otherwise
  * </dl>
  */
  static HRESULT GetNewName(const SEQUENCE(octet) & iOld, const SEQUENCE(octet) * iUUID, const CATPLMID & iPLMId, SEQUENCE(octet) & oNew);

  /**
  * Retrieves a new object from a given sequence.
  * @param iOld
  *   old sequence.
  * @param iPLMId
  *   new plmid.
  * @params opNewObj
  *   new object.
  * @return
  * <dl>
  * <dt> E_FAIL if there is no such object.
  * <dt> S_OK otherwise.
  * </dl>
  */
  static HRESULT GetPhase2ObjectInSession(const SEQUENCE(octet) & iOld, const CATPLMID & iPLMId, CATILinkableObject *& opNewObj);

  /**
  * Retrieves a link sequence from a given absolute and relatrive sequence sequence.
  * @param iAbs
  *   absolute sequence.
  * @param iRela
  *   relative sequence.
  * @params oSeq
  *   new sequence.
  * @return
  * <dl>
  * <dt> E_FAIL if there is problem.
  * <dt> S_OK otherwise.
  * </dl>
  */
  static HRESULT GetNewSequenceFromAbsoluteAndRelativeName(const SEQUENCE(octet) & iAbs, const SEQUENCE(octet) & iRela, SEQUENCE(octet) & oSeq);

  /**
  * Temporary function to inform the soft link of the FBDI context.
  * @param iIsInFBDI
  *   Status of the FBDI replay.
  * <dl>
  * <dt> TRUE in FBDI context.
  * <dt> FALSE otherwise.
  * </dl>
  */
  static void SetIsInFBDI(const CATBoolean & iIsInFBDI);

  static CATBoolean GetIsInFBDI();

  /**
  * Purge false impacts on a given component.
  * @param iComponent
  *   The given component.
  * @return
  * <dl>
  * <dt> S_OK if some false impacts were successfully removed.
  * <dt> S_FALSE if there is no false impact.
  * <dt> otherwise, associated error code.
  * </dl>
  */
  static HRESULT PurgeFalseImpacts(CATIPLMComponent & iComponent);

private:
  CATOmbLinkPrivateServicesForFBDI() = delete;
  ~CATOmbLinkPrivateServicesForFBDI() = delete;

  static CATBoolean s_isInFBDI;
};

#endif




