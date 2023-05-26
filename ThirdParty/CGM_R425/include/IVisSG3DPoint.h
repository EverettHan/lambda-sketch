#ifndef IVISSG3DPOINT_H
#define IVISSG3DPOINT_H

// COPYRIGHT DASSAULT SYSTEMES 2009

#include "IVisSG3DPrimitive.h"
#include "VisSceneGraph.h"

#include "CATSymbolType.h"

extern ExportedByVisSceneGraph IID IID_IVisSG3DPoint;

/** 
 * Basic class of any Scene Graph 3D Point.
 * <b>Role</b>: This is the basic class that any Scene Graph 3D Point has to C++ derive from.
 */
class ExportedByVisSceneGraph IVisSG3DPoint : public IVisSG3DPrimitive
{  
public:

  /**
   * Defines the symbol used to represent the 3D Point.
   * @param iSymbol
   *   The symbol used to represent the 3D Point.
   * @return
   *   <dl>
   *   <dt><tt>S_OK</tt>          <dd>If the call succeedeed
   *   <dt>Other                  <dd>If the call failed
   *   </dl>
   */
  virtual HRESULT SetSymbol(CATSymbolType iSymbol) = 0;

  /**
   * Retrieves the symbol used to represent the 3D Point.
   * @param oSymbol
   *   The symbol used to represent the 3D Point.
   * @return
   *   <dl>
   *   <dt><tt>S_OK</tt>          <dd>If the call succeedeed
   *   <dt>Other                  <dd>If the call failed
   *   </dl>
   */
  virtual HRESULT GetSymbol(CATSymbolType& oSymbol) = 0;
};

#endif // IVISSG3DPOINT_H
