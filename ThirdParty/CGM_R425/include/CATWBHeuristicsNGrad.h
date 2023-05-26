// COPYRIGHT DASSAULT SYSTEMES 2006
//===================================================================
//
// CATWBHeuristicsNGrad:
// into BlackBox ones.
//
//===================================================================
// Usage notes:
// This class is used for call user-defined BlackBox procedure.
//===================================================================
//   /12/06 VTN  Creation
// 25/01/23 Q48  Black-box rearchitecture to support clone
//                  - behind define WBx_BBx_Rearchitecture (inactive)
//===================================================================

#ifndef CATWBHeuristicsNGrad_H
#define CATWBHeuristicsNGrad_H

// Class header
#include "CATWBHeuristics.h"

// ExportedBy
#include "CATWhiteBoxSolver.h"

// C++11
#include "CATCDSVirtual.h"

// WBx
#include "CATWBTypes.h"
//#include "CATWBVariable.h"
class CATWBVariable;
class CATWBBlackBoxOperator;

// WBx solver
#include "CATWBManager.h"

// Temp
#include "CATWBBlackBoxOperator.h" // temporary - needed until changes in KnowEquCDSPlug\KnowEquCDSPlug.m\src\CATCkeCDSRootTerm.cpp reach BSF

/**
 * An axis description.
 * The structure is used inside MainMethod for search correct points.
 */
typedef struct {
  public:
  unsigned idx;
  unsigned block;
  unsigned weight;
  double delta1; // ai
  double delta2; // 1-k; ci=ai*(1-k)
  double delta3; // |c|^2
} myDir;

class ExportedByCATWhiteBoxSolver CATWBHeuristicsNGrad : public CATWBHeuristics
{

  public:

   /**
    * Make CATWBHeuristicsNGrad object.
    * @param ipBB is a BB computed by this heuristics
    * @param ipManager is a Solver manager
    */
#ifdef WBx_BBx_Rearchitecture
   CATWBHeuristicsNGrad(CATWBBlackBoxOperator * ipBB);
#else
   CATWBHeuristicsNGrad(CATWBBlackBox *ipBB, CATWBManager *ipManager);
#endif

   /**
    * Calculate the BlackBox interval result iArg.
    * @return 1 if the calculations finished successfully,
    *         0 otherwise
    */
    virtual int CalcIntervalResult( int iArg) CATCDSOverride;

   /**
    * Calculate the BlackBox interval result iArg.
    * @return 1 if the calculations finished successfully,
    *         0 otherwise
    */
//    virtual int CalcIntervalArgument(int iArg);

   /**
    * Get the BlackBox interval value for the argument iArg. (nArg argument is the BB Result)
    * @return oVal
    */
    void GetResult(int iArg, CATWBValue & oVal) const;

  protected:
   
   /**
    * Build the first point of computation taken from _startPoint
    */
    void BuildFirstPoint();
   /**
    * Set conditions for launch the main algorithm (initial point, bounds, etc.).
    */
    int  CheckAllStartPoints();

   /**
    * Search min or max values of the direct function.
    */
    virtual void MovePoint();

   /**
    * Check the location of the ind point.
    * @return 1 ok,
    *         0 ko,
    */
    int IsPointLower( int ind ) const;
    int IsPointUpper( int ind ) const;

   /**
    * Calculate min or max of the BB function.
    */
    int MainMethod(int iDir, unsigned isOut, double ik, double i_M, unsigned iSteps);

   /**
    * Compute the gradient of the ioVector point.
    */
    double CalcGradient( double *ioVector );

   /**
    * Use Neuton method to reach the target output value.
    * The target value is stored in iBisectTarget.
    * Bounds are set in pntBisect0,  pntBisect1.
    * @param iArg in the case 1D, the number of coordinate.
    * @param iDim =0 for 1D case; =1 for ND case.
    * @param iSteps - maximal number of the bisection steps or -1.
    * @param iBisectTarget - a goal value.
    */
    int Bisect(unsigned iArg, unsigned iDim, int iSteps, double iBisectTarget);

    int _calcArg;  // the index of argument to be calculated
                   // for CATWBHeuristicsNGrad class _calcArg==_nArgs is the BB result
    int _reached;     // 0 - LB&UB not reached; 
                      // 1 - LB reached only; 
                      // 2 - UB reached only;
                      // 3 - LB&UB both reached.

  private:

   /**
    * Build the next point according to the formulae
    * initial formula: m*x`` + rx` + f`(x) = 0
    * m - point "weight"; r - "friction coefficient"
    * x(n+1)=x(n) +iDir*f`(x(n))/(m+r) + m/(m+r) *(x(n) - x(n-1))
    * @param iDir specify the direction = 1 go to the upper bound
    *                                    -1 go to the lower bound 
    * @param oSize - a distance between the old point and the new one
    */
void   BuildNextPoint( int iDir, double &oSize);

   /**
    * Build the move steps (delta) for the argument to be computed
    * @param ioDir - the old and new steps
    * @param iLen2 - a square distance between the old point and the new one
    * @param iSz - a number of BB arguments to be computed (=="_nArgs - constant arguments") 
    */
void   BuildDelta2( myDir &ioDir, double iLen2, unsigned iSz );

int    CheckCoord( int iDir, myDir *ioDir, unsigned i1, unsigned i2, 
                                           unsigned iSz, double iLen2, int *oRes);
int    FindCorrectPoints( int iDir, int *oRes );
   /**
    * Set the next value of delta = "old/2"
    * @return 0, if the new value is too small (< -eps)
    *         1, otherwise
    */
int    SetNextDelta();

   /**
    * Check if the bound is reached
    * @param iDir - flag specifying the direction = 1 verify the upper bound
    *                                              -1 verify the lower bound 
    * @param isOut - flag specifying the actual position = 1 out of bounds
    *                                                      0 inside the bounds
    * @param iRes - the result of BB call = 1, if the call is OK
    *                                       0, otherwise
    * @return 0, if we are inside the bounds
    *         1, otherwise
    */
int    CheckJumpedBounds( int iDir, unsigned isOut, int iRes);

   /**
    * Choose the best good point among the old and new ones
    * @param iDir - flag specifying the move direction = 1 to the upper bound
    *                                                   -1 to the lower bound 
    * @return the best value (== new, old, CATCDSMaxReal, or -CATCDSMaxReal)
    */
double IsBetter(int iDir);

int    CheckBetter( int iDir, double iStep, double *oVecSize, double i_M, unsigned iNSteps);

   /**
    * Build the middle point 
    * oCur = iLow + ik*(iUpp-iLow).
    */
  int BuildMiddlePoint  (double *iLow, double *iUpp, double *oCur, double ik);
   /**
    * Build the middle point in one dimension case 
    */
  int BuildMiddle1DPoint(double  iLow, double  iUpp, double &oCur, double ik);
  
   /**
    * Check if the last step crossed the target value.
    */
  int CrossBound(double iVal1, double iVal2, double iBisectTarget) const;
//----------------------------------------------------------------------------------------------
  
   /**
    * Search min or max values of the inverse function.
    * _calcArg the index of the computed argument
    */
    void MovePointInverse();
    
   /**
    * Check if we can move into the iDir direction
    * @param iDir == -1 specify the direction to the lower bound
    *                 1 specify the direction to the upper bound
    * @return 1 or 0
    */
    int CanMove(int iDir);
   /**
    * Search min (iDirArg==-1) or max ((iDirArg==1)) values of the inverse function.
    * _calcArg the index of the computed argument
    */
    int Move1PointArg(int iDirArg);

   /**
    * Intersect line <iPt0, iPt1> with the bound(s).
    * @param iPt0 an index of the 1st point of the line
    * @param iPt1 an index of the 2nd point of the line
    * @param iPtRes an index of the resulted point
    */
    int  IntersectLineWithBounds(int iPt0, int iPt1, int iPtRes);
   /**
    * Check if the bound point (iPnt) is upper or lower of consistent area.
    * @param iPnt is a checking point index
    * @param ioBoundSign is a result flag:
    *        1 - lower
    *        2 - upper
    *        3 - inside area
    */
    void CheckBoundPoint( int &ioBoundSign, int iPnt );
   /**
    * Check BestPoints.
    * @return 1 if the bound was reached,
    *         0 otherwise
    */
    int  CheckBestPoint( int iDirArg );

   /**
    * Compute the first BB derivative on ipVariable in iX, iofX point
    * @return the value of derivative
    */
double EvalFirstDeriv(CATWBVariable * ipVariable, double iX, double &iofX);

//----------------------------------------------------------------------------------------------

    unsigned _NrndSteps;        // a number of random steps
    unsigned _ReduceStep;       // if _ReduceStep==0 then the step reduced in all cases
    unsigned _NSteps, _NStepsPrev; // a number of successful steps during the forward search

    // coefficients
    double _MR_1;        // "area" of points = "significance" of the koordinate weight
    double _M;           // new "area" of points = "significance" of the koordinate weight
};

#endif  // ifndef CATWBHeuristicsNGrad_H

