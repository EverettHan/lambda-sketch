#ifndef CATMathMarshSolver_h
#define CATMathMarshSolver_h

// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2000
/** @level Protected
*  @usage U3 
*/

#include "MathAdvMarsh.h"

#include "CATMathMarshBasicSolver.h"

#include "CATMathDef.h"
#include "CATLISTV_CATMathPoint.h"
#include "CATListOfInt.h"
#include "CATMathStream.h"
#include "CATMathDebugFactory.h"

class CATIMathMarshPPCArray;
class CATIMathMarshLXYZCArray;
class CATIMathMarshLSCArray;
class CATMathMarshFunction;
class CATMathMarshSolvingFunction;
class CATMathMarshExternFunction;
class CATMathMarshPUMOption;
class CATMathPlane;
class CATMathDebugFactory;
class CATSoftwareConfiguration;

/**
* The mathematical marshmallow solver.
* <br><b>Role</b>: Constraint Solver in 3D, it allows to interpolate punctual 3d constraintes
                   If you want, basical functionalities see the class @href CATMathMarshBasicSolver
* <p>
* Do not use the @href CATMathMarshSolver constructor to
*  but instead the function @href CreateCATMathMarshSolver
*
* @example
*  // example to load pinpoint constrainte
*	 <br>CATIMathMarshPPCArray * IPPC1 = xxx;
*	 <br>CATIMathMarshPPCArray * IPPC2 = xxx;
*  <br>pObject = new CreateCATMathMarshSolver();
*  <br>pObject->Load(IPPC1);
*  <br>pObject->Load(IPPC2);
*  <br>pObject->SolveTI();  //Execute 
*  <br>CATMathMarshFunction * Res = pObject->GetResult();
*  <br>...
*
* @see @href CATMathMarshBasicSolver, @href CATMathMarshFunction, @href CATIMathMarshPPCArray, @href CATIMathMarshLXYZCArray, @href CATIMathMarshLSCArray
*/

class CATMathTransformation;

//#define WithDirectMode


class CATMathMarshSolver : public CATMathMarshBasicSolver
{
public:

 // Methodes PUBLIC

	virtual ~CATMathMarshSolver() {}; 


  /** 
  * Clone this solver in another one.
  *
  * <br><b>Role</b>: ADVANCED USE for multi-threading purpose.
  *
  * @param oCopy [out]
  *   The cloned mathematical marshmallow solver.
  *
  * @return
 *   0 : Ok it is done
  *   >0 : One error occur, the replacement is not done.
  *
  */
  virtual int Clone(CATMathMarshSolver *& oCopy) const=0;

	virtual CATBoolean IsAKindOf(const char* iName) const {
		if (!strcmp(iName, "CATMathMarshSolver")) return 1;
		if (!strcmp(iName, "CATMathMarshBasicSolver")) return 1;
		return 0;
	}

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
	* Set an array of Linear scalar Constraints.
	* <br><b>Role</b>: Define a list of constraints.
	* <br>    this array is sharing by this object and its caller, in order than a modification
	* <br>    by the caller is known by the Solver object.
	*
	* @param ILSC [inout]
	*   The input array.
	*/
	virtual void Load(CATIMathMarshLSCArray * ILSC) = 0;


  /** 
  * Replace an array of PinPointConstraint array by another one.
  *
  * <br><b>Role</b>: ADVANCED USE for multi-threading purpose
  *
  * @param iOldPPC [in]
  *   The old PinPointConstraint array 
  * @param iNewPPC [in]
  *   The new PinPointConstraint array 
  *
  * @return
  *   0 : Ok it is done
  *   >0 : One error occur, the replacement is not done.
  *
  */
  virtual int ReplaceLoad(CATIMathMarshPPCArray * iOldPPC, CATIMathMarshPPCArray * iNewPPC)=0;
  /** 
  * Set a plane of symetrie.
  *
  * <br><b>Role</b>: Allow to perform an symetric deformation
  *
  * @param iSymPlane [in]
  *   The plane of symetry.
  *
  * @return
  *   0 : OK
	* <br>  >0: else (the pre func methode has no effect)
  *
  */
  virtual int LoadSymPlane(const CATMathPlane* iSymPlane)=0;

  /** 
  * Save the target constraint in this.
  *
  * <br><b>Role</b>: Allow to save the constraint, in order to modify its and restore its later.
  *  Limitation : only for PinPoint constraint (return an error else)
  *
  * @return
	*   0 : OK
  * <br> 33 : Some constraints are not treated
	* <br>  >0: else (the Save Target has no effect)
  */
  virtual int SaveTarget()=0;

  /** 
  * Force all the constraints to be the Identity.
  *
  * @return
	*   0 : OK
  * <br> 33 : Some constraints are not treated
	* <br>  >0: else (the Save Target has no effect)
  *
  */
  virtual int RazTarget()=0;

  virtual int RestoreTarget()=0;


  virtual void SetMute(CATBoolean isMute)=0;

  virtual int SetScaleMaxDim(const double iScale)=0;
  
	/** 
	* Set a multiquadric coefficient.
	*
	* <br><b>Role</b>: To have a Multiquadic cooefficient allow to have a more continuous solution.
	* <br> In other side, the solution can become mor irregular.
	* <br> The default value is 0.0
	* <p> <b>Limitation</b>: This have no effect if an an external elementary function is used.
	*
	* @param iC [in]
	*   A positive (or null) value.
	*
	*   0 : OK
	* <br>  >0: else (the pre func methode has no effect)
	*
	*/
	virtual int SetMultiQuadC(const double iC) = 0;

	/** 
	* Set an approximative Solution.
	*
	* <br><b>Role</b>: It is possible to have an approximative solution t outr problem <b>Role</b>
	*   and we want solve the residual problem L(F+G) = C wich replace the normal L(F) = C.
	*
	* @param iPreFunc [in]
	*   The iPreFunc is the approximative solution G (see uppper)
	*
	* @return
	*   0 : OK
	* <br>  >0: else (the pre func methode has no effect)
	*
	*/
	virtual int SetPreFunc(CATMathMarshFunction * iPreFunc) = 0;

	/** 
	* To (un)activate the prefunc mode.
	*
	* <br><b>Role</b>: To take into account an approximative solution see #SetPreFunc .
	*
	* @param iActivate [in]
	*   TRUE : The prefunc mode is actived (if a pre function is actived)
	*<br>  FALSE : The prefunc mode is unactived.
	*
	* @return
*   0 : OK.
	* <br>  >0: else (the ActivatePreFunc has no effect)
	*/
	virtual int ActivatePreFunc(const CATBoolean iActivate) = 0;

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
						          const double modif_epsilon = 0.001) = 0;  // @NumValidated : Tolerance normalise (distance dans une Boule (O,1))

	/** 
	* Solve the problem with an external elementary function.
	*
	* <br><b>Role</b>: Allow to interpolate the constraint with user's kernel.
	*
	* @param ESE [inout]
	*   The elementary function, used in the solver.
	* @param CoefNormalization [inout]
	*   Define the radius, of the normalized Ball. 
	* @param modif_epsilon [inout]
	*   Define the confusion tolerance in the normalized Ball.
	* <p> This allow eliminate redundant constraint (compatible or not)
	*
	* @return
*   0 : If the solve is done
	* <br>  >0: else
	*
	*/
	virtual int SolveTI(CATMathMarshExternFunction *ESE,
											 const double CoefNormalization=1.0,
											 const double modif_epsilon = 0.001) = 0;  // @NumValidated : Tolerance normalise (distance dans une Boule (O,1))


  virtual int FreezeScale(const CATMathPoint& iCenter, const double iScale) = 0;


	//virtual int PseudoSolveWithPartialSolution(CATListOfInt& iRowsWithSolution) = 0;


	//
	// return code
	// 0 : OK
	// 1 : Some pinpoint are not identified
	// 2 : Some pinpoint are identified more thane one time !
	// >2 : Internal error
	//virtual int IdentifyRows(CATIMathMarshPPCArray * IPPC, CATListOfInt& oRows) const = 0;


#ifdef WithDirectMode
	// Very advanced methode !
	virtual int SetDirectMode(CATBoolean isDirect) =0;
#endif

  virtual int KeepSolAndSecMember(const int isKeep) = 0;
	virtual int GetSolAndSecMember(double *& oSol, double *& oSecmember, 
		                             int& oNb, int& oDimMoment, int* iopCurrentArraysSize=NULL) = 0;
	virtual int GetPolyPart(double*& oPol, int& oNbCoeff) = 0;
	virtual int GetPolyWeight(double*& oGamma, int& oNbW, const double iCoefNormalization)const = 0;

 

  /** 
  * Give the function's result.
  *
  * <br><b>Role</b>: Give the solution with detail, it is usfule 
	* to perform some algorithm ased on marshMallow
  *
  * <p>
	*  it 'is for advanced use only, else use CATMathMarshBasicSolver#GetResult()
  * @return
  *   The result function.
  *
  */
  virtual const CATMathMarshSolvingFunction * GetFunction() const = 0;

	/** 
	* Get the prefunction.
	*
	* <br><b>Role</b>: retrieves the pre function @see #SetPreFunc .
	*
	* @return
	*   the prefunction.
	*/
	virtual const CATMathMarshFunction * GetPreFunc() const = 0;

  /** 
	* To say if the prefunc mode is actived
	*
	* @return
  *   TRUE : The prefunc mode is actived.
	*   FALSE : The prefunc mode is not actived.
	*/
	virtual CATBoolean IsActivatePreFunc() const = 0;


	/** 
	* Get the maximal radius compatible with the number of punctual Load.
	*
	* <br><b>Role</b>: Can be useful to choose an radius.
	*
	*
	* @return
	*   Explain return values
	*
	*/
	virtual double GetRadiusMax() const=0;


	/** 
	* Get the residual norm of the solution
	*
	* <br><b>Role</b>: Get information on accuracy and stability
	*
	*
	* @return
	*   return the residual norm.
	*/
	virtual double GetResidu() const = 0;


	/** 
	* Get a minorant of the condition number.
	* <br><b>Role</b>: Get information on the algorithm 's stability.
	8                  After the Solve the Condition Number can be minored
	* @return
	*   A minorant of the algorithm condition Number
	*/
	virtual double GetCondNumberMinorant() const =0;


  /** 
  * Detect if some Linear scalar constraint are contained.
  *
  *
  * @return
  *   TRUE : if some LSC are Loaded
  *   False: else
  *
  */
  virtual CATBoolean IsContainLSC() const =0;

	virtual CATLONG32 GetConfusedCenter(CATLISTV(CATMathPoint)& ConfusedPoints) const =0;

	virtual 	double GetConfusion() const =0;

  virtual double GetMultiQuadC() const =0;

  virtual  CATBoolean IsUnderConstrained()const = 0;

  //Debug Purpose
  virtual int DisplayPPCA( CATMathDebugFactory * iFactory) const =0;

	//KTU 23/09/10 MPROC
	virtual int LocatePPCA(CATIMathMarshPPCArray * ipPPCA2Locate)const=0;
	virtual CATIMathMarshPPCArray* GetPPCA(const int iPosition )=0;
	virtual CATBoolean IsStreamable()const=0;
	virtual int Stream(CATMathStream &ioWriteStream)const=0;

	virtual void setDebugFactory(CATMathDebugFactory* debugFactory) {};
};


/** 
* Create a solver object.
*
* <br><b>Role</b>: o Interpolate 3D constraints
*
* @param iTrsf [in]
*   A (optional) pre conditionner transformation.
*
* @return
*   A constraint solver.
*
*/

ExportedByMathAdvMarsh CATMathMarshSolver * CreateCATMathMarshSolver(const CATSoftwareConfiguration* iConfig, const CATMathTransformation* iTrsf=0);
ExportedByMathAdvMarsh CATMathMarshSolver * CreateCATMathMarshSolver(CATMathStream &ioReadStream);

ExportedByMathAdvMarsh CATMathMarshSolver * CreateCATMathMarshSolverFMM(const CATSoftwareConfiguration* iConfig, const double iTol, const CATMathTransformation* iTrsf=0, const int iNbMaxThreads=0);

//ExportedByMathAdvMarsh CATMathMarshSolver* CreateCATMathMarshSolverPUM(const CATSoftwareConfiguration* iConfig, const double nbPPCByBox = 100., const double Covering = 0.3, const bool cao = false, const short geomChosen=1);
ExportedByMathAdvMarsh CATMathMarshSolver* CreateCATMathMarshSolverPUM(const CATSoftwareConfiguration* iConfig, const CATMathMarshPUMOption* iOption = NULL);

#endif
