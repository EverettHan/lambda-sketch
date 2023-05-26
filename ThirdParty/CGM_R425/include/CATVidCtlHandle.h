// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATVidCtlHandle.h
// Header definition of CATVidCtlHandle
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Oct 2005  Creation: Code generated by the CAA wizard  jov
//===================================================================
#ifndef CATVidCtlHandle_H
#define CATVidCtlHandle_H

#include <VisuDialog.h>
#include <CATVidCtlRect.h>
#include <CATMathPointf.h>
#include <CAT4x4Matrix.h>

//-----------------------------------------------------------------------
/**
 * Deprecated class.
 * @deprecated use CATVidCtlButton instead, by using CreateButton or CreateThumbnail for example
 */
class ExportedByVisuDialog CATVidCtlHandle: public CATVidCtlRect
{
  CATDeclareClass;

public:
  // Standard constructors and destructors
  // -------------------------------------
  CATVidCtlHandle (CATCommand *i_pParent, const CATString & i_pIdentifier);

  // Get the notification
  // --------------------
  CATNotification *GetHandleStateChangedNotification() const{return GetPressAndReleaseNotification();};
  CATNotification *GetHandleDraggedNotification() const{return GetDragNotification();};

protected:
  virtual ~CATVidCtlHandle ();

private:
  // Copy constructor and equal operator
  // -----------------------------------
  CATVidCtlHandle (CATVidCtlHandle &);
  CATVidCtlHandle& operator=(CATVidCtlHandle& original);
};

//-----------------------------------------------------------------------

#endif