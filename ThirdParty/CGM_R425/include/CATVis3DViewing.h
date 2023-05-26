// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATVis3DViewing.h
// Header definition of CATVis3DViewing
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  June 2009  Creation: ywg
//===================================================================
#ifndef CATVis3DViewing_H
#define CATVis3DViewing_H

#include "CATVisImmersivePanel.h"
#include "CATVisViewing.h"
#include "CATVisViewingUtility.h"

#include "CATMathPoint2Df.h"
#include "CATMathPointf.h"

#include "CAT3DBoundingSphere.h"

class CAT2DBoundingBox;
class CATViewer;
class CATViewpoint;
class CAT3DViewpoint;
class CATPixelImage;
class CATViz3DCamera;
class CATRep;
class CAT3DRep;
class CAT2DRep;

class CATVidCtlScreen;
class CATVidGPLabel;

//-----------------------------------------------------------------------

class ExportedByCATVisImmersivePanel CATVis3DViewing: public CATVisViewing
{
   CATDeclareClass;

   //DeclareResource(CATVis3DViewing, CATVisViewing);
   virtual  char*  GetResourceFilename(int  nDepth)  const
   {
      return  (char  *)(  nDepth  <=  0  ?  "CATVis3DViewing"  :  CATVisViewing::GetResourceFilename(nDepth-1)  );
   }

public:

   // Standard constructors and destructors
   // -------------------------------------
   CATVis3DViewing (CATCommand *i_pParent, const CATString & i_pIdentifier, CATVisViewingStyle iStyle = VIEWING_DEFAULT_STYLE);

   virtual void SetViewer(CATViewer * i_pViewer);
   virtual void SetViewpoint(CATViewpoint * i_pViewpoint, ViewpointFixedState isFixed = UnchangedState);

protected:
   virtual ~CATVis3DViewing ();

   virtual CATVidCtlScreen * BuildCtlScreen();
   virtual void UpdateCamera();
   virtual void FrameModified(CATMathPoint2Df iFramePos, CATMathPoint2Df iFrameDim);
   virtual CATRep * GetRepFromViewpoint(CATViewpoint * i_pViewpoint);
   virtual void ReframeOnRep(CATViewpoint * io_Viewpoint = NULL);
   virtual CAT3DBoundingSphere GetBoundigSphereFromRep(CAT3DRep * iRep);

   virtual void UpdateQuality();

private:
   // Copy constructor and equal operator
   // -----------------------------------
   CATVis3DViewing (CATVis3DViewing &);
   CATVis3DViewing& operator=(CATVis3DViewing&);

   void OnStdView(CATCommand *i_pCommand, CATNotification *i_pNotification, CATCommandClientData i_commandData );

   void CameraEndManipulationCB(CATCommand *i_pCommand, CATNotification *i_pNotification, CATCommandClientData i_commandData );

   void MouseMoveOverCB (CATCommand *i_pCommand, CATNotification *i_pNotification, CATCommandClientData i_commandData );

private:

   int GetSphereIntersection(const CATMathPoint2Df iMousePos, CAT3DViewpoint * iViewpoint, int &ioSide, CATMathPointf &oIntersection);

   void ComputeFrameDimension(CATMathPoint2Df & ioPos, CATMathPoint2Df & ioDim);
   float GetFocusDistance();
   int GetIntersection(const CATMathPoint2Df iPickPos, CATMathPointf & oIntersection);

   CATPixelImage * CreateStdCameraImage(CATViz3DCamera * iCamera);

   void DisplayEmptyMsg(int iDisplay = 1);
   CATVidGPLabel * _pNoticeLabel_1;
   CATVidGPLabel * _pNoticeLabel_2;
   CATVidGPLabel * _pNoticeLabel_3;

   int _is_be_invalid;
   
   CAT3DBoundingSphere _global_be;
};

//-----------------------------------------------------------------------
#endif
