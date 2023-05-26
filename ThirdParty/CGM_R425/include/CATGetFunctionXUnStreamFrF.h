/* -*-c++-*- */
#ifndef CATGetFunctionXUnStreamFrF_h
#define CATGetFunctionXUnStreamFrF_h

// #define CATGetFunctionXUnStreamFrF_AddLawEquationFunctions "EN cours NLD071118"
// COPYRIGHT DASSAULT SYSTEMES 1999
//-------------------------------------------------------------------------------------------------------------------------------
// 23/07/09 NLD (courant R19) Ajout previsionnel CATMathStrNormalSquareNormType               (implemente le 23/07)
// 23/07/09 NLD (courant R19) Ajout previsionnel CATMathStrFractionXYType                     (implemente le 29/07)
// 23/07/09 NLD (courant R19) Ajout previsionnel CATMathStrDerivXType                         (implemente le 23/07)
// 29/07/09 NLD (courant R19) Ajout previsionnel CATMathStrSingleMemoryXYType                 (implemente le 29/07)
// 29/07/09 NLD (courant R19) Ajout previsionnel CATMathStrOppositeXType                      (implemente le 29/07)
// 31/07/09 NLD (courant R19) Ajout previsionnel CATMathStrEquationProjectionPtCrvType        (implemente le 31/07)
//                                          avec CATMathStrEquationProjectionPtCrvUnStreamSharedLib
//                                            et CATMathStrEquationProjectionPtCrvUnStreamEntryName
// 31/07/09 NLD (courant R19) Ajout previsionnel CATMathStrSweepCoherenceFormDirFunctionXType (implemente le 31/07)
//                                          avec CATMathStrSweepCoherenceFormDirFunctionXUnStreamSharedLib
//                                            et CATMathStrSweepCoherenceFormDirFunctionXUnStreamEntryName
//              Ajout type CATFunctionXUnStream pour les chargements dynamiques de fonctions X de UnStream()
// 31/07/09 NLD Introduction de CATMathStrFunctionNoType pour parametrer le -1 
// 05/08/09 NLD Ajout CATMathStrEquationDistancePtCrvType        (implemente le 05/08)
//               avec CATMathStrEquationDistancePtCrvUnStreamSharedLib
//                 et CATMathStrEquationDistancePtCrvUnStreamEntryName
//              Ajout CATMathStrOffsetSurfaceCGMFunctionXYType      (implemente le 05/08) pour CATOffsetSurfaceCGMFunctionXY
//               avec CATMathStrOffsetSurfaceCGMFunctionXYUnStreamSharedLib
//                 et CATMathStrOffsetSurfaceCGMFunctionXYUnStreamEntryName
//              Ajout type CATFunctionXYUnStream pour les chargements dynamiques de fonctions XY de UnStream()
//              Ajout CATMathStrGenericFilletEquationType      (implemente le 05/08) pour CATGenericFilletEquation
//               avec CATMathStrGenericFilletEquationSharedLib
//                 et CATMathStrGenericFilletEquationEntryName
// 21/10/09 NLD Ajout CATMathStrFunctionInitProjIsoparType      (implemente le 21/10) pour CATFunctionInitProjIsopar
//               avec CATMathStrFunctionInitProjIsoparSharedLib
//                 et CATMathStrFunctionInitProjIsoparUnStreamEntryName
//-------------------------------------------------------------------------------------------------------------------------------
// Historique de CATGetFunctionXUnStreamFrF
//-------------------------------------------------------------------------------------------------------------------------------
// 17/11/17 NLD Ajout macro UnStreamArguments
//              Ajout CATFunctionXUnStream_CATFunctionG2IntoC2
// 24/11/17 NLD Renommage en CATGetFunctionXUnStreamFrFArguments de UnStreamArguments (maladroit), et #undef final
// 21/06/18 NLD Ajout CATFunctionXUnStream_MvFrPseudoOrthoFunctionX
//              Deflaggage
// 07/11/18 NLD Ajout des fonctions correspondant aux equations de distance:
//              - CATFunctionXUnStream_LawEquationDistCrv
//              - CATFunctionXUnStream_LawEquationDistPCrvPCrv
//              - CATFunctionXUnStream_LawEquationDistLnCrvParamOnCrv
//-------------------------------------------------------------------------------------------------------------------------------
#include "CATIACGMLevel.h"
#include "CATMathStrFunctionType.h"
#include "FrFObjects.h"
#include "FrFAdvancedOpeCrv.h"
#include "FrFEquation.h"
class CATTolerance;
extern "C"
{
  ExportedByFrFObjects        CATFunctionXUnStream* CATGetFunctionXUnStreamFrF(const short iType) ;
 
  #define CATGetFunctionXUnStreamFrFArguments CATMathStream& Str, const CATTolerance &iTolObject, const char iLabelReserved[] 

  ExportedByFrFObjects        CATMathFunctionX* CATFunctionXUnStream_SweepCoherenceFormDirFunctionX(CATGetFunctionXUnStreamFrFArguments);
  ExportedByFrFAdvancedOpeCrv CATMathFunctionX* CATFunctionXUnStream_CATFunctionG2IntoC2           (CATGetFunctionXUnStreamFrFArguments);
  ExportedByFrFEquation       CATMathFunctionX* CATFunctionXUnStream_MvFrPseudoOrthoFunctionX      (CATGetFunctionXUnStreamFrFArguments);

  #ifdef CATGetFunctionXUnStreamFrF_AddLawEquationFunctions
  ExportedByFrFObjects        CATMathFunctionX* CATFunctionXUnStream_LawEquationDistCrv            (CATGetFunctionXUnStreamFrFArguments);
  ExportedByFrFObjects        CATMathFunctionX* CATFunctionXUnStream_LawEquationDistPCrvPCrv       (CATGetFunctionXUnStreamFrFArguments);
  ExportedByFrFObjects        CATMathFunctionX* CATFunctionXUnStream_LawEquationDistLnCrvParamOnCrv(CATGetFunctionXUnStreamFrFArguments);
  #endif

  #undef CATGetFunctionXUnStreamFrFArguments
  
};

 
#endif
