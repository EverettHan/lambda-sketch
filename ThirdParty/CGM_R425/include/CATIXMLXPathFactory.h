#ifndef CATIXMLXPathFactory_h
#define CATIXMLXPathFactory_h

// COPYRIGHT DASSAULT SYSTEMES 2007

/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */

// System framework
#include "CATUnicodeString.h"
#include "CATBaseUnknown.h"
class CATIXMLXPathExpression_var;

// XMLParser framework
#include "CatXmlItfExt.h"

#ifndef LOCAL_DEFINITION_FOR_IID
    extern ExportedByCatXmlItfExt IID IID_CATIXMLXPathFactory;
#else // LOCAL_DEFINITION_FOR_IID
    extern "C" const IID IID_CATIXMLXPathFactory ;
#endif // LOCAL_DEFINITION_FOR_IID

/**
 * Interface to instantiate XPath expressions. 
 * <strong>Role</strong>: This interface is used to create XPath expressions.
 * These XPath expressions use as a context node the DOM node which implements
 * the interface. This context node can be either a CATIDOMDocument or a
 * CATIDOMElement node. 
 * <p>The following code sample shows how an CATIXMLXPathFactory can be
 * obtained from a CATIDOMElement to create and evaluate an XPath expression.
 * </p>
 * <pre>
 * CATIDOMElement_var x = ...;
 * CATIXMLXPathFactory factory = x;
 * if (factory != NULL_var) {
 *     CATIXMLXPathExpression_var xPath;
 *     hr = factory->CreateExpression("foo/bar", xPath);
 *     if (SUCCEEDED(hr) && (xPath != NULL_var)) {
 *          CATIDOMNodeList_var nodeList;
 *          hr = xPath->EvaluateAsNodeList(nodeList);
 *     }
 * }
 * </pre>
 * @see CATIXMLXPathExpression
 */
class ExportedByCatXmlItfExt CATIXMLXPathFactory : public CATBaseUnknown {
    CATDeclareInterface;
    public:
        /**
         * Creates a new XPath expression.
         * @param iExpression
         * The text of the XPath expression.
         * @param oPath
         * The XPath expression represented by this object.
         * @return
         * If the method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
         */
        virtual HRESULT CreateExpression(
            const CATUnicodeString& iExpression,
            CATIXMLXPathExpression_var& oPath) = 0;
};

CATDeclareHandler(CATIXMLXPathFactory, CATBaseUnknown);

#endif // CATIXMLXPathFactory_h
