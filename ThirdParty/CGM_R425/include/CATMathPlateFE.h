/// COPYRIGHT DASSAULT SYSTEMES 1999
//=============================================================================
//
// CATMathPlateFE :
//  This  class implement a Finite Element
//        Method algorithm able  to  define a BSpline   two variable
//        function satisfying   some constraints and  minimizing  an
//        energy like criterion.

//     see also CATMathPlateSolver for analytical method.

//=============================================================================
// Septembre . 99    Creation             P.Mangin
//=============================================================================
// File : CATMathPlateFE.h
// Apr  2012   NLD : - Add SetSoftwareConfiguration()
// Fev  2006   KTU : - Add int FixedExtremities( unsigned int  iExtRanks[4] );
// Sept 2003   KTU : - Progress Bar integration 
// Jan  2002   KTU : - Ajout de la methode LoadMaximumNumberOfPatch(const int iMaxU, const int iMaxU)
//                     pour le getion de MaxPacth en U et En V
//

#ifndef CATMathPlateFE_H
#define CATMathPlateFE_H

#include "PlateFE.h"
#include "CATMathDef.h"
#include "CATListOfDouble.h"


/// #define  CATFE_AGAIN mv to CATPlateFEBasicFunction by ktu

class CATIMathPlatePPCArray;
class CATIMathPlateLXYZCArray;
class CATIMathPlateLScalarCArray;

class CATPlateFEOptimUVOption;

class CATFrFNurbsBipar;
class CATMathNurbsBipar;
class CATGeoFactory;
class CATSoftwareConfiguration;
class CATCGMProgressBar;

///#define LoadProgressive

///#define KTUcondFE
#include "CATPlateFEBasicFunction.h"


class ExportedByPlateFE CATMathPlateFE : public CATPlateFEBasicFunction
{
public:
  
	virtual ~CATMathPlateFE();

   virtual void SetFactory ( CATGeoFactory * iFactory ) = 0;

   virtual void SetSoftwareConfiguration(CATSoftwareConfiguration* iSoftwareConfiguration) = 0;

   // load some puncutal displacements Tab with tolerances and the ratio of 
   // 
   virtual void LoadPercent(CATIMathPlatePPCArray* IPPC, double* iTolerances, const double& iPercent) = 0;

	// Load some puncutal displacements.
	// Warning : If you change these displacement, PlateFE have to take into account them !
	virtual void Load(CATIMathPlatePPCArray* IPPC, double* iTolerances, const int ilevel = 0) = 0;

	// Load some linear constraint in each spatial dimmension
	// Warning : If you change these displacement, PlateFE have to take into account them !
	virtual void Load(CATIMathPlateLXYZCArray* ILXYZC, double* iTolerances) = 0;

	// Load some scalar constraint ie linear constraints on (Xi,Yi,Zi)
	// Warning : If you change these displacement, PlateFE have to take into account them !
	virtual void Load(CATIMathPlateLScalarCArray* ILSC, double* iTolerances) = 0;

	// Resume all the Load
	virtual void ResetConstraints() = 0;

#ifdef FE_FACTORY
	// Load the surface to deform
	virtual void LoadSurfInit(CATNurbsSurface* iSurfInit, 
														const double iAniso = 1., 
														const double iCoefAniso = 50.) = 0;//do not use
#endif

	virtual	int LoadSurfInit(CATMathNurbsBipar* iSurfInit,  
														const double iAniso = 1., 
														const double iCoefAniso=50)=0;

	// Set a weight to an order of Energy
	// Order have to be  0 <= order <= 9;
	// to suppress an order you have to set coef = 0.
	virtual int LoadEnergy(const int iorder, const double icoef) = 0;

	// Define if the approximation precessus begin with one Bezier 
	// or with the initial surface.
	virtual void DefineInit(const CATBoolean InitLikeSurfInit = 0) = 0;

  // Set the maximum number of iteration of each Phasis
	// iNbPhase1 : Number of iteration to Find Equilibrum beetween Constraint and Energy
	// iNbPhase2 : Number of iteration to Find the best number of vertexes on 
	//             the Delta Surface:  Each iteration can multiply the vertexes number by 2
	// iNbPhase3 : Number of iteration to reach the wanted accuracy.
	// Warning : Each NumberOfIteration can be Zero but one of them have to be positive
	virtual void LoadNumberOfIterations(const int iNbPhase1 = 5, 
		                                  const int iNbPhase2 = 4, 
													 const int iNbPhase3 = 9,
                                        const int iWithPhase4 = 0) = 0;

	/*
	*  Un mode qui vise le respect des moindre carre des la phase1
	*  C'est utile quand il, n'y a pas de phase 2 et que l'on veut tenir les tolerance coute que coute!!!
	*/
	virtual void SetQTargetMode(const CATBoolean isQTargetMode = FALSE) = 0;

	/*
		Set the maximum number of patches authorized in the DeltaSurface
	*/
	virtual void LoadMaximumNumberOfPatch(const CATLONG32 iNbMaxOfPatch) = 0;

	/*
    * ktu 23/02/2202
	 *	Set the maximum number of patches U ab V authorized in the DeltaSurface 
	 */
	virtual void LoadMaximumNumberOfPatch(const CATLONG32 iNbMaxOfPatchU,
                                          const CATLONG32 iNbMaxOfPatchV) = 0;


   /*
		To force a minimal Continuity at the delta Surfaces
		Warning : it is not used for the BindingKnots (see LoadBindingKnotsInU() method)
	*/
	virtual void LoadMinimalContinuity(const CATLONG32 UMinCont, const CATLONG32 VMinCont)=0;

	/*
	  To force some cutting in the PlateFE Result... 
	*/
	virtual void LoadBindingKnotsInU(const int iNbUCut, const double * iCutInU, const int iUContinuity)=0;
	virtual void LoadBindingKnotsInV(const int iNbVCut, const double * iCutInV, const int iVContinuity)=0;

/***********************************************************************************
 * purpuse: Imposed Cutting values                                                 *
 ***********************************************************************************/
	virtual void SetImposedCutting(const CATBoolean iImposed)=0;

  /*
	  To read the CodeLevel 
	*/
	virtual int CodeLevel() const = 0;

  /*
	  To Set the CodeLevel 
		Warning this methode erase the LoadInformation (it must be call before any Load)
	*/
	virtual void SetCodeLevel(const int iCodeLevel) = 0;

	/* 
	To manage Parametric Optimisation
	*/
    virtual CATPlateFEOptimUVOption* GetOptimUVOption() = 0;

	// The Complete methode to solve.
	// The return code can be not so accurate as Run methode. 
	// 0 : All is Ok;
	//-1 : Warning, the result is inaccurate
	// 1 : Error : No result are computed.
	virtual int Run() =0;

#ifdef  CATFE_AGAIN
	// The optimized methode to solve. 
	// It is usefull to solve after small modification of the constraints
	// Warning : These methode can 
	// The return code can be not so accurate as Run methode. 
	// 0 : All is Ok;
	//-1 : Warning, you use RunAgain before Run
	// 1 : Error : No result are computed.
	virtual int RunAgain() =0;
#endif

	// Get the initial surface
	virtual const CATMathNurbsBipar* GetSurfInit() = 0;

// Get the result surface
	virtual void GetSurfResult(CATFrFNurbsBipar*& oSurf) const= 0;

	// Get the delta surface
	virtual void GetSurfDelta(CATFrFNurbsBipar*& oSurf) const= 0;

  // Get the maximal deformation on verticies.
  virtual int GetDeltaMax(double& oDeltaMax) const=0;


	// Get the Energy on the delta Surface.
	virtual double GetEnergy() const= 0;

	// return the Max order of constraint loaded;
	virtual int MaxConstraintOrder() = 0;	
	
	/*  Not Documented */
	virtual void Dump(const int iLevel) const = 0;

/// //ktu nb de niveau de pnt
	virtual	void SetMaxLeveL(const int imaxLevel) = 0;

  //// ktu 02/06/01 chargement des vertex comme decoupe prefs
  virtual void LoadVertexKnotsInU(const int iNbVertexUCut, 
													const double * iVertexCutInU, 
													const int iVertexUContinuity) = 0;
  virtual void LoadVertexKnotsInV(const int iNbVertexVCut, 
													const double * iVertexCutInV, 
													const int iVertexVContinuity) = 0;
  ///ktu 11/07/01 pour compacter les lsc
  virtual void SetCompactLSC(CATBoolean iOption) = 0;

   
  /**
   * ktu 17/03/03
   * SetFilterOfCuttingByRatio:
   * Permet d'activer le filtre local des decoupes
   * par les ratio des spans
   */
   virtual void SetFilterOfCuttingByRatio( CATBoolean iFilterOn) = 0;

   virtual void ActivedCldMode( CATBoolean iIsActive ) = 0;

   /**
    * Set Callback function to update Progress Bar
    * iNbTops : 0<iNbTops<=100 : number of times to call iFunc.
    * WARNING : iFunc will be called EXACTLY iNbTops times.
    */
   virtual int SetProgressBarEvolFunction( void (*iFunc)(), unsigned short iNbTops ) = 0;
   virtual void SetCallback( CATCGMProgressBar *ipProgressBar ) = 0;


	/**
	 * That makes it possible to fix a consecutive number of Ranks of Control points.
	 * iExtRanks[i] : Contains the numbers of row to fix for Iso i.
	 * if iExtRanks[i]==0, no row will be fixed.
	 * Convention adopted for Iso :
	 *
	 *                           Iso V= Vmax
	 *                           iExtRanks[3]
	 *         vmax +-------------------------------------+
	 *              |                                     |
	 *              |                                     |
	 *              |                                     |
	 *              |                                     |
	 * Iso U= umin  |                                     |  Iso U= umax
	 * iExtRanks[0] |                                     |  iExtRanks[1]
	 *              |                                     |
	 *              |                                     |
	 *              |                                     |
	 *              |                                     |
	 *			  vmin +-------------------------------------+
	 *             umin                                  umax 
	 *                           Iso V= Vmin
	 *                           iExtRanks[2]
	 *
	 **/
	virtual int FixedExtremities( unsigned int iExtRanks[4])=0;

	// tmp 
	virtual int EnableRealignmentCut2 ()=0;
	virtual int DesableRealignmentCut2 () =0;

  virtual void SetMaxContinuity(const int iCont)=0;

   //@nodoc
   virtual void BeginWith1(CATBoolean iWith1)=0;

   //@NoDoc (@KTU20130821) 
   virtual int SetScale(const double iScale )=0;


};

// Build a plateFE operators with definition the maximum degree of the deformation
// and a order of Energy (beetween 2 and 9)
ExportedByPlateFE CATMathPlateFE * CreatePlateFE (const int idegreeU = 5, 
										          const int idegreeV = 5,
												  const int iOrderEnergy = 3);

// Build a plateFE operators with definition the maximum degree of the deformation,
// a order of Energy (beetween 2 and 9), and optimization of (u, v) of some constraints.
// 
ExportedByPlateFE CATMathPlateFE * CreatePlateFEOptimUV (const int idegreeU = 5, 
														  const int idegreeV = 5,
														  const int iOrderEnergy = 3);
																								
ExportedByPlateFE CATMathPlateFE * CreatePlateFENonLin (const int idegreeU = 5, 
														const int idegreeV = 5,
														const int iOrderEnergy = 3);
#endif
