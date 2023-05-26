/* -*-c++-*- */
/**
* @level Protected
* @usage U3 
*/
//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2011
//-----------------------------------------------------------------------------
//
// class PLMIBLErrorIterator.h
//
// Handle dedicated to provide to the list of attribute 
// on which there are some truncation problems according to knowledge dictionary rules
// 
// 
//-----------------------------------------------------------------------------
// 24/05/2011 Creation                                                     ECN
//-----------------------------------------------------------------------------
#ifndef PLMIBLErrorIterator_H
#define PLMIBLErrorIterator_H

#include "PLMBusinessLogicInterfaces.h"
#include "CATBaseUnknown.h"

class CATUnicodeString;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByPLMBusinessLogicInterfaces IID IID_PLMIBLErrorIterator;
#else
extern "C" const IID IID_PLMIBLErrorIterator ;
#endif



//-----------------------------------------------------------------------------

/**
* Interface intended to scan and read errors logged by an Error Monitor.
* <br><b>Role</b>: Scans sequentially and Reads errors logged by a given Error Monitor.
* The errors can be eventually filtered by a given input criterium
* <p>
* For use only - This interface cannot be re-implemented by applications using it.
*/

class ExportedByPLMBusinessLogicInterfaces PLMIBLErrorIterator: public CATBaseUnknown
{
	CATDeclareInterface;

public:

	
/**
 * Returns the next attribute on which a truncation is needed on its valuation.
 *
 * <br><b>Role</b>: Access to the next attribute on which a truncation is needed on its valuation.
 *
 * @param ioPosition [inout]
 *   On input, it's the index of the attribute (specify 0 for the first attribute). On output, it will represent the index of the next attribute.
 * @param oComponentNumber [out]
 *   The component number on which there is a problem of truncation in one of its attribute.
 * @param oAttribute [out]
 *   The attribute name. 
 *
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if everything ran ok.</li>
 *   <li><code>S_FALSE</code> if no more attributes are available.</li>
 *   <li><code>E_INVALIDARG</code> if invalid position is provided.</li>
 *   <li><code>E_FAIL</code> if a fatal error occured during the operation. Nothing was done during the operation.</li>
 *   </ul>
 *
 */
	virtual HRESULT Next(int & ioPosition, int & oComponentNumber, CATUnicodeString & oAttribute)= 0;
};

//-----------------------------------------------------------------------------
CATDeclareHandler(PLMIBLErrorIterator, CATBaseUnknown);
#endif
