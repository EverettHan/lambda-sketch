#ifndef CAT3DManipulator_h
#define CAT3DManipulator_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATVisFoundation.h"
#include "CATManipulator.h"
#include "CATMathPoint.h"
#include "CATMathLine.h"
#include "CATMathPlane.h"
#include "CAT4x4Matrix.h"
#include "CATMathAxis.h"
#include "CATTransformationNotification.h"
#include "CATViz3DViewer.h"
#include "CATBaseUnknown_WR.h"

class CAT3DBagRep;
class CAT3DRep;
class CAT3DViewpoint;
class CATDeviceEvent;
class CATMouseDevice;
class CATPickPath;
class CAT3DViewer;
/**
  * Class to control a 3D representation.
  * <b>Role</b>:
  * A CAT3DManipulator is a Controller attached to a 3D representation providing 
  * a proposition of a new position for 3D manipulation after the representation
  * selected by the user has been manipulated.
  * <p>
  * Usage of manipulators
  * <ul>
  * <li>In the instanciation : 
  *	<ol> 
  *	<li>	Instanciate a manipulator connected to the representation :
  *		  <pre>CAT3DManipulator * _Manip = new 
  *		    CAT3DManipulator( this, "MYName", MYRep, CAT3DManipulator::Translation);</pre>
  *	
  *	<li>	Position the manipulator	
  *		  <pre>_Manip->SetPosition( PositionComputedFromNewModelization)</pre>
  *			
  *	<li>	Set characteristics (Invariants)   Note: Do it after SetPosition()
  *		  <pre>Manip->SetTranslationDirection( CATMathJ);</pre>
  *			
  *	<li> 	Branch a callback in you father command to be informed about the manipulation
  *		  <pre>AddAnalyseNotificationCB( _Manip, CATManipulator::GetCATManipulate(), 
  *		    (CATCommandMethod) &MYCommand::MYCallback, NULL);</pre>
  *	</ol>
  * <li>In the callback,
  *	<ol>
  *     <li> Read data of manipulation
  *		<ul>
  *		<li> read the RESULT of the manipulation
  *		<pre>CATMathAxis Position = ((CAT3DManipulator *)Command)->GetPosition();</pre>
  *
  *		<li> read the event elementary TRANSFORMATION of the manipulation
  *	        <pre>CATTransformationNotification *TransfoNotif =
  *	        ((CATTransformationNotification *) Command->SendCommandSpecificObject(
  *	        CATTransformationNotification::ClassName(), Notification));
  *	        CATMathTransformation *Transformation = TransfoNotif->GetNotification();
  *		</pre></ul>
  *	<li>	In the callback, Update your modelization
  *	    
  *	<li>    In the callback, Reposition the manipulator if needed (usualy when there is constraints)
  *		  	<pre>_Manip->SetPosition( PositionComputedFromNewModelization)</pre>
  *	</ol>			
  * </ul>
  */		

class ExportedByCATVisFoundation CAT3DManipulator : public CATManipulator
{
//------------------------------------------------------------------------------
  CATDeclareClass;

  friend class CAT3DVisuHandle;

  public:
/**
* Defines the different types of manipulation available for
* a 3D representation.
*
* @param NoManipulation             The CAT3DManipulator does no specific work
* @param DirectionTranslation       The CAT3Dmanipulator contrains its position along a given direction during the manipulation
* @param PlaneTranslation           The CAT3Dmanipulator contrains its position along a given plane during the manipulation
* @param PlaneMovement              Do not use 
* @param LineRotation               The CAT3Dmanipulator contrains its position on a circle normal to a given axis
* @param PointRotation              The CAT3Dmanipulator contrains its position on a sphere centered on a given point
* @param FrontestPlaneTranslation   The CAT3Dmanipulator contrains its position along a plane parallel to the screen
**/

    enum ManipulationStyle {
      NoManipulation,		
      DirectionTranslation,	
      PlaneTranslation,		
      PlaneMovement,
      LineRotation,		
      PointRotation,	
      FrontestPlaneTranslation
    };
  
    // Structors
    //----------
    /** Construction of the manipulator.
     *  @param iFirstStyle = style of manipulation used by Mouse Left button drag
     *  @param iSecondStyle = style of manipulation used by Mouse Left+Middle buttons drag (left THEN middle)
     */
    CAT3DManipulator( CATCommand *iFather, const CATString &iName,
      CAT3DRep *iRep, 
      const ManipulationStyle iFirstStyle=NoManipulation, 
      const ManipulationStyle iSecondStyle=NoManipulation);

   /** @nodoc */
    virtual ~CAT3DManipulator();

    // Geometry invariants
    //--------------------
    /** Sets the invariant point of PointRotation. */
    virtual void SetRotationPoint( const CATMathPoint &iPoint);

    /** Sets the invariant direction of DirectionTranslation. */
    virtual void SetTranslationDirection( const CATMathDirection &iWAxis);

    /** Sets the invariant line of LineRotation and PlaneMovement.*/
    virtual void SetRotationLine( const CATMathLine &iLine);

    /** Sets the invariant plane of PlaneTranslation and PlaneMovement.*/
    virtual void SetTranslationPlane( const CATMathPlane &iPlane);

    // Current position of the manipulator
    //------------------------------------
    /** Gets the current position of the manipulator. 
        This Position is not linked to the position of any maniulated representation
        The Manipulator changes that position according to the manipulations */
    virtual CATMathAxis GetPosition() const;
    
    /** Sets the position of the manipulator. */
    virtual void SetPosition( const CATMathAxis &iPosition);

    /**
     * Gets the manipulation style.
     *  @param iFirstStyle = style of manipulation used by Mouse Left button drag
     *  @param iSecondStyle = style of manipulation used by Mouse Left+Middle buttons drag (left THEN middle)
     **/
    void GetManipulationStyle(ManipulationStyle& o_firstStyle, ManipulationStyle& o_secondStyle);
    
    /** 
     * Gets the invariant point of Point Rotation. 
     *  @param o_point = invariant point 
     **/
    void GetRotationPoint( CATMathPoint &o_point);
    
    /** 
     * Gets the invariant direction of translation direction. 
     *  @param o_direction = invariant direction 
     **/
    void GetTranslationDirection( CATMathDirection &o_direction);

    /** 
     * Gets the invariant line of LineRotation and PlaneMovement.
     * @param o_line = invariant line.
     **/
    void GetRotationLine( CATMathLine &o_line);

    /**
     * Gets the invariant plane of translationPlane and PlaneMovement.  
     * @param o_plane = invariant plane.
     **/
    void GetTranslationPlane( CATMathPlane &o_plane);

 /**
     * Determines whether the manipulator is to be used in an immersive environment or not.
     * @param iImmersiveMode = true : the manipulator is used with a stylus device ;
     *                       = false : the manipulator is used with a mouse device.
     **/
    void SetImmersiveMode(const CATBoolean &iImmersiveMode);
 /**
  * @nodoc
  * Requests an object to be retrieved.
  * <br><b>Role</b>:
  *  Asks a command for more information when that command calls you back.
  * @param iUuid
  *  The desired object, given by the ClassName method.
  *  The CAT3DManipulator can return :
  *    <ol>
  *    <li>CATTransformationNotification  The notification containing the transformation associated to the manipulation.
  *    </ol>
  * @param iGraphicNotification
  *  The notification received in the callback which caused the need for that object.
  * @return
  *   A pointer to the retrieved object.
  */  
  virtual void * SendCommandSpecificObject ( const char *iUuid, CATNotification *iGraphicNotification);

    // Manipulation calls from viewer
    //-------------------------------
  /** @nodoc */
    virtual MInfo BeginManipulate( CATNotification *event, CATManipulator *m);
  /** @nodoc */
    virtual MInfo Manipulate( CATNotification *event, CATManipulator *m);
   /** @nodoc */
   virtual MInfo EndManipulate( CATNotification *event, CATManipulator *m);

   /** @nodoc */
   virtual MInfo Preactivate( CATNotification *event, CATManipulator *m);
  /** @nodoc */
    virtual MInfo MoveOver( CATNotification *event, CATManipulator *m);
  /** @nodoc */
    virtual MInfo Move( CATNotification *event, CATManipulator *m);
  /** @nodoc */
    virtual MInfo EndPreactivate( CATNotification *event, CATManipulator *m);
  /** @nodoc */
    virtual MInfo Context( CATNotification *event, CATManipulator *m);
    
//------------------------------------------------------------------------------
  protected:

    // Manipulation style
    // ------------------
  /** @nodoc */
    ManipulationStyle _PrimaryManipStyle;			// With Button 1
  /** @nodoc */
    ManipulationStyle _SecondaryManipStyle;			// With Button 1 + Button 2

    // Manipulation Reference geometry
    // -------------------------------
  /** @nodoc */
    CATMathDirection _UAxis;			// First vector of the plane
  /** @nodoc */
    CATMathDirection _VAxis;			// Second vector of the plane
  /** @nodoc */
    CATMathDirection _Normal; 		// Define plane normal (Is always _UAxis ^ _VAxis)
  /** @nodoc */
    CATMathDirection _Axis;			// Vector of the axis operation
  /** @nodoc */
    CATMathPoint _InvariantPoint;		// Invariant point for rotation and movors

    // Manipulation Tools
    //-------------------
  /** @nodoc */
    virtual MInfo MouseManipulate( CATDeviceEvent *Notification, ManipulationStyle iManipStyle);

    /** @nodoc */
    MInfo StylusManipulate(CATDeviceEvent *Notification);

    // Side forward(-1) or backward(+1) of the contact point on the virtual sphere
  /** @nodoc */
    int side_;
   /** @nodoc */
   CATMathPoint *_RotatePoint;	// Rotate point (Contact or Invariant) for the SpaceDevice
  /** @nodoc */
    CATMathVector ComputeTranslationJump( const CATMathVector &KeyboardJump, const CAT3DViewpoint &Viewpoint);
  /** @nodoc */
	void ConnectReferencesAxis( ManipulationStyle iManipStyle);
  /** @nodoc */
    CATMathDirection *_MousePlaneAxis1;	// First vector of the plane
  /** @nodoc */
    CATMathDirection *_MousePlaneAxis2;	// Second vector of the plane
  /** @nodoc */
    CATMathDirection *_MousePlaneNormal;	// Second vector of the plane
  /** @nodoc */
    ManipulationStyle _CurrentMouseManip;			

    // Geometric tools
    //----------------
  /** @nodoc */
    CATMathPoint GetPickPoint( CATViewerEvent *ViewerEvent);
  /** @nodoc */
    int GetPlaneIntersection( CATDeviceEvent *Notification, CATMathDirection &PlaneAxis, 
      CATMathPoint &PlanePoint, CATMathPoint &Intersection);
  /** @nodoc */
    void GetLineIntersection( CATDeviceEvent *Notification, CATMathDirection &LineAxis, 
      CATMathPoint &LinePoint, CATMathPoint &Intersection);
  /** @nodoc */
    void GetSphereIntersection( CATDeviceEvent *Notification, 
	    const CATMathPoint &iCenter, const double iRadius, int &ioSide, CATMathPoint &oIntersection);

    // Display Feedbacks
  /** @nodoc */
    void Feedback( const int DisplayOrHideRep);	// DisplayOrHideRep: 1=Display  0=Hide
   /** @nodoc */
   CAT3DBagRep *_FeedbackRep;
  /** @nodoc */
    CATPickPath *_RepPath;

    // Dialog datas	
  /** @nodoc */
    int _LastGeneralModifier, _LastMouseModifiers;		// For mouse multi-manipulations 


    // A classer
    //----------
    // Position of the object and event sent while manipulating
  /** @nodoc */
    CATTransformationNotification _Transformation;
  /** @nodoc */
    CATMathAxis _Position;

    // Contact point between user and object
  /** @nodoc */
    CATMathPoint _ContactPoint;
  /** @nodoc */
    CATMathAxis _ContactPosition;	// Position proposed
    
    // Currently linked objects

    // Attention !!! SVQ 06/02/01 : ne plus utiliser _3DViewer (build impact : CAT3DXYZManipulator dans CATIAApplicationFrame)

    CAT3DViewer *_3DViewer;
    CATViz3DViewer *_Viz3DViewer;			// Viewer the manipulator work with  (Found in BeginManipulate ViewerEvent
  /** @nodoc */
    CAT3DViewpoint *_3DViewpoint;	// Viewpoint manip work in  (Found in ViewerEvent.PickPath.Viewpoint

    /**  @nodoc */
    CAT3DViewpoint * Get3DViewpoint ();
    /**  @nodoc */
    void Set3DViewpoint (CAT3DViewpoint * iViewpoint);

  /** @nodoc */
    CATMathTransformation _DataMatrix;		// For decoding

    /** @nodoc */
    CATMathTransformation _StylusPose;

  /** @nodoc */
    CAT4x4Matrix _AbsoluteToRepAxisMatrix;

  private :    
    static CATTrace  *_TraceManipulator3D;
    static int _TraceManipulator3DCounter;
    CATBoolean m_immersiveMode;

     CATBaseUnknown_WR _3DViewpoint_WR;
     
};

#endif
