#ifndef CAT2DIndicator_h
#define CAT2DIndicator_h

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
// Abstract:    Object attached to a viewpoint providing a proposition 
//		of a transformation from a normalized square to the indicated 
//              rectangle zone.
//
//------------------------------------------------------------------------------
//
// Usage:
//	In the instanciation :  
//	1/	Instanciate a indicator connected to the representation :
//		  CAT2DIndicator * _Manip = new 
//		    CAT2DIndicator( this, "MYName", MYRep);  // default style = Indication
//		    CAT2DIndicator( this, "MYName", MYRep, CAT2DManipulator::Scaling);
//
//	2/ 	Branch a callback in you father command to be informed about the manipulation
//  		  AddAnalyseNotificationCB( _Manip, CATManipulator::GetCATManipulate(), 
//		    (CATCommandMethod) &MYCommand::MYCallback, NULL);
//
//	In the callback :
//	3/      Read the indication
//         a/	  - read the RESULT of the indication
//		    CATMathTransformation2D Indication = ((CAT2DIndicator *)Command)->GetIndication();
//		or:
//                - read the event elementary TRANSFORMATION of the manipulation
//         b/       CATTransformation2DNotification *TransfoNotif =
//                     ((CATTransformation2DNotification *) Command->SendCommandSpecificObject(
//                     CATTransformation2DNotification::ClassName(), Notification));
//                  CATMathTransformation2D *Transformation = TransfoNotif->GetTransformation();
//
//	4/	Update your modelization
//          a/  CATMathPoint2D IndicationPoint = Indication * CATMathO2D;
//              CATMathPoint2D OpositePointOfTheIndicatedZone = Indication * CATMathPoint(1, 1);
//		...
//              or: 
//          b/  IndicationPoint = Transformation * LastIndicationPoint;
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
//	CATMathTransformation2D GetIndication()	: Get the position of the manipulator
//
//------------------------------------------------------------------------------
//
// Class:      CAT2DIndicator
// ------	 CATIndicator
//                 CATCommand
//------------------------------------------------------------------------------

#include "CATVisFoundation.h"

#include "CATIndicator.h"
#include "CAT2DIndication.h"
#include "CATMathTransformation2D.h"
#include "CATMathAxis2D.h"


class CATTransformationIndicate;
class CAT2DViewpoint;
class CATVizViewer;
/** Class to retrieve mouse interaction not implying graphic representations.*/

class ExportedByCATVisFoundation CAT2DIndicator : public CATIndicator
{
 CATDeclareClass;

//------------------------------------------------------------------------------
  public:
  
    // Styles
    //----------
/** @nodoc */
    enum IndicationStyle {
      NoIndication,		// Nothing to do
      Indication,		// Give the point indicated
      Scaling,			// Scaling of a rectangle // parallel to Axis
      RotationAndScaling};	// Scaling and orientation

    // Structors
    //----------
  /** Construct a CAT2DIndicator*/
    CAT2DIndicator( CATCommand *Father, const CATString &iName, CAT2DViewpoint &viewpoint,
	  const IndicationStyle iFirstStyle=CAT2DIndicator::Indication, 
	  const IndicationStyle iSecondStyle=CAT2DIndicator::Indication);

    virtual ~CAT2DIndicator();

    // Current position of the manipulator
    //------------------------------------
    
   /** @nodoc */    
    virtual CATMathTransformation2D GetIndication() const;
   /** @nodoc */    
   virtual void SetIndication( const CATMathTransformation2D &iIndication);

  /**
  * Get a desired object provided a notification.
  * @param iUuid
  *  The desired object, given by the ClassName method.
  *  the CAT2DIndicator can return :
  *    <ol>
  *    <li>CAT2DIndication  
  *    </ol>
  * @param iNotification
  *  The notification which caused the need for that object
  *  Usually, you ask a command for more information when that
  *  command calls you back. Use pass the notification you receive
  *  in your callback.
  */
   //virtual void * SendCommandSpecificObject(const char *uuid, CATNotification*notification);

/** @nodoc */
    CAT2DViewpoint & Get2DViewpoint() const;

    // Manipulation calls from viewer
    //-------------------------------
   /** @nodoc */    
   virtual MInfo BeginManipulate( CATNotification *event, CATManipulator *m);
   /** @nodoc */    
    virtual MInfo Manipulate( CATNotification *event, CATManipulator *m);


//------------------------------------------------------------------------------
  protected:
  
   /** @nodoc */    
    CATVizViewer *_Viewer;		// Current viewer of the manipulation

    // Manipulation styles
    // -------------------
   /** @nodoc */    
    IndicationStyle _PrimaryStyle;		// With Button 1
   /** @nodoc */    
    IndicationStyle _SecondaryStyle;		// With Button 1 + Button 2

    // Geometry
    //---------
   /** @nodoc */    
    CATMathPoint2D _ContactPoint;
   /** @nodoc */    
    CATTransformationIndicate *_Transformation;
   /** @nodoc */    
    CATMathTransformation2D _Position;
   /** @nodoc */    
    CATMathAxis2D _ReferenceAxis;

    // Manipulation Tools
    //-------------------
   /** @nodoc */    
    MInfo MouseManipulate( CATDeviceEvent *Notification, IndicationStyle iStyle);
   /** @nodoc */    
    CATMathPoint2D GetIntersection( CATDeviceEvent *Notification);

    // Dialog datas	
    //-------------
   /** @nodoc */    
    int _LastGeneralModifier;
   /** @nodoc */    
   int _LastMouseModifiers;	// For mouse multi-manipulations 
   /** @nodoc */    
    IndicationStyle _CurrentMouseManip;			
};


#endif

