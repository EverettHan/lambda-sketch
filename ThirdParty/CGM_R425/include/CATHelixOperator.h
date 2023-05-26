// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CATHelixOperator_H
#define CATHelixOperator_H

#include "FrFOpeCrv.h"
#include "CATSkillValue.h"
#include "CATCGMOperator.h"

#include "CATMathDef.h"
#include "CATMathAxis.h"
#include "CATCrvLimits.h"

class CATSoftwareConfiguration;
class CATGeoFactory;
class CATHelix;
class CATPCurve;
class CATLaw;


/**
 * Class defining a geometric operator that create an CATHelix.
 * A CATHelixOperator operator is created with the <tt>@href CATHelixOperator </tt> global method
 * and must be directly <tt>delete</tt>d after use.
 * It is is not streamable.
 */

class ExportedByFrFOpeCrv CATHelixOperator : public CATCGMOperator
{
public :
/**
 * Destructor.
 */ 
  ~CATHelixOperator();

/**
 * Runs <tt>this</tt> operator (<tt>ADVANCED</tt> mode).
 */
  virtual int RunOperator() =0;
  
/**
 * Returns the CATHelix
 */
  virtual CATHelix* GetResult() = 0;

  protected:
/**
 * Constructors.
 */
  CATHelixOperator(CATGeoFactory* iFactory);
  CATHelixOperator(CATHelixOperator& );
};



//-----------------------------------------------------------------------------
// Create
//-----------------------------------------------------------------------------
ExportedByFrFOpeCrv
CATHelixOperator* CATCreateHelix(CATGeoFactory      *iFactory,
                                 const CATMathAxis  &iAxis,
                                 const CATPCurve    *iProfile,
                                 CATCrvLimits       &iLimitsOfProfile,
                                 CATLaw             *iZthetaLaw,
                                 CATAngle            iStartAngle,
                                 CATLONG32                iOrientationCurve,
                                 CATLONG32                iTrigonometricOrientation,
                                 double              iTolerance,
                                 CATSoftwareConfiguration *iSoftConfig,
                                 CATSkillValue       iMode = BASIC);


#endif

