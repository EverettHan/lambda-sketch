//===================================================================
// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATICDSSkinParamCGM.h
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
//===================================================================

#ifndef CATICDSSkinParamCGM_H
#define CATICDSSkinParamCGM_H

#include "CATIAV5Level.h"

// FCX 04.2021 : removed in CXR32/R424
#if !defined(CATIAV5R32) && !defined(CATIAR424)

#include "CATCDSVirtual.h"
#include "SkinWire.h"
#include "CATICDSSkinParam.h"
#include "CATCDSInline.h"

class CATSoftwareConfiguration;
class CATICDSSkin;
class CATFace;
class CATEdge;
class CATVertex;
class CATSkinParamCGMImp;
class CATSkinCGMImp;

class ExportedBySkinWire CATICDSSkinParamCGM : public CATICDSSkinParam
{
public:

  // Object management

  CATICDSSkinParamCGM(CATSoftwareConfiguration * ipSoftwareConfiguration, CATICDSSkin &iSkin,
    CATFace * ipFace, double * ipParam = 0);

  CATICDSSkinParamCGM(CATSoftwareConfiguration * ipSoftwareConfiguration, CATICDSSkin &iSkin,
    CATEdge * ipEdge, double * ipParam = 0);

  CATICDSSkinParamCGM(CATSoftwareConfiguration * ipSoftwareConfiguration, CATICDSSkin &iSkin,
    CATVertex * ipVertex);

  CATICDSSkinParamCGM(CATSoftwareConfiguration * ipSoftwareConfiguration, CATICDSSkin &iSkin);

  virtual void CopyFrom(const CATICDSSkinParam * ipPointOnSkin) CATCDSOverride;
  
  virtual ~CATICDSSkinParamCGM();

  virtual CATSkinParamCGMImp* GetImplementation();
  
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
  
  // DUMP
  virtual void Dump();

  // FCX 11.2011 : store and restore a SkinParamCGM
  // returns 0 if ok
  int GetInternalData(int oType[2], unsigned int oTag[3], double oParam[3]);
  int SetInternalData(int iType[2], unsigned int oTag[3], double iParam[3]);

private:
  CATCDSInline CATSkinParamCGMImp* GetParamImp(const CATICDSSkinParam *ipPointOnSkin) const;
  CATCDSInline CATSkinCGMImp* GetSkinImp(const CATICDSSkin *ipSkin) const;

private:
  CATSkinParamCGMImp *_pImp;
};

#endif
#endif
