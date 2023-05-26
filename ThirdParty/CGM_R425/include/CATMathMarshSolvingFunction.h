#ifndef _CATMathMarshSolvingFunction_HeaderFile
#define _CATMathMarshSolvingFunction_HeaderFile
// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2000
//
/** @level private
* @usage U3
*/
  


#include "CATMathDef.h"
#include "CATMathVector.h"
#include "CATMathMarshFunction.h"
#include "CATListPOfMarsh3DBox.h"
#include "CATListOfInt.h"

class CATSoftwareModification;
class CATMathProgressContext;

/**
* <br><b>Role</b>: Classe abstraite des Function de base "MarshMallow"
*   utilisable dans les algo de resolution.
* <p>
* Do not use the @href CATMathMarshSolvingFunction constructor but instead
* use CATMathMarshSolver#GetFunction
*

*
* @see @href CATMathMarshSolver, @href CATMathMarshFunction
*/
class CATMathMarshSolvingFunction : public CATMathMarshFunction
{
public:

	/** 
	* Isotropy information.
	* <br><b>Role</b>: Say if the deformations  is equal for X, Y and Z.
	* <br> The function F is called "Isotrope" if for each P in IR3
	* <br> the vector F(P) have his 3 coordinate equal.
	* @return
	* <li> TRUE if the function is ISOTROPE.
	* <li> FALSE else
	*/
	virtual CATBoolean IsIsotrope()  const =0;


  virtual int SetFastEvalMode(CATBoolean isFastMode, const double iTol, CATMathProgressContext* iContext=0)=0;

  virtual CATBoolean GetFastEvalMode(double& oTol) const=0;

  virtual CATBoolean IsFastModeAvailable() const=0;



	/** 
	* Compact information
	*
	* <br><b>Role</b>: Say if the bases functions are compact
	*
	* @return
	* <li> TRUE if the function is ISOTROPE.
	* <li> FALSE else
	*/
	virtual CATBoolean IsCompact()  const =0;

  //virtual CATSoftwareModification* GetSoftwareModification() const =0;

  virtual CATBoolean HasSymPlane() const =0;

	virtual int GetFunctionCoef(CATMathVector*& oFunctionCoef, int& oNbRadFunc, int&oNbPolyFunc) const = 0;

	virtual int GetNumberOfSources() const = 0;
	// recupere les points sources dans l'espace utilisateur 
	// DOIT ETRE DES-ALLOUER PAR L'APPELLANT !!
	virtual CATMathPoint* GetPoints() const = 0;

	virtual int GetRadialCoef(const double* iPoint, double*& oRadialCoef, 
													 int& oNbNoNull, 
													 CATListOfInt* ListIndex=NULL, const CATBoolean isAllocationInside = TRUE) const = 0;

  virtual int GetSymCoef(const double* iSetOfPoints, double*& oSumCoef, double*& oDiffCoef,
		                int& oNbNoNull, CATListOfInt* ListIndex=NULL, const CATBoolean isAllocationInside = TRUE) const = 0;

  virtual int GetRadialCoefByBox(const double* iPoint,  double* oRadialCoef,
												 int& oNbNoNull, CATListOfInt* oListIndex) const=0;

	virtual int GetPolynomialCoef(const double* iSetOfPoints, int iNbPoints, 
		                            double*& oPolynomialCoef, const CATBoolean isAllocationInside = TRUE) const = 0;
#ifdef MarshSym_Pol
  virtual int GetSymPolCoef(const double* iSetOfPoints, int iNbPoints, double*& oEvenCoef, double*& oddCoef,
		                const CATBoolean isAllocationInside = TRUE) const = 0;
#endif

	virtual const CATListPOfMarsh3DBox * GetBoxes() const = 0;

	virtual double GetScale() const = 0;


  virtual double GetMultiQuadC() const = 0;

  // Set le coefficent pour les Multi-quadrique
  // Permet de lisser la fonction.
  virtual int SetMultiQuadC(const double iCoeff) = 0;

  // Permet de lisser, tout en majorant l'erreur
  virtual double GetMaxMultiQuad(const double iTolerance) const =0;

	/** 
	* radius of cmpact base
	*
	* <br><b>Role</b>: donne le rayon du domaine de definition des fonction de base (dans le cas compacte)
	*
	* @param isNormalized [in]
	* <br> si isNormalized == TRUE, le rayon est normalise (ie < 1)
	* <br> sinon il est donne dans la metrique de l'utilisateur.
	*
	* @return
	*   The compact radius
	*
	*/
	virtual double GetRadius(const CATBoolean isNormalized = FALSE) const = 0;
};


#endif
