#ifndef CATMathMarshBasicSolver_h
#define CATMathMarshBasicSolver_h

// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2000-2005
//
/** @level Protected
*  @usage U3 
*/

#include "MathMarsh.h"

#include "CATMathDef.h"
#include "CATLISTV_CATMathPoint.h"
#include "CATListOfInt.h"

class CATIMathMarshPPCArray;
class CATIMathMarshLXYZCArray;
class CATIMathMarshLSCArray;
class CATMathMarshFunction;
class CATMathMarshSolvingFunction;
class CATMathMarshExternFunction;
class CATSoftwareConfiguration;


/**
* <br><b>Role</b>: Basic Constraint Solver in 3D, it allows to interpolate punctual 3d constraintes
                   If you want, more functionalities see the class @href CATMathMarshSolver
* <p>
* Do not use the @href CATMathMarshBasicSolver constructor to
* do such and such but instead the function @href CATCreateMathMarshBasicSolver
*
* @example
*  // example to load pinpoint constrainte
*	 <br>CATIMathMarshPPCArray * IPPC1 = xxx;
*	 <br>CATIMathMarshPPCArray * IPPC2 = xxx;
*  <br>pObject = new CreateCATMathMarshBasicSolver
*  <br>pObject->Load(IPPC1);
*  <br>pObject->Load(IPPC2);
*  <br>pObject->SolveTI();  //Execute 
*  <br>CATMathMarshFunction * Res = pObject->GetResult();
*  <br>...
*
* @see @href CATMathMarshSolver, @href CATMathMarshFunction, @href CATIMathMarshPPCArray, @href CATIMathMarshLXYZCArray
*/


class CATMathMarshBasicSolver {
public:

 // Methodes PUBLIC

	virtual ~CATMathMarshBasicSolver() {}; 

	/** 
	*  Select an behavior.
	* <br><b>Role</b>: Allow to freeze an (historical) behavior.
	*
	* @param iLevel [in]
	*<br>   0 : Original version.
	*<br>   1 : some improvement in management of the polynomal kernel.
	*<br>   7 : allow 3901 punctal constraint for compact base with radius < 0.27
	*<br>   9 : relation between the maximum number of punctal constraints allowed and the compact base's radius
              Limitation of Bucket'size
  *<br>  12 : Modification of test value for singularity.
	*
	* @return
	*<br>   0 : if iLevel is correct
	*<br>   >0 : if iLevel is refused by this
	*/
	virtual int SetLevel(const short iLevel)=0;


  virtual int SetKernelLevel(const short iLevel)=0;
	

	/** 
	*  Set an array of PinPointConstrainte.
	* <br><b>Role</b>: Define a list of constraints.
	* <br>    this array is sharing by this object and its caller, in order than a modification
	* <br>    by the caller is known by the Solver object.
	*
	* @param IPPC [inout]
	*   The input array.
	*/
	virtual void Load(CATIMathMarshPPCArray * IPPC) = 0;

	/** 
	* Set an array of Linear XYZ Constraints.
	* <br><b>Role</b>: Define a list of constraints.
	* <br>    this array is sharing by this object and its caller, in order than a modification
	* <br>    by the caller is known by the Solver object.
	*
	* @param ILXYZC [inout]
	*   The input array.
	*/
	virtual void Load(CATIMathMarshLXYZCArray * ILXYZC) = 0;


	/** 
	* To solve the constraint.
	* <br><b>Role</b>: Execute the interpolation.
	*
	* @param ord [in]
	*   Define the behavior of the interpolation must be between 2 and 6
	* @param modif_epsilon [in]
  *   Define the confusion tolerance in the normalized Ball.
	* <p> This allow eliminate redundant constraint (compatible or not)
	*
	* @return
	*   0 : If the solve is done
	* <br>  >0: else
	*/
	virtual int SolveTI(const int ord = 4,
						          const double confusion_epsilon = 0.001) = 0;  // @NumValidated : Tolerance normalise (distance dans une Boule (O,1))

  /** 
  * <br><b>Role</b>: After a first SolveTI, you can change the constraint array and perfom an faster solve with this methode
	* @see CATIMathMarshPPCArray#SetPPCValue
  *
  * @param iComputeInfo [in]
  *<br>  TRUE : Some information (like  energy) are computed
	*<br>  FALSE: Only the function result is computed.
  *
  * @return
	*   0 : If the solve is done
	* <br>  >0: else
  */
  virtual int SolveTIAgain(const CATBoolean iComputeInfo = FALSE) = 0;

 /** 
  * The solution is it done ? .
  *
  * <br><b>Role</b>: Say if a solution is done (and compatible with the parameters)
  *
  *
  * @return
  *   TRUE : Yes the solve is done : It'is possible to  call #GetResult
	*<br>   FALSE : No the solve isn't done. It is necessary to call #SolveTI or #SolveTIAgain
  *
  */
  virtual CATBoolean IsDone() const = 0;

  /** 
  * Complete initialization
  *
  * <br><b>Role</b>: Restore the object to it initial state.
  */
  virtual void Init() = 0;  

  /** 
	* Give the function solution.
  * <br><b>Role</b>: Give the function solution.
  *
  * @return
  *   return a pointer on the solution. 
	* <br>  Warning do not delete or modify it, you can clone this result and manage he life cycle of the cloned solution.
  *
  */
  virtual const CATMathMarshFunction  * GetResult() const = 0;

/** 
  * Count the number of punctual element in the probleme to solve.
	* <br><b>Role</b>: Get information on the algorithm 's complexity 
	* @return
	*   The number of punctual element
	*/
	virtual int NumberOfPunctualLoad() const = 0;

	
	/** 
	* Say if there are too constraints loaded.
	*
	* <br><b>Role</b>: Explain a capacity limitation.
	*
	* @return
	*   TRUE : There are too constraints. It is impossible to solve the systeme !
	*<br>  FALSE: No capacity problem.
	*
	*/
	virtual CATBoolean TooPunctualLoad() const=0;


	/** 
	* Get current energy.
	* <br><b>Role</b>: Give a numerical measure the solution 's "smoothness".
	*
	* @return
	*   return the energy value.
	*/
	virtual double GetEnergy() const = 0;
};


/** 
*  Build an CATMathMarshBasicSolver.
* <br><b>Role</b>: Create a @href CATMathMarshBasicSolver
*
* @return
*   A basic 3d solver ready to use.
*
*/
ExportedByMathMarsh CATMathMarshBasicSolver * CATCreateMathMarshBasicSolver(const CATSoftwareConfiguration* iConfig=NULL);
#endif
