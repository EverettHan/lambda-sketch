// COPYRIGHT DASSAULT SYSTEMES 2002

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#ifndef CATSAXNotSupportedException_h
#define CATSAXNotSupportedException_h

// System framework
#include "CATInternalError.h"
class CATUnicodeString;

// XMLParser framework
#include "CatXmlItfBase.h"


/**
 * Class for errors related to an unsupported operation.
 *
 * <p>A @href CATISAXXMLReader will raise this error when it recognizes a feature or property 
 * identifier, but cannot perform the requested operation (setting a state or value). 
 * Other SAX2 applications and extensions may use this class for similar purposes.</p>
 *
 * @see CATISAXXMLReader#SetFeature, CATISAXXMLReader#SetProperty
 */
class ExportedByCatXmlItfBase CATSAXNotSupportedException: public CATInternalError {
	CATDeclareError(CATSAXNotSupportedException, CATInternalError)
	public:
		
		/**
		 * Factory method.
		 * @param iRequest
		 * specifies the operation which was being performed at the time the error occurred.
		 * @param iIdentifier
		 * the name of the feature or property which is not supported.
		 * @param iIdentifier
		 * the NLS error identifier.
		 * @param oError
		 * the error created by the factory method.
		 */
		static HRESULT CreateError(
			const CATUnicodeString& iRequest, 
			const CATUnicodeString& iIdentifier,
			const CATUnicodeString& iErrorId,
			CATSAXNotSupportedException*& oError);

};

#endif //CATSAXNotSupportedException_h

