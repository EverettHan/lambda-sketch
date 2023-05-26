//-*-C++-*-
/**
 * @level Private
 * @usage U3
 * This class defined the interface for the most basical streamer
 * It provides service for primitive types such as int, CATUnicodeString, double, char...
 * @fullReview lpu 05:12:02
 * Reimplementation of this interface is not permitted without OME permission
 * if needed an adapter will be provided
 */

#ifndef PLMIStreamWriter_H
#define PLMIStreamWriter_H


#include "PLMSCStreamerItf.h"
#include "CATBaseUnknown.h"
class CATUnicodeString;

extern ExportedByPLMSCStreamerItf const IID IID_PLMIStreamWriter;


#include "PLMIBaseWriter.h"
class ExportedByPLMSCStreamerItf PLMIStreamWriter : public PLMIBaseWriter
{
	CATDeclareInterface;
public:
	/**
	 * Write an int in the Stream
	 * @param iData the int to be written
	 * This function will take care of the endianness of the host
	 * The corresponding Reader must be used to properly decode the information
	 * E_FAILED may be returned if the underlying stream is in a state that do not permit to do the operation
	 */
	virtual HRESULT Write( const int idata ) = 0 ;

	/**
	 * Write a double in the Stream
	 * @param idata the double to be written
	 * This function will take care of the endianness of the host
     * The corresponding Reader must be used to properly decode the information
	 * E_FAILED may be returned if the underlying stream is in a state that do not permit to do the operation
	 */
	virtual HRESULT Write( const double idata) = 0;

	/**
	 * Write a char in the Stream
	 * @param idata the char* to be written
	 * @param isize the number of element to be written
     * The corresponding Reader must be used to properly decode the information
	 * E_FAILED may be returned if the underlying stream is in a state that do not permit to do the operation
	 */
	virtual HRESULT Write( const char* idata , const size_t isize ) = 0;
	
	/**
	 * Write a CATUnicodeString in the Stream
	 * @param iStr the string to be written
	 * Specific encoding such as UTF8 or UTF16 are used so that characters encoding is platform independent
     * The corresponding Reader must be used to properly decode the information
	 * E_FAILED may be returned if the underlying stream is in a state that do not permit to do the operation
	 */
	virtual HRESULT Write( const CATUnicodeString& iStr ) = 0;
	
};

CATDeclareHandler( PLMIStreamWriter , CATBaseUnknown);

#endif
