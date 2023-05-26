#ifndef CATTransformation2DNotification_H
#define CATTransformation2DNotification_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

//
// CATIA Version 5 Release 1 Framework Visualization
// Copyright Dassault Systemes 1997
//------------------------------------------------------------------------------
//
// Abstract : 	Notification which contains a 2D transformation
// ---------
//
//------------------------------------------------------------------------------
//
// Usage :      this event is send by 2D manipulators and 2D indicators	
// -------	
//
//------------------------------------------------------------------------------
//
// Heritage :	CATTransformation2DNotification
//               CATIndicateEvent
//                CATNotification (SYSTEM framework)
//
//------------------------------------------------------------------------------


#include "CATVisFoundation.h"
#include "CATNotification.h"
#include "CATMathTransformation2D.h"

class CATViewerEvent;

/**
 * Class to notify the interactive 2D manipulation of visualized objects.
 * <b>Role</b>: This notification sent by a @href CAT2DManipulator
 * is used to retrieve mathematic transformation data from the mouse move.
 * It can be decoded in a callback method 
 * through the @href CATManipulator#SendCommandSpecificObject method. 
 */

class ExportedByCATVisFoundation CATTransformation2DNotification : public CATNotification
{
  CATDeclareClass;
  
  //------------------------------------------------------------------------------
public:
  
    /** @nodoc */
  CATTransformation2DNotification();
    /** @nodoc */
  CATTransformation2DNotification( const CATMathTransformation2D &Transformation, const unsigned long iTime);
    /** @nodoc */
  virtual void SetTransformation( const CATMathTransformation2D &Transformation);	
    /**
     * Returns the 2D mathematic transformation of the movement
     * This transformation reflect the mouse move since the last recieved
     * notification.
     */
  CATMathTransformation2D GetTransformation() const;
    /** @nodoc */
  CATNotification* GetBasicNotification ( void) const;
    /** @nodoc */
  void SetBasicNotification( CATNotification * Notification );
  //------------------------------------------------------------------------------
protected:
	 /** @nodoc */
  CATMathTransformation2D _Transformation;	// Instantaneous transformation of the object
   /** @nodoc */
  CATNotification* _BasicNotification;
};

#endif
