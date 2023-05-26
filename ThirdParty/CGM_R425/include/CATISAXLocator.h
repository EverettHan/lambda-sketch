// COPYRIGHT DASSAULT SYSTEMES 2002

/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */

#ifndef CATISAXLocator_h
#define CATISAXLocator_h

// System framework
#include "CATBaseUnknown.h"
class CATUnicodeString;

// XMLParser framework
#include "CatXmlItfBase.h"

#ifndef LOCAL_DEFINITION_FOR_IID
	extern ExportedByCatXmlItfBase IID IID_CATISAXLocator;
#else // LOCAL_DEFINITION_FOR_IID
	extern "C" const IID IID_CATISAXLocator ;
#endif // LOCAL_DEFINITION_FOR_IID

/**
 * Interface for associating a SAX event with a document location.
 *
 * <p>If a SAX parser provides location information to the SAX
 * application, it does so by implementing this interface and then
 * passing an instance to the application using the document
 * handler's @href CATISAXContentHandler#SetDocumentLocator method. 
 * The application can use the
 * object to obtain the location of any other document handler event
 * in the XML source document.</p>
 *
 * <p>Note that the results returned by the object will be valid only
 * during the scope of each document handler method: the application
 * will receive unpredictable results if it attempts to use the
 * locator at any other time.</p>
 *
 * <p>SAX parsers are not required to supply a locator, but they are
 * very strong encouraged to do so.  If the parser supplies a
 * locator, it must do so before reporting any other document events.
 * If no locator has been set by the time the application receives
 * the @href CATISAXContentHandler#StartDocument event, the application should assume that a
 * locator is not available.</p>
 *
 * @see CATISAXContentHandler#SetDocumentLocator 
 */
class ExportedByCatXmlItfBase CATISAXLocator: public CATBaseUnknown {
		CATDeclareInterface;
		
	public:
		
		/**
		 * Retrieves the column number where the current document event ends.
		 * Note that this is the column number of the first
		 * character after the text associated with the document
		 * event.  The first column in a line is position 1.
		 * @param oNumber
		 * The column number, or -1 if none is available.
		 * @see #GetLineNumber
		 */		
		virtual HRESULT GetColumnNumber(int & oNumber) = 0;
		
		/**
		 * Retrieves the line number where the current document event ends.
		 * Note that this is the line position of the first character
		 * after the text associated with the document event.
		 * @param oNumber
		 * The line number, or -1 if none is available.
		 * @see #GetColumnNumber
		 */
		virtual HRESULT GetLineNumber(int & oNumber) = 0;
		
		/**
		 * Retrieves the public identifier for the current document event.
		 * <p>This will be the public identifier
		 * @param oPublicId
		 * A string containing the public identifier
		 * @return
		 * <tt>S_OK</tt> upon success, or <tt>E_FAIL</tt> if no public identifier is available.
		 * @see #GetPublicId
		 */
		virtual HRESULT GetPublicId(CATUnicodeString & oPublicId) = 0;
		
		/**
		 * Retrieves the system identifier for the current document event.
		 *
		 * <p>If the system identifier is a URL, the parser must resolve it
		 * fully before passing it to the application.</p>
		 *
		 * @param oSystemId
		 * A string containing the system identifier.
		 * @return
		 * <tt>S_OK</tt> upon success, or <tt>E_FAIL</tt> if no system identifier is available.
		 * @see #GetSystemId
		 */
		virtual HRESULT GetSystemId(CATUnicodeString & oSystemId) = 0;
};

CATDeclareHandler(CATISAXLocator, CATBaseUnknown);


#endif // CATISAXLocator_h
