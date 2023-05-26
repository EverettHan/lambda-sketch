#ifndef INCL_IConnectionPoint_h
#define INCL_IConnectionPoint_h

#ifdef _WINDOWS_SOURCE
#pragma once
#include <olectl.h>
#else
#include "IUnknown.h"

class IEnumConnections;
class IConnectionPointContainer;

//
// COPYRIGHT DASSAULT SYSTEMES  1999
//=============================================================================
// Jul. 99   Creation
//=============================================================================
//
/**
 * The IConnectionPoint interface stores pointers to clients which are interested
 * in being notified when certain types of events occur. The clients must all implement
 * an interface (the connection interface) and register themselves to the connection
 * point using this interface.
 */

class IConnectionPoint : public IUnknown {
	public:

		/**
		 * Establishes a connection between the connection point object and the 
		 * client's sink.
		 */
		virtual HRESULT __stdcall Advise(
			IUnknown *pUnk,			// Pointer to the client's advise sink
			ULONG *pdwCookie	// Pointer to the connection point identifier used 
									// by Unadvise
		) = 0;

		/**
		 * Creates an enumerator object to iterate through the current connections 
		 * for this connection point.
		 */
		virtual HRESULT __stdcall EnumConnections(
			IEnumConnections **oPpenum	// Address of output variable that 
										// receives the IEnumConnections interface 
										// pointer
		) = 0;

		/**
		 * Returns the IID of the outgoing interface managed by this connection point.
		 */
		virtual HRESULT __stdcall GetConnectionInterface(
			IID *pIID	// Pointer to an IID variable
		) = 0;

		/**
		 * Retrieves the IConnectionPointContainer interface pointer for 
		 * the parent connectable object.
		 */
		virtual HRESULT __stdcall GetConnectionPointContainer(
			IConnectionPointContainer **ppCPC	// Address of output variable that receives
												// the IConnectionPointContainer interface pointer
		) = 0;

		/**
		 * Terminates an advisory connection previously established through 
		 * IConnectionPoint::Advise. The dwCookie parameter identifies the 
		 * connection to terminate.
		 */
		virtual HRESULT __stdcall Unadvise(
			ULONG dwCookie  // Connection token
		) = 0;
};

/* B196B286-BAB4-101A-B69C-00AA00341D07 */
extern "C" const IID IID_IConnectionPoint;

/**
 * HRESULT values.
 */


#define SEVERITY_ERROR 1
#define FACILITY_ITF   4
#define MAKESCODE(sev,fac,code) \
 (((ULONG)(sev)<<31) | ((ULONG)(fac)<<16) | ((ULONG)(code)))

#define CONNECT_E_FIRST    MAKESCODE(SEVERITY_ERROR,   FACILITY_ITF, 0x0200)

#define CONNECT_E_NOCONNECTION      (CONNECT_E_FIRST+0)
// there is no connection for this connection id

#define CONNECT_E_ADVISELIMIT       (CONNECT_E_FIRST+1)
// this implementation's limit for advisory connections has been reached

#define CONNECT_E_CANNOTCONNECT     (CONNECT_E_FIRST+2)
// connection attempt failed

#define CONNECT_E_OVERRIDDEN        (CONNECT_E_FIRST+3)
// must use a derived interface to connect


#endif
#endif

