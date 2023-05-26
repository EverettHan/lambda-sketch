// COPYRIGHT DASSAULT SYSTEMES 2002

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#ifndef CATSAXException_h
#define CATSAXException_h

// System framework
#include "CATInternalError.h"
class CATUnicodeString;

// XMLParser framework
#include "CatXmlItfBase.h"


/**
  * Class to encapsulate a general SAX error or warning.
  *
  * <p>This class can contain basic error or warning information from
  * either the XML SAX parser or the application: a parser writer or
  * application writer can subclass it to provide additional
  * functionality.  SAX handlers may raise this error or
  * any error subclassed from it.</p>
  *
  * <p>If the parser or application needs to include information
  * about a specific location in an XML document, it should use the
  * @href CATSAXParseException subclass.</p>
  *
  * @see CATSAXParseException
  */
class ExportedByCatXmlItfBase CATSAXException: public CATInternalError {
	CATDeclareError(CATSAXException, CATInternalError)
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
			CATSAXException*& oError);

		/**
		 * Returns the message describing the error details.
		 * To get a complete description of the error, you can call
		 * @href CATError#GetNLSMessage
		 * @returns
		 * The message describing the error details
		 */
		CATUnicodeString GetMessage();
			

	protected:
		CATUnicodeString _message;
};

#endif //CATSAXException_h

