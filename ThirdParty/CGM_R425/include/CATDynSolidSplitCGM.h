//=============================================================================
// SolidSplit implementation.
// 30/01/2017  G5S  Make the extrapolation tool into a class like an operator and refactor
//                  to use this new class in split and DOCO.  We need to set the extrapolation limit,
//                  as we do in DOCO.  
// 07/02/2017  G5S  Use enums for extrapolation mode and limit.  Add method to set Extrapolation limit.
// 14/03/17  G5S  Add the Extrapolation Limit to the CGMReplay.
//=============================================================================
/* -*-c++-*- */
#ifndef CATDynSolidSplitCGM_H_
#define CATDynSolidSplitCGM_H_

#include <CATDynSplit.h>
#include "BONEWOPE.h"
#include "CATMathInline.h"
#include <CATDynCNEXT.h>
#include "CATIACGMLevel.h"

class CATAdaptiveHashTable;

class ExportedByBODYNOPE CATDynSolidSplitCGM : public CATDynSplit
{
 public:

  CATDynSolidSplitCGM (CATGeoFactory*     iContainer,
                       CATTopData*        iData,
                       CATBody*           iBody,
                       CATDynSplitType    SplitType);
                                          
  CATDynSolidSplitCGM  (CATGeoFactory*     Container,
                        CATBody*           iBody,
                        CATDynSplitType    SplitType,
                        CATCGMJournalList* iJournal=NULL);

  virtual ~CATDynSolidSplitCGM();

  virtual void SetSplit (CATPlane*);
  virtual void SetSplit (CATSurface*);
  virtual void SetSplit (CATBody*);
  virtual void SetSplit (ListPOfCATFace & iListOfSplittingFaces);
  void SetBodyToSplit(CATBody * iBodyToSplit) {_Part = iBodyToSplit;}

  CATSurface * GetSplittingSurface() {return _SplitSurface;}
  CATBody * GetSplittingBody() {return _SplitBody;}
  ListPOfCATFace GetListOfSplittingFaces() {return _ListOfSplittingFaces;}
  CATBody * GetBodyToSplit() {return _Part;}

  virtual void SetExtrapolationMode(CATDynExtrapolationMode iExtrapolMode);
  void SetExtrapolMode(short iExtrapolMode);

  virtual void SetExtrapolationLimit(CATDynExtrapolationLimit iExtrapolLimit); 
  void SetExtrapolLimit(short iExtrapolLimit);

  virtual void SetSelectionMode(CATDynSelectionMode iSelectionMode);

  CATDynExtrapolationMode GetExtrapolationMode();
  CATDynSelectionMode GetSelectionMode() {return _SelectionMode;}
  CATDynSplitType GetSplitType() {return _Operation;}
  
  INLINE void SetNoVolumicSimplif(CATBoolean iNoVolumicSimplif);
  INLINE void SetLumpPropagation(CATBoolean iLumpPropagation);

  virtual int  Run();
  
  virtual void GetUnknownPositionCells(CATLISTP(CATCell)& iUnknownPositionCells);
  virtual CATBoolean GetRelimitation();

  void RattrapJournal(CATTopData* iTopData);

  INLINE void SetRelimitationDiag(CATBoolean iDiag);
  INLINE void SetUnknownPositionPolyCells(CATLISTP(CATCell)& iUnknownPositionPolyCells);
  
   static const CATString * GetDefaultOperatorId() { return & _OperatorId; };

  static short ConvertSplitType(CATDynSplitType iDynSplitType);

  //-----------------------------------------------------------------------
  //- Gestion Mode Record 
  //-----------------------------------------------------------------------  
  static CATString _OperatorId;
	const CATString * GetOperatorId();
  CATExtCGMReplay *IsRecordable(short & LevelOfRuntime, short &VersionOfStream);
  void WriteInput(CATCGMStream  & ioStream);
  void WriteOutput(CATCGMStream & ioStream);
	CATBoolean ValidateOutput(CATCGMStream& ioStream, CATCGMOutput& os);
  void Dump( CATCGMOutput& os ) ;
  int RunOperator();
  void RequireDefinitionOfInputAndOutputObjects();
  virtual CATCGMOperator::CATCheckDiagnostic CheckOutput(CATCGMOutput & os);
  void SetCGMReplayStreamVersion(short iCGMReplayStreamVersion);
  void WriteTopOutput(CATCGMStream & Str);
  CATTopCheckJournal * ReadTopOutput(CATCGMStream &Str);
  virtual CATBoolean ValidateTopOutput(CATTopCheckJournal* iEquivalent,CATCGMOutput& os);
  
#ifdef CATIAR419   
   // Hybrid Management
   // Exact only
   virtual int RunExactOperator();
   // With Polyhedral data
   virtual int RunPolyOperator();
#endif

  // Authorized members only
  //----------------------------------------
 protected:
  CATDynSplitType          _Operation;
  CATDynSelectionMode      _SelectionMode;
  CATBody*                 _Part; 
  CATSurface*              _SplitSurface; 
  CATBody*                 _SplitBody;
  ListPOfCATFace           _ListOfSplittingFaces;
  CATLISTP(CATCell)        _UnknownPositionCells;
  CATBoolean               _Relimitation;
  CATDynExtrapolationMode  _ExtrapolMode; // No extrapolation, C1 or C2 extrapolation.
  CATBoolean               _NoVolumicSimplif;
  CATBoolean               _LumpPropagation;

  // Extrapolation to bounding box or Through next part such that extrapolation is connected to shell before extrapolation.
  CATDynExtrapolationLimit _ExtrapolLimit; 

  CATBoolean               _ExtrapolDone;

  CATCGMJournalList* _WorkingJournal;

  CATCGMJournalList* GetWorkingJournal();
  void DebugSplit(CATBody* iSplitEntity, CATBoolean iDelBP);

  short GetCGMReplayStreamVersion();

  //------------------------------------------------------------------
  //Deprecated methods
  //------------------------------------------------------------------
  CATBody * Deprecated_SplitInternal();
  CATBody * Deprecated_SplitWithBody();
  CATBody * Deprecated_SplitWithSurface();
  CATBody * Deprecated_SplitWithExtrapolatedSplitBody();

private:
  short _CGMReplayStreamVersion;
  CATBoolean _ReferenceBodyExists;
  CATBoolean _NewMode;
};

// methods inline
// --------------
INLINE void CATDynSolidSplitCGM::SetRelimitationDiag(CATBoolean iDiag) {
  _Relimitation = iDiag; }

INLINE void CATDynSolidSplitCGM::SetUnknownPositionPolyCells(CATLISTP(CATCell)& iUnknownPositionPolyCells) {
  _UnknownPositionCells.Append(iUnknownPositionPolyCells); }

INLINE void CATDynSolidSplitCGM::SetNoVolumicSimplif(CATBoolean iNoVolumicSimplif)
{
  _NoVolumicSimplif = iNoVolumicSimplif;
}

INLINE void CATDynSolidSplitCGM::SetLumpPropagation(CATBoolean iLumpPropagation)
{
  _LumpPropagation = iLumpPropagation;
}
#endif
