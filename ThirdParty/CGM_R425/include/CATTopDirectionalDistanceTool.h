// --------------------------------------------------------------------------------
//  COPYRIGHT DASSAULT SYSTEMES 2016
// --------------------------------------------------------------------------------
//
//  CATTopDirectionalDistanceTool :
//
//     Class defining the directional parallel computation.
//
// --------------------------------------------------------------------------------
#ifndef CATTopDirectionalDistanceTool_H
#define CATTopDirectionalDistanceTool_H

#include "ExportedByPARLight.h"

#include "CATTopDef.h"
#include "CATTopDistanceTool.h"
#include "CATMathDirection.h"

#include "CATMathInline.h"

class CATGeoFactory;
class CATTopData;
class CATLaw;
class CATBody;
class CATVertex;
class CATGeometry;
class CATDistanceTool;


/**
 * Class defining the directional parallel computation.
 * This class is used to define the parameters of a @href CATTopParallel operator.
 * @nodoc @nocgmitf (do not create any specific interface)
 */
class ExportedByPARLight CATTopDirectionalDistanceTool : public CATTopDistanceTool
{
 public:

  /**
 * Constructs the object for the euclidean computation.
 * @param iGeoFactory
 * The pointer to geometry factory.
 * @param iSoftwareConfiguration
 * The pointer to the software configuration with which the code must be run.
 * @param iDirection
 * the mathematical direction defining the projection onto a working plane on which the parallel curve will be computed
 * and then projected onto the shell along the same direction 
 * @param iOrientation
 * The side on which the parallel is computed.
 * The cross product between the shell normal and the wire tangent define the
 * left side.
 * <br><b>Legal values </b>: <tt>CATOrientationPositive</tt> for the left side,
 * <tt>CATOrientationNegative</tt> for the right side.
 * @param iDistance
 * The pointer to the law defining the parallel offset.
 */
  CATTopDirectionalDistanceTool(CATGeoFactory * iGeoFactory, CATTopData * iData, CATMathDirection &iDirection, CATOrientation iOrientation, CATLaw *iDistance);

  ~CATTopDirectionalDistanceTool();

  INLINE void GetDirection(CATMathDirection &oDirection) const;

  
  /** @nodoc nocgmitf */
  static const CATTopDirectionalDistanceTool * CastToDirectionalDistanceTool(const CATDistanceTool &iDistanceTool);


  /** @nodoc */
  virtual short GetType() const;

  /** @nodoc */
  virtual void DuplicateTool(CATTopDistanceTool * & oNewTool);


  // Methods mandatory to implement not to be abstract 
  // =================================================


  /** @nodoc - Not yet implemented -> Throw an error*/
  virtual int IsParallelImage(CATGeoFactory * iFacto, CATTopData * iData, CATGeometry * iSupport, CATGeometry * iCurveIni,CATLaw ** MapLaws, CATGeometry * iVtxImage,CATGeometry * iVtxOrig);

  /** @nodoc - Not yet implemented -> Throw an error*/
  virtual void ComputeParallelImage(CATGeoFactory * iFacto, CATTopData * iData, CATGeometry * iSupport, CATGeometry * iCurveIni,CATLaw ** MapLaws, CATGeometry *& oVtxImage,CATGeometry * iVtxOrig);

  /** @nodoc - Not yet implemented -> Throw an error*/
  virtual void ComputeParallelImageFromTangent(CATGeoFactory * iFacto, CATTopData * iData, CATGeometry * iSupport, CATGeometry * iCurveIni,CATLaw ** MapLaws, CATGeometry *& oVtxImage,CATGeometry * iVtxOrig,CATVertex * iVtxExtremity,CATMathVector & iTangent); 



private :

  CATMathDirection          _Direction;

};

// methods INLINE 
// ==============

INLINE void CATTopDirectionalDistanceTool::GetDirection(CATMathDirection &oDirection) const {
  oDirection = _Direction; }


#endif




















