// COPYRIGHT DASSAULT SYSTEMES 1997 
//==========================================================================
//
// CATFrFConnectSurface: classe de gestion pour les operateurs multi-surface
//
//========================================================================== 
// Septembre 98     Creation          Catherine Eymin
// Aout 99          Modification      David Haegeman (portage sur ConnectCurves, 
//                                                    CompositeSurface,...)
//========================================================================== 
#ifndef CATFrFConnectSurface_H
#define CATFrFConnectSurface_H "NLD230512 pour programmation fiable du shunt NDNCoverage051005"
#endif

#ifndef CATFrFConnectSurface_H
#define CATFrFConnectSurface_H

#include "FrFObjects.h"
#include "CATDataType.h"
#include "CATListOfCATSurfaces.h"
#include "CATCGMVirtual.h"

class CATFrFConnectCurve;
class CATFrFNurbsMultiForm;
class CATSurface;
class CATSurParam;
//-----------------------------------------------------------------------------
class ExportedByFrFObjects CATFrFConnectSurface  : public CATCGMVirtual
{
  public :

//-----------------------------------------------------------------------------
//  Constructeurs
//-----------------------------------------------------------------------------
//  IMPORTANT : une ConnectSurface doit etre construite dans une CompositeSurface 
//  (methode CreateConnectSurface de CATFrFCompositeSurface)            
    CATFrFConnectSurface(const CATFrFConnectSurface &);
    CATFrFConnectSurface();

//-----------------------------------------------------------------------------
//  Destructeur
//-----------------------------------------------------------------------------
    virtual ~CATFrFConnectSurface();

//-----------------------------------------------------------------------------
//  Mise a jour des donnees de la ConnectSurface
//-----------------------------------------------------------------------------
//  Informations des surfaces voisines via les ConnectCurves
    void    SetNeighboursForUmin(CATLONG32 &iNumber, const CATFrFConnectCurve **iArrayOfConnectCurves);
    void    SetNeighboursForUmax(CATLONG32 &iNumber, const CATFrFConnectCurve **iArrayOfConnectCurves);
    void    SetNeighboursForVmin(CATLONG32 &iNumber, const CATFrFConnectCurve **iArrayOfConnectCurves);
    void    SetNeighboursForVmax(CATLONG32 &iNumber, const CATFrFConnectCurve **iArrayOfConnectCurves);

//  Mise a jour des frontieres objcetives (par recopie des entrees)
//  Note : ces frontieres sont calculees dans l'objet CATFrFGlobalConnectSurface
//  ibord correspond a :
//  ibord = 0 -> v=0
//  ibord = 1 -> u=0
//  ibord = 2 -> v=1
//  ibord = 3 -> u=1  
    void SetTargetBoundary(const CATFrFNurbsMultiForm *iNurbsCrv, const CATLONG32 &iBord);

//  Ne pas utiliser :
//    void    Update(CATSurface *iSurf, const CATLONG32 &iRank)
//    {_Surf = iSurf;_Rank = iRank;};

//-----------------------------------------------------------------------------
//  Lecture des donnees de la ConnectSurface
//-----------------------------------------------------------------------------
//  Recuperations des surfaces voisines via les ConnectCurves
    void    GetNeighboursForUmin(CATLONG32 &oNumber, CATFrFConnectCurve **&oArrayOfConnectCurves) const;
    void    GetNeighboursForUmax(CATLONG32 &oNumber, CATFrFConnectCurve **&oArrayOfConnectCurves) const;
    void    GetNeighboursForVmin(CATLONG32 &oNumber, CATFrFConnectCurve **&oArrayOfConnectCurves) const;
    void    GetNeighboursForVmax(CATLONG32 &oNumber, CATFrFConnectCurve **&oArrayOfConnectCurves) const;    

//  Lecture d'une frontiere cible sur un bord donne
    void    GetTargetBoundary(const CATFrFNurbsMultiForm *&oNurbsCrv, const CATLONG32 &iBord) const;

//  Lecture du rang dans la CompositeSurface
    CATLONG32    GetRank() const
    {return _Rank;};

//  Lecture de la surface associee
    CATSurface *GetSurface() const
    {return _Surf;};

//  Lecture du nombre total de ConnectSurfaces (et donc de ConnectCurves) 
//    connexes a la ConnectSurface courante
    CATLONG32 GetNumberOfConnections() const
    {return _NbConnex;};

//  Nombre sur bord UMin, VMin, UMax et VMax
    CATLONG32 GetNumberOfConnectionsOnUMin() const
    {return _NbConnexOnUmin;};
    CATLONG32 GetNumberOfConnectionsOnVMin() const
    {return _NbConnexOnVmin;};
    CATLONG32 GetNumberOfConnectionsOnUMax() const
    {return _NbConnexOnUmax;};
    CATLONG32 GetNumberOfConnectionsOnVMax() const
    {return _NbConnexOnVmax;};

//  Etude des continuites
    CATLONG32 GetMinContinuityOnBoundary(const CATLONG32 &iBord) const;
    CATLONG32 GetMaxContinuityOnBoundary(const CATLONG32 &iBord) const;


//-----------------------------------------------------------------------------
//  Donnees de la ConnectSurface
//-----------------------------------------------------------------------------
  protected:
   CATFrFConnectCurve           ** _ConnectCurvesUmin, ** _ConnectCurvesUmax,
                                ** _ConnectCurvesVmin, ** _ConnectCurvesVmax;
   CATLONG32                       _Rank;
   CATLONG32                       _NbConnex;   
   CATSurface                    * _Surf;
   CATLONG32                       _NbConnexOnUmin, _NbConnexOnUmax, _NbConnexOnVmin, _NbConnexOnVmax; 
   CATFrFNurbsMultiForm          * _TargetBoundaryUmin, *_TargetBoundaryUmax;
   CATFrFNurbsMultiForm          * _TargetBoundaryVmin, *_TargetBoundaryVmax;
};
#endif

