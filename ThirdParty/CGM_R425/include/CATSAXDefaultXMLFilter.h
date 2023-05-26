// COPYRIGHT DASSAULT SYSTEMES 2002

/**
 * @CAA2Level L1
 * @CAA2Usage U2
 */

#ifndef CATSAXDefaultXMLFilter_h
#define CATSAXDefaultXMLFilter_h

// System framework
#include "CATBaseUnknown.h"
class CATUnicodeString;

// XMLParser framework
#include "CatXmlItfBase.h"
#include "CATISAXXMLReader.h"
#include "CATISAXContentHandler.h"
#include "CATISAXDTDHandler.h"
#include "CATISAXErrorHandler.h"
#include "CATISAXEntityResolver.h"
class CATISAXLocator_var;
class CATISAXAttributes_var;
class CATISAXInputSource_var;
class CATSAXParseException;

/**
 * Base class for deriving an XML filter.
 *
 * <p>This class is designed to sit between an @href CATISAXXMLReader and the client 
 * application's event handlers. By default, it does nothing but pass requests up to 
 * the reader and events on to the handlers unmodified, but subclasses can override specific 
 * methods to modify the event stream or the configuration requests as they pass through.</p>
 *
 * @see CATISAXXMLReader
 */
class ExportedByCatXmlItfBase CATSAXDefaultXMLFilter: public CATBaseUnknown {
	CATDeclareClass;
	
	public:
		
		/**
		 * Constructor
		 * @param iParentReader
		 * The parent reader
		 */
		CATSAXDefaultXMLFilter(
			CATISAXXMLReader_var& iParentReader);

		/**
		 * Destructor
		 */
		virtual ~CATSAXDefaultXMLFilter();

		// Implementation of the CATISAXXMLFilter
		/**
		 * Parses an XML document.
		 * @see CATISAXXMLReader#Parse 
		 */
		virtual HRESULT Parse(
			const CATISAXInputSource_var& iInputSource);
		/**
		 * Parses an XML document from a system identifier (URI).
		 * @see CATISAXXMLReader#Parse 
		 */
		virtual HRESULT Parse(
			const CATUnicodeString & iSystemId);
		/**
		 * Retrieves the current content event handler.
		 * @see CATISAXXMLReader#GetContentHandler 
		 */
		virtual HRESULT GetContentHandler(
			CATISAXContentHandler_var& oContentHandler);
		/**
		 * Allows an application to register a content event handler.
		 * @see CATISAXXMLReader#SetContentHandler 
		 */
		virtual HRESULT SetContentHandler(
			const CATISAXContentHandler_var& iContentHandler);
		/**
		 * Retrieves the current DTD event handler.
		 * @see CATISAXXMLReader#GetDTDHandler 
		 */
		virtual HRESULT GetDTDHandler(
			CATISAXDTDHandler_var& oDTDHandler);
		/**
		 * Allows an application to register a DTD event handler.
		 * @see CATISAXXMLReader#SetDTDHandler 
		 */
		virtual HRESULT SetDTDHandler(
			const CATISAXDTDHandler_var& iDTDHandler);
		/**
		 * Retrieves the current entity resolver.
		 * @see CATISAXXMLReader#GetEntityResolver 
		 */
		virtual HRESULT GetEntityResolver(
			CATISAXEntityResolver_var& oEntityResolver);
		/**
		 * Allows an application to register a custom entity resolver.
		 * @see CATISAXXMLReader#SetEntityResolver 
		 */
		virtual HRESULT SetEntityResolver(
			const CATISAXEntityResolver_var& iEntityResolver);
		/**
		 * Retrieves the current error event handler.
		 * @see CATISAXXMLReader#GetErrorHandler 
		 */
		virtual HRESULT GetErrorHandler(
			CATISAXErrorHandler_var& oErrorHandler);
		/**
		 * Allows an application to register an error event handler.
		 * @see CATISAXXMLReader#SetErrorHandler 
		 */
		virtual HRESULT SetErrorHandler(
			const CATISAXErrorHandler_var& iErrorHandler);
		/**
		 * Retrieves the value of a feature.
		 * @see CATISAXXMLReader#GetFeature 
		 */
		virtual HRESULT GetFeature(
			const CATUnicodeString &iName,
			CATBoolean& oFeature);
		/**
		 * Sets the value of a feature.
		 * @see CATISAXXMLReader#SetFeature 
		 */
		virtual HRESULT SetFeature(
			const CATUnicodeString &iName,
			CATBoolean iFeature);
		/**
		 * Retrieves up the value of a property.
		 * @see CATISAXXMLReader#GetProperty
		 */
		virtual HRESULT GetProperty(
			const CATUnicodeString &iName,
			CATBaseUnknown_var& oProperty);
		/**
		 * Sets the value of a property.
		 * @see CATISAXXMLReader#SetProperty
		 */
		virtual HRESULT SetProperty(
			const CATUnicodeString &iName,
			CATBaseUnknown_var iProperty);
		/**
		 * Get the parent reader. 
		 * @param oParent
		 * The parent reader
		 */
		virtual HRESULT GetParent(
			CATISAXXMLReader_var& oParent);	
		/**
		 * Set the parent reader.
		 * This is the @href CATISAXXMLReader from which this filter will obtain its 
		 * events and to which it will pass its configuration requests. The parent may itself be another filter.
		 * If there is no parent reader set, any attempt to parse or to set or get a feature or property will fail.
		 * @param iParent
		 * The parent reader
		 */
		virtual HRESULT SetParent(
			const CATISAXXMLReader_var& iParent);

		// Implementation of the CATISAXContentHandler interface (simply forwards the event to the original handler)
		/**
		 * Receives notification of the beginning of a document.
		 * @see CATISAXContentHandler#StartDocument
		 */
		virtual HRESULT StartDocument();
		/**
		 * Receives notification of the end of a document.
		 * @see CATISAXContentHandler#EndDocument
		 */
		virtual HRESULT EndDocument();
		/**
		 * Receives notification of the beginning of an element.
		 * @see CATISAXContentHandler#StartElement
		 */
		virtual HRESULT StartElement(
			const CATUnicodeString & iURI, 
			const CATUnicodeString & iLocalName, 
			const CATUnicodeString & iQualifiedName, 
			const CATISAXAttributes_var & iAttributes);
		/**
		 * Receives notification of the end of an element.
		 * @see CATISAXContentHandler#EndElement
		 */
		virtual HRESULT EndElement(
			const CATUnicodeString & iURI, 
			const CATUnicodeString & iLocalName, 
			const CATUnicodeString & iQualifiedName);
		/**
		 * Receives notification of character data.
		 * @see CATISAXContentHandler#Characters
		 */
		virtual HRESULT Characters(
			const CATUnicodeString & iCharacters);
		/**
		 * Receives notification of ignorable whitespace in element content.
		 * @see CATISAXContentHandler#IgnorableWhiteSpace
		 */
		virtual HRESULT IgnorableWhiteSpace(
			const CATUnicodeString & iCharacters);
		/**
		 * Receives notification of a processing instruction.
		 * @see CATISAXContentHandler#ProcessingInstruction
		 */
		virtual HRESULT ProcessingInstruction(
			const CATUnicodeString & iTarget, 
			const CATUnicodeString & iData);
		/**
		 * Receives an object for locating the origin of SAX content events.
		 * @see CATISAXContentHandler#SetDocumentLocator
		 */
		virtual HRESULT SetDocumentLocator(
			const CATISAXLocator_var& iLocator);
		/**
		 * Receives notification of the beginning of the scope of a prefix-URI Namespace mapping.
		 * @see CATISAXContentHandler#StartPrefixMapping
		 */
		virtual HRESULT StartPrefixMapping(
			const CATUnicodeString & iPrefix, 
			const CATUnicodeString & iURI);
		/**
		 * Receives notification of the end of the scope of a prefix-URI Namespace mapping.
		 * @see CATISAXContentHandler#EndPrefixMapping
		 */
		virtual HRESULT EndPrefixMapping(
			const CATUnicodeString & iPrefix);
		/**
		 * Receives notification of a skipped entity.
		 * @see CATISAXContentHandler#SkippedEntity
		 */
		virtual HRESULT SkippedEntity(
			const CATUnicodeString & iName);

		// Implementation of the CATISAXErrorHandler interface (simply forwards the event to the original handler)
		/**
		 * Receives notification of a recoverable error.
		 * @see CATISAXErrorHandler#Error
		 */
		virtual HRESULT Error(
			CATSAXParseException* iException);
		/**
		 * Receives notification of a non-recoverable error.
		 * @see CATISAXErrorHandler#FatalError
		 */
		virtual HRESULT FatalError(
			CATSAXParseException* iException);
		/**
		 * Receives notification of a warning.
		 * @see CATISAXErrorHandler#Warning
		 */
		virtual HRESULT Warning(
			CATSAXParseException* iException);

		// Implementation of the CATISAXDTDHandler interface (simply forwards the event to the original handler)
		/**
		 * Receives notification of a notation declaration event.
		 * @see CATISAXDTDHandler#NotationDecl
		 */
		virtual HRESULT NotationDecl(
			const CATUnicodeString & iName, 
			const CATUnicodeString & iPublicId, 
			const CATUnicodeString & iSystemId);
		/**
		 * Receives notification of an unparsed entity declaration event.
		 * @see CATISAXDTDHandler#NotationDecl
		 */
		virtual HRESULT UnparsedEntityDecl(
			const CATUnicodeString & iName, 
			const CATUnicodeString & iPublicId, 
			const CATUnicodeString & iSystemId, 
			const CATUnicodeString & iNotationName);

		// Implementation of the CATISAXEntityResolver interface (simply forwards the event to the original handler)
		/**
		 * Allows the application to resolve external entities.
		 * @see CATISAXEntityResolver#ResolveEntity
		 */
		virtual HRESULT ResolveEntity(
			const CATUnicodeString & iPublicId, 
			const CATUnicodeString & iSystemId, 
			CATISAXInputSource_var& oInputSource);

	private:
		CATSAXDefaultXMLFilter (CATSAXDefaultXMLFilter &);
		CATSAXDefaultXMLFilter& operator=(CATSAXDefaultXMLFilter&);
		HRESULT _Setup();
		HRESULT _Cleanup();

	protected:
		/**
		 * The parent reader. When you overwrite one of methods of the default filter,
		 * you can use this member to get access to the old method from the new method.
		 */
		CATISAXXMLReader_var _parent;

	private:
		CATISAXContentHandler_var _contentHandler;
		CATISAXDTDHandler_var _dtdHandler;
		CATISAXErrorHandler_var _errorHandler;
		CATISAXEntityResolver_var _entityResolver;
};

#endif // CATSAXDefaultXMLFilter_h
