// COPYRIGHT DASSAULT SYSTEMES 2023, ALL RIGHTS RESERVED.
//===================================================================
//
// CATBodyToPolyBodyAdapter
//
//===================================================================
// March 2023 : F1Z : Creation (try to make a based class for TessBuilder and GMAdapter)
//                    Big code clean & factorisation from CATTessPolyBodyBuilder.
//                    Handle volumes and heterogenous cases.
//===================================================================
#pragma once

#include "TessBodyAdapters.h"
#include "CATSoftwareConfiguration.h"
#include "CATBody.h"
#include "CATTopDefine.h"
#include "CATPolyCellOrbit.h"

#include "CATTessPolyBodyBuilder.h"
#include "CATPGMTessBody.h"
#include "CATPolyBody.h"
#include "CATTessPolyBodyDiagnosis.h"
#include "CATMapOfCellToPolyCell.h"
#include "CATMapOfEdgeToPolySurfaceVertexLine.h"
#include "CATMapOfVertexToPolySurfaceVertex.h"

#include <vector>


class CATBody;

class CATWire;
class CATDomain;

class CATVolume;
class CATFace;
class CATEdge;
class CATVertex;

class CATPolyCell;
class CATPolyFace;
class CATPolyEdge;
class CATPolyVertex;
class CATIPolyPoint;
class CATPolyVolume;

typedef CATTessPolyBodyDiagnosis CATBodyToPolyBodyDiagnosis;

class ExportedByTessBodyAdapters CATBodyToPolyBodyAdapter
{
public:
  virtual ~CATBodyToPolyBodyAdapter();

  HRESULT Run();

  // Result info
  CATPolyBody * GetPolyBody(); // you need to release the poly body

  void GetMapOfGMCellToPolyCell(CATMapOfCellToPolyCell & oMap);

protected:
  // Instantiation only possible through the inherit class
  CATBodyToPolyBodyAdapter(CATBody & body,
                           CATBodyToPolyBodyDiagnosis & diag);

  // Instead of failure, we accept partial edge/vertex info
  // and created 3D geometry otherwise
  inline void SetWith3DBackup(bool with3DBackup = true) { _with3DBackup = with3DBackup; };
  inline void SetWithPolyVolume(bool withPolyVolume = true) { _withPolyVolume = withPolyVolume; };

protected:
  // Class to specialize
  virtual CATPolyBody * CreatePolyBody() = 0;
  virtual CATIPolyPoint * GetPoint(CATVertex & vertex,
                                   CATOrientation oriVertexVSDomain) = 0;
  virtual CATIPolyCurve * GetCurve(CATEdge & edge,
                                   CATOrientation oriEdgeVSLoop,
                                   CATOrientation & oriCrvVsEdge) = 0;
  virtual CATIPolySurface * GetSurface(CATFace & face) = 0;
  virtual void EndCellProcess(CATCell & cell);
  virtual HRESULT RunPostProcess();

protected:
  inline CATVolume * GetVolumeSupport() { return _volume; };
  inline CATFace * GetFaceSupport() { return _face; };
  inline CATEdge * GetEdgeSupport() { return _edge; };

  CATPolyVolume * GetPolyVolumeSupport() { return _polyVolume; };
  CATPolyFace * GetPolyFaceSupport() { return _polyFace; };

private:
  HRESULT Process(CATDomain & domain,
                  CATOrientation domainOrientation,
                  CATLocation  domainLocation);

  HRESULT Process(CATCell & cell,
                  CATOrientation cellOrientation,
                  CATLocation cellLocation);

  Poly::OrbitQualifier PolyQualifier(CATLocation cellLocation);
  HRESULT GetOrCreatePolyCell(CATCell & cell,
                              CATOrientation cellOrientation,
                              CATLocation cellLocation);

  HRESULT GetOrCreatePolyFace(CATFace & face,
                              CATOrientation & faceOrientationToShell,
                              CATLocation & faceLocationToVolume,
                              CATPolyFace ** polyFace=NULL);

  HRESULT GetOrCreatePolyEdge(CATEdge & edge,
                              CATOrientation cellOrientation,
                              CATLocation cellLocation,
                              CATPolyEdge ** oPolyEdge=NULL);

  HRESULT GetOrCreatePolyVertex(CATVertex & vertex,
                                CATOrientation cellOrientation,
                                CATLocation cellLocation,
                                CATPolyVertex ** oPolyVertex=NULL);

  HRESULT Run3DBackup();

private:
  // state of the operator
  CATVolume * _volume;
  CATPolyVolume * _polyVolume;
  CATFace * _face;
  CATPolyFace * _polyFace;
  CATEdge * _edge;
  bool _inBackupMode;

private:
  // operator parameters
  CATBody & _body;
  CATBodyToPolyBodyDiagnosis & _diag;
  CATMapOfCellToPolyCell _mapCellToPolyCell;
  bool _with3DBackup;
  bool _withPolyVolume;
  CATPolyBody * _polyBody;
};

