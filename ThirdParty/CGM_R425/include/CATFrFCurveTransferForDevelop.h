/**
 * @quickreview

 * @fullreview 25/11/2020 SOU
 */
 //=============================================================================
 // COPYRIGHT DASSAULT SYSTEMES 2020
 //=============================================================================
 // CATFrFCurveTransferForDevelop: Header for a class that manages transformations and required information for curve transfer for unfold support surfaces 
 //           This class does not derive from CGMOperator
 // 
 //=============================================================================
 // History:
 // 
 //=============================================================================
 // Usage notes:
 //=============================================================================
 //  19/11/2020 SME31 Creation
 //  23/11/2020 SME31 Curve Transfer Refactoring to move implementation from CATTopShellUnfoldTransferImpl to FreeFormOperators CATFrFCurveTransferForDevelop
 //  23/11/2020 SME31 Support Curve Transfer for Offsets
 //=============================================================================

#ifndef CATFrFCurveTransferForDevelop_H
#define CATFrFCurveTransferForDevelop_H

#include "CATSurface.h"
#include "CATSurLimits.h"
#include "CATBoolean.h"

#include "CATGeoFactory.h"
#include "CATGeoOperator.h"

#include "FrFOpeUtil.h"
#include "CATSkillValue.h"

class ExportedByFrFOpeUtil CATFrFCurveTransferForDevelop : public CATGeoOperator
{
public:

  //
  //  +-----------------------------+
  //  | Constructor and destructor  |
  //  +-----------------------------+
  //
  CATFrFCurveTransferForDevelop(CATGeoFactory * iFactory);

  virtual ~CATFrFCurveTransferForDevelop();

  //
  //
  //  +--------------------+
  //  | Run operator     |
  //  +--------------------+
  //
  virtual int Run() = 0;

  //
  //  +--------------------------+
  //  | Get the result     |
  //  +--------------------------+
  //
  virtual void GetTransfoInformation(CATMathTransformation2D & Transfo2D) = 0;

  //-----------------------------------------------------------------------------
  virtual CATSurface * GetResult() = 0;
};

ExportedByFrFOpeUtil CATFrFCurveTransferForDevelop * CreateFrFCurveTransferForDevelop(CATGeoFactory * const ipTopOperFactory, 
                                          CATSoftwareConfiguration* ipTopOperSoftwareConfig,
                                          CATSurface * & ipSurfSupp, 
                                          CATSurface * & ipSurfIma,
                                          CATSurface * ipOldSurface,
                                          CATSurLimits & iLimits_Support, 
                                          CATSurLimits & iLimits_Image, 
                                          CATBoolean iReverseTransfer,
                                          CATSkillValue iMode = BASIC);

//-----------------------------------------------------------------------

#endif
