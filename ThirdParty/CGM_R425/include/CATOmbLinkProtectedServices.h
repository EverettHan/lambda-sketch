#ifndef CATOmbLinkProtectedServices_H_
#define CATOmbLinkProtectedServices_H_


// COPYRIGHT DASSAULT SYSTEMES	2004


/**
 * @level Private
 * @usage U1
 */


#if defined (private) || defined(friend) || defined (protected)

#error Forbidden re-define of 'private', 'friend' or 'protected'
 // Fatal error on solaris
@error

#endif


#define AuthorizedModule     999

// List of authorized infrastructure modules 

#define CATOmbLinkAccess													AuthorizedModule
#define CATOmbLinkApplicativeAccess								AuthorizedModule
#define CATOsmLink																AuthorizedModule
#define CATOmbLinks																AuthorizedModule
#define CATMmrBrepMAccess                         AuthorizedModule
#define CATOmbLinkTrader													AuthorizedModule

#define CATOmbTstLinkAccess_EditLinks							AuthorizedModule
#define CATOmbTstLinkAccess_PhysicalRerouteOnRep	AuthorizedModule
#define CATOmbTstLinkAccess_PhysicalRerouteOnRepWithListener	AuthorizedModule
#define CATOmbTstLinkAccess_PhysicalRerouteOnVO		AuthorizedModule
#define CATOmbTstLinkAccess_PhysicalRerouteOnVOWithListener     AuthorizedModule
#define OmbTST_PLMShared													AuthorizedModule
#define CATOmbTBSample														AuthorizedModule
#define CATOmbTBSamplePLMTrader12									AuthorizedModule
#define AC0XXLNK                                  AuthorizedModule
#define CATPrdRelationsPLO                        AuthorizedModule
#define CATImmNavLinks                            AuthorizedModule
#define CATOmbLnkVO                               AuthorizedModule
#define CATOmbDebugLink														AuthorizedModule
#define CATMmlBRepMode                            AuthorizedModule
#define CATPrdPccRelationsPLO						AuthorizedModule
#define CATPLMClientCoreModel						AuthorizedModule
#define CATOmbUFO                       AuthorizedModule
#define CATOmbTransientServices                     AuthorizedModule
#define AC0SPDOC AuthorizedModule
#define AC0SPBAS AuthorizedModule
#define CheckRepBatch                   AuthorizedModule
#define CATOmbLinkAccessTestLib         AuthorizedModule


#if _MK_MODNAME_ == AuthorizedModule

#else

#error Forbidden access to link services from a non-infrastructure module
  // Fatal error on solaris
  @error

#endif

#undef CATOmbLinkAccess           
#undef CATOmbLinkApplicativeAccess                  
#undef CATOsmLink      
#undef CATOmbLinks
#undef CATMmrBrepMAccess
#undef CATOmbLinkTrader

#undef CATOmbTstLinkAccess_EditLinks                
#undef CATOmbTstLinkAccess_PhysicalRerouteOnRep                
#undef CATOmbTstLinkAccess_PhysicalRerouteOnRepWithListener
#undef CATOmbTstLinkAccess_PhysicalRerouteOnVO
#undef CATOmbTstLinkAccess_PhysicalRerouteOnVOWithListener
#undef OmbTST_PLMShared                
#undef CATOmbTBSample                
#undef CATOmbTBSamplePLMTrader12 
#undef AC0XXLNK
#undef CATPrdRelationsPLO
#undef CATImmNavLinks
#undef CATOmbLnkVO
#undef CATOmbDebugLink
#undef CATMmlBRepMode
#undef CATPrdPccRelationsPLO
#undef CATPLMClientCoreModel
#undef CATOmbTransientServices
#undef AC0SPDOC
#undef AC0SPBAS
#undef CheckRepBatch

#ifndef CheckRepModeFromOMB
#define CheckRepModeFromOMB
#endif


#include "CATObjectModelerBase.h"
#include "IUnknown.h" // for HRESULT
#include "sequence_octet.h"
#include "CATCollec.h"
  class CATLISTV(CATComponentId);
class CATProxySpace;

#include "CATLISTV_CATBaseUnknown.h"
#include "CATBoolean.h"
#include "CATOmbDocServices.h"

class CATBaseUnknown;
class CATComponentId;
class CATDocument;
class CATLinkName;
class CATIBindParameters;
class CATOmbRelationMetaData;
class CATSysSimpleHashTable;
class CATILinkableObject;
#include "CATOmxSet.h"
class CATOmbLink;
#include "CATOmxKernel.h"
class CATSymbolProperty;

/**
 * Singleton class giving access to link protected services.
 */
class ExportedByCATObjectModelerBase CATOmbLinkProtectedServices
{
public:

  /**
   * Retrieves an object inserted in the session link cache.
   * @param iContainer
   *   containers which is the naming context of the seeked object.
   * @param iRelativeName
   *   relative identifier of the seeked object.
   * @params oObject
   *   addrefed object if found.
   * @return
   * <dl>
   * <dt> E_FAIL if there is no such object.
   * <dt> S_OK otherwise.
   * </dl>
   */
  static HRESULT GetObjectInLinkCache(CATBaseUnknown * iContainer, SEQUENCE(octet) const & iRelativeName, CATBaseUnknown *& oObject);


  /**
   * Loads an representation document (the main SD) in full mode.
   * @return
   *  An HRESULT value:
   *  <dl>
   *   <dt>E_FAIL</dt>
   *    <dd>The representation can't be globally loaded.</dd>
   *   <dt>S_FALSE</dt>
   *    <dd>The representation is already globally loaded.</dd>
   *   <dt>S_OK</dt>
   *    <dd>The representation has been globally loaded successfully.</dd>
   *  </dl>
   */
  static HRESULT LoadGlobally(CATBaseUnknown * iRepRef);

  /**
   * Checks whether an object is inside a main SD.
   * @param iObject
   *  The object.
   * @param oIsInMainSD
   *  The boolean result.
   * @return
   *  An HRESULT value:
   *  <dl>
   *   <dt>E_INVALIDARG</dt>
   *    <dd>The object is null or does not have any associated document.</dd>
   *   <dt>CATOmb_E_NO_REPREF</dt>
   *    <dd>The document of the object has no associated stream descriptor nor associated RepRef.</dd>
   *   <dt>S_OK</dt>
   *    <dd>The check has been done successfully.</dd>
   *  </dl>
   */
  static HRESULT IsInMainSD(CATILinkableObject * iObject, CATBoolean & oIsInMainSD);

  // services for CheckRepBatch to enable the CheckRepMode in OMB
  static void SetCheckRepMode(CATBoolean iMode);
  static CATBoolean IsCheckRepMode();

  /** @nodoc */
  CATOmbLinkProtectedServices();

  /** @nodoc */
  ~CATOmbLinkProtectedServices();

  enum RetrieveAllScope { external, ancestor };
  static void OldRetrieveAllTargets(RetrieveAllScope iScope);
};

#endif




