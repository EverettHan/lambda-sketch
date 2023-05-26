//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2018, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyHealingWithOverlayStatus.h
//
//===================================================================
// 09/07/18 F1Z : Creation
//===================================================================
#pragma once

enum CATPolyBodyHealingWithOverlayStatus
{
  eOtherIssue = 0x0001, // Other unreference issue
  eConformalIssue = 0x0002, // Conformisation issue
  eOrientationIssue = 0x0004, // Orientation issue
  eFillHoleIssue = 0x0008, // Fill hole issue
  eIsOpen = 0x0010, // The poly body is open
  eNonManifoldBars = 0x0012, // The poly body contains non manifold bars
  eMoreThanOneElements = 0x0018  // The poly body contains more than one connexe element
  // Add here other status to be used in overlay operators
};

namespace Poly
{
  namespace HWO
  {
    using Status = CATPolyBodyHealingWithOverlayStatus;
  };
};



