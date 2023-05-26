/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES	2001
#ifndef CATIStandardValue_H
#define CATIStandardValue_H

#include "CATBaseUnknown.h"
#include "CATCORBAAny.h"

/**
 * Interface to get a standard value
 */
#include "UIModelInterfaces.h"
#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByUIModelInterfaces IID IID_CATIStandardValue;
#else
extern "C" const IID IID_CATIStandardValue;
#endif

#include "CATWinCORBA.h"
#include "CATListOfCATUnicodeString.h"

#ifndef CATStdKind
#define CATStdKind TCKind
#endif  // CATStdKind

class CATUnicodeString;

class ExportedByUIModelInterfaces CATIStandardValue : public CATBaseUnknown
{ 
public:
  CATDeclareInterface;

  /**
		obtain the size for a list
  * @param iName
  *	name of the attribute.
  * @param oSize
  * size
  * @return
  * status
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT GetSize(const char* iName, int& oSize ) = 0;

  /**
		obtain the type
  * @param iName
  *	The name of the attribute.
  * @param oType
  * type 
  * @return
  * status
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT GetType(const char* iName, CATStdKind& oType ) = 0;
  /**
		obtain type of elements if list
  * @param iName
  *	name
  * @param oType
  * type 
  * @return
  * status
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  
  virtual HRESULT GetListType(const char* iName, CATStdKind& oType ) = 0;

  /**
		obtain name of a definition
  * @param iName
  *	name of the attribute.
  * @param oName
  * name of Enum or Type Definition
  * @return
  * status
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT GetDefinitionName( const char* iName, CATUnicodeString& oName ) =  0 ;
  
  /**
		obtain integer value (array)
  * @param iName
  *	name
	* @param oValue
  *	array of unitialized integers
	* @param oSize
  * array size pointer
  * @return
  * status
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT GetValue(const char* iName, int* oValue, int* oSize = 0) = 0;
  /**
		obtain integer value (single)
  * @param iName
  *	name
  * @param iRank
  * rank in list or type
  * @param oValue
  * integer value
  * @return
  * status
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT GetValue(const char* iName, const int& iRank, int& oValue ) = 0;


  /**
		obtain double value (array)
  * @param iName
  *	name
	* @param oValue
  *	array of unitialized doubles
	* @param oSize
  * array size pointer
  * @return
  * status
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT GetValue(const char* iName, double* oValue, int *oSize = NULL) = 0;
  /**
		obtain double value (element)
  * @param iName
  *	name
  * @param iRank
  * rank in list or type
  * @param oValue
  * double value
  * @return
  * The status call
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT GetValue(const char* iName, const int& iRank, double& oValue ) = 0;


  /**
		obtain string value (array)
  * @param iName
  *	name
	* @param oValue
  *	array of pointers to CATUnicodeString (must exist before call)
	* @param oSize
  * array size pointer
  * @return
  * status
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT GetValue(const char* iName, CATUnicodeString** oValue, int *oSize = NULL) = 0;

  /**
		obtain string value (single)
  * @param iName
  *	name
  * @param iRank
  * rank in array or type
  * @param oValue
  * string value
  * @return
  * status
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT GetValue(const char* iName, const int& iRank, CATUnicodeString* oValue ) = 0;


  /**
		modify integer value (by array)
  * @param iName
  *	name
	* @param iValue
  *	array of integers
	* @param iSize
  * array size
  * @return
  * status
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT SetValue(const char* iName, int* iValue, int iSize = 1) = 0;

  /**
		modify integer value element
  * @param iName
  *	name
  * @param iRank
  * rank in list or type
  * @param iValue
  *	integer value
  * @return
  * status
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT SetValue(const char* iName, const int& iRank, int& iValue) = 0;

  /**
		modify double value (by array)
  * @param iName
  *	name
  * @param iValue
  *	array of doubles
  * @param iSize
  * array size
  * @return
  * status
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT SetValue(const char* iName, double* iValue, int iSize = 1) = 0;

  /**
		modify double value (element)
  * @param iName
  *	name
  * @param iRank
  * rank in list or type
  * @param iValue
  *	double value
  * @return
  * status
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT SetValue(const char* iName, const int& iRank, double& iValue) = 0;

  /**
		modify string value (by array)
  * @param iName
  *	standard name
	* @param iValue
  *	array of string pointers
	* @param iSize
  * array size
  * @return
  * status
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT SetValue(const char* iName, CATUnicodeString** iValue, int iSize = 1) = 0;

  /**
		modify string value (element)
  * @param iName
  *	name
  * @param iRank
  * rank in list or type
  * @param iValue
  *	CATUnicodeString value
  * @return
  * status
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT SetValue(const char* iName, const int& iRank, CATUnicodeString& iValue) = 0;

  /**
		obtain max integer value
  * @param iName
  *	name
  * @param oMin, oMax
  * min and max
  * @param oMaxSet
  * true if max is set (otherwise only min)
  * @return
  * status
  * <br><b>Legal values</b>: S_OK, E_FAIL (no min/max defined)
  */
  virtual HRESULT GetMinMaxValues(const char* iName, int& oMin, int& oMax,boolean& oMaxSet ) = 0;

  /**
		obtain max size allowed in a node
  * @param iName
  *	name
  * @param oMax
  * maximum size (number of values)
  * @return
  * status
  * <br><b>Legal values</b>: S_OK, E_FAIL (no max size)
  */
  virtual HRESULT GetMaxSize(const char* iName, int& oMax) = 0;

  /**
		obtain lock value
  * @param iName
  *	standard name
  * @return
  * status
  * <br><b>Legal values</b>: S_OK, S_FALSE, E_FAIL
  */
  virtual HRESULT IsLocked(const char* iName)=0;

  /**
		Lock corresponding value
  * @param iName
  *	standard name
  * @return
  * status
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT Lock(const char* iName)=0;
  /**
		Unlock corresponding value
  * @param iName
  *	standard name
  * @return
  * status
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT Unlock(const char* iName)=0;

  /**
		Define a new occurence of a defined type
  * @param iName
  *	name
  * @param oRank
  * rank of new occurrence
  * @return
  * status
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT AppendInstance( const char* iName, int& oRank )=0;

  /**
		Remove an occurence of a defined type
  * @param iName
  *	name
  * @param iRank
  * rank to be removed
  * @return
  * status
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT RemoveInstance( const char* iName, const int& iRank )=0;
	
  /**
		Lists all elements of type definition
  * @param iTypeName
  *	type name
  * @param oStringList
  * list of names
  * @return
  * status
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT ListAttributes(const CATUnicodeString& iTypeName, 
				 CATListOfCATUnicodeString* oStringList) = 0;
};
//
CATDeclareHandler(CATIStandardValue, CATBaseUnknown);

#endif      

