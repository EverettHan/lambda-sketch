// COPYRIGHT DASSAULT SYSTEMES 1999
//==========================================================================
//
// CATFrFConnectCurve: classe permettant la gestion des continuites
// entre deux surfaces dans les operateurs multi-surfaces.
//
//========================================================================== 
// Aout 99     Creation          David HAEGEMAN
//========================================================================== 

#ifndef CATFrFConnectCurve_H
#define CATFrFConnectCurve_H "NLD230512 pour programmation fiable du shunt NDNCoverage051005"
#endif

#ifndef CATFrFConnectCurve_H
#define CATFrFConnectCurve_H

#include "FrFObjects.h"
#include "CATSurParam.h"
#include "CATCGMVirtual.h"

class CATFrFConnectSurface;
//-----------------------------------------------------------------------------
class ExportedByFrFObjects CATFrFConnectCurve  : public CATCGMVirtual
{
  public :

// Construction de la ConnectCurve :
//  Ibord = 0 => Umin
//  Ibord = 1 => Umax
//  Ibord = 2 => Vmin
//  Ibord = 3 => Vmax
//  iCont : continuite entre les deux surfaces au niveau de la ConnectCurve
    CATFrFConnectCurve(      CATFrFConnectSurface *Surf1,
                       const CATLONG32            &iBord1, 
                       const CATSurParam          *ExtremiteDebut1,
                       const CATSurParam          *ExtremiteFin1,
                             CATFrFConnectSurface *Surf2,
                       const CATLONG32           &iBord2, 
                       const CATSurParam         *ExtremiteDebut2,
                       const CATSurParam         *ExtremiteFin2,
                             CATLONG32            iCont = 0);
    CATFrFConnectCurve(const CATFrFConnectCurve &);
    CATFrFConnectCurve();

//  Destructeur
    virtual ~CATFrFConnectCurve();

//  Acces aux donnees
   CATLONG32 GetContinuity() const
            {return _Continuity;};
   CATLONG32 GetBord1() const
            {return _Bord1;};
   CATLONG32 GetBord2() const
            {return _Bord2;};
   void GetConnectSurface1(CATFrFConnectSurface *&oConnectSurf) const;
   void GetConnectSurface2(CATFrFConnectSurface *&oConnectSurf) const;
   void GetExtremities1   (CATSurParam &oDebut, CATSurParam &oFin) const;
   void GetExtremities2   (CATSurParam &oDebut, CATSurParam &oFin) const;

//  Acces aux donnees pour une surface
   void GetConnectData      (const CATFrFConnectSurface *  iConnectSurf,
                                   CATFrFConnectSurface *& oOtherConnectSurf) const;
   void GetDataForOneSurface(const CATFrFConnectSurface *  iConnectSurf, 
                                   CATSurParam           & oDebut,
                                   CATSurParam           & oFin,
                                   CATLONG32             & oBord) const;

//  Methodes avancees
   void ComputeMaxContinuity(const CATLONG32 &iNumberOfDiscretizationPoints);


  protected:
    CATLONG32                    _Continuity, _Bord1, _Bord2;
    CATFrFConnectSurface        *_Surf1, *_Surf2;
    CATSurParam                  _Debut1, _Fin1, _Debut2, _Fin2;

};

#endif

