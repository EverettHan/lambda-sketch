// COPYRIGHT DASSAULT SYSTEMES 1997
//==========================================================================
//
// CATFrFProfile:
// Interface class of Profile Object for the Generalized Sweep Operator.
//
//==========================================================================
//
// Usage notes:
//
//==========================================================================
//   May 97 TPG Creation                                             T.Phung
// 23/02/99 NLD Ajout GetOnecurve
// 05/03/99 CPL Ajout GetOnecurve
// 07/09/99 CPL Ajout Set Get BreakInfo 
// 24/10/02 NLD Ajout iTolerance a ComputeIntersectAxis() (modif du 01/08/02)
// 03/06/03 NDN Ajout de la methode IsPlanar.
// 10/10/03 JSX Passage des CATLONG32 en int
// 15/10/03 JSX Modif Archi heritage de CATFrFObjectVirtual
// 02/06/04 NLD Ajout GetOneCrvLimits()
// 08/11/04 NLD On autorise et documente l'absence de guide dans 
//              ComputeIntersectAxis() et ComputeMinDistanceAxis()
// 14/03/07 NLD Le constructeur recoit un CATFrFObject
// 28/01/10 JSX Ajout de GetNumberOfCurvatures et ICurvatureMode dans Set/GetTangency
// 02/10/12 NLD Documentation du nouveau diagnostic -1 pour quasi lines dans GetInertiaAxis()
// 01/08/14 NLD Smart indent
//              Mise en conformite de la presentation avec CATFrFProfileCx2
//==========================================================================
//
#ifndef CATFrFProfile_H
#define CATFrFProfile_H
//
#include <CATFrFGeneralizedProfile.h>

class CATNurbsCurve;
class CATFrFNurbsMultiForm;
class CATFrFCompositeCurve;
class CATFrFMovingFrame;
class CATGeoFactory;
class CATMathSetOfPoints;
class CATMathTransformation;
class CATMathAxis;
class CATMathPlane;
class CATMathPoint;
class CATMathVector;
class CATMathLine;
class CATFrFCCvParam;
class CATBreakInfo;
class CATCurve;
#include <CATCrvLimits.h>

//-----------------------------------------------------------------------------
class ExportedByFrFAdvancedObjects CATFrFProfile : public CATFrFGeneralizedProfile
{
 public :

                                                            CATFrFProfile            (      CATGeoFactory                 *  iFactory        ,
                                                                                            CATSoftwareConfiguration      *  iConfig         = 0);
             //                                             CATFrFProfile            (      CATFrFObject                   & iFrFObject      );

     virtual                                               ~CATFrFProfile            ()       ;

    // 1) Derivation des methodes de CATFrFGeneralizedProfile
    //    ---------------------------------------------------
             // Get one Init Curve
     virtual CATCurve                                     * GetOneCurve              (      int                              iIndex          )         = 0;

    // 2) Methodes specifiques
    //    --------------------
             // Get one segment
     virtual CATFrFNurbsMultiForm                         * GetOneSegment            (      int                              iIndex          )   const = 0;


             // Get one Init Curve limits
     virtual CATCrvLimits                                   GetOneCrvLimits          (      int                              iIndex          )         = 0;

             // Get Initial Ccv
     virtual CATFrFCompositeCurve                         * GetInitCcv               ()                                                          const = 0;


             // Get Local Axis
     virtual CATMathAxis                                  * GetAxis                  ()                                                          const = 0;

             // Get Mean Plane
     virtual CATMathPlane                                 * GetPlane                 ()                                                          const = 0;

             // Get  Points
     virtual void                                           GetPoints                (      CATMathPoint                  *  ioPoints        )   const = 0;


             // Set Init Curves
     virtual void                                           SetCurves                (      CATCurve                     **  iCurves         ,
                                                                                            int                              iNbCrv          )         = 0;

             // Set Local Axis
     virtual void                                           SetAxis                  (      CATMathAxis                   *  iAxis           )         = 0;

 ///////////////////
 // Profile Position
 ///////////////////

             // Compute Local Axis by intersection between Plan Profile & guide
             // Special computation using moving frame spine if no guide provided
     virtual CATBoolean                                     ComputeIntersectAxis     (      CATGeoFactory                 *  iFactory        ,
                                                                                            CATFrFCompositeCurve          *  iGuide          ,
                                                                                            CATFrFMovingFrame             *  iMF             )         = 0;
             // Compute Local Axis by intersection between Plan Profile & guide
             // Special computation using moving frame spine if no guide provided
             // oParam is a Global parameter
     virtual CATBoolean                                     ComputeIntersectAxis     (      CATGeoFactory                 *  iFactory        ,
                                                                                            CATFrFCompositeCurve          *  iGuide          ,
                                                                                            CATFrFMovingFrame             *  iMF             ,
                                                                                            double                         & oParam          ,
                                                                                            double                        *  iTolerance      = NULL)   = 0;
             // Compute Local Axis by MinDist between Profile & guide
             // oParam is a Global parameter
             // Special computation using moving frame spine if no guide provided
     virtual CATBoolean                                     ComputeMinDistanceAxis   (      CATGeoFactory                *  iFactory        ,
                                                                                            CATFrFCompositeCurve         *  iGuide          ,
                                                                                            CATFrFMovingFrame            *  iMF             ,
                                                                                            double                        & oParam          )          = 0;
             // Compute Local Axis & Parameter on Spine by MinDist between Profile & guide
             // oParam is a Global parameter
     virtual CATBoolean                                     ComputeProjectAxis       (      CATGeoFactory                *  iFactory        ,
                                                                                            CATFrFCompositeCurve         *  iGuide          ,
                                                                                            CATFrFMovingFrame            *  iMF             ,
                                                                                            CATFrFCCvParam                & oParamOnSpine   ,
                                                                                            CATFrFCCvParam                & oParamOnGuide   )          = 0;

             // P0: first point & P1 is the last point
             // Z: Normal vector to Plan Profile
             // X: P1-P0
             // if P0 & P1 are equal, X: Tgte(P1)
     virtual void                                           ComputeDefaultAxis       ()                                                                = 0;

 ///////////////////

             // Append one segment
     virtual void                                           Append                   (      CATNurbsCurve                *  iSegment        )          = 0;

             // Getting a parameter on the Nurbs Curve corresponding to a given
             // parameter on the profile curve
     virtual void                                           ComputeNewParameter      (const CATFrFCCvParam                & iParam          ,
                                                                                            CATFrFCCvParam                & oParam          )          = 0; 

             // Apply transformation on each segments.
             // oPoints is already allocated but not oPoints[i]
     virtual void                                           ApplyTransformation      (      CATMathTransformation        *  iTransfo        ,
                                                                                            CATMathSetOfPoints          **  oPoints         )    const = 0;

             // Apply transformation on each segments.
             // oPoints is already allocated
     virtual void                                           ApplyTransformation      (      CATMathTransformation        *  iTransfo        ,
                                                                                            CATMathSetOfPoints           *  oPoints         )    const = 0;
             // Apply transformation on each segments.
             // oPoints is already allocated
     virtual void                                           ApplyTransformation      (      CATMathTransformation        *  iTransfo        ,
                                                                                            double                       *  oPoints         )    const = 0;

    /////////////////
    //  Sweep Crv/Crv
    /////////////////


             // Profile Generalized parameter
     virtual double                                         GetParameter             ()                                                          const = 0;
     virtual void                                           SetParameter             (      double                           iParam         )          = 0;

             // return the position of each point
             // (between which and which guide the point is located)
     virtual int                                          * GetTransfoIndex          ()                                                          const = 0;

             // iIndex[i] < nbGuides
     virtual void                                           SetTransfoIndex          (      int                           *  iIndex         )          = 0;

             // ultratempo ......
     virtual void                                           ComputeNbPts             ()                                                                = 0;

     virtual CATMathPoint                                   GetStartPoint            ()                                                          const = 0;
     virtual CATMathPoint                                   GetEndPoint              ()                                                          const = 0;

     virtual void                                           SetStartPoint            (const CATMathPoint                   & iStartPt       )          = 0;
     virtual void                                           SetEndPoint              (const CATMathPoint                   & iEndPt         )          = 0;

             // Compute Inertia Axis of Control Points
             // return 0 if Diagnosis= Point, Space
             // return 1 if Diagnosis= Line          (and -1 for some quasi line cases; NLD021012)
             // return 2 if Diagnosis= Plane
     virtual int                                            GetInertiaAxis           (      CATMathAxis                    & ioInertiaAxis  )          = 0;


 // Set & Get Tangent (CrvCrv)
             // Imposition du peigne de tangence homogeneise
             // 
             // Notes sur les cycles de vie, d'apres l'implementation:dans CATFrFProfileCx2. NLD070814
             // - le tableau iNurbs[] reste propriete de l'appelant, mais peut etre detruit sitot apres l'appel
             //   (on en fait une copie locale)
             // - chacun des elements iNurbs[*] devient la propriete de cet objet,
             //   et sera detruit par son destructeur
     virtual void                                           SetTangency              (      CATFrFNurbsMultiForm         **  iNurbs         ,
                                                                                            int                              iNbNurbs       ,
                                                                                            CATLONG32                        ICurvatureMode )          = 0;

             // Get Tangent / Curvatures
     virtual int                                            GetNumberOfTangents      ()                                                          const = 0;

     virtual int                                            GetNumberOfCurvatures    ()                                                          const = 0;

     virtual void                                           GetTangents              (      CATMathLine                   *  ioTangents     )    const = 0;

     virtual void                                           GetTangents              (      CATMathPoint                  *  ioPoints1      ,
                                                                                            CATMathPoint                  *  ioPoints2      ,
                                                                                            CATLONG32                        iCurvatureMode = 0) const = 0;
     virtual CATBoolean                                     GetTangents              (      double                        *  ioTangents     )    const = 0;



             // Set & Get BreakInfo
     virtual void                                           SetBreakInfo             (      CATBreakInfo                 **  iBreakInfo     ,
                                                                                            int                              iNbElt         )          = 0;

     virtual void                                           GetBreakInfo             (      CATBreakInfo                 **& oBreakInfo     ,
                                                                                            int                            & oNbElt         )    const = 0;

            // Set & Get CGMLevel ==> Declare dans CATFrfObjectVirtual
  // virtual void                                           SetCGMLevel              (      int                              iCGMLevel      )          = 0;
  // virtual int                                            GetCGMLevel              ()                                                          const = 0;

             // Profile is Planar then return code value is 1,
             //            Linear then r.c.                 2,
             // Else                   r.c.                 0 (means profile is truely 3D).
     virtual int                                            IsPlanar                 ()                                                          const = 0;

};
#endif

