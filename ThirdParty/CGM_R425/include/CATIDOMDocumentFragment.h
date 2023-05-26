// COPYRIGHT DASSAULT SYSTEMES 2002

/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */

#ifndef CATIDOMDocumentFragment_h
#define CATIDOMDocumentFragment_h

// XMLParser framework
#include "CatXmlItfExt.h"
#include "CATIDOMNode.h"

#ifndef LOCAL_DEFINITION_FOR_IID
	extern ExportedByCatXmlItfExt IID IID_CATIDOMDocumentFragment;
#else // LOCAL_DEFINITION_FOR_IID
	extern "C" const IID IID_CATIDOMDocumentFragment ;
#endif // LOCAL_DEFINITION_FOR_IID

/**
 * Interface representing a "lightweight" or "minimal" 
 * <code>CATIDOMDocument</code> object. 
 *
 * It is very common to want to be able to 
 * extract a portion of a document's tree or to create a new fragment of a 
 * document. Imagine implementing a user command like cut or rearranging a 
 * document by moving fragments around. It is desirable to have an object 
 * which can hold such fragments and it is quite natural to use a @href CATIDOMNode for 
 * this purpose. While it is true that a @href CATIDOMDocument object could 
 * fulfil this role,  a @href CATIDOMDocument object can potentially be a 
 * heavyweight  object, depending on the underlying implementation. What is 
 * really needed for this is a very lightweight object.  
 * @href CATIDOMDocumentFragment is such an object.
 * <p>Furthermore, various operations -- such as inserting nodes as children 
 * of another @href CATIDOMNode -- may take @href CATIDOMDocumentFragment 
 * objects as arguments;  this results in all the child nodes of the 
 * @href CATIDOMDocumentFragment being moved to the child list of this node.
 * <p>The children of a @href CATIDOMDocumentFragment node are zero or more 
 * nodes representing the tops of any sub-trees defining the structure of the 
 * document. @href CATIDOMDocumentFragment nodes do not need to be 
 * well-formed XML documents (although they do need to follow the rules 
 * imposed upon well-formed XML parsed entities, which can have multiple top 
 * nodes). For example, a @href CATIDOMDocumentFragment might have only one 
 * child and that child node could be a @href CATIDOMText node. Such a 
 * structure model  represents neither an HTML document nor a well-formed XML 
 * document.  
 * <p>When a @href CATIDOMDocumentFragment is inserted into a  
 * @href CATIDOMDocument (or indeed any other @href CATIDOMNode that may take 
 * children) the children of the @href CATIDOMDocumentFragment and not the 
 * @href CATIDOMDocumentFragment itself are inserted into the 
 * @href CATIDOMNode. This makes the @href CATIDOMDocumentFragment very 
 * useful when the user wishes to create nodes that are siblings; the 
 * @href CATIDOMDocumentFragment acts as the parent of these nodes so that the
 * user can use the standard methods from the @href CATIDOMNode interface, 
 * such as @href CATIDOMNode#InsertBefore and @href CATIDOMNode#AppendChild.
 * @see CATIDOMDocument, CATIDOMNode
 */

class ExportedByCatXmlItfExt CATIDOMDocumentFragment : public CATIDOMNode {
	CATDeclareInterface;

	public:

};

CATDeclareHandler(CATIDOMDocumentFragment, CATIDOMNode);

#endif // CATIDOMDocumentFragment_h

