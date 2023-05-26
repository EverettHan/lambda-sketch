#ifndef INCL_CATIConnectionPointContainerInit_h
#define INCL_CATIConnectionPointContainerInit_h

#include "IUnknown.h"

//
// COPYRIGHT DASSAULT SYSTEMES  1999
//=============================================================================
// Jul. 99   Creation
//=============================================================================
//
/**
 * This private interface must be implemented by CAA2 objects which want to be
 * be IConnectionPointContainers. It is used to initialize IConnectionPointContainerImpl,
 * the generic IConnectionPointContainer implementation used throughout DS.
 * It lets developers specify which IIDs the IConnectionPointContainer is going
 * to support.
 */


class CATIConnectionPointContainerInit : public IUnknown {
	public:
		/**
		 * Returns the number of connexions points supported by the IConnectionPointContainer.
		 */
		virtual HRESULT __stdcall Count(
			unsigned long *oCount
		) = 0;

		/**
		 * Returns the IID of the iIndex-th connection point.
		 */
		virtual HRESULT __stdcall GetConnectionPointIID(
			unsigned long iIndex,
			IID* pIID
		) = 0;

};

/* 3fe589a8-3ebd-11d3-b802-0008c70fc870 */
extern "C" const IID IID_CATIConnectionPointContainerInit;

#endif
