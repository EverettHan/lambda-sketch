#ifndef CATIOmbLinkAccessListener_H
#define CATIOmbLinkAccessListener_H


// COPYRIGHT DASSAULT SYSTEMES 2006


/**
* @level Protected
* @usage U5
*/


#include "CATObjectModelerBase.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATObjectModelerBase IID IID_CATIOmbLinkAccessListener;
#else
extern "C" const IID IID_CATIOmbLinkAccessListener ;
#endif


/**
* Listener on events related to relation and link access APIs.
*/
class ExportedByCATObjectModelerBase CATIOmbLinkAccessListener : public CATBaseUnknown
{
	CATDeclareInterface;

public:

	/**
	* The transactions that send events.
	*/
	enum TransactionType{ ComponentLoad };

	/** 
	* Called before executing a transaction.
	* @param iType
	*  The type of the transaction.
	* @param iNumberOfObjects
	*  The number of objects involved by the transaction.
	* @return
	*  An HRESULT value: 
	*  <dl>
	*   <dt>E_FAIL</dt>
	*    <dd>Abort the transaction.</dd>
	*   <dt>S_OK</dt>
	*    <dd>Proceed with the transaction.</dd>
	*  </dl>
	*/
	virtual HRESULT OnBeginTransaction( TransactionType iType, int iNumberOfObjects ) = 0;

	/** 
	* Called before executing an operation on a specific object.
	* @param iType
	*  The type of the current transaction.
	* @param ipObj
	*  The involved object.
	*/
	virtual void OnBeginEvent( TransactionType iType, CATBaseUnknown* ipObj ) = 0;

	/** 
	* Called after executing an operation on a specific object.
	* @param iType
	*  The type of the current transaction.
	* @param ipObj
	*  The involved object.
	* @param iIsSuccessful
	*  <dl>
	*   <dt>TRUE</dt>
	*    <dd>The operation succeeded.</dd>
	*   <dt>FALSE</dt>
	*    <dd>The operation failed.</dd>
	*  </dl>
	*/
	virtual void OnEndEvent( TransactionType iType, CATBaseUnknown* ipObj, CATBoolean iIsSuccessful ) = 0;

	/** 
	* Called after executing a transaction.
	* @param iType
	*  The type of the transaction.
	*/
	virtual void OnEndTransaction( TransactionType iType ) = 0;
};

CATDeclareHandler( CATIOmbLinkAccessListener, CATBaseUnknown );


#endif
