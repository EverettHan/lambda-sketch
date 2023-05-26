#ifndef CATFrFFSBlsMultiForm_H
#define CATFrFFSBlsMultiForm_H
//
//===================================================================
// Copyright Dassault Systemes Provence 2009-2016, all rights reserved
//===================================================================
// Usage notes:
//
//===================================================================
// 29/02/16 : HLN ; XScale: suppression constructeurs obsoletes
// 10/12/13 : HLN ; XScale : suite. Ajout iTolEpsg
// 25/04/12 : NLD ; Reception de la configuration; ajout _SoftwareConfig
// 02/07/09 : MWE ; Creation d'apres CATClassATopoOperators\ProtectedInterfaces\CATCltBlsMultiForm.h
//===================================================================
#include "CATFrFFilletStyle.h"

class CATFrFFSBsplineApp;
class CATKnotVector;
class CATFrFNurbsMultiForm;
class CATGeoFactory;
class CATMathPoint;
class CATSoftwareConfiguration;

class ExportedByCATFrFFilletStyle CATFrFFSBlsMultiForm
//class CATFrFFSBlsMultiForm
{
public:
  //===============
  //  Constructors 
  //===============
/*hln29022016  CATFrFFSBlsMultiForm(CATSoftwareConfiguration* iSoftwareConfig,
                       const CATKnotVector *iKnotVector, int iNfix, int *iAfix, 
                       int nRows, int iNpts, CATMathPoint *iPoints, double *iParams,
                       double iSmoothFac );

  CATFrFFSBlsMultiForm(CATSoftwareConfiguration* iSoftwareConfig,
                       const CATKnotVector *iKnotVector, int iStorageMode, // 1 : Points are stored row wise;  
                       int nfix, int *afix, 
                       int idim, int nRows, int npts, double *pkte, double *parameters,
                       int ntan, int *tanindex, double *tangents,
                       double glafak );

  CATFrFFSBlsMultiForm(CATGeoFactory *iGeoFac, CATSoftwareConfiguration* iSoftwareConfig,
                       const CATKnotVector *iKnotVector, int iNfix, int *iAfix, 
                       int nRows, int iNpts, CATMathPoint *iPoints, double *iParams,
                       double iSmoothFac ); */

  CATFrFFSBlsMultiForm(CATGeoFactory *iGeoFac, CATSoftwareConfiguration* iSoftwareConfig,
                       const CATKnotVector *iKnotVector, int iStorageMode, // 1 : Points are stored row wise;  
                       int iNfix, int *iAfix, 
                       int iDim, int nRows, int iNpts, double *iPoints, double *iParams,
                       int iNtan, int *iTanInd, double *iTangents,
                       double iSmoothFac ); 
    
  //==============
  //  Destructor 
  //==============
  virtual ~CATFrFFSBlsMultiForm();

  //=======
  //  Run 
  //=======
  void Run();
  CATFrFNurbsMultiForm *GetResult();

private :
  double * _NewPoints;
  int _Dimension;
  int _NumberOfRows;
  CATSoftwareConfiguration* _SoftwareConfig;
  CATGeoFactory *_GeoFactory;

  CATFrFFSBsplineApp *_BsplineCreator;
};
#endif
