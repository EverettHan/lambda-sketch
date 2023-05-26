// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATIOmyEditorNotification.h
// Define the CATIOmyEditorNotification interface
//
//===================================================================
//
// Usage notes:
//   This interface has to be implemented by Editors that want to be informed of
//   - PLM entities entrying the session because of an open operation
//   - Local Save
//
//   To be notified, the editor has to register through CATOmyEditorRegistry  protocol
//
// We reserve the right to add at any time additional member function to the itf, to add other notification capacities.
// Hence implementations of the itf must always C++ derived from the associated adaptor CATOmyEditorNotificationAdapter 
// never directly from the interface. 
//
//===================================================================
//
//  Jan 2009  Creation JRZ
//===================================================================
/**
 * @level Protected
 * @usage U4
 */
#ifndef CATIOmyEditorNotification_H
#define CATIOmyEditorNotification_H

#include "CATBaseUnknown.h"
#include "CATOMYBaseSession.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATOMYBaseSession IID IID_CATIOmyEditorNotification;
#else
extern "C" const IID IID_CATIOmyEditorNotification ;
#endif

//------------------------------------------------------------------
class CATOmyIterator;
class ExportedByCATOMYBaseSession CATIOmyEditorNotification: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

  /** 
   * Notified the editor that an open has occured.
   * @param iCmpIter [in]
   *    Iterator of PLMComponents that are new in session because of the open operation   
   */
   virtual void OnOpenForEditor        (CATOmyIterator & iCmpIter)=0; 

  /** 
   * Notified the editor that a local save has occured.
   */
   virtual void OnLocalSaveForEditor ()=0;
};

CATDeclareHandler( CATIOmyEditorNotification, CATBaseUnknown );

#endif
