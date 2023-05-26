#ifndef CATTransformationNotification_H
#define CATTransformationNotification_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

//
// CATIA Version 5 Release 1 Framework VFW2
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract : 	notification which contains a 3D transformation matrix.
// ----------
//
//------------------------------------------------------------------------------
// Usage :      is used by 3D manipulator to send the matrix they suggest on
// -------        a 3D object. Application uses this information to move
//                the model object at its desired position.
//
//------------------------------------------------------------------------------
// Heritage :	CATTransformationNotification
//                    CATNotification (SYSTEM framework)
//------------------------------------------------------------------------------


#include "CATVisFoundation.h"
#include "CATNotification.h"
#include "CATMathTransformation.h"	
#include "CATMathLine.h"	

class CATViewerEvent;

/**
 * Class to notify the interactive manipulation of visualized objects.
 * <b>Role</b>: This notification sent by a @href CATManipulator
 * is used to retrieve mathematic transformation data from the mouse move.
 * It can be decoded in a callback method 
 * through the SendCommandSpecificObject method. 
 */

class ExportedByCATVisFoundation CATTransformationNotification : public CATNotification
{
  CATDeclareClass;

//------------------------------------------------------------------------------
  public:
  
    /** @nodoc */
    CATTransformationNotification();

	/** @nodoc */
    CATTransformationNotification( const CATMathTransformation &iTransformation, const unsigned long iTime = 0);
    
	/**
     * Returns the mathematic transformation of the movement.
     * This transformation reflect the mouse move since the last recieved
     * notification.
     */
    virtual const CATMathTransformation &GetTransformation() const;
    /**
     * Get the rotation characteristics.
     * @param oAxis 
     *   The rotation axis wich is the line defined to the manipulator
     *   by @href CAT3DManipulator#SetRotationLine (with the same orientation).
     * @param oAngle 
     *   The rotation angle since the last recieved notification.
     */
    CATBoolean IsRotation( CATMathLine &oAxis, CATAngle &oAngle) const;

    /** @nodoc */
    void SetRotation( const CATMathLine &iAxis, const CATAngle &iAngle);
    /** @nodoc */
    virtual void SetTransformation( const CATMathTransformation &iTransformation);	
    /** @nodoc */
    void SetBasicNotification ( CATNotification * );
    /** @nodoc */
    CATNotification * GetBasicNotification() const;

//------------------------------------------------------------------------------
  protected:
	  /** @nodoc */
    CATMathTransformation _Transformation;	// New position of the object
	/** @nodoc */
    CATNotification *_BasicNotification;
	/** @nodoc */
    CATMathLine _Axis;	// Rotation definition
	/** @nodoc */
    CATAngle _Angle;	// Rotation definition
};

#endif
