// COPYRIGHT Dassault Systemes 2007
//===================================================================
//
// CATVidCtlScreen.h
// Header definition of CATVidCtlScreen
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Jul 2007  Creation: jov
//===================================================================
#ifndef CATVidCtlScreen_H
#define CATVidCtlScreen_H

#include "VisuDialog.h"
#include "VisQualityData.h"
#include "CATVidCtl.h"
#include <CATMathPlane.h>
#include <CATMathPoint2Df.h>
#include "CATVidCursor.h"

class CATViewpoint;
class CATVidGPSquare;
class CATPixelImage;
class CATVidSupport;
class CATMouseEvent;
class CATMathPointf;
class CATDeviceEvent;
class CATSYPIntAnimation;
class CATSYPBeginStoryboard;
class CATVisuTexture;
class CATVisInfiniteEnvironment;
class CATPickPathList;
class CATVidColor;
//-----------------------------------------------------------------------
/**
 * @ingroup VIDControls
 */
class ExportedByVisuDialog CATVidCtlScreen: public CATVidCtl
{
  CATDeclareClass;

public:
  // Standard constructors and destructors
  // -------------------------------------
  CATVidCtlScreen ();
  CATVidCtlScreen (CATCommand *i_pParent, const CATString & i_pIdentifier);

  virtual void TunnelInformation(const CATVidInformation& i_information);

  virtual void Update();

  int GetViewMode() const;
  void SetViewMode(int i_viewMode);

  CATBoolean GetFSAAFlag() const;
  void SetFSAAFlag(CATBoolean i_fsaaFlag);

  float GetMMInSupportUnitFactor() const;
  void SetMMInSupportUnitFactor(float i_MMInSupportUnitFactor);

  int GetLocalManipulationMode() const;
  void SetLocalManipulationMode(int i_localManipulationMode);

  const CATString& GetAmbienceName() const;
  void SetAmbienceName(const CATString& i_ambienceName);

  CATBoolean GetLocalManipulationEnableFlag() const;
  void SetLocalManipulationEnableFlag(CATBoolean i_localManipulationEnableFlag);

  CATBoolean GetNoBackgroundFlag() const;
  void SetNoBackgroundFlag(CATBoolean i_noBackgroundFlag);

  unsigned int GetTextureFormat() const;
  void SetTextureFormat(unsigned int i_textureFormat);

  const CATVidColor& GetBackgroundColor()const;

  CATNotification * GetCameraBeginManipulationNotification() const;
  CATNotification * GetCameraEndManipulationNotification() const;

  CATNotification * GetMouseMoveOverNotification() const;
  CATNotification * GetMouseLeaveNotification() const;
  CATNotification * GetMouseEntryNotification() const;
  CATNotification * GetDoubleClickNotification() const;

  void SetOverCursor(CATVidCursor::CATVidCursorStyle i_cursor);

  void SetViewerQuality(const VisQualityData &iQuality);

protected:
  virtual ~CATVidCtlScreen ();

  void SetViewpoint(CATViewpoint* i_pViewpoint);
  CATViewpoint* GetViewpoint() const;

  void Refresh(CATBoolean i_transitionFlag = FALSE);
  virtual void ManipulateViewpoint(const CATUnicodeString& eventName){};

private:
  // Copy constructor and equal operator
  // -----------------------------------
  CATVidCtlScreen (CATVidCtlScreen &);
  CATVidCtlScreen& operator=(CATVidCtlScreen&);
  void BuildCATVidCtlScreen();

  void OnCB (CATCommand *i_pCommand, CATNotification *i_pNotification, CATCommandClientData i_commandData );

  void Pick(CATMouseEvent& i_mouseEvent, CATPickPathList& o_pickPathList);
  void RefreshAmbience();

  void HandleEvent(const CATUnicodeString& eventName);


private:
  int _localManipulationMode;
  CATString _ambienceName;
  CATVisuTexture* _pVisuTexture;
  CATVidGPSquare* _pSquareGP;
  CATVidGPSquare* _pTransitionSquareGP;
  CATVidSupport* _pVidSupport;
  CATViewpoint* _pViewpoint;

  CATSYPIntAnimation* _pAlphaAnimation;
  CATSYPBeginStoryboard* _pBeginStoryboard;
  CATVisInfiniteEnvironment *_pAmbience;
  CATBoolean _localManipulationEnableFlag;
  CATBoolean _noBackgroundFlag;
  unsigned int _textureFormat;
  VisQualityData _viewerQualityData;

  CATVidCursor::CATVidCursorStyle _overCursor;
};


//-----------------------------------------------------------------------

#endif
