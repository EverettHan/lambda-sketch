#ifndef CAT3DViewer_H
#define CAT3DViewer_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


#include "CATVisController.h"
#include "CATViewer.h"
#include "CATProjectionType.h"
#include "CATMathDirectionf.h"
#include "CAT3DBoundingSphere.h"
#include "VisClipPlaneDesc.h"
#include "CATIAV5Level.h"


class CAT3DViewpoint;
class CAT3DViewport;
class CAT3DRep; 
class CAT2DRep;
class CATViz3DViewer;

/**
* Class to display 3D Graphic Representations on the screen.
* 
*/

class ExportedByCATVisController CAT3DViewer : public CATViewer
{
 CATDeclareClass;

 public :

  /**
  * Constructs a CAT3DViewer.
  * @param iFather  
  * @param iStyle
  * @param iWidth  Width in pixel
  * @param iHeight Height in pixel
  * @param iViewerStyle Options of the viewer's behaviour.
  */
  CAT3DViewer (CATDialog * iFather,
               const CATString & iName,
               CATDlgStyle iStyle=CATDlgFraNoTitle,
	             const int iWidth= 800,
	             const int iHeight= 500,
	             const CATViewerStyle iViewerStyle=NULL);

 /** @nodoc */
  virtual ~CAT3DViewer();
  
  
  //  operation on the main 3D viewpoint
  //  ----------------------------------
  /**
  * Modifies the Main 3D viewpoint so that the specified CAT3DBoundingSphere 
  * takes as much place as possible on the screen.
  * @param iBs3D The CAT3DBoundingSphere you want to reframe on
  * @see CAT3DBoundingSphere
  */
  virtual void ReframeOn(const CAT3DBoundingSphere &iBs3D); // To frame on a specific bounding sphere
  /** 
   * Gets the CAT3DBoundingSphere of the scene displayed by the CAT3DViewer.
   */
  CAT3DBoundingSphere GetGlobalBoundingSphere();
  
  //  definition and fog activation 
  //  -----------------------------
  
  /** @nodoc */
 void SetFogMode    (const int);
 /** @nodoc */
  int IsFogOn() const;
  
 /** @nodoc */
  CATMathDirectionf GetVertical();
 /** @nodoc */
  CATMathDirectionf & GetNorth () ;
  
 /** @nodoc */
  void SetGround (const CATMathDirectionf &vertical, const CATMathDirectionf &north);

  // Clipping plane (maximum 6)
  // -------------------------
  
 /** @nodoc */
  void AddClippingPlane (const int nb_planes, const float *point, const float *normal, const int clippingPlaneFlags = VisClipPlaneDesc::fCapping);
 /** @nodoc */
  void RemoveClippingPlane ();
  
 /** @nodoc */
  void AddCullingBox (const int nb_planes, const float *point, const float *normal);
 /** @nodoc */
  void RemoveCullingBox ();

 /** @nodoc */
  void InterpretKeybdEvent( CATCallbackEvent, 
			    void *,
			    CATNotification *, 
			    CATSubscriberData, 
			    CATCallback);
  

 /** @nodoc */
  void RestoreLastMainViewpoint();
 
 /** @nodoc  return NULL is viewpoint tracking is off */
  CATCommand* IsViewpointTracking();

//------------------------------------------------------------------------------

 protected :
  
 /**
  * @nodoc
  * Constructs a CAT3DViewer.
  * @param iFather  
  * @param iStyle
  * @param iWidth  Width in pixel
  * @param iHeight Height in pixel
  * @param iViewerStyle Options of the viewer's behaviour.
  */
  CAT3DViewer (CATDialog * iFather,
               const CATString & iName,
               CATDlgStyle iStyle,
	             const int iWidth,
	             const int iHeight,
	             const CATViewerStyle iViewerStyle,
               CATViz3DViewer *letter);


    
   virtual CATVizViewer *CreateLetterObject(CATString i_name, int i_nSizeX, int i_nSizeY, CATViewerStyle i_viewerStyle);
  // Ground informations for Viewpoint manipulation:
  // -----------------------------------------------
  
 /** @nodoc */
  CATMathDirectionf _north;	

public :

  //  Event Define
  //  ------------
  
   /** @nodoc */
  CATDeclareCBEvent (NAVIGATION_GROUND_CHANGE);
   /** @nodoc */
  CATDeclareCBEvent (VIEWPORT_EVENT);
   /** @nodoc */
  CATDeclareCBEvent (ROTATE_EVENT);
   /** @nodoc */
  CATDeclareCBEvent (POSITION_EVENT);


};


#endif
