// COPYRIGHT DASSAULT SYSTEMES 1999 
//==========================================================================
//
// CATFrFConnectPoint: classe de gestion pour operateurs multi-surfaces.
// Cette classe permet notamment de retouver les infos concernant les
// configurations en '+', en 'T', ...
//
//========================================================================== 
// Aout 99     Creation          David HAEGEMAN
//========================================================================== 

#ifndef CATFrFConnectPoint_H
#define CATFrFConnectPoint_H "NLD230512 pour NDNCoverage021205 apprenons a notre ami a faire un shunt compilable"
#endif
#ifndef CATFrFConnectPoint_H
#define CATFrFConnectPoint_H

#include "FrFObjects.h"
#include "CATDataType.h"
#include "CATCGMVirtual.h"

class CATFrFConnectCurve;
//-----------------------------------------------------------------------------
class ExportedByFrFObjects CATFrFConnectPoint  : public CATCGMVirtual
{
  public :

// Construction du ConnectPoint
    CATFrFConnectPoint (      CATFrFConnectCurve **  iArrayOfConnectCrvs,
                        const CATLONG32            & iNumberOfConnectCrvs);
    CATFrFConnectPoint (const CATFrFConnectPoint   &);
    CATFrFConnectPoint ();

// Mise a jour des donnees 
   void AddConnectCurve(      CATFrFConnectCurve  *  iConnectCrv);
   void SetSizeMax     (const CATLONG32            & iSizeMax);

// Destructeur
   virtual ~CATFrFConnectPoint();

//  Lecture des donnees
   CATLONG32 GetSizeMax() const
    {return _SizeMax;};

   CATLONG32 GetNumberOfConnectCurves() const
    {return _NbCurves;};

   void GetConnectCurve(const CATLONG32 &iRank, const CATFrFConnectCurve *oConnectCurve) const
   {oConnectCurve = _ConnectCurves[iRank-1];};

   CATLONG32 GetMinContinuityOnConnectPoint() const;


  protected:
    CATLONG32             _NbCurves,
                          _SizeMax;
    CATFrFConnectCurve ** _ConnectCurves;

};
#endif

