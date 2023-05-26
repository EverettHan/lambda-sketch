//===================================================================
// COPYRIGHT dassault systems 2018/09/26
//===================================================================
// CATIUserSelectionFilterStatus.cpp
// Header definition of class CATIUserSelectionFilterStatus
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2018/09/26 Creation: Code generated by the 3DS wizard
//===================================================================
#ifndef CATIUserSelectionFilterStatus_H
#define CATIUserSelectionFilterStatus_H

#include "SceneGraphManager.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedBySceneGraphManager IID IID_CATIUserSelectionFilterStatus;
#else
extern "C" const IID IID_CATIUserSelectionFilterStatus;
#endif


class ExportedBySceneGraphManager CATIUserSelectionFilterStatus: public CATBaseUnknown
{
CATDeclareInterface;

public:

  virtual int GetUserSelectionFilterStatus() = 0; //returns 1 for ON and 0 for OFF

};

//-----------------------------------------------------------------------

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler(CATIUserSelectionFilterStatus, CATBaseUnknown);

#endif
