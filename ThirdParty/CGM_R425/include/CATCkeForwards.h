/**  	   	   	 
* @level Protected 	  	  	 
* @usage U1 	  	  	 
*/

// Copyright Dassault Systemes 2000
#ifndef CATCkeForwards_h
#define CATCkeForwards_h
//////////////////////////////////////////////////////////////////////////
//
//
//	Cke Adapter Implementations
// 	declaration of CATCkeContext forwards
//
//
//////////////////////////////////////////////////////////////////////////


// streams
class CATCkeStream;
class CATCkeOStream;

// Context forwards

// implementation-dependant forwards. tmp
class CATCkeSdmFactory;
class CATCkeUsrFactory;
typedef CATCkeSdmFactory* CATCkeSdmFactoryH;
typedef CATCkeUsrFactory* CATCkeUsrFactoryH;

class CATCkeException;
class CATCkeAssertFailed;
class CATCkeNotYetImplemented;
class CATCkeBoundError;
class CATCkeInvalidType;
class CATCkeInvalidName;
class CATCkeConstObject;
class CATCkeUnderlyingError;

#endif



