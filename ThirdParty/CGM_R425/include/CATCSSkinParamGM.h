//===================================================================
// COPYRIGHT Dassault Systemes 2014
//===================================================================
//
// CATCSSkinParamGM.h
// GM CATCSSkinParam object
//
//===================================================================
//
// Usage notes:
//
//===================================================================
// July 2014    Creation                                         FCX
// Feb 2018     Use of CATSkinParamGMImp as implementation       FCX
//===================================================================

#ifndef CATCSSkinParamGM_H
#define CATCSSkinParamGM_H

#include "CATCDSVirtual.h"
#include "SkinWireGM.h"
#include "CATCSSkinParam.h"
#include "SkinWireGMDefines.h"

#ifndef CATCDSGMINFRA_IMP
class CATSkinParamCGMImp;
#endif

class CATSoftwareConfiguration;
class CATCSSkin;
class CATFace;
class CATEdge;
class CATVertex;
class CATCSSkinGM;
class CATSkinParamGMImp;
class CATCGMStream;

//-----------------------------------------------------------------------

class ExportedBySkinWireGM CATCSSkinParamGM: public CATCSSkinParam
{
public:

  // Object management

  CATCSSkinParamGM(CATSoftwareConfiguration * ipSoftwareConfiguration, CATCSSkin * ipSkin,
    CATFace * ipFace, double * ipParam = 0);

  CATCSSkinParamGM(CATSoftwareConfiguration * ipSoftwareConfiguration, CATCSSkin * ipSkin,
    CATEdge * ipEdge, double * ipParam = 0);

  CATCSSkinParamGM(CATSoftwareConfiguration * ipSoftwareConfiguration, CATCSSkin * ipSkin,
    CATVertex * ipVertex);

  CATCSSkinParamGM(CATSoftwareConfiguration * ipSoftwareConfiguration, CATCSSkin * ipSkin);

  CATCSSkinParamGM();

  virtual void CopyFrom(const CATCSSkinParam * ipPointOnSkin) CATCDSOverride;
  //CATCSSkinParam& operator= (const CATCSSkinParam& iPointOnSkin);

  virtual ~CATCSSkinParamGM();

  // Information methods

  virtual CATCSParamType GetParamType() CATCDSOverride;
  virtual CATCDSBoolean IsParamOnWire() CATCDSOverride;
  virtual CATCDSBoolean IsParamOnVertex() CATCDSOverride;
  virtual CATCDSBoolean IsParamOnBorder() CATCDSOverride;
  virtual int GetInformationOnVertex(int & oNbOfWires, int & oNbOfFaces) CATCDSOverride;
  virtual CATCSContinuity GetContinuity() CATCDSOverride;

  // NextParam methods

  virtual int GetNextParamOnWire(CATCSSkinParam * oPointOnSkin) CATCDSOverride;
  virtual int GetNextParamOnFace(CATCSSkinParam * oPointOnSkin) CATCDSOverride;
  virtual int GetNextParamOnVertex(CATCSSkinParam * oPointOnSkin) CATCDSOverride;

  // Stream/Unstream
  void Stream(CATCGMStream & oStream);
  void Stream(char *& oStreamData, size_t & oLength) CATCDSOverride;
  void StreamNCGM(const char* iaOutputDir, const char* iaOutputName, unsigned int & ioIndex, CATCDSBoolean iForceIndex = FALSE);
  CATCDSBoolean Unstream(CATCGMStream & iStream, CATCSSkinGM * ipSkin);

  // DUMP
  virtual void Dump();

  // FCX 11.2011 : store and restore a SkinParamGM
  // returns 0 if ok
  int GetInternalData(int oType[2], unsigned int oTag[3], double oParam[3]);
  int SetInternalData(int iType[2], unsigned int oTag[3], double iParam[3]);

  // internal use
#ifdef CATCDSGMINFRA_IMP
  inline CATSkinParamGMImp* GetImplementation() { return _pImp; }
#else
  inline CATSkinParamCGMImp* GetImplementation() { return _pImp; }
#endif

protected :
  CATCSSkinParam& operator= (const CATCSSkinParam& iPointOnSkin);

  //DATA ===================================================
private:
#ifdef CATCDSGMINFRA_IMP
  CATSkinParamGMImp *_pImp;
#else
  CATSkinParamCGMImp *_pImp;
#endif
};

//-----------------------------------------------------------------------

#endif
