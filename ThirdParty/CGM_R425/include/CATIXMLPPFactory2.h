#ifndef CATIXMLPPFactory2_h
#define CATIXMLPPFactory2_h

// COPYRIGHT DASSAULT SYSTEMES 2010

// System framework
#include "CATUnicodeString.h"
#include "CATBaseUnknown.h"
#include "CATListOfCATUnicodeString.h"

// XMLParser framework
#include "CatXmlItfBase.h"
class CATIXMLPPWriter_var;
class CATIXMLPPOutputSource_var;
class CATXMLPPMemoryBuffer;
class CATISAXInputSource_var;
class CATIXMLPPReader_var;
#include "CATISAXEntityResolver.h"

/**
 * CLSID of the Xerces IBM pull parser.
 */
extern ExportedByCatXmlItfBase CLSID CLSID_XML4C5_PP;

/**
 * CLSID of the XmlLite IBM pull parser.
 */
extern ExportedByCatXmlItfBase CLSID CLSID_MSXML_PP;

/**
 * CLSID of the libxml2 pull parser.
 */
extern ExportedByCatXmlItfBase CLSID CLSID_LIBXML2_PP;

#ifndef LOCAL_DEFINITION_FOR_IID
	extern ExportedByCatXmlItfBase IID IID_CATIXMLPPFactory2;
#else // LOCAL_DEFINITION_FOR_IID
	extern "C" const IID IID_CATIXMLPPFactory2 ;
#endif // LOCAL_DEFINITION_FOR_IID

/**
 * Factory interface for objects of the XML writer API.
 * See @href CATIXMLPPOutputSource and @href CATIXMLPPWriter objects.
 */
class ExportedByCatXmlItfBase CATIXMLPPFactory2 : public CATBaseUnknown {
	CATDeclareInterface;
	public:
		/**
		 * Creates a new CATIXMLPPOutputSource to write XML
		 * in a file.
		 * @param iXMLFilePath
		 * The absolute path of the XML write to generate
		 * @param oOutputSource
		 * The resulting CATIXMLPPOutputSource which will be used
		 * to write in this XML file
		 */
		virtual HRESULT CreateOutputSourceFromFile(
			const CATUnicodeString& iXMLFilePath,
			CATIXMLPPOutputSource_var& oOutputSource) = 0;

		/**
		 * Creates a new CATIXMLPPOutputSource to write XML
		 * in a memory buffer.
		 * @param iBuffer
		 * A memory buffer object
		 * @param oOutputSource
		 * The resulting CATIXMLPPOutputSource which will be used
		 * to write in this memory buffer
		 */
		virtual HRESULT CreateOutputSourceFromMemoryBuffer(
			const CATXMLPPMemoryBuffer& iBuffer,
			CATIXMLPPOutputSource_var& oOutputSource) = 0;

		/**
		 * Creates a new CATIXMLPPWriter to write XML
		 * in a memory buffer.
		 * @param iOutputSource
		 * An output source to store the generated XML
		 * @param oXMLWriter
		 * The resulting CATIXMLPPWriter which will be used
		 * to write in this memory buffer
		 * @param iOptions
		 * The names of the options to set
		 * @param iOptionValues
		 * The values of the options to set.
		 * The current list of options is
		 * <table border="1">
		 * <tr bgcolor="a4f4a4">
		 *  <td><b>Option name</b></td>
		 *  <td><b>Description</b></td>
		 *  <td><b>Possible values</b></td>
		 *  <td><b>Default value</b></td>
		 * </tr>
		 * <tr>
		 *  <td>CATEncoding</td>
		 *  <td>The value for the 'encoding' attribute of the XML header.
		 *      The recommended value is UTF-8.</td>
		 *  <td>encoding value</td><td>UTF-8</td>
		 * </tr>
		 * <tr>
		 *  <td>CATSortAttributes</td>
		 *  <td>Sorts the attributes of each elements alphabetically.</td>
		 *  <td>true or false</td><td>false</td>
		 * </tr>
		 * <tr>
		 *  <td>CATIndentation</td>
		 *  <td>Controls how the output is formatted to produce human-readable indented XML.</td>
		 *  <td>A positive or null integer specifying the number of 
		 *      indentation characters to insert before each element</td>
		 *  <td>0 (no identation)</td>
		 * </tr>
		 * <tr>
		 *  <td>CATIndentationCharacter</td>
		 *  <td>Specifies the indentation character to use when indentation is requested.</td>
		 *  <td>A valid indentation character (space or tab)</td>
		 *  <td>space</td>
		 * </tr>
		 * </table>
		 */
		virtual HRESULT CreateXMLWriter(
			const CATIXMLPPOutputSource_var& iOutputSource,
			CATIXMLPPWriter_var & oXMLWriter,
			const CATListOfCATUnicodeString& iOptions = CATListOfCATUnicodeString(),
			const CATListOfCATUnicodeString& iOptionValues = CATListOfCATUnicodeString()) = 0;
			
		/**
		 * Creates a new instance of a pull parser.
		 * @param iSource
		 * A XML source to parse
		 * @param oReader
		 * The result pull parser
		 * @param iOptions
		 * The names of the options to set
		 * The current list of options is
		 * <table border="1">
		 * <tr bgcolor="a4f4a4">
		 *  <td><b>Option name</b></td>
		 *  <td><b>Description</b></td>
		 *  <td><b>Possible values</b></td>
		 *  <td><b>Default value</b></td>
		 * </tr>
		 * <tr>
		 *  <td>CATResolveExternalEntities</td>
		 *  <td>Specifies if the reader should load external entities such as DTDs</td>
		 *  <td>true or false</td>
		 *  <td>true</td>
		 * </tr>
		 * </table>
		 * @param iOptionValues
		 * The values of the options to set
		 * @param iEntityResolver
		 * An optional @href CATISAXEntityResolver which can be used to resolve entities during parse
		 * The current node type
		 */
		virtual HRESULT CreateReader(
			const CATISAXInputSource_var& iSource,
			CATIXMLPPReader_var& oReader,
			const CATListOfCATUnicodeString& iOptions = CATListOfCATUnicodeString(),
			const CATListOfCATUnicodeString& iOptionValues = CATListOfCATUnicodeString(),
			const CATISAXEntityResolver_var& iEntityResolver = NULL_var) = 0;
};

CATDeclareHandler(CATIXMLPPFactory2, CATBaseUnknown);

/**
 * Returns the root object which corresponds to a specific implementation of the XML pull parser API.
 * This object is an instance of @href CATIXMLPPFactory2.
 * @param oFactory
 * The resulting <tt>CATIXMLPPFactory2</tt>
 * @param iClsId
 * The CLSID of the <tt>CATIXMLPPFactory2</tt> to instantiate
 * <br><b>Legal values</b>:
 * <tt>CLSID_XML4C5_PP</tt> Use this value to instantiate the implementation based on XML4C 5.0 from IBM.
 */
extern "C" ExportedByCatXmlItfBase HRESULT CreateCATIXMLPPFactory2(
	CATIXMLPPFactory2_var& oFactory,
	const CLSID& iClsId = CLSID_XML4C5_PP);

#endif // CATIXMLPPFactory2_h