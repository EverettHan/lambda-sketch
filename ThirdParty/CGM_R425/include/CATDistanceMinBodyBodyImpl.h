/* -*-C++-*- */
#ifndef CATDistanceMinBodyBodyImpl_h
#define CATDistanceMinBodyBodyImpl_h

// COPYRIGHT DASSAULT SYSTEMES  2011
//===================================================================
//  CATDistanceMinBodyBodyImpl
//===================================================================

#include "AnalysisToolsLight.h"
#include "CATDistanceMinBodyBody.h"

///////////////////////////////////////////////////////////////
// This API has been deprecated. 
// Please use the new API instead:
//    CATICGMDistanceBodyBody (created using CATCGMCreateDistanceBodyBodyOp)
///////////////////////////////////////////////////////////////


/**
 * @deprecated V5R27-R419 CATICGMDistanceBodyBody
 */
class ExportedByAnalysisToolsLight CATDistanceMinBodyBodyImpl : public CATDistanceMinBodyBody
{
public :
  CATDistanceMinBodyBodyImpl(CATGeoFactory  * iFactory,
                             CATTopData     * iData,
                             CATBody        * iBody1,
                             CATBody        * iBody2,
                             CATBoolean       iInternalMode = FALSE);

  virtual ~CATDistanceMinBodyBodyImpl();

  int Run();

protected:

  int RunOperator();

  // CGMReplay

  static const  CATString        *GetDefaultOperatorId();
         const  CATString        *GetOperatorId();
  static        CATString         __OperatorId;
                void              RequireDefinitionOfInputAndOutputObjects();

                CATExtCGMReplay  *IsRecordable(short &LevelOfRuntime, short &VersionOfStream);

  // Write Inputs and Output
                void              WriteInput (CATCGMStream & Str);
                void              WriteOutput(CATCGMStream & Str);

  // Dump Output  
                void              Dump      (CATCGMOutput &os);
                void              DumpOutput(CATCGMStream& ioStream, CATCGMOutput& os,int VersionNumber);
                void              DumpOutput(CATCGMOutput &os);

  // Validate OutPut
                CATBoolean        ValidateOutput   (CATCGMStream& Str, CATCGMOutput & os, int VersionNumber);  
                CATBoolean        ValidateTopOutput(CATTopCheckJournal* iEquivalent,CATCGMOutput& os);  

  CATCGMOperator::CATCheckDiagnostic CheckOutput(CATCGMOutput &os);


public:

  // internal
  void ReadInput(CATCGMStream & Str);

  CATCGMOperator::CATCheckDiagnostic CheckInput(CATCGMOutput &oOut);

protected:

  void ReadOutput(
        CATCGMStream& Str, 
        int           VersionNumber,
        double      & Distance,
        CATBoolean  & ArePointsAvailable,
        CATMathPoint& P1,
        CATMathPoint& P2,
        CATULONG32  & Cell1Tag,
        CATULONG32  & Cell2Tag);

  void DumpOutput(
        double      & Distance,
        CATBoolean  & ArePointsAvailable,
        CATMathPoint& P1,
        CATMathPoint& P2,
        CATULONG32  & Cell1Tag,
        CATULONG32  & Cell2Tag,
        CATCGMOutput& os);
};

#endif // CATDistanceMinBodyBodyImpl_h


