#ifndef CATPLANARPROJECTION_H
#define CATPLANARPROJECTION_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1997
//
// CATHLRPlanarProjection : class for the  projection of CATCurve on a CATPlane
//
// DESCRIPTION : Projection of CATLine is a CATPoint(CGM) or a CATPLine(CGM)
// Projection of CATCircle is a CATPCircle(CGM), a CATEllipse(CGM) or a CATPLine(CGM)
// Projection of CATEllipse is a CATEllipse(CGM) ,a CATPLine(CGM) or a CATPCircle(CGM)
// Projection of CATBezierCurveV4 is a CATPNurbs(CGM)
//
// Parabola,Hyperbola are not treated here
//
// ** WARNING ** : the CATGeoFactory must be a "CGM" CATGeoFactory
// (use CGMCreateRootContainer)
//
//=============================================================================
// Abstract Class     : No
// Template Code      : No
// Inline Functions   : Yes
//=============================================================================
//
// History
//
// Aug. 1997 JCH Creation            
// Jun. 1999 HKL Recherche de canonicite pour la projection des splinecurves
// Aug. 1999 HKL Unification de demi-cercles projetes
// Jun. 2000 HKL Projection en conique
//
//=============================================================================

// For Windows NT
#include "HLRProject.h"

// Other includes
#include "CATHLRConstant.h"
#include "CATErrorDef.h" // HRESULT

class CATCurve;
class CATGeoFactory;
class CATPCurve;
class CATPlane;
class CATCrvParam;
class CATHLRCurve;
class CATHLREdge;
class CATHLRDiscretizer;
class CATHLRProjection; 
class CATHLRGeometry2DFactory;
class CATHLRResultPart;
class CATHLRResultPartV4;
class CATHLRObjectLinker;
class CATMathSetOfPointsND;
class CATSoftwareConfiguration;
class CATTolerance;

class CATMathPoint;
class CATMathPoint2D;


class ExportedByHLRProject CATHLRPlanarProjection
{
 public:
//------------------------------------------------------------
// Enumeration
//------------------------------------------------------------
  enum ProjectedType
    {
      Unknown, Line, Circle
      };
  
//------------------------------------------------------------
// Constructor
//------------------------------------------------------------
  CATHLRPlanarProjection(CATGeoFactory                * iFactoryForCreation, 
                         CATPlane                     * iProjectionPlane,
                         CATHLRConstant::TypeProjection iProjectionType = 
                         CATHLRConstant::Cylindrical, CATSoftwareConfiguration * iConfig = 0);

  CATHLRPlanarProjection(CATGeoFactory                * iFactoryForCreation, 
                         CATPlane                     * iProjectionPlane,
                         const CATMathPoint           & iObserver,
                         const CATMathPoint           & iTarget,
                         CATHLRConstant::TypeProjection iProjectionType = 
                         CATHLRConstant::Cylindrical, CATSoftwareConfiguration * iConfig = 0);

// Destructor  
  ~CATHLRPlanarProjection();


//------------------------------------------------------------
// Methods
//------------------------------------------------------------
// Sets the SoftwareConfiguration for versionning
  virtual void SetCGMSoftwareConfiguration(CATSoftwareConfiguration * iConfig);

// Projection of a curve. The type of the curve might be precised with the last
// parameter else it is taken on the CATHLRCurve.
// iProjectionMode 
// 0: approximate 
// 1: exact projection if available
  CATPCurve * ProjectCurve(CATHLRCurve          * iCurve      , 
			                     const CATCrvParam    & iStartParam ,
                           const CATCrvParam    & iEndParam   ,
                           CATHLRConstant::TypeCurve iType = CATHLRConstant::Spline,
                           CATHLREdge           * iHLREdge = NULL,
                           int                  * oBreakingFlag = NULL,
                           CATCrvParam          * oBreakingParam = NULL,
                           int                    iProjectionMode = 0);

  // Projection of a 3D Point
  // The projected point is a CATMathPoint2D lying on the CATMathPlane of the reference planar surface
  HRESULT ProjectPoint(const CATMathPoint & iPt3DToProject, CATMathPoint2D & oProjectedPtOnPlane);
  
// Sets the object that creates the 2-dimensional geoemtry (note that the given
// object becomes the property of the CATHLRPlanarProjection and is deleted by him).
  void Set2DGeoFactory(CATHLRGeometry2DFactory * iGeo2DFactory);

  const CATTolerance & GetPlanarTolerance();

  // Gets the projection 2D factory
  inline CATHLRGeometry2DFactory * Get2DGeoFactory();

  // Gets the projection plane
  inline CATPlane * GetPlane();

  inline CATHLRDiscretizer * GetDiscretizer();

// Asks the projection to infere the best canonicity on projected curves
// This flag should be OFF for V4 HLR motor (for we do rasage+lissage)
// and ON for exact HLRs (for some projections should be circles/ellipses)
  inline void SetBestCanonicityOn();
  inline void SetBestCanonicityOff();
  
// Destruction d'un element projete
  void RemoveElement(CATPCurve * iPCurve);

// Unification de demi-cerles
  CATPCurve * MergeParts(CATPCurve          * iPCurve, 
                         CATHLRResultPart   * iNewPart, 
                         CATHLRResultPart   * iOldPart, 
                         CATHLRObjectLinker * iPartToJeleTable);

// Unification de demi-cerles
  CATPCurve * MergeParts(CATPCurve * iPCurve, 
                         CATHLRResultPartV4 * iNewPart, 
                         CATHLRResultPartV4 * iOldPart, 
                         CATHLRObjectLinker * iPartToJeleTable);

//=============================================================================
// INTERNAL DATAS
//=============================================================================
protected:

  // Versionning
  CATSoftwareConfiguration * _SoftwareConfiguration;
  int                 _InputConfig;

  // Factory to create the PCurves
  CATGeoFactory     * _Factory;

  // Plane on which all is projected
  CATPlane          * _Plane; 

  // Projection used
  CATHLRProjection  * _Projection;

  // Object to discretize the curves
  CATHLRDiscretizer * _Discretizer;

  // Resolution for the minimum size of the projected curves
  double              _Resolution;

  // Object that is used to create the 2-dimensional geometry
  CATHLRGeometry2DFactory * _Geo2DFactory;

  // Tells if the projection should look for the best canonicity
  int                 _BestCanonicityFlag;

  // The limits of the projetcion plane
  double _umin, _umax, _vmin, _vmax;

  // Gestion des projections coniques
  CATHLRConstant::TypeProjection _ProjectionType;

  CATMathSetOfPointsND * _SetOfPoints;

  //=============================================================================
  // INTERNAL METHODES
  //=============================================================================

private:
  
  int BreakSuperposedLine(double                iCheckPrecision,
                          CATMathSetOfPointsND &ioSetOfPoints,
                          CATCrvParam          &oBreakingParam);
};

//=============================================================================
// INLINE FUNCTIONS
//=============================================================================
inline CATHLRGeometry2DFactory * CATHLRPlanarProjection::Get2DGeoFactory()
{
  return _Geo2DFactory;
}

inline CATPlane * CATHLRPlanarProjection::GetPlane()
{
  return _Plane;
}

inline CATHLRDiscretizer * CATHLRPlanarProjection::GetDiscretizer()
{
  return _Discretizer;
}

inline void CATHLRPlanarProjection::SetBestCanonicityOn()
{
  _BestCanonicityFlag=1;
}

inline void CATHLRPlanarProjection::SetBestCanonicityOff()
{
  _BestCanonicityFlag=0;
}


#endif
