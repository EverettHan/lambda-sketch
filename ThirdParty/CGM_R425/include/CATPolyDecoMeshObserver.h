//=============================================================================
// COPYRIGHT Dassault Systemes 2009
//=============================================================================
//
// CATPolyDecoMeshObserver.h
//
//=============================================================================
// 2009-03-18 ZFI
//=============================================================================

#ifndef CATPolyDecoMeshObserver_H
#define CATPolyDecoMeshObserver_H

#include "PolyBodyBuilders.h"

#include "CATErrorDef.h" 
#include "CATIPolyMeshObserver.h"

class CATPolyDecoMeshBars;

class ExportedByPolyBodyBuilders CATPolyDecoMeshObserver : public CATIPolyMeshObserver
{
public:
	CATPolyDecoMeshObserver (CATPolyDecoMeshBars* iDecoMesh) ;
	virtual ~CATPolyDecoMeshObserver () ;

public:

  virtual HRESULT ReactToSplitTriangle (int t, int t0, int t1);

private:
  CATPolyDecoMeshBars* _DecoMesh;  
};

#endif 
