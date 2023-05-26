//===================================================================
// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATSkinParamCGMImp.h
// Implementation of CATSkinParamCGMImp
//
//===================================================================
//
// Usage notes:
//
//===================================================================
// May 2005  Creation                                           FCX
// Aout 2009 JSX Suppression de _TestMode
//               Warning sur GetContinuity
//               modif de GetCurrentParam pour un bord de face
//===================================================================

#ifndef CATSkinParamCGMImp_H
#define CATSkinParamCGMImp_H

#include "CATIAV5Level.h"

// FCX 04.2021 : removed in CXR32/R424
#if !defined(CATIAV5R32) && !defined(CATIAR424)

#include <stddef.h> 
#include "SkinWireImp.h"
#include "CATBoolean.h"

class CATSkinCGMImp;
class CATSoftwareConfiguration;
class CATFace;
class CATEdge;
class CATVertex;
class CATSurface;
class CATEdgeCurve;
class CATCGMStream;

enum CATContinuityCGM
{
  CATCGMContinuityG0,
  CATCGMContinuityG1,
  CATCGMContinuityG2
};

//-----------------------------------------------------------------------

class ExportedBySkinWireImp CATSkinParamCGMImp
{
public:

  // Object management

  CATSkinParamCGMImp(CATSoftwareConfiguration * ipSoftwareConfiguration, CATSkinCGMImp * ipSkin,
                     CATFace * ipFace, double * ipParam);

  CATSkinParamCGMImp(CATSoftwareConfiguration * ipSoftwareConfiguration, CATSkinCGMImp * ipSkin,
                     CATEdge * ipEdge, double * ipParam);

  CATSkinParamCGMImp(CATSoftwareConfiguration * ipSoftwareConfiguration, CATSkinCGMImp * ipSkin,
                     CATVertex * ipVertex);

  CATSkinParamCGMImp(CATSoftwareConfiguration * ipSoftwareConfiguration, CATSkinCGMImp * ipSkin);

  CATSkinParamCGMImp();

  //CATSkinParamCGMImp& operator= (const CATSkinParamCGMImp& iPointOnSkinImp);
  void CopyFrom(const CATSkinParamCGMImp * ipPointOnSkinImp);

  virtual ~CATSkinParamCGMImp();

  // Implementation methods

  CATBoolean IsParamOnWire();
  CATBoolean IsParamOnVertex();
  CATBoolean IsParamOnBorder();

  int GetInformationOnVertex(int & oNbOfWires, int & oNbOfFaces);

  int GetNextParamOnWire(CATSkinParamCGMImp * oPointOnSkinImp);
  int GetNextParamOnFace(CATSkinParamCGMImp * oPointOnSkinImp);
  int GetNextParamOnVertex(CATSkinParamCGMImp * oPointOnSkinImp);

  CATContinuityCGM GetContinuity();

  // Specific methods of CATSkinParamCGMImp

  void Reset();
  int GetDimension() const;
  int GetCurrentParam(CATFace *& oFace, double & oU, double & oV) const;
  int GetCurrentParam(CATEdge *& oEdge, double & oW) const;
  int GetCurrentParam(CATVertex *& oVertex) const;
  int SetCurrentParam(CATFace * iFace, double iU, double iV, CATEdge * iCloseEdge = 0, CATVertex * iCloseVertex = 0);
  int SetCurrentParam(CATEdge * iEdge, double iW, CATVertex * iCloseVertex = 0);
  int SetCurrentParam(CATVertex * iVertex, CATEdge * iPreviousEdge = 0, CATFace * iPreviousFace = 0);
  CATBoolean IsEqualTo(CATSkinParamCGMImp * iPointOnSkinImp) const;

  // FCX 04/08/2011 : for stream/unstream of skinparams
  void GetInternalData(int & oDimension, int & oState, CATFace *& oFace, CATEdge *& oEdge, CATVertex *& oVertex, double * oParams);
  void SetInternalData(int iDimension, int iState, CATFace * iFace, CATEdge * iEdge, CATVertex * iVertex, double * iParams);
  
  // FCX 11.2011 : store and restore a SkinParamCGM
  int GetInternalData(int oType[2], unsigned int oTag[3], double oParam[3]);
  int SetInternalData(int iType[2], unsigned int oTag[3], double iParam[3]);

  // FCX 07.2014 : new stream architecture for EK
  void Stream(CATCGMStream & oStream);
  void Stream(char *& oStreamData, size_t & oLength);
  CATBoolean Unstream(CATCGMStream & iStream, CATSkinCGMImp * ipSkinImp);

  inline CATSkinCGMImp* GetSkinImp() const {return _pSkinImp;}

  void Dump();

private:

  void Initialize();
  void CheckState();

  // Data

  CATSoftwareConfiguration  * _pConfig;
  int                         _Dimension;
  int                         _State;
  CATSkinCGMImp             * _pSkinImp;
  CATFace                   * _pCurrentFace;
  CATEdge                   * _pCurrentEdge;
  CATVertex                 * _pCurrentVertex;
  double _U, _V, _W;
};

//-----------------------------------------------------------------------

#endif
#endif
