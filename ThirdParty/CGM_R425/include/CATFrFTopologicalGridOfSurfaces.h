// COPYRIGHT DASSAULT SYSTEMES 1999
//=============================================================================
//
// CATFrFTopologicalGridOfSurfaces:
// Utility for producing topology from a grid of surfaces
//
//                                                    Nicolas LOCHARD
//=============================================================================
// Usage notes:
// ************************************************************
// * CAUTION: parameter change from curves along U and curves *
// * along V to Surfaces must be linear                       *
// ************************************************************
//
//
//
//=============================================================================
// 04 01 99 NLD Creation
// 21 01 99 NLD Ajout _ImplicitFactory, _GeomFactory
// 25 07 00 ALM Migration sur CATTopData et CATTopOperator
// 30 11 00 NLD _TopDataToDelete
// 28 09 05 NLD Suppression des constructeurs sans TopData
// 16 09 19 NLD Suppression _TopDataToDelete compte tenu des seuls constructeurs restants
//=============================================================================

#ifndef CATFrFTopologicalGridOfSurfaces_H
#define CATFrFTopologicalGridOfSurfaces_H
// Module definition for Windows
#include <FrFTopologicalOpe.h>
#include <CATTopOperator.h>

// For interface and Data
// pour CATBoolean
#include <CATMathDef.h>
class CATGeoFactory ;
class CATTopData;
class CATGeometry ;
class CATSurface ;
class CATFrFCompositeCurve ;
class CATBody     ;
class CATCGMJournalList ;
class CATExtruderForGridOfSurfaces ;
class CATSweep ;
#ifndef NULL
#define NULL 0
#endif
//=============================================================================
// Class Definition
//=============================================================================
class ExportedByFrFTopologicalOpe CATFrFTopologicalGridOfSurfaces : public CATTopOperator
{
  public :
/*
  // Default constructor (do not use)
  CATFrFTopologicalGridOfSurfaces() ;
*/
// Constructor from CCVs
  CATFrFTopologicalGridOfSurfaces
            (CATGeoFactory          * iFactory               ,
             CATTopData             * iTopData               ,
             CATFrFCompositeCurve   * iCurvesAlongU          ,
             CATFrFCompositeCurve   * iCurvesAlongV          ,
             int                      iNumberOfSurfacesAlongU,
             int                      iNumberOfSurfacesAlongV,
             // le 1er indice est l'indice en U, le second l'indice en V
             CATSurface           *** iSurfaces) ;
// Constructor from CATBodies
  CATFrFTopologicalGridOfSurfaces
            (CATGeoFactory          * iFactory               ,
             CATTopData             * iTopData               ,
             CATBody                * iCurvesAlongU          ,
             CATBody                * iCurvesAlongV          ,
             int                      iNumberOfSurfacesAlongU,
             int                      iNumberOfSurfacesAlongV,
             // le 1er indice est l'indice en U, le second l'indice en V
             CATSurface           *** iSurfaces              ) ;

  // Execution
  int Run() ;

  // Result request
  CATBody* GetResult() ;
     
  // Destructor
  ~CATFrFTopologicalGridOfSurfaces ();

  private : 
  
  //========================================================================
  // private data
  //========================================================================
  CATGeoFactory               * _Factory         ,
                              * _ImplicitFactory ,
                              * _GeomFactory     ;
  CATCGMJournalList           * _Report          ;
  int                           _CallLevel       ;
  CATFrFCompositeCurve        * _CurvesAlongU    ;
  CATFrFCompositeCurve        * _CurvesAlongV    ;
  CATBody                     * _BodyAlongU      ;
  CATBody                     * _BodyAlongV      ;
  CATBoolean                    _DeleteCurvesBodies ;
  int                           _NumberOfSurfacesAlongU ;
  int                           _NumberOfSurfacesAlongV ;
  // le 1er indice est l'indice en U, le second l'indice en V
  CATSurface                *** _Surfaces        ;
  CATExtruderForGridOfSurfaces* _Extruder        ;
  CATSweep                    * _OperatorCGM     ;

  //========================================================================
  // private methods
  //========================================================================

  // Verification des donnees
  void     InputDataVerification() ;

  // Initialisations
  void     Init() ;

  // Conversion de CCV en body
  void     ConvertCCVToBody
     (CATFrFCompositeCurve*  iCCV ,
      CATBody             *& oBody) ;

  // Conversion de body en CCV
  void ConvertBodyToCCV
     (CATBody             *  iBody,
      CATFrFCompositeCurve*& oCCV ) ;

  // Nettoyage
  void     Clear() ;

  // Check de debug
  void     CheckAll() ;


}  ;


#endif
