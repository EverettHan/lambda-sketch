#ifndef _CATIPLMIndexResultRow_H
#define _CATIPLMIndexResultRow_H

#include "IUnknown.h" // for HRESULT
#include "CATTypUtilit.h" // SEQUENCE_Octet

#include "CATLISTP_CATMathTransformation.h"

class CATPLMID;
class CATMathTransformation;
class CATMathPoint;
class CATUnicodeString;
/**
 * @level Private
 * @usage U3
 */



/** 
 * This class supplies CATIAsmGeoObject.
 * <b>role</b>: This interface represents a result line.
 *  That is, a set of values whose types are defined by the select clause.
 *  The values in the line can be read by calling GetField() on it.
 *  0 <= iIndex < size of line.
 *  Returns E_FAIL if encounters an error (for instance if iIndex is outside range)
 */
class CATIPLMIndexResultRow
{
public:
	/** Get the value associated to iIndex^th field.
	 *  0 <= iIndex < size of line.
	 *  Returns E_FAIL if encounters an error (for instance if iIndex is outside range).
	 *  Returns E_INVALIDARG if the requested type doesn't match
	 *  Returns S_FALSE if value is N/A. */
	virtual HRESULT GetField(int iIndex, CATPLMID &oID) = 0 ;

	/**
	 * Get the value associated to iIndex^th field.
	 */
	virtual HRESULT GetField(int iIndex, int &oInt) = 0;
	
	/**
	 * Get the value associated to iIndex^th field.
	 */
	virtual HRESULT GetField(int iIndex, CATMathTransformation &oTransformation) = 0;

	/** oTransformationList must not be deleted. Its life time is the same as the result Row.
	 *  WARNING !!! do not keep a reference on oTransformationList */
	virtual HRESULT GetField(int iIndex, const CATMathTransformationList *&oTransformationList) = 0;

	/**
	 * Get the value associated to iIndex^th field.
	 */
	virtual HRESULT GetField(int iIndex, SEQUENCE_octet &oSequenceOctet) = 0;

	/**
	 * Get the value associated to iIndex^th field.
	 */
	virtual HRESULT GetField(int iIndex, CATMathPoint &oBoxMin, CATMathPoint &oBoxMax) = 0;

	/**
	 * Get the value associated to iIndex^th field.
	 */
	virtual HRESULT GetField(int iIndex, CATUnicodeString &oString) = 0;

	// ...
};

#endif
