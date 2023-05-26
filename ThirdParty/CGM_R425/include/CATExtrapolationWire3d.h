//=========================================================================
// COPYRIGHT DASSAULT SYSTEMES 2003 
//=========================================================================
//
// CATExtrapolationWire3d:extrapolation of wire when no support defined
//
//=========================================================================
// Oct 03     Creation                       AOV 
//========================================================================= 
#ifndef CATExtrapolationWire3d_H
#define CATExtrapolationWire3d_H

#include "CATIACGMLevel.h" // automatic treatment EB_2014_04_16
#include "CATExtrapolationWire3d.h"
#include "AdvTopoSketch.h"
#include "CATTopExtrapolWireOpe.h"
#include "CATHybDef.h"
#include "CATMathVector.h"


class CATBody;
class CATVertex;
class CATCGMJournalList;
class CATPlane;


class ExportedByAdvTopoSketch CATExtrapolationWire3d:public CATTopExtrapolWireOpe
{
  public:
    
    CATExtrapolationWire3d(CATGeoFactory * iFacto,CATTopData * iData,CATBody * iBodyToExtrapol);
    
    virtual              ~CATExtrapolationWire3d()  ;
    
    /**
    * SetXXX methods
    */
    virtual void SetContinuityType(int itype);
    virtual void SetExtrapolLimit(CATVertex * iVertex,CATBody * iLimBody);
    virtual void SetExtrapolLimit(CATVertex * iVertex, double ilength=0);

    virtual int          Run();
    
    virtual CATBody *    GetResult() ;
    virtual CATBody *    GetResult(CATCGMJournalList * iJourn);

#ifdef CATIACGMV5R17 
    virtual void SetNoSimplifOnLine();
#endif 

    // ---------------
    // methods for CGM Replay 
    // ---------------
    static const CATString *GetDefaultOperatorId() { return &_OperatorId; }
  
  protected :
  
    static CATString  _OperatorId;
    const  CATString *GetOperatorId();
    CATExtCGMReplay  *IsRecordable( short &LevelOfRuntime, short &VersionOfStream );
    void              WriteInput( CATCGMStream  &ioStream );
    void              Dump( CATCGMOutput &os );
    int               RunOperator();
    void              RequireDefinitionOfInputAndOutputObjects();
    
    
  private:

    //run extrapolation 3d G1
    CATBody * RunExtrapolationInTangency(CATGeoFactory * iFacto,CATTopData * iData);
    //run extrapolation 3d G2
    CATBody * RunExtrapolationInCurvature(CATGeoFactory * iFacto,CATTopData * iData);

    //utilitaires
    void ComputeLength(CATGeoFactory * iFacto, CATTopData * iData);
    CATBody * RelimitExtrapol(CATGeoFactory * iFacto,CATTopData * iData,CATBody * ExtrapBody);
    void CheckIfIntersBeforeExtrap(CATGeoFactory * iFacto,CATTopData * iData);
    CATBody * DuplicateBody(CATGeoFactory * iFacto,CATCGMJournalList * IntJourn,CATBody * iBodyToExtrapol);

    

    CATBody *                 _BodyToExtrapol;
    CATBody *                 _UpToElement;
    CATVertex *               _StartVertex;
    double                    _Length;
    int                       _ContinuityType; 
    CATCGMJournalList *       _JournResult;
    CATHybSelectionMode       _Side;
    CATLONG32                 _IsInsert;
    CATLONG32                 _IsGetted;
    CATMathVector             _Direction;
    CATLONG32                 _InterAtStart;
    CATMathPoint*             _ListOfIntPtBefore;
    int                       _NbInter;
    CATPlane*                 _TargetPlane;
    int                       _Simplif;
    
};
#endif
