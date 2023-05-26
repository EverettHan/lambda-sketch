// COPYRIGHT DASSAULT SYSTEMES 2004

#ifndef CATXMLPPMemoryOutputSourceImpl_h
#define CATXMLPPMemoryOutputSourceImpl_h

// System framework
#include "CATBaseUnknown.h"

// XMLParser framework CAA headers
class CATXMLPPMemoryBuffer;
#include "CATIXMLPPOutputSource.h"
#include "CatXmlItfBase.h"

/**
 * @author Jean-Francois DOUE (JDU)
 */
class ExportedByCatXmlItfBase CATXMLPPMemoryOutputSourceImpl: public CATIXMLPPOutputSource {
	CATDeclareClass;
	
	public:
		/**
		 * Constructor
		 */
		CATXMLPPMemoryOutputSourceImpl(
			CATXMLPPMemoryBuffer* iBuffer);

		/**
		 * Destructor
		 */
		virtual ~CATXMLPPMemoryOutputSourceImpl();
		
		// Implementation of the CATIXMLPPOutputSource interface
		virtual HRESULT Write(
			unsigned char* iByteArray,
			unsigned int iByteCount);
		
	private:
		// The copy constructor and the equal operator must not be implemented
		CATXMLPPMemoryOutputSourceImpl (CATXMLPPMemoryOutputSourceImpl &);
		CATXMLPPMemoryOutputSourceImpl& operator=(CATXMLPPMemoryOutputSourceImpl&);

	protected:
		CATXMLPPMemoryBuffer* _buffer;
};

#endif // CATXMLPPMemoryOutputSourceImpl_h
