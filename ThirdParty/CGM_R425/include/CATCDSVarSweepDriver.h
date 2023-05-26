//===================================================================
// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATCDSVarSweepDriver.h
// CDS driver construction class
// 1. SM and GSD : data declaration
// 2. GSD : creation of a CATCDSEngine class from this class
//
//===================================================================
//
// Usage notes:
//
//===================================================================
// 23.09.2005 FCX Creation
// 28 02 2013 NLD Ajout argument iPlane a SetCSParameter()
//===================================================================

#ifndef CATCDSVarSweepDriver_H
#define CATCDSVarSweepDriver_H

#include "VarSweepDriver.h"
#include "CATDataType.h"
#include "CATLISTV_CATBaseUnknown.h"

#include "CATConstraintSolver.h"
#include "CATCSGeomConstraint.h"
#include "CATCSGeometryLeaf.h"

class CATICDSAdvanced;
class CATLaw;
class CATBody;
class CATICDSGeomConstraint;
class CATICDSGeometryLeaf;
class CATCDSVarSweepDriverImp;
class CATCDSVarSweepFuncEvaluator;
class CATPlane;

enum CATCSMarkType
{
  CSMTypeIntersection=0,
  CSMTypeProjection,
  CSMTypeOffset,
  CSMTypeOutline,
  CSMTypeHelp// JSX For Internal Purpose Only
};

enum CATCSExtremitiesType
{
  CSETypeNoExtremities,
  CSMTypeFixedExtremities,
  CSMTypeFreeExtremities
};

class ExportedByVarSweepDriver CATCDSVarSweepDriver
{
public:
  ~CATCDSVarSweepDriver();
  CATCDSVarSweepDriverImp* GetImp();

  // *******
  // * GSD *
  // *******

  // Instanciation de CATCDSVarSweepDriver

  CATCDSVarSweepDriver(CATBody * iSpine = 0);

  // Declaration des parametres variables (intervenant dans les lois et les relations)

  void SetParameters(CATLISTV(CATBaseUnknown_var) & iGSDConstraintTable);

  // Declaration des lois

  void SetLaws(int iNbParameters, int * iParameterIndexTable, CATLaw ** iLawTable, CATLaw * iMvFrToLawParamMapping);

  // Declaration des relations

  void AddFunction(int iNbParameters, int * iParameterIndexTable, CATCDSVarSweepFuncEvaluator * iEvaluator);

  // Ne plus utiliser !
  void SetLaws(CATLISTV(CATBaseUnknown_var) & iGSDConstraintTable, CATLaw ** iLawTable, CATLaw * iMvFrToLawParamMapping);

  // Ne plus utiliser !
  void SetFunctions(CATLISTV(CATBaseUnknown_var) & iGSDConstraintTable, void ** iFunctionTable);

  // Parametre initial sur la spine et plan du sketch

  void SetCSParameter(double iT, CATPlane* iPlane = NULL);

  // Renvoie vrai si le sweep avec le driver est appliquable

  CATBoolean IsSupported() const;

  // ******
  // * SM *
  // ******

  // Association du solver CDS d'un sketch resolu

  void SetConstraintSolver(CATICDSAdvanced * iConstraintSolver,CATBoolean = FALSE);

  // SM fait le lien entre les contraintes de type GSD et les constraintes CDS.

  void GetGSDConstraintTable(CATLISTV(CATBaseUnknown_var) & oGSDConstraintTable);

  void SetConstraintTable(CATICDSGeomConstraint ** iCSConstraintTable);

  // Declaration des use-edges a partir d'une skin

  void SetMarkFromShell( CATBody              * iSkin,
                         CATCSMarkType          iMType,
                         CATICDSGeometryLeaf  * iCSGeometry,
                         CATCSExtremitiesType   iEType             = CSETypeNoExtremities, 
                         CATICDSGeometryLeaf  * iCSFirstExtremity  = 0,
                         CATICDSGeometryLeaf  * iCSSecondExtremity = 0);

  // Declaration des use-edges a partir d'un guide
  // iGuideSupport NULL si guide non pose

  void SetMarkFromWire( CATBody             * iGuide,
                        CATBody             * iGuideSupport,
                        CATCSMarkType         iMType,
                        CATICDSGeometryLeaf * iCSGeometry);

  // Declaration des use-edges a partir d'un vertex

  void SetMarkFromVertex( CATBody             * iPoint,
                          CATCSMarkType         iMType,
                          CATICDSGeometryLeaf * iCSGeometry);

  // Declaration des courbes visibles du profil

  void SetProfileItems(CATLONG32 iNumberOfGeometries, CATICDSGeometryLeaf ** iCSGeometryTable, double * iStartParamTable = 0, double * iEndParamTable = 0);

private:
  CATCDSVarSweepDriverImp * _Imp;
  CATLISTV(CATBaseUnknown_var) _GSDConstraintTableLaws;
  CATLISTV(CATBaseUnknown_var) _GSDConstraintTableFunctions;
};

#endif
