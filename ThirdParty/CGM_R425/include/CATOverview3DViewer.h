#ifndef CATOverview3DViewer_H
#define CATOverview3DViewer_H
//
// COPYRIGHT DASSAULT SYSTEMES 1996
//----------------------------------------------------------------------
// Abstract: The base class for an oriented Graph Viewer
//
//----------------------------------------------------------------------
// Usage:    Like any Object from Dialog FrameWork
//----------------------------------------------------------------------
// Inheritance:    CATOverview3DViewer
//                     CAT3DViewer
//                        CATViewer
//                           CATDlgFrame (Dialog Framework)
//----------------------------------------------------------------------
// Main methods:
//
//----------------------------------------------------------------------
#include "CATVisController.h"

#include "CAT3DViewer.h"
#include "CAT3DViewpoint.h"
#include "CAT2DCustomRep.h"
#include "CATDataType.h"

class CAT2DRectangleGP;
class CAT2DMarkerGP;
class CAT2DManipulator;

class ExportedByCATVisController CATOverview3DViewer : public CAT3DViewer
{
   public :

      CATOverview3DViewer ( CATDialog *parent, CATViewer *viewer, const CATString &name, CATDlgStyle style, const int width, const int height, const CATViewerStyle iViewerStyle);
      virtual ~CATOverview3DViewer();

       
   private :

      void UpdateGP();
      void VerifyGP(float masque[], float center[], CATINTPTR manipData=0);
      void ModifyGP (const float masque[]);
      void UpdateViewport();
      void Create            (CATCommand *, CATNotification *, CATCommandClientData);
      void ResizeOverview    (CATCommand *, CATNotification *, CATCommandClientData);

      void BeginManipulateCB (CATCommand *, CATNotification *, CATCommandClientData);
      void TransManipulateCB (CATCommand *, CATNotification *, CATCommandClientData);
      void ZoomManipulateCB  (CATCommand *, CATNotification *, CATCommandClientData);
      void EndManipulateCB   (CATCommand *, CATNotification *, CATCommandClientData);

      void UpdateViewer (CATCallbackEvent, void *, CATNotification *, CATSubscriberData, CATCallback);
      void ModifyBackground (CATCallbackEvent, void *, CATNotification *, CATSubscriberData, CATCallback);
      CATCallback _viewpointChangedCB, _backgroundChangedCB;

      void ViewerCopy (CATViewer * sourceViewer, CATViewer * targetViewer) ;
      void BackgroundCopy (CATViewer * sourceViewer, CATViewer * targetViewer) ;

      CATViewer *_fatherViewer;

      CAT2DCustomRep *_customRep, *_pt1Rep, *_pt2Rep;
      CAT2DRectangleGP *_customRECT1, *_customRECT2, *_customRECT3, *_customRECT4, *_customGP1, *_customGP2;
      CAT2DMarkerGP *_customPT1, *_customPT2;
      CATGraphicAttributeSet _customAttribut1, _customAttribut2;
      CAT2DManipulator  *_trans, *_zoom1, *_zoom2;
      CAT3DViewpoint _viewpoint3D;

      float _xmin, _xmax, _ymin, _ymax;
      float _xminViewer, _xmaxViewer, _yminViewer, _ymaxViewer;
      float _xCenter, _yCenter;
      float _ySizeMin, _miniSize;
      float _xSize, _ySize, _ratio;
      int   _manipulate, _limited;
};

#endif  
