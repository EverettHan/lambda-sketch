/**
 * @level Private
 * @usage U1
 */
 /* -*-C++-*-*/
 // COPYRIGHT DASSAULT SYSTEMES 1997
 //===================================================================
 //
 // CATKWEErrorManager:
 //===================================================================
 // Feb.   1999  Creation                         P. Grignon (PPG) 
 //===================================================================
#ifndef CATKWEErrorManager_h
#define CATKWEErrorManager_h

// BSFBuildtimeData
#include "CATIAV5Level.h"
// System
#include "CATBaseUnknown.h"
// LiteralFeatures
#include "CATKWEError.h"
#include "CATKWEErrorManagerBase.h"

#if !defined(CATIAR201)
#include "CATLifToolkit.h"
#endif

class CATLifErrorManager;

/** The CATKWEErrorManager.<br>
*  This class is a Singleton.<br>
*
*  WARNING !!<br>
* The instance is deleted by Knowledgeware only.
*/
#if defined(CATIAR201)
class ExportedByCATLifDictionary CATKWEErrorManager : public CATKWEErrorManagerBase
#else
class ExportedByCATLifToolkit CATKWEErrorManager : public CATKWEErrorManagerBase
#endif
{
public:
  CATDeclareClass;

  //	To get the only instance of this class.
  static CATKWEErrorManager* Instance();

  //	To delete the only instance of this class. NOT TO BE CALLED BY ANYBODY.
  static void Delete();

protected:
  CATKWEErrorManager();
  virtual ~CATKWEErrorManager();

  static CATLifErrorManager * _instance;
};
#endif


