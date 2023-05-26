// COPYRIGHT Dassault Systemes 2002
//===================================================================
//
// CATP2PService.h
// Provide implementation to interface
//    CATIP2PService
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//CAA2 Wizard Generation Report
//   IMPLEMENTATION
//   TIE: CATIP2PPeer
//End CAA2 Wizard Generation Report
//
//  May 2002  Creation: Code generated by the CAA wizard  jnm
//===================================================================
#ifndef CATP2PService_H
#define CATP2PService_H

// COPYRIGHT DASSAULT SYSTEMES 2003



/**
 * @CAA2Level L0
 * @CAA2Usage U2
 */


#include "CATP2PCore.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATErrorDef.h"
#include "CATICommMsg.h"
#include "CATP2PDefs.h"
//
class CATIP2PMessage; 
class CATIBBStreamer;

//------------------------------------------------------------------

/**
 * Concrete class.
 * <b>Role</b>: P2P services base class.
 * To create your own service you have to derive this class.
 * It also provides you basic services.
 */

class ExportedByCATP2PCore CATP2PService: public CATBaseUnknown
{
  CATDeclareClass;

  public:

     CATP2PService ();
     virtual ~CATP2PService ();

/** 
 *  Initialization method.
 * <br><b>Role</b>: This method is called when the peer is created and allow you to initialize your service.
 *  If this method returns E_FAIL the service will be disable.
 */
	 virtual HRESULT Initialize() = 0;
	 
/** 
 *  Service naming method.
 * <br><b>Role</b>: This method must be implemented by your service to retrieve its identifier.
 * CATP2PServiceName is a string.
 */
	 virtual CATP2PServiceName GetServiceName() = 0; 

/** 
 *  Reception method.
 * <br><b>Role</b>: This method is called each time a message for your service arrives on the plateform.
 * In this method, you read the message and treat it.
 * @param iMess 
 *  received message
 */
	 virtual HRESULT HandleMessage(CATIP2PMessage* iMess)=0; 

/**
 * @nodoc
 */
	 void HandleMessage(CATICommMsg_var iMessage);
/**
 * @nodoc
 */
	 HRESULT FilterMessageFromGroup(CATUnicodeString& message_group);


  protected :

	  CATIBBStreamer* _streamer;

  private:
  // The copy constructor and the equal operator must not be implemented
  // -------------------------------------------------------------------
  CATP2PService (CATP2PService &);
  CATP2PService& operator=(CATP2PService&);

};

//-----------------------------------------------------------------------

#endif
