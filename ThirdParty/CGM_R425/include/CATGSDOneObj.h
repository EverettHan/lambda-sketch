/*-*-c++-*-*/
//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 1999
//=============================================================================
//
// CATGSDOneObj :
// Implementation class for global deformation of one obj. 
//
//=============================================================================
// Usage notes:
// sample of use :
// to provide
//
//=============================================================================
// July  99 Dr,DJn Creation                          Daniel Roudil et Johansson
// Dec   02 DJn Preview                                        Daniel Johansson
// 13/02/19 NLD Mise au propre
//=============================================================================

#ifndef CATGSDOneObj_H  
#define CATGSDOneObj_H 

#include "CATGSDOneObj.h"
#include "CATMathGridOfPoints.h"
#include "CATMathGridOfVectors.h"
#include "CATNurbsSurface.h"
#include "CATNurbsCurve.h"
#include "CATMathPoint.h"
#include "CATKnotVector.h"
#include "CATMath3x3Matrix.h" 
#include "CATMathMxNMatrix.h"
#include "CATMathMxNBandMatrix.h"
#include "CATMathMxNFullMatrix.h"
#include "CATMathNxNMatrix.h"
#include "CATMathVector.h"
#include "CATMathDirection.h"
#include "CATFrFUtiNurbs.h"
#include "CATGeometry.h"
#include "CATGSDBase.h"
#include "CATCGMVirtual.h"

class ExportedByFrFOpeSur CATGSDOneObj : public CATCGMVirtual

{
public:
        
        /* Construktor */
        
        CATGSDOneObj (CATGSDBase        *AnaOpe, 
                      CATLONG32          nrOfSynOpe, 
                      CATGSDBase       **SynOpe, 
                      CATGeometry       *Geometry,   
                      CATLONG32          indexSynOpe = 0 ) ; 
        
        /* Destruktor */
        
        virtual ~CATGSDOneObj () ;
        
        /* Run */
        
        CATLONG32 Run () ;  // returns 1 if ok, else 0. 

        /* The preview must be activated before first call of Run(). Only for surfaces! */

        void SetPreview()
        {
           _preview = 1 ; 
        }; 

        /* To avoid repeated grid allocations, give an array of four pointers.
        Use: "CATMathGridOfPoints *MYGRIDS[4] = { NULL, NULL, NULL, NULL } ;". Then,
        use this set-method to all analysis operators working on surfaces. The four
        grids will be allocated once. Delete each of MYGRIDS after final use. */

        void SetExternalGrids( CATMathGridOfPoints **ExternGrids ) ; 
        
        /* By default, number of grid points = number of control points.
        this sets extra points in between: */
        
        void SetMoreDenseGrid( CATLONG32 extraU, CATLONG32 extraV )
        {
            _extraU = extraU ; _extraV = extraV ; 
        } ; 
        
        /* If other SynOpe, given in the constructor, is to be used */
        
        void ChangeIndexOfSynOpe ( CATLONG32 indexSynOpe )
        {
            _indSynOpe = indexSynOpe ; 
        } ;
        

        /* If the object shall be transformed even if it is partially beside
        the transformation domain */

    void PartiallyTransformed ( CATLONG32 yes )
        { _PartiallyTransformed = yes ; } ;

        /* If the result is to be analyzed: */

    void AnalyzeResult ( CATLONG32 yes )
        {
           _AnalyzeResult = yes ; 
        } ;

        /*        Diagnosis of result: maxErr is maximal POINT deviation (see "AnalyzeResult"),  
                all  = 1 means that all points are transformed (see "PartiallyTransformed").           
                none = 1 means that no point is transformed and the patch is unchanged. */
        
        void Diagnosis ( double &maxErr, CATLONG32 &all, CATLONG32 &none )
        {
           maxErr = _ERR ; all = _all ; none = _none ; 
        } ;

        void Diagnosis ( double &maxErr )
        {
           maxErr = _ERR ; 
        } ;

        /*  Pointwise diagnosis of transfosmation success (1) or not (0).
                oAll  = 1 if all of oBOOLA and all of oBOOLS are one. 
                oNone = 1 if all of oBOOLS are zero. 
            oBOOLA: Analysis success 
            oBOOLS: Analysis success and Synthesis success.
                The booleran elements correspond to a parameter grid of size 
                oNbU x oNbV in an obvious way, where oNbV is considered to be 
                one in case of curve transformation.
                The arrays belongs to "this" object and may not be deleted!
        */
        void Diagnosis (               CATLONG32    & oAll,
                                       CATLONG32    & oNone,
                                       CATLONG32    & oNbBOOL,
                        const unsigned int         *& oBOOLA,
                        const unsigned int         *& oBOOLS,
                                       CATLONG32      &oNbU,
                        const          double      *& oParU ) ;

        void Diagnosis (               CATLONG32    & oAll,
                                       CATLONG32    & oNone,
                                       CATLONG32    & oNbBOOL,
                        const unsigned int         *& oBOOLA,
                        const unsigned int         *& oBOOLS,
                                       CATLONG32    & oNbU,
                        const double               *& oParU,
                                       CATLONG32    & oNbV,
                        const double               *& oParV ) ;

        // -------------------------------------------------------------------------
        
private:
        
        CATGeoFactory    * _Factory;
        CATNurbsSurface  * _NurbSur ; 
        CATNurbsCurve    * _NurbCrv ; 
        CATGSDBase       * _AnaOpe,
                        ** _SynOpe ; 
        CATLONG32          _all,
                           _none,
                           _nU,
                           _nV,
                           _nCPU,
                           _nCPV,
                           _extraU,
                           _extraV,
                           _AnalysisIsDone ;
        CATLONG32          _nrSynOpe,
                           _indSynOpe,
                           _CaseSurf,
                           _CaseCurve,
                           _preview ; 
        CATLONG32          _PartiallyTransformed,
                           _AnalyzeResult ;
        double           * _ArrayOfhAII,
                         * _ArrayOfhAu,
                         * _ArrayOfhAv,
                         * _ParU,
                         * _ParV,
                           _ERR ;
        CATMathDirection * _ArrayOfWA,
                         * _ArrayOfNA ;
        CATMathVector    * _ArrayOfWAu,
                         * _ArrayOfWAv,
                         * _ArrayOfNAu,
                         * _ArrayOfNAv ;
        CATMathVector    * _ArrayOfPs,
                         * _ArrayOfPt ;
        CATMath3x3Matrix * _ArrayOfAxes ; 
        CATMathPoint     * _ArrayOfUVW,
                         * _ArrayOfP,
                         * _ArrayOfTrP ; 
        CATMathMxNMatrix * _MakeCrvU,
                         * _MakeCrvV,
                         * _CrossU,
                         * _CrossV ;

        unsigned int     * _BOOLA,
                         * _BOOLS ;
        CATMathGridOfPoints ** _ExtGrids ;
        CATKnotVector      _KVU,
                           _KVV ;
        /* Allocatiotion of grids, arrays and matrices: */
        
        void Allocations() ; 
        
        /* Create matrix to set control points of a curve: */
        
        void MatCrvDef (const CATLONG32 nU, 
                        const CATLONG32 nCP,
                        const CATKnotVector *KV,
                              double *par ,
                        const double scale ,
                              CATMathMxNMatrix *MatCrv ) ; 
        
        /* Discretize the curve and create the matrix setting control points */ 
        
        void InitializeAllForCurve () ; 
        
        /* Transform the arrays and make new curve */
        
        CATLONG32 TransformGridAndMakeNewCurve () ; 
        
        /* additional metod for surfaces: This method create matrixes  
        used to evaluate approximated cross derivatives:*/
        
        void InitCrossMat(const CATLONG32         iNbPar, 
                                          double           * iPar,
                                          const double       iScale, 
                                          CATMathMxNMatrix * ioCrossMat ) ;

        /* for preview work */                                                                
        void InitPointMat(const CATLONG32         iNbPar, 
                              double           * iPar,
                              CATKnotVector    * iKV,
                              CATMathMxNMatrix * ioPointMat ) ;

        /* Discretize the surface and run "InitAllMatrices()" */ 
        
        void InitializeAllForSurf () ; 
        
        /* Transform the arrays and make new surface */
        
        CATLONG32 TransformGridAndMakeNewSurf () ; 
        
        /* parameter grid from a knot vector: */
        
        void ParamGrid (const CATKnotVector *KV,
                              double        *pGrid,
                              CATLONG32      NrBetween )  ;
        
                /* Inverse using SVD. "tol" sets smallest used singular value
        related to the biggest: */
        
        void InverseSVD (CATMathMxNMatrix *A,
                double tol = 0.0 ) ;
        
};

#endif
