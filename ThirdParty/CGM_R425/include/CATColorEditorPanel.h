#ifndef CATColorEditorPanel_H
#define CATColorEditorPanel_H
//
// CATIA Version 5 Release 1 Framework GraphicEditor
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract : RGB/HSL Color editor
// ----------  
//	
//------------------------------------------------------------------------------
// Usage :	is used by application which wants to define a color
// -------     
//
//------------------------------------------------------------------------------
// Main methods :
// --------------
//   GetSelectedColor get Red Green Blue values between 0 and 255
//                    and Hue Sat   Lum  values between 0 and 240  
//------------------------------------------------------------------------------
// Class :	CATColorEditorPanel
// -------        CATDlgDialog (Dialog)
//------------------------------------------------------------------------------

#include "CATVisPanel.h"

#include "CATDlgDialog.h"

class CATViewer;
class CATDlgPushButton;
class CATColorEditor;


class ExportedByCATVisPanel CATColorEditorPanel : public CATDlgDialog
{
 DeclareResource(CATColorEditorPanel,CATDlgDialog)
 
//------------------------------------------------------------------------------
  public:

  virtual ~CATColorEditorPanel();
  CATColorEditorPanel(CATDialog *,
                       const CATString &,
                       CATDlgStyle style = NULL);
  void GetSelectedColor(int *, int *, int *,int *, int *, int *);
  void GetSelectedColor(float *, float *, float *,float *, float *, float *);
  void SetSelectedColor(int, int, int);
  const char * GetColMODIFYNotification();

//------------------------------------------------------------------------------
  private:

  void DoOk        (CATCommand *, CATNotification *, CATCommandClientData);
  void DoApply     (CATCommand *, CATNotification *, CATCommandClientData);
  void DoCancel    (CATCommand *, CATNotification *, CATCommandClientData);
  void ModifyColor (CATCommand *, CATNotification *, CATCommandClientData);

  CATColorEditor   *_ColorEditor;

};

#endif
