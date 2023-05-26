/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 1999
//
//==============================================================================
// Inheritance
// -----------
// CATNeonMap
//    CATGraphicMaterial
//
//==============================================================================
// Abstract
// --------
// class used for environment mapping
//
//==============================================================================
// Usage
// -----
// 
//==============================================================================
// History
// -------
//     - Jun 7, 1999: Created.
//==============================================================================
#ifndef CATNeonMap_H
#define CATNeonMap_H

class CATTexturePixelImage;

#include "CATGraphicMaterial.h"

#include "CATMathDirectionf.h"

#include "CATVisFoundation.h"
class ExportedByCATVisFoundation CATNeonMap : public CATGraphicMaterial
{
public:
  // macros
  CATDeclareClass;

  // 'tors
  CATNeonMap();
  virtual ~CATNeonMap();

  const CATMathDirectionf & GetDirection() const;

protected:
  CATMathDirectionf _LightSourceDirection;
};

#endif // CATNeonMap_H
