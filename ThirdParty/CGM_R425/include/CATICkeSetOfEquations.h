// COPYRIGHT Dassault Systemes 2001
#ifndef CATICkeSetOfEquations_H
#define CATICkeSetOfEquations_H


/** 
* @CAA2Level L1
* @CAA2Usage U3
*/

/*  CAA2Reviewed by FRH */

#include "KnowledgeItf.h"
#include "CATBaseUnknown.h"
#include "CATLib.h"

//Literalfeatures
#include "CATICkeParm.h"


#include "CATCkeListOfInterface.h"

extern ExportedByKnowledgeItf IID IID_CATICkeSetOfEquations ;

class CATThreads;
class CATNotification;
class CATICkeTerm;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByKnowledgeItf IID IID_CATICkeSetOfEquations;
#else
extern "C" const IID IID_CATICkeSetOfEquations;
#endif

#include "CATUnicodeString.h"


/**
* @nodoc to be exposed
* Settings concerning the calculus of Black Box parameters for the Constraint Satisfaction feature.
* Eps: The precision used to calculate the BlackBox.
* Calls: Number of calls. 
* HeuristicN:
* Heuristic1:
* 
*/
struct BlackboxParameters { 
   double Eps;
   unsigned long Calls;
   CATUnicodeString HeuristicN, Heuristic1;
   double Unimodal;
   unsigned long Attempts;
   unsigned long CacheSize;
};
  
/**
 * Interface dedicated to the management of Set of Equations relations.
 * This interface requires the Knowledge Advisor license.
 * This interface is mono implemented
 */
class ExportedByKnowledgeItf CATICkeSetOfEquations: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

   /**
    * @nodoc to be suppressed
    * The function sets the flag if the Set of Equations should be solved
    * in a separate thread or not, and also returns the previous value of the
    * flag.
    * @param iFlag = 0 if Set of Equations hasn't to be solved in a thread,
    *                1 if so,
    *                2 (by default) if you just check the value of the flag.
    * @return the previous value of the flag
    * @see System.CATThreads
    */
    virtual int HasToBeSolvedInThread( int iFlag = 2 ) = 0;

   /**
   * @nodoc to be suppressed
    * The function sets a thread where Set of Equations is solved.
    * @param ipSolvingThread a pointer to a thread
    * @see System.CATThreads
    */
    virtual HRESULT SetSolvingThread( CATThreads *ipSolvingThread ) = 0;

   /**
   * @nodoc to be suppressed
    * The function returns a thread where Set of Equations is solved.
    * @return a pointer to a thread
    * @see System.CATThreads
    */
    virtual CATThreads *GetSolvingThread() const = 0;

   /**
    * @nodoc
    * The function sets a timer id for the time of solving Set of Equations.
    * @param iTimerId a time id
    */
    virtual HRESULT SetTimerId( CATTimerId iTimerId ) = 0;

   /**
    * @nodoc
    * The function returns a timer id for the time of solving Set of Equations.
    * @return a timer id
    */
    virtual CATTimerId GetTimerId() const = 0;

   /**
    * @nodoc to be exposed
	* @param iInputParameterIndex index
    */
    virtual HRESULT SetInputParameters(int  iInputParameterIndex)= 0;

    /**
    * Specifies that the parameter must be considered as input parameter. 
    * @param iParameter The parameter to set up as input of the SetOfEquationObject
	* @return classic HRESULT
    */
    virtual HRESULT SetParameterAsInput(CATICkeParm* iParameter)= 0;

    /**
    * Specifies that the parameter must be considered as output parameter. 
    * @param iParameter The parameter to set up as input of the SetOfEquationObject
	* @return classic HRESULT
    */
    virtual HRESULT SetParameterAsOutput(CATICkeParm* iParameter)= 0;

    /**
    * Specifies that the parameter must be considered as input parameter. 
    * @param iParameter The parameter to set up as input of the SetOfEquationObject
	* @return classic HRESULT
    */
    virtual HRESULT SetParametersAsInput(CATCkeListOfParm iParameter)= 0;

    /**
    * Specifies that the parameter must be considered as output parameter. 
    * @param iParameter The parameter to set up as input of the SetOfEquationObject
	* @return classic HRESULT
    */
    virtual HRESULT SetParametersAsOutput(CATCkeListOfParm iParameter)= 0;

    /**
    * Get own notification.
	* @return notification
    */
    virtual CATNotification* GetUpdateNotification()= 0;

    /**
    * Set a calculation precision.
	* @param iEps calculation precision
	* @return classic HRESULT
    */
    virtual HRESULT SetPrecision(double iEps)= 0;

    /**
    * Get a calculation precision.
	* @return the precision
    */
    virtual double GetPrecision()= 0;

    /**
    * Get/set status of using the Gauss method for linear equations.
    * @param iSymbolic =0 - don`t use Gauss method;
    *                  =1 - use Gauss method;
    *                  =2 - get current status.
    * @return a current status
    */
    virtual int UseGaussElimination(int iSymbolic=2)= 0;

    /**
    * Get/set the flag which is indicated if the "Stop Dialog" should be created.
    * @param iUsed =0 - don`t show "Stop Dialog";
    *                  =1 - show "Stop Dialog";
    *                  =2 - get current status.
    * @return a current status
    */
    virtual int DisplayStopDialog(int iUsed=2)= 0;

    /**
    * Set a maximal duration of the current model calculations.
    * @param iMaxTime a maximal time (seconds)
	* @return classic HRESULT
    */
    virtual HRESULT SetMaxCalculationTime(unsigned long iMaxTime)= 0;

    /**
    * Get a maximal calculation time.
	* @return maximal calculation time
    */
    virtual unsigned long GetMaxCalculationTime()= 0;

    /**
    * @nodoc do not use.
    * Set blackbox parameters.
	* @param iPars blackbox parameters
	* @return classic HRESULT
    */
    virtual HRESULT SetBlackBoxParameters(BlackboxParameters &iPars)= 0;

    /**
    * @nodoc do not use.
    * Get blackbox parameters.
	* @param iPars blackbox parameters
	* @return classic HRESULT
    */
    virtual HRESULT GetBlackBoxParameters(BlackboxParameters &oPars)= 0;

   /**
    * Get the status of the set of equation.
	* @param oStatus
    * 0 = unknown.
    * 1 = solved.
    * 2 = no solution found.
    * 3 = Evaluation error.
    * 4 = Interruption.
    * 5 = all solutions found.
	* @return classic HRESULT
    */
    virtual HRESULT GetStatus(int& oStatus)= 0;

   /**
    * Set the status of the set of equation.
	* @param iStatus status 
    * 0 = unknown.
    * 1 = solved.
    * 2 = no solution found.
    * 3 = Evaluation error.
    * 4 = Interruption.
    * 5 = all solutions found.
	* @return classic HRESULT    
	*/
    virtual HRESULT SetStatus(int iStatus)= 0;

//--------------------------------------------------
// Stop Dialog
//--------------------------------------------------

    /**
    * Set current time.
    * @param iTime a current time (milliseconds)
	* @return classic HRESULT    
    */
    virtual HRESULT SetCalculationTime(unsigned long iTime)= 0;

    /**
    * Get current time (milliseconds).
	* @return current time   
    */
    virtual unsigned long GetCalculationTime()= 0;

    /**
    * Get/set a terminate flag.
    * @param iAction =0 - reset the flag;
    *                =1 - set the flag;
    *                =2 - get the flag.
	* @return the flag 
    */
    virtual int RunHasToStop(int iAction=2)= 0;

    /**
    * Set a number of shown solutions.
    * The method is used to get a count of shown solutions to "Stop Dialog"
    * @param iNSol a number of solutions. 
    *        If iNSol==-1 then the count doesn`t modified.
    * @return a current number of shown solutions.
    */
    virtual unsigned long NumberOfShownSolutions(int iNSol)= 0;

    /**
    * Control the initializing/finalizing CATIASubdefiniteCallBack.
    * @param iStep  =0 - initializing;
    *               =1 - finalizing.
    * @param iState =0 - doesn`t performs;
    *               =1 - performs;
    *               =2 - performs, but only 1 time;
    *               =3 - show current state.
    * @return a current status
    */
    virtual int ControlCallBackInitializing(int iStep, int iState)= 0;

   /**
    * Set expected time.
    * @param iTime a expected time (milliseconds)
	* @return classic HRESULT    
    */
    virtual HRESULT SetExpectedTime(unsigned long iTime)= 0;

   /**
    * Get expected time (milliseconds).
	* @return expected time
    */
    virtual unsigned long GetExpectedTime()= 0;

//--------------------------------------------------
// Smart Error localization
//--------------------------------------------------

    /**
    * Get/set status of using the Smart Error localization.
    * @param iError =0 - don`t use Smart Error localization;
    *                  =1 - use Smart Error localization;
    *                  =2 - get current status.
    * @return a current status
    */
    virtual int UseErrorDescription(int iError=2)= 0;

    /**
    * Get error description.
	* @param oDescrition error description
	* @return classic HRESULT    
    */
    virtual HRESULT GetErrorDescription(CATUnicodeString &oDescrition)= 0;

    /**
    * Get description of the constraint. Work with Smart Error localization only.
    * @param iCnt a number of the constraint.
    * @param oDescrition a view of the constraint.
    * @param oCount a number of calls of the constraint.
    * @param oErr 1 if the contradiction occured in the constraint.
	* @return classic HRESULT    
    */
    virtual HRESULT GetConstraintDescription(long iCnt, CATUnicodeString &oDescrition, unsigned &oCount, boolean &oErr)= 0;

    /**
    * Get/set status of using additional warnings.
    * @param iError =0 - don`t show additional warnings;
    *                  =1 - show additional warnings;
    *                  =2 - get current status.
    * @return a current status
    */
    virtual int UseWarningLevel(int iError=2)= 0;
    
//--------------------------------------------------
// Multiple solutions
//--------------------------------------------------
    /**
    * Get number of the found solutions.
	* @return number of solutions found  
    */
     virtual int GetNumberOfSolutions () = 0;

    /**
    * Find several next solutions.
    * @param iNsols a number of calculated solutions.
	* @return classic HRESULT    
    */
     virtual HRESULT FindNextSolutions (unsigned iNsols )  = 0;

    /**
    * Set the solution as a current one.
    * @param iIdxSol a number of the solution.
	* @return classic HRESULT    
    */
     virtual HRESULT SelectSolution (unsigned iIdxSol )  = 0;

    /**
    * Set the minimal distance between solutions.
	* @param iEps  minimal distance between solutions.
	* @return classic HRESULT    
    */
    virtual HRESULT SetSolutionsDistance(double iEps)= 0;

    /**
    * Get the minimal distance between solutions.
	* @return the minimal distance between solutions   
    */
    virtual double GetSolutionsDistance()= 0;

    /**
    * Get a maximal number of solutions those should be found during calculations.
	* @return maximal number of solutions those should be found during calculations.
    */
    virtual unsigned long GetNumberOfSolutionsToFind()= 0;

    /**
    * Set a maximal number of solutions those should be found during calculations.
    * @param inSol a number of solutions
	* @return classic HRESULT 
	*/
    virtual HRESULT SetNumberOfSolutionsToFind(unsigned long inSol)= 0;

    /**
    * Store DesingTable (results of CS) and state.
    * @param iTable a table of solutions
    * @param iState a current state of CS
	* @return classic HRESULT 
	*/
    virtual HRESULT StoreResults(CATBaseUnknown_var &iTable, int iState)= 0;

    /**
    * Restore DesingTable (results of CS) and state.
    * @param oTable a table of solutions
    * @param oState a state of CS
	* @return classic HRESULT    
	*/
    virtual HRESULT RestoreResults(CATBaseUnknown_var &oTable, int &oState)= 0;

    /**
	* @nodoc to be suppressed
    * Store the last evaluated term. 
    * This method prevent a recreation of the calculated model.
    * @param iTerm a term
	* @return classic HRESULT    
	*/
    virtual HRESULT FixRootTerm(CATICkeTerm* iTerm)= 0;

};


CATDeclareHandler( CATICkeSetOfEquations, CATBaseUnknown );

#endif
