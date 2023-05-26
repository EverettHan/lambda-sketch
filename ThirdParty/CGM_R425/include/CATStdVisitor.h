/**  	   	   	 
* @level Protected 	  	  	 
* @usage U1 	  	  	 
*/


// COPYRIGHT DASSAULT SYSTEMES  2001
//=============================================================================
//
// CATStandardVisitors.cpp:
//
//=============================================================================
// Usage Notes:
//
//=============================================================================
// 26/01/2001   Creation                                   TVQ
//=============================================================================


#ifndef _CATStandardsVisitors_
#define _CATStandardsVisitors_

#include "CATIAV5Level.h"
#include "CATLifDictionary.h"
#include "CATCallbackManager.h"
#include "CATVisitorAdapter.h"
#include "CATBaseUnknown.h"

#include "CATLISTV_CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATCkeHashTabOfCATBaseUnknown.h"

#include "CATIVisitor.h"
#include <time.h>
#include "CATEventSubscriberTypedefs.h"

class CATUuid;

/**
* Basic visitor (accumulator of instances implementing a given interface)
*/
class ExportedByCATLifDictionary CATStdVisitor : public CATVisitorAdapter
{
	CATDeclareClass;
public:
	CATStdVisitor(const GUID& clsid, CATLISTV(CATBaseUnknown_var) *listToFill, int stopWhenAnInstanceFound);
	CATStdVisitor(const CATUnicodeString &itfName, CATLISTV(CATBaseUnknown_var) *listToFill, int stopWhenAnInstanceFound);
	virtual ~CATStdVisitor();

	HRESULT Visit(CATBaseUnknown *instance);
	
private:
	CATStdVisitor(const CATStdVisitor&);
	void operator=(const CATStdVisitor&);

	GUID _Guid;
	CATUnicodeString _ItfName;
	int _StopWhenAnInstanceFound; /** @win64 fbq : 64-bit structure packing **/
	int _GuidOrItfName; // 0 guid 1 intfName
	CATLISTV(CATBaseUnknown_var) *_List;
};


class CATStdCacheVisitor;

/**
 * Standard recursive and optimized visitor (thanks to FSD).<br>
 * It ensures that one can not visit two times the same instance.<br>
 * It doens't visit any instance any more if Visit returned E_FAIL once. (a good coding of CATIParmPublisher::VisitChildren should do the same thing, see Visit explanation in CATIVisitor header)
 */
class ExportedByCATLifDictionary CATStdRecursiveVisitor : public CATVisitorAdapter
{
	CATDeclareClass;
public:
	CATStdRecursiveVisitor( CATIVisitor * iVisit, int guessedSize = 100);
	virtual ~CATStdRecursiveVisitor() {}

	virtual HRESULT Visit( CATBaseUnknown * iInstance );

private:
	CATStdRecursiveVisitor(const CATStdRecursiveVisitor&);
	void operator=(const CATStdRecursiveVisitor&);

protected:
  HRESULT m_subState;
	CATIVisitor_var m_subVisitor;
	CATHTAB(CATBaseUnknown) m_table;
};

#endif
