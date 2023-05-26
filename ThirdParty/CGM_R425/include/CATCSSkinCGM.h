//===================================================================
// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATCSSkinCGM.h
// Driver of CATCSSkin (implementation : CATSkinCGMImp)
//
//===================================================================
//
// Usage notes:
//
//===================================================================
// May 2005  Creation                                           FCX
//===================================================================

#ifndef CATCSSkinCGM_H
#define CATCSSkinCGM_H

// FCX 04.2021 : removed in CXR32/R424
#if !defined(CATIAV5R32) && !defined(CATIAR424)

#include "CATCDSVirtual.h"
#include "SkinWire.h"
#include "CATCSSkin.h"

class CATBody;
class CATShell;
class CATFace;
class CATSoftwareConfiguration;
class CATCGMStream;
class CATSkinCGMImp;
class CATMathPoint;
class CATMathPlane;
class CATGeoFactory;

//-----------------------------------------------------------------------

class ExportedBySkinWire CATCSSkinCGM: public CATCSSkin
{
public:

  // Object management

  CATCSSkinCGM(CATSoftwareConfiguration * ipSoftwareConfiguration, CATBody * ipBody, int iTestMode = 0);
  CATCSSkinCGM(CATSoftwareConfiguration * ipSoftwareConfiguration, CATShell * ipShell, int iSkinOrientation = 1, int iTestMode = 0);
  CATCSSkinCGM(CATSoftwareConfiguration * ipSoftwareConfiguration, CATFace * ipFace, CATBody * ipBody, int iTestMode = 0);
  CATCSSkinCGM();
  virtual ~CATCSSkinCGM();
  virtual CATSkinCGMImp* GetImplementation();

  // Methods of CATCSSkin

  virtual CATCSSkin* Clone() const CATCDSOverride;

  virtual CATCSSkinParam* CreateParam() CATCDSOverride;
  virtual CATCSSkinParam * CreateParam(double iaPoint[3]) CATCDSOverride;
  virtual CATCSSkinParam * CreateParam(const CATCSSkinParam * ipPointOnSkin) CATCDSOverride;

  virtual int Evaluate( CATCSSkinParam * iPointOnSkin, 
                        double         * oaPoint,
                        double         * oaDU,
                        double         * oaDV,
                        double         * oaD2U,
                        double         * oaDUDV,
                        double         * oaD2V) CATCDSOverride;

  virtual int EvaluateOnWire( CATCSSkinParam  * iPointOnSkin, 
                              double          * oaPoint,
                              double          * oaDW,
                              double          * oaD2W) CATCDSOverride;

  virtual int EvaluateOnVertex( CATCSSkinParam * iPointOnSkin, double* oaPoint);

  virtual int GetClosePoint( CATCSSkinParam              * iPointOnSkin,
                             double                        iDeltaU,
                             double                        iDeltaV,
                             CATCSStopCommand              iStopCommand,
                             CATCSSkinParam              * oPointOnSkin,
                             CATCSClosePointDiagnostics  & oDiagnostics,
                             double                      & oAppliedDeltaU,
                             double                      & oAppliedDeltaV) CATCDSOverride;

  virtual int GetClosePointOnWire( CATCSSkinParam              * iPointOnSkin,
                                   double                        iDeltaW,
                                   CATCSStopCommand              iStopCommand,
                                   CATCSSkinParam              * oPointOnSkin,
                                   CATCSClosePointDiagnostics  & oDiagnostics,
                                   double                      & oAppliedDeltaW) CATCDSOverride;

  virtual void ApplyTransformation(const double iMatrix[3][3], const double iTranslation[3]) CATCDSOverride;

  virtual int ComputeDistanceMin(CATMathPoint & iPoint, CATCSSkinParam * oPointOnSkin);

  virtual int ComputeDistanceMin(CATMathPlane & iPlane, CATCSSkinParam * oPointOnSkin);

  virtual int ComputeDistanceMin(CATCSSkin * iOtherSkin, CATCSSkinParam * oPointOnThisSkin, CATCSSkinParam * oPointOnTheOtherSkin);

  // curvilinear mode

  virtual int EvaluateNormalize( CATCSSkinParam * iPointOnSkin, 
                                 double         * oaPoint,
                                 double         * oaDU,
                                 double         * oaDV,
                                 double         * oaD2U,
                                 double         * oaDUDV,
                                 double         * oaD2V) CATCDSOverride;

  virtual int GetClosePointByLength( CATCSSkinParam              * iPointOnSkin,
                                     double                        iDirectionUV[2],
                                     double                        iLength,
                                     CATCSStopCommand              iStopCommand,
                                     CATCSSkinParam              * oPointOnSkin,
                                     CATCSClosePointDiagnostics  & oDiagnostics,
                                     double                      & oAppliedLength) CATCDSOverride;

  // Stream/Unstream
  void Stream(CATCGMStream & oStream);
  void Stream(char *& oStreamData, size_t & oLength) CATCDSOverride;
  CATCDSBoolean Unstream(CATCGMStream & iStream, CATGeoFactory *& iopFactory);

  // Stream (old version)
  void Stream(const char* iDebugDir, const char* iDebugName, CATGeoFactory * iFactory, CATBody *& oSkinBody, unsigned int & oIndex, unsigned int *oType = 0);
  void StreamSP(CATCSSkinParam * iPointOnSkin, const char* iDebugDir, const char* iDebugName, unsigned int & oIndex, unsigned int *oType = 0);

private:
  CATCSSkinCGM(const CATCSSkinCGM & iSkinCGM);
  CATSkinCGMImp *_pImp;
  CATSoftwareConfiguration *_pConfig;
  //CATStopCommandCGM Convert(CATCSStopCommand & iStopCommand);
  //CATCSClosePointDiagnostics Convert(CATClosePointDiagnosticsCGM & iDiag);

  // tmp : used for CATCDSReplayStreamEK mode
  void GenerateDataFileName(const char* iDebugDir, const char* iDebugName, const char* iExtension, CATCDSString & oFileName, unsigned int & oIndex);
};

//-----------------------------------------------------------------------

#endif
#endif
