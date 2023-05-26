// COPYRIGHT DASSAULT SYSTEMES 2000
//==========================================================================
//
// Objet d'extraction de peigne : cas d'une courbe sans contrainte G1 - gestion avec des
// voisins en contact G1.
// 
//==========================================================================
// April 2000  Creation                          NDN
//==========================================================================
// 04/11/10 JSX  : Ajout oer a EvalLocalCoordSystem 
//==========================================================================
#ifndef CATFrFPointComb_H
#define CATFrFPointComb_H

#include "FrFOpeCrv.h"
#include "CATFrF3DComb.h"
class CATGeoFactory;
class CATMathSetOfPointsND;
class CATMathPoint;
class CATLine;

//--------------------------------------------------------------------------
class ExportedByFrFOpeCrv CATFrFPointComb : public CATFrF3DComb
{
 public:
  //--------------------
  // Constructor
  //--------------------
  CATFrFPointComb(CATGeoFactory *iFactory, const CATMathPoint &iPt, const CATMathSetOfPointsND * iSetOfParams, 
                   const CATMathSetOfPointsND * iSetOfVectors);

  //--------------------
  // Destructor
  //--------------------
  virtual ~CATFrFPointComb();

  //To get the type of Comb.
  virtual CATBoolean IsATypeOf(const CATTypeOfComb &iType) const;

  //To get the point.
  virtual void GetPoint(double *ioPt) const;

  void Dump() const;

 protected:
  virtual void EvalLocalCoordSystem(CATError *&oer, double iparam,double *iDefaultDirForG1,double *iDerCrv,double *iNormal,
                                    double *iFirstDerivDefaultDirForG1=0,double *iDer2Crv=0,double *iDerNormal=0);
  virtual void EvalCrv(double iparam,CATMathOption iOption,double *ioPt,double *ioTg=0,double *ioDs=0) const;

  //Datas
  double   _Pt[3];
  CATLine *_Line;
};
#endif
