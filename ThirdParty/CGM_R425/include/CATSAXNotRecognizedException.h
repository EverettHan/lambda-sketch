// COPYRIGHT DASSAULT SYSTEMES 2002

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#ifndef CATSAXNotRecognizedException_h
#define CATSAXNotRecognizedException_h

// System framework
#include "CATInternalError.h"
class CATUnicodeString;

// XMLParser framework
#include "CatXmlItfBase.h"


/**
 * Class for errors related to an unrecognized operation.
 *
 * <p>A @href CATISAXXMLReader will raise this error when it finds an unrecognized feature or property identifier; 
 * SAX applications and extensions may use this class for other, similar purposes.</p>
 *
 * @see CATISAXXMLReader#SetFeature, CATISAXXMLReader#SetProperty
 */
class ExportedByCatXmlItfBase CATSAXNotRecognizedException: public CATInternalError {
	CATDeclareError(CATSAXNotRecognizedException, CATInternalError)
	public:
		
		/**
		 * Factory method.
		 * @param iRequest
		 * specifies the operation which was being performed at the time the error occurred.
		 * @param iIdentifier
		 * the name of the feature or property which could not be recognized.
		 * @param iIdentifier
		 * the NLS error identifier.
		 * @param oError
		 * the error created by the factory method.
		 */
		static HRESULT CreateError(
			const CATUnicodeString& iRequest, 
			const CATUnicodeString& iIdentifier,
			const CATUnicodeString& iErrorId,
			CATSAXNotRecognizedException*& oError);

};

#endif //CATSAXNotRecognizedException_h

