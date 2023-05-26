// COPYRIGHT DASSAULT SYSTEMES 2002

/**
 * @CAA2Level L1
 * @CAA2Usage U5
 */

#ifndef CATISAXXMLFilter_h
#define CATISAXXMLFilter_h

// System framework
#include "CATBoolean.h"
class CATUnicodeString;

// XMLParser framework
#include "CATISAXXMLReader.h"
#include "CatXmlItfBase.h"
class CATISAXXMLReader_var;

#ifndef LOCAL_DEFINITION_FOR_IID
	extern ExportedByCatXmlItfBase IID IID_CATISAXXMLFilter;
#else // LOCAL_DEFINITION_FOR_IID
	extern "C" const IID IID_CATISAXXMLFilter ;
#endif // LOCAL_DEFINITION_FOR_IID

/**
 * Interface for an XML filter.
 *
 * <p>An XML filter is like an XML reader, except that it obtains its
 * events from another XML reader rather than a primary source like
 * an XML document or database.  Filters can modify a stream of
 * events as they pass on to the final application.</p>
 *
 * <p>The @href CATSAXDefaultXMLFilter helper class provides a convenient base
 * for creating SAX2 filters, by passing on all @href CATISAXEntityResolver, 
 * @href CATISAXDTDHandler, @href CATISAXContentHandler and @href CATISAXErrorHandler events automatically.</p>
 *
 * @see CATISAXXMLReader, CATSAXDefaultXMLFilter
 */
class ExportedByCatXmlItfBase CATISAXXMLFilter : public CATISAXXMLReader {
	CATDeclareInterface;
	
	public:
		
		/**
		 * Retrieves the parent reader.
		 *
		 * <p>This method allows the application to query the parent reader (which may be another filter). 
		 * It is generally a bad idea to perform any operations on the parent reader directly: 
		 * they should all pass through this filter.</p>
		 *
		 * @param oParent
		 * The parent reader, or <tt>NULL_var</tt> if none has been set.
		 *
		 * @see #SetParent
		 */
		virtual HRESULT GetParent(
			CATISAXXMLReader_var& oParent) = 0;
		
		/**
		 * Sets the parent reader.
		 *
		 * <p>This method allows the application to link the filter to a parent reader (which may be another filter). 
		 * The argument may not be <tt>NULL_var</tt>.</p>
		 *
		 * @param iParent
		 * The parent reader.
		 *
		 * @see #SetParent
		 */
		virtual HRESULT SetParent(
			const CATISAXXMLReader_var& iParent) = 0;
};

CATDeclareHandler(CATISAXXMLFilter, CATBaseUnknown);

#endif // CATISAXXMLFilter_h
