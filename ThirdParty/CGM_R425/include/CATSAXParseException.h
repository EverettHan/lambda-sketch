// COPYRIGHT DASSAULT SYSTEMES 2002

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#ifndef CATSAXParseException_h
#define CATSAXParseException_h

// System framework
class CATUnicodeString;

// XMLParser framework
#include "CATSAXException.h"
#include "CatXmlItfBase.h"

/**
 * Class to encapsulate an XML parse error or warning.
 *
 * <p>This exception will include information for locating the error
 * in the original XML document.  Note that although the application
 * will receive a @href CATSAXParseException as the argument to the handlers
 * in the @href CATISAXErrorHandler interface, the application is not actually
 * required to raise an error; instead, it can simply read the
 * information in it and take a different action.</p>
 *
 * @see CATSAXException, CATISAXLocator, CATISAXErrorHandler
 */
class ExportedByCatXmlItfBase CATSAXParseException : public CATSAXException {
	CATDeclareError(CATSAXParseException, CATSAXException)
	public:
		
		/**
		 * Factory method.
		 * @param iRequest
		 * specifies the operation which was being performed at the time the error occurred.
		 * @param iMessage
		 * specifies the message describing the error details.
		 * @param oError
		 * the error created by the factory method.
		 * @param iLineNumber
		 * The line number of the end of the text where the exception occurred.
		 * @param iColumnNumber
		 * The column number of the end of the text where the exception occurred.
		 * @param iPublicID
		 * A string containing the public identifier.
		 * @param iSystemID
		 * A string containing the system identifier.
		 */
		static HRESULT CreateError(
			const CATUnicodeString& iRequest, 
			const CATUnicodeString& iMessage,
			CATSAXParseException*& oError,
			int iLineNumber = -1,
			int iColumnNumber = -1,
			const CATUnicodeString& iPublicID = "",
			const CATUnicodeString& iSystemID = "");

		/**
		 * The column number of the end of the text where the exception occurred.
		 *
		 * <p>The first column in a line is position 1.</p>
		 *
		 * @return
		 * An integer representing the column number, or -1 if none is available.
		 *
		 * @see CATISAXLocator#GetColumnNumber
		 */
		int GetColumnNumber() const;
   
		/**
		 * The line number of the end of the text where the exception occurred.
		 *
		 * @return
		 * An integer representing the line number, or -1 if none is available.
		 *
		 * @see CATISAXLocator#GetLineNumber
		 */
		int GetLineNumber() const;
    
		/**
		 * Get the public identifier of the entity where the exception occurred.
		 *
		 * @return
		 * A string containing the public identifier
		 *
		 * @see CATISAXLocator#GetPublicId
		 */
		CATUnicodeString GetPublicId() const;

    
		/**
		 * Get the system identifier of the entity where the exception occurred.
		 *
		 * <p>If the system identifier is a URL, it will be resolved
		 * fully.</p>
		 *
		 * @return
		 * A string containing the system identifier
		 *
		 * @see CATISAXLocator#GetSystemId
		 */
		CATUnicodeString GetSystemId() const;

	private:
		int					_column;
		int					_line;
		CATUnicodeString	_publicId;
		CATUnicodeString	_systemId;	
};

#endif // CATSAXParseException_h

