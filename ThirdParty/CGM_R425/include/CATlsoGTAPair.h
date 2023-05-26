#ifndef CATlsoGTAPair_H
#define CATlsoGTAPair_H

#include "CATBoolean.h"
#include "CATCGMNewArray.h"
#include "CATlsoGTAPseudoFace.h"
#include "CATSysErrorDef.h"
#include "ListPOfCATlsoGTAPair.h"

class CATFace;
class CATCGMStream;
class CATSoftwareConfiguration;

#define GTAPairType          CATlsoGTAPair::PairType
#define GTAPairUnknowType    CATlsoGTAPair::UNKNOWN
#define GTAPairPerfectType   CATlsoGTAPair::PERFECT
#define GTAPairInfrontType   CATlsoGTAPair::INFRONT
#define GTAPairComplexType   CATlsoGTAPair::COMPLEX


#define GTASimplePairType          CATlsoGTASimplePair::PairType
#define GTASimplePairUnknowType    CATlsoGTASimplePair::UNKNOWN
#define GTASimplePairPerfectType   CATlsoGTASimplePair::PERFECT
#define GTASimplePairInfrontType   CATlsoGTASimplePair::INFRONT
#define GTASimplePairComplexType   CATlsoGTASimplePair::COMPLEX



#define GTAPairTrustLevel GTAPair_TrustLevel

// =============================================================================
// ===                           CATlsoGTAPair                               ===
// =============================================================================
// -----------------------------------------------------------------------------
//  Structure storing Pairs of CATlsoGTAPseudoFaces and associated results
// -----------------------------------------------------------------------------
class CATlsoGTAPair
{

public:

  // Constructors
  // ============
  CATlsoGTAPair (CATlsoGTAPseudoFace * ipPseudoFace1,
                 CATlsoGTAPseudoFace * ipPseudoFace2,
                 CATSoftwareConfiguration* iConfig,
                 CATLONG32 iPersistentTag=0,
                 double iEps=0 );
  CATlsoGTAPair (CATlsoGTAPair * ipGTAPair);
  // New Overload
  CATCGMNewClassArrayDeclare;

  // Destructor
  // ==========
  ~CATlsoGTAPair ();

  // GTAPair type
  enum PairType {
    UNKNOWN = 0,
    PERFECT = 1,
    INFRONT = 2,
    COMPLEX = 3
  };

  // Get Methods
  // ===========
  INLINE CATSoftwareConfiguration* GetSoftwareConfiguration() const;
  INLINE CATFace &             GetFace1 () const;
  INLINE CATFace &             GetFace2 () const;
  INLINE CATlsoGTAPseudoFace & GetPseudoFace1 () const;
  INLINE CATlsoGTAPseudoFace & GetPseudoFace2 () const;
  INLINE CATLONG32             GetPersistentTag () const;
  INLINE double                GetThicknessLowerApprox () const;
  INLINE double                GetThicknessUpperApprox () const;
  INLINE double                GetVerticalDistance () const;
  INLINE double                GetEpsForLengthTest () const;
  double                       GetImpactRadiusSum () const;
  INLINE CATBoolean            IsMarked () const;
  INLINE GTAPairType           GetPairType() const;
         CATBoolean            IsParallelPlanar () const;
         CATBoolean            IsOffset() const;
         double                GetOffsetValueIfExists() const;
         CATBoolean            IsConcentricCylinder() const;
         CATBoolean            HasOneCenterInside () const;
         double                GetCentersSquareDistance () const;
  INLINE CATBoolean            IsValidPair();
  // Set Methods
  // ===========
  INLINE void                  SetThicknessLowerApprox (const double & iThicknessLowerApprox);
  INLINE void                  SetThicknessUpperApprox (const double& iThicknessUpperApprox);
  INLINE void                  SetVerticalDistance (const double & iVerticalDistance);
  INLINE void                  Mark ();
  INLINE void                  UnMark ();
  INLINE void                  SetValidPair ();
  void                         SetPairType(GTAPairType iType);

  // Comparison Methods
  // ==================
  static int CompareThickness (CATlsoGTAPair * ipGTAPair1, CATlsoGTAPair * ipGTAPair2, int iCompareType);
  static int CompareMinThickness(CATlsoGTAPair* ipGTAPair1, CATlsoGTAPair* ipGTAPair2);
  static int CompareMaxThickness(CATlsoGTAPair* ipGTAPair1, CATlsoGTAPair* ipGTAPair2);
  static int CompareCentersDistances (CATlsoGTAPair* ipGTAPair1, CATlsoGTAPair* ipGTAPair2);

  // Debug Methods
  // +++++++++++++
  void DisplayPair (int (* iColor)[3]) const;
  void DisplayPairLink (CATGeoFactory *iFactory) const;
  void DisplayThickness (CATGeoFactory *iFactory) const;
  void DumpPairType(CATCGMOutput& os) const;

  // Stream
  // ======
  HRESULT StreamGTASimplePairInput (CATCGMStream &ioStream) const;

private:

  // Internal data
  // =============
  CATlsoGTAPseudoFace * _pPseudoFace1;
  CATlsoGTAPseudoFace * _pPseudoFace2;
  CATSoftwareConfiguration* _Config;
  CATLONG32             _PersistentTag;
  double                _ThicknessLowerApprox;
  double                _ThicknessUpperApprox;
  double                _VerticalDistance;
  double                _EpsForLengthTest;
  CATBoolean            _IsMarked;
  CATBoolean            _IsValidPair;
  GTAPairType           _PairType; 
};

// Inline Methods
// ==============

INLINE CATSoftwareConfiguration* CATlsoGTAPair::GetSoftwareConfiguration() const {
  return _Config;
}

INLINE CATFace & CATlsoGTAPair::GetFace1 () const {
  CATlsoAssert (_pPseudoFace1);
  return _pPseudoFace1->GetFace ();
}

INLINE CATFace & CATlsoGTAPair::GetFace2 () const {
  CATlsoAssert (_pPseudoFace2);
  return _pPseudoFace2->GetFace ();
}

INLINE CATlsoGTAPseudoFace & CATlsoGTAPair::GetPseudoFace1 () const {
  CATlsoAssert (_pPseudoFace1);
  return *_pPseudoFace1;
}

INLINE CATlsoGTAPseudoFace & CATlsoGTAPair::GetPseudoFace2 () const {
  CATlsoAssert (_pPseudoFace2);
  return *_pPseudoFace2;
}

INLINE CATLONG32 CATlsoGTAPair::GetPersistentTag () const {
  return _PersistentTag;
}

INLINE double CATlsoGTAPair::GetThicknessLowerApprox () const {
  return _ThicknessLowerApprox;
}

INLINE double CATlsoGTAPair::GetThicknessUpperApprox () const {
  return _ThicknessUpperApprox;
}

INLINE double CATlsoGTAPair::GetVerticalDistance () const {
  return _VerticalDistance;
}

INLINE double CATlsoGTAPair::GetEpsForLengthTest () const {
  return _EpsForLengthTest;
}

INLINE GTAPairType CATlsoGTAPair::GetPairType() const {
  return _PairType;
}

INLINE CATBoolean CATlsoGTAPair::IsMarked () const {
  return _IsMarked;
}

INLINE void CATlsoGTAPair::SetThicknessLowerApprox (const double & iThicknessLowerApprox) {
  _ThicknessLowerApprox = iThicknessLowerApprox;
}

INLINE void CATlsoGTAPair::SetThicknessUpperApprox (const double& iThicknessUpperApprox) {
  _ThicknessUpperApprox = iThicknessUpperApprox;
}

INLINE void CATlsoGTAPair::SetVerticalDistance (const double & iVerticalDistance) {
  _VerticalDistance = iVerticalDistance;
}

INLINE void CATlsoGTAPair::Mark () {
  _IsMarked = TRUE;
}

INLINE void CATlsoGTAPair::UnMark () {
  _IsMarked = FALSE;
}

INLINE void CATlsoGTAPair::SetValidPair() {
  _IsValidPair = TRUE;
}

INLINE CATBoolean CATlsoGTAPair::IsValidPair() {
  return _IsValidPair;
}

// -----------------------------------------------------------------------------
// =============================================================================


// =============================================================================
// ===                          CATlsoGTASimplePair                              ===
// =============================================================================
// -----------------------------------------------------------------------------
//   Simplified Pair Structure for output and Multi Process Stream
// -----------------------------------------------------------------------------

class CATlsoGTASimplePair
{

public:

  // Constructors
  // ============
  CATlsoGTASimplePair ();
  CATlsoGTASimplePair (const CATlsoGTAPair & iGTAPair);
  CATlsoGTASimplePair (const CATlsoGTASimplePair & iGTASimplePair);
  // New overload
  CATCGMNewClassArrayDeclare;

  // Destructor
  // ==========
  ~CATlsoGTASimplePair ();

  // GTAPair type
  enum PairType {
    UNKNOWN = 0,
    PERFECT = 1,
    INFRONT = 2,
    COMPLEX = 3
  };

  // Get Methods
  // ============
  INLINE CATFace * GetFace1 () const;
  INLINE CATFace * GetFace2 () const;
  INLINE CATLONG32 GetPersistentTag () const;
  INLINE double    GetThicknessLowerApprox () const;
  INLINE double    GetThicknessUpperApprox () const;
  INLINE GTASimplePairType  GetPairType() const;

  // Set Methods
  // ===========
  INLINE void SetFace1 (CATFace * ipFace);
  INLINE void SetFace2 (CATFace * ipFace);
  INLINE void SetPersistentTag (CATLONG32 & iIndex);
  INLINE void SetThicknessLowerApprox (double & iThicknessLowerApprox);
  INLINE void SetThicknessUpperApprox (double & iThicknessUpperApprox);
  INLINE void SetPairType(GTASimplePairType iType);

  // Comparison
  // ==========
  CATBoolean IsEqual (const CATlsoGTASimplePair & iGTASimplePair, const double iTolerance) const;
  CATBoolean IsSameFaces (const CATlsoGTASimplePair & iGTASimplePair) const;
  CATBoolean IsSameMaxDistance (const CATlsoGTASimplePair & iGTASimplePair, const double iTolerance) const;

  // For CGMReplay
  // =============
  void Dump (CATCGMOutput & os) const;
  void DumpPairType(CATCGMOutput& os) const;
  void DumpPairDistanceInfo(CATCGMOutput& os) const;
  void DumpFaces (CATCGMOutput & os) const;
  void DumpDifferences (const CATlsoGTASimplePair & iGTASimplePair, const double iTolerance, CATCGMOutput & os) const;
  static CATBoolean AreSameLists (const ListPOfCATlsoGTASimplePair & iList1, const ListPOfCATlsoGTASimplePair & iList2, const double iTolerance);
  static void       CompareLists (const ListPOfCATlsoGTASimplePair & iOutputList, const ListPOfCATlsoGTASimplePair & iReferenceList, const double iTolerance, CATCGMOutput & os);

  // Stream / Unstream
  // =================
  HRESULT StreamGTASimplePair         (CATCGMStream & ioStream) const;
  HRESULT StreamGTASimplePairOutput   (CATCGMStream & ioStream) const;
  HRESULT UnStreamGTASimplePair (CATCGMStream & ioStream, CATGeoFactory * ipFactory);
  HRESULT UnStreamGTASimplePairInput  (CATCGMStream & ioStream, CATGeoFactory * ipFactory);
  HRESULT UnStreamGTASimplePairOutput (CATCGMStream & ioStream);
  static HRESULT StreamGTASimplePairList (const ListPOfCATlsoGTASimplePair & iGTASimplePairList, CATCGMStream & ioStream);
  static HRESULT UnStreamGTASimplePairList (ListPOfCATlsoGTASimplePair & oGTASimplePairList, CATCGMStream & ioStream, CATGeoFactory * ipFactory);

private:

  // Internal Data
  // =============
  // Inputs
  CATFace * _pFace1;        // Input
  CATFace * _pFace2;        // Input
  CATLONG32 _PersistentTag;  // Input/Output
  // Outputs
  double _ThicknessLowerApprox;
  double _ThicknessUpperApprox;

  // Dump
  GTASimplePairType _PairType;
  GTAPseudoFaceType _FaceType1;
  GTAPseudoFaceType _FaceType2;
  CATMathVector         _CenterNormal1;
  CATMathVector         _CenterNormal2;
  double                _HorizontalDistance;
  double                _VerticalDistance;
  double                _ImpactRadius1;
  double                _ImpactRadius2;
};

// Inline Methods
// ==============

INLINE CATFace * CATlsoGTASimplePair::GetFace1 () const {
  return _pFace1;
}

INLINE CATFace * CATlsoGTASimplePair::GetFace2 () const {
  return _pFace2;
}

INLINE CATLONG32 CATlsoGTASimplePair::GetPersistentTag () const {
  return _PersistentTag;
}

INLINE double CATlsoGTASimplePair::GetThicknessLowerApprox () const {
  return _ThicknessLowerApprox;
}

INLINE double CATlsoGTASimplePair::GetThicknessUpperApprox () const {
  return _ThicknessUpperApprox;
}

INLINE GTASimplePairType CATlsoGTASimplePair::GetPairType() const {
  return _PairType;
}

INLINE void CATlsoGTASimplePair::SetFace1 (CATFace * ipFace) {
  _pFace1 = ipFace;
}

INLINE void CATlsoGTASimplePair::SetFace2 (CATFace * ipFace) {
  _pFace2 = ipFace;
}

INLINE void CATlsoGTASimplePair::SetPersistentTag (CATLONG32 & iIndex) {
  _PersistentTag = iIndex;
}

INLINE void CATlsoGTASimplePair::SetThicknessLowerApprox (double & iThicknessLowerApprox) {
  _ThicknessLowerApprox = iThicknessLowerApprox;
}

INLINE void CATlsoGTASimplePair::SetThicknessUpperApprox (double& iThicknessUpperApprox) {
  _ThicknessUpperApprox = iThicknessUpperApprox;
}

INLINE void CATlsoGTASimplePair::SetPairType(GTASimplePairType iType) {
  _PairType = iType;
}


// -----------------------------------------------------------------------------
// =============================================================================

#endif

