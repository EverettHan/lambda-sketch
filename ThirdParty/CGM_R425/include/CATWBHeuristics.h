// COPYRIGHT DASSAULT SYSTEMES 2006
//===================================================================
//
// CATWBHeuristics:
// A heuristics for transformations WhiteBox calls into BlackBox ones.
//
//===================================================================
// Usage notes:
// This class is used for call user-defined BlackBox procedure.
//===================================================================
//   /12/06 VTN  Creation
// 25/01/23 Q48  Black-box rearchitecture to support clone
//                  - behind define WBx_BBx_Rearchitecture (inactive)
//===================================================================

#ifndef CATWBHeuristics_H
#define CATWBHeuristics_H

// ExportedBy
#include "CATWhiteBoxSolver.h"

// WBx
#ifndef WBx_BBx_Rearchitecture
#include "CATWBBlackBox.h"
#endif
class CATWBBlackBoxOperator;
#include "CATWBBlackBoxPoints.h"
#include "CATWBValue.h"
#include "CATWBEnvironment.h"
#include "CATWBManager.h"

// CDS
#include "CATCDSBoolean.h"

class CATWBBlackBoxOperator;
class CATWBenvironment;
/*
 * The flag of BB arguments (and result)
 */
enum argFlag  { argDef    = 0,
                argConst  = 1 
//                argSingle = 2, 
//                argForce  = 4 
              };
/**
 * Points indexes.
 * pntBase     - store the basic value;       
 * pntGradient - store the gradient value;
 * pntNew      - store the new point value;
 * pntPrev     - store the previous point value;
 * pntTmp     ;
 * pntInit     - store the init value for the bisection;
 * pntBisect0  - store the left side value for the bisection;
 * pntBisect1  - store the right side value for the bisection;
 * pntBaseInv  - store the init value for the inverse computation;
 * pntPrevInv  - store the previous value for the inverse computation;
 * pntBound0   - store the left bound value for the inverse computation;
 * pntBound1   - store the right bound value for the inverse computation;
 */
const int pntBase    =  0;       
const int pntGradient=  1;
const int pntNew     =  2;
const int pntPrev    =  3;
const int pntTmp     =  4;
const int pntInit    =  5;
const int pntBisect0 =  6;
const int pntBisect1 =  7;
const int pntBaseInv =  8;
const int pntPrevInv =  9;
const int pntBound0  = 10;
const int pntBound1  = 11;

//extern ExportedByCATWhiteBoxSolver double CATWB_Error;    // inconsistent real value used in BlackBoxes

class ExportedByCATWhiteBoxSolver CATWBHeuristics
{
public:

   /**
   * Make CATWBHeuristics object.
   * @param ipBBxOp a CATWBBlackBoxOperator object
   */
#ifdef WBx_BBx_Rearchitecture
   CATWBHeuristics(CATWBBlackBoxOperator * ipBBxOp);
#else
   CATWBHeuristics(CATWBBlackBox *ipBBx, CATWBManager *ipManager);
#endif

   /**
   * Destroy the object.
   */
   virtual ~CATWBHeuristics(); 

   /**
   * Set initial Parameters of the heuristics.
   * @param iStartPoint - a start point (exact) for BB computation.
   * @param iNbDataPoints - number of data points.
   * @param iBest - best points.
   * @param iEnv - factory's environment.
   */
   virtual void Init(      double              * iStartPoint,
                           int                   iNbDataPoints,
                           CATWBBlackBoxPoints * iBest,
                     const CATWBEnvironment    * iEnv);

   ///**
   //* Return the Solver's Manager.
   //* @return _pManager
   //* the Manager is not used for the moment
   //*/
   //CATWBManager * GetManager();

   CATCDSBoolean ContainsBBxOp(const CATWBBlackBoxOperator * iBBxOp) const;

   /**
   * Return the pointer to the Factory's Environment.
   * @return _Env
   */
   const CATWBEnvironment * GetEnvironment();

   /**
   * Calculate the BlackBox interval result.
   * @return 1 if the calculations finished successfully,
   *         0 otherwise
   */
   virtual int CalcIntervalResult( int iArgIndex) = 0;



   /**
   * Return the result of the Heuristic computation.
   * @param iArg  an index of the goal argument.
   * @param oVal  the resulting value.
   */
   void GetResult (int iArg, CATWBValue & oVal) const;

   /**
   * Return the best points of this heuristics
   */
   void GetBestPoints (CATWBBlackBoxPoints *oBestPoints) const;

   /**
   * Check if the heuristic has been interrupted.
   */
   int IsInterrupted() const; 

   /**
   * Check if the Heuristic search only the 1st solution.
   * @return 1 if the Heuristic search only the 1st solution,
   *         0 otherwise
   */
   int Is1Solution() const; 

   /**
   * Check if all bounds of the goal argument are reached.
   */
   int IsAllReached( int iArg ) const;

   /**
   * Call the BB on the given points 
   * the BB result value is assigned to the last point
   * @return 1 if the call is successful,
   *         0 otherwise
   */
   virtual int CallBB (double *ioPoint); 

   /**
   * Compute the distance between 2 given points 
   */
   double CalcDistance( int iPt0, int iPt1 ) const;

   /**
   * Get the number of BB arguments 
   * @return the number of BB arguments
   */
   int GetNbOfArguments( ) const;

   /**
   * Store Best Points into PrevBestPoints 
   */
   void StoreBestPoints ();

   /**
   * Store Initial Values of BB arguments 
   * @return 1 if the store method finished successfully,
   *         0 otherwise
   */
   int StoreInitValues();

   /**
   * Restore Initial Values of BB arguments after BB computation 
   * @return 1 if the restore method finished successfully,
   *         0 otherwise
   */
   int  RestoreInitValues();

   /**
   * Take the value from the _BBxOperator and put it in oValue 
   */
   void SetBBValue(const CATWBValue &oValue);

protected:

         double * GetPoint(int ind);
   const double * GetPoint(int ind) const;
         void     SetPoint(int ind, double * iFrom);
         void     CopyPoint(int iTo, int iFrom);
   
   /**
   * If the new point is outside the interval then assign it the nearest bound value
   */
   void     CorrectPoint(double *ioPoint);

   /**
   * Call BB on all previous best points 
   */
   void     CheckBestPoints();

   /**
   * Check if the bound value of the result is reached.
   */
   int IsResultReached() const;

   /**
   * Check if the heuristic should be terminated.
   */
   int  IsStopped () const { return _blackboxState&1; };

   void SetState (unsigned iState) { _blackboxState = iState; };

   /**
   * Check if the Lower bound value of iArg argument is reached.
   */
   int IsLowBoundReached( int iArg ) const;

   /**
   * Check if the Upper bound value of iArg argument is reached.
   */
   int IsUppBoundReached( int iArg ) const;

   /**
   * Check if the ind point is consistent.
   */
   int IsGood( int ind ) const;
   int IsGood( double * iPoint ) const;

   double                  _eps;            // BB precision
   CATWBBlackBoxOperator * _BBxOperator;    // pointer to the BB operator
//       CATWBBlackBox         * _BlackBox;
   double                * _startPoint;     // list of exact values of arguments (BB start point)
   CATWBValue            * _initValues;     // list of init values of arguments
   CATWBValue              _initResult;     // init value of BB result
   int                     _nArgs;          // Number of BB arguments

   argFlag               * _used;           // flags of input arguments:
                                            // 0 - to be computed; 1 - const;
   CATWBBlackBoxPoints   * _PrevBestPoints; // Pointer to Previous best points
   CATWBBlackBoxPoints   * _BestPoints;     // Cache for storing the BB best points
   CATWBBlackBoxPoints   * _BestLTPoints;   // Cache for storing the BB best points Less than the initial interval
   CATWBBlackBoxPoints   * _BestGTPoints;   // Cache for storing the BB best points Greater than the initial interval
   CATWBBlackBoxPoints   * _Data0;          // Auxiliary cache for storing the BB points
   int                     _blackboxState;  // 0 - OK
   // 1 - bb computations must be stopped
   // 2 - user have asked only 1 solution ("exact")
   //CATWBManager          * _pManager;
   CATCDSBoolean               _IsFilledBestPoints;
   const CATWBEnvironment       * _Env;           // the pointer to the factory's environment
};

#endif  // ifndef Heuristics_H
