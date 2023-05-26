#ifndef CATModifyClippingPlanes_h
#define CATModifyClippingPlanes_h

// Copyright Dassault Systemes 2006

#include "SceneGraphManager.h"
#include "CATModify.h"
#include "VisClipPlaneDesc.h"

class CATModelNotification;
class CATVisClippingFilter;
class ExportedBySceneGraphManager CATModifyClippingPlanes : public CATModify
{
    CATDeclareClass;

public:
    CATModifyClippingPlanes(
        CATBaseUnknown* iObject,
        const int iNbPlane = 0,   
		const float * iPoint = NULL, 
        const float * iNormal = NULL, 
 		const int * iCappingPlaneSeen = NULL,
		unsigned int defaultFlags = VisClipPlaneDesc::fDefaultOnFlags);

    virtual ~CATModifyClippingPlanes();

    virtual CATModelNotification* Clone ();  
    
    CATVisClippingFilter* CreateVisFilter();

private:
    int          _nbPlanes;
    float*       _points;
    float*       _normals;
    int*         _capping;
	int			 _defFlags;
};

#endif
