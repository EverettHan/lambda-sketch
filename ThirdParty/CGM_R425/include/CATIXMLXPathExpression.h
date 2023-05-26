#ifndef CATIXMLXPathExpression_h
#define CATIXMLXPathExpression_h

// COPYRIGHT DASSAULT SYSTEMES 2007

/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */

// System framework
#include "CATUnicodeString.h"
#include "CATBaseUnknown.h"
#include "CATListOfCATUnicodeString.h"

// XMLParserItf framework
#include "CatXmlItfExt.h"
class CATIDOMNodeList_var;
class CATIDOMNode_var;

#ifndef LOCAL_DEFINITION_FOR_IID
    extern ExportedByCatXmlItfExt IID IID_CATIXMLXPathExpression;
#else // LOCAL_DEFINITION_FOR_IID
    extern "C" const IID IID_CATIXMLXPathExpression ;
#endif // LOCAL_DEFINITION_FOR_IID

/**
 * Interface to represent an XPath expression. 
 * <strong>Role</strong>: An XPath expression represents a
 * path in a DOM tree from a root node (called the context
 * node) to a set of target nodes (called the result set nodes).
 * XPath expressions can be used to retrieve nodes from a DOM tree
 * and make DOM programs more compact.
 * @see CATIXMLXPathFactory
 */
class ExportedByCatXmlItfExt CATIXMLXPathExpression : public CATBaseUnknown {
    CATDeclareInterface;
    public:
        /**
         * Returns the XPath expression represented by this object.
         * @param oExpression
         * The XPath expression represented by this object.
         * @return
         * If the method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
         */
        virtual HRESULT GetExpression(
            CATUnicodeString& oExpression) = 0;

        /**
         * Returns the context node for this expression. 
		 * The context node is the DOM node (either a CATIDOMElement_var 
         * or a CATIDOMDocument_var instance) where the expression evaluation will begin.
         * @param oContext
         * The context node for this expression.
         * @return
         * If the method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
         */
        virtual HRESULT GetContext(
            CATIDOMNode_var& oContext) = 0;

        /**
         * Evaluates an XPath expression of type &quot;node list&quot; and returns its result set.
         * The expression must evaluate to a node list (as opposed to a boolean, a string or
         * a number), or an error will be returned. The expression may evaluate to an empty node list.
         * @param oResult
         * The result set obtained by evaluating this expression.
         * @return
         * If the method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
         */
        virtual HRESULT EvaluateAsNodeList(
            CATIDOMNodeList_var& oResult) = 0;

        /**
         * Evaluates an XPath expression of type &quot;node list&quot; and returns the
         * first item in its result set. 
         * The expression must evaluate to a node list (as opposed to a boolean, 
         * a string or a number), or an error will be returned.
         * If the expression evaluates to an empty list, NULL_var is returned.
         * @param oResult
         * The first node of the result set, or NULL_var if no node matches the expression.
         * @return
         * If the method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
         */
        virtual HRESULT EvaluateAsNode(
            CATIDOMNode_var& oResult) = 0;

        /**
         * Specifies the binding of prefixes used in this XPath expression. 
         * You must define one such binding for each prefix your
         * XPath expression uses before invoking EvaluateAsNodeList or EvaluateAsNode.
         * @iPrefixes a list of prefixes used by this XPath expression.
         * @iNamespaceURIs the namespace URIs corresponding to prefixes specified in iPrefixes.
         * @return
         * If the method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
         */

        virtual HRESULT SetNamespacePrefixes(
            const CATListOfCATUnicodeString& iPrefixes, 
            const CATListOfCATUnicodeString& iNamespaceURIs) = 0;
        
        /**
         * Returns the binding of prefixes used in this XPath expression. 
         * You must define one such binding for each prefix your
         * XPath expression uses before invoking EvaluateAsNodeList or EvaluateAsNode.
         * @iPrefixes a list of prefixes used by this XPath expression.
         * @iNamespaceURIs the namespace URIs corresponding to prefixes specified in iPrefixes.
         * @return
         * If the method succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.
         */
        virtual HRESULT GetNamespacePrefixes(
            CATListOfCATUnicodeString& oPrefixes, 
            CATListOfCATUnicodeString& oNamespaceURIs) = 0;
};

CATDeclareHandler(CATIXMLXPathExpression, CATBaseUnknown);

#endif // CATIXMLXPathExpression_h
