#ifndef INCL_IConnectionPointContainer_h
#define INCL_IConnectionPointContainer_h

#ifdef _WINDOWS_SOURCE
#pragma once
#include <olectl.h>
#else
#include "IUnknown.h"

class IEnumConnectionPoints;
class IConnectionPoint;

//
// COPYRIGHT DASSAULT SYSTEMES  1999
//=============================================================================
// Jul. 99   Creation
//=============================================================================
//
/**
 * The IConnectionPointContainer interface indicates the existence of outgoing 
 * interfaces. Each type of outgoing interface is handled by a connection point
 * object. The container gives access to these connection points.
 */

class IConnectionPointContainer : public IUnknown {
	public:
		/**
		 * Returns an enumerator which enumerates all the connection points
		 * supported by the container.
		 */
		virtual HRESULT __stdcall EnumConnectionPoints(
			IEnumConnectionPoints **oPpenum	// Address of output variable that 
											// receives the IEnumConnectionPoints 
											// interface pointer
		) = 0;

		/**
		 * Retrieves the connection point for a given outgoing interface.
		 */
		virtual HRESULT __stdcall FindConnectionPoint(
			REFIID riid,				// Requested connection point's interface identifier
			IConnectionPoint **ppCP		// Address of output variable that receives the 
										// IConnectionPoint interface pointer
		) = 0;
};

/* B196B284-BAB4-101A-B69C-00AA00341D07 */
extern "C" const IID IID_IConnectionPointContainer;

#endif



/* This macro can be used by event publisher implementors to
 implement dispatch loops. 
 + The first parameter is the name of the event interface implemented 
 by the subscribers. (ex: IMyEvents)
 + The second parameter is the method to call in the event interface
 along with all its parameters (ex: mouseClicked(x, y) ) */

#define ICONNECTION_POINT_DISPATCH(INTERFACE, METHOD)			\
  /* Retrieve the IConnectionPointContainer interface.*/		\
  IConnectionPointContainer *_icpc = NULL;				\
  HRESULT _hr = QueryInterface(IID_IConnectionPointContainer, (void **)&_icpc);	\
  if (SUCCEEDED(_hr)) {							\
    									\
    /* Retrieve the CATIEventListener1 connection point. */		\
    IConnectionPoint *_icp = NULL;					\
    _hr = _icpc->FindConnectionPoint(IID_##INTERFACE, &_icp);		\
    if (SUCCEEDED(_hr) && _icp != NULL) {				\
      									\
      /* Retrieve the connection enumerator. */				\
      IEnumConnections* _iec = NULL;					\
      _hr = _icp->EnumConnections(&_iec);				\
      									\
      /* Dispatch loop. */						\
      CONNECTDATA* _connection = new CONNECTDATA[1];			\
      while(1) {							\
	_hr = _iec->Next(1, _connection, NULL);				\
	if (_hr != S_OK) {						\
	  break;							\
	}								\
	_hr = ((INTERFACE*)(_connection->pUnk))->METHOD;		\
	if (!SUCCEEDED(_hr)) {						\
	  break;							\
	}								\
	_connection->pUnk->Release();					\
	break;								\
      }									\
      									\
      /* Cleanup. */							\
      _icp->Release();							\
      _iec->Release();							\
    }									\
    _icpc->Release();							\
  }

#endif
