// COPYRIGHT DASSAULT SYSTEMES 2002

/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */

#ifndef CATISAXXMLReader_h
#define CATISAXXMLReader_h

// System framework
#include "CATBaseUnknown.h"
#include "CATBoolean.h"
class CATUnicodeString;
#include "CATBaseUnknown_var.h"

// XMLParser framework
#include "CatXmlItfBase.h"
class CATISAXInputSource_var;
class CATISAXContentHandler_var;
class CATISAXDTDHandler_var;
class CATISAXEntityResolver_var;
class CATISAXErrorHandler_var;

#ifndef LOCAL_DEFINITION_FOR_IID
	extern ExportedByCatXmlItfBase IID IID_CATISAXXMLReader;
#else // LOCAL_DEFINITION_FOR_IID
	extern "C" const IID IID_CATISAXXMLReader ;
#endif // LOCAL_DEFINITION_FOR_IID

/**
 * Interface for reading an XML document using callbacks.
 *
 * <p>CATISAXXMLReader is the interface that an XML parser's SAX2 driver must
 * implement.  This interface allows an application to set and
 * query features and properties in the parser, to register
 * event handlers for document processing, and to initiate
 * a document parse.</p>
 *
 * <p>All SAX interfaces are assumed to be synchronous: the
 * @href CATISAXXMLReader#Parse methods must not return until parsing
 * is complete, and readers must wait for an event-handler callback
 * to return before reporting the next event.</p>
 *
 * @see CATISAXEntityResolver, CATISAXDTDHandler, CATISAXContentHandler, CATISAXErrorHandler, CATSAXDefaultHandler, CATISAXInputSource
 */
class ExportedByCatXmlItfBase CATISAXXMLReader : public CATBaseUnknown {
	CATDeclareInterface;
	
	public:
		
		/**
		 * Parses an XML document.
		 *
		 * <p>The application can use this method to instruct the SAX parser
		 * to begin parsing an XML document from any valid input
		 * source (a character stream, a byte stream, or a URI).</p>
		 *
		 * <p>Applications may not invoke this method while a parse is in
		 * progress (they should create a new @href CATISAXXMLReader instead for each
		 * additional XML document).  Once a parse is complete, an
		 * application may reuse the same reader object, possibly with a
		 * different input source.</p>
		 *
		 * <p>During the parse, the @href CATISAXXMLReader will provide information about 
		 * the XML document through the registered event handlers.</p>
		 *
		 * <p>This method is synchronous: it will not return until parsing has ended. 
		 * If a client application wants to terminate parsing early, it should raise an error.</p>
		 *
		 * @param iInputSource 
		 * The input source for the top-level of the XML document.
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
		 *        <td class="errtd">If an error (such as a not well formed XML document) occurs during parse</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATSAXException </td>
		 *        <td class="errtd">XMLParserERR_2001</td>
		 *        <td class="errtd">If an I/O error occurs during parse</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 *
		 * @see CATISAXInputSource, #SetEntityResolver, #SetDTDHandler, #SetContentHandler, #SetErrorHandler
		 */
		virtual HRESULT Parse(
			const CATISAXInputSource_var& iInputSource) = 0;
		
		/**
		 * Parses an XML document from a system identifier (URI).
		 *
		 * <p>This method is a shortcut for the common case of reading a
		 * document from a system identifier. If the system identifier is a URL, it must be fully resolved
		 * by the application before it is passed to the parser.</p>
		 *
		 * @param iSystemId
		 * The system identifier (URI).
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
		 *        <td class="errtd">If an error (such as a not well formed XML document) occurs during parse</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATSAXException </td>
		 *        <td class="errtd">XMLParserERR_2001</td>
		 *        <td class="errtd">If an I/O error occurs during parse</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 * 
		 *
		 * @see #Parse
		 */
		virtual HRESULT Parse(
			const CATUnicodeString & iSystemId) = 0;


		/**
		 * Retrieves the current content event handler.
		 *
		 * @param oContentHandler
		 * The content handler.
		 *
		 * @see #SetContentHandler, CATSAXDefaultHandler, CATISAXContentHandler
		 */
		virtual HRESULT GetContentHandler(
			CATISAXContentHandler_var& oContentHandler) = 0;

		/**
		 * Allows an application to register a content event handler.
		 *
		 * If the application does not register a content handler, all
		 * content events reported by the SAX parser will be silently
		 * ignored (this is the default behaviour implemented by
		 * @href CATSAXDefaultHandler ).
		 *
		 * Applications may register a new or different handler in the
		 * middle of a parse, and the SAX parser must begin using the new
		 * handler immediately.
		 *
		 * @param iContentHandler
		 * The content handler.
		 *
		 * @see #GetContentHandler, CATSAXDefaultHandler, CATISAXContentHandler
		 */
		virtual HRESULT SetContentHandler(
			const CATISAXContentHandler_var& iContentHandler) = 0;

		/**
		 * Retrieves the current DTD event handler.
		 *
		 * @param oDTDHandler
		 * The DTD handler.
		 *
		 * @see #SetDTDHandler, CATSAXDefaultHandler, CATISAXDTDHandler
		 */
		virtual HRESULT GetDTDHandler(
			CATISAXDTDHandler_var& oDTDHandler) = 0;

		/**
		 * Allows an application to register a DTD event handler.
		 *
		 * If the application does not register a DTD handler, all DTD
		 * events reported by the SAX parser will be silently ignored (this
		 * is the default behaviour implemented by @href CATSAXDefaultHandler ).
		 *
		 * Applications may register a new or different handler in the middle
		 * of a parse, and the SAX parser must begin using the new handler
		 * immediately.
		 *
		 * @param iDTDHandler
		 * The DTD handler.
		 *
		 * @see #GetDTDHandler, CATSAXDefaultHandler, CATISAXDTDHandler
		 */
		virtual HRESULT SetDTDHandler(
			const CATISAXDTDHandler_var& iDTDHandler) = 0;
		
		/**
		 * Retrieves the current entity resolver.
		 *
		 * @param oEntityResolver
		 * The entity resolver.
		 *
		 * @see #SetEntityResolver, CATSAXDefaultHandler, CATISAXEntityResolver
		 */
		virtual HRESULT GetEntityResolver(
			CATISAXEntityResolver_var& oEntityResolver) = 0;

		/**
		 * Allows an application to register a custom entity resolver.
		 *
		 * If the application does not register an entity resolver, the
		 * SAX reader will resolve system identifiers and open connections
		 * to entities itself (this is the default behaviour implemented in
		 * @href CATSAXDefaultHandler ).
		 *
		 * Applications may register a new or different entity resolver
		 * in the middle of a parse, and the SAX parser must begin using
		 * the new resolver immediately.
		 *
		 * @param iEntityResolver
		 * The object for resolving entities.
		 *
		 * @see #GetEntityResolver, CATSAXDefaultHandler, CATISAXEntityResolver
		 */
		virtual HRESULT SetEntityResolver(
			const CATISAXEntityResolver_var& iEntityResolver) = 0;
		
		/**
		 * Retrieves the current error event handler.
		 *
		 * @param oErrorHandler
		 * The error event handler.
		 *
		 * @see #SetErrorHandler, CATSAXDefaultHandler, CATISAXErrorHandler
		 */
		virtual HRESULT GetErrorHandler(
			CATISAXErrorHandler_var& oErrorHandler) = 0;

		/**
		 * Allows an application to register an error event handler.
		 *
		 * If the application does not register an error event handler,
		 * all error events reported by the SAX parser will be silently
		 * ignored, except for @href CATISAXErrorHandler#FatalError, which will raise a @href CATSAXException
		 * error (this is the default behaviour implemented by @href CATSAXDefaultHandler ).
		 *
		 * Applications may register a new or different handler in the
		 * middle of a parse, and the SAX parser must begin using the new
		 * handler immediately.
		 *
		 * @param iErrorHandler 
		 * The error handler.
		 *
		 * @see #GetErrorHandler, CATISAXErrorHandler, CATSAXDefaultHandler
		 */
		virtual HRESULT SetErrorHandler(
			const CATISAXErrorHandler_var& iErrorHandler) = 0;

		/**
		 * Retrieves the value of a feature.
		 *
		 * <p>The feature name is any fully-qualified URI.  It is
		 * possible for an @href CATISAXXMLReader to recognize a feature name but
		 * to be unable to return its value.</p>
		 *
		 * <p>All @href CATISAXXMLReader s are required to recognize the
		 * <tt>http://xml.org/sax/features/namespaces</tt> and the
		 * <tt>http://xml.org/sax/features/namespace-prefixes</tt> feature names.</p>
		 *
		 * <p>Some feature values may be available only in specific
		 * contexts, such as before, during, or after a parse.</p>
		 *
		 * <p>Typical usage is something like this:</p>
		 *
		 * <pre>
		 * CATISAXReader_var r;
		 * hr = factory->CreateReader(r);
		 * if (SUCCEEDED(hr) && (r != NULL_var)) {
		 *     hr = r->SetFeature("http://xml.org/sax/features/validation", TRUE);
		 *     if (FAILED(hr)) {
		 *         cerr << "Cannot activate validation." << endl;
		 *     } else {
		 *         CATISAXContentHandler_var myContentHandler;
		 *         MyContentHandler* myContentHandlerImpl = new MyContentHandler();
		 *         myContentHandler = myContentHandlerImpl;
		 *         myContentHandlerImpl->Release();
		 *         myContentHandlerImpl = NULL;
		 * 
		 *         CATISAXErrorHandler_var myErrorHandler;
		 *         MyErrorHandler* myErrorHandlerImpl = new MyErrorHandler();
		 *         myErrorHandler = myErrorHandlerImpl;
		 *         myErrorHandlerImpl->Release();
		 *         myErrorHandlerImpl = NULL;
		 * 
		 *         r->SetContentHandler(myContentHandler);
		 *         r->SetErrorHandler(myErrorHandlerImpl);
		 *         hr = Parse("http://www.foo.com/mydoc.xml");
		 *         if (FAILED(hr)) {
		 *             CATError *error = CATError::CATGetLastError();
		 *             if (error != NULL) {
		 *                 cerr << error->GetNLSMessage().CastToCharPtr() << endl;
		 *                 error->Release();
		 *                 error = NULL;
		 *             } else {
		 *                 cerr << "Unknown error." << endl;
		 *             }
		 *         }
		 *     }
		 * }
		 * </pre>
		 * 
		 * <p>Implementors are free (and encouraged) to invent their own features,
		 * using names built on their own URIs.</p>
		 *
		 * @param iName
		 * The feature name, which is a fully-qualified URI.
		 * @param oFeature
		 * The current state of the feature (<tt>TRUE</tt> or <tt>FALSE</tt>).
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
		 *        <td class="errtd">@href CATSAXNotRecognizedException </td>
		 *        <td class="errtd">XMLParserERR_2302</td>
		 *        <td class="errtd">If the @href CATISAXXMLReader does not recognize the feature name.</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATSAXNotSupportedException </td>
		 *        <td class="errtd">XMLParserERR_2303</td>
		 *        <td class="errtd">When the XMLReader recognizes the feature name but cannot determine its value at this time.</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 * 
		 *
		 * @see #SetFeature
		 */
		 virtual HRESULT GetFeature(
			const CATUnicodeString &iName,
			CATBoolean& oFeature) = 0;

		/**
		 * Sets the value of a feature.
		 *
		 * <p>The feature name is any fully-qualified URI.  It is
		 * possible for an @href CATISAXXMLReader to recognize a feature name but
		 * to be unable to set its value.</p>
		 * 
		 * <p>All @href CATISAXXMLReader s are required to support setting
		 * <tt>http://xml.org/sax/features/namespaces</tt> to <tt>TRUE</tt> and
		 * <tt>http://xml.org/sax/features/namespace-prefixes</tt> to <tt>FALSE</tt>.</p>
		 * 
		 * <p>Some feature values may be immutable or mutable only 
		 * in specific contexts, such as before, during, or after 
		 * a parse.</p>
		 *
		 * @param iName
		 * The feature name, which is a fully-qualified URI.
		 * @param oFeature
		 * The requested state of the feature (<tt>TRUE</tt> or <tt>FALSE</tt>).
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
		 *        <td class="errtd">@href CATSAXNotRecognizedException </td>
		 *        <td class="errtd">XMLParserERR_2302</td>
		 *        <td class="errtd">If the @href CATISAXXMLReader does not recognize the feature name.</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATSAXNotSupportedException </td>
		 *        <td class="errtd">XMLParserERR_2303</td>
		 *        <td class="errtd">When the XMLReader recognizes the feature name but cannot determine its value at this time.</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 * 
		 *
		 * @see #SetFeature
		 */
		virtual HRESULT SetFeature(
			const CATUnicodeString &iName,
			CATBoolean iFeature) = 0;

		/**
		 * Retrieves up the value of a property.
		 * 
		 * <p>The property name is any fully-qualified URI.  It is
		 * possible for a @href CATISAXXMLReader to recognize a property name but
		 * to be unable to return its state .</p>
		 *
		 * <p>@href CATISAXXMLReader s are not required to recognize any specific
		 * property names, though an initial core set is documented for
		 * SAX2.</p>
		 *
		 * <p>Some property values may be available only in specific
		 * contexts, such as before, during, or after a parse.</p>
		 *
		 * <p>Implementors are free (and encouraged) to invent their own properties,
		 * using names built on their own URIs.</p>
		 *
		 * @param iName
		 * The property name, which is a fully-qualified URI.
		 * @param oProperty
		 * The current value of the property.
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
		 *        <td class="errtd">@href CATSAXNotRecognizedException </td>
		 *        <td class="errtd">XMLParserERR_2300</td>
		 *        <td class="errtd">If the @href CATISAXXMLReader does not recognize the feature name.</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATSAXNotSupportedException </td>
		 *        <td class="errtd">XMLParserERR_2301</td>
		 *        <td class="errtd">When the XMLReader recognizes the feature name but cannot determine its value at this time.</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 * 
		 *
		 * @see #SetProperty
		 */
		virtual HRESULT GetProperty(
			const CATUnicodeString &iName,
			CATBaseUnknown_var& oProperty) = 0;

		/**
		 * Sets the value of a property.
		 * 
		 * <p>The property name is any fully-qualified URI.  It is
		 * possible for a @href CATISAXXMLReader to recognize a property name but
		 * to be unable to return its state.</p>
		 *
		 * <p>@href CATISAXXMLReader s are not required to recognize any specific
		 * property names, though an initial core set is documented for
		 * SAX2.</p>
		 *
		 * <p>Some property values may be available only in specific
		 * contexts, such as before, during, or after a parse.</p>
		 *
		 * <p>Implementors are free (and encouraged) to invent their own properties,
		 * using names built on their own URIs.</p>
		 *
		 * @param iName
		 * The property name, which is a fully-qualified URI.
		 * @param iProperty
		 * The requested value for the property.
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
		 *        <td class="errtd">@href CATSAXNotRecognizedException </td>
		 *        <td class="errtd">XMLParserERR_2300</td>
		 *        <td class="errtd">If the @href CATISAXXMLReader does not recognize the feature name.</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATSAXNotSupportedException </td>
		 *        <td class="errtd">XMLParserERR_2301</td>
		 *        <td class="errtd">When the XMLReader recognizes the feature name but cannot determine its value at this time.</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 * 
		 *
		 * @see #GetProperty
		 */
		virtual HRESULT SetProperty(
			const CATUnicodeString &iName,
			const CATBaseUnknown_var& iProperty) = 0;
};

CATDeclareHandler(CATISAXXMLReader, CATBaseUnknown);

#endif // CATISAXXMLReader_h
