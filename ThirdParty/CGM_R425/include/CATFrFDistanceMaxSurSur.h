// COPYRIGHT DASSAULT SYSTEMES 1998
//==========================================================================
//
// CATFrFDistanceMaxSurSur est un objet temporaire pour calculer la distance
// entre 2 surfaces (en attendant de l objet mathematique).
//
//==========================================================================
//
// Usage notes: Objet servant a calculer la distance entre 2 surfaces.
// Un cheminement est effectue sur la 1ere courbe (!! traitement non
// symetrique) et pour chaque point on calcule le min distance avec la 
// courbe opposee ; le resultat est le max de ces min distances.
// 
//========================================================================== 
//    02/98 NDN Creation                                      NDN
//    12/03 MNA Ajout d'une SoftwareConfiguration
//========================================================================== 

#ifndef CATFrFDistanceMaxSurSur_H
#define CATFrFDistanceMaxSurSur_H

#include "FrFOpeUtil.h"
#include "CATSkillValue.h"
#include "CATGeoFactory.h"
#include "CATSurface.h"
#include "CATSurLimits.h"
#include "CATSurParam.h"
#include "CATCGMVirtual.h"

class CATSoftwareConfiguration;

//-----------------------------------------------------------------------------
class ExportedByFrFOpeUtil CATFrFDistanceMaxSurSur  : public CATCGMVirtual
{
  public :
    CATFrFDistanceMaxSurSur(      CATGeoFactory            *  iFactory ,
                            const CATSurface               *  CRef   ,
                            const CATSurface               *  C2     ,
                            const CATSurLimits              & CLRef       ,
                            const CATSurLimits              & CL2         ,
                            const CATSkillValue             & iMode = BASIC,
                                  CATSoftwareConfiguration *  iSoftwareConfiguration=NULL);
  
    virtual ~CATFrFDistanceMaxSurSur();
  
    double GetMaxDistance() const ;
    void   GetParams( CATSurParam& oCPRef, CATSurParam& oCP2 ) const;
  
    void SetSurfaceRef(const CATSurface* CRef, const CATSurLimits& CLRef);
    void SetSurfaceTwo(const CATSurface* C2  , const CATSurLimits& CL2);

    void SetNbOfDiscretizedPoints(CATLONG32 NbOfDiscretizedPointsU,CATLONG32 NbOfDiscretizedPointsV);

    void Run ();

  private :

    CATGeoFactory            * _Factory;
    CATSoftwareConfiguration * _SoftwareConfig;
    const CATSurface         * _Surface1;
    const CATSurface         * _Surface2;
    CATSurLimits               _SurLimits1;
    CATSurLimits               _SurLimits2;
  
    CATLONG32                  _NbOfDiscretizedPointsU;
    CATLONG32                  _NbOfDiscretizedPointsV;
    double                     _MaxDist;

    CATSurParam                _SurParam1;
    CATSurParam                _SurParam2;

};

#endif


