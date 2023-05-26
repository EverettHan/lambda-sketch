// COPYRIGHT DASSAULT SYSTEMES 2004

#ifndef CATXMLPPFactoryImpl_h
#define CATXMLPPFactoryImpl_h

// System framework
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"

// XMLParserItf framework CAA headers
class CATIXMLPPOutputSource_var;
class CATXMLPPMemoryBuffer;
class CATIXMLPPWriter_var;
class CATISAXEntityResolver_var;
class CATISAXInputSource_var;
class CATIXMLPPReader_var;
#include "CatXmlItfBase.h"

/**
 * Base class for CATIXMLPPFactory2 implementations
 * @author Jean-Francois DOUE (JDU)
 */
class ExportedByCatXmlItfBase CATXMLPPFactoryImpl: public CATBaseUnknown {
	
	public:
		/**
		 * Constructor
		 */
		CATXMLPPFactoryImpl();

		/**
		 * Destructor
		 */
		virtual ~CATXMLPPFactoryImpl();
		
		// Implementation of the CATIXMLPPFactory interface
		virtual HRESULT CreateOutputSourceFromFile(
			const CATUnicodeString& iXMLFilePath,
			CATIXMLPPOutputSource_var& oOutputSource);
		virtual HRESULT CreateOutputSourceFromMemoryBuffer(
			const CATXMLPPMemoryBuffer& iBuffer,
			CATIXMLPPOutputSource_var& oOutputSource);
		virtual HRESULT CreateXMLWriter(
			const CATIXMLPPOutputSource_var& iOutputSource,
			CATIXMLPPWriter_var & oXMLWriter,
			const CATListOfCATUnicodeString& iOptions,
			const CATListOfCATUnicodeString& iOptionValues);
		virtual HRESULT CreateReader(
			const CATISAXInputSource_var& iSource,
			CATIXMLPPReader_var& oReader,
			const CATListOfCATUnicodeString& iOptions,
			const CATListOfCATUnicodeString& iOptionValues,
			const CATISAXEntityResolver_var& iEntityResolver);
		
	private:
		// The copy constructor and the equal operator must not be implemented
		CATXMLPPFactoryImpl (CATXMLPPFactoryImpl &);
		CATXMLPPFactoryImpl& operator=(CATXMLPPFactoryImpl&);
};

#endif // CATXMLPPFactoryImpl_h
