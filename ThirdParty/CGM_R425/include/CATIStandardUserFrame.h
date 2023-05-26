/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES	2002
#ifndef CATIStandardUserFrame
#define CATIStandardUserFrame_H

#include "CATBaseUnknown.h"

/**
 * Interface to implement on specific frame in Standard Editor panel to validate modification
 */
#include "UIModelInterfaces.h"
#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByUIModelInterfaces IID IID_CATIStandardUserFrame;
#else
extern "C" const IID IID_CATIStandardUserFrame;
#endif

class ExportedByUIModelInterfaces CATIStandardUserFrame : public CATBaseUnknown
{ 
  CATDeclareInterface;

  public:

  /**
  * CommitModification
  * This method is called before each save of xml standard file to validate modification
  * done inside the customized frame.
  * <br><b>Legal values</b>: S_OK, E_FAIL
  */
    virtual HRESULT CommitModification() = 0;
};
CATDeclareHandler(CATIStandardUserFrame, CATBaseUnknown);

#endif      
