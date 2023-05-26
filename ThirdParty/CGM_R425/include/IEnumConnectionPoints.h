#ifndef INCL_IEnumConnectionPoints_h
#define INCL_IEnumConnectionPoints_h

#ifdef _WINDOWS_SOURCE
#pragma once
#include <olectl.h>
#else
#include "IUnknown.h"

class IConnectionPoint;

//
// COPYRIGHT DASSAULT SYSTEMES  1999
//=============================================================================
// Jul. 99   Creation
//=============================================================================
//
/**
 * This interface enumerates IConnectionPoints.
 */

class IEnumConnectionPoints : public IUnknown {
	public:
		/**
		 * Retrieves the next iCelt items in the enumeration sequence. If 
		 * there are fewer than the requested number of elements left in the 
		 * sequence, it retrieves the remaining elements. The number of 
		 * elements actually retrieved is returned through oPceltFetched 
		 * (unless the caller passed in NULL for that parameter).
		 * The reference count of each item returned is increased, so it
		 * it up to the caller to release it.
		 */
		virtual HRESULT __stdcall Next(
			ULONG iCelt,
			IConnectionPoint **oRgelt,
			ULONG *oPceltFetched
		) = 0;
    
		/**
		 * Skips over the next specified number of elements in the enumeration
		 * sequence.
		 */
		virtual HRESULT __stdcall Skip(
			ULONG iCelt
		) = 0;
    
		/**
		 * Resets the enumeration sequence to the beginning.
		 */
		virtual HRESULT __stdcall Reset() = 0;

		/**
		 * Creates another enumerator that contains the same enumeration state 
		 * as the current one. Using this function, a client can record a 
		 * particular point in the enumeration sequence, and then return to 
		 * that point at a later time. The new enumerator supports the same 
		 * interface as the original one.
		 */
		virtual HRESULT __stdcall Clone(
			IEnumConnectionPoints **oPpenum
		) = 0;    
};

/* B196B285-BAB4-101A-B69C-00AA00341D07 */
extern "C" const IID IID_IEnumConnectionPoints;

#endif
#endif
