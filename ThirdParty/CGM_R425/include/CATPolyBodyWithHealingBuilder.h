//=============================================================================
// COPYRIGHT Dassault Systemes 2009
//=============================================================================
//
// CATPolyBodyWithHealingBuilder.h
//
//=============================================================================
// 2009-10-10 ZFI
//=============================================================================

#ifndef CATPolyBodyWithHealingBuilder_H
#define CATPolyBodyWithHealingBuilder_H


#include "PolyBodyBuilders.h"

#include "CATErrorDef.h" 
#include "CATBoolean.h"


class CATPolyBody;
class CATPolyDecoMeshBars;
class CATPolyDecoMeshBarsConcatenator;
class CATMapOfPtrToPtr;
class CATMapOfIntToPtr;
class CATMathTransformation;

class ExportedByPolyBodyBuilders CATPolyBodyWithHealingBuilder
{
public:
	CATPolyBodyWithHealingBuilder () ;
	virtual ~CATPolyBodyWithHealingBuilder () ;

public:
  HRESULT Concatenate(const CATPolyBody& iPolyBody, 
                      const CATMathTransformation * iTransfo=0,
                      CATBoolean iEnableMapping=0);

  HRESULT BuildPolyBody(CATPolyBody*& oValidPolyBody,
                        CATMapOfPtrToPtr* ioMapNew2OldPolyCell=0);
    
  HRESULT BuildMonoFacePolyBody(CATPolyBody*& oPolyBody);
  

public:
  //options
  HRESULT SetTolerance(const float iTolerance);
  HRESULT CreateOnFace(CATBoolean iCreateOneFace);
  HRESULT CreatePolyEdges(CATBoolean iCreatePolyEdges);
  HRESULT SetAutoMode(CATBoolean iAutoMode);
  HRESULT SetCloneMode(CATBoolean iCloneMode);


public:
  //for debug
  CATPolyDecoMeshBars* GetDecoMesh();

private:
  CATPolyDecoMeshBars* _DecoMesh;
  CATPolyDecoMeshBarsConcatenator* _DecoMeshConcatenator;
  CATMapOfIntToPtr* _MapTag2OldPolyCell;

  int _LastTag;

  float _Tolerance;
  CATBoolean _CreateOneFace;
  CATBoolean _CreatePolyEdges;
  CATBoolean _AutoMode, _CloneMode;
};
#endif 
