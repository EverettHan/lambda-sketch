#ifndef CATlsoGTAPseudoFace_H
#define CATlsoGTAPseudoFace_H

#include "CATCGMNewArray.h"
#include "CATDataType.h"
#include "CATlsoError.h"
#include "CATMathPoint.h"
#include "CATMathVector.h"
#include "ListPOfCATEdge.h"
#include "ListPOfCATVertex.h"
#include "ListPOfCATlsoGTAPair.h"
#include "ListPOfCATlsoGTAPseudoFace.h"
#include "CATBoolean.h"
#include "CATSurParam.h"
#include "CATListValCATSurParam.h"
#include "CATLISTP_CATMathPoint.h"
#include "CATCGMHashTableWithAssoc.h"
#include "CATEdgeHashTable.h"
#include "CATVertexHashTable.h"

class CATGeoFactory;
class CATSoftwareConfiguration;
class CATPoint;
class CATFace;
class CATBody;
class CATMathBox;
class CATMathOBB;
class CATLsoGTAPair;
class CATOffsetSurface;
class CATSurface;

#define GTAPseudoFaceType          CATlsoGTAPseudoFace::PseudoFaceType
#define GTAPseudoFaceUnknowType    CATlsoGTAPseudoFace::UNKNOWN
#define GTAPseudoFacePerfectType   CATlsoGTAPseudoFace::PERFECT
#define GTAPseudoFaceInfrontType   CATlsoGTAPseudoFace::INFRONT
#define GTAPseudoFaceComplexType   CATlsoGTAPseudoFace::COMPLEX

// =============================================================================
// ===                        CATlsoGTAPseudoFace                            ===
// =============================================================================
// -----------------------------------------------------------------------------
//   Structure containing working information relative to a CATFace used in 
// CATGlobalPairingThicknessAnalayser.
// -----------------------------------------------------------------------------

class CATlsoGTAPseudoFace
{

public:

  // Constructor
  // ===========
  CATlsoGTAPseudoFace (double    iEps,
                       CATFace * ipFace,
                       CATLONG32 iPersitentTag);
  // New overload
  CATCGMNewClassArrayDeclare;

  // Destructor
  // ==========
  ~CATlsoGTAPseudoFace ();

  // PseudoFace type
  enum PseudoFaceType {
    UNKNOWN = 0,
    PERFECT = 1,
    INFRONT = 2,
    COMPLEX = 3
  };

  // Get methods
  // ===========
  // Internal Data
  INLINE CATFace & GetFace () const;
         int                            GetEdgeHT (CATEdgeHashTable& oEdgeHT) const;
         int                            GetVertexHT (CATVertexHashTable& oVertexHT) const;
  INLINE CATLONG32                      GetPersistentTag () const;
  INLINE const CATMathPoint &           GetCenterPoint ();
  INLINE double                         GetNumberOfLoops () const;
  INLINE CATBoolean                     IsCenterInside () const;
  INLINE const CATMathVector &          GetCenterNormal ();
  INLINE double                         GetSquaredImpactRadius () const;
  INLINE double                         GetEpsForLengthTest () const;
         CATBoolean                     GetCenterLabel (int iDirection, double & oLabel) const;
  INLINE CATMathOBB *                   GetOBB() const;
  INLINE CATMathOBB *                   GetOffsettedOBB () const;
  INLINE double                         GetCenterInnerMaxOffset () const;
  INLINE double                         GetCenterOuterMaxOffset () const;
  INLINE CATLONG32                      GetNumberOfGTAPairs () const;
         void                           GetMinThicknessMarkedGTAPair (ListPOfCATlsoGTAPair & oGTAPairList) const;
         void                           GetMaxThicknessMarkedGTAPair (ListPOfCATlsoGTAPair & oGTAPairList, double & oThickness) const;
  INLINE CATBoolean                     IsTackled () const;  
  INLINE const ListPOfCATVertex&        GetOuterVertices() const;
         const CATVertexHashTable&      GetVertexHT ();
  INLINE const CATLISTP(CATMathPoint)&  GetAllMathPoints() const;
  INLINE const CATLISTV(CATSurParam)&   GetOuterVertexSurParam() const;
  INLINE PseudoFaceType                 GetPseudoFaceType() const;
  INLINE int                            GetNbInfrontPair() const;
  INLINE CATLONG32                      GetInfrontPseudoFaceTag() const;
         CATBoolean                     IsPlanar (CATSoftwareConfiguration& iConfig) const;
         CATBoolean                     IsCylinder() const;
  INLINE CATBoolean                     IsFinalPairingFace() const;
         int                            GetVertexNormal(CATVertex*& iVertex, CATBody*& iBody, CATMathVector& oNormalVector) const;
         ListPOfCATlsoGTAPseudoFace&    GetPairingPseudoFaceList();
         CATlsoGTAPair*                 GetPairFromOtherFace(CATlsoGTAPseudoFace*& iPseudoFace);
  INLINE void                           GetPairList(ListPOfCATlsoGTAPair& oPairList);
         CATOffsetSurface*              GetOffsetSurfaceIfExists();
         CATSurface*                    GetSurface();
         CATBoolean                     AreOffset(CATSoftwareConfiguration& iConfig, CATlsoGTAPseudoFace & iOtherPseudoFace);
         double                         GetOffsetValueIfExists(CATSoftwareConfiguration& iConfig, CATlsoGTAPseudoFace & iOtherPseudoFace);
         void                           GetReferenceSurfaceAndOffsetValue(CATSoftwareConfiguration& iConfig, CATOffsetSurface & iOffsetSurface, CATSurface *& oRefSurface, double & oOffsetValue);

  // Set methods
  // ===========
  INLINE void                  SetTackled ();
  INLINE void                  SetPseudoFaceType(PseudoFaceType iType);
  INLINE void                  SetInfrontPseudoFaceTag(CATLONG32 iTag);              
  INLINE void                  SetFinalPairingFace();

  // Insert methods
  // ==============
  INLINE void                  InsertGTAPair (CATlsoGTAPair * ipGTAPair);

  // Tests methods
  // =============
  CATBoolean                   BelongToAMarkedGTAPair () const;
  
  // Comparison methods
  // ==================
  static int                   CompareCenterXLabel (CATlsoGTAPseudoFace * iPseudoFace1, CATlsoGTAPseudoFace * iPseudoFace2);
  static int                   CompareCenterYLabel (CATlsoGTAPseudoFace * iPseudoFace1, CATlsoGTAPseudoFace * iPseudoFace2);
  static int                   CompareCenterZLabel (CATlsoGTAPseudoFace * iPseudoFace1, CATlsoGTAPseudoFace * iPseudoFace2);

  // Compute methods
  // ===============
  CATBoolean                   ComputeInternalData (CATBody & iBody, CATGeoFactory & iFactory, CATSoftwareConfiguration & iConfig, const double iOffset, const double iMaxOffsetLimit);
  CATBoolean                   ComputeOuterVertices (CATSoftwareConfiguration & iConfig);
  CATBoolean                   ComputeVertices(CATSoftwareConfiguration& iConfig);
  CATBoolean                   ComputeImpactRadius ();
  CATBoolean                   ComputeOBB (const double iOffset);
  CATBoolean                   ComputeCenterMaxOffset (CATBody & iBody, CATGeoFactory & iFactory, CATSoftwareConfiguration & iConfig, const double iMaxOffsetLimit);
  CATBoolean                   ComputeIsSurParamInside (CATBody & iBody, CATGeoFactory & iFactory, CATSoftwareConfiguration & iConfig, CATSurParam & iSurParam, CATBoolean & oIsInside);

  // Debug Methods
  // +++++++++++++
  void                         DisplayNormal (CATGeoFactory *iFactory) const;
  // +++++++++++++

private:

  // Private methods
 // ===========
  void                         InsertVertexAndSurParam(CATVertex*& iVertex, CATSurParam & iSurParam);

  // Internal data
  // =============
  CATFace *                   _pFace;
  CATSurface *                _pSurface;
  CATLONG32                   _PersistentTag;
  CATMathPoint                _CenterPoint;
  CATSurParam                 _CenterSurParam;
  CATBoolean                  _UpdateCenterWithVertices;
  double                      _NumberOfLoops;
  double                      _UpdatedCenterParamU;
  double                      _UpdatedCenterParamV;
  CATBoolean                  _IsCenterInside;
  ListPOfCATVertex            _ListOfOuterVertices;
  CATVertexHashTable*         _pVertexHT;
  CATLISTP(CATMathPoint)      _ListOfMathPoints;
  CATLISTV(CATSurParam)       _ListOfOuterVertexSurParam;
  CATMathVector               _CenterNormal;
  double                      _SquaredImpactRadius; //CircumscribedCircleRadius
  double                      _EpsForLengthTest;
  ListPOfCATlsoGTAPair        _GTAPairList;
  CATMathOBB *                _OBB;
  CATMathOBB *                _OffsettedOBB;
  double                      _CenterInnerMaxOffset;
  double                      _CenterOuterMaxOffset;
  CATBoolean                  _IsTackled;
  GTAPseudoFaceType           _PseudoFaceType;
  CATLONG32                   _InfrontPseudoFaceTag; // other pseudo face tag in an Infront pair
  int                         _NbInfrontPair;
  CATBoolean                  _IsFinalPairingFace;
  CATCGMHashTableWithAssoc*   _MappingVertexAndSurParam;
  ListPOfCATlsoGTAPseudoFace  _PairingPseudoFaceList;
  CATBoolean                  _PairingPseudoFaceComputed;
};

// Inline Functions
// ================

INLINE CATFace & CATlsoGTAPseudoFace::GetFace () const {
  CATlsoAssert (_pFace);
  return *_pFace;
}

INLINE CATLONG32 CATlsoGTAPseudoFace::GetPersistentTag () const {
  return _PersistentTag;
}

INLINE const CATMathPoint & CATlsoGTAPseudoFace::GetCenterPoint () {
  return _CenterPoint;
}

INLINE double CATlsoGTAPseudoFace::GetNumberOfLoops () const {
  return _NumberOfLoops;
}

INLINE CATBoolean CATlsoGTAPseudoFace::IsCenterInside () const {
  return _IsCenterInside;
}

INLINE const CATMathVector & CATlsoGTAPseudoFace::GetCenterNormal () {
  return _CenterNormal;
}

INLINE double CATlsoGTAPseudoFace::GetSquaredImpactRadius () const {
  return _SquaredImpactRadius;
}

INLINE double CATlsoGTAPseudoFace::GetEpsForLengthTest () const {
  return _EpsForLengthTest;
}

INLINE CATMathOBB* CATlsoGTAPseudoFace::GetOBB() const {
  return _OBB;
}

INLINE CATMathOBB * CATlsoGTAPseudoFace::GetOffsettedOBB () const {
  return _OffsettedOBB;
}

INLINE double CATlsoGTAPseudoFace::GetCenterInnerMaxOffset () const {
  return _CenterInnerMaxOffset;
}

INLINE double CATlsoGTAPseudoFace::GetCenterOuterMaxOffset () const {
  return _CenterOuterMaxOffset;
}

INLINE CATLONG32  CATlsoGTAPseudoFace::GetNumberOfGTAPairs () const {
  return _GTAPairList.Size ();
}

INLINE GTAPseudoFaceType CATlsoGTAPseudoFace::GetPseudoFaceType() const {
  return _PseudoFaceType;
}

INLINE int CATlsoGTAPseudoFace::GetNbInfrontPair() const {
  return _NbInfrontPair;
}

INLINE CATLONG32 CATlsoGTAPseudoFace::GetInfrontPseudoFaceTag() const {
  return _InfrontPseudoFaceTag;
}

INLINE CATBoolean CATlsoGTAPseudoFace::IsTackled () const {
  return _IsTackled;
}

INLINE void CATlsoGTAPseudoFace::SetTackled () {
  _IsTackled = TRUE;
}

INLINE void CATlsoGTAPseudoFace::SetPseudoFaceType(GTAPseudoFaceType iType) {
  _PseudoFaceType = iType;
  _NbInfrontPair++;
}

INLINE void CATlsoGTAPseudoFace::SetInfrontPseudoFaceTag(CATLONG32 iTag) {
  if (_PseudoFaceType == GTAPseudoFaceInfrontType)
    _InfrontPseudoFaceTag = iTag;
}

INLINE void CATlsoGTAPseudoFace::InsertGTAPair (CATlsoGTAPair * ipGTAPair)
{
  _GTAPairList.Append (ipGTAPair);
}

INLINE const ListPOfCATVertex& CATlsoGTAPseudoFace::GetOuterVertices() const {
    return _ListOfOuterVertices;
}

INLINE const CATLISTV(CATSurParam)& CATlsoGTAPseudoFace::GetOuterVertexSurParam() const {
    return _ListOfOuterVertexSurParam;
}

INLINE const CATLISTP(CATMathPoint)& CATlsoGTAPseudoFace::GetAllMathPoints() const {
  return _ListOfMathPoints;
}

INLINE void CATlsoGTAPseudoFace::SetFinalPairingFace() {
  _IsFinalPairingFace = TRUE;
}
INLINE CATBoolean CATlsoGTAPseudoFace::IsFinalPairingFace() const {
  return _IsFinalPairingFace;
}

INLINE void CATlsoGTAPseudoFace::GetPairList(ListPOfCATlsoGTAPair& oPairList) {
  oPairList = _GTAPairList;
}

// -----------------------------------------------------------------------------
// =============================================================================


#endif

