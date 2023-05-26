#ifndef CAT3DIndicator_h
#define CAT3DIndicator_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


#include "CATVisFoundation.h"

#include "CATIndicator.h"

//
// CATIA Version 5 Release 1 Framework Visualization
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
//
// Abstract:   defines behavior in the back of a 3D viewpoint of a viewer
// ---------
//
//
//------------------------------------------------------------------------------
//
// Usage:      is used to give indication in a 3D viewer
// ------
//
//------------------------------------------------------------------------------
//
// Main methods:
// -------------
//
//
//------------------------------------------------------------------------------
//
// Class:      CAT3DIndicator
// ------
//
//------------------------------------------------------------------------------


class CAT3DViewpoint;

/** Class to retrieve mouse interaction not implying graphic representations.*/
class ExportedByCATVisFoundation CAT3DIndicator : public CATIndicator
{
 CATDeclareClass;

  public:
  /** Construct a CAT3DIndicator 
  * @param iFather
  * @param iName
  * @param iviewpoint  The viewpoint used to compute the CATIndicationSegment*/
  CAT3DIndicator( CATCommand *iFather, const CATString &iName, CAT3DViewpoint &iviewpoint);
  /** @nodoc */
  virtual ~CAT3DIndicator();

   /**
  * Gets a desired object provided a notification.
  *
  * @param iUuid
  *  The desired object, given by the ClassName method.
  *  the CAT3DIndicator can return :
  *    <ol>
  *    <li>CATIndicationSegment  the line segment under the mouse cursor when the event occured
  *    </ol>
  * @param iNotification
  *  The notification which caused the need for that object
  *  Usually, you ask a command for more information when that
  *  command calls you back. Use pass the notification you receive
  *  in your callback.
  */  
  //virtual void * SendCommandSpecificObject(const char *iUuid, CATNotification*iNotification);

};


#endif

