//=========================================================================
// COPYRIGHT DASSAULT SYSTEMES 2003 
//=========================================================================
//
// CATExtrapolationWireOnShell: extrapolation wire on shell
//
//========================================================================= 
// Sept 03     Creation                       AOV 
//========================================================================= 
#ifndef CATExtrapolationWireOnShell_H
#define CATExtrapolationWireOnShell_H

#include "CATIACGMLevel.h" // automatic treatment EB_2014_04_16
#include "CATExtrapolationWireOnShell.h"
#include "AdvTopoSketch.h"
#include "CATTopExtrapolWireOpe.h"
#include "CATListOfCATSurParams.h"
#include "CATFace.h"
#include "CATVertex.h"
#include "CATHybDef.h"
#include "CATMathVector.h"
#include "ListPOfCATVertex.h"

class CATLISTP(CATFace);

class ExportedByAdvTopoSketch CATExtrapolationWireOnShell:public CATTopExtrapolWireOpe
{

  public:
  
    CATExtrapolationWireOnShell(CATGeoFactory * iFacto,CATTopData * iData,CATBody * iShellBody,CATBody * iBodyToExtrapol);

  virtual              ~CATExtrapolationWireOnShell();

  /**
  * SetXXX methods
  */
  virtual void SetContinuityType(int type);
  virtual void SetExtrapolLimit(CATVertex * iVertex,double ilength=-1.);
  virtual void SetExtrapolLimit(CATVertex * iVertex,CATBody * iLimBody);


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

    CATBody *    ExtrapolWireInTangencyMode(CATGeoFactory * iFacto,CATTopData * iData,CATBody * iBodyToExtrapol,CATBody * iUpToWire=NULL);
    CATBody *    ExtrapolWireInCurvatureMode(CATGeoFactory * iFacto,CATTopData * iData,CATBody * iBodyToExtrapol,CATBody * iUpToWire=NULL);
    int          RetrieveFaceAndParam(CATGeoFactory * iFacto, CATTopData * iData,CATBody * iShellBody, CATVertex * iVtx,CATLISTP(CATFace) & oListOfFaces,CATSurParam *& oListOfPtParam);
    void         ComputeLength(CATGeoFactory * iFacto, CATTopData * iData);
    int CheckIntersectionResult(CATGeoFactory * iFacto, CATTopData * iData, CATBody * iInterBody, int& ioNbConf);
    int          CheckIntersBeforeExtrap(CATGeoFactory * iFacto, CATTopData * iData,CATBody * iBodyToExtrapol);
    CATBody *    RelimitExtrapolBody(CATGeoFactory * iFacto,CATTopData * iData,CATBody * iResultExtrap,CATBody * iUpToWire);
    CATBody *    DuplicateBody(CATGeoFactory * iFacto,CATCGMJournalList * IntJourn,CATBody * iBodyToExtrapol);
    void         JournalTreatment(CATCGMJournalList * iJourn,CATBody * iBodyWire,int ilevel,CATLISTP(CATVertex) & ListOfVertex);


    CATBody                 * _ShellBody;
    CATBody                 * _BodyToExtrapol;
    CATBody                 * _UpToWire;
    CATBody                 * _UpToPlane;
    CATVertex               * _StartVertex;
    double                    _Length;
    int                       _ContinuityType;
    CATCGMJournalList       * _JournResult;
    CATMathVector             _Direction;
    CATHybSelectionMode       _Side;
    int                       _IntersectInput;
    CATLONG32                 _IsInsert;
    CATLONG32                 _IsGetted;
    CATLONG32                 _UpToDim2;
    CATLONG32                 _Posage;
    CATMathPoint*             _ListOfIntPtBefore;
    int                       _NbInter;
    CATLONG32                 _InterAtStart;

};
#endif
