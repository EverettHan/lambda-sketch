// COPYRIGHT Dassault Systemes 2004
//===================================================================
//
// CATIOmbDownwardData.h
// Define the CATIOmbDownwardData interface
//
//===================================================================
//
// Usage notes:
//   New interface: This interface offers OmbDownwardData services
//
//===================================================================
//
//===================================================================

/**
 * @level Private
 * @usage U3
 */

#ifndef CATIOmbDownwardData_H
#define CATIOmbDownwardData_H

#include "CATBaseUnknown.h"
#include "CATOmbDWC.h"
#include "CATDocument.h"
#include "IUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATOmbDWC IID IID_CATIOmbDownwardData;
#else
extern "C" const IID IID_CATIOmbDownwardData ;
#endif

//------------------------------------------------------------------

/**
 * This interface offers DownwardData services to process a container inside a document
 * Late implementing this interface is computed as follow dwc_ContainerLateType_Document_LateType ex:dwc_CATProdCont_CATPart
 *
 * Please Derive from Adapter CATEOmbDownwardData
 */
class ExportedByCATOmbDWC CATIOmbDownwardData: public CATBaseUnknown
{
  CATDeclareInterface;

  public:
	 /**
     * Process a document at end of CATBack operation
     */
    virtual HRESULT ProcessDocument(CATDocument& iDocument) = 0;
};
//------------------------------------------------------------------

#endif
