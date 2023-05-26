/* -*-C++-*- */
// COPYRIGHT DASSAULT SYSTEMES  2005                                         
//===========================================================================
//
// CATIV4iTransactionFactory 
//
//==============================================================================
// Creation : V. ZAFRANY le 15/06/2005
//==============================================================================

#ifndef CATIV4iTransactionFactory_H
#define CATIV4iTransactionFactory_H

/**
*@level Protected
*@usage U3
*/

#include "AD0XXBAS.h"
#include "CATBaseUnknown.h"

class CATIContainer;
class CATFormat;
class CATIV4iTransaction;

extern ExportedByAD0XXBAS IID IID_CATIV4iTransactionFactory;

/**
	* Interface to allow the applications to create their own transactions
	* during the Copy/Paste operation. 
	* <b>Role</b>: This interface is implemented by all applicative elements 
	* that have to be migrated. 
*/
class  ExportedByAD0XXBAS CATIV4iTransactionFactory :  public CATBaseUnknown
{
  CATDeclareInterface;
  
	public:
  
/**
 * Retrieves the transaction associated to the element which implements the interface.
 * <br><b>Role</b>: The "GetTransaction" method enables to retrieve the transaction 
 *									chosen by the application in order to migrate the element which
 *									implements this interface. 
 *									The application can either decide to create a new transaction for 
 *									the element to be migrated or to use an existing one.
 * @param iFormat
 *	The conversion format.
 *	<b>Legal values</b>:
 *	<br><tt>CATIA_SPEC:</tt>    the "As Spec" conversion
 * 	<br><tt>CATIA_RESULT:</tt>  the "As Result" conversion
 * @param iReceptContainer
 *	The selected container for the Paste operation.
 * @param oApplicativeTransaction
 *	The chosen transaction for the migration.
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/

	virtual HRESULT GetTransaction(	const CATFormat*		iFormat,	
																		CATIContainer*		iReceptContainer,
																		CATIV4iTransaction*&	oApplicativeTransaction ) = 0;
    
};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATIV4iTransactionFactory, CATBaseUnknown ) ;

#endif
