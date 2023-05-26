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
// Usage :      this event is send by 2D indicators	
// -------	
//
//------------------------------------------------------------------------------
//
// Heritage :	CATTransformationIndicate
//               CATIndicateEvent
//                CATNotification (SYSTEM framework)
//
//------------------------------------------------------------------------------


#include "CATVisFoundation.h"
#include "CATIndicateEvent.h"
#include "CATMathTransformation2D.h"

class CATViewerEvent;

/**
 * Class to notify the 2D indication.
 * <b>Role</b>: This event sent by a @href CAT2DIndicator
 * is used to retrieve mathematic transformation data from the mouse move.
 * It can be decoded in a callback method from manipulator notification
 * through the @href #GetDataNotification method. 
 */

class ExportedByCATVisFoundation CATTransformationIndicate : public CATIndicateEvent
{
  CATDeclareClass;
  
  //------------------------------------------------------------------------------
public:
  
    /** @nodoc */
  CATTransformationIndicate();
    /** @nodoc */
  CATTransformationIndicate( const CATMathTransformation2D &Transformation, const unsigned long iTime);
    /** @nodoc */
  virtual void SetTransformation( const CATMathTransformation2D &Transformation);	
    /**
     * Returns the 2D mathematic transformation of the movement
     * This transformation reflect the mouse move since the last recieved
     * notification.
     */
  const CATMathTransformation2D& GetTransformation() const;
  //------------------------------------------------------------------------------
protected:
	 /** @nodoc */
  CATMathTransformation2D _Transformation;	// Instantaneous transformation of the object
};

#endif
