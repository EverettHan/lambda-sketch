#ifndef CATColorChooserPanel_H
#define CATColorChooserPanel_H
//
// CATIA Version 5 Release 1 Framework GraphicEditor
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract : 	RGB Color chooser + RGB/HSL editor
// ----------   
//------------------------------------------------------------------------------
// Usage :	is used by application which wants to define a color
// -------      
//------------------------------------------------------------------------------
// Main methods :
// --------------
//      GetSelectedColor  get Red, Green and blue values between 0 and 255
//------------------------------------------------------------------------------
// Class :	CATColorChooserPanel
// -------        CATDlgDialog (Dialog)
//------------------------------------------------------------------------------

#include "CATVisPanel.h"

#include "CATDlgDialog.h"
#include "CATDlgUtility.h"
#include "GraphicEditorEnum.h"

class CATViewer;
class CATColorChooser;
class CATColorEditor;
class CATDlgPushButton;
class CATDlgFrame;
class CATDialog;
class CATString;
class CATCommand;
class CATNotification;


class ExportedByCATVisPanel CATColorChooserPanel : public CATDlgDialog
{
 DeclareResource(CATColorChooserPanel,CATDlgDialog)
 
//------------------------------------------------------------------------------
  public:

  virtual ~CATColorChooserPanel();
  CATColorChooserPanel(CATDialog *,
                       const CATString &,
                       CATDlgStyle style = NULL,
                       EditorMode editormode = DELAYEDEDITOR);
  void GetSelectedColor(int *, int *, int *);
  void SetSelectedColor(int, int, int);

//------------------------------------------------------------------------------
  private:
  CATColorChooserPanel();
  CATColorChooserPanel(const CATColorChooserPanel &);               // no copy constructor
  CATColorChooserPanel& operator = (const CATColorChooserPanel &);  // no egal operator

  void DefineColor (CATCommand *, CATNotification *, CATCommandClientData);
  void ModifySelectedColor (CATCommand *,
                            CATNotification *,
                            CATCommandClientData);
  void DoOk        (CATCommand *, CATNotification *, CATCommandClientData);
  void DoApply     (CATCommand *, CATNotification *, CATCommandClientData);
  void DoCancel    (CATCommand *, CATNotification *, CATCommandClientData);

  CATColorChooser  *_ColorChooser;
  CATColorEditor   *_ColorEditor;
  CATDlgPushButton *_DefineColorPush;
  CATDlgPushButton *_ModifyCurrentColorPush;
  CATDlgFrame      *_feditor;
  EditorMode        _EditorMode;

};

#endif
