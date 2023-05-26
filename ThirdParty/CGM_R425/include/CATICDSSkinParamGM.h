//===================================================================
// COPYRIGHT Dassault Systemes 2016
//===================================================================
//
// CATICDSSkinParamGM.h
// Implemenation of CATICDSSkinParam for CGM skins based
// on CGM implementation : CATSkinParamCGMImp
//
//===================================================================
//
// Usage notes:
//
//===================================================================
// May 2005  Creation                                             FCX
// Jul 2013  Migration to CDS public interfaces                   D5T
// Dec 2016  Implementation in CATCDSGMInfra                      FCX
// Feb 2018  Use of CATSkinParamGMImp as implementation           FCX
//===================================================================

#ifndef CATICDSSkinParamGM_H
#define CATICDSSkinParamGM_H

#include "CATCDSVirtual.h"
#include "SkinWireGM.h"
#include "CATICDSSkinParam.h"
#include "CATCDSInline.h"
#include "SkinWireGMDefines.h"
#include <string.h>

#ifndef CATCDSGMINFRA_IMP
class CATSkinParamCGMImp;
class CATSkinCGMImp;
#endif

class CATSoftwareConfiguration;
class CATICDSSkin;
class CATFace;
class CATEdge;
class CATVertex;
class CATSkinParamGMImp;
class CATCGMStream;
class CATICDSSkinParam;
class CATSkinGMImp;

class ExportedBySkinWireGM CATICDSSkinParamGM : public CATICDSSkinParam
{
public:

  // Object management

  CATICDSSkinParamGM(CATSoftwareConfiguration * ipSoftwareConfiguration, CATICDSSkin &iSkin,
    CATFace * ipFace, double * ipParam = 0);

  CATICDSSkinParamGM(CATSoftwareConfiguration * ipSoftwareConfiguration, CATICDSSkin &iSkin,
    CATEdge * ipEdge, double * ipParam = 0);

  CATICDSSkinParamGM(CATSoftwareConfiguration * ipSoftwareConfiguration, CATICDSSkin &iSkin,
    CATVertex * ipVertex);

  CATICDSSkinParamGM(CATSoftwareConfiguration * ipSoftwareConfiguration, CATICDSSkin &iSkin);

  virtual void CopyFrom(const CATICDSSkinParam * ipPointOnSkin) CATCDSOverride;
  
  virtual ~CATICDSSkinParamGM();

  // Information methods

  virtual CATCSParamType GetParamType() CATCDSOverride;
  virtual CATCDSBoolean IsParamOnWire() CATCDSOverride;
  virtual CATCDSBoolean IsParamOnVertex() CATCDSOverride;
  virtual CATCDSBoolean IsParamOnBorder() CATCDSOverride;
  virtual int GetInformationOnVertex(int & oNbOfWires, int & oNbOfFaces) CATCDSOverride;
  virtual CATCSContinuity GetContinuity() CATCDSOverride;

  // NextParam methods

  virtual int GetNextParamOnWire(CATICDSSkinParam * oPointOnSkin) CATCDSOverride;
  virtual int GetNextParamOnFace(CATICDSSkinParam * oPointOnSkin) CATCDSOverride;
  virtual int GetNextParamOnVertex(CATICDSSkinParam * oPointOnSkin) CATCDSOverride;
 
  // Stream
  void Stream(CATCGMStream & oStream);
  void Stream(char *& oStreamData, size_t & oLength);
  void StreamNCGM(const char* iaOutputDir, const char* iaOutputName, unsigned int & ioIndex, CATCDSBoolean iForceIndex = FALSE);

  // DUMP
  virtual void Dump();

  // FCX 11.2011 : store and restore a SkinParamGM
  // returns 0 if ok
  int GetInternalData(int oType[2], unsigned int oTag[3], double oParam[3]);
  int SetInternalData(int iType[2], unsigned int oTag[3], double iParam[3]);

#ifdef CATCDSGMINFRA_IMP
  virtual CATSkinParamGMImp* GetImplementation() { return _pImp; }
#else
  virtual CATSkinParamCGMImp* GetImplementation() { return _pImp; }
#endif

private:
#ifdef CATCDSGMINFRA_IMP
  CATSkinParamGMImp *_pImp;
  CATCDSInline CATSkinParamGMImp* GetParamImp(const CATICDSSkinParam *ipPointOnSkin) const;
  CATCDSInline CATSkinGMImp* GetSkinImp(const CATICDSSkin *ipSkin) const;
#else
  CATSkinParamCGMImp *_pImp;
  CATCDSInline CATSkinParamCGMImp* GetParamImp(const CATICDSSkinParam *ipPointOnSkin) const;
  CATCDSInline CATSkinCGMImp* GetSkinImp(const CATICDSSkin *ipSkin) const;
#endif
};

#endif
