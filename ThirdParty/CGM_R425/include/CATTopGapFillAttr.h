/**
 * @COPYRIGHT DASSAULT SYSTEMES 2008
 */

/* -*-C++-*- */

#ifndef CATTopGapFillAttr_H_
#define CATTopGapFillAttr_H_


//=============================================================================
// Feb  08  Creation                                                      BQJ
//=============================================================================
#include "CATCGMStreamAttribute.h"
#include "CATFace.h"
#include "BOIMPOPE.h"
#include "CATMathDirection.h"
#include "CATVertex.h"

#include "CATMathStreamDef.h"

class ExportedByBOIMPOPE CATTopGapFillAttr : public CATCGMStreamAttribute
{
public :

  CATCGMDeclareAttribute(CATTopGapFillAttr,CATCGMStreamAttribute);

  CATTopGapFillAttr();

  ~CATTopGapFillAttr() {}

  //----------------------------------------------------------------
  // Stream / Unstream
  //----------------------------------------------------------------
  void Stream(CATCGMStream & ioStream) const;
  void UnStream(CATCGMStream& ioStr );
  
  //----------------------------------------------------------------
  // Get Methods
  //----------------------------------------------------------------
  short GetOrientation() const { return _Orientation;}
  double GetDraftAngle() const { return _DraftAngle;}
  void GetDraftDirection(CATMathDirection &ioPullDirection) const { ioPullDirection = _PullDirection;}
  void GetTrackLengths(double* ioLengths);
  void GetPartingVertex(CATMathPoint &ioPartingVertex);
  short GetEndType() const { return _EndType;}

  double GetPartingDeviation() const {return _PartingDeviation;}
  double GetIdealRadius() const {return _IdealRadius;}
  //1 == NN, 2 == RR
  short GetDrafttype() const {return _DraftType;}

  //----------------------------------------------------------------
  // Set Methods
  //----------------------------------------------------------------
  void SetParameters(short iOrientation, double iDraftAngle, const CATMathDirection &iPullDirection, double *iLengths, 
                      short iEndType, const CATMathPoint &iPartingVertex, double iPartingDeviation, double iIdealRadius,
                      short _DraftType);

  virtual CATBoolean IsStreamable(const CATCGMStreamVersion iTargetVersion, CATBoolean & ioReversible) const;

private:
  
  short _Orientation;
  double _DraftAngle;
  CATMathDirection _PullDirection;
  double _TrackLength1;
  double _TrackLength2;
  double _TrackLength3;
  short _EndType;
  CATMathPoint _PartingVertex;
  double _PartingDeviation;
  double _IdealRadius;
  short _DraftType;
};

#endif
