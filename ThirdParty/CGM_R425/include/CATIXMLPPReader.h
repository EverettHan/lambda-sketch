#ifndef CATIXMLPPReader_h
#define CATIXMLPPReader_h

// COPYRIGHT DASSAULT SYSTEMES 2010

// System framework
#include "CATBaseUnknown.h"
#include "CATBoolean.h"
#include "CATListOfCATUnicodeString.h"
class CATUnicodeString;

// XMLParserItf framework
#include "CatXmlItfBase.h"
#include "CATISAXEntityResolver.h"
class CATISAXInputSource_var;
class CATIXMLPPReader_var;

#ifndef LOCAL_DEFINITION_FOR_IID
	extern ExportedByCatXmlItfBase IID IID_CATIXMLPPReader;
#else // LOCAL_DEFINITION_FOR_IID
	extern "C" const IID IID_CATIXMLPPReader ;
#endif // LOCAL_DEFINITION_FOR_IID

enum CatXMLPPNodeType {
    NodeType_None,
    NodeType_StartDocument,
    NodeType_StartElement,
    NodeType_EndElement,
    NodeType_Characters,
    NodeType_Comment,
    NodeType_ProcessingInstruction,
    NodeType_EndDocument
};

/**
 * Interface to read XML streams using a pull paradigm.
 */
class ExportedByCatXmlItfBase CATIXMLPPReader : public CATBaseUnknown {
	CATDeclareInterface;
	
	public:
		/**
		 * Returns the type of node the reader currently points to.
		 * @param oNodeType
		 * The current node type
		 */
		virtual HRESULT Current(
			CatXMLPPNodeType& oNodeType) = 0;
		
		/**
		 * Move the reader to the next node and return its type.
		 * @param oNodeType
		 * The node type
		 */
		virtual HRESULT Next(
			CatXMLPPNodeType& oNodeType) = 0;
		
		/**
		 * Get the prefix of the element.
		 * @param oPrefix
		 * the prefix of the element
		 * @return
		 * Raises CATError if the method is called when the reader is not positionned on a
		 * node of type START_ELEMENT or END_ELEMENT
		 */
		virtual HRESULT GetPrefix(
			CATUnicodeString& oPrefix) = 0;

		/**
		 * Get the qualifed name of an element node or the target of
		 * a processing instruction.
		 * @param oName
		 * the qualifed name of an element node or the target of
		 * a processing instruction
		 * @return
		 * Raises CATError if the method is called when the reader is not positionned on a
		 * node of type START_ELEMENT or END_ELEMENT
		 */
		virtual HRESULT GetName(
			CATUnicodeString& oName) = 0;

		/**
		 * Get the local name of the element.
		 * @param oLocalName
		 * the  local name of the element
		 * @return
		 * Raises CATError if the method is called when the reader is not positionned on a
		 * node of type START_ELEMENT or END_ELEMENT
		 */
		virtual HRESULT GetLocalName(
			CATUnicodeString& oName) = 0;

		/**
		 * Get the namespace URI of the element.
		 * @param oNamespaceUri
		 * the namespace URI of the element
		 * @return
		 * Raises CATError if the method is called when the reader is not positionned on a
		 * node of type START_ELEMENT or END_ELEMENT
		 */
		virtual HRESULT GetNamespaceUri(
			CATUnicodeString& oNamespaceUri) = 0;

		/**
		 * Get the number of attributes of the current element node.
		 * @param oCount
		 * number of attributes of the current element node
		 * @return
		 * Raises CATError if the method is called when the reader is not positionned on a
		 * node of type START_ELEMENT.
		 */
		virtual HRESULT GetAttributeCount(
			unsigned int& oCount) = 0;
		
		/**
		 * Get the prefix of the attribute at the specified index.
		 * @param iIndex
		 * index of the attribute
		 * @param oPrefix
		 * the prefix of the attribute at the specified index
		 * @return
		 * Raises CATError if the method is called when the reader is not positionned on a
		 * node of type START_ELEMENT.
		 */
		virtual HRESULT GetAttributePrefix(
			unsigned int iIndex,
			CATUnicodeString& oPrefix) = 0;

		/**
		 * Get the qualifed name of the attribute at the specified index.
		 * @param iIndex
		 * index of the attribute
		 * @param oName
		 * the qualifed name of the attribute at the specified index
		 * @return
		 * Raises CATError if the method is called when the reader is not positionned on a
		 * node of type START_ELEMENT.
		 */
		virtual HRESULT GetAttributeName(
			unsigned int iIndex,
			CATUnicodeString& oName) = 0;

		/**
		 * Get the local name of the attribute at the specified index.
		 * @param iIndex
		 * index of the attribute
		 * @param oLocalName
		 * the local name of the attribute at the specified index
		 * @return
		 * Raises CATError if the method is called when the reader is not positionned on a
		 * node of type START_ELEMENT.
		 */
		virtual HRESULT GetAttributeLocalName(
			unsigned int iIndex,
			CATUnicodeString& oLocalName) = 0;

		/**
		 * Get the namespace URI of the attribute at the specified index.
		 * @param iIndex
		 * index of the attribute
		 * @param  oNamespaceUri
		 * namespace URI of the attribute at the specified index
		 * @return
		 * Raises CATError if the method is called when the reader is not positionned on a
		 * node of type START_ELEMENT.
		 */
		virtual HRESULT GetAttributeNamespaceUri(
			unsigned int iIndex,
			CATUnicodeString& oNamespaceUri) = 0;

		/**
		 * Get the value of the attribute at the specified index.
		 * @param iIndex
		 * index of the attribute
		 * @param oValue
		 * the value of the attribute at the specified index
		 * @return
		 * Raises CATError if the method is called when the reader is not positionned on a
		 * node of type START_ELEMENT.
		 */
		virtual HRESULT GetAttributeValue(
			unsigned int iIndex,
			CATUnicodeString& oValue) = 0;

		/**
		 * Get whether the attribute at the specified index is a default value
		 * or explicitely set.
		 * @param iIndex
		 * index of the attribute
		 * @param oDefault
		 * true if the attribute is a default value, false otherwise
		 * @return
		 * Raises CATError if the method is called when the reader is not positionned on a
		 * node of type START_ELEMENT.
		 */
		virtual HRESULT IsAttributeDefault(
			unsigned int iIndex,
			CATBoolean& oDefault) = 0;
		
		/**
		 * Get the value of an character node or a comment node or the data of
		 * a processing instruction.
		 * @param oText
		 * the value of an character node or a comment node or the data of
		 * a processing instruction
		 * @return
		 * Raises CATError if the method is called when the reader is not positionned on a
		 * node of type CHARACTERS or COMMENT or PROCESSING_INSTRUCTION.
		 */
		virtual HRESULT GetText(
			CATUnicodeString& oText) = 0;

		/**
		 * Get the line number at which the reader is currently positionned.
		 * @param oLine
		 * the line number at which the reader is currently positionned
		 */
		virtual HRESULT GetLine(
			int& oLine) = 0;
		
		/**
		 * Get the column number at which the reader is currently positionned.
		 * @param oColumn
		 * the column number at which the reader is currently positionned
		 */
		virtual HRESULT GetColumn(
			int& oColumn) = 0;
		
		/**
		 * Create a new reader to parse the subtree rooted at
		 * the element on which the reader is currently positionned.
		 * The current reader becomes locked until the new reader
		 * as fully processed its content. The current reader can
		 * the resume the parsing at the node immediately following
		 * the subtree.
		 * @param oReader
		 * a subtree reader
		 * @return
		 * Raises CATError if the method is called when the reader is not positionned on a
		 * node of type START_ELEMENT.
		 */
		virtual HRESULT Subtree(
			CATIXMLPPReader_var& oReader) = 0;
		
		/**
		 * Positions the reader on the specified element
		 * @param
		 * iLocalName local name of the element
		 * @param
		 * iNamespaceURI namespace URI of the element
		 * @param oFound
		 * true is the element is succesfully located, false otherwise.
		 */
		virtual HRESULT GotoElement(
			const CATUnicodeString& iLocalName, 
			const CATUnicodeString& iNamespaceURI,
			CATBoolean& oFound) = 0;
			
		/**
		 * Returns the options currently being applied to this reader
		 * @param oOptionNames
		 * The name of the options
		 * @param oOptionValues
		 * The value of the options
		 */
		virtual HRESULT GetOptions(
 			CATListOfCATUnicodeString& oOptionNames,
			CATListOfCATUnicodeString& oOptionValues) = 0;
};

CATDeclareHandler(CATIXMLPPReader, CATBaseUnknown);

#endif // CATIXMLPPReader_h
