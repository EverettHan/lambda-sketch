//====================================================================
// Copyright Dassault Systemes Provence 2005, all rights reserved 
//====================================================================
//
//
// CATFrFConvert2DCCVTo3DCCV :
// conversion of a CATCompositeCurve that contains PNurbs
// into a composite curve that contain approximated NurbsCurves
//==========================================================================
// Nov,     2005 : ANR : Ajout d'une option de decoupe pour l'offsetabilite des SDS
//                       la prochaine option, il faut faire un run ...
// April,   2005 : ANR/FZA : Creation     (D'apres  CATConvert2DCCVTo3DCCV)  
//==========================================================================

#ifndef CATFrFConvert2DCCVTo3DCCV_H
#define CATFrFConvert2DCCVTo3DCCV_H
#include "CATFrFNetSurface.h"
#include "CATBoolean.h"
#include "CATKnotVector.h"


class CATFrFCompositeCurve;
class CATSoftwareConfiguration;
class CATGeoFactory; 
//----------------------------------------------------------------------
class ExportedByCATFrFNetSurface CATFrFConvert2DCCVTo3DCCV
{
public :

  CATFrFConvert2DCCVTo3DCCV (CATGeoFactory            * iFactory, 
                             CATSoftwareConfiguration * iConfig,
                             CATFrFCompositeCurve     * iCCV);
  
  ~CATFrFConvert2DCCVTo3DCCV();
  
  void SetTestC1Mode(CATBoolean  iTestC1=FALSE);
  void SetImposedCubicDegree(CATBoolean  iImposedCubicDegree=FALSE);
  void SetOptionForSDSOffset(CATBoolean  iOptionForSDSOffset=FALSE);
  void SetOptionReparam(CATBoolean  iOptionReparam=FALSE);
  void SetImposedMaxArcs(CATBoolean  iImposedMaxArcs=FALSE, int iNbMaxOfArcs=20);

  // Ajout ANR pour IMA
  void SetSubdivisionOption(CATBoolean iLODMode=TRUE);

  void Run() ;

  CATFrFCompositeCurve* GetResult(){return _resultingCCV;};
  
  void GetResultBis(CATFrFCompositeCurve*& oCCVs);

  int GetNbOfArcs();

private :

  // Pour IMA
  void AddCuttingPoints(CATKnotVector *iKnotVec, int MaxNumberOfArcs,
                        CATKnotVector *&oKnotVec) ;
  CATGeoFactory *_Factory;
  CATSoftwareConfiguration * _Config;
  CATFrFCompositeCurve     * _InputCCV ;
  CATFrFCompositeCurve* _resultingCCV;

  CATBoolean  _TestC1;
  CATBoolean  _ImposedCubicDegree ;
  CATBoolean  _OptionForSDSOffset;
  CATBoolean  _OptionReparam ;
  CATBoolean  _ImposedMaxArcs ;
  int _ImposedNbMaxOfArcs ;

  int _NbOfArcsResult;

  CATBoolean _LODMode ;

  int _CGMLevel;
  int _LevelOfParam;
  CATBoolean _VersionningOfParam;

};
#endif
