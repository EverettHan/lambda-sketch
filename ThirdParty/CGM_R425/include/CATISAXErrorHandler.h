// COPYRIGHT DASSAULT SYSTEMES 2002

/**
 * @CAA2Level L1
 * @CAA2Usage U5
 */

#ifndef CATISAXErrorHandler_h
#define CATISAXErrorHandler_h

// System framework
#include "CATBaseUnknown.h"

// XMLParser framework
#include "CatXmlItfBase.h"
class CATSAXParseException;

#ifndef LOCAL_DEFINITION_FOR_IID
	extern ExportedByCatXmlItfBase IID IID_CATISAXErrorHandler;
#else // LOCAL_DEFINITION_FOR_IID
	extern "C" const IID IID_CATISAXErrorHandler ;
#endif // LOCAL_DEFINITION_FOR_IID

/**
 * Interface for SAX error handlers.
 *
 * <p>If a SAX application needs to implement customized error
 * handling, it must implement this interface and then register an
 * instance with the SAX parser using the parser's @href CATISAXXMLReader#SetErrorHandler
 * method.  The parser will then report all errors and warnings
 * through this interface.</p>
 *
 * <p> The parser shall use this interface instead of raising an
 * error: it is up to the application whether to raise an
 * error for different types of errors and warnings.  Note,
 * however, that there is no requirement that the parser continue to
 * provide useful information after a call to @href #FatalError (in other
 * words, a SAX driver class could catch an error and report a
 * fatalError).</p>
 *
 * <p>The @href CATSAXDefaultHandler class provides a default implementation of this
 * interface, ignoring warnings and recoverable errors and raising a
 * CATSAXParseException error for fatal errors.  An application may extend
 * that class rather than implementing the complete interface
 * itself.</p>
 *
 * @see CATISAXXMLReader#SetErrorHandler, CATSAXParseException, CATSAXDefaultHandler
 */
class ExportedByCatXmlItfBase CATISAXErrorHandler: public CATBaseUnknown {
	CATDeclareInterface;
	
	public:
		
		/**
		 * Receives notification of a recoverable error.
		 *
		 * <p>This corresponds to the definition of "error" in section 1.2
		 * of the W3C XML 1.0 Recommendation.  For example, a validating
		 * parser would use this callback to report the violation of a
		 * validity constraint.  The default behaviour is to take no
		 * action.</p>
		 *
		 * <p>The SAX parser must continue to provide normal parsing events
		 * after invoking this method: it should still be possible for the
		 * application to process the document through to the end.  If the
		 * application cannot do so, then the parser should report a fatal
		 * error even if the XML 1.0 recommendation does not require it to
		 * do so.</p>
		 *
		 * @param iException
		 * The error information encapsulated in a SAX parse exception.
		 *
		 * </dl>
		 * <dt><b>Errors Returned</b>:</dt>
		 * <dd>
		 *   <table class="errtab">
		 *     <tr>
		 *       <th class="errth">Error Class</th>
		 *       <th class="errth">Error Id</th>
		 *       <th class="errth">Description</th>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATSAXException </td>
		 *        <td class="errtd">XMLParserERR_2000</td>
		 *        <td class="errtd">The method can raise a CATSAXException</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATSAXParseException </td>
		 *        <td class="errtd">XMLParserERR_2002</td>
		 *        <td class="errtd">The method can raise a CATSAXParseException</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 * 
		 *
		 * @see CATSAXParseException 
		 */
		virtual HRESULT Error(
			CATSAXParseException* iException) = 0;
		
		/**
		 * Receives notification of a non-recoverable error.
		 *
		 * <p>This corresponds to the definition of "fatal error" in
		 * section 1.2 of the W3C XML 1.0 Recommendation.  For example, a
		 * parser would use this callback to report the violation of a
		 * well-formedness constraint.</p>
		 *
		 * <p>The application must assume that the document is unusable
		 * after the parser has invoked this method, and should continue
		 * (if at all) only for the sake of collecting addition error
		 * messages: in fact, SAX parsers are free to stop reporting any
		 * other events once this method has been invoked.</p>
		 *
		 * @param iException 
		 * The error information encapsulated in a SAX parse exception.
		 *
		 * </dl>
		 * <dt><b>Errors Returned</b>:</dt>
		 * <dd>
		 *   <table class="errtab">
		 *     <tr>
		 *       <th class="errth">Error Class</th>
		 *       <th class="errth">Error Id</th>
		 *       <th class="errth">Description</th>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATSAXException </td>
		 *        <td class="errtd">XMLParserERR_2000</td>
		 *        <td class="errtd">The method can raise a CATSAXException</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATSAXParseException </td>
		 *        <td class="errtd">XMLParserERR_2002</td>
		 *        <td class="errtd">The method can raise a CATSAXParseException</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 * 
		 *
		 * @see CATSAXParseException
		 */
		virtual HRESULT FatalError(
			CATSAXParseException* iException) = 0;
		
		/**
		 * Receives notification of a warning.
		 *
		 * <p>SAX parsers will use this method to report conditions that
		 * are not errors or fatal errors as defined by the XML 1.0
		 * recommendation.  The default behaviour is to take no action.</p>
		 *
		 * <p>The SAX parser must continue to provide normal parsing events
		 * after invoking this method: it should still be possible for the
		 * application to process the document through to the end.</p>
		 *
		 * @param iException
		 * The warning information encapsulated in a SAX parse exception.
		 *
		 * </dl>
		 * <dt><b>Errors Returned</b>:</dt>
		 * <dd>
		 *   <table class="errtab">
		 *     <tr>
		 *       <th class="errth">Error Class</th>
		 *       <th class="errth">Error Id</th>
		 *       <th class="errth">Description</th>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATSAXException </td>
		 *        <td class="errtd">XMLParserERR_2000</td>
		 *        <td class="errtd">The method can raise a CATSAXException</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATSAXParseException </td>
		 *        <td class="errtd">XMLParserERR_2002</td>
		 *        <td class="errtd">The method can raise a CATSAXParseException</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 * 
		 *
		 * @see CATSAXParseException 
		 */
		virtual HRESULT Warning(
			CATSAXParseException* iException) = 0;
	
};
CATDeclareHandler(CATISAXErrorHandler, CATBaseUnknown);


#endif // CATISAXErrorHandler_h
