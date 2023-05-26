// COPYRIGHT DASSAULT SYSTEMES 1998
//==========================================================================
//
// CATTopoGeodesic:
// Interface class of the CornerOnSupport Operator.
//
//==========================================================================
//
// Usage notes:
//
//========================================================================== 
// July 98     Creation                       JBX
//  11 01 02  ALV   Ajout de iNbWires dans le constructeur 
//                  pour l'indexation des corners solutions.
//========================================================================== 
//
#ifndef CATTopologicalCorner_H
#define CATTopologicalCorner_H
//
#include "FrFTopologicalOpe.h"
#include "CATMathDef.h"
#include "CATTopCornerCx2.h"
//
class CATWire;
class CATMathPoint;
class CATMathDirection;
//
//-----------------------------------------------------------------------------

class ExportedByFrFTopologicalOpe CATTopologicalCorner : public CATTopCornerCx2
{
  public :

    virtual              ~CATTopologicalCorner()          ;
    CATTopologicalCorner(CATGeoFactory * Facto,int iNbWires);
    CATTopologicalCorner(CATGeoFactory * Facto, CATTopData * iTopData,int iNbWires);

    // This method returns 
    //    a one-domain body if the geometric solution is full in face 
    //    a multi-domain if not
    virtual CATBody * GetCircle () const = 0;
    virtual int  RunCornerByType() = 0;

    virtual void GetOffsetOrientation(int &oOrientCrv1, 
                                      int &oOrientCrv2, int &oOrientCrv3) const=0;

  protected:
    //method form CATTopCornerCx2.
    CATBody *  GetRelimitDomain(CATLONG32 numdom);
    void GetSupportCells(CATLONG32 iNumCorn,CATLONG32 & oNbCells,CATCell **& oCells);
    void GetBuildingCells(CATLONG32 iNumCorn,CATLONG32 & oNbCells,CATCell **& oCells);
    void GetCurReport(CATLONG32 iNumCorn, CATBody * iBody, CATCGMJournalList * iCurJourn);
    void GetSupportBodies(CATLONG32 & nbsupports,CATBody **& TabSupports);
    void GetCurReportVertices(CATBody * iBody, CATCGMJournalList * iCurJourn);
    void SetTrim(CATBody * Corner, CATBody *&AssmbledBody);

    
};

#endif


