// COPYRIGHT DASSAULT SYSTEMES 2004

#ifndef CATXMLPPException_h
#define CATXMLPPException_h

// System framework
#include "CATInternalError.h"

// XMLParser framework
#include "CatXmlItfBase.h"

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

/**
 * Class to encapsulate errors raised by the CATIXMLPPWriter interface.
 */
class ExportedByCatXmlItfBase CATXMLPPException: public CATInternalError {
	CATDeclareError(CATXMLPPException, CATInternalError)
};

#endif //CATXMLPPException_h

