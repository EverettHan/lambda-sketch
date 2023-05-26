#ifndef CATOverview2DViewer_H
#define CATOverview2DViewer_H
//
// COPYRIGHT DASSAULT SYSTEMES 1996
//----------------------------------------------------------------------
// Abstract: The base class for an oriented Graph Viewer
//
//----------------------------------------------------------------------
// Usage:    Like any Object from Dialog FrameWork
//----------------------------------------------------------------------
// Inheritance:    CATOverview2DViewer
//                     CAT2DViewer
//                        CATViewer
//                           CATDlgFrame (Dialog Framework)
//----------------------------------------------------------------------
// Main methods:
//
//----------------------------------------------------------------------
#include "CATVisController.h"

#include "CAT2DViewer.h"

class CAT2DBagRep;
class CAT2DCustomRep;
class CAT2DRectangleGP;
class CAT2DMarkerGP;
class CAT2DManipulator;

class ExportedByCATVisController CATOverview2DViewer : public CAT2DViewer
{
 public :

    CATOverview2DViewer ( CATDialog *parent, CATViewer *viewer, const CATString &name, CATDlgStyle style, const int width, const int height, const CATViewerStyle iViewerStyle);
    virtual ~CATOverview2DViewer();

    void Update();
       
  private :

    void Create             (CATCommand *, CATNotification *, CATCommandClientData);
    void ResizeOverview     (CATCommand *, CATNotification *, CATCommandClientData);
    void ManipulateOverview (CATCommand *, CATNotification *, CATCommandClientData);

    void UpdateViewpoint (CATCallbackEvent, void *, CATNotification *, CATSubscriberData, CATCallback);
    CATCallback _viewpointChangedCB;

    CATViewer *_fatherViewer;
    CAT2DBagRep *_bagRep;
    CAT2DCustomRep *_customRep, *_pt1Rep, *_pt2Rep;
    CAT2DRectangleGP *_customRECT1, *_customRECT2, *_customRECT3, *_customRECT4, *_customGP1, *_customGP2;
    CAT2DMarkerGP *_customPT1, *_customPT2;
    CATGraphicAttributeSet _customAttribut1, _customAttribut2;
    float _topRight[2], _bottomLeft[2], _zoom, _size;
    int _manipulate;

    CAT2DManipulator  *_trans, *_zoom1, *_zoom2;
};

#endif  
