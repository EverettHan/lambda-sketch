#ifndef CATColorEditor_H
#define CATColorEditor_H
//
// CATIA Version 5 Release 1 Framework Visualization
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract : 	basic class which allow to display representations in
// ----------   2D or 3D viewpoint and to interact with representations
//	
//------------------------------------------------------------------------------
// Usage :	is used by application which wants to display and interact
// -------      with 2D and or 3D data.
//
//------------------------------------------------------------------------------
// Main methods :
// --------------
//------------------------------------------------------------------------------
// Class :	CATColorEditor
// -------        CATDlgFrame (Dialog)
//------------------------------------------------------------------------------

#include "CATVisPanel.h"

#include "CATDlgFrame.h"
#include "CATDlgUtility.h"

class CAT2DViewer;
class CATViewer;
class CAT2DCustomRep;
class CATManipulator;
class CATDlgDialog;
class CATDlgEditor;
class CATDlgPushButton;
class CATColorChooser;
class CAT2DImagePixelRep;
class CATIndicator;
class CAT2DLineGP;
class CAT2DQuadStripGP;
class CATDialog;
class CATString;

class ExportedByCATVisPanel CATColorEditor : public CATDlgFrame
{
 DeclareResource(CATColorEditor,CATDlgFrame)
 
//------------------------------------------------------------------------------
  public:

  virtual ~CATColorEditor();
  CATColorEditor(CATDialog *, const CATString &, CATDlgStyle style = NULL);
  void SetSelectedColor(int, int, int);
  void GetIntPreviewColor(int *, int *, int *, int *, int *, int *);
  void GetFloatPreviewColor(float *,float *,float *,float *,float *,float *);
  const char * GetColMODIFYNotification();

  void InputModifyHueEditor(int);
  void InputModifySatEditor(int);
  void InputModifyLumEditor(int);
  void InputModifyRedEditor(int);
  void InputModifyGreenEditor(int);
  void InputModifyBlueEditor(int);

//------------------------------------------------------------------------------
  private:
  CATColorEditor();
  CATColorEditor(const CATColorEditor &);               // no copy constructor
  CATColorEditor& operator = (const CATColorEditor &);  // no egal operator

  void UpdateLuminanceViewer();
  void UpdateLuminanceCursor();
  void UpdatePreviewViewer();
  void UpdateEditor();
  void UpdateHSLEditor();
  void UpdateRGBEditor();
  void UpdateTargetCursor();
  void RemoveTargetCursor();
  void ModifyLuminance(CATCommand *, CATNotification *, CATCommandClientData);
  void NoAction(CATCommand *, CATNotification *, CATCommandClientData);
  void BeginModifyTarget(CATCommand *, CATNotification *, CATCommandClientData);
  void ModifyTarget(CATCommand *, CATNotification *, CATCommandClientData);
  void EndModifyTarget(CATCommand *, CATNotification *, CATCommandClientData);
  void Destroy();

  CAT2DViewer        *_TargetColorViewer,*_LuminanceColorViewer;
  CAT2DViewer        *_PreviewColorViewer;
  CATDlgEditor       *_HueEditor, *_SatEditor, *_LumEditor;
  CATDlgEditor       *_RedEditor, *_GreenEditor, *_BlueEditor;
  CAT2DCustomRep     *_CursorRep, *_TargetRep, *_LuminanceRep;
  CAT2DImagePixelRep *_2DImageRep;
  CATIndicator       *_IndicTarget, *_IndicLuminance;
  CAT2DLineGP        *_TargetCursorGP;
  CAT2DQuadStripGP   *_LuminanceGP;
  int                 _red, _green, _blue, _hue, _sat, _lum;

};

#endif
