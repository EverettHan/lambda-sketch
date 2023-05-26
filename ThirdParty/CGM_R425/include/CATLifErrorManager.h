/**
 * @level Protected
 * @usage U1
 */

 /* -*-C++-*-*/
 // COPYRIGHT DASSAULT SYSTEMES 1999
 //===================================================================
 //
 //CATLifErrorManager:
 // This class is a singleton.
 //===================================================================
 // Feb.   1999  Creation                         P. Grignon (PPG) 
 //===================================================================
#ifndef CATLifErrorManager_h
#define CATLifErrorManager_h

// BSFBuildtimeData
#include "CATIAV5Level.h"
// System
#include "CATBaseUnknown.h"
#include "CATCallbackManager.h"
#include "CATListPV.h"
#include "CATNotification.h"
// LiteralFeatures
#include "CATKWEError.h"
#include "CATKWEErrorManager.h"

#if !defined(CATIAR201)
#include "CATLifToolkit.h"
#endif

/** The CATLifErrorManagerBase<br>
*  This class is a Singleton : there exists only one instance of the manager.<br>
*  WARNING !!<br>
* The manager is detroyed by LiteralFeature only. <br>
*
*  This class is used with only four methods: <br>
*  <ol>
*	1. ErrorTry() is used to open an error session.<br>
*	2. ErrorThrow() is used to throw an error (CATKWEError).<br>
*	3. ErrorCatch() is used to catch the errors coming from lower level error sessions.<br>
*	4. ErrorClean() is used to close the error session.<br>
* </ol>
* See examples for correctly usig this class<br>
*
* @see CATKWEError
* @see CATKWEErrorManager
*/
#if defined(CATIAR201)
class ExportedByCATLifDictionary CATLifErrorManager : public CATKWEErrorManager
#else
class ExportedByCATLifToolkit CATLifErrorManager : public CATKWEErrorManager
#endif
{
public:
  enum LifBehavior { Popup = CATKWEErrorManagerBase::Popup, Silent = CATKWEErrorManagerBase::Silent, Forward = CATKWEErrorManagerBase::Forward, Factorize = 8 };

  // Same as ErrorCatch but triggers the behavior only once for all errors of the same type.
  virtual int ErrorCatchOneShot(char const * iErrorType, int iBehavior = CATKWEErrorManagerBase::Silent, CATBaseUnknown_var	const & iSource = NULL_var);

  // Return the only instance of the Error manager.
  static CATLifErrorManager * Instance();

  //	To delete the instance of the manager. NOT TO BE USED BY ANYBODY.
  static void Delete();

private:
  CATLifErrorManager();
  virtual ~CATLifErrorManager();
};
#endif


