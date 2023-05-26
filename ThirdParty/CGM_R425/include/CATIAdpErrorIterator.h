/* -*-c++-*- */
/**
* @level Protected
* @usage U1  
*/
//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2008
//-----------------------------------------------------------------------------
//
// class CATIAdpErrorIterator.h
//
// Handle dedicated to the scan of all errors raised by a (series) 
// of PLM action(s) enabled to collect errors (Engines, AdpServices, ..)
// 
//-----------------------------------------------------------------------------
// 04/07/2008 Creation                                                     VCS
//-----------------------------------------------------------------------------
#ifndef CATIAdpErrorIterator_H
#define CATIAdpErrorIterator_H

#include "CATPLMIntegrationAccess.h"
//#include "CATAdpErrorIteratorRestricted.h"
#include "CATIAdpPLMErrorIterator.h"
#include "CATBaseUnknown.h"

class CATIAdpErrorCell;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationAccess IID IID_CATIAdpErrorIterator;
#else
extern "C" const IID IID_CATIAdpErrorIterator ;
#endif

/**
* Interface intended to scan and read errors logged by an Error Monitor.
* <br><b>Role</b>: Scans sequentially and Reads errors logged by a given Error Monitor.
* The errors can be eventually filtered by a given input criterium
* <p>
* For use only - This interface cannot be re-implemented by applications using it.
*/

class ExportedByCATPLMIntegrationAccess CATIAdpErrorIterator: public CATIAdpPLMErrorIterator
{
	CATDeclareInterface;

public:

	/**
	* 
	Resets iterator for a new iteration on the list
	* <br><b>Role:</b> Resets iterator for a new iteration on the list content at the Iterator CREATION TIME.
	* @return
	*		 S_OK : Reset successfull
	* <br> E_FAIL : Reset failed
	*/
	virtual HRESULT Reset()= 0;

	/**
	* Resets iterator for a new iteration on the list
	* <br><b>Role:</b> Resets iterator for a new iteration on the CURRENT list content 
	* @return
	*		 S_OK : Reset successfull
	* <br> E_FAIL : Reset failed
	*/
	virtual HRESULT SetToCurrent()= 0;

	/**
	* Iterates on the Next Error Cell in the list
	* <br><b>Role:</b> Iterates on the next Error Cell in the list, allways scanned from the first error pushed in ErrorMonitor to the last one.
	* The first call returns the first cell in list.
	* Hidden errors are not shown (@see CATIAdpErrorCell#HideError).
	* The scan of the list ends normally when this method returns a NULL pointer with a S_OK return code.
	* As an AddRef is performed on each Error Cell returned by this method, a Release is to be done by user after Error Cell use.
	* @param opErrorCell [out, CATBaseUnknown#Release]
	*        The Error cell read by the iterator.
	*        It must be released after use. NULL when the last Error Cell has already been reached.
	* @return
	*		 S_OK : iteration successfull
	* <br> E_FAIL : iteration failed
	*/
	virtual HRESULT Next(CATIAdpErrorCell* & opErrorCell)= 0;
};

//-----------------------------------------------------------------------------
CATDeclareHandler(CATIAdpErrorIterator, CATBaseUnknown);
#endif
