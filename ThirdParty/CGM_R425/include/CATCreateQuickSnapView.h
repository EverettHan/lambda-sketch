// COPYRIGHT DASSAULT SYSTEMES 2007

#ifndef CATCreateQuickSnapView_H
#define CATCreateQuickSnapView_H

#include "CATVisCommands.h"

#include "IUnknown.h"

class CATMathAxis;
class CATMathPoint;

/*
 * Launch the View Aligment command.
 * This modifies the main 3D viewpoint of the current viewer 
 * so that the most seen plane of ipAxis is aligned parallel to the screen. 
 * The plane orientation is changed to the nearest vertical or horizontal orientation.
 * 
 * If ipAxis is null, the command uses CATMathOIJK.
 * The inputs are duplicated in the method, it is not necessary to do an addref.
 */

ExportedByCATVisCommands HRESULT CreateQuickSnapViewCmd(const CATMathAxis  * ipAxis = 0,
  const CATMathPoint * ipTarget = 0); // NULL is not a defined symbol here on Unix

#endif
