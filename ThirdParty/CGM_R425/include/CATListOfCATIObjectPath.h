// COPYRIGHT DASSAULT SYSTEMES 1999

#ifndef CATListOfCATIObjectPath_h
#define CATListOfCATIObjectPath_h

#include <CATLISTP_Clean.h>
#include "SceneGraphManager.h"
#define CATLISTP_Append
#define CATLISTP_InsertAt
#define CATLISTP_Locate
#define CATLISTP_RemovePosition
#include <CATLISTP_Declare.h>

#ifdef CATCOLLEC_ExportedBy
#undef CATCOLLEC_ExportedBy
#endif
#define CATCOLLEC_ExportedBy ExportedBySceneGraphManager

class CATIObjectPath;

CATLISTP_DECLARE(CATIObjectPath);

#endif
