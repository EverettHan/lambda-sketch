// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATVisViewing.h
// Header definition of CATVisViewing
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  June 2009  Creation: ywg
//===================================================================
#ifndef CATVisViewing_H
#define CATVisViewing_H

#include "CATVisImmersivePanel.h"
#include "CATVidCtl.h"
#include "CATVisViewingUtility.h"

#include "CATMathPoint2Df.h"

class CATViewer;
class CATRep;
class CATViewpoint;

class CATVidCtlScreen;
class CATVidGPSquare;
class CATVidCtlPushButton;
class CATVidGPLabel;
class CATVidCtlFrame;
class CATVidLaySideAttach;
class CATVidFraDialogBox;

enum  ViewpointFixedState {UnchangedState, UnfixedViewpoint, FixedViewpoint};

//-----------------------------------------------------------------------

class ExportedByCATVisImmersivePanel CATVisViewing: public CATVidCtl
{
   CATDeclareClass;

   //DeclareResource(CATVis3DViewing, CATVisViewing);
   virtual  char*  GetResourceFilename(int  nDepth)  const
   {
      return  (char  *)(  nDepth  <=  0  ?  "CATVisViewing"  :  CATVidCtl::GetResourceFilename(nDepth-1)  );
   }

public:

   CATDeclareCBEvent(VIS_VIEWING_DELETED);

   // Standard constructors and destructors
   // -------------------------------------
   CATVisViewing (CATCommand *i_pParent, const CATString & i_pIdentifier, CATVisViewingStyle iStyle = VIEWING_DEFAULT_STYLE);


   virtual void SetViewer(CATViewer * i_pViewer);
   virtual void SetViewpoint(CATViewpoint * i_pViewpoint, ViewpointFixedState isFixed = UnchangedState);

   CATViewpoint* GetViewpoint() const;
   CATVidFraDialogBox * GetDialogBox();

protected:

   virtual ~CATVisViewing ();

   virtual void BuildDialog(CATViewer * i_pViewer);
   virtual CATVidCtlScreen * BuildCtlScreen();
   virtual void UpdateCamera();
   virtual void FrameModified(CATMathPoint2Df iFramePos, CATMathPoint2Df iFrameDim);
   virtual CATRep * GetRepFromViewpoint(CATViewpoint * i_pViewpoint);
   virtual void ReframeOnRep(CATViewpoint * io_Viewpoint = NULL);

   virtual void UpdateQuality();

   void ConnectCallbacks();
   void DisconnectCallbacks();
   void SetHandleDimension(CATMathPoint2Df iPos, CATMathPoint2Df iDim);
   void UpdateHandleDimension();

private:
   // Copy constructor and equal operator
   // -----------------------------------
   CATVisViewing (CATVisViewing &);
   CATVisViewing& operator=(CATVisViewing&);

   void OnHandle (CATCommand *i_pCommand, CATNotification *i_pNotification, CATCommandClientData i_commandData );

   void ViewpointModifiedCB(  CATCallbackEvent, void *, CATNotification * evt, CATSubscriberData data, CATCallback );
   void AnimationStartedCB(  CATCallbackEvent, void *, CATNotification * evt, CATSubscriberData data, CATCallback );
   void AnimationStopedCB(  CATCallbackEvent, void *, CATNotification * evt, CATSubscriberData data, CATCallback );

   CATVidFraDialogBox * CreateDialogBox();

   void ResizeOverView();
   void GraphicSizeChangeCB(CATCallbackEvent event, void * sender, CATNotification * notif, CATSubscriberData data, CATCallback);
   void InterpretKeybdEvent(CATCallbackEvent event, void * sender, CATNotification * notif, CATSubscriberData data, CATCallback);

   void ViewerUpdateCB(CATCallbackEvent event, void * sender, CATNotification * notif, CATSubscriberData data, CATCallback);


protected:

   CATViewer         * _pViewer;
   CATViewpoint      * _prViewpoint;
   CATRep            * _pBagRep;

   ViewpointFixedState _isViewpointFixed;

   CATVidCtlScreen   * _pCtlScreen;
   CATVidGPSquare    * _pSquare;
   CATVidGPLabel     * _pStdViewLabel;
   CATVidGPLabel     * _pLostHelpLabel;
   CATVidGPLabel     * _pEmptyViewLabel;

   CATVidLaySideAttach * _pLaySideAttach;

   CATVidCtlFrame    * _pHandle;
   CATMathPoint2Df     _handlePos;
   CATMathPoint2Df     _handleDim;

   CATVidCtlPushButton * _pStdViewButton;

   CATVidFraDialogBox * _pDialogBox;

   int        _viewpointAnimatedFlag;
   float      _maxAngle;
   float      _minAngle;
   int        _stdCameraOn;
   int        _frameManip;
   
   CATVisViewingStyle _viewingStyle;

   int Vis_Viewing_Version;

};

//-----------------------------------------------------------------------

#endif
