#ifndef INCL_IEnumString_h
#define INCL_IEnumString_h

#ifdef _WINDOWS_SOURCE
#pragma once
#include <objidl.h>
#else
#include "IUnknown.h"
#include <wchar.h>

//
// COPYRIGHT DASSAULT SYSTEMES  1999
//=============================================================================
// Jul. 99   Creation
//=============================================================================
//
/**
 * This interface enumerates NLS strings (wchar_t*).
 */

class IEnumString : public IUnknown {
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
			unsigned long iCelt,
			wchar_t **oRgelt,
			unsigned long *oPceltFetched
		) = 0;
    
		/**
		 * Skips over the next specified number of elements in the enumeration
		 * sequence.
		 */
		virtual HRESULT __stdcall Skip(
			unsigned long iCelt
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
			IEnumString **oPpenum
		) = 0;    
};

/* 00000101-0000-0000-C000-000000000046 */
extern "C" const IID IID_IEnumString;

#endif
#endif
