#ifndef CAT2DViewer_H
#define CAT2DViewer_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


#include "CATVisController.h"
#include "CATViewer.h"
#include "CAT2DViewpoint.h"
#include "CAT2DBoundingBox.h"

class CAT2DRep;
class CATDlgScrollBar;
class CATMathPlane;

/**
* Class to display 2D Graphic Representations on the screen.
* 
*/
class ExportedByCATVisController CAT2DViewer : public CATViewer
{
  CATDeclareClass;

  public:

  /**
   * Creates a 2D Dialog frame.
   * @param iFather Dialog object the viewer will be inserted into.
   * @param iName Name of the viewer.
   * @param iStyle Frame style (See CATDlgFrame styles)
   * @param iWidth Width of the viewer's window (in pixel)
   * @param iHeight Height of the viewer's window
   * @param iViewerStyle 
   * Options of the viewer's behaviour. 
   */
  CAT2DViewer (CATDialog *iFather, const CATString &iName, CATDlgStyle style=NULL, 
   const int iWidth = 800, const int Height= 500, 
    const CATViewerStyle iViewerStyle=NULL);

 /** @nodoc */
  virtual ~CAT2DViewer();

  /**
   * Reframes a zone of the model into the window. 
   * <br>This zone is described in model
   * coordinates. All the zone (or more depending of width/height ratios) is seen. 
   * @param iXMinModel Left side of the zone
   * @param iXMaxModel Right side of the zone
   * @param iYMinModel Bottom side of the zone
   * @param iYMaxModel Top side of the zone
   */
  virtual void ReframeOn( const float iXMinModel=-1e+10, const float iXMaxModel=1e+10, 
			  const float iYMinModel=-1e+10, const float iYMaxModel=1e+10);
  
  /**
   * Gets the rectangle zone seen through the window.
   * @param oXMinModel Left side of the zone
   * @param oXMaxModel Right side of the zone
   * @param oYMinModel Bottom side of the zone
   * @param oYMaxModel Top side of the zone
   */
  virtual void GetViewport( float &oXMinModel, float &oXMaxModel, 
			       float &oYMinModel, float &oYMaxModel) const;
  
  /**
   * Gets the rectangle zone of the representations attached to the viewer.
   * return CAT2DBoundingBox.
   */
  virtual CAT2DBoundingBox GetGlobal2DBoundingBox();

  /**
   * Synchronizes the 3DMainViewpoint and the 2DMainViewpoint. 
   * The synchronization is done by a geometrical relation : The position
   * of the 2D viewpoint'space into 3D viewpoint'space is gived by a 3D Plane.
   * @param iPlane plane of the 2D space into 3D space.
   */
  void SetPlane( const CATMathPlane &iPlane);

  /** 
   *Gets the point expressed in the model coordinate system lying under the given pixel position.
   * @param iModelPoint
  */
  virtual CATMathPoint2Df GetPixelCoordinates( const CATMathPoint2Df &iModelPoint) const; 

  /** 
   *Gets the pixel position at which a given model point is displayed.
   * @param iPixelPoint
  */
  virtual CATMathPoint2Df GetModelCoordinates( const CATMathPoint2Df &iPixelPoint) const;
 
 /** @nodoc */
  void InterpretKeybdEvent( CATCallbackEvent, 
			    void *,
			    CATNotification *, 
			    CATSubscriberData, 
			    CATCallback);

  /** @nodoc */
  void RestoreLastMainViewpoint();
 
//------------------------------------------------------------------------------
  protected:

   virtual CATVizViewer *CreateLetterObject(CATString i_name, int i_nSizeX, int i_nSizeY, CATViewerStyle i_viewerStyle);

 /** @nodoc */
  virtual void UpdateLayout();

  //  Scrollbars
  //  ----------

 /** @nodoc */
  CATDlgScrollBar *_Scrollbar[2];
 /** @nodoc */
  CATCallback _ViewpointCB;
 /** @nodoc */
  int _LastScrollPos[2];
 /** @nodoc */
  float _ScrollbarMinBound[2], _ScrollbarMaxBound[2];
   
//------------------------------------------------------------------------------
  private :
    // Scrollbars mechanism
    //---------------------
 /** @nodoc */
    void ViewportModified( CATCallbackEvent, void *, CATNotification *, CATSubscriberData Data, CATCallback);
 /** @nodoc */
    void Scroll (CATCommand *, CATNotification *, CATCommandClientData);
 /** @nodoc */
    int _ScrollbarAlreadyUpdated;

    // Synchronization 3DMainViewpoint & 2DMainViewpoint
    //--------------------------------------------------
 /** @nodoc */
    void Update3DMainViewpoint( CATCallbackEvent, void *, CATNotification *, CATSubscriberData Data, CATCallback);
 /** @nodoc */
    //CATCallback _Viewpoint3DChangeCB;
 /** @nodoc */
    CATMathPlane *_3DPlane;

};

#endif
