#ifndef CATAfrUIActiveServices_H
#define CATAfrUIActiveServices_H
#include "CATDialogEngine.h"
#include "CATBaseUnknown.h"

// COPYRIGHT DASSAULT SYSTEMES 2006
// protected DI0APPLI.m
//---------------------------------------------------------------------------
/**
 * Looks for an interface in the current UIActive path.
 * <br><b>Role</b>: This function scans the UIActive path from its top to its leaf,
 * searches the first object which implements an interface
 * and returns a pointer to this object.<br>
 * Do not use this service outside of an interactive context.
 * If your code is supposed to work in batch mode this service will not work.<br>
 * Example of use :
 *  CATIPLMComponent* toto=NULL;
 *  if (SUCCEEDED (CATAfrFindUIActiveElement(titi, IID_CATIPLMomponent, toto)))
 *  {
 *    toto->Gettata()
 *    toto->Release()
 *  }
 * @param ipObjectToEditor
 * The object belonging to the context of the caller.
 * The service uses this pointer to find the right UIActive path in the right CATFrmEditor.<br>
 * The nominal use case is from a CATStateCommand. A CATStateCommand In this case ipThisCommand should be a pointer to the CATStateCommand.<br>
 * You may also use this service inside other CATCommand derived types. Then ipThisCommand can be a pointer to this CATCommand.<br>
 * If you are inside the code of a CATFrmEditor, or if you want the service to work in a CATFrmEditor, you should give a pointer to this editor.<br>
 * If your want to use this service outside of a CATCommand, a CATCommandHeader and a CATFrmEditor
 * any use of the UIActive context is unsafe so please do not use this service
 * 
 * @param iInterfaceId
 * The IID of the interface.
 * @param oInterfacePointer
 * The first object of the UI-Active object which implements the given interface
 * (or NULL if no object in the path implements the interface).
 * <br> This is an interface pointer so <b> DO NOT FORGET TO RELEASE IT </b> after use.
 * @return
 * Returns the result of the last QueryInterface executed.
 */
ExportedByCATDialogEngine
HRESULT CATAfrFindUIActiveElement (CATBaseUnknown *ipObjectToEditor, const IID iInterfaceId, void **oInterfacePointer);

#endif
