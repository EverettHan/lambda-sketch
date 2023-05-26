/* -*-C++-*-*/
#ifndef CATHLRPtOnFaceSectorIter_H
#define CATHLRPtOnFaceSectorIter_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2012
//
// CATHLRPtOnFaceSectorIter 
//
// DESCRIPTION :

//
// Main Methods :
//  
//=============================================================================
// Abstract Class     : Yes
//=============================================================================
//
// History
//
// Dec. 2012   D.Prevost
//
//=============================================================================

// For Windows NT
#include "HLRTopology.h"

#include "CATCrvParam.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "CATSysBoolean.h"

#include "CATMathPoint.h"
#include "CATLISTV_CATMathVector.h"


class CATHLRFace;
class CATHLRPCurve;

class CATSurParam;
class CATMathPoint;
class CATMathVector;

enum VectorPosVsHLRPtOnFace { HLRInternalVectorFromPt=0, HLRVectorOnStartPCrv=1, HLRVectorOnEndPCrv=2, HLRVectorBoundingHole=3 };


class ExportedByHLRTopology CATHLRPtOnFaceSectorIter
{
public:


//=============================================================================
// CONSTRUCTORS AND DESTRUCTOR
//=============================================================================

  /**
  * Constructor from a HLRFace
  */
  CATHLRPtOnFaceSectorIter(CATHLRFace &iHLRFace);  
  virtual ~CATHLRPtOnFaceSectorIter();

  // iPCrv1 & iOriPC1VsLoop define the local Coedge relatively to the HLRFace
  // iOriPC1VsLoop : +1 if the face is on the left, -1 on the right
  // iW1 and iSense1 describe the half curve from the point to define the future vector
  // iSense1 : relatively to the orientation of the PCurve from the point iW1
  HRESULT Reset(CATHLRPCurve * iPCrv1, CATHLRPCurve * iPCrv2, int iOriPC1VsLoop, int iOriPC2VsLoop, CATCrvParam & iW1, CATCrvParam & iW2, int iSense1, int iSense2);

  // These 2 methods have no sense if the Reset() method has not be called yet
  void GetPoint(CATMathPoint &oPoint3D); // independantly of sectors
  int GetNumberOfSectors();

  //=============================================================================
  // Iterator METHODS
  //=============================================================================

  inline void Begin ();
  CATBoolean End () const;
  inline void operator++ ();


  //=============================================================================
  // Get METHODS
  //=============================================================================

  virtual void GetSectorParam(CATSurParam &oSurParam)=0;

  VectorPosVsHLRPtOnFace GetStartPosition();
  VectorPosVsHLRPtOnFace GetEndPosition();
  void GetStartVector(CATMathVector &oStartVector);
  void GetEndVector(CATMathVector &oEndVector);
  virtual void GetBisectorVector(CATMathVector &oBisectorVector);


protected:

  virtual HRESULT Compute()=0;


protected:

  //=============================================================================
  // INPUT DATAS
  //=============================================================================

  CATHLRFace               & _HLRFace;

  CATHLRPCurve             * _HLRPCrv1;
  CATHLRPCurve             * _HLRPCrv2;
  CATCrvParam                _W1;
  CATCrvParam                _W2;
  int                        _Sense1;
  int                        _Sense2;


  //=============================================================================
  // INTERNAL DATAS
  //=============================================================================

  CATMathPoint               _CoordPtOnFace;
  CATLISTV(CATMathVector)    _ListOfVectors;
  int                        _SectorCursor;

};

//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================

//-----------------------------------------------------------------------------

inline void CATHLRPtOnFaceSectorIter::Begin() { 
  _SectorCursor = 1; }

inline void CATHLRPtOnFaceSectorIter::operator++ () {
  _SectorCursor++; }

#endif
