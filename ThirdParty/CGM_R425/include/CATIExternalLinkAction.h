/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES	2000
#ifndef _CATIExternalLinkAction_h
#define _CATIExternalLinkAction_h

#include "CATBaseUnknown.h"

/**
 * Interface to manage external links.
 * <b>Role</b>: Delegates to the link the change source operation.
 */
#include "CATInteractiveInterfaces.h"
#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATInteractiveInterfaces IID IID_CATIExternalLinkAction;
#else
extern "C" const IID IID_CATIExternalLinkAction;
#endif

class ExportedByCATInteractiveInterfaces CATIExternalLinkAction : public CATBaseUnknown
{
public:
  CATDeclareInterface;

  enum CATExternalLinkAction {FindSourceAction};

  /**
   * Delegates action to the link.
   * @param iAction
   * The identifier of the action.
   * <br><b>Legal values </b>:
   * <br> FindSource: Find Source Action. 
   * @return
   * The status call
   * <br><b>Legal values</b>: S_OK, E_FAIL
   */
  virtual HRESULT Do(CATExternalLinkAction iAction) = 0;

  /**
   * Allows or forbids the action.
   * @param iAction
   * The identifier of the action.
   * <br><b>Legal values </b>:
   * <br> FindSource: Find Source Action. 
   * @return
   * The status call
   * <br><b>Legal values</b>: 0,1
   */
  virtual int IsAllowed(CATExternalLinkAction iAction) = 0;
};

#endif
