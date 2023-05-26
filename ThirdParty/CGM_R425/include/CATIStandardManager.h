/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES	2001
#ifndef CATIStandardManager_H
#define CATIStandardManager_H

#include "CATBaseUnknown.h"
#include "CATCollec.h"

/**
 * Interface to get a standard manager
 */
#include "UIModelInterfaces.h"
#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByUIModelInterfaces IID IID_CATIStandardManager;
#else
extern "C" const IID IID_CATIStandardManager;
#endif

class CATUnicodeString;
class CATIStandardObject;

#include "CATLISTV_Declare.h"
class CATLISTV(CATIStandardObject_var) ;

class ExportedByUIModelInterfaces CATIStandardManager : public CATBaseUnknown
{ 
public:
  CATDeclareInterface;

  /**
  *	get the standard root
  * @param iName
  *	The name of the standard
  * @param oStandardList
  *	pointer to a liste of standard object
  * @return
  * status
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  //virtual HRESULT GetRoots(const char* iName, CATLISTV(CATIStandardObject_var)* oStandardList)= 0;

  /**
		get the standard root
  * @param iName
  *	The name of the standard
	* @param oStandard
  *	pointer to standard object
  * @return
  * status
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT GetRoot(const char* iName, CATIStandardObject** oStandard) = 0;

  /**
		get the standard object
  * @param iName
  *	path name
	* @param oStandard
  *	pointer to standard object
  * @return
  * status
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT GetObject(const char* iName, CATIStandardObject** oStandard) = 0;

  /**
  *	Add a standard (by parsing xml file in $OS/resources/standard)
  * @param iName
  *     standard name
  * @param iDir
  *     directory (standard/...)
  * @return
  * status
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
 virtual HRESULT AddStandard(const char* iName,const char* iDir = NULL) = 0;

  /**
  *	List standards
  * @param  oStringList
  * list of std
  * @return
  * status
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT ListStandards(CATListOfCATUnicodeString* oStringList) = 0;

  /**
  *	Remove a standard
  * @param iName
  *     standard name
  * @return
  * status
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
 virtual HRESULT RemoveStandard(const char* iName) = 0;

  /**
		Copy a value to another location in tree (will create object if not existent)
  * @param iName1
  *	path name
  * @param iName2
  * target path name
  * @return
  * status
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT CopyValue( const char* iName1, const char* iName2 )=0;

  /**
		remove a value (with all nodes)
  * @param iName1
  *	path name
  * @return
  * status
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT RemoveValue( const char* iName1 )=0;

  /**
  *	GetStandardType
  * @param  iName
  * standard name
  * @param oType
  * the type
  * @return
  * status
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT GetStandardType(const char* iName,CATUnicodeString& oType) = 0;

  /**
  *	List Definitions
  * @param stdName
  *        Standard Name
  * @param iFilter
  *   0 : All definitions
  *   1 : only Enum Definitions 
  *   2 : only Type Definitions
  * @param  oStringList
  * list of definitions
  * @return
  * status
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT ListDefinitions(const CATUnicodeString& stdName, const int& iFilter, 
				  CATListOfCATUnicodeString* oStringList) = 0;


   /**
		SaveAsXML
  * @param iStandardName
  * standard
  * @param iFileName
  *	XML File output
  * @return
  * status
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT SaveAsXML(const char* iStandardName,const char* iFileName) = 0;

  /**
		GetLastDiagnosis (of last failed operation : unstream...)
  * @param oStr
  *	string
  * @return
  * status
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT GetLastDiagnosis(CATUnicodeString& oStr) = 0;

  /**
  * Replicate a standard (identified by its name) from a given standards manager in this 
  * standard manager.
  * <b>Warning</b> Since CNEXT documents are supposed to be self-contained, you cannot rely
  * on the fact that an embeded standard named XXX is always the same standard as the XML 
  * file named XXX.XML
  * <b>Warning</b> This operation is not automatically replayed during a warmstart. 
  * You have to manage manually the replication at warmstart-time.
  * @param iStandardName
  * The name of the standard (in the given CATIStandardManager) which is to be replicated
  * in this standard manager.
  * @param iSrcManager
  * The CATIStandardManager providing the standard to replicate.
  * <br><b>Precondition</b>:
  * <ul>
  * <li>iStandardName must be the name of a standard in iSrcManager.</li>
  * <li>This standard manager must not already contains a standard named iStandardName.</li>
  * <li>Replication in the same standards manager is forbiden.</li>
  * </ul>
  * @return
  * An <tt>HRESULT</tt> value.
  * <br><b>Legal values</b>:
  * <dl>
  * <dt> <tt>S_OK</tt>          <dd> Success. This standard manager now contains a copy of the source  
  *                                  standard.
  * <dt> <tt>E_UNEXPECTED</tt>  <dd> Preconditions not met.
  * <dt> <tt>E_FAIL</tt>        <dd> Internal error. Check that there is enough space on disk for creating 
  *                                  a temporary file.
  * </dl>
  */
  virtual HRESULT ReplicateStandardFrom(const char* iStandardName, CATIStandardManager *iSrcManager)= 0;


};

CATDeclareHandler(CATIStandardManager, CATBaseUnknown);

#endif      

