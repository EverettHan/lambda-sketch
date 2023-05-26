#ifndef __CATIDocLinkManager_h__
#define __CATIDocLinkManager_h__ 2 // Version number.

/**
 * @level Private
 * @usage U3
 * COPYRIGHT DASSAULT SYSTEMES 1998
 */

//=============================================================================
//
//  CATIDocLinkManager :
//		interface used to access to root links pointed by a document
//  
//=============================================================================          
//
//==================================================================
//  Usage notes
//   This class is used to centralise pointing root objects 
//	( pointing documents...)
//
//	slg July.98
//==================================================================

// ----------------------------------------------------------------------------
//	Bind method
//
//	input:
//		- IndexVal: index value from the index table
//		- LightName: (consider a light name comparing to PointedObject->GetName_B(..) return value )
//	output:
//		- PointedObject: pointed object
// ----------------------------------------------------------------------------
//	GetIndex method
//
//	input:
//		- PointedObject: pointed object
//		- ResearchType
//	output:
//		- IndexVal: index value from the index table	
// ----------------------------------------------------------------------------
//	GetIndexLightName method
//
//	input:
//		- PointedObject: pointed object
//		- ResearchType
//	output:
//		- IndexVal: index value from the index table	
//		- LightName
// ----------------------------------------------------------------------------
//	GetIndexLightName method
//
//	input:
//		- CompleteName: pointed object comple name (object)
//		- ResearchType
//	output:
//		- IndexVal: index value from the index table	
//		- LightName
// ----------------------------------------------------------------------------
//
//	GetIndexLightName method
//
//	output: 
//		- IndexList: list of index possible on a given document
//	
// ----------------------------------------------------------------------------
//
//	LocateLightName method
//
//	input:
//		- IndexVal: value of index
//	output:
//		-LightName: Corresponding Name (LightName)
//		
// ----------------------------------------------------------------------------


// System
#include "CATBaseUnknown.h"
#include "CATListOfInt.h"
// ObjectModelerCollection
#include "sequence_octet.h"
// ObjectModelerBase
#include "CATObjectModelerBase.h"

class CATILinkableObject_var;
class CATIBindParameters;
class CATUnicodeString;
class CATOmbRelationMetaData;
class CATOmxKeyValueBlock ;

extern ExportedByCATObjectModelerBase IID IID_CATIDocLinkManager ;


enum CATIndexResearch 
{
  CreateIndexIfNecessary=1,
  UponExistingIndex=2,
  TakeCareOfMyOldPath=3 //Reserver a usage res. a specsmodeler pour rattrape de  donnees verolees
};


class ExportedByCATObjectModelerBase CATIDocLinkManager : public CATBaseUnknown
{
  CATDeclareInterface;

public:
	  
  virtual HRESULT Bind(int iIndexVal, SEQUENCE(octet) const & iLightName, CATILinkableObject_var & oPointedObject, CATIBindParameters * iParams = NULL, CATUnicodeString * oErrMsg = NULL) = 0;

  virtual	HRESULT GetCompleteName(int iIndexVal, SEQUENCE(octet) const & iLightName, SEQUENCE(octet) & oCompleteName) = 0;

	virtual HRESULT GetIndexList (CATListOfInt & oIndexList) = 0;

  virtual HRESULT GetRootNameFromIndex(int iIndexVal, SEQUENCE(octet) & oRootName) = 0;


	// Counter Management
  virtual HRESULT AddRefForLink(int Index, int AddRefMode = 3, boolean SavingMode = FALSE) = 0;

  virtual HRESULT ReleaseForLink(int Index, int ReleaseMode = 3, boolean SavingMode = FALSE) = 0;


	// New implementation of GetIndex methods with meta data management
  virtual	HRESULT GetIndex(CATILinkableObject_var const & iPointedObject, CATOmbRelationMetaData & iRMD, int & oIndex, CATIndexResearch iResearchType = CreateIndexIfNecessary) = 0;

  virtual	HRESULT GetIndexLightName(CATILinkableObject_var const & iPointedObject, CATOmbRelationMetaData & iRMD, int & oIndex, SEQUENCE(octet) & oLightName, CATIndexResearch iResearchType = CreateIndexIfNecessary) = 0;

  virtual	HRESULT GetIndexLightName(SEQUENCE(octet) const & iCompleteName, CATOmbRelationMetaData & iRMD, int& oIndex, SEQUENCE(octet)& oLightName, CATIndexResearch iResearchType = CreateIndexIfNecessary) = 0;

	/**
	 * Retrieves the index corresponding to the old index and new link meta data
	 * @param iOldIndex
	 *	Old index.
	 * @param iNewLinkMD
	 *	new link meta data.
	 * @param oIndex
	 *	new index.
	 * @return
	 *	An HRESULT value: 
	 *	<dl>
	 *		<dt>S_OK</dt>
	 *			<dd>The new index is the same as the old one.</dd>
	 *		<dt>S_FALSE</dt>
	 *			<dd>The new index different from the old one.</dd>
	 *		<dt>E_FAIL</dt>
	 *			<dd>The old index doesn't exist.</dd>
	 *	</dl>
   */
  virtual HRESULT GetIndex(int iOldIndex, CATOmbRelationMetaData & iNewRelationMD, int & oIndex) = 0;
    
  // Replace deprecated GetIndexLightName & co. Internal use for CATBAck, FBDI etc ...
  virtual HRESULT GetRawLinkPersistency(const CATOmxKeyValueBlock & iVersion, const CATBaseUnknown_var & iPointed, SEQUENCE(octet) & oLightName, int & oIndex) const = 0;

};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATIDocLinkManager , CATBaseUnknown ) ;


#endif
