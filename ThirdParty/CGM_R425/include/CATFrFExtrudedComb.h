// COPYRIGHT DASSAULT SYSTEMES 2000
//==========================================================================
//
// Objet d'extraction de peigne : Derive de FrFComb
//    Ici le repere  n'est pas defini
//         par la normale et la dérivée de la courbe
//    mais par la normale et la direction de l'Isopare (en u ou v)
// 
//==========================================================================
// 01 2003  Creation                          MNA
//==========================================================================
// 04/11/10 JSX  : Ajout oer a EvalLocalCoordSystem
//==========================================================================
#ifndef CATFrFExtrudedComb_H
#define CATFrFExtrudedComb_H

#include "FrFOpeCrv.h"
#include "CATFrFComb.h"
#include "CATCrvLimits.h"
#include "CATCGMVirtual.h"
class CATPCurve;
class CATGeoFactory;

//--------------------------------------------------------------------------
class ExportedByFrFOpeCrv CATFrFExtrudedComb : public CATFrFComb
{
 public:
  //--------------------
  // Constructor
  //--------------------
  CATFrFExtrudedComb(CATGeoFactory *iFactory, const CATPCurve *iPCurve, const CATCrvLimits *iPCurveLimits=0, 
                     CATLONG32 iIsotype=0);
  //--------------------
  // Destructor
  //--------------------
  virtual ~CATFrFExtrudedComb();

  CATLONG32 GetIsoType();

  CATBoolean IsATypeOf(const CATTypeOfComb &iType) const;

 protected:
   
   void EvalLocalCoordSystem(CATError *&oer,double iparam,double *iDefaultDirForG1,double *iDerCrv,double *iNormal,
     double *iFirstDerivDefaultDirForG1,double *iDer2Crv,double *iDerNormal);
   
   //DATA
 private:
   CATLONG32 _IsoType; //1 means Isoparametric in U direction, 2 in  V direction. par defaut _Isotype=0 (erreur)


};
#endif
