#ifndef CATICDSBBoxSkin_H
#define CATICDSBBoxSkin_H

// COPYRIGHT DASSAULT SYSTEMES  2013

#include "CATCDS.h"

#include "CATCDSAdvancedEnums.h"
#include "CATICDSSkin.h"

class CATICDSBBoxSkinAdapter;

/**
 * @SKIP
 *
 * Black-box 3D rigid surface. It uses an input adapter object 
 * to make the binding with application implemented methods.
 */ 
class ExportedBySolverInterface CATICDSBBoxSkin : public CATICDSSkin
{
public:
  
  /**
   * Retreive pointer to adapter object.
   */
  virtual CATICDSBBoxSkinAdapter* GetAdapter() const = 0;

  /**
   * Creates an instance of the CATICDSBBoxSkin geometry.
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use.
   * @param ipAdapter
   *   Pointer to the adapter to use.
   */
  static CATICDSBBoxSkin* Create(CATICDSFactory *ipFactory,
                                 CATICDSBBoxSkinAdapter* ipAdapter);
};

#endif
