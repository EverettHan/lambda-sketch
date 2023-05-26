#ifndef CATIXMLXSLTransformer_h
#define CATIXMLXSLTransformer_h

// System framework
#include "CATBaseUnknown.h"
#include "CATListOfCATUnicodeString.h"
#include "CATUnicodeString.h"

// XMLParser framework
#include "CatXmlItfExt.h"
class CATISAXInputSource_var;
class CATIXMLPPOutputSource_var;

#ifndef LOCAL_DEFINITION_FOR_IID
	extern ExportedByCatXmlItfExt IID IID_CATIXMLXSLTransformer;
#else // LOCAL_DEFINITION_FOR_IID
	extern "C" const IID IID_CATIXMLXSLTransformer ;
#endif // LOCAL_DEFINITION_FOR_IID

/**
 * Interface to represent an XSLT transformation.
 * Users must first specify an input source on which the transformation
 * will be applied; then an output source where the result of the transformation
 * will be stored; finally, they must invoke the <code>Transform</code> method.
 * @href CATISAXInputSource and @href CATISAXXMLReader objects.
 */
class ExportedByCatXmlItfExt CATIXMLXSLTransformer : public CATBaseUnknown {
	CATDeclareInterface;
	public:
		/**
		 * Returns the name and namespace of all the XSLT parameters
		 * defined for this transformer
		 * @param oParameterNames
		 * A list of parameter names
		 * @param oParameterNamespaces
		 * A list of parameter namespaces
		 */
		virtual HRESULT GetDefinedParameters(
			CATListOfCATUnicodeString& oParameterNames,
			CATListOfCATUnicodeString& oParameterNamespaces) = 0;
		
		/**
		 * Returns the value of the specified XSLT parameter.
		 * @param iParameterName
		 * The parameter name
		 * @param iParameterNamespace
		 * The parameter namespace
		 * @param oValue
		 * The parameter value
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
		 *        <td class="errtd">@href CATSAXParseException</td>
		 *        <td class="errtd">XMLParserERR_2100</td>
		 *        <td class="errtd">Parameter is not set</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 */
		virtual HRESULT GetParameter(
			const CATUnicodeString& iParameterName,
			const CATUnicodeString& iParameterNamespace,
			CATUnicodeString& oParameterValue) = 0;

		/**
		 * Sets the value of the specified XSLT parameter.
		 * @param iParameterName
		 * The parameter name
		 * @param iParameterNamespace
		 * The parameter namespace
		 * @param iValue
		 * The parameter value
		 */
		virtual HRESULT SetParameter(
			const CATUnicodeString& iParameterName,
			const CATUnicodeString& iParameterNamespace,
			const CATUnicodeString& iParameterValue) = 0;

		/**
		 * Removes all the XSLT parameters
		 */
		virtual HRESULT ClearParameters() = 0;

		/**
		 * Returns the names of all the configuration options currently
		 * specified for this transformer
		 */
		virtual HRESULT GetDefinedOptions(
			CATListOfCATUnicodeString& oOptionNames) = 0;

		/**
		 * Returns the value of the specified configuration options
		 * @param iOptionName
		 * The option name
		 * @param oOptionValue
		 * The option value
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
		 *        <td class="errtd">@href CATSAXParseException</td>
		 *        <td class="errtd">XMLParserERR_2900</td>
		 *        <td class="errtd">Option is not set</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 */
		virtual HRESULT GetOption(
			const CATUnicodeString& iOptionName,
			CATUnicodeString& oOptionValue) = 0;

		/**
		 * Sets the value of the specified configuration options
		 * @param iOptionName
		 * The option name
		 * @param iOptionValue
		 * The option value
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
		 *        <td class="errtd">@href CATSAXParseException</td>
		 *        <td class="errtd">XMLParserERR_2901</td>
		 *        <td class="errtd">Unsupported option</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATSAXParseException</td>
		 *        <td class="errtd">XMLParserERR_2902</td>
		 *        <td class="errtd">Invalid value for option</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 */
		virtual HRESULT SetOption(
			const CATUnicodeString& iOptionName,
			const CATUnicodeString& iOptionValue) = 0;

		/**
		 * Returns the XML input source which
		 * contains the XSLT stylesheet applied by this transformer
		 * @param oXslSource
		 * An XSLT stylesheet source 
		 */
		virtual HRESULT GetXslSource(
			CATISAXInputSource_var& oXslSource) = 0;

		/**
		 * Returns the XML input source to be transformed
		 * by this transformer
		 * @param oSource
		 * An XML input source 
		 */
		virtual HRESULT GetInputSource(
			CATISAXInputSource_var& oSource) = 0;

		/**
		 * Sets the XML input source to be transformed
		 * by this transformer
		 * @param oSource
		 * An XML input source 
		 */
		virtual HRESULT SetInputSource(
			const CATISAXInputSource_var& iSource) = 0;

		/**
		 * Returns the output source where the result
		 * of the transformation is stored
		 * @param oSource
		 * An XML output source 
		 */
		virtual HRESULT GetOutputSource(
			CATIXMLPPOutputSource_var& oSource) = 0;

		/**
		 * Sets the output source where the result
		 * of the transformation is stored
		 * @param oSource
		 * An XML output source 
		 */
		virtual HRESULT SetOutputSource(
			const CATIXMLPPOutputSource_var& iSource) = 0;

		/**
		 * Runs the XSLT transformation on the 
		 * configured input source, storing the result
		 * in the configured output source.
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
		 *        <td class="errtd">@href CATSAXParseException</td>
		 *        <td class="errtd">XMLParserERR_2910</td>
		 *        <td class="errtd">No input source specified</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATSAXParseException</td>
		 *        <td class="errtd">XMLParserERR_2911</td>
		 *        <td class="errtd">No output source specified</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATSAXParseException</td>
		 *        <td class="errtd">XMLParserERR_2912</td>
		 *        <td class="errtd">Execution error</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 */
		virtual HRESULT Transform() = 0;
};

CATDeclareHandler(CATIXMLXSLTransformer, CATBaseUnknown);


#endif // CATIXMLXSLTransformer_h
