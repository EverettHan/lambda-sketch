//=============================================================================
// COPYRIGHT Dassault Systemes 2009
//=============================================================================
//
// CATPolyDecoMeshBarsZipper.h
//
//=============================================================================
// June 2009 ZFI
//=============================================================================

#ifndef CATPolyDecoMeshBarsZipper_H
#define CATPolyDecoMeshBarsZipper_H

#include "PolyBodyBuilders.h"

#include "CATErrorDef.h" 
#include "CATListPV.h"
#include "CATMapOfIntToInt.h"
#include "CATBoolean.h"
#include "CATListOfInt.h"

class CATPolyDecoMeshBars;
class CATPolyBarsSpatialPartitionOper;
class CATPolyBitSet;
class CATPolyDecoMeshBarsZipperTopo;

class ExportedByPolyBodyBuilders CATPolyDecoMeshBarsZipper
{
public:
	CATPolyDecoMeshBarsZipper (CATPolyDecoMeshBars* iDecoMesh,
                             CATPolyDecoMeshBarsZipperTopo* iTopo) ;
	virtual ~CATPolyDecoMeshBarsZipper () ;

public:
  HRESULT CreateLinksUsingPolyVertices(const float iTolerance);

  HRESULT CreateLinksForHoleVertices(const float iTolerance);
  HRESULT CreateLinksForHoleVerticesSamePos();
  HRESULT CreateRemainingLinks(const float iTolerance);
  
  HRESULT Close();
  
private:
 
  HRESULT CreateVertexNodeInNeighborHood(const int iIdxVertex,
                                         const float iTolerance,
                                         CATPolyBarsSpatialPartitionOper& iSpatialPartition,
                                         int& oIdxVertexNode);

  HRESULT CreateLinksBetweenVertexNodes();
  HRESULT CreateLinksTwins();
  HRESULT FillCurveBars(const int iIdxVertex, 
                        const int iIdxBar, 
                        CATPolyBitSet& ioBarProcessed,
                        CATListOfInt& ioBars,
                        int& oLastVertex);
  
  HRESULT CloseAllTwinsWithNodes(const float iTolerance);
  HRESULT CloseTwinsWithNodes(const int iIdxLink1, const int iIdxLink2, 
                              const float iTolerance);

  //checks
private:
  //projection
  CATBoolean CheckGeometryForVertexProjection(const int iV,const int iBar, const float iTolerance);
  CATBoolean CheckTopologyForVertexProjection(const int iV,const int iBar);

  HRESULT ProjectVertexOnBar(const int iV, const int iV1, const int iV2, 
                             double& oDistance, 
                             double& oAlpha);
  HRESULT TryToProjectVertexOnBar(const int iIdxV1,
                                  int& ioIdxV2, 
                                  const int iNumBar2, 
                                  CATListOfInt& ioListOfBars, 
                                  const float iTolerance, 
                                  CATBoolean& oOk);

private:
  CATPolyDecoMeshBars* _DecoMesh;  
  CATPolyDecoMeshBarsZipperTopo* _Topo;

};

#endif 
