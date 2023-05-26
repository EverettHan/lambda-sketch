// COPYRIGHT Dassault Systemes 2007
//===================================================================
//
// CATVidTextureAnimation.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Jan 2007  Creation: NSI
//===================================================================
#ifndef CATVidTextureAnimation_H
#define CATVidTextureAnimation_H

#include <CATVisuAnimation.h>
#include <VisuDialog.h>
#include <CATVidEnum.h>
#include <CATEventSubscriber.h>

class CATVidCtlRect;
class CATVizPixelImageAnimation;
class CATVidListener;
class CATVidWidget;
/**
 * Deprecated class.
 * @deprecated Use instead .mng format on CATVidGPSquare or high level class 
 * (Icon property on CATVidCtlButton)
 */
class ExportedByVisuDialog CATVidTextureAnimation : public CATVisuAnimation
{
public:
  CATVidTextureAnimation (float i_delay, CATVidCtlRect* i_pWidget);
  virtual ~CATVidTextureAnimation ();
  void SetPixelImageAnimation(CATVizPixelImageAnimation* i_pPixelImageAnimation, CATVidState i_state = CATVidStateOff);
  virtual void Start();
  virtual void End();
  float WakeUp();
  virtual CATBoolean IsRemoveNeeded();
protected:
  CATVidWidget* GetVidWidget() const {return _pWidget;};
  virtual void GoToStep();
private:
  void ResetWidget(){_pWidget = NULL;_cb = NULL;}
  CATVidTextureAnimation& operator=(CATVidTextureAnimation&);
  void RemoveAnimation();
  CATVizPixelImageAnimation* GetPixelImageAnimation();
  CATVidState _state;
  CATVizPixelImageAnimation* _pCurrentPixelImageAnimation;
  CATVizPixelImageAnimation* _pPixelImageAnimationStateOff;
  CATVizPixelImageAnimation* _pPixelImageAnimationStateOn;
  CATVizPixelImageAnimation* _pPixelImageAnimationStateOver;
  CATVizPixelImageAnimation* _pPixelImageAnimationStateOverOn;
  CATBoolean _removeAnimationFlag;
  CATBoolean _endFlag;

  CATVidWidget*   _pWidget;
  static CATVidListener * GetListener();
  static CATVidListener *_pListener;
  CATCallback _cb;
  friend class CATVidListener;

};

//-----------------------------------------------------------------------
#endif
