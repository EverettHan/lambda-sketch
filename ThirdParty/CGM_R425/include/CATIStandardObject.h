/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES	2000
#ifndef CATIStandardObject_H
#define CATIStandardObject_H

#include "CATBaseUnknown.h"

/**
 * Interface to explore the standard tree
 */
#include "UIModelInterfaces.h"
#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByUIModelInterfaces IID IID_CATIStandardObject;
#else
extern "C" const IID IID_CATIStandardObject;
#endif

class CATUnicodeString;

#include "CATListOfCATIStandardObject.h"

#include "CATLISTV_Declare.h"
class CATLISTV(CATIStandardObject_var) ;


class ExportedByUIModelInterfaces CATIStandardObject : public CATBaseUnknown
{ 
  CATDeclareInterface;

public:

  /**
		List children
  * @param  oStdList
  * list of std
  * @return
  * The status call
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT ListChildren( CATLISTV(CATIStandardObject_var)* oStringList) = 0;

  /**
		get a child
  * @param iName
  *	The name of the child
	* @param oStandard
  *	pointer to standard object
  * @return
  * The status call
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  //virtual HRESULT GetChild(const char* iName, CATIStandardObject** oStandard) = 0;
  /**
		Get String Identifier
  * @param oString
  *	identifier to be used by CATIStandardValue (xxx.xxx.xxx)
  * @return
  * The status call
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT GetStringIdentifier(CATUnicodeString& oString) = 0;

  /**
		Get Display Name
  * @param oString
  *	identifier to be displayed
  * @return
  * The status call
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
  virtual HRESULT GetDisplayName(CATUnicodeString& oString) = 0;
 
};
CATDeclareHandler(CATIStandardObject, CATBaseUnknown);

#endif      

