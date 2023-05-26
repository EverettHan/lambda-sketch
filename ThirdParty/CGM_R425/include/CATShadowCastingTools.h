#ifndef CATShadowCastingTools_H
#define CATShadowCastingTools_H

// COPYRIGHT DASSAULT SYSTEMES 2001

#include "CATVisFoundation.h"
#include "CATShadowEnum.h"
#include "CATProjectionType.h"

class CAT3DViewpoint;
class CAT3DBagRep;
class CATMathPointf;
class CAT3DLightSourceRep;

// Shadow Mapping ///////////////////////////////////////
ExportedByCATVisFoundation void   DestroyBox              (CAT3DBagRep **opBoxBag, CAT3DBagRep* i_pOtherBag);
ExportedByCATVisFoundation void   CreateBox               (CATMathPointf *ipBoxPoints, CAT3DBagRep **opBoxBag, int icolor, CAT3DBagRep* i_pOtherBag);
ExportedByCATVisFoundation float  GiveAutoShadowLightNear (CAT3DViewpoint *i_pViewpoint, CAT3DLightSourceRep *i_plightSourceRep);

#endif

