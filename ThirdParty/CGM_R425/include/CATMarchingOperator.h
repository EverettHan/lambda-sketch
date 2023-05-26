// COPYRIGHT DASSAULT SYSTEMES 1997 
//==========================================================================
//
// CATMarchingOperator:
// Interface class of FrF Marching Operator.
//
//==========================================================================
//
// Usage notes:
// This class can be used as is for simple Marching Operator or derived
// in order to implement specific algorithm or capabilities.
//
// Operator must be created through CreateMarchingOperator()
// Then software configuration must be set trough SetSoftwareConfiguration()
//                                                                 NLD040516
//
//========================================================================== 
//   May 97 tpg Creation                                          Tuan Phung
//   /07/03 JSX Derive directement de CGMVirtual
// 07/11/05 NLD Derive de CATFrFObjectVirtual
//              SetSoftwareConfiguration() n'est plus definie ici
// 27/02/07 NLD : Migration vers CATFrFObject au lieu de CATFrFObjectVirtual
// 23/09/09 JSX : Utilisation de nom de methode plus specifique au marching
//                a migrer en local interfaces !
// 09/12/09 NLD Definition de nomenclature pour les #define partages:
//              TestPrecision devient CATMarchingOperator_TestPrecision
// 05/11/10 NLD Ajout SetProgressBar()
// 04/05/16 NLD Smart indent
// 04/01/19 JSX Ajout SetKeepShapeParams
// 20/02/19 JSX Ajout SetMaxNumberOfPatches
//========================================================================== 

#ifndef CATMarchingOperator_H
#define CATMarchingOperator_H

//#define CATMarchingOperator_TestPrecision // JSX DEBUG Teste la precision du resultat 


#include "FrFAdvancedOpeSur.h"

#include "CreateMarchingOperator.h"
#include "CATMathVectorialFunctionX.h"
#include "CATMathDef.h"
#include "CATFrFObject.h"


class CATFrFNurbsMultiForm;
class CATMathAttrPointerValue;
class CATMathSetOfPointsND;
class CATFrFShapeResult;
class CATSurface;
class CATSoftwareConfiguration;
class CATCGMProgressBar;
//-----------------------------------------------------------------------------
class ExportedByFrFAdvancedOpeSur CATMarchingOperator : public CATFrFObject
{
  public :
//
// Constructor
  CATMarchingOperator();
//
// Destructor
  virtual ~CATMarchingOperator();

// Progress bar
  virtual void                    SetProgressBar                    (      CATCGMProgressBar         *  iProgressBar             )        = 0;

// Set Blend Mode -> Utilisation de poids pour les pon,ts G1 et G2
  virtual void                    SetBlendMode_DEPRECATED           ()                                                           = 0;

// Set du mode FSS (suplementaire au mode blend) poids G1 en fonction de la distance ptG0 ptG1 
  virtual void                    SetFSSBlendMode_DEPRECATED        ()                                                           = 0;

// Tol used in Blend Mode Only Default is Factoy->GetResolution();
  virtual void                    SetToleranceForSurfaceConstruction(      double                       iTolSurface              ,
                                                                           double                       iTolSurG1                = 0.1*CATDegreeToRadian
                                                                    ) = 0;

// Set Max Number Of patches
  virtual void                    SetMaxNumberOfPatches             (      int                          iMaxNumberOfPatches)              = 0;

//
//
// Get Result
//
  virtual CATFrFNurbsMultiForm ** GetCubicResult                    (      int                        & oNumberOfNurbsMultiForms )        = 0; 
//
  virtual CATFrFShapeResult     * GetCubicResult                    ()                                                                    = 0; 
//
// Get QuinticResult (Nurbs Interpolation) 
//
  virtual CATFrFShapeResult     * GetQuinticResult                  ()                                                                    = 0;
//
// GetParams Get the parametrization used for calculated discretized points
// !! it will be deleted when ~CATMarchingOperator() will be called
// 
  virtual CATMathSetOfPointsND  * GetMarchingParams                 ()                                                              const = 0;

//  ATTENTION.                                      NLD040516
// - l'implementation actuelle ne gere qu'un appel
// - l'attribut sera passe au sampling de CATMathVectorialFunctionX::Sample
//   (dont on consultera la documentation pour connaitre la liste des attributs autorises)
// - l'attribut CATMathAttrRepartition ne doit pas etre utilise car il est defini en interne
// 
  virtual void                    SetAttribute                      (const CATMathAttrPointerValue *  AttrPtVal                  ) = 0;
//
  virtual void                    SetOverSampling                   (      int                        iOverSampling              ) = 0;
//
  virtual void                    SetMarchingLevel_DEPRECATED       (      int                        iLevel                     ) = 0;
//
//
  virtual void                    SetDiscontinuityMode              (      int                        iMode                      ) = 0;

// Keep the parametrization of the shape ( expect of a shift , first param is always 0.0)
  virtual void                    SetKeepShapeParams                (      CATBoolean                 iKeepShapeParams           ) = 0;

//
  virtual CATLONG32               GetDiagnostic                     ()                                                             = 0;
  
  virtual void                    SetActivDomain                    (const CATListOfInt             & iActivDomains              ) = 0;
  
  virtual void                    GetActivDomain                    (      CATListOfInt             & iActivDomains              ,
                                                                           int                      & oModeMarching              ) = 0;

#ifdef  CATMarchingOperator_TestPrecision
// DEBUG et TEST : A ne pas utiliser en Officiel
//
// Test de la precison de la nurbs interpolant la surface decrite par le marching 
//
//   
  virtual double                  TestResultSurfacePrecision        (      CATSurface              *  iSurface                   ,
                                                                           int                        iNumDom                    ,
                                                                           int                        iNumSur                    ) = 0;

  virtual void                    Verif                             (      CATMathSetOfPointsND    *  Param                      ,
                                                                           CATMathSetOfPointsND    *  Point                      , 
                                                                           CATMathSetOfPointsND    *  Tang                       , 
                                                                           CATMathSetOfPointsND    *  SecondD                    , 
                                                                           CATSurface              *  iSurface                   ,
                                                                           int                        iNumDom                    ,
                                                                           int                        iNumSur                    ) = 0;
#endif
};

#endif
