// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATIKweErrorManager.h
// Interface representing the way to manage parse and evaluation errors.
//
//===================================================================
#ifndef CATIKweErrorManager_H
#define CATIKweErrorManager_H

/** 
 * @CAA2Level L1
 * @CAA2Usage U3 
 */

#include "CATLifSpecs.h"
#include "CATBaseUnknown.h"

class CATUnicodeString;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATLifSpecs IID IID_CATIKweErrorManager;
#else
extern "C" const IID IID_CATIKweErrorManager ;
#endif

//------------------------------------------------------------------

/**
* Interface representing the way to manage parse and evaluation errors.
* This interface is mono implemented and accessible from @href CATCkeGlobalFunctions#GetErrorManager.
*/
class ExportedByCATLifSpecs CATIKweErrorManager: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

    /**
	 * If a method raises some Knowledge Error and you want to catch them, you need to call ErrorTry before and ErrorCatch or ErrorClean after.
     */
	 virtual void ErrorTry() =0;

	/** 
	* Behavior when catching or cleaning the error.
	*	<ol>
	*	Popup: triggers a popup window displaying the message (or a trace in batch mode).
	*	Silent: simply erase the error from the manager.
	*	Forward: Forward the error to an upper error manager.
	*	</ol>
	*/
	  enum Behavior {
						Popup	= 1, 
						Silent	= 2,
						Forward = 4, 
					};	
	
	
	/** 
	 *  Cleans the error if any and treat it depending on the behavior required.
	 *	@param iBehavior behavior requested at the end of the clean operation.
	 *  @return number of error raised (0 if none).
	*/
     virtual int ErrorClean (const CATIKweErrorManager::Behavior &iBehavior) =0;	 

	/** 
	 * Type of error we want to catch.
	 *	<ol>
	 *	All: we want to catch evaluation error, parse error or magnitude consistency checking.
	 *	Parse: we want to catch only parse error.
	 *	MagnitudeConsistency: we want to catch only  magnitude consistency errors
	 *	Evaluation: we want to catch only evaluation error.
	 *	</ol>
	 */
	  enum Filter {
						All	= 0, 
						Parse	= 1,
						MagnitudeConsistency	= 2,
						Evaluation = 3, 
					};	

	  /**  
  	   * Severity of error.
	 *	<ol>
	 *	Error: the treatment has failed.
	 *	Warning: the treatment has not failed.
	 *	</ol>
	 */
	  enum Severity {
						Error	= 1, 
						Warning	= 2 
					};	

	/** 
	 *  Catches the error if any and treat it depending on the behavior required.
	 *	@param iFilter kind of error we want to catch.
	 *	@param iBehavior behavior requested at the end of the clean operation.
	 *	@param oMessage message of the error if any.
	 *  @param oLineNumber line number where error occurred
	 *  @param oSeverity severity of the error
	 *  @return number of error raised (0 if none).
	*/
     virtual int ErrorCatch (const CATIKweErrorManager::Filter &iFilter, 
							 const CATIKweErrorManager::Behavior &iBehavior,	 
							 CATUnicodeString &oMessage,
							 int &oLineNumber,
							 CATIKweErrorManager::Severity &oSeverity
							 ) =0;	 

};

//------------------------------------------------------------------
CATDeclareHandler(CATIKweErrorManager,CATBaseUnknown);

#endif
