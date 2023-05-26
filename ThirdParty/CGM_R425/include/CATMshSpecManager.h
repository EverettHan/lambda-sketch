#ifndef CATMshSpecManager_H
#define CATMshSpecManager_H

//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2022
//=============================================================================
//
// CATMshSpecManager.h
// Define the CATMshSpecManager object : use to handle some meshing spec.
// Only allocation for now.
//
//=============================================================================
// February  2022   Creation                         Fabien Noblet (FNT1)
//=============================================================================


#include "ExportedByCATMshMesherCore.h"
#include "CATMshBase.h"
#include "CATIMshSpec.h"


/**
 * Object that handle some operation relative to meshing spec.
 */
class ExportedByCATMshMesherCore CATMshSpecManager : public CATMshBase
{

public:

  /* Constructeur */
  CATMshSpecManager();

  /* Destructeur */
  virtual ~CATMshSpecManager();

  CATIMshSpec * CreateSpec(CATMshSpecType iType);

  int ForUpdatable(CATMshSpecType iSpecType);

};

#endif
