#ifndef CATPLMTypeId_H
#define CATPLMTypeId_H

/**
 * @level Private
 * @usage U1
 */
#include "CATPLMIdentificationAccess.h"
#include "CATBaseUnknown.h"
#include "CATBoolean.h"
#include "CATString.h"
#include "CATListOfCATString.h"
#include "IUnknown.h"
#include "CATPLMIdentificationAccessMacros.h"
#include "CATPLMCoreType.h"
#include "CATPLMCoreTypeFilter.h"
#include "CATPLMTypeIdClassificationEnum.h"

class CATPLMTypeIdInfo;
class CATPLMTypeId;
class CATIAdpType;
class CATIAdpExtType;
class CATOmxKeyString;

#ifdef _CAT_ANSI_STREAMS
/** @c++ansi tcx 2005-08-02.20:09:19 [Replace forward declaration of standard streams with osfwd.h] **/
#include "iosfwd.h" 
#else //!_CAT_ANSI_STREAMS 
class ostream;
#endif //_CAT_ANSI_STREAMS


/**
 * Symbolic handle on Type manipulated by PLM Integration
 * It could be considered as minimal keeping attribute
 *    to identify the CATPLMType of Meta-Data Service
 *
 *   DO NOT DERIVATE FROM THIS CLASS
 *   HOWEVER, THIS CLASS CAN BE AGGREGATED
 *
 */
class ExportedByCATPLMIdentificationAccess CATPLMTypeId
{
public:

  /**
   * @deprecated V6R213
   * @use CATPLMIdentificationAccess.CATPLMTypeH#GetAdpType
   */
  HRESULT GetAdpType(CATIAdpType *& oAdpType) const;

  /**
   * @deprecated V6R213
   * @use CATPLMIdentificationAccess.CATPLMTypeH#GetAdpExtType
   */
  HRESULT GetAdpExtType(CATIAdpExtType *& oAdpExtType) const;

  /**
   * @deprecated V6R213
   * @use CATPLMIdentificationAccess.CATPLMTypeDescriptor#IsKindOf
   * @use CATPLMIdentificationAccess.CATIAdpType#GetPLMCoreType
   */
  HRESULT GetPLMCoreType(CATPLMCoreType & oCoreType) const;

  /**
   * @deprecated V6R213
   * @use CATPLMIdentificationAccess.CATPLMTypeH#CATPLMTypeH
   */
  CATPLMTypeId(const char iCoreName[], const char iModelerType[], const char iCustomizationType[]);

  /**
   * @deprecated V6R213
   * @use CATPLMIdentificationAccess.CATPLMTypeDescriptor#GetTypeName
   * @use CATPLMIdentificationAccess.CATPLMTypeDescriptor#GetModelerName
   * @use CATPLMIdentificationAccess.CATPLMTypeDescriptor#IsKindOf
   */
  HRESULT GetNames(CATString & oCustomizationType, CATString & oModelerType, CATString & oCoreName) const;

  /**
   * @deprecated V6R213
   * @use CATPLMIdentificationAccess.CATPLMTypeDescriptor#IsKindOf
   */
  HRESULT GetCoreName(CATString & oCoreName) const;

  /**
   * @deprecated V6R213
   */
  int GetDefinitionDepth() const;

  /**
  * Check if repository type is valuated or unset.
  *
  * @return
  *      TRUE    if unset<br>
  *      FALSE   if valuated<br>
  */
  inline explicit operator bool() const { return _Index != 0; }

  /** deprecated, use operator == */
  HRESULT IsStrictyEqualTo(const CATPLMTypeId& iSecondTypeId) const;

  /**
  * comparison
  */
  inline bool operator == (const CATPLMTypeId & iToCompare) const { return _Index == iToCompare._Index; }
  inline bool operator != (const CATPLMTypeId & iToCompare) const { return !this->operator==(iToCompare); }

  /**
  * Destructor
  */
  inline ~CATPLMTypeId() { }

  /**
  * Build by copy a Object Integration Type
  *
  * @param iCopy
  *      Type of Copy<br>
  */
  inline CATPLMTypeId(const CATPLMTypeId& iCopy) :_Index(iCopy._Index) {}

  /**
  * Assign by a reference a Object Integration Type
  *
  * @param iCopy
  *      Type of CATPLMTypeId to Copy<br>
  */
  inline CATPLMTypeId& operator=(const CATPLMTypeId& iCopy) { _Index = iCopy._Index; return *this; }

  /**
  *  Empty Build
  */
  inline CATPLMTypeId() :_Index(0) {}


  /** meaningless */
  HRESULT DevelopmentStage(ostream &oToDump) const;


  /**
  * ComputeHashKey on PLM Type
  *
  * @param oKey
  *
  * @return
  *      S_OK   if request succeeded <br>
  *      E_FAIL if request failed <br>
  */
  unsigned int ComputeHashKey() const;
  inline HRESULT ComputeHashKey(unsigned int &oKey) const { oKey = ComputeHashKey(); return S_OK; }

  /**
   * @deprecated V6R213
   * @use CATPLMIdentificationAccess.CATPLMTypeH#CATPLMTypeH
   */
  CATPLMTypeId(const char iModelerType[], const char iCoreName[]);

  /**
   * @deprecated V6R213
   * @use CATPLMIdentificationAccess.CATPLMTypeH#CATPLMTypeH
   */
  CATPLMTypeId(const char iCoreName[]);

  /**
   * @deprecated V6R213
   * @use CATPLMIdentificationAccess.CATPLMTypeDescriptor#GetTypeName
   * @use CATPLMIdentificationAccess.CATPLMTypeDescriptor#IsKindOf
   */
  inline HRESULT GetName(CATString & oCoreName) const { return GetCoreName(oCoreName); }

  /**
   * @deprecated V6R213
   * @use CATPLMIdentificationAccess.CATPLMTypeDescriptor#GetTypeName
   * @use CATPLMIdentificationAccess.CATPLMTypeDescriptor#GetModelerName
   */
  HRESULT GetDomainName(CATString & oModelerType, CATString & oCoreName) const;

  /**
   * @deprecated V6R213
   * @use CATPLMIdentificationAccess.CATPLMTypeDescriptor#IsKindOf
   */
  HRESULT IsAKindOf(const CATPLMTypeId & iReferenceType) const;

  /**
   * @deprecated V6R213
   * @use CATPLMIdentificationAccess.CATPLMTypeDescriptor#IsKindOf
   */
  HRESULT HasSameCoreType(const CATPLMTypeId & iReferenceType) const;

  /**
   * @deprecated V6R213
   * @use CATPLMIdentificationAccess.CATPLMTypeDescriptor#IsKindOf
   */
  CATBoolean IsMatchingCoreTypes(CATPLMCoreTypeFilter iTypeFilter) const;

  /**
   * @deprecated V6R213
   * @use CATPLMIdentificationAccess.CATPLMTypeDescriptor#IsKindOf
   */
  HRESULT HasSameModeler(const CATPLMTypeId & iReferenceType) const;

  /**
  * Handle of Type  'by name'
  *
  * Constructor to be used with Meta-Data Services
  *
  * @param iMetaType
  *    The classification of the type.
  *
  * @param iTypeName
  *    The Type name.
  *
  */
  CATPLMTypeId(CATPLMTypeId_Classification iClassification, const char iTypeName[]);
  CATPLMTypeId(CATPLMTypeId_Classification iClassification, const CATUnicodeString& iTypeName);
  CATPLMTypeId(CATPLMTypeId_Classification iClassification, const CATOmxKeyString& iTypeName);

  /**
   * @deprecated
   * @use CATPLMTypeDescriptor#IsKindOf
   */
  HRESULT GetClassification(CATPLMTypeId_Classification &oClassification) const;

  /** @nodoc internal use */
  inline CATPLMTypeIdInfo* _Get() const { return _Index; }

  HRESULT InternalCoreInfo(CATOmxKeyString & oCoreInfo) const;

protected:

  friend class CATPLMID_Builder;
  friend class CATPLMID_Simple_Builder;
  friend class CATPLMID_Simple_PrivateBuilder;
  friend class ItgDumpMessages; // InternalTypeIdDump - for internal type id dump.
  friend class CATPLMTypeIdMessage; // InternalTypeIdDump - for internal type id dump.
  friend class CATPLMCompMetaDataService; // InternalTypeIdDump - for plm dico cache building.
  friend class CATOxStreamer; // InternalTypeIdDump - for TOS internal streaming (localSave).
  friend class CATPLMAttributeBlockAccessAdapter; // InternalTypeIdDump - for quick access to PLMExtension core type. Should disapear after re-architecturing the code (it needs to be).
  friend class PlmIDSimple; // InternalTypeIdDump - for internal type id dump.
  friend class CATPLMRecordReadAdapterImpl; // InternalTypeIdDump - for sectionname computing.
  friend class CATPLMTypeH;

  /** DO NOT USE. Does not work when triplette is suppressed. MUST BE REMOVED WHEN TRIPLETTE IS SUPPRESSED. */

  HRESULT IsConsistentForGenerate(CATBoolean & oIsConsistent) const;

  /** @nodoc  */
  HRESULT InternalTypeIdDump(CATString & oCustomizationType, CATString & oModelerType, CATString & oCoreName) const;

  /**  @nodoc  */
  class CATPLMTypeIdInfo  *_Index;
};

/**
 * @deprecated V6R213
 * @use CATPLMIdentificationAccess.CATPLMTypeH#CATPLMTypeH("PLMCoreReference")
 */
extern ExportedByCATPLMIdentificationAccess const char CATPLMTypeId_PLMCoreReference[];     // "PLMCoreReference"  

/**
 * @deprecated V6R213
 * @use CATPLMIdentificationAccess.CATPLMTypeH#CATPLMTypeH("PLMCoreRepReference")
 */
extern ExportedByCATPLMIdentificationAccess const char CATPLMTypeId_PLMCoreRepReference[];  // "PLMCoreRepReference"  

/**
 * @deprecated V6R213
 * @use CATPLMIdentificationAccess.CATPLMTypeH#CATPLMTypeH("PLMCoreInstance")
 */
extern ExportedByCATPLMIdentificationAccess const char CATPLMTypeId_PLMCoreInstance[];      // "PLMCoreInstance"  

/**
 * @deprecated V6R213
 * @use CATPLMIdentificationAccess.CATPLMTypeH#CATPLMTypeH("PLMCoreRepInstance")
 */
extern ExportedByCATPLMIdentificationAccess const char CATPLMTypeId_PLMCoreRepInstance[];   // "PLMCoreRepInstance"  

/**
 * @deprecated V6R213
 * @use CATPLMIdentificationAccess.CATPLMTypeH#CATPLMTypeH("PLMConnection")
 */
extern ExportedByCATPLMIdentificationAccess const char CATPLMTypeId_PLMConnection[];        // "PLMConnection"  

/**
 * @deprecated V6R213
 * @use CATPLMIdentificationAccess.CATPLMTypeH#CATPLMTypeH("PLMPort")
 */
extern ExportedByCATPLMIdentificationAccess const char CATPLMTypeId_PLMPort[];              // "PLMPort"  


/**
 * @deprecated V6R213
 * @use CATPLMIdentificationAccess.CATPLMTypeH#CATPLMTypeH("PLMCoreReference")
 */
extern const ExportedByCATPLMIdentificationAccess CATPLMTypeId CATPLMTypeId_CoreReference;

/**
* @deprecated V6R213
* @use CATPLMIdentificationAccess.CATPLMTypeH#CATPLMTypeH("PLMCoreRepReference")
*/
extern const ExportedByCATPLMIdentificationAccess CATPLMTypeId CATPLMTypeId_CoreRepReference;

/**
* @deprecated V6R213
* @use CATPLMIdentificationAccess.CATPLMTypeH#CATPLMTypeH("PLMCoreInstance")
*/
extern const ExportedByCATPLMIdentificationAccess CATPLMTypeId CATPLMTypeId_CoreInstance;

/**
* @deprecated V6R213
* @use CATPLMIdentificationAccess.CATPLMTypeH#CATPLMTypeH("PLMCoreRepInstance")
*/
extern const ExportedByCATPLMIdentificationAccess CATPLMTypeId CATPLMTypeId_CoreRepInstance;

/**
* @deprecated V6R213
* @use CATPLMIdentificationAccess.CATPLMTypeH#CATPLMTypeH("PLMConnection")
*/
extern const ExportedByCATPLMIdentificationAccess CATPLMTypeId CATPLMTypeId_Connection;

/**
* @deprecated V6R213
* @use CATPLMIdentificationAccess.CATPLMTypeH#CATPLMTypeH("PLMPort")
*/
extern const ExportedByCATPLMIdentificationAccess CATPLMTypeId CATPLMTypeId_Port;

/**
* @deprecated V6R213
* @use CATPLMIdentificationAccess.CATPLMTypeH#CATPLMTypeH("CacheInstance")
*/
extern const ExportedByCATPLMIdentificationAccess CATPLMTypeId CATPLMTypeId_DynamicCacheInstance;

/**
* @deprecated V6R213
* @use CATPLMIdentificationAccess.CATPLMTypeH#CATPLMTypeH("HistoryEntry")
*/
extern const ExportedByCATPLMIdentificationAccess CATPLMTypeId CATPLMTypeId_HistoryEntry;

/**
* @deprecated V6R213
* @use CATPLMIdentificationAccess.CATPLMTypeH#CATPLMTypeH("LPPrivateRepReference")
*/
extern const ExportedByCATPLMIdentificationAccess CATPLMTypeId CATPLMTypeId_PrivateRepReference;

/**
* @deprecated V6R213
* @use CATPLMIdentificationAccess.CATPLMTypeH#CATPLMTypeH("LPPrivateRepInstance")
*/
extern const ExportedByCATPLMIdentificationAccess CATPLMTypeId CATPLMTypeId_PrivateRepInstance;

/**
* @deprecated V6R213
* @use CATPLMIdentificationAccess.CATPLMTypeH#CATPLMTypeH("VPMReference")
*/
extern const ExportedByCATPLMIdentificationAccess CATPLMTypeId CATPLMTypeId_ProductReference;

/**
* @deprecated V6R213
* @use CATPLMIdentificationAccess.CATPLMTypeH#CATPLMTypeH("VPMInstance")
*/
extern const ExportedByCATPLMIdentificationAccess CATPLMTypeId CATPLMTypeId_ProductInstance;

/**
* @deprecated V6R213
* @use CATPLMIdentificationAccess.CATPLMTypeH#CATPLMTypeH("VPMCfgContext")
*/
extern const ExportedByCATPLMIdentificationAccess CATPLMTypeId CATPLMTypeId_VPMCfgContext;

/**
* @deprecated V6R213
* @use CATPLMIdentificationAccess.CATPLMTypeH#CATPLMTypeH("VPMCfgEffectivity")
*/
extern const ExportedByCATPLMIdentificationAccess CATPLMTypeId CATPLMTypeId_VPMCfgEffectivity;

/**
* @deprecated V6R213
* @use CATPLMIdentificationAccess.CATPLMTypeH#CATPLMTypeH("VPMCfgInstanceConfiguration")
*/
extern const ExportedByCATPLMIdentificationAccess CATPLMTypeId CATPLMTypeId_VPMCfgInstanceConfiguration;

/**
* @deprecated V6R213
* @use CATPLMIdentificationAccess.CATPLMTypeH#CATPLMTypeH("VPMCfgConfiguration")
*/
extern const ExportedByCATPLMIdentificationAccess CATPLMTypeId CATPLMTypeId_VPMCfgConfiguration;

/**
* @deprecated V6R213
* @use CATPLMIdentificationAccess.CATPLMTypeH#CATPLMTypeH("WspTableEntry")
*/
extern const ExportedByCATPLMIdentificationAccess CATPLMTypeId WsEntry;

#endif
