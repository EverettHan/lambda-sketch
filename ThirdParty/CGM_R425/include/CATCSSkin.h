// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATCSSkin.h
// Header definition of CATCSSkin
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Jul 2005  Creation                    Andrey CHUGUEV
//===================================================================

#ifndef CATCSSkin_H
#define CATCSSkin_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSGeometryLeaf.h"

class CATCSSkinParam;

//-----------------------------------------------------------------------

class ExportedBySolverInterface CATCSSkin : public CATCSGeometryLeaf
{
public:
  virtual ~CATCSSkin();

  virtual CATCSType GetType() const CATCDSOverride;
  virtual CATCDSBoolean IsMatched(CATCSType iType) const CATCDSOverride;

  virtual CATCSSkin* Clone() const;

  virtual CATCSSkinParam * CreateParam() = 0;
  virtual CATCSSkinParam * CreateParam(double iaPoint[3]) = 0;
  virtual CATCSSkinParam * CreateParam(const CATCSSkinParam * ipPointOnSkin) = 0;

  virtual int Evaluate(
    CATCSSkinParam * ipPointOnSkin,
    double* oaPoint,
    double* oaDU,
    double* oaDV,
    double* oaD2U,
    double* oaDUDV,
    double* oaD2V) = 0;

  virtual int EvaluateOnWire(
    CATCSSkinParam * ipPointOnSkin,
    double* oaPoint,
    double* oaDW,
    double* oaD2W) = 0;

  virtual int GetClosePoint(
    CATCSSkinParam * ipPointOnSkin,
    double iDeltaU, double iDeltaV,
    CATCSStopCommand iStopCommand,
    CATCSSkinParam * opPointOnSkin,
    CATCSClosePointDiagnostics & oDiagnostics,
    double & oAppliedDeltaU, double & oAppliedDeltaV) = 0;

  virtual int GetClosePointOnWire(
    CATCSSkinParam * ipPointOnSkin,
    double iDeltaW,
    CATCSStopCommand iStopCommand,
    CATCSSkinParam * opPointOnSkin,
    CATCSClosePointDiagnostics & oDiagnostics,
    double & oAppliedDeltaW) = 0;

  // curvilinear mode
  
  virtual int EvaluateNormalize(
    CATCSSkinParam * iPointOnSkin, 
    double * oaPoint,
    double * oaDU,
    double * oaDV,
    double * oaD2U,
    double * oaDUDV,
    double * oaD2V);

  virtual int GetClosePointByLength(
    CATCSSkinParam * iPointOnSkin,
    double iDirectionUV[2],
    double iLength,
    CATCSStopCommand iStopCommand,
    CATCSSkinParam * oPointOnSkin,
    CATCSClosePointDiagnostics & oDiagnostics,
    double & oAppliedLength);

  /* for internal use */
  virtual void Stream(char *& oStreamData, size_t & oLength);

  /**
   * DO NOT USE
   * TEST ONLY
   */
  virtual void Scale(double iFactor);

protected:
  CATCSSkin();
};

//-----------------------------------------------------------------------

#endif
