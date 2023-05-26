//===================================================================
// COPYRIGHT Dassault Systemes 2015/01/16
//===================================================================
// CATIPLMSaveV5V6Visu.cpp
// Header definition of class CATIPLMSaveV5V6Visu
//===================================================================
#ifndef CATIPLMSaveV5V6Visu_H
#define CATIPLMSaveV5V6Visu_H

#include "CATSysMacros.h"
#include "CATObjectModelerItf.h"
#include "CATBaseUnknown.h"

class CATDocument;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATObjectModelerItf IID IID_CATIPLMSaveV5V6Visu;
#else
extern "C" const IID IID_CATIPLMSaveV5V6Visu ;
#endif

class ExportedByCATObjectModelerItf CATIPLMSaveV5V6Visu: public CATBaseUnknown
{
  CATDeclareInterface;

public:

/**   
 * Manages a V5 CATPart transient extension with proper input conditions 
 * necessary to generate related CGR at next V6 Save
 *
 *
 * Initializes CGR computation inputs necessary to generate a V5 CATPart's related CGR at next V6 Save
 * these inputs are stored in a specific extension to be released after Save.
 * Right pattern of use: 
 * CATBaseUnknown* pV5NativeCgrPointer = NULL;
 * pV5V6Visu = QI or CATOmxQIPtr(CATIPLMSaveV5V6Visu) on a modified CATPartDoc;
 * if (pV5V6Visu)
 *  {
 *   pV5V6Visu->PrepareV5NativeCGR();
 *   pV5NativeCgrPointer = pV5V6Visu->GetV5NativeCGRPointer();
 *  }
 *  .....
 *  V6 Save (CATPartV5);
 *  CATSysReleasePtr(pV5NativeCgrPointer); // avoids eventual MLK
 *  .....
 */
  virtual HRESULT PrepareV5NativeCGR() = 0;

  // Horrible hack: get, store and later release the pointer on the CATPart transient extension, after CGR has been generated at V6 Save from its inputs
  virtual CATBaseUnknown* GetV5NativeCGRPointer() = 0;

};
#endif
