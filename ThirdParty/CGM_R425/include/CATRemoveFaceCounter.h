// COPYRIGHT DASSAULT SYSTEMES 2019, ALL RIGHTS RESERVED.
//=============================================================================
//
// RESPONSIBLE  : ZUT
//
// DESCRIPTION  : Class used to trace all the calls made to the operators of the RemoveFace 'Familly' (singleton)
//
//=============================================================================
// Creation ZUT June 2019
//=============================================================================

#ifndef CATRemoveFaceCounter_H
#define CATRemoveFaceCounter_H

// ++++ Includes ++++
#include "Thick.h"
#include "IUnknown.h" // For NULL definition (linux)
#include "CATDataType.h"
#include "CATMathInline.h"

// ++++ Predeclarations ++++
class CATCGMOutput;
class CATCGMOperator;

// ++++ MACROS ++++
#define RF_COUNTER_ON 1

#ifdef RF_COUNTER_ON
#define RF_COUNTER_Reset()                         CATRemoveFaceCounter::GetInstance().Reset()
#define RF_COUNTER_SetMainOperator(iMainOpe)       CATRemoveFaceCounter::GetInstance().SetMainOperator(iMainOpe)
#define RF_COUNTER_Dump(oStr)                      CATRemoveFaceCounter::GetInstance().Dump(oStr)
#define RF_COUNTER_DumpIf(iCurOpe,oStr)            CATRemoveFaceCounter::GetInstance().DumpIf(iCurOpe,oStr)
#define RF_COUNTER_IncrRemoveFaceCalls()           CATRemoveFaceCounter::GetInstance().IncrRemoveFaceCalls()
#define RF_COUNTER_IncrRemoveFaceSuccess()         CATRemoveFaceCounter::GetInstance().IncrRemoveFaceSuccess()
#define RF_COUNTER_IncrRemoveFaceFailures()        CATRemoveFaceCounter::GetInstance().IncrRemoveFaceFailures()
#define RF_COUNTER_IncrLocalRemoveFaceAttempts()   CATRemoveFaceCounter::GetInstance().IncrLocalRemoveFaceAttempts()
#define RF_COUNTER_IncrLocalRemoveFaceCandidates() CATRemoveFaceCounter::GetInstance().IncrLocalRemoveFaceCandidates()
#define RF_COUNTER_IncrLocalRemoveFaceSuccess()    CATRemoveFaceCounter::GetInstance().IncrLocalRemoveFaceSuccess()
#define RF_COUNTER_IncrRemoveFacePlusCalls()       CATRemoveFaceCounter::GetInstance().IncrRemoveFacePlusCalls()
#define RF_COUNTER_IncrSecondRemoveFaceAttempts()  CATRemoveFaceCounter::GetInstance().IncrSecondRemoveFaceAttempts()
#define RF_COUNTER_IncrSecondRemoveFaceSuccess()   CATRemoveFaceCounter::GetInstance().IncrSecondRemoveFaceSuccess()
#define RF_COUNTER_IncrAdvancedRemoveFaceCalls()   CATRemoveFaceCounter::GetInstance().IncrAdvancedRemoveFaceCalls()
#define RF_COUNTER_IncrSingleRemoveFaceCalls()     CATRemoveFaceCounter::GetInstance().IncrSingleRemoveFaceCalls()
#define RF_COUNTER_IncrRegularizationCalls()       CATRemoveFaceCounter::GetInstance().IncrRegularizationCalls()
#define RF_COUNTER_IncrRemoveFaceG1G2Calls()       CATRemoveFaceCounter::GetInstance().IncrRemoveFaceG1G2Calls()
#define RF_COUNTER_IncrInitilizationFailures()     CATRemoveFaceCounter::GetInstance().IncrInitilizationFailures()
#define RF_COUNTER_IncrG2G2Zones()                 CATRemoveFaceCounter::GetInstance().IncrG2G2Zones()
#define RF_COUNTER_IncrG1G2Zones()                 CATRemoveFaceCounter::GetInstance().IncrG1G2Zones()
#define RF_COUNTER_IncrG1G1Zones()                 CATRemoveFaceCounter::GetInstance().IncrG1G1Zones()
#define RF_COUNTER_IncrTTgtZones()                 CATRemoveFaceCounter::GetInstance().IncrTTgtZones()
#define RF_COUNTER_IncrG1G2BackupCalls()           CATRemoveFaceCounter::GetInstance().IncrG1G2BackupCalls()
#define RF_COUNTER_NbRemoveFaceCalls()             CATRemoveFaceCounter::GetInstance().GetNbRemoveFaceCalls()
#define RF_COUNTER_NbRemoveFaceSuccess()           CATRemoveFaceCounter::GetInstance().GetNbRemoveFaceSuccess()
#define RF_COUNTER_NbRemoveFaceFailures()          CATRemoveFaceCounter::GetInstance().GetNbRemoveFaceFailures()
#define RF_COUNTER_NbLocalRemoveFaceAttempts()     CATRemoveFaceCounter::GetInstance().GetNbLocalRemoveFaceAttempts()
#define RF_COUNTER_NbLocalRemoveFaceCandidates()   CATRemoveFaceCounter::GetInstance().GetNbLocalRemoveFaceCandidates()
#define RF_COUNTER_NbLocalRemoveFaceSuccess()      CATRemoveFaceCounter::GetInstance().GetNbLocalRemoveFaceSuccess()
#define RF_COUNTER_NbRemoveFacePlusCalls()         CATRemoveFaceCounter::GetInstance().GetNbRemoveFacePlusCalls()
#define RF_COUNTER_NbSecondRemoveFaceAttempts()    CATRemoveFaceCounter::GetInstance().GetNbSecondRemoveFaceAttempts()
#define RF_COUNTER_NbSecondRemoveFaceSuccess()     CATRemoveFaceCounter::GetInstance().GetNbSecondRemoveFaceSuccess()
#define RF_COUNTER_NbAdvancedRemoveFaceCalls()     CATRemoveFaceCounter::GetInstance().GetNbAdvancedRemoveFaceCalls()
#define RF_COUNTER_NbSingleRemoveFaceCalls()       CATRemoveFaceCounter::GetInstance().GetNbSingleRemoveFaceCalls()
#define RF_COUNTER_NbRegularizationCalls()         CATRemoveFaceCounter::GetInstance().GetNbRegularizationCalls()
#define RF_COUNTER_NbRemoveFaceG1G2Calls()         CATRemoveFaceCounter::GetInstance().GetNbRemoveFaceG1G2Calls()
#define RF_COUNTER_NbInitilizationFailures()       CATRemoveFaceCounter::GetInstance().GetNbInitilizationFailures()
#define RF_COUNTER_NbG2G2Zones()                   CATRemoveFaceCounter::GetInstance().GetNbG2G2Zones()
#define RF_COUNTER_NbG1G2Zones()                   CATRemoveFaceCounter::GetInstance().GetNbG1G2Zones()
#define RF_COUNTER_NbG1G1Zones()                   CATRemoveFaceCounter::GetInstance().GetNbG1G1Zones()
#define RF_COUNTER_NbTTgtZones()                   CATRemoveFaceCounter::GetInstance().GetNbTTgtZones()
#define RF_COUNTER_NbG1G2BackupCalls()             CATRemoveFaceCounter::GetInstance().GetNbG1G2BackupCalls()
#else
#define RF_COUNTER_Reset()
#define RF_COUNTER_SetMainOperator(iMainOpe)
#define RF_COUNTER_Dump(oStr)
#define RF_COUNTER_DumpIf(iCurOpe,oStr)
#define RF_COUNTER_IncrRemoveFaceCalls()
#define RF_COUNTER_IncrRemoveFaceSuccess()
#define RF_COUNTER_IncrRemoveFaceFailures()
#define RF_COUNTER_IncrLocalRemoveFaceAttempts()
#define RF_COUNTER_IncrLocalRemoveFaceCandidates()
#define RF_COUNTER_IncrLocalRemoveFaceSuccess()
#define RF_COUNTER_IncrRemoveFacePlusCalls()
#define RF_COUNTER_IncrSecondRemoveFaceAttempts()
#define RF_COUNTER_IncrSecondRemoveFaceSuccess()
#define RF_COUNTER_IncrAdvancedRemoveFaceCalls()
#define RF_COUNTER_IncrSingleRemoveFaceCalls()
#define RF_COUNTER_IncrRegularizationCalls()
#define RF_COUNTER_IncrRemoveFaceG1G2Calls()
#define RF_COUNTER_IncrInitilizationFailures()
#define RF_COUNTER_IncrG2G2Zones()
#define RF_COUNTER_IncrG1G2Zones()
#define RF_COUNTER_IncrG1G1Zones()
#define RF_COUNTER_IncrTTgtZones()
#define RF_COUNTER_IncrG1G2BackupCalls()
#define RF_COUNTER_NbRemoveFaceCalls()           0
#define RF_COUNTER_NbRemoveFaceSuccess()         0
#define RF_COUNTER_NbRemoveFaceFailures()        0
#define RF_COUNTER_NbLocalRemoveFaceAttempts()   0
#define RF_COUNTER_NbLocalRemoveFaceCandidates() 0
#define RF_COUNTER_NbLocalRemoveFaceSuccess()    0
#define RF_COUNTER_NbRemoveFacePlusCalls()       0
#define RF_COUNTER_NbSecondRemoveFaceAttempts()  0
#define RF_COUNTER_NbSecondRemoveFaceSuccess()   0
#define RF_COUNTER_NbAdvancedRemoveFaceCalls()   0
#define RF_COUNTER_NbSingleRemoveFaceCalls()     0
#define RF_COUNTER_NbRegularizationCalls()       0
#define RF_COUNTER_NbRemoveFaceG1G2Calls()       0
#define RF_COUNTER_NbInitilizationFailures()     0
#define RF_COUNTER_NbG2G2Zones()                 0
#define RF_COUNTER_NbG1G2Zones()                 0
#define RF_COUNTER_NbG1G1Zones()                 0
#define RF_COUNTER_NbTTgtZones()                 0
#define RF_COUNTER_NbG1G2BackupCalls()           0
#endif

// ++++ class definition ++++

class ExportedByThick CATRemoveFaceCounter
{
public:

  /**
  * Destructor
  */
  virtual ~CATRemoveFaceCounter();

  /**
  * Reset
  */
  void Reset();

  /**
  * Dump
  */
  void Dump( CATCGMOutput & oStr );

  /**
  * DumpIf
  */
  void DumpIf( CATCGMOperator * iCurrentOperator, CATCGMOutput & oStr );

  //---------------------------------------------------------------------------
  // STATIC METHODS
  //---------------------------------------------------------------------------

  static CATRemoveFaceCounter & GetInstance();

  //---------------------------------------------------------------------------
  // INLINE METHODS
  //---------------------------------------------------------------------------

  void SetMainOperator( CATCGMOperator * iMainOperator );

  void IncrRemoveFaceCalls();
  void IncrRemoveFaceSuccess();
  void IncrRemoveFaceFailures();
  void IncrLocalRemoveFaceAttempts();
  void IncrLocalRemoveFaceCandidates();
  void IncrLocalRemoveFaceSuccess();
  void IncrRemoveFacePlusCalls();
  void IncrSecondRemoveFaceAttempts();
  void IncrSecondRemoveFaceSuccess();
  void IncrAdvancedRemoveFaceCalls();
  void IncrSingleRemoveFaceCalls();
  void IncrRegularizationCalls();
  void IncrRemoveFaceG1G2Calls();
  void IncrInitilizationFailures();
  void IncrG2G2Zones();
  void IncrG1G2Zones();
  void IncrG1G1Zones();
  void IncrTTgtZones();
  void IncrG1G2BackupCalls();

  CATLONG32 GetNbRemoveFaceCalls() const;
  CATLONG32 GetNbRemoveFaceSuccess() const;
  CATLONG32 GetNbRemoveFaceFailures() const;
  CATLONG32 GetNbLocalRemoveFaceAttempts() const;
  CATLONG32 GetNbLocalRemoveFaceCandidates() const;
  CATLONG32 GetNbLocalRemoveFaceSuccess() const;
  CATLONG32 GetNbRemoveFacePlusCalls() const;
  CATLONG32 GetNbSecondRemoveFaceAttempts() const;
  CATLONG32 GetNbSecondRemoveFaceSuccess() const;
  CATLONG32 GetNbAdvancedRemoveFaceCalls() const;
  CATLONG32 GetNbSingleRemoveFaceCalls() const;
  CATLONG32 GetNbRegularizationCalls() const;
  CATLONG32 GetNbRemoveFaceG1G2Calls() const;
  CATLONG32 GetNbInitilizationFailures() const;
  CATLONG32 GetNbG2G2Zones() const;
  CATLONG32 GetNbG1G2Zones() const;
  CATLONG32 GetNbG1G1Zones() const;
  CATLONG32 GetNbTTgtZones() const;
  CATLONG32 GetNbG1G2BackupCalls() const;

protected: 

  //---------------------------------------------------------------------------
  // PROTECTED METHODS
  //---------------------------------------------------------------------------

  /**
  * Constructor
  */
  CATRemoveFaceCounter();

  //---------------------------------------------------------------------------
  // PROTECTED DATA MEMBERS
  //---------------------------------------------------------------------------

  CATCGMOperator * _MainOperator;

  // CATRemoveFace
  CATLONG32 _NbRemoveFaceCalls;
  CATLONG32 _NbRemoveFaceSuccess;
  CATLONG32 _NbRemoveFaceFailures;

  // CATLocalRemoveFace
  CATLONG32 _NbLocalRemoveFaceAttempts;
  CATLONG32 _NbLocalRemoveFaceCandidates;
  CATLONG32 _NbLocalRemoveFaceSuccess;

  // CATRemoveFacePlus
  CATLONG32 _NbRemoveFacePlusCalls;
  CATLONG32 _NbSecondRemoveFaceAttempts;
  CATLONG32 _NbSecondRemoveFaceSuccess;

  // CATAdvancedRemoveFace
  CATLONG32 _NbAdvancedRemoveFaceCalls;
  CATLONG32 _NbSingleRemoveFaceCalls;
  CATLONG32 _NbRegularizationCalls;
  
  // CATRemoveFaceG1G2
  CATLONG32 _NbRemoveFaceG1G2Calls;
  CATLONG32 _NbInitilizationFailures;
  CATLONG32 _NbG2G2Zones;
  CATLONG32 _NbG1G2Zones;
  CATLONG32 _NbG1G1Zones;
  CATLONG32 _NbTTgtZones;
  CATLONG32 _NbG1G2BackupCalls;
};

//-----------------------------------------------------------------------------
// INLINE IMPLEMENTATIONS
//-----------------------------------------------------------------------------

INLINE void CATRemoveFaceCounter::SetMainOperator( CATCGMOperator * iMainOperator ) {
  _MainOperator = iMainOperator; }

INLINE void CATRemoveFaceCounter::IncrRemoveFaceCalls() {
  _NbRemoveFaceCalls++; }

INLINE void CATRemoveFaceCounter::IncrRemoveFaceSuccess() {
  _NbRemoveFaceSuccess++; }

INLINE void CATRemoveFaceCounter::IncrRemoveFaceFailures() {
  _NbRemoveFaceFailures++; }

INLINE void CATRemoveFaceCounter::IncrLocalRemoveFaceAttempts() {
  _NbLocalRemoveFaceAttempts++; }

INLINE void CATRemoveFaceCounter::IncrLocalRemoveFaceCandidates() {
  _NbLocalRemoveFaceCandidates++; }

INLINE void CATRemoveFaceCounter::IncrLocalRemoveFaceSuccess() {
  _NbLocalRemoveFaceSuccess++; }

INLINE void CATRemoveFaceCounter::IncrRemoveFacePlusCalls() {
  _NbRemoveFacePlusCalls++; }

INLINE void CATRemoveFaceCounter::IncrSecondRemoveFaceAttempts() {
  _NbSecondRemoveFaceAttempts++; }

INLINE void CATRemoveFaceCounter::IncrSecondRemoveFaceSuccess() {
  _NbSecondRemoveFaceSuccess++; }

INLINE void CATRemoveFaceCounter::IncrAdvancedRemoveFaceCalls() {
  _NbAdvancedRemoveFaceCalls++; }

INLINE void CATRemoveFaceCounter::IncrSingleRemoveFaceCalls() {
  _NbSingleRemoveFaceCalls++; }

INLINE void CATRemoveFaceCounter::IncrRegularizationCalls() {
  _NbRegularizationCalls++; }

INLINE void CATRemoveFaceCounter::IncrRemoveFaceG1G2Calls() {
  _NbRemoveFaceG1G2Calls++; }

INLINE void CATRemoveFaceCounter::IncrInitilizationFailures() {
  _NbInitilizationFailures++; }

INLINE void CATRemoveFaceCounter::IncrG2G2Zones() {
  _NbG2G2Zones++; }

INLINE void CATRemoveFaceCounter::IncrG1G2Zones() {
  _NbG1G2Zones++; }

INLINE void CATRemoveFaceCounter::IncrG1G1Zones() {
  _NbG1G1Zones++; }

INLINE void CATRemoveFaceCounter::IncrTTgtZones() {
  _NbTTgtZones++; }

INLINE void CATRemoveFaceCounter::IncrG1G2BackupCalls() {
  _NbG1G2BackupCalls++; }

INLINE CATLONG32 CATRemoveFaceCounter::GetNbRemoveFaceCalls() const {
  return _NbRemoveFaceCalls; }

INLINE CATLONG32 CATRemoveFaceCounter::GetNbRemoveFaceSuccess() const {
  return _NbRemoveFaceSuccess; }

INLINE CATLONG32 CATRemoveFaceCounter::GetNbRemoveFaceFailures() const {
  return _NbRemoveFaceFailures; }

INLINE CATLONG32 CATRemoveFaceCounter::GetNbLocalRemoveFaceAttempts() const {
  return _NbLocalRemoveFaceAttempts; }

INLINE CATLONG32 CATRemoveFaceCounter::GetNbLocalRemoveFaceCandidates() const {
  return _NbLocalRemoveFaceCandidates; }

INLINE CATLONG32 CATRemoveFaceCounter::GetNbLocalRemoveFaceSuccess() const {
  return _NbLocalRemoveFaceSuccess; }

INLINE CATLONG32 CATRemoveFaceCounter::GetNbRemoveFacePlusCalls() const {
  return _NbRemoveFacePlusCalls; }

INLINE CATLONG32 CATRemoveFaceCounter::GetNbSecondRemoveFaceAttempts() const {
  return _NbSecondRemoveFaceAttempts; }

INLINE CATLONG32 CATRemoveFaceCounter::GetNbSecondRemoveFaceSuccess() const {
  return _NbSecondRemoveFaceSuccess; }

INLINE CATLONG32 CATRemoveFaceCounter::GetNbAdvancedRemoveFaceCalls() const {
  return _NbAdvancedRemoveFaceCalls; }

INLINE CATLONG32 CATRemoveFaceCounter::GetNbSingleRemoveFaceCalls() const {
  return _NbSingleRemoveFaceCalls; }

INLINE CATLONG32 CATRemoveFaceCounter::GetNbRegularizationCalls() const {
  return _NbRegularizationCalls; }

INLINE CATLONG32 CATRemoveFaceCounter::GetNbRemoveFaceG1G2Calls() const {
  return _NbRemoveFaceG1G2Calls; }

INLINE CATLONG32 CATRemoveFaceCounter::GetNbInitilizationFailures() const {
  return _NbInitilizationFailures; }

INLINE CATLONG32 CATRemoveFaceCounter::GetNbG2G2Zones() const {
  return _NbG2G2Zones; }

INLINE CATLONG32 CATRemoveFaceCounter::GetNbG1G2Zones() const {
  return _NbG1G2Zones; }

INLINE CATLONG32 CATRemoveFaceCounter::GetNbG1G1Zones() const {
  return _NbG1G1Zones; }

INLINE CATLONG32 CATRemoveFaceCounter::GetNbTTgtZones() const {
  return _NbTTgtZones; }

INLINE CATLONG32 CATRemoveFaceCounter::GetNbG1G2BackupCalls() const {
  return _NbG1G2BackupCalls; }

#endif /* CATRemoveFaceCounter_H */
