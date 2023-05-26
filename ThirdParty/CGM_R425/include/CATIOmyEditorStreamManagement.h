/* -*-c++-*- */

#ifndef CATIOmyEditorStreamManagement_h
#define CATIOmyEditorStreamManagement_h

/**
 * @level Protected
 * @usage U4 [CATOmyEditorStreamManagementAdaptor]
 */

/**
 * Interface dedicated to the Editor management for LocalSave
 * should be implemented by UI editor manager
 */

#include "CATOMYBaseSession.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATOMYBaseSession IID IID_CATIOmyEditorStreamManagement;
#else
extern "C" const IID IID_CATIOmyEditorStreamManagement ;
#endif


class ExportedByCATOMYBaseSession CATIOmyEditorStreamManagement: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

  /** 
   * 
   * This method is called by the LocalSave Engine each time a valid LocalSave is performed, before
   * the editor streaming operation.
   * <br><b>Role</b>: Register all open editors with the @href CATOmyClientEditorRegistry mechanism
   *
   * This method is temporary ; the editors should record themselves with the @href CATOmyClientEditorRegistry
   * mechanism but it doesn't work at the moment. So this method allows an editor manager to scan all the
   * open editors and make them register.
   *
   * @return
   *   <code>S_OK</code>if the operation was performed normally  <code>E_FAIL</code> otherwise.
   *
   */
  virtual HRESULT PrepareEditorStreaming() =0;

};


#endif
