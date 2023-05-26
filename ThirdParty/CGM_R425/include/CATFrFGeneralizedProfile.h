// COPYRIGHT DASSAULT SYSTEMES 1998
//==========================================================================
//
// CATFrFGeneralizedProfile:
// Interface class of Profile Object for the Generalized Sweep Operator.
// Profile is Implicit (Segment, Circle, ...) or Explicit (Nurbs Curve)
//
//==========================================================================
//
// Usage notes:
//
//==========================================================================
// Sept 98     Creation                      C.Pradal (CPL)
// Jan  02     Ajout EvalDistance            J.Saloux (JSX)
// Oct  03     CATLONG32->Int et Heritage de FrFVirtual     JSX
// 10/10/03 JSX Passage des CATLONG32 en int
// 15/10/03 JSX Modif Archi heritage de CATFrFObjectVirtual 
// 27/04/04 NLD Eval n'est plus const.
//              Ajout RaiseLastEvalError()
// 21/09/06 NLD Ajout ActivateNextEvalError()
// 27/02/07 NLD Migration vers CATFrFObject au lieu de CATFrFObjectVirtual
// 02/03/07 NLD Suppression du constructeur avec CATFrFConfiguration
//              le constructeur avec CATSoftwareConfiguration devient le defaut
//              et prend un pointeur nul en entree par defaut
// 14/03/07 NLD Le constructeur recoit un CATFrFObject
//              On declare en prive les constructeurs par defaut et par copie
// 09/05/14 NLD Definition des codes d'evaluation CATFrFImplicitProfileResultOption_* 
//              et                                CATFrFExplicitProfileResultOption_*
//==========================================================================
//
#ifndef CATFrFGeneralizedProfile_H
#define CATFrFGeneralizedProfile_H

//
#include "FrFAdvancedObjects.h"
#include "CreateFrFProfile.h"

#include "CATFrFObject.h"

#include "CATListOfCATCurves.h"

class CATGeoFactory;
class CATMathTransformation;
class CATCurve;

class CATFrFConfiguration;

   typedef enum {
                  // Explicit profile cases
                  CATFrFExplicitProfileResultOption_1_XYZTab         = 1,
                  CATFrFExplicitProfileResultOption_2_SetOfPoints    = 2,
                  CATFrFExplicitProfileResultOption_3_SetOfPointsTab = 3,
                  // Implicit profile cases
                  CATFrFImplicitProfileResultOption_1_XYZTab         = 1,
                  CATFrFImplicitProfileResultOption_2_SetOfPoints    = 2,
                  CATFrFImplicitProfileResultOption_3_NurbsMultiForm = 3,
                  CATFrFImplicitProfileResultOption_4_XYZWTab        = 4,
                } CATFrFGeneralizedProfileResultOption;

//-----------------------------------------------------------------------------
class ExportedByFrFAdvancedObjects CATFrFGeneralizedProfile : public CATFrFObject
{
 private :
                      CATFrFGeneralizedProfile();
                      CATFrFGeneralizedProfile(const CATFrFGeneralizedProfile              & iFrFGeneralizedProfile);
 public :

   //                 CATFrFGeneralizedProfile(      CATFrFConfiguration                  *  iFrFConfig            = 0);
                      CATFrFGeneralizedProfile(      CATGeoFactory                        *  iFactory              ,
                                                     CATSoftwareConfiguration             *  iConfig               = 0);
   //                 CATFrFGeneralizedProfile(      CATFrFObject                          & iFrFObject            );
   virtual           ~CATFrFGeneralizedProfile();

   // Profile evaluator at the param iT
   // iOption indicate the Type of oResult
   // oResult have to be already allocated.
   //   if this is an Explicit Profile (CATFrFProfile):
   //     iOption=1 => oResult have to be a double*
   //     iOption=2 => oResult have to be a CATMathSetOfPoints*
   //     iOption=3 => oResult have to be a CATMathSetOfPoints**
   //
   //   if this is an Implicit Profile (CATFrFImplicitProfile):
   //     iOption=1 => oResult have to be a double*               pour chaque point: coordonnees
   //     iOption=2 => oResult have to be a CATMathSetOfPoints*
   //     iOption=3 => oResult have to be a CATNurbsMultiForm*[1]
   //     iOption=4 => oResult have to be a double*               pour chaque point: coordonnees + poids (special cercle/conique, cas rationnel)
   //                                                            (Ajout documentation option 4       NLD090514)

   // Attention neanmoins a des bizarreries de codage dans CATFrFSweepCanonicProfileCx2::EvalDebug() NLD090514
   // Il semble que l'on puisse recevoir une combinaison d'une de ces valeurs et d'un multiple de 10
   // voir CATFrFBlendProfileCx2::Eval() pour le decodage


   virtual CATBoolean Eval                    (      double                                  iT                    ,
                                                     CATMathTransformation                *  iLocalFrame           ,
                                                     int                                     iOption               , // plus ou moins de type CATFrFGeneralizedProfileResultOption
                                                     void                                 *  oResult               )       = 0;
   // Activates error creation if error in next eval (will not be raised; use RaiseLastEvalError())
   virtual void       ActivateNextEvalError   ()                                                                           = 0;
   // Raises, if any, the error relative to last Eval
   virtual void       RaiseLastEvalError      ()                                                                           = 0;

   virtual CATBoolean IsEvalDistanceAvailable ()                                                                           = 0;
   virtual double     EvalDistance            (      double                                  iT                    ,
                                                     CATMathTransformation                *  iLocalFrame           ,
                                                     int                                     iNearProfileIsSet     ,
                                               const double                               *  iNearProfile          )       = 0;
   virtual void       SetEvalDistanceTolerance(      double                                  iTol              [3] )       = 0;

   virtual int        GetNumberOfSegments     ()                                                                     const = 0;
   virtual CATCurve * GetOneCurve             (      int                                     iIndex                )       = 0;
   virtual int        GetNumberOfPoints       ()                                                                     const = 0;

};
#endif

