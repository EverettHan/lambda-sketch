// COPYRIGHT DASSAULT SYSTEMES 2002

/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */

#ifndef CATIDOMAttr_h
#define CATIDOMAttr_h

// System framework
#include "CATBoolean.h"
class CATUnicodeString;

// XMLParser framework
#include "CatXmlItfExt.h"
#include "CATIDOMNode.h"
class CATIDOMElement_var;

#ifndef LOCAL_DEFINITION_FOR_IID
	extern ExportedByCatXmlItfExt IID IID_CATIDOMAttr;
#else // LOCAL_DEFINITION_FOR_IID
	extern "C" const IID IID_CATIDOMAttr ;
#endif // LOCAL_DEFINITION_FOR_IID

/**
 * Interface that refers to an attribute of an XML element.
 *
 * Typically the allowable values for the 
 * attribute are defined in a document type definition.
 * <p>@href CATIDOMAttr objects inherit the @href CATIDOMNode
 * interface, but since attributes are not actually child nodes of the 
 * elements they are associated with, the 
 * DOM does not consider them part of the document tree. Thus, the returned
 * @href CATIDOMNode value for the @href CATIDOMNode#GetParentNode,  
 * @href CATIDOMNode#GetPreviousSibling, and @href CATIDOMNode#GetNextSibling is <tt>NULL_var</tt>
 * for @href CATIDOMAttr objects. The DOM takes the view that 
 * attributes are properties of elements rather than having a separate 
 * identity from the elements they are associated with ; this should make it 
 * more efficient to implement such features as default attributes associated 
 * with all elements of a given type. Furthermore, attribute nodes 
 * may not be immediate children of a @href CATIDOMDocumentFragment. However, 
 * they can be associated with @href CATIDOMElement nodes contained within a 
 * @href CATIDOMDocumentFragment. In short, users of the DOM 
 * need to be aware that @href CATIDOMAttr nodes have some things in common 
 * with other objects inheriting the @href CATIDOMNode interface, but they 
 * also are quite distinct.
 * @see CATIDOMNode, CATIDOMDocumentFragment, CATIDOMElement
 */
class ExportedByCatXmlItfExt CATIDOMAttr: public CATIDOMNode {
  CATDeclareInterface;

	public:

		/**
		 * Retrieves the name of this attribute.
		 *
		 * @param oName
		 * The name of this attribute.
		 */
		virtual HRESULT GetName(
			CATUnicodeString& oName) = 0;
		
		/**
		 * Returns wether the attribute's value was specified or not.
		 * Returns <tt>TRUE</tt> if the attribute received its value explicitly in the
		 * XML document, or if a value was assigned programatically with
		 * the @href #SetValue function.
		 * Returns <tt>FALSE</tt> if the attribute value 
		 * came from the default value declared in the document's DTD.
		 *
		 * @param oIsSpecified
		 * The retrieved boolean specifying wether the attribute's value was specified or not.
		 *
		 */
		virtual HRESULT GetSpecified(
			CATBoolean& oIsSpecified) = 0;
		
		/**
		 * Retrieves the value of the attribute.
		 *
		 * The value of the attribute is returned as a string. 
		 * Character and general entity references are replaced with their values.
		 *
		 * @param oValue
		 * The retrieved value of the attribute.
		 */
		virtual HRESULT GetValue(
			CATUnicodeString& oValue) = 0;
		
		/**
		 * Sets the value of the attribute.
		 * A @href CATIDOMText node with the unparsed contents
		 * of the string will be created.
		 *
		 * @param iValue
		 * The value of the DOM attribute to be set.
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
		 *        <td class="errtd">@href CATDOMException </td>
		 *        <td class="errtd">XMLParserERR_2207</td>
		 *        <td class="errtd">NO_MODIFICATION_ALLOWED_ERR: Raised if this node is readonly.</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 */
		virtual HRESULT SetValue(
			const CATUnicodeString& iValue) = 0;
		
		/**
		 * Retrieves the <code>CATIDOMElement</code> node this attribute is attached.
		 * <tt>oOwnerElement</tt> is set to <tt>NULL_var</tt> if this attribute is not in use.
		 *
		 * @param oOwnerElement
		 * The retrieved @href CATIDOMElement node this attribute is attached.
		 */
		virtual HRESULT GetOwnerElement(
			CATIDOMElement_var & oOwnerElement) = 0;
};

CATDeclareHandler(CATIDOMAttr, CATIDOMNode);

#endif // CATIDOMAttr_h

