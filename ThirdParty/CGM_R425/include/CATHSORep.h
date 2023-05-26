// COPYRIGHT DASSAULT SYSTEMES	<1999>
//=============================================================================
//
// Function CATHSORep :
// This Function return the representations of a specific selection.
//
//=============================================================================
// Usage Notes:
//
//  IHSO       : the HSO to use.
//
//=============================================================================
#include "SceneGraphManager.h"

class CATHSO;

ExportedBySceneGraphManager list<CATRep> * CATHSO3DRep(CATHSO &IHSO);

ExportedBySceneGraphManager list<CATRep> * CATHSO2DRep(CATHSO &IHSO);
