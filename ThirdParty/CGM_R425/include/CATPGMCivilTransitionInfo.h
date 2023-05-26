#ifndef CATPGMCivilTransitionInfo_h_
#define CATPGMCivilTransitionInfo_h_

// COPYRIGHT DASSAULT SYSTEMES 2018

// Base class
#include "CATCGMVirtual.h"

// ExportedBy
#include "CATGMModelInterfaces.h"

// GMModelInterfaces
#include "CATCivilCurveDef.h"

class CATCivilCurveParam;

// ============================================================================================================================= //
//                                                    CATPGMCivilTransitionInfo                                                     //
// ============================================================================================================================= //
class ExportedByCATGMModelInterfaces CATPGMCivilTransitionInfo: public CATCGMVirtual
{
public:
  /**
   * Constructor
   */
  CATPGMCivilTransitionInfo();

  /**
   * Destructor
   */
  virtual ~CATPGMCivilTransitionInfo();

  //-----------------------------------------------------------------------------
  // Get
  //-----------------------------------------------------------------------------

  virtual CATCivilTransitionType GetTransitionType() const = 0;
};

// --------------------------------------------------------------------------------------
// Line - Line
// --------------------------------------------------------------------------------------
ExportedByCATGMModelInterfaces CATPGMCivilTransitionInfo* CATPGMCreateCATCivilTransitionInfo(const CATCivilTransitionType     iTransitionType,
                                                                                             const CATCivilTransitionInfoType iTransitionTypeInfo,
                                                                                             const double                     iVal);

// --------------------------------------------------------------------------------------
// Line-Circle-Line (deprecated - please use CATCivilCurveParam signature)
// --------------------------------------------------------------------------------------
ExportedByCATGMModelInterfaces CATPGMCivilTransitionInfo* CATPGMCreateCATCivilTransitionInfo(const CATCivilTransitionType iTransitionType,
                                                                                             const double                 iL1,
                                                                                             const double                 iL2,
                                                                                             const double                 iR);

// --------------------------------------------------------------------------------------
// Line-Circle-Line
// --------------------------------------------------------------------------------------
ExportedByCATGMModelInterfaces CATPGMCivilTransitionInfo* CATPGMCreateCATCivilTransitionInfo(const CATCivilTransitionType   iTransitionType,
                                                                                             const CATCivilCurveParam     & iL1,
                                                                                             const CATCivilCurveParam     & iL2,
                                                                                             const CATCivilCurveParam     & iR);

#endif /* CATPGMCivilTransitionInfo_h_ */
