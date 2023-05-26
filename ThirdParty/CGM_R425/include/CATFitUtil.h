// COPYRIGHT DASSAULT SYSTEMES 2001 
//==========================================================================
//
// CATFitUtil:
//
//==========================================================================
//
// Usage notes:
//
//========================================================================== 
// Mar. 01     Creation                  Daniel Johansson
//========================================================================== 

#ifndef CATFitUtil_H
#define CATFitUtil_H

#include "CATFitUtil.h"
#include "CATKnotVector.h"
#include "CATMathMxNMatrix.h"
#include "CATMathMxNBandMatrix.h"
#include "CATFrFUtiNurbs.h"
#include "CATMetaClass.h"
#include "CATGeometry.h"
#include "CATMathDef.h"
#include "CATCrvParam.h"
#include "CATCurve.h"
#include "CATCrvEvalLocal.h"
#include "FrFFitting.h"

//-----------------------------------------------------------------------------

/**    
 * Evaluate basis polynomials into MxN banded matrices.
 * if ioBM  isn't NULL, polynomials are evaluated 
 * if ioDM  isn't NULL, first derivatives of the polynomials are evaluated. 
 * if ioD2M isn't NULL, Second derivatives of the polynomials are evaluated. 
 * iPar  is supposed to be inside knot interval and increasing.
 *       If not, the result may be useles!
 */
ExportedByFrFFitting    
void BasisValuesForAllArcsDJ(const CATKnotVector *iKV,
                             const CATLONG32    iNbPar,
                             const double *iPar,
                             CATMathMxNBandMatrix *ioBM,  
                             CATMathMxNBandMatrix *ioDM,
                             CATMathMxNBandMatrix *ioD2M ) ;

/**    
 * Evaluate basis polynomials into MxN banded matrices. Intended for 
 * successive extension.
 * ioBM must be sufficiently big and must have correct row size. 
 * iPar  is supposed to be inside knot interval and increasing.
 *       If not, the result may be useles!
 * The result will be written from the row iIndStartRow up to 
 * iIndStartRow + iNbPar-1. The column size will, at least, be
 * iIndStartRow + iNbPar.
 * if iDiff the basis will be differentiated (but only once so far)
 */
ExportedByFrFFitting    
void BasisValuesForAllArcsDJ(const CATKnotVector  *iKV,
                             const CATLONG32       iNbPar,
                             const double         *iPar,
                             CATMathMxNBandMatrix *ioBM,  
                             const CATLONG32       iIndStartRow = 0 ,
                             const CATLONG32       iDiff = 0,
                             const double          iScale = 1.0) ;
/**    
 * Create matrix to set contol points of a curve 
 */
/*NDN Coverage 030106
ExportedByFrFFitting    
    void InitCurveMatDJ (const CATLONG32 nPar, 
                         const double *par,
                         const CATKnotVector *KV,
                         const double scale,
                         CATMathMxNMatrix *MatCrv ) ;
            NDN Coverage 030106 */
/**    
 * Create banded matrix to set contol points of a curve 
 */
ExportedByFrFFitting    
void InitBandedCurveMatDJ (const CATLONG32        iNbPar, 
                           const double          *iPar,
                           const double           iLnOfDeriv,
                           const CATKnotVector   *iKv,
                           CATMathMxNBandMatrix  *&ioMatrixC,
                           CATMathMxNBandMatrix  *&ioSolve,
                           CATLONG32              &ioNbF, 
                           CATLONG32             *&ioF,
                           CATLONG32             &ioNbRW,  
                           double                *&ioRW,
                           const double           iTolPt, 
                           const double           iTolTg = 0.0 ) ;

/**    
 * Find index of interval in iParamArray containing iParam. 
 * If iParam < iParamArray[0], zero is returned. 
 * If iParam > iParamArray[iNbInterval-1], iNbInterval-1 is returned. 
 * This code is optimized supposing that last used index is close to
 * the new one. Otherwise, just use iLastIndex = iNbInterval/2. 
 */
ExportedByFrFFitting
CATLONG32 GetIntervalIndex(const double   *iParamArray, 
                                 CATLONG32 iNbInterval, 
                                 double    iParam, 
                                 CATLONG32 iLastIndex ) ;


/**    
 * Create or expand CATLONG32 arrays to size iNewSize. If old size is given, 
 * the data are copied up to this size.  
 */
ExportedByFrFFitting
void ExpandArrayDJ (CATLONG32       *&ioArray,
                    const CATLONG32 iNewSize,
                    const CATLONG32 iOldSize = 0 ) ;

ExportedByFrFFitting
void ExpandArrayDJ (      double   *&ioArray,
                    const CATLONG32  iNewSize,
                    const CATLONG32  iOldSize = 0 ) ;

ExportedByFrFFitting
void ExpandArrayDJ (      unsigned int *& ioArray,
                    const CATLONG32       iNewSize,
                    const CATLONG32       iOldSize = 0 ) ;

/**    
 * Returns how many values given by the CATKnotVector method "ParameterAssociated-
 * ToVertexRank()" that are in [iStartParam, iEndParam].  
 */
ExportedByFrFFitting
CATLONG32 StartNbVertexParamDJ (const CATKnotVector *iKV,
                                const double         iStartParam,
                                const double         iEndParam ) ;

/**    
 * Fills parameter values relative the knot vector. The values are initially 
 * set by the CATKnotVector method "ParameterAssociatedToVertexRank()", Then,
 * the size is expanded or reduced, by "linear blending of neighbours" to iSize.
 * The iSize must be larger than half of "iKV->GetNumberOfControlPoints()". 
 * If iEndParam > iStartParam a grid is created between these values, but with
 * a desity consistent with the method above.
 */
ExportedByFrFFitting
void StartParamGridDJ (const        CATKnotVector *iKV,
                       double      *iParamGrid,
                       const CATLONG32   iSize, 
                       const double iStartParam = 1.0,
                       const double iEndParam   = 0.0 ) ;

/**    
 * Fills parameter values where ioParamGrid is too sparse relative the knot vector.
 * (see the method StartParamGridDJ above)
 * The old values correspoinds to ones in oFilled while the new correspond to zeroes 
 * The useful old and new sizes are in ioNb.
 * The maximal space is incrreased in steps of 50, if needed.
 * returns one if expansion was needed, otherwise zero.
 */
ExportedByFrFFitting
CATLONG32 ExpandParamGridDJ (const CATKnotVector *  iKV,
                                   double        *& ioParamGrid,
                                   CATLONG32     *& oFilled,
                                   CATLONG32      & ioNb,
                                   CATLONG32      & ioMaxNb,
                             const double           iEpsPar);


/**    
 * Errors at each knot interval (arc) are given by non zero values in iERR. 
 * If iMaxDegree is not reached the degree of the knot vector is increased.
 * Otherwise the arc with error is split in the middle. 
 * Reduction of the number of nodes may be done if:
 *   0 < ioRemainigReductions,
 *   0 < iReduceLevel,
 *   3 < the number of knots and, finally, if the number of arcs with errors 
 *   are less than a third of the number of arcs.
 * If iReduceLevel is one, around 15 % is removed. If two around 25%.
 * The arrays ioMult and ioKnots are work areas. Their size and adresses 
 * might change.
 * returns 0 if no change of the knot vector is done.
 */
ExportedByFrFFitting
CATLONG32 MoreKnotsOrHigherDegreeDJ (const CATLONG32        iMoreKnots, 
                                           CATKnotVector *  ioKV, 
                                     const CATLONG32     *  iERR,
                                           CATLONG32      & ioRemainigReductions, 
                                     const CATLONG32        iReduceLevel,
                                     const CATLONG32        iMaxDegree,
                                     const CATLONG32        iMaxNbKnots,
                                     const double           iMinKnotDist,
                                           CATLONG32      & ioSizeKnotMult,
                                           double        *& ioKnot,
                                           CATLONG32     *& ioMult ) ;

/**    
 * Calculates the length of a short curve segment within a tolerance, iTol.
 * Curve reference of iCrvParam must be set in advance.
 * The segment is limited by [iU1, iU5]. iU3 = 0.5*(iU5+iU1).
 * iLnD1, iLnD3 and iLnD5 are the length of the derivatives in iU1,iU3 and 
 * iU5 respectively.
 * iLnC = (iU5-iU1)*(iLnD1 + 4.0*iLnD3 + iLnD5) / 6.0.
 */
ExportedByFrFFitting
double LengthRecursivDJ(CATCrvParam     *iCrvParam,
                        const CATCurve  *iCRV,
                        CATCrvEvalLocal *iEvalLoc,
                        const double     iTol,
                        const double     iU1,
                        const double     iU3,
                        const double     iU5,
                        const double     iLnC,
                        const double     iLnD1, 
                        const double     iLnD3, 
                        const double     iLnD5,
                        const CATLONG32       iMaxRecursionLevels = 5 ) ;


#endif




