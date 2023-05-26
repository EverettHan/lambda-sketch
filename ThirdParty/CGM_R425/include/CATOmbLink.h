#ifndef CATOmbLink_h
#define CATOmbLink_h 4 /* Version number. */

/**
 * @level Private
 * @usage U1
 * COPYRIGHT DASSAULT SYSTEMES 2005
 */

 // SpecialAPI
#include "CATDataType.h"
// System
#include "CATBaseUnknown.h"
// ObjectModelerCollection
#include "CATOmxKeyValueBlock.h"
#include "CATOmxOHMap.h"
#include "sequence_octet.h"
// CATPLMIdentificationAccess
#include "CATListPtrCATIPLMComponent.h"
#include "CATPLMTypeH.h"
// ObjectModelerBase
#include "CATObjectModelerBase.h"
#include "CATOmbCuteUniversalLink.h"
#include "CATOmbFilterOnInverseLink.h"
#include "CATOmbGenericLinkInterface.h"
#include "CATOmbTimeStamp.h"

class CATOmbLinkSource;
class CATILinkableObject;
class CATBaseUnknown;
class CATIBindParameters;
class CATOmbLinkInterface;
class CATIDocId;
class CATComponentId;
class CATIOmbUniversalLink;
class CATPLMID;
class CATOmbLinkPositionTransaction;
class CATOmbUniversalLinkResult;
class CATDocument;
class PLMIOmbVirtualObjectDescriptor_var;
class CATIOmbFunction;
class CATIOmbProxySpecifications;
class CATStreamDefinition;
class CATOmxKeyValueBlock;
class CATIOmbProxySpecifications;
class CATPLMTypeH;
class CATOmbRelationMetaData;

#define CATOmbLinkChangePolicy_AVAILABLE

typedef unsigned int CATOmbLinkChangePolicy;
#define CATOmbLink_DEFAULT            0
#define CATOmbLink_NO_DIRTY           0x0001
#define CATOmbLink_NO_UNDO            0x0002


/**
 * Class that allows to use OMB link.
 * <b>Role</b>: A CATOmbLink is a session
 * link which can be solved, unload and streamed.
 */
class ExportedByCATObjectModelerBase CATOmbLink : public CATOmbGenericLinkInterface
{

public:

  // Link global state 
  enum LifeCycleState { Valid, Garbaged };

  // resolution du liens
  virtual HRESULT Bind(CATILinkableObject *& oObj, CATIBindParameters * B = NULL) = 0;

  // resolution du liens
  virtual HRESULT Bind(CATIBindParameters * B = NULL) = 0;


  // resolution du liens
  virtual HRESULT IsSolved(CATBoolean & Bound) = 0;

  //Get the TicketId
  virtual CATULONG32 GetId() const = 0;

  //objet pointe si present en memoire
  virtual HRESULT GetTarget(CATILinkableObject *& oObj) const = 0;
  virtual HRESULT GetTarget(CATBaseUnknown *& oObj) const = 0;

  /*
   * Get the final target of the link, regardless of the state of intermediate objects
   */
  virtual HRESULT GetFinalTarget(CATBaseUnknown *& oObj) const = 0;

  //rend le nom du pointe / GetExternalName
  virtual HRESULT GetTargetName(SEQUENCE(octet) &) const = 0;

  //rend le docid du pointe
  virtual HRESULT GetPointedDocId(CATIDocId *& oDiD) = 0;

  // does the link need to use the old (SpecsModeler-based) RetrieveAll mechanism ? (usually no; yes for catalogs and file-based links, e.g. FBDI)
  virtual CATBoolean NeedsOldRetrieveAll() = 0;

  // gestion de unload 
  virtual HRESULT Untie() = 0;

  // Dans la cas des liens inst/ref exposes (cas detail/ditto), le time stamp du composant pointe est pris comme reference.
  virtual HRESULT Synchronize(CATOmbLinkChangePolicy iPolicy = CATOmbLink_DEFAULT) = 0;

  // gestion des TS
  virtual HRESULT IsSynchronized(SynchroState & oSyncro)const = 0;

  // gestion des TS
  virtual HRESULT SetTimeStamp(CATOmbTimeStamp) = 0;

  // gestion des TS
  virtual CATOmbTimeStamp GetTimeStamp() const = 0;

  //lien intra et extra document -> S_OK intra, S_FALSE ->Extra, E_FAIL soucis
  virtual HRESULT IsIntraDoc() const = 0;

  //lien inter et intra composant -> S_OK inter composant, S_FALSE ->intra composant, E_FAIL soucis
  virtual HRESULT IsInterComponent() const = 0;

  //A Appeler lors du dechargement de l'objet pointant (contexte de close session du pointant): NB le lien est detruit en sortie de ce call
  virtual void SessionRelease() = 0;

  //A Appeler lors de la destruction logique non undoable de l'object pointant: NB le lien est detruit en sortie de ce call
  // Voir diagramme d'etat plus bas
  virtual HRESULT Remove() = 0;

  //A Appeler lors de la destruction logique undoable de l'object pointant.
  // Voir diagramme d'etat plus bas
  virtual HRESULT Garbage() = 0;

  //A Appeler lors de l'undo de destruction de l'object pointant.
  // Voir diagramme d'etat plus bas
  virtual HRESULT Restore() = 0;

  //A Appeler lors de l'unmarshalling warmstart.
  // Sans commentaire.....
  virtual HRESULT ForceGarbaged() = 0;

  //retourne l'etat de l'objet
  virtual LifeCycleState GetLifeCycleState() const = 0;

  // useful for copy/paste transformation
  HRESULT CloneLink(CATOmbLinkSource & iSource, CATOmbRelationMetaData & iRelationMetaData, CATBoolean iCopyAsGarbaged = FALSE) const;

  //New Factory using Cute links
  static HRESULT CreateLink(CATIOmbUniversalLink & iTarget, CATOmbLinkSource & iSource, CATOmbRelationMetaData & iRelationMetaData);

  // Factories de creation
  // creation avec objet resolu  (SetExternalObject)
  static HRESULT CreateLink(CATILinkableObject * iTarget, CATOmbLinkSource & iSource, CATOmbRelationMetaData & iRelationMetaData);

  // creation avec nom (SetExternalObjectName)
  static HRESULT CreateLink(const SEQUENCE(octet) & iTarget, CATOmbLinkSource & iSource, CATOmbRelationMetaData & iRelationMetaData);

  // Unstream donnee phase 1 -> migration
  static HRESULT CreateLink(int Index, const SEQUENCE(octet) & LigthName, CATOmbLinkSource & iSource, CATOmbRelationMetaData & iRelationMetaData);

  // Unstream donnee phase 2
  static HRESULT GetLink(CATULONG32 iLinkId, CATOmbLinkSource & iSource, CATOmbRelationMetaData & iRelationMetaData);

  //Get the CATOmbLink from its id for LinkBLock (PC2 light mode)
  static CATOmbLink * GetLinkWithoutSource(CATULONG32 iLinkId, CATDocument & iDoc);

  // Stream de donnee phase 2 vers le format phase 1 -> CATBack
  static HRESULT GetOldLinkInfo(CATOmbLink & iLink, int & Index, SEQUENCE(octet) & LigthName);

  // Services de Reroute
  static HRESULT ChangeTarget(CATOmbLink & oLink, CATOmbRelationMetaData & iRelationMetaData, const SEQUENCE(octet) & iTarget);

  // Services de Reroute
  static HRESULT ChangeTarget(CATOmbLink & oLink, CATOmbRelationMetaData & iRelationMetaData, CATIOmbUniversalLink & iTarget);

  // Services de Reroute
  static HRESULT ChangeTarget(CATOmbLink & oLink, CATOmbRelationMetaData & iRelationMetaData, CATILinkableObject * iTarget);


  // Gives the activation state of the activation of OMB ticket persistency
  static CATBoolean IsTicketPersistencySupported();

  /** @nodoc */
  virtual CATOmbLinkInterface & GetOmbImplObject() = 0;

  /**
  * Retrieves the pointed component of the link resolved dynamically in session.
  * The retrieved component can be the one the link was built from, or an equivalent minor in session.
  *
  * @param oCID
  *   The pointed component of the relation.
  * @return S_OK    : And no pointed component if link is not a PLM one (Not associated to a relation)
  *         S_OK    : And a pointed component if the CID is corresponding to build target
  *         S_FALSE : And a pointed component if the CID is dynamically solved in session with equivalent minors
  *         E_FAIL  : otherwise
  */
  virtual HRESULT GetDynamicPointedComponentResolvedInSession(CATComponentId & oCID) const = 0;

  /** @nodoc */
  virtual const CATComponentId & GetPointedComponentOnBuild() const = 0;


  /** @nodoc */
  virtual HRESULT  GetTargetComponent(CATLISTP(CATIPLMComponent) &) const = 0;


  // Checks if link is exclusively referencing components without entering into (Works with direct & complex pointers)
  virtual CATBoolean IsExclusivelyReferencingComponentsWithoutPenetration() const = 0;

  // Access the ULR (even if it is behind a VO)
  virtual HRESULT GetUniversalLinkResult(CATOmbUniversalLinkResult *& opUniversalLinkResult) = 0;

  // Is a contextual link ?
  virtual CATBoolean IsContextualConsumerLink() const = 0;


  //rend Stream du lien inter session
  virtual HRESULT GetCompleteStream(CATStreamDefinition &) const = 0;

  // Replace deprecated GetIndexLightName & co. Internal use for CATBack, FBDI etc ...
  virtual HRESULT GetRawPersistency(const CATOmxKeyValueBlock & iVersion, SEQUENCE(octet) & oLightName, int & oIndex) const;

  // Access the pointed VODescriptor
  HRESULT GetVODescriptor(PLMIOmbVirtualObjectDescriptor_var & ospVODescriptor, CATBoolean iFold = TRUE, CATIOmbProxySpecifications * ipProxySpecs = NULL, CATIOmbFunction * ipFunction = NULL, bool iGeomReroute = false);

  // Returns S_FALSE if synchro is not based on attributes
  virtual HRESULT GetAttributesUsedForSynchro(CATOmxArray<CATOmbCuteUniversalLink_Attribute> & oAttributeList) const;

  // return new Persistency
  virtual HRESULT GetPersistency(CATOmxKeyValueBlock & oStreamBlock) const = 0;

  //tells if SR attributes are supported:
  //  pure relational (no stream, no private part, 1 link == 1 SR)
  //  neutral (implementative restriction)
  //
  virtual bool AreSRAttributesSupported() const;
  //caution: zero behavior,  undo-redo and dirty are not managed, all the work must be performed by caller
  virtual CATOmxOHMap<CATPLMTypeH, CATOmxKeyValueBlock> RawGetSRAttributes() const;
  virtual HRESULT RawSetSRAttributes(const CATOmxOHMap<CATPLMTypeH, CATOmxKeyValueBlock> & iAttributes);

  /**returns associated semantic relation AppIndex attribute value (or 0)*/
  int GetRelationAppIndex() const;

  /** return the source of the link */
  virtual CATOmbLinkSource * GetSource() const = 0;
  CATOmbLinkSource & RequireSource() const;
};
#endif
