#ifndef CATICopyAdditionalFormat_H
#define CATICopyAdditionalFormat_H

// COPYRIGHT DASSAULT SYSTEMES 2018

//===========================================================================
// Interface for retriving additinal format on copy
// To be implemented by connector application
//===========================================================================

/**
* @level Protected
* @usage U1
*/


#include "CATBaseUnknown.h"
#include "CATLISTV_CATBaseUnknown.h"
#include "CATFormats.h"
#include "CATMacForIUnknown.h"
#include "CATFormat.h"

#include "CP0CLIP.h"
#include "IUnknown.h"

extern ExportedByCP0CLIP IID IID_CATICopyAdditionalFormat;

class  ExportedByCP0CLIP CATICopyAdditionalFormat : public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /**
  * Method to get additional format(e.g. 3DXContent) for selected objects on copy operation
  * @param input_list_objects
  *        The selected objects in CSO as input
  * @param oFormat
  *        New CCP format as output
  * @param oFormatObject
  *        The output extracted format object required to be set on clipboard
  * @return
  * <ul>
  *     <li> S_OK   If succeeded </li>
  *     <li> E_FAIL Otherwise    </li>
  * </ul>
  */
  virtual HRESULT GetAdditionalFormat(CATLISTV(CATBaseUnknown_var) * input_list_objects, const CATFormat *&oFormat, CATBaseUnknown_var &oFormatObject)=0 ;

};

#endif
