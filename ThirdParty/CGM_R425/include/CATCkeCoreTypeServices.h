// COPYRIGHT Dassault Systemes 2010
//===================================================================
//
// CATCkeCoreTypeServices.h
// Header definition of CATCkeCoreTypeServices
//
//===================================================================
//
// Usage notes:
// Provides services to match CATIType and PLM Core Types
//
//===================================================================



#ifndef CATCkeCoreTypeServices_H
#define CATCkeCoreTypeServices_H

// Module export
#include "CATLifSpecs.h"
#include "IUnknown.h"
#include "CATBoolean.h"
#include "CATListOfCATUnicodeString.h"

class CATICkeObject_var;
class CATUnicodeString;

/**
 * Services to make a relationship between a CATIType and a core type...
 */
class ExportedByCATLifSpecs CATCkeCoreTypeServices
{

  public:

    /**
	 * Enumerated value that defines the list of core types .<br>
	 */
	  enum CkeCoreType { PLMCkeCoreReference=0,
						 PLMCkeCoreInstance=1,
						 PLMCkeCoreRepReference=2,
						 PLMCkeCoreRepInstance=3,
						 PLMCkeConnection=4,
						 PLMCkePort=5,
						 PLMCkeBusinessType=6,
						 PLMCkeRelationType=7,
	  }; 
	
	// Internal
	static CATListOfCATUnicodeString CkeCoreTypeAsStrings ();
	static CATUnicodeString CkeCoreTypeAsString (const CkeCoreType iCoreType);
	static HRESULT CkeCoreTypeFromString (const CATUnicodeString &s, CkeCoreType &oOperation);

};

//-----------------------------------------------------------------------

#endif
