// COPYRIGHT DASSAULT SYSTEMES 2002

/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */

#ifndef CATISAXInputSource_h
#define CATISAXInputSource_h

// System framework
#include "CATBaseUnknown.h"
class CATUnicodeString;

// XMLParser framework
#include "CatXmlItfBase.h"


#ifndef LOCAL_DEFINITION_FOR_IID
	extern ExportedByCatXmlItfBase IID IID_CATISAXInputSource;
#else // LOCAL_DEFINITION_FOR_IID
	extern "C" const IID IID_CATISAXInputSource;
#endif // LOCAL_DEFINITION_FOR_IID

/**
  * Interface to represent a single input source for an XML entity.
  *
  * <p>This interface encapsulates information about an input source in a
  * single object, which may include a public identifier or a system
  * identifier</p>
  *
  * <p>There are two places where the application will deliver this input
  * source to the parser: as the argument to the @href CATISAXXMLReader#Parse method, or as
  * the return value of the @href CATISAXEntityResolver#ResolveEntity method.</p>
  *
  * <p>A @href CATISAXInputSource encapsulates particular types of input sources. Implementations are
  * provided for URL input sources, memory buffer input sources, and so on.</p>
  *
  * <p>A @href CATISAXInputSource object belongs to the application: the parser never
  * modifies them in any way. They are always passed by const reference so
  * the parser will make a copy of any input sources that it must keep 
  * around beyond the call.</p>
  *
  * @see CATISAXXMLReader#Parse, CATISAXEntityResolver#ResolveEntity
  */
class ExportedByCatXmlItfBase CATISAXInputSource : public CATBaseUnknown {  
	CATDeclareInterface;

	public:
		/**
		 * Retrieves the name of the encoding that is to be forced.
		 * An input source can be set to force the parser to assume a particular
		 * encoding for the data that input source reprsents, via the #href SetEncoding method.
		 * If the encoding has never been forced, it returns an empty @href CATUnicodeString .
		 *
		 * @param oEncoding 
		 * The forced encoding (can be an empty @href CATUnicodeString if
		 * no forced encoding was given).
		 * @see #SetEncoding
		 */
		virtual HRESULT GetEncoding(
			CATUnicodeString & oEncoding) = 0;
		
		/**
		 * Sets the encoding which will be required for use with the XML text read
		 * via a stream opened by this input source.
		 *
		 * <p>This is usually not set, allowing the encoding to be sensed in the
		 * usual XML way. However, in some cases, the encoding in the file is known
		 * to be incorrect because of intermediate transcoding, for instance
		 * encapsulation within a MIME document.
		 * 
		 * @param iEncoding
		 * The name of the encoding to force.
		 */
		virtual HRESULT SetEncoding(
			const CATUnicodeString & iEncoding) = 0;
		
		/**
		 * Retrieves the public identifier for this input source.
		 *
		 * @param oPublicId
		 * The public identifier (can be an empty @href CATUnicodeString if
		 * no public identifier was given).
		 * @see #SetPublicId
		 */
		virtual HRESULT GetPublicId(
			CATUnicodeString & oPublicId) = 0;
		
		/**
		 * Sets the public identifier for this input source.
		 *
		 * <p>The public identifier is always optional: if the application writer
		 * includes one, it will be provided as part of the location information.</p>
		 *
		 * @param iPublicId
		 * The public identifier as a string.
	 	 * @see CATISAXLocator#GetPublicId, CATSAXParseException#GetPublicId, #GetPublicId
		 */
		virtual HRESULT SetPublicId(
			const CATUnicodeString & iPublicId) = 0;
		
		/**
		 * Retrieves the system identifier for this input source.
		 *
		 * <p>If the system ID is a URL, it will be fully resolved.</p>
		 *
		 * @param oSystemId The system identifier.
		 * @see #SetSystemId
		 */
		virtual HRESULT GetSystemId(
			CATUnicodeString & oSystemId) = 0;
		
		/**
		 * Sets the system identifier for this input source.
		 *
		 * </p>The system id is always required. The public id may be used to map
		 * to another system id, but the system id must always be present as a fall
		 * back.
		 *
		 * <p>If the system ID is a URL, it must be fully resolved.</p>
		 *
		 * @param iSystemId
		 * The system identifier as a string.
		 *
		 * @see #GetSystemId, CATISAXLocator#GetSystemId, CATSAXParseException#GetSystemId
		 */
		virtual HRESULT SetSystemId(
			const CATUnicodeString & iSystemId) = 0;
};

CATDeclareHandler(CATISAXInputSource, CATBaseUnknown);

#endif // CATISAXInputSource_h
