// COPYRIGHT DASSAULT SYSTEMES 2002

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#ifndef CATSAXIOException_h
#define CATSAXIOException_h

// System framework
#include "CATInternalError.h"
class CATUnicodeString;

// XMLParser framework
#include "CatXmlItfBase.h"


/**
 * Class to encapsulates an IO error in the context of a SAX parser.
 * These errors can occur while invoking the @href CATISAXXMLReader#Parse method
 * or when the SAX parser asks the @href CATISAXEntityResolver for the resolution of an entity.
 * @see CATISAXXMLReader#Parse, CATISAXEntityResolver
 */
class ExportedByCatXmlItfBase CATSAXIOException: public CATInternalError {
	CATDeclareError(CATSAXIOException, CATInternalError)
	public:
		
		/**
		 * Factory method.
		 * @param iRequest
		 * specifies the operation which was being performed at the time the error occurred.
		 * @param iMessage
		 * specifies the message describing the error details.
		 * @param oError
		 * the error created by the factory method.
		 */
		static HRESULT CreateError(
			const CATUnicodeString& iRequest, 
			const CATUnicodeString& iMessage,
			CATSAXIOException*& oError);

		/**
		 * Returns the message describing the error details.
		 * To get a complete description of the error, you can call
		 * @href CATError#GetNLSMessage
		 * @returns
		 * The message describing the error details
		 */
		CATUnicodeString GetMessage();


	private:
		CATUnicodeString _message;
};

#endif //CATSAXIOException_h

