/* -*-c++-*- */
#ifndef _CATIAfrDialogForAgent_H
#define _CATIAfrDialogForAgent_H

// COPYRIGHT DASSAULT SYSTEMES  2000

/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */

#include "CATIAfrDialog.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATAfrItf IID IID_CATIAfrDialogForAgent;
#else
extern "C" const IID IID_CATIAfrDialogForAgent;
#endif

/**
 * Interface to visualize a dialog agent in a toolbar.
 * <b>Role:</b> To visualize a dialog agent in a toolbar there is 3 steps:
 * <ol> 
 * <li>Sets the dialog agent in the SDO: @href CATStateCommand#AddSDOElement(CATBaseUnknown*) </li>
 * <li>This agent must implement this interface </li>
 * <li>In the @href CATCommandHeaderWithSDOForAgent constructor you should give
 * the IID of this interface </li>
 * </ol>
 * The unic dialog agent which implements this interface is the @href CATCmdSwitchAgent 
 */

class ExportedByCATAfrItf CATIAfrDialogForAgent : public CATIAfrDialog
{
  public:

};

#endif
