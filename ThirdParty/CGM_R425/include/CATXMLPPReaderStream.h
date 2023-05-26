// COPYRIGHT DASSAULT SYSTEMES 2010

#ifndef CATXMLPPReaderStream_h
#define CATXMLPPReaderStream_h

// System framework
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"

// XMLParserItf framework CAA headers
#include "CATIXMLPPReader.h"
#include "CATIXMLInputStream.h"
#include "CatXmlItfBase.h"

/**
 * Class to implement CATIXMLInputStream on top of
 * a CATIXMLPPReader. 
 * @author Jean-Francois DOUE (JDU)
 */

class ExportedByCatXmlItfBase CATXMLPPReaderStream: public CATBaseUnknown {
	CATDeclareClass;
	public:
		static HRESULT CreateStream(
			const CATIXMLPPReader_var& iReader,
			CATIXMLInputStream_var& oStream);
		~CATXMLPPReaderStream();
		
		// Implementation of the CATIXMLInputStream interface
		virtual HRESULT Read(	unsigned char* 	ioByteArray,
			unsigned int 	iByteArrayCapacity,
			unsigned int& 	oSizeRead);
			
		// Implementation of the CATIXMLPPReader interface
		virtual HRESULT Current(
			CatXMLPPNodeType& oNodeType);
		virtual HRESULT Next(
			CatXMLPPNodeType& oNodeType);
		virtual HRESULT GetPrefix(
			CATUnicodeString& oPrefix);
		virtual HRESULT GetName(
			CATUnicodeString& oName);
		virtual HRESULT GetLocalName(
			CATUnicodeString& oName);
		virtual HRESULT GetNamespaceUri(
			CATUnicodeString& oNamespaceUri);
		virtual HRESULT GetAttributeCount(
			unsigned int& oCount);
		virtual HRESULT GetAttributePrefix(
			unsigned int iIndex,
			CATUnicodeString& oPrefix);
		virtual HRESULT GetAttributeName(
			unsigned int iIndex,
			CATUnicodeString& oName);
		virtual HRESULT GetAttributeLocalName(
			unsigned int iIndex,
			CATUnicodeString& oLocalName);
		virtual HRESULT GetAttributeNamespaceUri(
			unsigned int iIndex,
			CATUnicodeString& oNamespaceUri);
		virtual HRESULT GetAttributeValue(
			unsigned int iIndex,
			CATUnicodeString& oValue);
		virtual HRESULT IsAttributeDefault(
			unsigned int iIndex,
			CATBoolean& oDefault);
		virtual HRESULT GetText(
			CATUnicodeString& oText);
		virtual HRESULT GetLine(
			int& oLine);
		virtual HRESULT GetColumn(
			int& oColumn);
		virtual HRESULT Subtree(
			CATIXMLPPReader_var& oReader);	
		virtual HRESULT GotoElement(
			const CATUnicodeString& iLocalName, 
			const CATUnicodeString& iNamespaceURI,
			CATBoolean& oFound);
		virtual HRESULT GetOptions(
 			CATListOfCATUnicodeString& oOptionNames,
			CATListOfCATUnicodeString& oOptionValues);

	protected:
		CATXMLPPReaderStream(const CATIXMLPPReader_var& iReader);
	private:
		static void CopyChars(
			const CATUnicodeString& iString,
			int srcBegin,
			int srcEnd,
			CATUC2Bytes* ioCharArray,
			int destBegin);
	private:
		CATIXMLPPReader_var _reader;
		int _state;
		int _nextState;
		int _textPos;
		int _markupPos;
		unsigned int _attPos;
		int _bracketCount;
		CATUnicodeString _markup;
		CATBoolean _closed;

};

#endif // CATXMLPPReaderStream_h
