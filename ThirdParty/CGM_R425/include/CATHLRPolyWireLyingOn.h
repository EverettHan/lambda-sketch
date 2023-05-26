/* -*-C++-*-*/
#ifndef CATHLRPolyWireLyingOn_H
#define CATHLRPolyWireLyingOn_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2013
//
// CATHLRPolyWireLyingOn 
//
// DESCRIPTION :
// Utilities services class in the context of
// HLR Entity based on a CATPolyBody to be computed by the Exact Motor
//
//
// History
//
// March. 2013 DPS Creation
//
//=============================================================================

// For Windows NT
#include "HLRTopology.h"

// For inheritance
#include "CATHLRTopology.h"

#include "CATDataType.h"    // HRESULT
#include "CATListOfInt.h"
#include "CATMapOfPtrToPtr.h"

class CATHLREdge;
class CATHLRFace;
class CATHLRLoop;

class CATPolyBody;
class CATPolyEdge;
class CATIPolyMesh;
class CATMathSetOfPoints;
class CATMathTransformation;

class ExportedByHLRTopology CATHLRPolyWireLyingOn 
{

public :

  CATHLRPolyWireLyingOn(int iHLREntityID, CATMathTransformation * iTransfo);
  ~CATHLRPolyWireLyingOn();

  HRESULT AppendHLRWireEdgeOnMesh(CATHLREdge & iWireHLREdge, CATIPolyMesh & iMeshSupport, CATListOfInt &iMeshVtxIndexes);
  HRESULT AppendHLRWire3DEdge(CATHLREdge &iWireHLREdge, void * iHLRVtxPTR[2], CATHLRFace * iHLRFace, CATMathSetOfPoints &iPoints);

  HRESULT StreamPolyBody(const char * iStreamDirectoryPath, const char * iStreamPrefix);

  inline int GetNbEdges();
  inline CATPolyBody * GetPolyBodyWire(CATMathTransformation *&oTransfo);

  CATHLREdge * GetEquivalentHLREdge(CATPolyEdge * iPolySilhEdge);



private :

  CATMathTransformation * _Transfo;
  CATPolyBody    & _PolyWireLyingOn;

  CATMapOfPtrToPtr _mapOfHLRVtxToPolyVtx;
  CATMapOfPtrToPtr _mapOfPolyEdgToHLREdg;

  int              _HLREntityID;
  int              _NbEdges;

  //*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*

};

inline int CATHLRPolyWireLyingOn::GetNbEdges() {
  return _NbEdges; }

inline CATPolyBody * CATHLRPolyWireLyingOn::GetPolyBodyWire(CATMathTransformation *&oTransfo) {
  oTransfo = _Transfo;
  return &_PolyWireLyingOn; }

#endif
