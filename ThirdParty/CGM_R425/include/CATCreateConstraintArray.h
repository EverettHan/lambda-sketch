#ifndef CATCreateConstraintArray_h
#define CATCreateConstraintArray_h


#include "MathPlate.h"

#include "CATMathPlateD1.h"
#include "CATMathPlateD2.h"
#include "CATMathPlateD3.h"
#include "CATMathPoint2D.h"
#include "CATMathLine.h"
#include "CATMathPlane.h"

class CATIMathPlatePPCArray;
class CATIMathPlateLXYZCArray;
class CATIMathPlateLScalarCArray;


// ==============================================
// ========     Create arrays to fill     =======
// ==============================================

 ExportedByMathPlate CATIMathPlatePPCArray* CreatePPCArray(CATLONG32 iLength);
// ==============================================
// =====          Build GToCConstraint    =======
// ==============================================
//    define a G1, G2  or G3 constraint on the Plate

    // D1S : first  derivative of  S, the surface we want to  correct 
    // D1T : first derivative of the reference surface
    // D2S : second derivative of  S, the surface we want to  correct 
    // D2T : second derivative of the reference surface
    // D3S : third derivative of  S, the surface we want to  correct 
    // D3T : third derivative of the reference surface
    // iDir is a optional vector : it define a diretion of deformation
		///ktu:: 11/04/2001 
		/// const CATBoolean iCorrigeTol : Pour connaitre s vous vouler beneficier de la 
		/// correction du calcul des tolerances C1 ou non

// Build a G1 Constraint
 ExportedByMathPlate CATIMathPlatePPCArray* CreatePPCArray(const CATMathPoint2D& point2d,
									                       const CATMathPlateD1& D1S,
														   const CATMathPlateD1& D1T,
														   const CATMathVector * iDir = NULL,
														   const double &iTolG1=0.001,
														   double *oTolC1 = NULL,
															 const CATBoolean iCorrigeTol = 0);

// Build a G2 (& G1 ) Constraint
 ExportedByMathPlate CATIMathPlatePPCArray* CreatePPCArray(const CATMathPoint2D& point2d,
									   const CATMathPlateD1& D1S,
									   const CATMathPlateD1& D1T,
									   const CATMathPlateD2& D2S,
									   const CATMathPlateD2& D2T,
									   const CATMathVector * iDir = NULL,
									   const double &iTolG1=0.001,
									   const double &iTolG2=0.001,
									   double *oTolC2 = NULL,
										 const CATBoolean iCorrigeTol = 0);
 
// Build a G3 (& G1/2 ) Constraint
  ExportedByMathPlate CATIMathPlatePPCArray* CreatePPCArray(const CATMathPoint2D& point2d,
									   const CATMathPlateD1& D1S,
									   const CATMathPlateD1& D1T,
									   const CATMathPlateD2& D2S,
									   const CATMathPlateD2& D2T,
									   const CATMathPlateD3& D3S,
									   const CATMathPlateD3& D3T,
									   const CATMathVector * iDir = NULL,
									   const double &iTolG1=0.001,
									   const double &iTolG2=0.001,
									   const double &iTolG3=0.001,
									   double *oTolC3 = NULL,
										 const CATBoolean iCorrigeTol = 0);

// ==============================================
// =====      Build FreeGToCConstraint    =======
// ==============================================
// define a G1, G2 or G3 constraint on the Plate using weaker
//         constraint than GtoCConstraint 
// Build a G1 Constraint
 ExportedByMathPlate CATIMathPlateLScalarCArray*  
CreateFreeGToCCArray(const CATMathPoint2D& iPoint2d,
									   const CATMathPlateD1& iD1S,
									   const CATMathPlateD1& iD1T,
										 const double &iTolG1=0.001,
										 double *oTolC1 = NULL, // null ou add d'un tableau de 2 doubles
									   const double iIncrementalLoad = 1.0,
									   const int iOrientation = 0);

// Build a G2 (& G1 ) Constraint
 ExportedByMathPlate int CreateFreeGToCCArray(CATIMathPlatePPCArray*& oPPCA,
									   CATIMathPlateLScalarCArray*& oLSCA,
									   const CATMathPoint2D& iPoint2d,
									   const CATMathPlateD1& iD1S,
									   const CATMathPlateD1& iD1T,
									   const CATMathPlateD2& iD2S,
									   const CATMathPlateD2& iD2T,
									   const double iIncrementalLoad = 1.0,
									   const int iOrientation = 0);

// Build a G3 (& G1 G2 ) Constraint
ExportedByMathPlate int CreateFreeGToCCArray(CATIMathPlatePPCArray*& oPPCA,
									    CATIMathPlateLScalarCArray*& oLSCA,
										  const CATMathPoint2D& iPoint2d,
										  const CATMathPlateD1& iD1S,
										  const CATMathPlateD1& iD1T,
										  const CATMathPlateD2& iD2S,
										  const CATMathPlateD2& iD2T,
										  const CATMathPlateD3& iD3S,
										  const CATMathPlateD3& iD3T,
										  const double iIncrementalLoad = 1.0,
										  const int iOrientation = 0);

/*
** To define a LXYZCArray of Length iLength
** Warning this array have to be filled.
*/
ExportedByMathPlate CATIMathPlateLXYZCArray*  CreateLXYZCArray(CATLONG32 iLength);

/*
**  To define a constraint of "Global Translation" on a set of points
*/
ExportedByMathPlate CATIMathPlateLXYZCArray*  CreateLXYZCArray(int iLength, CATMathPoint2D * iPoints);

/*
** To define a LXYZCArray of Length iLength
** Warning this array have to be filled.
*/
ExportedByMathPlate CATIMathPlateLScalarCArray*  CreateLScalarCArray(CATLONG32 iLength);

/*
**  To define a Line constraint on a set of points
*/
ExportedByMathPlate CATIMathPlateLScalarCArray*  CreateLScalarCArray(const CATMathPoint2D* iPoint2D,
																	 const int iNumber,
																	 const CATMathPoint* iStartPoint,
																	 const CATMathLine& iLine, 
																	 const int iU=0, const int iV=0);

/*
**  To define a Plane constraint on a set of points
*/
ExportedByMathPlate CATIMathPlateLScalarCArray*  CreateLScalarCArrayWithPlane(const CATMathPoint2D* iPoint2D,
																	 const int iNumber,
																	 const CATMathPoint* iStartPoint,
																	 const CATMathPlane& iPlane, 
																	 const int iU=0, const int iV=0);

/*
**  To define a constraint of "Sampled Curve Constraint" on a set of points
*/
ExportedByMathPlate CATIMathPlateLXYZCArray*  CreateSampledCurveConstraint(CATIMathPlatePPCArray* iPPCA, const int iN);


/**
 * contruire les G1 et G2 transcerse
 * et calcul les tol C2 correspondants
 * oPPCA => contrainte G1
 * oLXYZ => contrainte G2 transverse;
 * iP2D : 2d
 * iDxS : les derivees d'odre x de l'init
 * iDxT : ""     ""      ""   "  de l'objectif
 * iTolG1 : tolerence G1 en grd
 * iTolG2 : % des erreurs G2 ( % des courbures transverse
 * ioTolC2[3]: 0,1 = tolc1, 2=>C2 des lxyz
 * return 1 => error 0 => if not
 */
 ExportedByMathPlate int CreateTransverseConstraints(CATIMathPlatePPCArray * & oPPCA,
                                                   CATIMathPlateLXYZCArray *& oLXYZA, 
                                                   const CATMathPoint2D& point2d,
									                        const CATMathPlateD1& D1S,
									                        const CATMathPlateD1& D1T,
									                        const CATMathPlateD2& D2S,
									                        const CATMathPlateD2& D2T,
                                                   const CATMathVector & iDirTrans,
									                        const double iTolG1=0.0087,
									                        const double iTolG2=0.01,
									                        double *oTolC2 = NULL,
                                                   const double iMinTolG1 = 1.745e-5, //=>1e-3 deg,
                                                   const int iLevel = 0,
                                                   const CATMathVector * iDeformDir = NULL);

#endif


