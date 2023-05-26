// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATIModelUndoRedoManager.h
// Define the CATIModelUndoRedoManager interface
//
//===================================================================
//
// Usage notes:
//   New interface: Interface to manage Model_UndoRedoEngine.
//   Only CATUndoRedoEngine can use this interfaces
//
//===================================================================
//  July 2006  Creation: RJS
//===================================================================

/**
* @level Protected
* @usage U3
*/

#ifndef CATIModelUndoRedoManager_h
#define CATIModelUndoRedoManager_h


#include "CATBaseUnknown.h"
#include "AD0XXBAS.h"
#include "CATBoolean.h"
#include "CATDataType.h"
#include "CATOmbUndoRedoDefs.h"
class CATError;
#ifndef LOCAL_DEFINITION_FOR_IID
extern "C" ExportedByAD0XXBAS IID IID_CATIModelUndoRedoManager;
#else
extern "C" const IID IID_CATIModelUndoRedoManager ;
#endif
//------------------------------------------------------------------

/**
* Interface to manage Undo/Redo operations during a working session.
*
* <br><b>Role</b>: Be able to manage Undo/Redo operations on PLMModel.
* <p>
*/
class CATEModelUndoRedoManager;
class ExportedByAD0XXBAS CATIModelUndoRedoManager : public CATBaseUnknown
{
  CATDeclareInterface;
public:
  /**
  * Open a new transaction and commit the previous one if it exists.
  *	@param iContext
  *		The context when requesting the transaction.
  *	@param oErrorId
  *		Typed informations if an error is detected.
  *	@return
  *		An integer value:
  *   <br><b>Legal values</b>:
  *   <dl>
  *     <dt><tt>-1</tt></dt>
  *     <dd>if an error is detected</dd>
  *     <dt><tt>0</tt></dt>
  *     <dd>it is Model_UndoRedoEngine ZERO transaction</dd>
  *     <dt><tt>positve integer</tt></dt>
  *     <dd>the identifier of opened transaction requested</dd>
  *   </dl>
  */
  virtual int NewTransaction(OmbUndoRedoContext& iContext, OmbUndoRedoErrorId& oErrorId)=0;

  /**
  * Replay backward a stack transactions.
  *	@param iFrom
  *		The top of the stack of transactions.
  *	@param iTo
  *		The bottom of the stack of transactions.
  *	@param oErrorId
  *		Typed informations if an error is detected and S_OK is not returned.
  *	@return
  *		An HRESULT value:
  *   <br><b>Legal values</b>:
  *   <dl>
  *     <dt><tt>S_OK</tt></dt>
  *     <dd>the operation is succesful</dd>
  *     <dt><tt>S_FALSE</tt></dt>
  *     <dd>the operation has already been performed on the current stack</dd>
  *     <dt><tt>E_FAIL</tt></dt>
  *     <dd>the operation failed</dd>
  *   </dl>
  */
  virtual HRESULT UndoTransactions(unsigned int iFrom, unsigned int iTo, OmbUndoRedoErrorId& oErrorId)=0;

  /**
  * Replay forward a queue of transactions.
  *	@param iFrom
  *		The bottom of the queue of transactions.
  *	@param iTo
  *		The top of the queue of transactions.
  *	@param oErrorId
  *		Typed informations if an error is detected and S_OK is not returned.
  *	@return
  *		An HRESULT value:
  *   <br><b>Legal values</b>:
  *   <dl>
  *     <dt><tt>S_OK</tt></dt>
  *     <dd>the operation is succesful</dd>
  *     <dt><tt>S_FALSE</tt></dt>
  *     <dd>the operation has already been performed on the current queue</dd>
  *     <dt><tt>E_FAIL</tt></dt>
  *     <dd>the operation failed</dd>
  *   </dl>
  */
  virtual HRESULT RedoTransactions(unsigned int iFrom, unsigned int iTo, OmbUndoRedoErrorId& oErrorId)=0;

  /**
  * Delete a queue of transactions.
  *	@param iFrom
  *		The bottom of the queue of transactions.
  *	@param iTo
  *		The top of the queue of transactions.
  *	@param oErrorId
  *		Typed informations if an error is detected and S_OK is not returned.
  *	@return
  *		An HRESULT value:
  *   <br><b>Legal values</b>:
  *   <dl>
  *     <dt><tt>S_OK</tt></dt>
  *     <dd>the operation is succesful</dd>
  *     <dt><tt>S_FALSE</tt></dt>
  *     <dd>the operation has already been performed on the current queue</dd>
  *     <dt><tt>E_FAIL</tt></dt>
  *     <dd>the operation failed</dd>
  *   </dl>
  */
  virtual HRESULT DeleteTransactions(unsigned int iFrom, unsigned int iTo, OmbUndoRedoErrorId& oErrorId)=0;

  /**
  * Concatenate a list of transactions.
  * All concatenated transactions are deleted except iTarget.
  *	@param iFrom
  *		The begining of the list of transactions.
  *	@param iTarget
  *		The target of merge and also the end of the list of transactions.
  *	@param oErrorId
  *		Typed informations if an error is detected and S_OK is not returned.
  *	@return
  *		An HRESULT value:
  *   <br><b>Legal values</b>:
  *   <dl>
  *     <dt><tt>S_OK</tt></dt>
  *     <dd>the operation is succesful</dd>
  *     <dt><tt>S_FALSE</tt></dt>
  *     <dd>the operation has already been performed on the current list</dd>
  *     <dt><tt>E_FAIL</tt></dt>
  *     <dd>the operation failed</dd>
  *   </dl>
  */
  virtual HRESULT ConcatenateTransactions(unsigned int iFrom, unsigned int iTarget, OmbUndoRedoErrorId& oErrorId)=0;

  /**
  * Check whether a transaction contains modifications.
  *	@param iTransactionNumber
  *		The identifier of transaction.
  *	@return
  *		An boolean value:
  *   <br><b>Legal values</b>:
  *   <dl>
  *     <dt><tt>FALSE</tt></dt>
  *     <dd>if transaction contains at least one transaction</dd>
  *     <dt><tt>TRUE</tt></dt>
  *     <dd>if there is no transaction</dd>
  *   </dl>
  */
  virtual CATBoolean IsEmptyTransaction(unsigned int iTransactionNumber)=0;

  /**
  * Set UndoRedo mode.
  *	@param iMode
  *		The current mode.
  *	@return
  *		An boolean value:
  *   <br><b>Legal values</b>:
  *   <dl>
  *     <dt><tt>TRUE</tt></dt>
  *     <dd>operation succeeded</dd>
  *     <dt><tt>FALSE</tt></dt>
  *     <dd>operation failed</dd>
  *   </dl>
  */
  virtual CATBoolean SetMode(OmbUndoRedoMode iMode)=0;

	/**
	 * Get UndoRedo mode.
	 * @return
	 *   The OmbUndoRedoMode.
	 */
	virtual OmbUndoRedoMode GetMode()=0;
  /**
  * Return related CATError according to ErrorId
  * @param iErrorId
  *   The Id of error
  * @return
  *     A CATError.
  */
  virtual CATError* GetReportedError(OmbUndoRedoErrorId iErrorId)=0;
  /**
  * Casting Method to dynamically and quickly obtain a type-safe reference to a subclass in an inheritance hierarchy
  * Private to SessionUndoCore
  */
  virtual CATEModelUndoRedoManager* GetModelUndoRedoManager()=0;
};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler(CATIModelUndoRedoManager, CATBaseUnknown);


#endif
