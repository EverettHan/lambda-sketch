// COPYRIGHT DASSAULT SYSTEMES 1997
//=============================================================================
//
// CATSweepGeo2Def:
// Utility for migration
//=============================================================================

//=============================================================================
// HISTORIC
//
// July. 98 CFT Creation
// 07 06 00 ALM __SortieDesLongueursDExtrapolation_070600 : on sort les longueurs
//              d'extrapolation estimees par GetDiscontinuityVertices, pour le 
//              nouveau code de calcul de skin de CATSweep
// 03 08 00 ALM Suppression de __SortieDesLongueursDExtrapolation_070600 et 
//              livraison de ComputeDiscontinuities qui gere le non manifold,
//              les extrapolations sur voisinage, et ne met pas a jour les 
//              CATCrvLimits dans la CCv apres extrapolation. Ce code est 
//              appelle par CATSweep, via un set au runtime :
//              set DEV__ALM_Sweep2.
// 05 03 01 ALM Ajout de CuspVertices dans ComputeDiscontinuities.
// 21 03 01 ALM Ajout de CrvIndicesLists, CrvParamsLists, ParamsLists, 
//              et LimitTypesLists dans ComputeDiscontinuities.
// 19 06 02 ALV Ajout de iTopData dans 1 constructeur pour le versionning de CATPGMExtruder...
//=============================================================================
#ifndef CATSweepGeo2Def_H
#define CATSweepGeo2Def_H

//=============================================================================
// ALGO OPTIONS
//
//=============================================================================

//=============================================================================
// DEBUG OPTIONS
//
//=============================================================================

//=============================================================================
// INCLUDES
//
#include "BO0SWEEPLight.h"
#include "CATSweepBasic.h"
#include "CATListOfCATCurves.h"
#include "CATListOfInt.h"
#include "CATMathDirection.h"
#include "CATListOfCATCrvLimits.h"
#include <ListPOfCATVertex.h>                 
#include <ListPOfCATEdge.h>
#include "CATTopData.h"
//=============================================================================

//=============================================================================
// CLASSES
//
class CATPGMExtruder;
           
class CATGeoFactory ; 
class CATGeometry ;
class CATMathDirection ;
class CATSurface;
class CATSurParam ;
class CATCurve;
//=============================================================================

//-----------------------------------------------------------------------------
class ExportedByBO0SWEEPLight CATSweepGeo2Def
{
public:

  //-------------------------------------------------------------------------
  // Object Management
  //-------------------------------------------------------------------------
  CATSweepGeo2Def ( CATSweepBasic * iSweepBasic , CATGeoFactory * iWhere ,CATTopData * iTopData );
  CATSweepGeo2Def ( CATPGMExtruder * iExtruder );
  ~CATSweepGeo2Def() ;

  //-------------------------------------------------------------------------
  // Read
  //-------------------------------------------------------------------------
  CATPGMExtruder * GetExtruder ();

  //-------------------------------------------------------------------------
  // Already existing surfaces.
  // This list defines which surfaces can be used rather than generated.
  // This list may be modified because it is filtered according to extrude type.
  //-------------------------------------------------------------------------
  void SetExistingSurfaces( CATLISTP(CATSurface)* ioSurfacesList ) ;

  //-------------------------------------------------------------------------
  // Center Body management
  //-------------------------------------------------------------------------
  void SetCenterBody(CATBody * iCenterBody) ;

  //-------------------------------------------------------------------------
  // Profile Body management
  //-------------------------------------------------------------------------
  void SetProfileBody(CATBody * iProfileBody) ;

  //-------------------------------------------------------------------------
  // Center Curves Orientation management
  //-------------------------------------------------------------------------
  void SetCenterCurves( CATLISTP(CATCurve) & CenterCurves ,
			CATListOfInt       & CenterCurvesOrn) ;

  //-------------------------------------------------------------------------
  // Returns in which direction the provided point will be SweepGeod.
  //-------------------------------------------------------------------------
  void GetDeriv( const CATSurface  * iSupport, 
                 const CATSurParam & iLocation,
                 const CATCurve    * iCenter,
                 CATMathDirection  & oDirection);

  //-------------------------------------------------------------------------
  // Returns data about C0 vertices discontinuities
  //-------------------------------------------------------------------------
  void GetDiscontinuityVerticesOnCenter (ListPOfCATVertex & oDiscontinuityVertices,
                                        ListPOfCATEdge   & oEdgesToExtrapolate,
                                        CATLISTP(CATCrvLimits) & oNewEdgesLimits);
  void ComputeDiscontinuities(CATListPV       & oNMVertices, 
                              CATListPV       & oC0Vertices,
                              CATListPV       & oEdgesToExtrapolate, 
                              CATListOfDouble & oExtrapolationLengthOnStart,
                              CATListOfDouble & oExtrapolationLengthOnEnd,
                              CATListPV       & oCuspVertices,
                              CATListPV       & oCrvIndicesLists,
                              CATListPV       & oCrvParamsLists,
                              CATListPV       & oParamsLists,
                              CATListPV       & oLimitTypesLists);
protected :

  CATPGMExtruder   *             _Extruder;

private:

  short                       _deleteExtrude;

};

#endif








