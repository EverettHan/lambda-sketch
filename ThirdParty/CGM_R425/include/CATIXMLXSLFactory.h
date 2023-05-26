#ifndef CATIXMLXSLFactory_h
#define CATIXMLXSLFactory_h

// System framework
#include "CATBaseUnknown.h"

// XMLParser framework
#include "CatXmlItfExt.h"
class CATISAXInputSource_var;
class CATIXMLXSLTransformer_var;

#ifndef LOCAL_DEFINITION_FOR_IID
	extern ExportedByCatXmlItfExt IID IID_CATIXMLXSLFactory;
#else // LOCAL_DEFINITION_FOR_IID
	extern "C" const IID IID_CATIXMLXSLFactory ;
#endif // LOCAL_DEFINITION_FOR_IID

/**
 * CLSID of the MSXML Microsoft XSLT processor.
 */
extern ExportedByCatXmlItfExt CLSID CLSID_XSLT_MSXML;

/**
 * CLSID of the Xalan XSLT processor.
 */
extern ExportedByCatXmlItfExt CLSID CLSID_XSLT_XALAN;

/**
 * CLSID of the Java XSLT processor.
 */
extern ExportedByCatXmlItfExt CLSID CLSID_XSLT_JAVA;

/**
 * CLSID of the .NET XSLT processor.
 */
extern ExportedByCatXmlItfExt CLSID CLSID_XSLT_DOTNET;

/**
 * CLSID of the default XSLT processor.
 */
extern ExportedByCatXmlItfExt CLSID CLSID_XSLT_DEFAULT;


/**
 * Factory interface for XSLT transformations.
 * @href CATISAXInputSource and @href CATISAXXMLReader objects.
 */
class ExportedByCatXmlItfExt CATIXMLXSLFactory : public CATBaseUnknown {
	CATDeclareInterface;
	public:
		/**
		 * Creates a CATIXMLXSLTransformer for the specified XSL.
		 * stylesheet
		 * @param iXslSource
		 * An XML input source containing the XSLT stylesheet to apply.
		 * @param oTransformer
		 * A transformer object configured for the specified XSLT stylesheet
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
		 */
		virtual HRESULT CreateTransformer(
			const CATISAXInputSource_var& iXslSource, 
			CATIXMLXSLTransformer_var & oTransformer ) = 0;

};

CATDeclareHandler(CATIXMLXSLFactory, CATBaseUnknown);

/**
 * Returns the root object which corresponds to a specific XSLT implementation.
 * This object is an instance of @href CATIXMLXSLFactory.
 * @param oFactory
 * The resulting <tt>CATIXMLXSLFactory</tt>
 * @param iClsId
 * The CLSID of the <tt>CATIXMLXSLFactory</tt> to instantiate
 * <br><b>Legal values</b>:
 * <tt>CLSID_XSLT_MSXML</tt> Use this value to instantiate the implementation based on MSXML.
 * <tt>CLSID_XSLT_XALAN</tt> Use this value to instantiate the implementation based on Xalan.
 * <tt>CLSID_XSLT_JAVA</tt> Use this value to instantiate the implementation based on an external Java process.
 * <tt>CLSID_XSLT_DOTNET</tt> Use this value to instantiate the implementation based on an external .NET process.
 */
extern "C" ExportedByCatXmlItfExt HRESULT CreateCATIXMLXSLFactory(
	CATIXMLXSLFactory_var& oFactory,
	const CLSID& iClsId = CLSID_XSLT_JAVA);

/**
 * Examines the XSLT implementations available on the host.
 * The function sequentially examines each of the supplied XSLT implementation CLSIDs
 * until one is found, which is installed on the host.
 * @param iClsIdArray
 * An array of XSLT implementation CLSIDs that the function should try to detect
 * @param iClsIdArraySize
 * The size of the CLSID array
 * @param oFirstAvailableIndex
 * The array index of the first XSLT implementation which was succesfully detected on the machine
 */
extern "C" ExportedByCatXmlItfExt HRESULT DetectCATIXMLXSLFactory(
	CLSID* iClsIdArray,
	unsigned int iClsIdArraySize,
	unsigned int& oFirstAvailableIndex);
	
#endif // CATIXMLXSLFactory_h
