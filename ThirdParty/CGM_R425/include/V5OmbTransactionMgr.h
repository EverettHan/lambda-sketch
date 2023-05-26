// COPYRIGHT DASSAULT SYSTEMES 2003

#ifndef V5OmbTransactionMgr_H
#define V5OmbTransactionMgr_H

/**
 * @level Private
 * @usage U1
 */

#include "AC0XXLNK.h"
#include "IUnknown.h" // for HResult


class V5OmbMonitorSession ;
class CATOmbTransaction ;
class CATOmbDocumentTransaction ;
class CATDocument ;

class ExportedByAC0XXLNK V5OmbTransactionMgr
{
 friend class V5OmbSession ;

 public :
   /**
	* Not Implemented : At this time there is one transaction identified by 0
	* The reason is that the upper layer of CATIA do not manage the Transaction
	* and considers that there is only one.
    * Enables to Create a Transaction with a name
	* At this time , there is 0 which corresponds to the 
	* transaction of Save/open of CATIA
	* Return Code possible: 
	* S_OK : done
	* E_FAIL :Error  
	*/
   HRESULT CreateTransaction(int& oIdentifierOfTheTransaction) ;
   HRESULT CloseTransaction(int& oIdentifierOfTheTransaction) ;


   /**
	* Create a Transaction with the Zero identifier 
	* Checks that the previous zero transaction has been closed
	* S_OK : done
	* E_FAIL :Error  
	*/   
   HRESULT CreateZeroTransaction() ;
   HRESULT CloseZeroTransaction() ;

   /**
    * Retrieves a Transaction by its identifier
	* Return Code possible : 
	* S_OK : done
	* E_FAIL : error 
	*     Cause of the error can be :
	*		 - iIdentifierOfTheTransaction does not exist
	*		 - other Error
	*/
   HRESULT FindTransactionByIdentifier(int iIdentifierOfTheTransaction,CATOmbTransaction*& oTransaction) ;
  
   HRESULT AddDocumentToTransactionByIdentifier(int iIdentifierOfTheTransaction,CATDocument* iDocument) ;
   HRESULT FindDocumentTransactionByIdentifierAndForDocument(int iIdentifierOfTheTransaction,CATDocument* iDocument,CATOmbDocumentTransaction*& DocTransaction) ;

 private :

   V5OmbTransactionMgr() ;
  ~V5OmbTransactionMgr() ;

   HRESULT MonitorInformation(const char* iInformation) ;
   CATOmbTransaction* zeroTransaction ;
} ;
#endif
