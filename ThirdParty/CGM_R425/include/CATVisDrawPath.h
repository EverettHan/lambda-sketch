#ifndef CATVisDrawPath_H
#define CATVisDrawPath_H
// COPYRIGHT DASSAULT SYSTEMES 1999
class CAT2DRep;
class CAT3DRep;
class CATRepPath;

#include "CATVisFoundation.h"

/**
 * @CAA2Level L0
 * @CAA2Usage U0
 */

/** @nodoc*/
class ExportedByCATVisFoundation CATVisDrawPath
{
public:

  /** @nodoc*/
  static CAT3DRep* CreateDrawPathRep(CATRepPath* iPath);
  
  /** @nodoc */
  static CAT2DRep* CreateDrawPath2DRep(CATRepPath* iPath);
};

#endif 
