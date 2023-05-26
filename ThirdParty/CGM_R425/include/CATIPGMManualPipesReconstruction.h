#ifndef CATIPGMManualPipesReconstruction_h_
#define CATIPGMManualPipesReconstruction_h_

// COPYRIGHT DASSAULT SYSTEMES 2023
#ifndef _AIX_SOURCE

#include "CATGMOperatorsInterfaces.h"
#include "CATIPGMTopOperator.h"

#include "CATGeoFactory.h"
#include "CATTopData.h" 
#include <vector> 
#include "CATMathPoint.h"

extern ExportedByCATGMOperatorsInterfaces IID IID_CATIPGMManualPipesReconstruction;

//constructeur
class ExportedByCATGMOperatorsInterfaces CATIPGMManualPipesReconstruction: public CATIPGMTopOperator
{
public:
  /**
   * Constructor
   */
  CATIPGMManualPipesReconstruction();

  //
  virtual void SetPolyLine(std::vector<int>& ilistOfIndices) = 0;

  //
  virtual void SetPolyLine(std::vector<CATMathPoint>& ilistOfpoints) = 0;

  //
  virtual void SetToleranceOnVertices(double iTolerance) = 0;

  //
  virtual void ImposedRadius(double iImposedRadius) = 0;

  //
  virtual void ImposedStartconstraint(
    CATMathPoint *iStartPoint = NULL,
    CATMathVector *iStartAxis = NULL) = 0;

  //
  virtual void ImposedEndconstraint(
    CATMathPoint *iEndPoint = NULL,
    CATMathVector *iEndAxis = NULL) = 0;

  //
  virtual int RunOperator() = 0;

  //
  virtual int RunOperator(int iSeed, CATBoolean iHorizontalOrVertical = FALSE) = 0;

  //
  virtual int RunOperator(
    CATMathPoint &iSeedPt,
    CATBoolean iHorizontalOrVertical = FALSE) = 0;

protected:
  /**
   * Destructor
   */
  virtual ~CATIPGMManualPipesReconstruction(); // -> delete can't be called
};

//
ExportedByCATGMOperatorsInterfaces CATIPGMManualPipesReconstruction *CATPGMCreateManualPipesReconstruction(
  CATGeoFactory *iFactory,
  CATTopData *iTopData,
  std::vector<double>& iVerticesCoords);

#endif /* CATIPGMManualPipesReconstruction_h_ */

#endif
