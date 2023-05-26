#ifndef CATVisSpace_H
#define CATVisSpace_H

#include "SGInfra.h"

#include "CATMathPoint.h"
#include "CATMathDirectionf.h"


/** @struct This structure exposes spatial requirement flags and services.
 *  Currently, it is used by scene API for lights and cameras.
 *  @see CATVisCamera, CATVisLight
 */
struct ExportedBySGInfra CATVisSpace
{
  enum FComponents
  {
    fNone = 0,
    fPosition     = (1<<0),
    fDirection    = (1<<1),
    fUpDirection  = (1<<2),
    fPosAndDir    = (fPosition | fDirection),
    fReferential  = (fPosition | fDirection | fUpDirection)
  };
  
  /** Service which makes two spatial directions orthogonal
   *  @param iKeptDir The direction which must be kept (accepted flags are only fDirection OR fUpDirection)
   *  @param ioDir The main direction (will be modified if iKeptDir is fUpDirection)
   *  @param ioUpDir The up direction (will be modified if iKeptDir is fDirection)
   */
  static void Orthogonalize(const FComponents iKeptDir, CATMathDirectionf& ioDir, CATMathDirectionf& ioUpDir);
};

#endif
