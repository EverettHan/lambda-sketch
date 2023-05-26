#ifndef _CATMathMarshFunction_HeaderFile
#define _CATMathMarshFunction_HeaderFile
// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2000
/** @level Protected
*  @usage U6
*/


#include "MathMarsh.h"
#include "CATMathDef.h"
#include "CATMathVector.h"
#include "CATMathStream.h"
#include "CATCGMStreamVersion.h"

class CATMathMarshSolver;
class CATMathTransformation;

/**
* 3d Point in float.
*
* <br><b>Role</b>: A structue to interface tesselation with marshMallow
*
* @see #EvalMesh
*/
typedef float cat_fpoint [3];

#define Marsh_Mode_Delta

/**
*  A function solution for MarshMallow.
*
* <br><b>Role</b>: Allow to evaluate a solution of MarshMallow
* <p>
* Do not use the @href CATMathMarshSolvingFunction constructor but instead
* use CATMathMarshBasicSolver#GetResult
*
* @see @href CATMathMarshSolver, @href CATMathMarshBasicSolver
*/
class CATMathMarshFunction
{
public:
	/**
	* Increments the reference count for the given function. 
	*/
	virtual void AddRef() = 0;

	/**
	* Decrements the reference count for the given interface. 
	* @return The reference count value.
	* <br>This information is meant to be used for diagnostic/testing purposes only, because, in certain situations, the value may be unstable.
	*/
	virtual void Release() = 0;

	/**
	* Determines whether the given object's class derives from a given class.
	* @param iName
	*   The class name from which the given object's class is supposed to derive.
	* @return 0 if the given object's class doesn't derive from <tt>iName</tt>
	* and a non null value otherwise.
	* @return
	* <br><b>Legal values</b>:
	*   <dl>
	*     <dt>0 </dt>
	*        <dd>Current onject does not derive from iName.</dd>
	*     <dt>1 </dt>
	*        <dd>Otherwise.</dd>
	*   </dl>
	*/
	virtual CATBoolean IsAKindOf(const char *iName) const = 0;

	/** 
	* Short role of the method.
	*
	* <br><b>Role</b>: Intialize the function
	*  after the initialization the function is NULL for
	*  all parameters.
	*/
	virtual void Init() = 0;

	/** 
	* <br><b>Role</b>: Create a function by copy
	*
	* @param oCopy [out]
	*   The created function
	* @param iCloneAll [in]
	*   Say if the created function have cloned all its field.
	*   This option is usfule to manage multi-thread (safe) with this class
	*
	* @return
	*   0 if all is OK.
	*
	*/
	virtual CATLONG32 Clone(CATMathMarshFunction * & oCopy, const CATBoolean iCloneAll=FALSE) const =0;

	/** 
	* <br><b>Role</b>: Function Evaluation
	*
	* @param iPoint [in]
	*   The 3d parameter P where the function is evaluated.
	* @param oResEval [out]
	*   The result of V = F(P)
	*
	* @return
	*   0 if the evaluation is performed.
	*/
	virtual CATLONG32 Evaluate(const CATMathVector & iPoint, CATMathVector& oResEval) const = 0;



	/** 
	* <br><b>Role</b>: Partial Derivative Function Evaluation
	*
	*      ix+iy+iz
	*    D          /   ix   iy   iz  F(P)
	*                D X   DY   DZ
	* @param iPoint [in]
	*   The 3d parameter P where the function is evaluated.
	* @param ix [in]
	*   The derivative order in x
	* @param iy [in]
	*   The derivative order in y
	* @param iz [in]
	*   The derivative order in z
	* @param oResEval [out]
	*   The result of V = dF(P)
	*
	* @return
	*    0 if the evaluation is performed.
	*
	*/
	virtual CATLONG32 EvaluateDerivative(const CATMathVector & iPoint,
		const int ix,
		const int iy,
		const int iz,
		CATMathVector& oResEval) const = 0;

	/** 
	* <br><b>Role</b>:  Multiple Partial Derivative Function Evaluation
	*
	* @param iPoint [in]
	*   The 3d parameter P where the function is evaluated.
	* @param iNbDer [in]
	*   The number of partial derivative to perform.
	* @param ix [in]
	*   The derivative order array in x
	* @param iy [in]
	*   The derivative order array in y
	* @param iz [in]
	*   The derivative order array in z
	* @param oResEval [out]
	*   The result array : {Vk} = dkF(P)
	*
	* @return
	*    0 if the evaluation is performed.
	*/
	virtual	CATLONG32 EvaluateDerivatives(const CATMathVector & iPoint,
		const int iNbDer,
		const int* idx,
		const int* idy,
		const int* idz,
		CATMathVector* oResEval) const = 0;


	/** 
	* The centers 
	* <br><b>Role</b>: Get the center used to normalize the function. 
	*
	* @param oCenter [out]
	*   the center used to normalize the function
	*/
	virtual void GetCenter(CATMathVector& oCenter)const=0;

	virtual void SetPolynomialPartOnly(const CATBoolean PPOnly = 0) = 0;

	/** 
	* Returns the number of sources in  the final resolution.		
	*/
	virtual int GetNumberOfSources() const =0;


  //// recupere les points sources dans l'espace utilisateur 
  //// DOIT ETRE DES-ALLOUER PAR L'APPELLANT !!
  virtual CATMathPoint* GetPointSources() const { return NULL; }

  
/**
*  SetHasCache
* <br><b>Role</b>: Set if cache are used or not in the evaluation
* @param iHascache
* TRUE : some cache are use to accelerate the evaluations
* FALSE : no cache are use to accelerate the evaluations (for multi-threading usage by example)
* WARNING : This is limited to simple evaluation (without dervative)
* 
*/
virtual void SetHasCache(CATBoolean iHascache)=0;
  

/**
* HasCache
* <br><b>Role</b>: Get cache usage state
* @return
* TRUE : some cache are use to accelerate the evaluations
* FALSE : no cache are use to accelerate the evaluations (for multi-threading usage by example)
* WARNING : This is limited to simple evaluation (without dervative)
*/
virtual CATBoolean HasCache() const=0; 


	/** 
	* Evaluation of a mesh
	*
	* <br><b>Role</b>: Compute the imgage by the function
	*  of a tesselation mesh.
	*
	* @param ID [inout]
	*   An IDentity number for the mesh, if for 2 following eval the initial Meshes (and ID) are equal 
	*   the methode can be optimized.
	*   IF THE MESHES ARE NOT EQUAL THE IDs HAVE TO BE DISTINCT !
	* @param iNumberOfFaces [in]
	*   The Number of faces in the mesh
	* @param iNumberOfVerticies [in]
	*   The number of verticies face by face.
	* @param iVerticies [in]
	*   The input vertices face by face.
	* @param iNormals [in]
	*   The input normales face by face.
	* @param oVerticies [out]
	*   The output vertices face by face.
	* @param oNormals [out]
	*   The output normales face by face.
	*
	* @return
	*   0 : OK
	*   >0 : KO;
	*/
	virtual int EvalMesh(int ID,
		int iNumberOfFaces,
		int *iNumberOfVerticies,
		cat_fpoint **iVerticies,
		cat_fpoint **iNormals,
		cat_fpoint **oVerticies,
		cat_fpoint **oNormals,
		CATMathTransformation*   iPreTransfo =0,
		CATMathTransformation*   inverseTransfo=0,
    CATMathVector * iCorrection =0) = 0;



	/** 
	* Linear combination of function
	* <br><b>Role</b>: Create a function by Linear combination
	* this function returns :  "this" + TabCoef[0]*(TabFunctions[0] -"this")
	* + TabCoef[1]*(TabFunctions[1]-"this") +...+TabCoef[NbFunctions-1]* (TabFunctions[NbFunctions-1]-"this")
	* .. with a reference counter set to 1... so... do a ->Release() when you are done.
	*	 it returns a null pointer if it fails (means that the true types are not consistent ...)
	*
	* @param NbFunctions [inout]
	*   The number of function to combine
	* @param TabFunctions [inout]
	*   The functions to combine
	* @param TabCoef [inout]
	*   The coefficient of the linear combination
	*
	* @return
	*   The created function
	* @return IUnknown#Release 
	*
	*/
	virtual CATMathMarshFunction *CreateLinearCombinationWith(const int NbFunctions, 
		CATMathMarshFunction **TabFunctions,
		double *TabCoef) const = 0;


/**
*
* <br><b>Role</b>: 
* @param iTargetVersion
* 
* @param ioReversible
* 
* @return
* 
*/
	virtual CATBoolean IsStreamable(const CATCGMStreamVersion iTargetVersion, CATBoolean & ioReversible)const =0;

/**
*
* <br><b>Role</b>: 
* @param ioWriteStream
* 
* 
*/
	virtual void Stream( CATMathStream& ioWriteStream )const  = 0;

};


/**
*  
* <br><b>Role</b>: Create a function from streamed Data
* @param ioReadStream
* Streamed Data
* @return
*   The created function
*/
ExportedByMathMarsh CATMathMarshFunction * CreateCATMathMarshFunction(CATMathStream& ioReadStream);

#endif
