//===================================================================
// COPYRIGHT Dassault Systemes 2014
//===================================================================
//
// CATCSSkinGM.h
// GM CATCSSkin object
//
//===================================================================
//
// Usage notes:
//
//===================================================================
// July 2014    Creation                                         FCX
// Feb 2018     Use of CATSkinGMImp as implementation            FCX
//===================================================================

#ifndef CATCSSkinGM_H
#define CATCSSkinGM_H

#include "CATCDSVirtual.h"
#include "CATCSSkin.h"
#include "SkinWireGM.h"
#include "SkinWireGMDefines.h"

#ifndef CATCDSGMINFRA_IMP
class CATSkinCGMImp;
#endif

class CATBody;
class CATShell;
class CATFace;
class CATSoftwareConfiguration;
class CATCGMStream;
class CATSkinGMImp;
class CATMathPoint;
class CATMathPlane;
class CATGeoFactory;

//-----------------------------------------------------------------------

class ExportedBySkinWireGM CATCSSkinGM : public CATCSSkin
{
public:
  // Object management

  CATCSSkinGM(CATSoftwareConfiguration* ipSoftwareConfiguration, CATBody* ipBody);
  CATCSSkinGM();
  virtual ~CATCSSkinGM();

  // Methods of CATCSSkin

  virtual CATCSSkin* Clone() const CATCDSOverride;

  virtual CATCSSkinParam* CreateParam() CATCDSOverride;
  virtual CATCSSkinParam* CreateParam(double iaPoint[3]) CATCDSOverride;
  virtual CATCSSkinParam* CreateParam(const CATCSSkinParam* ipPointOnSkin) CATCDSOverride;

  virtual int Evaluate(CATCSSkinParam* iPointOnSkin,
    double* oaPoint,
    double* oaDU,
    double* oaDV,
    double* oaD2U,
    double* oaDUDV,
    double* oaD2V) CATCDSOverride;

  virtual int EvaluateOnWire(CATCSSkinParam* iPointOnSkin,
    double* oaPoint,
    double* oaDW,
    double* oaD2W) CATCDSOverride;

  virtual int EvaluateOnVertex(CATCSSkinParam* iPointOnSkin, double* oaPoint);

  virtual int GetClosePoint(CATCSSkinParam* iPointOnSkin,
    double iDeltaU,
    double iDeltaV,
    CATCSStopCommand iStopCommand,
    CATCSSkinParam* oPointOnSkin,
    CATCSClosePointDiagnostics& oDiagnostics,
    double& oAppliedDeltaU,
    double& oAppliedDeltaV) CATCDSOverride;

  virtual int GetClosePointOnWire(CATCSSkinParam* iPointOnSkin,
    double iDeltaW,
    CATCSStopCommand iStopCommand,
    CATCSSkinParam* oPointOnSkin,
    CATCSClosePointDiagnostics& oDiagnostics,
    double& oAppliedDeltaW) CATCDSOverride;

  virtual void ApplyTransformation(const double iMatrix[3][3], const double iTranslation[3]) CATCDSOverride;

  virtual int ComputeDistanceMin(CATMathPoint& iPoint, CATCSSkinParam* oPointOnSkin);

  virtual int ComputeDistanceMin(CATMathPlane& iPlane, CATCSSkinParam* oPointOnSkin);

  virtual int ComputeDistanceMin(CATCSSkin* iOtherSkin, CATCSSkinParam* oPointOnThisSkin, CATCSSkinParam* oPointOnTheOtherSkin);

  // curvilinear mode

  virtual int EvaluateNormalize(CATCSSkinParam* iPointOnSkin,
    double* oaPoint,
    double* oaDU,
    double* oaDV,
    double* oaD2U,
    double* oaDUDV,
    double* oaD2V) CATCDSOverride;

  virtual int GetClosePointByLength(CATCSSkinParam* iPointOnSkin,
    double iDirectionUV[2],
    double iLength,
    CATCSStopCommand iStopCommand,
    CATCSSkinParam* oPointOnSkin,
    CATCSClosePointDiagnostics& oDiagnostics,
    double& oAppliedLength) CATCDSOverride;

  // Stream/Unstream
  void Stream(CATCGMStream& oStream);
  void Stream(char*& oStreamData, size_t& oLength) CATCDSOverride;
  void StreamNCGM(const char* iaOutputDir, const char* iaOutputName, CATGeoFactory* ipFactory, CATBody*& opSkinBody, unsigned int& ioIndex, CATCDSBoolean iForceIndex = FALSE);
  CATCDSBoolean Unstream(CATCGMStream& iStream, CATGeoFactory*& iopFactory);
  CATBody* GetBody() const;
// internal use
#ifdef CATCDSGMINFRA_IMP
  inline CATSkinGMImp* GetImplementation()
  {
    return _pImp;
  }
#else
  inline CATSkinCGMImp* GetImplementation()
  {
    return _pImp;
  }
#endif

private:
  CATCSSkinGM(const CATCSSkinGM& iSkinGM);
#ifdef CATCDSGMINFRA_IMP
  CATSkinGMImp* _pImp;
#else
  CATSkinCGMImp* _pImp;
//CATStopCommandCGM Convert(CATCSStopCommand & iStopCommand);
//CATCSClosePointDiagnostics Convert(CATClosePointDiagnosticsCGM & iDiag);
#endif
  CATSoftwareConfiguration* _pConfig;
};

//-----------------------------------------------------------------------

#endif
