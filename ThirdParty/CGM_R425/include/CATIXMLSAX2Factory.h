#ifndef CATIXMLSAX2Factory_h
#define CATIXMLSAX2Factory_h

// COPYRIGHT DASSAULT SYSTEMES 2002

/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */

// System framework
#include "CATUnicodeString.h"
#include "CATBaseUnknown.h"
#include "CATListOfCATUnicodeString.h"

// XMLParser framework
#include "CatXmlItfBase.h"
class CATISAXInputSource_var;
class CATISAXXMLReader_var;
class CATIXMLInputStream_var;

/**
 * CLSID of the XML4C 3.0 IBM SAX parser.
 */
extern ExportedByCatXmlItfBase CLSID CLSID_XML4C_SAX;

/**
 * CLSID of the XML4C 5.0 IBM SAX parser.
 */
extern ExportedByCatXmlItfBase CLSID CLSID_XML4C5_SAX;

/**
 * CLSID of the Xerces 3 SAX parser.
 */
extern ExportedByCatXmlItfBase CLSID CLSID_XMLXER3_SAX;

/**
 * CLSID of the XML4C 5.0 IBM light SAX parser.
 */
extern ExportedByCatXmlItfBase CLSID CLSID_XML4C5L_SAX;

/**
 * CLSID of the MSXML 3.0 Microsoft SAX parser.
 */
extern ExportedByCatXmlItfBase CLSID CLSID_MSXML3_SAX;

/**
 * CLSID of the MSXML 4.0 Microsoft SAX parser.
 */
extern ExportedByCatXmlItfBase CLSID CLSID_MSXML4_SAX;

/**
 * CLSID of the MSXML 5.0 Microsoft SAX parser.
 */
extern ExportedByCatXmlItfBase CLSID CLSID_MSXML5_SAX;

/**
 * CLSID of the MSXML 6.0 Microsoft SAX parser.
 */
extern ExportedByCatXmlItfBase CLSID CLSID_MSXML6_SAX;

/**
 * CLSID of the MSXML Microsoft SAX parser (will look for the
 * highest installed version)
 */
extern ExportedByCatXmlItfBase CLSID CLSID_MSXML_SAX;

/**
 * CLSID of the default SAX parser.
 * On windows: will look for the highest version of MSXML,
 * and if not installed, will look for the highest version of XML4C
 * On unix: will look for the highest version of XML4C
 */
extern ExportedByCatXmlItfBase CLSID CLSID_DEFAULT_SAX;

/**
 * CLSID of the libxml2 SAX parser.
 */
extern ExportedByCatXmlItfBase CLSID CLSID_LIBXML2_SAX;

#ifndef LOCAL_DEFINITION_FOR_IID
	extern ExportedByCatXmlItfBase IID IID_CATIXMLSAX2Factory;
#else // LOCAL_DEFINITION_FOR_IID
	extern "C" const IID IID_CATIXMLSAX2Factory ;
#endif // LOCAL_DEFINITION_FOR_IID

/**
 * Factory interface for SAX objects.
 * @href CATISAXInputSource and @href CATISAXXMLReader objects.
 */
class ExportedByCatXmlItfBase CATIXMLSAX2Factory : public CATBaseUnknown {
	CATDeclareInterface;
	public:

		/**
		 * Creates a CATISAXInputSource from the supplied file.
		 *
		 * @param iFileName
		 * The path of the file
		 * @param iPublicId
		 * The public id which will be assigned to the input source.
		 * @param oInputSource
		 * The resulting CATISAXInputSource
		 */
		virtual HRESULT CreateInputSourceFromFile(
			const CATUnicodeString & iFileName, 
			const CATUnicodeString & iPublicId, 
			CATISAXInputSource_var & oInputSource ) = 0;

		/**
		 * Creates a CATISAXInputSource from the supplied memory buffer.
		 *
		 * @param iBuffer
		 * A buffer containing XML text
		 * @param iPublicId
		 * The public id which will be assigned to the input source.
		 * @param oInputSource
		 * The resulting CATISAXInputSource
		 */
		virtual HRESULT CreateInputSourceFromMemoryBuffer(
			const CATUnicodeString & iBuffer, 
			const CATUnicodeString & iPublicId, 
			CATISAXInputSource_var & oInputSource ) = 0;

		/**
		 * Creates a CATISAXXMLReader.
		 *
		 * <p>No options are required since SAX defines a standard way to
		 * pass them to the reader</p>
		 *
		 * @param oParser
		 * The resulting CATISAXParser
		 */
		virtual HRESULT CreateXMLReader(
			CATISAXXMLReader_var & oXMLReader ) = 0;

		/**
		 * Creates a CATISAXInputSource from the supplied stream.
		 * @param iStream
		 * A stream from which XML contents will be fetched
		 * @param iPublicId
		 * The public id which will be assigned to the input source
		 * @param oInputSource
		 * The resulting CATISAXInputSource
		 */
		virtual HRESULT CreateInputSourceFromStream(
			const CATIXMLInputStream_var & iStream, 
			const CATUnicodeString & iPublicId, 
			CATISAXInputSource_var & oInputSource ) = 0;
};

CATDeclareHandler(CATIXMLSAX2Factory, CATBaseUnknown);

/**
 * Returns the root object which corresponds to a specific SAX implementation.
 * This object is an instance of @href CATIXMLSAX2Factory.
 * @param oFactory
 * The resulting <tt>CATIXMLSAX2Factory</tt>
 * @param iClsId
 * The CLSID of the <tt>CATIXMLSAX2Factory</tt> to instantiate
 * <br><b>Legal values</b>:
 * <tt>CLSID_XML4C_SAX</tt> Use this value to instantiate the implementation based on XML4C 3.0 from IBM. 
 * This implementation supports DTD validation but not XML schema validation.
 * <tt>CLSID_XML4C5_SAX</tt> Use this value to instantiate the implementation based on XML4C 5.0 from IBM.
 * This implementation supports both DTD and XML schema validation.
 */
extern "C" ExportedByCatXmlItfBase HRESULT CreateCATIXMLSAX2Factory(
	CATIXMLSAX2Factory_var& oFactory,
	const CLSID& iClsId = CLSID_XML4C_SAX);

/**
 * Examines the SAX implementations available on the host.
 * The function sequentially examines each of the supplied SAX implementation CLSIDs
 * until one is found, which is installed on the host.
 * @param iClsIdArray
 * An array of SAX implementation CLSIDs that the function should try to detect
 * @param iClsIdArraySize
 * The size of the CLSID array
 * @param oFirstAvailableIndex
 * The array index of the first SAX implementation which was succesfully detected on the machine
 */
extern "C" ExportedByCatXmlItfBase HRESULT DetectCATIXMLSAXFactory(
	CLSID* iClsIdArray,
	unsigned int iClsIdArraySize,
	unsigned int& oFirstAvailableIndex);

#endif // CATIXMLSAX2Factory_h
