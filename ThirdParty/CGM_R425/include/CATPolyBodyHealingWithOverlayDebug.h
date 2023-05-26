//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2021, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyHealingWithOverlayDebug.h
//
//===================================================================
// Nov 2021 : F1Z : Creation
//===================================================================

#pragma once

#include "PolyBodyBoolean.h"
#include "CATPolyBody.h"
#include "CATPolyBodyOverlayDebug.h"

class CATPolyBodyOverlay;

namespace Poly
{
  namespace HWO
  {
    class IPatchInfo;

    namespace Debug
    {
      ExportedByPolyBodyBoolean HRESULT BuildTolerantPatch(const CATPolyBody & iPolyBody,
                                                           const Poly::HWO::IPatchInfo & iPI,
                                                           CATPolyBody *& oPolyBody,
                                                           CATPolyFace ** oFreeTriangleFace=nullptr);
    }
  };
};


