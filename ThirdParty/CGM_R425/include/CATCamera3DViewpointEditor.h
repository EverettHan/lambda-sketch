#ifndef CATCamera3DViewpointEditor_H
#define CATCamera3DViewpointEditor_H
//------------------------------------------------------------------------------
// Class :	CATCamera3DViewpointEditor
//		  CATBasic3DViewpointEditor
//		    CATCommand
// Creation: MMG March 2013
//------------------------------------------------------------------------------
#include "CATVisFoundation.h"
#include "CATBasic3DViewpointEditor.h"

class CAT3DViewpoint;
class CATMouseEvent;

/**
* Class defining the basic Local Transformation behavior.
*/
class ExportedByCATVisFoundation CATCamera3DViewpointEditor : public CATBasic3DViewpointEditor
{
 CATDeclareClass;

//------------------------------------------------------------------------------
  public :
    CATCamera3DViewpointEditor( const CATString &iName, CAT3DViewpoint &Viewpoint,
                               float iMinDistance, float iMaxDistance, float iStartDistance);

    virtual void MouseTranslate( CATMouseEvent &MouseEvent);
    virtual void StartAndDisplayTarget( CATMouseEvent &MouseEvent);
    virtual void DriveZoom( CATMouseEvent &MouseEvent);
    virtual void DriveRotate( CATMouseEvent &MouseEvent);

  protected :

    float _MaxAngle;
    float _StartAngle;
    float _MinAngle;
};
#endif

