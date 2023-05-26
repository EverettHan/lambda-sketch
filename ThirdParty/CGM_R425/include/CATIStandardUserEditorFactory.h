/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES	2002
#ifndef CATIStandardUserEditorObject_H
#define CATIStandardUserEditorFactory_H

#include "CATBaseUnknown.h"

/**
 * Interface to customize the right side of Standard Editor panel
 */
#include "UIModelInterfaces.h"
#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByUIModelInterfaces IID IID_CATIStandardUserEditorFactory;
#else
extern "C" const IID IID_CATIStandardUserEditorFactory;
#endif

class CATIStandardUIObject;
class CATDlgFrame;

class ExportedByUIModelInterfaces CATIStandardUserEditorFactory : public CATBaseUnknown
{ 
  CATDeclareInterface;

  public:

    /**
		  BuildUserFrame
    * @param iStdUIObject
    * Gives you all the necessary information to build its own editor
    * @param iParentFrame
    *    the parent frame to use to build your dialog objects
    * @param oCreatedFrame
    *   the frame including your own editor
    * The status call
    * <br><b>Legal values</b>: S_OK, E_FAIL
    */
    virtual HRESULT BuildUserFrame(CATIStandardUIObject &iStdUIObject,
                                   CATDlgFrame *iParentFrame,
                                   CATDlgFrame **oCreatedFrame) = 0;
};
CATDeclareHandler(CATIStandardUserEditorFactory, CATBaseUnknown);

#endif      
