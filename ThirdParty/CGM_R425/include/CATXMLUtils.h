#ifndef CATXMLUtils_h
#define CATXMLUtils_h

// COPYRIGHT DASSAULT SYSTEMES 2006

// XMLParser framework
#include "CATSAXDefaultHandler.h"
#include "CATUnicodeString.h"
#include "CATBoolean.h"
#include "CATListOfCATUnicodeString.h"
class CATISAXInputSource_var;
class CATISAXAttributes_var;
class CATIDOMNode_var;
class CATIDOMElement_var;

// XMLParserItf framework
#include "CatXmlItfExt.h"

/**
 * Class to provide XML related utilities.
 * @author Jean-Francois DOUE (JDU)
 */
class ExportedByCatXmlItfExt CATXMLUtils : public CATSAXDefaultHandler {
	CATDeclareClass;
	public:
		/**
		 * Returns the namespace of the root element of the
		 * supplied XML input source
		 * @param iSource
		 * An XML input source
		 * @param oNamespace
		 * namespace URI of the root element
		 */
		static HRESULT GetNamespaceFromSource(
			const CATISAXInputSource_var& iSource,
			CATUnicodeString& oNamespace);
		/**
		 * Destructor
		 */
		~CATXMLUtils();

		static HRESULT Dump(
			const CATIDOMNode_var& iNode,
			CATUnicodeString & oResult);
		static HRESULT Write(
			const CATIDOMNode_var& iNode,
			CATUnicodeString & oResult,
			const CATListOfCATUnicodeString& iOptions = CATListOfCATUnicodeString(),
			const CATListOfCATUnicodeString& iOptionValues = CATListOfCATUnicodeString());
		static HRESULT WriteToFile(
			const CATIDOMNode_var& iNode,
			const CATUnicodeString & iPath,
			const CATListOfCATUnicodeString& iOptions = CATListOfCATUnicodeString(),
			const CATListOfCATUnicodeString& iOptionValues = CATListOfCATUnicodeString());
		static HRESULT WriteFileWithEncoding(
			const CATUnicodeString& iEncoding,
			const CATUnicodeString& iFilePath,
			const CATUnicodeString& iFileContents);
		static HRESULT RenameElement(
			const CATIDOMElement_var& iElement,
			const CATUnicodeString& newName);
		static HRESULT RenameElement(
			const CATIDOMElement_var& iElement,
			const CATUnicodeString& newName,
			CATIDOMElement_var& oElement);

		HRESULT StartElement(
			const CATUnicodeString & iURI, 
			const CATUnicodeString & iLocalName, 
			const CATUnicodeString & iQualifiedName, 
			const CATISAXAttributes_var & iAttributes);
	private:
		///////////////////////////////////////////////////////////////////////
		/**
		 * Constructor
		 */
		CATXMLUtils();

		CATUnicodeString _namespace;
		CATBoolean _rootElementFound;

	private:
		///////////////////////////////////////////////////////////////////////
		static CATUnicodeString _TOK_AMPESC;
		static CATUnicodeString _TOK_QUOTESC;
		static CATUnicodeString _TOK_LTESC;
		static CATUnicodeString _TOK_GTESC;
		static CATUnicodeString _TOK_HTESC;
		static CATUnicodeString _TOK_LFESC;
		static CATUnicodeString _TOK_CRESC;
		static CATUnicodeString _TOK_SP;
		static CATUnicodeString _TOK_QUOT;
		static CATUnicodeString _TOK_LT;
		static CATUnicodeString _TOK_GT;
		static CATUnicodeString _TOK_ATTEQ;
		static CATUnicodeString _TOK_CLELT;
		static CATUnicodeString _TOK_EMPTYELT;
		static CATUnicodeString _TOK_STCOMM;
		static CATUnicodeString _TOK_ENDCOMM;
		static CATUnicodeString _TOK_STCDATA;
		static CATUnicodeString _TOK_ENDCDATA;
		static CATUnicodeString _TOK_STPI;
		static CATUnicodeString _TOK_ENDPI;
		static CATUnicodeString _TOK_STENT;
		static CATUnicodeString _TOK_ENDENT;
		static CATUnicodeString _TOK_LF;

		class WriteParams {
			public:
				WriteParams(
					unsigned int iCapacity,
					CATBoolean iExpandEntities,
					CATBoolean iSortAttributes,
					const CATUnicodeString& iIndentation,
					const CATUnicodeString& iLineSeparator,
					const CATUnicodeString& iInternalSubset);
				~WriteParams();
				HRESULT ToString(
					CATUnicodeString& oString);
				void Append(
					CATUC2Bytes iChar);
				CATBoolean ExpandEntityReferences();
				CATBoolean SortAttributes();
				CATUnicodeString GetIndentation();
				CATUnicodeString GetLineSeparator();
				CATUnicodeString GetInternalSubset();
			private:
				CATUC2Bytes *_buffer;
				unsigned int _capacity;
				unsigned int _size;
				CATBoolean _expandEntities;
				CATBoolean _sortAttributes;
				CATUnicodeString _indentation;
				CATUnicodeString _lineSeparator;
				CATUnicodeString _internalSubset;
		};
		class OutOfMemoryError {
		};


		
		/**
		 * Appends a document to the supplied write buffer.
		 */
		static HRESULT _AppendDocument(
			WriteParams& iParams,
			const CATIDOMNode_var& iNode,
			const CATUnicodeString& iEncoding,
			unsigned int iDepth);
		/**
		 * Appends an element to the supplied write buffer.
		 */
		static HRESULT _AppendElement(
			WriteParams& iParams,
			const CATIDOMNode_var& iNode,
			const CATUnicodeString& iEncoding,
			unsigned int iDepth,
			const CATUnicodeString iNodeName);

		/**
		 * Appends an entity ref to the supplied write buffer.
		 */
		static HRESULT _AppendEntityRef(
			WriteParams& iParams,
			const CATIDOMNode_var& iNode,
			const CATUnicodeString& iEncoding,
			unsigned int iDepth,
			const CATUnicodeString iNodeName);

		/**
		 * Recursively appends a node to the supplied write buffer.
		 */
		static HRESULT _AppendToBuffer(
			WriteParams& iParams,
			const CATIDOMNode_var& iNode,
			const CATUnicodeString& iEncoding,
			unsigned int iDepth);

		/**
		 * Appends a string to the supplied write buffer.
		 */
		 static HRESULT _AppendToBuffer(
			WriteParams& iParams,
			const CATUnicodeString& iString,
			unsigned int iEscapeMode = 0);

		/**
		 * Indents the XML output by the specified depth.
		 */
		static HRESULT _Indent(
			unsigned int iDepth,
			WriteParams& iParams);

		/**
		 * Returns TRUE if the CATUnicodeString contains only white space, false otherwise.
		 */
		static CATBoolean _IsWhiteSpace(
			const CATUnicodeString& iString);

		/**
		 * Returns TRUE if the element requires indentation by the
		 * pretty-print function, false otherwise.
		 */
		static CATBoolean _RequiresIndentation(
			const CATIDOMNode_var& iNode);
			

		/**
		 * qsort comparison function for attribute sorting.
		 */
		static int _Compare(const void* iArg1, const void* iArg2);

		static HRESULT _Dump(
			const CATIDOMNode_var& iNode,
			int depth,
			CATUnicodeString & oResult);

};

#endif // CATXMLUtils
