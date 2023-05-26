// COPYRIGHT DASSAULT SYSTEMES 1998
//==========================================================================
//
// CATFrFSweepDomainOpe: Calculate all Domains and CcvIndex associated
//
//==========================================================================
//
// Usage notes:
//
//==========================================================================
// Oct 98  Christophe Pradal (cpl) Creation
// May 99  cpl Add _MasterProfile & _MasterGuide Indexes
// Aug 02  JSX methode KeepMovingFrameOrientation pour Sweep adaptatif
// Sep 04  JSX derive de CATFrFObjectVirtual
// 27/02/07 NLD : Migration vers CATFrFObject au lieu de CATFrFObjectVirtual
// 31/03/09 NLD : deplacement dans ProtectedInterfaces pour tentative 
//                d'utilisation dans l'homogeneisation topologique
//                La classe devient exportee
//==========================================================================

#ifndef CATFrFSweepDomainOpe_H
#define CATFrFSweepDomainOpe_H

#include "FrFAdvancedObjects.h"
#include "CATFrFCoupling.h"
#include "CATFrFMovingFrame.h"
#include "CATMathInterval.h"
#include "CATMathDef.h"
#include "CATFrFObject.h"

//----------------------------------------------------------------------------
class ExportedByFrFAdvancedObjects CATFrFSweepDomainOpe : public CATFrFObject//CATCGMVirtual
{
  public :

    ////////////////////////////////////////////////////
    // Creator & Destructor
    ////////////////////////////////////////////////////

    CATFrFSweepDomainOpe(CATFrFMovingFrame* iMovingFrame,
                         CATFrFCoupling* iCoupling,
                         CATLONG32 iMasterGuideIndex= 0,
                         CATLONG32 iMasterProfileIndex= 0);

    virtual ~CATFrFSweepDomainOpe();


    ////////////////////////////////////////////////////
    // Set
    ////////////////////////////////////////////////////
    // 
    void KeepMovingFrameOrientation();

    ////////////////////////////////////////////////////
    // Run
    ////////////////////////////////////////////////////


    void Run();

    ////////////////////////////////////////////////////
    // Get Result
    ////////////////////////////////////////////////////

    void GetResult(CATMathInterval*& oDomains, CATLONG32& iNbDomains,
                   CATLONG32*& iStartCrvIndex,CATLONG32*& iEndCrvIndex) const;

    ////////////////////////////////////////////////////
    // Extrapol Curves under Coupling
    ////////////////////////////////////////////////////

    void Extrapol(CATGeoFactory* iFactory) const;


 protected:

    // InPut
    CATFrFMovingFrame* _MovingFrame;
    CATFrFCoupling* _Coupling;
    CATLONG32 _MasterGuideIndex;
    CATLONG32 _MasterProfileIndex;


    CATLONG32 _UseMFOrient;
    // OutPut
    CATLONG32 _nbDomains;
    CATMathInterval* _Domains;
    CATLONG32* _StartCrvIndex;
    CATLONG32* _EndCrvIndex;

};

#endif

