#ifndef CAT2DManipulator_h
#define CAT2DManipulator_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


//
// CATIA Version 5 Release 1 Framework Visualization
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
//
// Abstract:    Object attached to a 2D representation providing a proposition 
//		of a new position for 2D manipulation
//
//------------------------------------------------------------------------------
//
// Usage:
//	In the instanciation :  
//	1/	Instanciate a manipulator connected to the representation :
//		  CAT2DManipulator * _Manip = new 
//		    CAT2DManipulator( this, "MYName", MYRep, CAT2DManipulator::DirectionTranslation);
//
//	2/	Position the manipulator	
//		  _Manip->SetPosition( PositionComputedFromNewModelization)
//			
//	3/	Set characteristics (Invariants)   Note: Do it after SetPosition()
//		  Manip->SetTranslationDirection( CATMathJ2D);
//			
//	4/ 	Branch a callback in you father command to be informed about the manipulation
//  		  AddAnalyseNotificationCB( _Manip, CATManipulator::GetCATManipulate(), 
//		    (CATCommandMethod) &MYCommand::MYCallback, NULL);
//
//	In the callback :
//	5/      Read data of manipulation
//      	  - read the RESULT of the manipulation
//		    CATMathAxis2D Position = ((CAT2DManipulator *)Command)->GetPosition();
//		or:
//                - read the event elementary TRANSFORMATION of the manipulation
//                  CATTransformationNotification2D *TransfoNotif =
//                     ((CATTransformationNotification2D *) Command->SendCommandSpecificObject(
//                     CATTransformationNotification2D::ClassName(), Notification));
//                  CATMathTransformation2D *Transformation = TransfoNotif->GetNotification();
//
//	6/	Update your modelization
//          
//	7/      Reposition the manipulator if needed (usualy when there is constraints)
//		  _Manip->SetPosition( PositionComputedFromNewModelization)
//				
//------------------------------------------------------------------------------
//
// Main methods:
// -------------
//       
//	CAT2DManipulator( father, "Name", FirstStyle, SecondStyle);
//		First style = used by Mouse Left button drag
//		Second style = used by Mouse Left+Middle buttons drag (left THEN middle)
//
//	SetPosition( CATMathAxis2D)		: Set the position of the manipulator
//	CATMathAxis2D GetPosition()		: Get the position of the manipulator
//
//	SetTranslationDirection( CATMathDirection2D)	: Axis of the DirectionTranslation
//	SetRotationPoint( CATMathPoint2D)	: InvariantPoint for Rotation
//
//
//------------------------------------------------------------------------------
//
// Class:      CAT2DManipulator
// ------        CATManipulator
//                 CATCommand (System FW)
//
//------------------------------------------------------------------------------

#include "CATVisFoundation.h"
#include "CATManipulator.h"
#include "CATTransformation2DNotification.h"
#include "CATMathPoint2D.h"
#include "CATMathDirection2D.h"
#include "CATMathAxis2D.h"

class CAT2DRep;
class CATViz2DViewer;
class CAT2DViewpoint;
class CAT2DBagRep;
class CATDeviceEvent;
class CATPickPath;

/* WARNING : those classes is defined in Visualization framework */
class CATViewer;
class CAT2DViewer;
class CAT3DViewer;

/**
*
* Class to manipulate 3D representations
*
* This object adds 2D specific behaviors to the CATManipulator.
* 
*
**/

class ExportedByCATVisFoundation CAT2DManipulator : public CATManipulator
{
//------------------------------------------------------------------------------

    CATDeclareClass;

    friend class CAT2DVisuHandle;

  public:
/**
* Defines the different types of manipulation available for
* a 2D representation.
*
* @param NoManipulation          The CAT2DManipulator does no specific work
* @param DirectionTranslation    The CAT2Dmanipulator contrains its position along a given direction during the manipulation
* @param Translation             Free translation   
* @param Rotation                The CAT2DManipulator constrains its position on a circle centered on a given point
**/
    enum ManipulationStyle {
      NoManipulation,		
      DirectionTranslation,	
      Translation,		
      Rotation};		

    // Structors
    //----------
    /** Construction of the manipulator.
     *  @param iFirstStyle = style of manipulation used by Mouse Left button drag
     *  @param iSecondStyle = style of manipulation used by Mouse Left+Middle buttons drag (left THEN middle)
     */
    CAT2DManipulator( CATCommand *iFather, const CATString &iName, CAT2DRep *iRep=NULL,
	  const ManipulationStyle iFirstStyle=CAT2DManipulator::Translation, 
	  const ManipulationStyle iSecondStyle=CAT2DManipulator::NoManipulation);
 
   /** @nodoc */
    virtual ~CAT2DManipulator();
    
    // Geometry invariants
    //--------------------
    /** Set the direction of DirectionTranslation ManipulationStyle. */
    virtual void SetTranslationDirection( const CATMathDirection2D &iAxis);
    /** Set the invariant point of Rotation ManipulationStyle. */
    virtual void SetRotationPoint( const CATMathPoint2D &iPoint);
    
    /** 
     * Gets the current position of the manipulator. 
     *
     *   This Position is not linked to the position of any maniulated representation
     *   The Manipulator changes that position according to the manipulations 
     */
    virtual CATMathAxis2D GetPosition() const;

    /** Sets the position of the manipulator. */
    virtual void SetPosition( const CATMathAxis2D &iPosition);

 /**
  * @nodoc
  * Requests an object to be retrieved.
  * <br><b>Role</b>:
  *  Asks a command for more information when that command calls you back.
  * @param iUuid
  *  The desired object, given by the ClassName method.
  *  The CAT2DManipulator can return :
  *    <ol>
  *    <li>CATTransformation2DNotification  The notification containing the transformation associated to the manipulation.
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
    virtual MInfo BeginManipulate(CATNotification *, CATManipulator *);
  /** @nodoc */
    virtual MInfo Manipulate(CATNotification *, CATManipulator *);
  /** @nodoc */
    virtual MInfo EndManipulate(CATNotification *, CATManipulator *);

 /** 
 * Changes the styles of manipulation.
 * @param iFirstStyle =  style of manipulation used by Mouse Left button drag
 *   @param iSecondStyle = style of manipulation used by Mouse Left+Middle buttons drag (left THEN middle)
 */
      void SetStyle( const ManipulationStyle iFirstStyle=CAT2DManipulator::Translation, 
      const ManipulationStyle iSecondStyle=CAT2DManipulator::NoManipulation);

//------------------------------------------------------------------------------
  protected:
   /** @nodoc */
     CATViz2DViewer *_2DViewer;		// Current viewer of the manipulation
   /** @nodoc */
     CAT2DViewpoint *_2DViewpoint;	// Current viewpoint of the manipulation

    // Manipulation styles
    // -------------------
   /** @nodoc */
     ManipulationStyle _PrimaryStyle;		// With Button 1
   /** @nodoc */
     ManipulationStyle _SecondaryStyle;		// With Button 1 + Button 2

    // Display Feedbacks
    //------------------
    void Feedback( const int DisplayOrHideRep);	// DisplayOrHideRep: 1=Display  0=Hide
   /** @nodoc */
     CAT2DBagRep *_FeedbackRep;
   /** @nodoc */
     CATPickPath *_RepPath;

    // Geometry
    //---------
   /** @nodoc */
     CATMathPoint2D _ContactPoint;
   /** @nodoc */
     CATTransformation2DNotification _Transformation;
    /** @nodoc */
    CATMathAxis2D _Position;
    /** @nodoc */
    CATMathAxis2D _ContactPosition;	// Position proposed
    
    // Manipulation Tools
    //-------------------
   /** @nodoc */
     MInfo MouseManipulate( CATDeviceEvent *Notification, ManipulationStyle iStyle);
   /** @nodoc */
     CATMathPoint2D GetIntersection( CATDeviceEvent *Notification);
   /** @nodoc */
     void ConnectReferencesAxis( ManipulationStyle iStyle);

    // Manipulation Reference geometry
    // -------------------------------
   /** @nodoc */
     CATMathDirection2D _Axis;		// Vector of the axis operation
    /** @nodoc */
    CATMathPoint2D _InvariantPoint;		// Invariant point for rotation and movors
    
    // Dialog datas	
    //-------------
   /** @nodoc */
     int _LastGeneralModifier, _LastMouseModifiers;	// For mouse multi-manipulations 
   /** @nodoc */
     ManipulationStyle _CurrentMouseManip;			

};

#endif
