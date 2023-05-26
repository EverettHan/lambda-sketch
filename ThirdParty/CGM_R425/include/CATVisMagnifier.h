#ifndef CATVidMagnifier_h
#define CATVidMagnifier_h

// COPYRIGHT Dassault Systemes 2014

#include "CATVisMagnifierHeader.h"
#include "CATCommand.h"
#include "list.h"
#include "CATMagnifierEvent.h"
#include "CATVisRepresentationRole.h"
#include "CATMathPoint2Df.h"

class CATVizViewer;
class CATVidCtlViewerBase;
class CATVidFraOverviewWindow;
class CATMathPoint2Df;
//class CAT3DBagRep;
//class CAT3DMarkerGP;
//class CAT3DCustomRep;
class CATVidLayLayer;
class CATVidLayGrid;
//class CATVidGPLine;
class CATVidGPPolygon;
class CATViewpoint;
//class CATRep;
class CATCallbackManager;

class ExportedByCATVisMagnifier CATVisMagnifier : public CATCommand
{
  CATDeclareClass;

public:

  struct ViwpointMap
  {
    CATViewpoint* sourceVp;
    CATViewpoint* targetVp;

    ViwpointMap();
    ~ViwpointMap();
  };

  enum TextAnchorPosition
  {
    TextAnchorPosition_LeftTop = 0,
    TextAnchorPosition_CenterTop,
    TextAnchorPosition_RightTop,
    TextAnchorPosition_LeftCenter,
    TextAnchorPosition_RightCenter,
    TextAnchorPosition_LeftBottom,
    TextAnchorPosition_CenterBottom,
    TextAnchorPosition_RightBottom
  };

 /** @nodoc */
  CATDeclareCBEvent (MAGNIFIER_POSITION_UPDATE);

  // Returns the magnifier for given viewer. It will create new one if it is not created previously.
  static CATVisMagnifier* CreateMagnifierForViewer(CATVizViewer* pViewer);

  // Returns the magnifier for given viewer. It will not create new one if it is not created previously.
  static CATVisMagnifier* GetMagnifierForViewer(CATVizViewer* pViewer);

  // Returns the parent viewer associated with magnifier.
  const CATVizViewer* GetViewer() const;

  // Decides magnifier position according to dominant hand.
  void SetRightHandedMagnifier(CATBoolean isRightHanded = TRUE);

  // Returns whether magnifier will work for right hand user or left hand user.
  CATBoolean GetRightHandedMagnifier() const;

  // Sets the anchor position of text around magnifier.
  void SetTextAnchorPosition(TextAnchorPosition anchor);

  // Gets current anchor position of text around magnifier.
  TextAnchorPosition GetTextAnchorPosition() const;

  // Sets magnifier to text distance.
  void SetMagnifierToTextDistance(const CATMathPoint2Df& dist);

  // Gets magnifier to text distance.
  CATMathPoint2Df GetMagnifierToTextDistance() const;

  // Gets the cuurent position of magnifier.
  CATMathPoint2Df GetMagnifierPosition() const;

  // Gets the cuurent position of text around magnifier.
  CATMathPoint2Df GetMagnifierTextPosition() const;

  // Gives the size of magnifier.
  CATMathPoint2Df GetMagnifierSize() const;

  // Gives magnifier to finger distance.
  CATMathPoint2Df GetMagnifierToFingerDistance() const;

protected:

  /**
  * Constructs a CATVisMagnifier
  */
  CATVisMagnifier(CATVizViewer* pViewer);
  virtual ~CATVisMagnifier();

  CATCallbackManager* GetCallbackManager();

  // Creates all magnifier components for 3D or 2D viewer. It is created only once per viewer.
  void CreateVidMagnifierWindow(const bool iIs3DViewer);

  // It will update magnifier's view on each move
  void UpdateOverview(const CATMathPoint2Df& iCenter);

  // Shows the magnifier at the location given in magnifier event
  void ShowMagnifier  (const CATMagnifierEvent& iMagnifierEvent);

  // Hides the magnifier
  void HideMagnifier  (const CATMagnifierEvent& iMagnifierEvent);

  // Moves magnifier at the location given in magnifier event
  void MoveMagnifier  (const CATMagnifierEvent& iMagnifierEvent);

  // Clone all parent viewer's viewpoint to magnifier hidden viewer
  void CloneAllViewpointsInMagnifier();

  void ClearViwpointMap();

  CATMathPoint2Df _previousPoint;

protected:

  // Pointer to the parent viewer. It must be supplied in constructor.
  CATVizViewer *_pViewer;

  // CtlViewer of magnifier.
  CATVidCtlViewerBase *_pCtlViewer;

  // Determines the magnifier position for right handed or left handed user.
  CATBoolean _isRightHanded;

  // Border size of magnifier ring.
  float _magBorderSize;

  // The top most window of magnifier which will remain on top over all other windows.
  CATVidFraOverviewWindow * _pOverviewWindow;

  // Distance of magnifier from finger in X-direction.
  // This distance can also be set from environment variable MAGNIFIER_X_SHIFT
  int _xShift;

  // Distance of magnifier from finger in Y-direction.
  // This distance can also be set from environment variable MAGNIFIER_Y_SHIFT
  int _yShift;

  // List of all mapped viewpoints.
  // The list is filled in each ShoeMagnifier call, is used in MoveMagnifier and is cleared in each HideMagnifier
  list<ViwpointMap> _listVp;

  // We need to set the sprites in ShowMagnifier to improve the performance.
  // Gets the sprites settings from main viewer and sets them in HideMagnifier.
  int _mainViewerSprites;

  // Callback managet to dispatch callbacks
  CATCallbackManager* _CallbackManager;

  // Defines the anchor postion of text around magnifier
  TextAnchorPosition  _anchor;

  // Distance from magnifier to text
  CATMathPoint2Df _magnifierToTextDistance;

  // Current position of magnifier
  CATMathPoint2Df _magnifierPosition;

  // Current position of text around magnifier
  CATMathPoint2Df _magnifierTextPosition;

private:

  // Maintains the list of all created magnifiers so far.
  // If user create the same magnifier already created for particular viewer, it will be returned from this list.
  static list<CATVisMagnifier> _createdMagnifiers;

  // Callback id for VIEWER_MAGNIFIER_EVENT event.
  CATCallback _magnifierEvent;

  // Callback id for VIEWER_DESTROYED event.
  CATCallback _vpDestroyedEvent;
  
  // Overview of VID component structure inside magnifier
  //
  //          _pOverviewWindow
  //                  |
  //              _pLayLayer
  //              /         \
  //      _pGridPolygon    _pGridViewer
  //            /               \
  //     _pPolygonGP          _pCtlViewer

  // Layer to accommodate other sub layers.
  CATVidLayLayer *_pLayLayer;

  // Grid layer to accommodate magnifier's ctlviewer with border as spacing.
  CATVidLayGrid *_pGridViewer;

  // It contains magnifier texture.
  CATVidGPPolygon *_pPolygonGP;
  
  // Layer to accommodate _pPolygonGP
  CATVidLayGrid *_pGridPolygon;

  // Callback for VIEWER_MAGNIFIER_EVENT event.
  void MagnifierEvent (CATCallbackEvent event, void *, CATNotification * notif, CATSubscriberData data, CATCallback);

  // Callback for VIEWER_DESTROYED event.
  void ViewerDestroyed(CATCallbackEvent event, void *, CATNotification * notif, CATSubscriberData data, CATCallback);

  // Copy constructor and equal operator
  // -----------------------------------
  CATVisMagnifier (CATVisMagnifier &);
  CATVisMagnifier& operator=(CATVisMagnifier&);
};

#endif // CATVidMagnifier_h
