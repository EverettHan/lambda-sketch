/* -*-C++-*-*/
#ifndef CATTPMSBasePattern_H
#define CATTPMSBasePattern_H

#include "GMScalarFieldsOperators.h"
#include "CATListOfDouble.h"
#include "CATTPMSType.h"
#include "DSYString.h"
#include "CATTolerance.h"
#include "CATMathPoint.h"
#include "CATMathVector.h"
#include "CATMathTransformation.h"

#include "CATCGMStreamVersion.h"
#include "CATCGMVersionDefinition.h"

//=====================================================================================
// Convenience methods used to define TPMS base pattern and different
// expressions from it.
//=====================================================================================

class ExportedByGMScalarFieldsOperators CATTPMSPattern
{
public :
  /**
  * Convenience method to define the basic pattern defining a TPMS.
  * @Param iTPMSType 
  *   input TPMS type
  * @Param oBasePatternExpr
  *   output CATUnicodeString containing the base expression for TPMS pattern
  */
  static HRESULT BasePatternExpression(const CATTPMSType iTPMSType, CATUnicodeString& oBasePatternExpr);
  
  /**
  * Convenience method to build the TPMS pattern expression using the base pattern definition.
  * @Param iTPMSType
  *   input TPMS type
  * @Param iPeriodicity
  *   input TPMS periodicity (2*PI/L, where L is the unit cell length) 
  * @Param iListOfArgs
  *   input list of values for different arguments that TPMS pattern may need
  * @Param oPatternExpr
  *   output CATUnicodeString containing the base expression for TPMS pattern
  */
  static HRESULT PatternExpressionBuilder(const CATTPMSType iTPMSType, const double iPeriodicity, CATListOfDouble& iListOfArgs, CATUnicodeString& oPatternExpr);  
  
  /**
  * Convenience method to build the offset of an input expression.
  * @Param iExpression
  *   input iExpression
  * @Param iOffset
  *   input offset distance
  * @Param iTol
  *   input CATTolerance used when computing the gradient of input expression
  * @Param oOffsetExpr
  *   output CATUnicodeString containing the offseted expression
  */
  static HRESULT OneSidedOffsetExpressionBuilder(const CATUnicodeString iExpression, const double iOffset, const CATTolerance& iTol, CATUnicodeString& oOffsetExpr);
  
  /**
  * Convenience method to build the two sided offset of an input expression.
  * @Param iExpression
  *   input iExpression
  * @Param iOffset
  *   input offset distance between two sides of final expression
  * @Param iTol
  *   input CATTolerance used when computing the gradient of input expression
  * @Param oOffsetExpr
  *   output CATUnicodeString containing the offseted expression
  */
  static HRESULT TwoSidedOffsetExpressionBuilder(const CATUnicodeString iExpression, const double iThickness, const CATTolerance& iTol, CATUnicodeString& oOffsetExpr);  
  
  /**
  * Convenience method to build an expression that can be assotiated to a CATBody (BodyPH).
  * This method will add affset to the set of faces defining the CATBody.
  * @Param iBodyId
  *   input tag used to reference a BodyPH
  * @Param iBlend
  *   input desired blending distance
  * @Param oBlendedBodyExpr
  *   output CATUnicodeString containing the CATBody expression
  */
  static HRESULT BodyExpressionBuilder(const CATUnicodeString iBodyId, const double iBlend, CATUnicodeString& oBlendedBodyExpr);
  
  /**
  * Convenience method to build an expression fusing two existing implicits functions.
  * This method is based on the clean union of 2 funntions: f1 + f2 - sqrt( f1*f1 + f2*f2).
  * @Param iExpr1
  *   input expression for function 1
  * @Param iExpr2
  *   input expression for function 2
  * @Param oCleanUnionExpr
  *   output CATUnicodeString containing the clean union expression
  */
  static HRESULT CleanUnionExpressionBuilder(const CATUnicodeString iExpr1, const CATUnicodeString iExpr2, CATUnicodeString& oCleanUnionExpr);

  /**
  * Convenience method to build the affine transformation of an input expression.
  * @Param iExpression
  *   input iExpression
  * @Param iTransformation
  *   input affine transformation to be applied
  * @Param oOffsetExpr
  *   output CATUnicodeString containing the offseted expression
  */
  static HRESULT AffineTransformationExpressionBuilder(const CATUnicodeString iExpression, const CATMathTransformation& iTransformation, CATUnicodeString& oOffsetExpr);
  
  /**
  * Convenience method to build the cylindrical transformation of an input expression.
  * @Param iExpression
  *   input iExpression
  * @Param iCylinderOrigin
  *   input CATMathPoint representing the cylindrical transformation origin
  * @Param iCylinderAxis
  *   input CATMathVector representing the cylindrical transformation axis
  * @Param iCylinderPeriodicity
  *   input periodicity value for cylindrical transformation
  * @Param oOffsetExpr
  *   output CATUnicodeString containing the offseted expression
  */
  static HRESULT CylindricalTransformationExpressionBuilder(const CATUnicodeString iExpression, const CATMathPoint& iCylinderOrigin, const CATMathVector& iCylinderAxis, const double iCylinderPeriodicity, CATUnicodeString& oOffsetExpr);


private:
  /**
  * Convenience methods to define different TPMS basic patterns
  */
  static HRESULT GyroidExpressionBuilder(const double iPeriodicity, CATUnicodeString& oCleanUnionExpr);
  static HRESULT NeoviusExpressionBuilder(const double iPeriodicity, CATUnicodeString& oCleanUnionExpr);
  static HRESULT LidinoidExpressionBuilder(const double iPeriodicity, CATUnicodeString& oCleanUnionExpr);
  static HRESULT IWPExpressionBuilder(const double iPeriodicity, CATUnicodeString& oCleanUnionExpr);
  static HRESULT FisherKochSExpressionBuilder(const double iPeriodicity, CATUnicodeString& oCleanUnionExpr);
  static HRESULT DiamondExpressionBuilder(const double iPeriodicity, CATUnicodeString& oCleanUnionExpr);

};

#endif // CATTPMSTypes_H
