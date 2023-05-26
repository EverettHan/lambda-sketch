#ifndef CATConvertCircleToNurbs_H
#define CATConvertCircleToNurbs_H
// COPYRIGHT DASSAULT SYSTEMES 2000
//=============================================================================
//
// CATConvertCircleToNurbs :
// Implementation class for operator of Circle into Nurbs conversion
//
//=============================================================================
// Septembre 2000     Creation                      PBK
// 31/05/07 NLD XScale ajout de CATTolerance en argument de ConvertFromDataToMultiform()
//              On change le fonctionnement: les methodes ne sont plus statiques
//              et il faut creer un objet avant d'utiliser les methodes de conversion
//              Ajout d'un constructeur
// 16/04/12 NLD Reception de la configuration dans le constructeur,
//              Ajout _Config
//=============================================================================
#include "FrFOpeCrv.h"
#include "CATDataType.h"


class CATMathCircleArc2D;
class CATFrFNurbsMultiForm;
class CATMathPlane;
class CATMathPoint;
class CATTolerance;
class CATSoftwareConfiguration;

class ExportedByFrFOpeCrv CATConvertCircleToNurbs
{
  private:
  CATConvertCircleToNurbs() ;
  public:
  CATConvertCircleToNurbs(      CATSoftwareConfiguration* iConfig,
                          const CATTolerance            * iTolObject) ;
  ~CATConvertCircleToNurbs();

  // Si iPlane==NULL on cree une Multiforme de dimension 2
  /* static */ void ConvertFromArc2DToMultiform(const CATMathCircleArc2D *iCircleArc2D,
                                          int iDegree,
                                          CATFrFNurbsMultiForm *&oMultiForm,
                                          const CATMathPlane *iPlane = 0);

  /* static */void ConvertFromDataToMultiform(const double iOrigin[2],
                                         double iRadius,
                                         double iStartAngle,
                                         double iEndAngle,
                                         int    iDegree,
                                         const CATMathPlane *iPlane,
                                         CATFrFNurbsMultiForm *&oMultiForm);
  
  /* static */void ConvertFromLineToMultiform(const CATMathPoint& Start, const CATMathPoint& End, 
                                         double      wStart, double      wEnd, 
                                         CATLONG32   idim,
                                         CATFrFNurbsMultiForm *&oMultiForm );


  private :

  /* static */ int GetDegreeMin(double iStartAngle, double iEndAngle);

  /* static */ void ConvertDataToData2D(double iMinorAxis,
                                  double iMajorAxis,
                                  const double iOrigin[2],
                                  double iStartAngle,
                                  double iEndAngle,
                                  double iOffsetAngle,
                                  int    iDegree,
                                  double *&oControlePoints,
                                  double *&oWeights);
        CATSoftwareConfiguration* _Config;
  const CATTolerance            * _TolObject ;
};
#endif




