/* -*-C++-*- */
// COPYRIGHT DASSAULT SYSTEMES  2005                                         
//===========================================================================
//
// CATIV4iTransactionFactory 
//
//==============================================================================
// Creation : V. ZAFRANY le 15/06/2005
//==============================================================================

#ifndef CATIV4iTransaction_H
#define CATIV4iTransaction_H

/**
* @level Protected
* @usage U3
*/

#include "AD0XXBAS.h"
#include "CATBaseUnknown.h"
#include "CATLISTP_CATBaseUnknown.h"

class CATIConversionTransaction;

extern ExportedByAD0XXBAS IID IID_CATIV4iTransaction;

/**
	* Interface to represent a  conversion transaction for the Copy/Paste operation. 
	* <b>Role</b>: All applicative elements that have to be migrated
	*							 will be added to a corresponding transaction: either a new one or an 
	*							 existing one. That transaction is defined via the 
	*							 CATIV4iTransactionFactory::GetTransaction method.
*/
class  ExportedByAD0XXBAS CATIV4iTransaction :  public CATBaseUnknown
{
  CATDeclareInterface;

	public:

	/**
	* Adds one element in the conversion transaction.
	* <br><b>Role</b>: The "AddElement" method enables to add the element to be migrated 
	*									 in the transaction chosen by the application. 
	* @param iElementToConvert
	*	The V4 element to be migrated that has to be taken in charge by the conversion 
	*	transaction.
	* @return
	*	<b>Legal values</b>:
	*	<br><tt>S_OK :</tt>   on Success
	* <br><tt>E_FAIL:</tt>  on failure
	*/
		virtual HRESULT AddElement(CATBaseUnknown* iElementToConvert) = 0;

	/**
		* Retrieves the list of geometric elements pointed by those belonging to the 
		*	conversion transaction.
		* <br><b>Role</b>: The "GetNecessaryElements" method enables to get the geometric
		*									 elements pointed by the applicative elements of the transaction.
		* @param oV4PointedElements
		*	The list of the V4 geometric elements, supports of the applicative elements.
		* These pointed elements will be migrated before the conversion of the applicative 
		*	elements.
		* @return
		*	<b>Legal values</b>:
		*	<br><tt>S_OK :</tt>   on Success
		* <br><tt>E_FAIL:</tt>  on failure
		*/
		virtual HRESULT GetNecessaryElements(CATLISTP(CATBaseUnknown)*& oV4PointedElements) = 0;

		/**
		* Run the conversion.
		* <br><b>Role</b>: The "Run" method enables to execute the global transaction 
		*									 corresponding to the Copy/Paste operation.
		* @param iGlobalTransaction
		*	The global transaction corresponding to the Copy/Paste operation. 
		* This will allow the applications to retrieve the mapping of the pointed 
		*	geometric elements.
		* @return
		*	<b>Legal values</b>:
		*	<br><tt>S_OK :</tt>   on Success
		* <br><tt>E_FAIL:</tt>  on failure
		*/
		virtual HRESULT Run( const CATIConversionTransaction* iGlobalTransaction ) = 0;

};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATIV4iTransaction, CATBaseUnknown ) ;

#endif
