#ifndef CATViewpointIndicator_h
#define CATViewpointIndicator_h
//
// CATIA Version 5 Release 1 Framework Visualization
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract :   Object necessary to use viewpoint editor as an indicator.
//------------------------------------------------------------------------------
// Usage :      To have viewpoint manipulation with the left mouse button
//		instead of middle mouse button, create a CATViewpointIndicator
//		and set it foreground in the viewer.
//------------------------------------------------------------------------------
// Class :    CATViewpointIndicator 
//	       CATIndicator 
//		CATManipulator
//                 CATCommand
//------------------------------------------------------------------------------

#include "CATIndicator.h"
#include "CATVisFoundation.h"

class CATViewpointEditor;

class ExportedByCATVisFoundation CATViewpointIndicator : public CATIndicator
{
//------------------------------------------------------------------------------
  public :
    CATViewpointIndicator( CATCommand *Father, const CATString &iName, 
	  CATViewpoint &viewpoint, CATViewpointEditor &ViewpointEditor);
    virtual ~CATViewpointIndicator();

    virtual MInfo Activate        (CATNotification *, CATManipulator *);
    virtual MInfo EndActivate     (CATNotification *, CATManipulator *);
    virtual MInfo Preactivate     (CATNotification *, CATManipulator *);
    virtual MInfo EndPreactivate  (CATNotification *, CATManipulator *);
    virtual MInfo BeginManipulate (CATNotification *, CATManipulator *);
    virtual MInfo Manipulate      (CATNotification *, CATManipulator *);
    virtual MInfo EndManipulate   (CATNotification *, CATManipulator *);

//------------------------------------------------------------------------------
  protected :
    CATViewpointEditor &_ViewpointEditor;
	
};


#endif

