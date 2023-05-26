//=============================================================================
// COPYRIGHT Dassault Systemes 2009
//=============================================================================
//
// CATPolyBodyMultiLayerBuilder.h
//
//=============================================================================
// 2011-10-10 ZFI
//=============================================================================

#ifndef CATPolyBodyMultiLayerBuilder_H
#define CATPolyBodyMultiLayerBuilder_H


#include "PolyBodyBuilders.h"

#include "CATErrorDef.h" 
#include "CATBoolean.h"


class CATPolyBody;
class CATPolyDecoMeshBars;
class CATPolyDecoMeshBarsConcatenator;
class CATMapOfPtrToPtr;
class CATMapOfIntToPtr;
class CATMathTransformation;
class CATMapOfPtrToInt;
class CATPolyBodyPreAllocatedFrameLayers;
class CATIPolyBodyFrameLayers;

class ExportedByPolyBodyBuilders CATPolyBodyMultiLayerBuilder
{
public:
	CATPolyBodyMultiLayerBuilder ();
	virtual ~CATPolyBodyMultiLayerBuilder () ;

public:
  typedef enum
  {
    PreAllocated,
    Buckets
  } MeshImplementation_T;
  
  HRESULT SetMeshImplentation(MeshImplementation_T iImplementation)
  {_MeshImplementation=iImplementation;return S_OK;}

public:
  HRESULT Concatenate(const CATPolyBody& iPolyBody, 
                      const CATMathTransformation * iTransfo=0,
                      const int iFrame=1);

  HRESULT BuildPolyBody(CATPolyBody*& oPolyBody, CATIPolyBodyFrameLayers*& oFrameLayers);

private:
  CATPolyBody* _PolyBody;
  CATPolyBodyPreAllocatedFrameLayers* _Layers;
  CATMapOfIntToPtr* _ID2NewPolyCell;
  MeshImplementation_T _MeshImplementation;
};
#endif 
