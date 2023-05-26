#ifndef _CATIPLMIndexResultProcessor_H
#define _CATIPLMIndexResultProcessor_H


#include "CATIPLMIndexResultRow.h"
#include "IUnknown.h" // for HRESULT

/**
 * @level Private
 * @usage U6
 */


/** This interface should be implemented by any one who wants to use 3D Index. */
class CATIPLMIndexResultProcessor
{
public:
	//virtual HRESULT Begin() = 0;

	/** This method is called for each row of the result.
	*
	* @param iResultRow
	*	One row of the query resuult.
	*   
	*/

	virtual HRESULT ProcessResultRow(CATIPLMIndexResultRow &iResultRow) = 0;

	//virtual HRESULT Finish() = 0;
};

#endif
