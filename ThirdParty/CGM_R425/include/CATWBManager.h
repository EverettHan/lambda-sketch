// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATWBManager.h
// Header definition of CATWBManager
//
//===================================================================
//
// Usage notes: A class for White Boxes equations support in CDS.
//
//===================================================================
//
//  Jun 2006  Creation                     Sergey Lipski, LEDAS Ltd.
//  Mar 2012  Introduction of the varsioning mecanism                  E.-M. Duclairoir (KJD)
//  03/05/2018 PKC Replace remaining CATBoolean by CATCDSBoolean in
//                 order to remove System prereq
//  01/06/2022 Q48 Migrate to use WBx debug trace
//===================================================================

#ifndef CATWBManager_h
#define CATWBManager_h

#include "CATWhiteBoxSolver.h"
#include "CATWBTypes.h"
//#include "CATBoolean.h"
#include "CATCDSBoolean.h"
//#include "IUnknown.h"

class CATWBFactory;
class CATWBExpression;

class CATWBEquation;
class CATCDSWhiteBoxSolver;
class CATWBValue;
class CATWBVariable;
class CATCDSWBSystemOfEquations;
class CATWBEquation;  
//class CATWBBlackBoxIntervalEval;

// Debug
//class CATWBDebug;
#include "CATWBDebug.h" // forward declaration not sufficient
class CATCDSString;

enum CATCDSSolverState 
{
  catInternalError = 0,        // internal error (BB, unsupported features,...)
  catOK            = 1,        // solving OK, solution(s) found
  catContradiction = 2,        // NO solution
  catNoBlackBoxDetected  = 3,  
  catInterrupted         = 4,  // comp. interrupted by the user
  catNoOtherSolutions    = 5,  
  catUndefined           = 6,  // non defined state=> check the solver
};

struct CATWBOptions 
{
  double            _Precision;          // comp. precision
  double            _Distance;           // distance between two sols
  int               _NbOfAskedSolutions;
  int               _nCalc;   // 0 - from the beginning // all constants
                              // 1 - from the beginning (interval computations only) // all outputs
                              // 2 - from the beginning (use the previous intervals && exact solutions) // inputs <-> outputs
                              // 3 - continue computations with the previous _Stack.
  CATCDSBoolean     _IntervalResultFlag; // TRUE - need interval result
  int               _NbOfBlackBoxes;     // Number of Black Boxes in the system of equations:
  // (they are the last equations in the system)
  int               _StopCallBack;       // = 1, if a CallBack BB equation was created
  //   0, otherwise
};

//for the future : allow to change the solving method
enum CATWBMethod
{   
   HC3,            //Hull Consistency
   CID,            //Constructive Interval Disjonction
   SimplexMethod,  //Simplex Method
   IntervalNewton, //interval Newton Method
   Krawczyk,       //interval krawczyk Method
};
//end kwm
//-----------------------------------------------------------------------

class ExportedByCATWhiteBoxSolver CATWBManager
{
public:
   CATWBManager(unsigned int iCDSLevel); // iCDSLevel = versioning level 

   // deprecated default constructor
   //   Q48 06/06/22: still called from KnowEquCDSPlug/KnowEquCDSPlug.m/src/CATCDSEquationParseContext.cpp
   CATWBManager();

   virtual ~CATWBManager();

   //
   // Declaration of inputs
  //

  /**
  * Return the associated factory.
  * The factory will be automatically deleted with the manager instance.
  */
  CATWBFactory * GetFactory();

  //
  // Retrieving inputs
  //
  /**
  * Get the number of equations (number of calls to AddEquation - includes inequations also)
  */
  int GetNumberOfEquations ();


  /**
  * Get the i-th equation (starting at 0)
  */
  CATWBEquation * GetEquation (int iIdx);


  //
  // Setting the options
  //
  //Allow to change solving method
  void          SetMethod(CATWBMethod iMethod);

  CATWBMethod*  GetMethod();
  
  //
  // Solving the system
  //
  int Solve(unsigned int iCDSLevel);
  int Solve();

  /**
  * Getting the number of founded results
  */
  int GetNbOfResults() const;

  /**
  * Set the Factory's variables with values taken from the Manager // not implementd
  */
  CATCDSBoolean SetVariablesWithResult(int iWantedResult);

 /**
  * Getting the step of the solving
  */
  int GetnCalc() const;
  //=======================================================================//
  /**
  * Get the variable's index into the Factory
  * @param ipVar - pointer to the variable
  * @return the variable's index (from 0 to _pFactory->_n)
  */
  int               GetVarIndex(const CATWBVariable *ipVar) const;

  /**
  * Get the variable's exact solution value into the solution number iSolNb
  * @param iSolNb - index of the awaited solution
  * @param ipVar - pointer to the variable
  * @param oValue - solution value
  * @return TRUE, if OK
  *         FALSE, otherwise
  */
  CATCDSBoolean     GetSolutionValue(int iSolNb, const CATWBVariable *ipVar, CATWBValue &oValue) const;

  /**
  * Get the variable's interval result value into the _IntervalResult
  * @param ipVar - pointer to the variable
  * @param oValue - interval result value
  * @return TRUE, if OK
  *         FALSE, otherwise
  */
  CATCDSBoolean     GetIntervalValue(const CATWBVariable *ipVar, CATWBValue &oValue) const;

  /**
  * Set the Factory's variables with the exact solution values taken from the Manager
  * @param iResult index of the exact solution in Manager
  * @return TRUE if OK
  *         FALSE otherwise
  */
  CATCDSBoolean     SetVarWithExactSolution(int iResult) const;

  /**
  * Set the Factory's variables with the interval result values taken from the Manager
  * @return TRUE if OK
  *         FALSE otherwise
  */
  CATCDSBoolean     SetVarWithIntervalResult() const;

  /**
  * Set the number of asked exact solutions 
  */
  void              SetNbOfAskedSolutions (const int iN);
  /**
  * Set the computation precision
  */
  void              SetPrecision (const double iEps);
  /**
  * Set the minimal distance between 2 exact solutions 
  */
  void              SetDistance (const double iD);
  /**
  * Set the value of _nCalc flag (= iN)
  * @param iN = 0, do the exact values verification
  *             1, do the interval computations only
  *             2, do the normal computations (interval a "_NbOfAskedSolutions" exact solutions found) 
  *             3, do the further computations into the dichotomy tree in order to find next "_NbOfAskedSolutions" exact solutions
  */
  void              SetnCalc (const int iN);

  /**
  * Set the interval result flag value
  * @param iFlag = TRUE, we need to store the interval result
  *              = FALSE, otherxise
  */
  void              SetIntervalResultFlag(const CATCDSBoolean iFlag);

  /**
  * Set the number of BlackBox equations in the Factory (= iN)
  * @param iN = the number of BB equations in the Factory
  */
  void              SetNbOfBlackBoxes (const int iN);

  /**
  * Get the computation precision
  */
  double            GetPrecision ();
  /**
  * Get the value of distance option 
  */
  double            GetDistance ();

  /**
  * Get the number of found exact solutions 
  */
  int               GetNbOfExactSolutions () const;
  /**
  * Get the state of the solver  
  */
  CATCDSSolverState GetSolverState        () const;
  /**
  * Get the interval result flag value
  */
  CATCDSBoolean     GetIntervalResultFlag () const;
  /**
  * Get the number of asked exact solutions 
  */
  CATCDSBoolean     GetNbOfAskedSolutions () const;

  /**
  * Get the number of equation where the contradiction has occurred 
  */
  int               GetErrorLine();

  /**
  * Copy the interval result from the solver to the manager's _IntervalResult
  */
  void              SaveIntervalResult(int iN);
  /**
  * Take the last found exact solutions from the solver and add them at the end of the manager's _ExactSolutions
  */
  void              SaveExactSolutions();

  /**
  * Set all variables into the Factory with the corresponding "Any" value
  */
  void              SetVarWithAny();

  /**
  * If the variable doesn't have a prefered value we assign it to the variable's current real value
  * @param iN = number of variables
  */
  void              SavePreferedValues(int iN);

  /**
  * Copy Variables values from the Factory to _PrevVarValues (previous variables values) vector
  * @param iN = number of variables
  */
  void              CopyToPrevVarValues(int iN);

  /**
  * Copy Variables values from iFrom to oTo vectors
  * @param iFrom = the values to copy
  * @param oTo = the new values 
  * @param iN = number of variables
  */
  void              CopyValues(CATWBValue *iFrom, CATWBValue *oTo, int iN);

  /**
  * Check if Variables values had not changed after the previous computation (the model is the same)
  * @param iN = number of variables
  * @return TRUE if the model is the same
  *         FALSE otherwise
  */
  CATCDSBoolean     CheckSameModel(int iN);

  /**
  * Set STOP callback flag = 1 if the callback BB was created
  * Callback BB functions can be used for stop/suspend calculations.
  * @param iN = 1
  */
  void              SetStopCallBackFlag (const int iN);
  /**
  * Get the STOP callback flag
  * @return _opt.StopCallBack
  */
  int               GetStopCallBackFlag ();
  /**
  * Check if the STOP callback BB was created or not
  * @return TRUE if OK
  *         FALSE otherwise
  */
  CATCDSBoolean     CheckStopCallBackBB();

  /*
  * Enables to launch the symbolic transformations without the CATWBCalcGauss option
  */
  void              UnplugGaussSimplif(); // 

private:
  void              InitManager(unsigned int iCDSLevel); 

protected:

   unsigned int            _CDSLevel;
   CATWBFactory          * _pFactory;
   CATCDSWhiteBoxSolver  *_pSolver;
   CATWBOptions           _opt;
   CATWBValue            *_IntervalResult;
   CATWBValue            *_PrevIntervalResult; // Interval Values of the previous model
   int                   _PrevIntervalSize;    // the size of the IntervalResult at the previous step
                                               // it can change if the constant BB are generated
   CATWBValue            *_PrevVarValues;      // Values of Variables for the previous model 
                                               // (we store them when (_nCalc==1 && _SecondNCalc1))
   int                    _SecondNCalc1;       // == 1 when _opt._nCalc == 1 for the second time
                                               // == 0 otherwise
   int                    _NbOfExactSolutions; // Nb of found solutions
   CATWBValue            *_Solutions;
   CATCDSSolverState      _SolverState;        // see above
   int                    _errorLine;          // the index of error expression
   CATCDSBoolean          _IsPreferedSolution; // TRUE - if the prefered values is a solution (found at the _nCalc=0 step)                                        
   CATWBMethod            _Method;             // Allow to change solving method
   unsigned int           _IsSymbolicDone;     // TRUE, if the symbolic transformations were done
   CATCDSBoolean          _WithGaussSimplif;
   //int                    _DebugLevel;

   // Debug
   // -----

protected:

   WBX_DEBUG_DECLARE;

#ifdef WBX_DEBUG_TRACE
   void PrintSolverOptions() const;
   
public:

   static void PrintVariableValues(const CATWBFactory * iFactory,
                                   const CATCDSString & iHeader);
   
   static void PrintEquations(const CATWBFactory * iFactory,
                              const CATCDSString & iHeader);
#endif // WBX_DEBUG_TRACE
};

//-----------------------------------------------------------------------

#endif
