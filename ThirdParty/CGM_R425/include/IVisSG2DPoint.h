#ifndef IVISSG2DPOINT_H
#define IVISSG2DPOINT_H

// COPYRIGHT DASSAULT SYSTEMES 2009

#include "IVisSG2DPrimitive.h"
#include "VisSceneGraph.h"

#include "CATSymbolType.h"

extern ExportedByVisSceneGraph IID IID_IVisSG2DPoint;

/** 
 * Basic class of any Scene Graph 2D Point.
 * <b>Role</b>: This is the basic class that any Scene Graph 2D Point has to C++ derive from.
 */
class ExportedByVisSceneGraph IVisSG2DPoint : public IVisSG2DPrimitive
{  
public:

  /**
   * Defines the symbol used to represent the 2D Point.
   * @param iSymbol
   *   The symbol used to represent the 2D Point.
   * @return
   *   <dl>
   *   <dt><tt>S_OK</tt>          <dd>If the call succeedeed
   *   <dt>Other                  <dd>If the call failed
   *   </dl>
   */
  virtual HRESULT SetSymbol(CATSymbolType iSymbol) = 0;

  /**
   * Retrieves the symbol used to represent the 2D Point.
   * @param oSymbol
   *   The symbol used to represent the 2D Point.
   * @return
   *   <dl>
   *   <dt><tt>S_OK</tt>          <dd>If the call succeedeed
   *   <dt>Other                  <dd>If the call failed
   *   </dl>
   */
  virtual HRESULT GetSymbol(CATSymbolType& oSymbol) = 0;
};

#endif // IVISSG2DPOINT_H
