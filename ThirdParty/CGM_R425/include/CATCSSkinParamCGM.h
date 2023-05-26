//===================================================================
// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATCSSkinParamCGM.h
// Driver of CATCSSkinParam (implementation : CATSkinParamCGMImp)
//
//===================================================================
//
// Usage notes:
//
//===================================================================
// May 2005  Creation                                           FCX
//===================================================================

#ifndef CATCSSkinParamCGM_H
#define CATCSSkinParamCGM_H

// FCX 04.2021 : removed in CXR32/R424
#if !defined(CATIAV5R32) && !defined(CATIAR424)

#include "CATCDSVirtual.h"
#include "SkinWire.h"
#include "CATCSSkinParam.h"

class CATSoftwareConfiguration;
class CATCSSkin;
class CATFace;
class CATEdge;
class CATVertex;
class CATCSSkinCGM;
class CATSkinParamCGMImp;
class CATCGMStream;

//-----------------------------------------------------------------------

class ExportedBySkinWire CATCSSkinParamCGM: public CATCSSkinParam
  {
  public:

    // Object management

    CATCSSkinParamCGM(CATSoftwareConfiguration * ipSoftwareConfiguration, CATCSSkin * ipSkin,
      CATFace * ipFace, double * ipParam = 0);

    CATCSSkinParamCGM(CATSoftwareConfiguration * ipSoftwareConfiguration, CATCSSkin * ipSkin,
      CATEdge * ipEdge, double * ipParam = 0);

    CATCSSkinParamCGM(CATSoftwareConfiguration * ipSoftwareConfiguration, CATCSSkin * ipSkin,
      CATVertex * ipVertex);

    CATCSSkinParamCGM(CATSoftwareConfiguration * ipSoftwareConfiguration, CATCSSkin * ipSkin);

    CATCSSkinParamCGM();

    virtual void CopyFrom(const CATCSSkinParam * ipPointOnSkin) CATCDSOverride;
    //CATCSSkinParam& operator= (const CATCSSkinParam& iPointOnSkin);

    virtual ~CATCSSkinParamCGM();

    virtual CATSkinParamCGMImp* GetImplementation();

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
    CATCDSBoolean Unstream(CATCGMStream & iStream, CATCSSkinCGM * ipSkin);

    // DUMP
    virtual void Dump();

    // FCX 11.2011 : store and restore a SkinParamCGM
    // returns 0 if ok
    int GetInternalData(int oType[2], unsigned int oTag[3], double oParam[3]);
    int SetInternalData(int iType[2], unsigned int oTag[3], double iParam[3]);

  protected :
    CATCSSkinParam& operator= (const CATCSSkinParam& iPointOnSkin);

    //DATA ===================================================
  private:
    CATSkinParamCGMImp *_pImp;
  };

//-----------------------------------------------------------------------

#endif
#endif
