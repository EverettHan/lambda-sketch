// COPYRIGHT DASSAULT SYSTEMES 1997
//==========================================================================
//
// CATFrFGeneratingShape:
// Interface class of FrF Generating Shape Object.
// Evaluate cross sections.
//
//==========================================================================
//
// Usage notes:
// This class can be used as is for simple Shape or derived
// in order to implement specific algorithm or capabilities.
//
//==========================================================================
//   Mar 98 cpl Creation                                   Christophe Pradal
//   Mar 99 cpl GetFirstDeriv
//   Apr 99 cpl IsRational
//              EvalRational
//   Dec 00 cpl GetTotalLength
//   Jun 00 cpl SetFastEval
//   Apr 01 cpl GetImposedParameter
//   Dec 01 JSX EvalDistance
//   mar 02 JSX Set/GetCGMLevel
//   Oct 03 JSX Derivation de CATFrFObjectVirtual  
//              Conversion partielle de long en int
// 08 06 05 NLD Ajout DataForNextEval() reciproque de DataFromLastEval()
// 27/02/07 NLD Migration vers CATFrFObject au lieu de CATFrFObjectVirtual
// 04 02 08 JSX Ajout argument CATFrFObject au constructeur
// 02 09 09 JSX Ajout GetPrecomputedParams
// 11 09 09 JSX GetFastEvalInfo remplace IsFastEval
// 17 09 11 JSX Ajout GetDiscernment
// 20/11/15 NLD Details d'utilisation de SetFastEval()
// 04/12/15 NLD Smart indent
//              XScale: details de specifications pour SetToleranceForEvalDistance()
//==========================================================================

#ifndef CATFrFGeneratingShape_H
#define CATFrFGeneratingShape_H

#include "FrFAdvancedObjects.h"

#include "CATMathDef.h"
#include "CATListOfInt.h"
#include "CATListOfDouble.h"
#include "CATFrFObject.h"

class CATMathSetOfPoints;
class CATMathSetOfPointsND;
class CATMathSetOfVectors;
class CATMathInterval;
class CATFrFCoupling;
class CATFrFMovingFrame;
class CATFrFSetOfGuides;
class CATFrFSetOfBaseCurves;
class CATFrFShapeConstraint;
class CATFrFProfile;
class CATFrFNurbsMultiForm;
class CATCurve;
class CATGeoFactory;
class CATMathTransformation;
class CATFrFShapeResult;

//-----------------------------------------------------------------------------
class ExportedByFrFAdvancedObjects CATFrFGeneratingShape : public CATFrFObject
{
private:
  CATFrFGeneratingShape();
protected :
  CATFrFGeneratingShape(CATFrFObject *iCATFrFObject);

public :

  
  virtual ~CATFrFGeneratingShape();

  //----------------------
  //  Get & Set Attributes
  //----------------------

  virtual double                   GetTotalLength()                                                                       const = 0;

  //
  // Coupling 
  virtual void                     SetCoupling   (                   CATFrFCoupling         *  iCoupling                )       = 0;
  virtual CATFrFCoupling         * GetCoupling   ()                                                                       const = 0;

  //
  // Moving Frame
  virtual void                     SetMovingFrame             (      CATFrFMovingFrame      *  iMovingFrame             )       = 0;
  virtual CATFrFMovingFrame      * GetMovingFrame             ()                                                                = 0;

  //
  // ShapeConstraint :
  // all the constraints on 1 Geometry
  // It contains angular Laws, radius law, continuity, orientation...
  virtual CATLONG32                GetNumberOfShapeConstraints()                                                          const = 0;
  virtual CATFrFShapeConstraint  * GetShapeConstraints        (const CATLONG32                 iShapeConstraintIndex    ) const = 0;
  virtual CATFrFShapeConstraint ** GetShapeConstraints        ()                                                          const = 0;
  virtual void                     SetShapeConstraints        (      CATLONG32                 iNumberOfShapeConstraints,
                                                                     CATFrFShapeConstraint **  IConstraints             )       = 0;


  // Get Caracteristic points Continuity
  // 0 out
  // 1 C0 (contact with Guides)
  // 2 C1, ...
  virtual CATBoolean               GetConstraintArray         (      int                    *& ioPointsContinuity, 
                                                                     int                     & ioNbPoints               )       = 0;

  //
  // Specific parameter
  virtual void                     GetImposedParameter        (      CATListOfDouble         & ioParams                 )       = 0;
  virtual void                     GetContinuityParams        (      int                       iContinuityLevel         ,
                                                                     int                       iDom                     ,
                                                                     CATListOfDouble         & oParams                  ,
                                                                     CATListOfInt            & oNumDom                  )       = 0;
  // Some params have been already computed
  virtual void                     GetPrecomputedParams       (      CATListOfDouble         & PrecomputedParams        )       = 0;

  //
  // Domains Of GeneratingShape ( used by Marching Operator )
  virtual CATLONG32                GetNumberOfDomains         ()                                                          const = 0;
  virtual CATMathInterval        * GetOneDomain               (      CATLONG32                 iIndex                   ) const = 0;
  virtual void                     SetDomains                 (      CATMathInterval        *  iDomains                 ,
                                                                     CATLONG32                 iNbDomains               )       = 0;
  virtual void                     SetDomains                 (      CATLONG32                 iNbDomains               ,
                                                                     CATMathInterval        *  iDomains                 ,
                                                                     CATLONG32              *  iStartCrvIndex           ,
                                                                     CATLONG32              *  iEndCrvIndex             )       = 0;
  virtual void                     SetWorkingDomain           (      CATLONG32                 iIndex                   )       = 0;
  virtual CATLONG32                GetWorkingDomain           ()                                                          const = 0;

  // number of CROSS surfaces
  virtual CATLONG32                GetNumberOfSurfaces        ()                                                          const = 0;

  
  
  //-----------------
  // Pseudo Operators
  //-----------------
  // Calculation of one section
  // The result is an array of nbSurfaces elements.
  // Each NurbsMultiForm contains just one form.
  virtual CATFrFNurbsMultiForm  ** GetProfile                 (const double                    iT                       ) const = 0;

  // Calculation of N sections. N= number of parameters in IParams
  virtual CATFrFShapeResult      * GetSection                 (const CATMathSetOfPointsND   *  iParams                  ) const = 0;

  // Calculation of M Result : M = number of domains (iParam [M])
  virtual CATFrFShapeResult      * GetSection                 (      CATMathSetOfPointsND  **  iParams                  )       = 0;


  //--------------------------
  //  Eval discretized Profile
  //--------------------------

  // Points of define profile
  virtual CATLONG32                GetNumberOfPoints          ()                                                          const = 0;

  // 0        : disable
  // 1, 2, ...: enable with special eval code depending on shape type
  // - Loft
  //            1 : Eval without sketcher in variational sweep
  //            1 : Eval without area law in loft
  // - Blend
  //            1, 2, ...: Special Blend Eval options, see CATFrFImplicitProfile. NLD201115
  virtual void                     SetFastEval                (      CATLONG32                 iEvalMode                )       = 0;
  virtual void                     GetFastEvalInfo            (      CATLONG32               & oNbOfEvalMode            ,
                                                                     CATLONG32               & oCurrentEvalMode         ,
                                                                     CATLONG32               & oCompletEvalCost         ) const = 0;

  // Donne le discernement de la shape
  // Generalement parfait  oPerfect=1 ce qui correspond a oShapeDiscernment=0.
  // Quand la shape fait appel a un solver, 2 evaluations proches peuvent etre confondues (faussent les derivées par differences finies)
  virtual void                     GetDiscernment             (      CATLONG32               & oPerfect                 ,
                                                                     double                  & oShapeDiscernment        ) const = 0;

  // oPt, oDer1, oDer2 are already allocated
  virtual void                     Eval                       (      double                    iT                       ,
                                                                     CATMathSetOfPoints     *  oPt                      ) const = 0;
  virtual void                     Eval                       (      double                    iT                       ,
                                                                     double                 *  oPt                      ) const = 0;

  virtual CATBoolean               EvalFirstDeriv             (      double                    iT                       ,
                                                                     CATMathSetOfVectors    *  oDer1                    ) const = 0;
  virtual CATBoolean               EvalFirstDeriv             (      double                    iT                       ,
                                                                     double                 *  oDer1                    ) const = 0;

  virtual CATBoolean               EvalSecondDeriv            (      double                    iT                       ,
                                                                     CATMathSetOfVectors    *  oDer2                    ) const = 0;
  virtual CATBoolean               EvalSecondDeriv            (      double                    iT                       ,
                                                                     double                 *  oDer2                    ) const = 0;

  virtual CATBoolean               IsEvalFirstDerivAvailable  ()                                                          const = 0;
  virtual CATBoolean               IsEvalSecondDerivAvailable ()                                                          const = 0;

  virtual CATBoolean               IsRational                 ()                                                          const = 0;
  virtual void                     EvalRational               (      double                    iT                       ,
                                                                     double                 *  oPt                      ) const = 0;

  // ATTENTION: (commentaires NLD201115 puis NLD041215)
  // EvalDistance() rend une distance relative (un ratio de qualite)
  // mais ses tolerances ne sont pas relatives et peuvent dependre de l'echelle
  // (Tol[0] est une tolerance en point    dependant  de l'echelle)
  // (Tol[1] est une tolerance angulaire independante de l'echelle) (en radian)
  // (Tol[2] n'a pas d'usage au 0412415 semble-t-il)
  virtual CATBoolean               IsEvalDistanceAvailable    ()                                                          const = 0;
  virtual CATBoolean               SetToleranceForEvalDistance(      double                    Tol[3]                   )       = 0;
  virtual double                   EvalDistance               (      double                    iT                       ,
                                                                     int                       iIsSet                   ,
                                                               const double                 *  iNearShape               ) const = 0;

  // Ca c'est pour imposer des donnees a la prochaine évaluation,
  // et chaque shape dérivée l'implémente à sa manière
  // avec la signification qu'elle veut pour les iDataIndex, et pour les
  // valeurs de sortie. NLD080605 reciproque de DataFromLastEval
  // utilisations specifiques existant pour Loft et pour Blend, a la date du 20/11/15
  virtual void                     DataForNextEval            (      int                       iDataIndex               ,
                                                                     CATLONG32              *  iTLong                   ,
                                                                     double                 *  iTDouble                 ) = 0;
  // Ca c'est pour recuperer des donnees de la dernière évaluation,
  // et chaque shape dérivée l'implémente à sa manière
  // avec la signification qu'elle veut pour les iDataIndex, et pour les
  // valeurs de sortie. NLD020704. Création de la méthode: JSX pour mesure d'aire du loft
  // utilisations specifiques existant pour Loft et pour Blend, a la date du 20/11/15
  virtual void                     DataFromLastEval           (       int                      iDataIndex               ,
                                                                      CATLONG32             *  oTLong                   ,
                                                                      double                *  oTDouble                 ) = 0;


  };

#endif



