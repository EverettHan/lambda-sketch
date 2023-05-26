//======================================================================================

//======================================================================================
#ifndef XPDMOmxCollection_H
#define XPDMOmxCollection_H
#include "ExportedByXPDMServices.h"

#include "CATOmxDefaultCollecManager.h"
#include "CATOmxCollecManager.h"
#include "CATOmxClassManager.h"
//#include "CATPLMIDCollecManager.h" 

#include "CATOmxArray.h"
#include "CATOmxOMap.h"
#include "CATOmxOSet.h"

//#include "CATPLMIDCollections.h"
#include "CATBinary.h"
#include "CATUnicodeString.h"

/*
// ############################################### Integrity data  structures ###############################################
// streams
class CATPLMExchangeEngineStatesStream;
template<> ExportedByXPDMServices CATOmxCollecManager&  CATOmxDefaultCollecManager< CATPLMExchangeEngineStatesStream >::manager();
typedef CATOmxArray< CATPLMExchangeEngineStatesStream,  CATOmxDefaultCollecManager< CATPLMExchangeEngineStatesStream >::manager > CATOmxArrayOfCATPLMExchangeEngineStatesStream;

template<> ExportedByXPDMServices CATOmxCollecManager&  CATOmxDefaultCollecManager< CATOmxArrayOfCATPLMExchangeEngineStatesStream >::manager();
typedef CATOmxOMap< CATUnicodeString, CATOmxArrayOfCATPLMExchangeEngineStatesStream, CATOmxDefaultCollecManager< CATUnicodeString >::manager, CATOmxDefaultCollecManager< CATOmxArrayOfCATPLMExchangeEngineStatesStream >::manager> CATOmxOMapCUSToCATOmxArrayOfCATPLMExchangeEngineStatesStream;

template<> ExportedByXPDMServices CATOmxCollecManager&  CATOmxDefaultCollecManager< CATOmxOMapCUSToCATOmxArrayOfCATPLMExchangeEngineStatesStream >::manager();
typedef CATOmxOMap< CATUnicodeString, CATOmxOMapCUSToCATOmxArrayOfCATPLMExchangeEngineStatesStream, CATOmxDefaultCollecManager< CATUnicodeString >::manager, CATOmxDefaultCollecManager< CATOmxOMapCUSToCATOmxArrayOfCATPLMExchangeEngineStatesStream >::manager> CATOmxOMapCUSToCATOmxOMapCUSToCATOmxArrayOfCATPLMExchangeEngineStatesStream;

//template<> ExportedByXPDMServices CATOmxCollecManager&  CATOmxDefaultCollecManager< CATOmxArrayCATPLMExchangeEngineStatesStream >::manager();
class  CATPLMExchangeEngineStatesStreamSet;
template<> ExportedByXPDMServices CATOmxCollecManager&  CATOmxDefaultCollecManager< CATPLMExchangeEngineStatesStreamSet >::manager();
typedef CATOmxOMap< CATPLMID, CATPLMExchangeEngineStatesStreamSet, CATOmxDefaultCollecManager< CATPLMID >::manager, CATOmxDefaultCollecManager< CATPLMExchangeEngineStatesStreamSet >::manager> CATOmxOMapCATPLMIDToCATPLMExchangeEngineStatesStreamSet;

// vvsurl
class CATVVSUrl;
// existant CATVVSUrlCollecManager mais en private, donc on duplique :(
struct ExportedByXPDMServices CATPLMExIntEngOmxCATVVSUrlManager : public CATOmxClassManager<CATVVSUrl>
{
  //   -1 if a<b
  //    1 if a>b
  //    0 if a=b
  virtual int Compare(const void* p1, const void* p2) const;

  virtual CATHashKey Hash(const void* pBin) const;
};
ExportedByXPDMServices CATOmxCollecManager&  CATPLMExIntEngOmxCATVVSUrlManagerLocator();
typedef CATOmxOMap< CATVVSUrl, CATPLMExchangeEngineStatesStreamSet, CATPLMExIntEngOmxCATVVSUrlManagerLocator, CATOmxDefaultCollecManager< CATPLMExchangeEngineStatesStreamSet >::manager> CATOmxOMapCATVVSUrlToCATPLMExchangeEngineStatesStreamSet;

// locator keyvalueblock
class CATOmxKeyValueBlock;
struct ExportedByXPDMServices CATPLMExIntEngOmxCATOmxKeyValueBlockManager : public CATOmxClassManager<CATOmxKeyValueBlock>
{
  //   -1 if a<b
  //    1 if a>b
  //    0 if a=b
  virtual int Compare(const void* p1, const void* p2) const;
	// LBV: converage operation, this Hash function is never used as only catomxomap are used, if ohmap are used uncomment this

  //virtual CATHashKey Hash(const void* pBin) const;
	//
};
ExportedByXPDMServices CATOmxCollecManager&  CATPLMExIntEngOmxCATOmxKeyValueBlockManagerLocator();
typedef CATOmxOMap< CATOmxKeyValueBlock, CATPLMExchangeEngineStatesStreamSet, CATPLMExIntEngOmxCATOmxKeyValueBlockManagerLocator, CATOmxDefaultCollecManager< CATPLMExchangeEngineStatesStreamSet >::manager> CATOmxOMapCATOmxKeyValueBlockToCATPLMExchangeEngineStatesStreamSet;

// attributes of data
class CATPLMExchangeEngineStatesAttributes;
//template<> ExportedByXPDMServices CATOmxCollecManager&  CATOmxDefaultCollecManager<CATOmxKeyValueBlock>::manager();
//typedef CATOmxOMap<CATUnicodeString, CATOmxKeyValueBlock, CATOmxDefaultCollecManager< CATUnicodeString >::manager, CATOmxDefaultCollecManager< CATOmxKeyValueBlock >::manager> CATOmxOMapCUSToCATOmxKeyValueBlock;
template<> ExportedByXPDMServices CATOmxCollecManager&  CATOmxDefaultCollecManager<CATPLMExchangeEngineStatesAttributes>::manager();
typedef CATOmxOMap< CATUnicodeString, CATPLMExchangeEngineStatesAttributes, CATOmxDefaultCollecManager< CATUnicodeString >::manager, CATOmxDefaultCollecManager< CATPLMExchangeEngineStatesAttributes >::manager> CATOmxOMapCUSToCATPLMExchangeEngineStatesAttributes;


// data
class CATPLMExchangeEngineStatesData;
template<> ExportedByXPDMServices CATOmxCollecManager&  CATOmxDefaultCollecManager< CATPLMExchangeEngineStatesData >::manager();
typedef CATOmxOMap< CATPLMID, CATPLMExchangeEngineStatesData, CATOmxDefaultCollecManager< CATPLMID >::manager, CATOmxDefaultCollecManager< CATPLMExchangeEngineStatesData >::manager> CATOmxOMapCATPLMIDToCATPLMExchangeEngineStatesData;

// link
class CATPLMExchangeEngineStatesLink;
template<> ExportedByXPDMServices CATOmxCollecManager&  CATOmxDefaultCollecManager<CATPLMExchangeEngineStatesLink >::manager();
//typedef CATOmxArray< CATPLMExchangeEngineStatesLink, CATOmxDefaultCollecManager< CATPLMExchangeEngineStatesLink >::manager > CATOmxArrayCATPLMExchangeEngineStatesLink;
typedef CATOmxOMap< CATPLMID, CATPLMExchangeEngineStatesLink, CATOmxDefaultCollecManager< CATPLMID >::manager, CATOmxDefaultCollecManager< CATPLMExchangeEngineStatesLink >::manager> CATOmxOMapCATPLMIDToCATPLMExchangeEngineStatesLink;

// linkset
class CATPLMExchangeEngineStatesLinkSet;
template<> ExportedByXPDMServices CATOmxCollecManager&  CATOmxDefaultCollecManager< CATPLMExchangeEngineStatesLinkSet >::manager();
//typedef CATOmxOMap< CATUnicodeString, CATPLMExchangeEngineStatesLinkSet, CATOmxDefaultCollecManager< CATUnicodeString >::manager, CATOmxDefaultCollecManager< CATPLMExchangeEngineStatesLinkSet >::manager> CATOmxOMapCUSToCATPLMExchangeEngineStatesLinkSet;

//sr link
class CATPLMExchangeEngineStatesSRLink;
template<> ExportedByXPDMServices CATOmxCollecManager&  CATOmxDefaultCollecManager< CATPLMExchangeEngineStatesSRLink >::manager();
typedef CATOmxOMap< unsigned int, CATPLMExchangeEngineStatesSRLink, CATOmxDefaultCollecManager< unsigned int >::manager, CATOmxDefaultCollecManager< CATPLMExchangeEngineStatesSRLink >::manager> CATOmxOMapIntToCATPLMExchangeEngineStatesSRLink;

//srlink set
class CATPLMExchangeEngineStatesSRLinkSet;
template<> ExportedByXPDMServices CATOmxCollecManager&  CATOmxDefaultCollecManager< CATPLMExchangeEngineStatesSRLinkSet >::manager();
typedef CATOmxOMap< CATPLMID, CATPLMExchangeEngineStatesSRLinkSet, CATOmxDefaultCollecManager< CATPLMID >::manager, CATOmxDefaultCollecManager< CATPLMExchangeEngineStatesSRLinkSet >::manager> CATOmxOMapCATPLMIDToCATPLMExchangeEngineStatesSRLinkSet;

//Path Type link
class CATPLMExchangeEngineStatesPathTypeLink;
template<> ExportedByXPDMServices CATOmxCollecManager&  CATOmxDefaultCollecManager< CATPLMExchangeEngineStatesPathTypeLink >::manager();
typedef CATOmxOMap< unsigned int, CATPLMExchangeEngineStatesPathTypeLink, CATOmxDefaultCollecManager< unsigned int >::manager, CATOmxDefaultCollecManager< CATPLMExchangeEngineStatesPathTypeLink >::manager> CATOmxOMapIntToCATPLMExchangeEngineStatesPathTypeLink;

//Path type link set
class CATPLMExchangeEngineStatesPathTypeLinkSet;
template<> ExportedByXPDMServices CATOmxCollecManager&  CATOmxDefaultCollecManager< CATPLMExchangeEngineStatesPathTypeLinkSet >::manager();
typedef CATOmxOMap< CATPLMID, CATPLMExchangeEngineStatesPathTypeLinkSet, CATOmxDefaultCollecManager< CATPLMID >::manager, CATOmxDefaultCollecManager< CATPLMExchangeEngineStatesPathTypeLinkSet >::manager> CATOmxOMapCATPLMIDToCATPLMExchangeEngineStatesPathTypeLinkSet;

class CATPLMExchangeEngineStatesCompositionLink;
template<> ExportedByXPDMServices CATOmxCollecManager&  CATOmxDefaultCollecManager< CATPLMExchangeEngineStatesCompositionLink >::manager();
typedef CATOmxArray< CATPLMExchangeEngineStatesCompositionLink, CATOmxDefaultCollecManager< CATPLMExchangeEngineStatesCompositionLink >::manager > CATOmxArrayCATPLMExchangeEngineStatesCompositionLink;

template<> ExportedByXPDMServices CATOmxCollecManager&  CATOmxDefaultCollecManager< CATOmxArrayCATPLMExchangeEngineStatesCompositionLink >::manager();

typedef CATOmxOMap< CATPLMTypeH , CATOmxArrayCATPLMExchangeEngineStatesCompositionLink, CATOmxDefaultCollecManager< CATPLMTypeH >::manager, CATOmxDefaultCollecManager< CATOmxArrayCATPLMExchangeEngineStatesCompositionLink >::manager> CATOmxOMapRelTypeHToCATOmxArrayCATPLMExchangeEngineStatesCompositionLink;
typedef CATOmxOMap< CATPLMID, CATOmxArrayCATPLMExchangeEngineStatesCompositionLink, CATOmxDefaultCollecManager< CATPLMID >::manager, CATOmxDefaultCollecManager< CATOmxArrayCATPLMExchangeEngineStatesCompositionLink >::manager> CATOmxOMapCATPLMIDToCATOmxArrayCATPLMExchangeEngineStatesCompositionLink;


// StructureLinkType
struct ExportedByXPDMServices CATPLMExIntEngOmxCATPLMExchangeEngineStatesStructureLinkTypeManager : public CATOmxClassManager<CATPLMExchangeEngineStatesStructureLinkType>
{
  //   -1 if a<b
  //    1 if a>b
  //    0 if a=b
  virtual int Compare(const void* p1, const void* p2) const;
	// LBV: converage operation, this Hash function is never used as only catomxomap are used, if ohmap are used uncomment this
 // virtual CATHashKey Hash(const void* pBin) const;
	//
};

ExportedByXPDMServices CATOmxCollecManager&  CATPLMExIntEngOmxCATPLMExchangeEngineStatesStructureLinkTypeManagerLocator();
typedef CATOmxOMap< CATPLMExchangeEngineStatesStructureLinkType, CATPLMExchangeEngineStatesLinkSet, CATPLMExIntEngOmxCATPLMExchangeEngineStatesStructureLinkTypeManagerLocator, CATOmxDefaultCollecManager< CATPLMExchangeEngineStatesLinkSet >::manager> CATOmxOMapLinkTypeToCATPLMExchangeEngineStatesLinkSet;

// Structure
class CATPLMExchangeEngineStatesStructure;
template<> ExportedByXPDMServices CATOmxCollecManager&  CATOmxDefaultCollecManager< CATPLMExchangeEngineStatesStructure >::manager();
typedef CATOmxOMap< CATPLMID, CATPLMExchangeEngineStatesStructure, CATOmxDefaultCollecManager< CATPLMID >::manager, CATOmxDefaultCollecManager< CATPLMExchangeEngineStatesStructure >::manager> CATOmxOMapCATPLMIDToCATPLMExchangeEngineStatesStructure;
// Reverse Structure
class CATPLMExchangeEngineStatesReverseStructure;
template<> ExportedByXPDMServices CATOmxCollecManager&  CATOmxDefaultCollecManager< CATPLMExchangeEngineStatesReverseStructure >::manager();
typedef CATOmxOMap< CATPLMID, CATPLMExchangeEngineStatesReverseStructure, CATOmxDefaultCollecManager< CATPLMID >::manager, CATOmxDefaultCollecManager< CATPLMExchangeEngineStatesReverseStructure >::manager> CATOmxOMapCATPLMIDToCATPLMExchangeEngineStatesReverseStructure;

class CATPLMExchangeEngineStatesPackageElement;
template<> ExportedByXPDMServices CATOmxCollecManager&  CATOmxDefaultCollecManager< CATPLMExchangeEngineStatesPackageElement >::manager();
typedef CATOmxOMap< CATPLMID, CATPLMExchangeEngineStatesPackageElement, CATOmxDefaultCollecManager< CATPLMID >::manager, CATOmxDefaultCollecManager< CATPLMExchangeEngineStatesPackageElement >::manager> CATOmxOMapCATPLMIDToCATPLMExchangeEngineStatesPackageElement;
class CATPLMExchangeEngineStatesPackage;
template<> ExportedByXPDMServices CATOmxCollecManager&  CATOmxDefaultCollecManager< CATPLMExchangeEngineStatesPackage >::manager();
typedef CATOmxOMap< unsigned int, CATPLMExchangeEngineStatesPackage, CATOmxDefaultCollecManager< unsigned int >::manager, CATOmxDefaultCollecManager< CATPLMExchangeEngineStatesPackage >::manager> CATOmxOMapUIntToCATPLMExchangeEngineStatesPackage;

//CATPLMExchangeEngineState

typedef CATOmxArray<CATPLMID, CATOmxDefaultCollecManager< CATPLMID >::manager > CATOmxArrayCATPLMID;

typedef CATOmxOSet<CATPLMID, CATOmxDefaultCollecManager< CATPLMID >::manager > CATOmxOSetCATPLMID;
*/

class XPDMLegacyUniqueID;
template<> ExportedByXPDMServices CATOmxCollecManager&  CATOmxDefaultCollecManager< XPDMLegacyUniqueID >::manager();
typedef CATOmxArray< XPDMLegacyUniqueID, CATOmxDefaultCollecManager< XPDMLegacyUniqueID >::manager > CATOmxArrayOfXPDMLegacyUniqueID;

class XPDMLegacyRevisionFamily;
template<> ExportedByXPDMServices CATOmxCollecManager&  CATOmxDefaultCollecManager< XPDMLegacyRevisionFamily >::manager();
typedef CATOmxArray< XPDMLegacyRevisionFamily, CATOmxDefaultCollecManager< XPDMLegacyRevisionFamily >::manager > CATOmxArrayOfXPDMLegacyRevisionFamily;

class XPDMIdentificationData;
template<> ExportedByXPDMServices CATOmxCollecManager&  CATOmxDefaultCollecManager< XPDMIdentificationData >::manager();
typedef CATOmxOMap< CATUnicodeString, XPDMIdentificationData, CATOmxDefaultCollecManager< CATUnicodeString >::manager, CATOmxDefaultCollecManager< XPDMIdentificationData >::manager > CATOmOMapOfStringToXPDMIdentificationData;

typedef CATOmxArray< CATUnicodeString, CATOmxDefaultCollecManager< CATUnicodeString >::manager > ArrayOfCUS;
//template<> ExportedByXPDMServices CATOmxCollecManager&  CATOmxDefaultCollecManager< ArrayOfCUS >::manager();
typedef CATOmxArray< ArrayOfCUS, CATOmxDefaultCollecManager< ArrayOfCUS >::manager > ArrayOfArrayOfCUS;


#endif
