/**
 * @level Protected
 * @usage U1
 */

 /* -*-C++-*-*/
 // COPYRIGHT DASSAULT SYSTEMES 1999
 //===================================================================
 //
 // CATKWEErrorManagerBase:
 // This class is a singleton.
 //===================================================================
 // Feb.   1999  Creation                         P. Grignon (PPG) 
 //===================================================================
#ifndef CATKWEErrorManagerBase_h
#define CATKWEErrorManagerBase_h

// BSFBuildtimeData
#include "CATIAV5Level.h"
// System
#include "CATBaseUnknown.h"
#include "CATCallbackManager.h"
#include "CATListPV.h"
#include "CATNotification.h"
// LiteralFeatures
#include "CATEventBus.h"
#include "CATKWEError.h"

#if !defined(CATIAR201)
#include "CATLifToolkit.h"
#endif


/** The CATKWEErrorManagerBase<br>
* This class is the base class for implementing a try/catch mecanism.<br>
*
*  This class is used with only four methods:<br>
*  <ol>
*	1. ErrorTry() is used to open an error session.<br>
*	2. ErrorThrow() is used to throw an error (CATKWEError).
*	3. ErrorCatch() is used to catch the errors coming from lower level error sessions.
*	4. ErrorClean() is used to close the error session. Always to be used to balance an <br>
*	ErrorTry().
* </ol>
*  WARNING !!<br>
* The manager is deleted by Knowledgeware only. <br>
*
* Advanced use:<br>
* You can put the manager into 'sleep mode' by using ErrorManagerSleep().<br>
* This overriddes the default catching behavior of the errors. The errors
* are then placed into a 'garbage' and can be only be retrieved by<br>
* ErrorSearch().<br>
* @see CATKWEError
* @see CATLifError
* @see CATKWEErrorManager
* @see CATLifErrorManager
*/
#if defined(CATIAR201)
class ExportedByCATLifDictionary CATKWEErrorManagerBase : public CATBaseUnknown
#else
class ExportedByCATLifToolkit CATKWEErrorManagerBase : public CATBaseUnknown
#endif
{
  CATDeclareClass;

public:
  enum Behavior
  {
    Popup = 1,
    Silent = 2,
    Forward = 4,
    Factorize = 8
  };

  /**
  *	Catch an all the errors of the type iErrorType, matching the source iSource and execute a default<br>
  *   behavior dictated by iBehavior<br>.
  *
  *   @param iErrorType the type of the error.
  *   @param iBehavior the behavior.<br>
  *	enum Behavior { Popup	= 1, Silent	= 2, Forward = 4, Factorize = 8 };<br>
  *	<ol>
  *	Popup: triggers a popup window displaying the message.
  *	Silent: simply erase the error from the manager.
  *	Forward: Forward the error to an upper error manager.
  *	Factorize: trigger a single error if several are equilalent. (see CATKWEError for the equivalence definition).
  *	</ol>
  *	@param iSource the source of the error. Set to NULL_var means that all the sources must be caught.
  *	@see CATKWEErrorManagerBase
  *	@see CATKWEError
*/
  virtual int ErrorCatch(char const *	iErrorType, int	iBehavior = CATKWEErrorManagerBase::Silent, CATBaseUnknown_var iSource = NULL_var);

  /**
  *	Begin to record the errors.
*/
  virtual void ErrorTry();

  /**
  * Raise an error.
  */
  void ErrorThrow(CATKWEError const * iError);

  /**
  *	Removes all the errors from the current buffer and deal with them <br>
  * using the iBehavior.
  * @param iBehavior the behavior with which all the errors remaining in the buffer<br.
  * must be dealt with.
  * @return the number of errors forwarded.
  */
  virtual int ErrorClean(int iBehavior);

  virtual int ErrorSearch(CATListPV &	oList, char const *	iErrorType = CATKWEError::ClassName(), CATBaseUnknown_var	iSource = NULL_var);

  /**
  *	Put the ErrorManager in a Silent Mode. Catching the errors does not produce any <br>
  *	visual effects (no popup window) except that they are saved for later use (ErrorSearch for example).<br>
  *  @return 0 if the Errormanager was already in sleep mode. 1 otherwise.
*/
  virtual int ErrorManagerSleep();

  /**
  *	Put the ErrorManager in a Active Mode. Catching the errors does produce a popup if required. <br>
  * @return 0 if the Errormanager was already in active mode. 1 otherwise.
  */
  virtual int ErrorManagerWakeUp(CATListPV * oList, int iBehavior = CATKWEErrorManagerBase::Silent);

  /**
  * Returns the message linked to the error.
  * @param iDetails = 0 for number of errors and buffers only, 1 for the list of all the errors.
  */
  virtual CATUnicodeString const ErrorManagerDump(int iDetails = 0) const;

protected:
  CATKWEErrorManagerBase();
  virtual ~CATKWEErrorManagerBase();

  /**
  * Store the error for delayed handling, Protected Method.
  *	@param iErrorToRegister A pointer toward a CATKWEError.
  */
  void StoreError(CATKWEError const * iErrorToRegister);

  /**
  * Forward the error to the next error buffer if the latter exists, Protected Method.
  *	@param iErrorToForward A pointer toward a CATKWEError.
  */
  void ForwardError(CATKWEError const * iErrorToForward);

  /**
  * Initialize data structures. To be used by constructors, Protected Method.<br>
  */
  void Init();

  /**
  *	Erase the error from the manager, Protected Method.
  *	@param iErrorToRemove A pointer toward a CATKWEError.
  */
  void RemoveError(CATKWEError const * iErrorToRemove, int iBehavior);

  /**
  *	Execute the desired behavior, Protected Method.
  *	@param iError A pointer toward a CATKWEError.
  *	@param iBehavior The behavior triggered by the error.
  */
  void ExecuteErrorBehavior(CATKWEError const *	iError, int	iBehavior);

  /**
  *	To stack the errors in the garbage if the catching behavior of the
  * error manager is overridden using the ErrorManagerSleep() function.
  * The error manager can be made active using the ErrorManagerWakeUp()
  *	@param iError A pointer toward a CATKWEError.
  *	@param iBehavior The behavior triggered by the error.
*/
  void PutErrorInOverriddenGarbage(CATKWEError const * iErrorToGarbage);


private:
  void EmptyGarbage();

protected:
  CATListPV * m_currentErrorBuffer;

private:
  CATListPV m_errorBuffers;
  CATListPV m_overriddenGarbage;
  bool m_sleepMode;
};
#endif


