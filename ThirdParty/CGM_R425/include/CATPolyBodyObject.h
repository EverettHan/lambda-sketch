// COPYRIGHT DASSAULT SYSTEMES 2010, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyObject.h
//
//===================================================================
//
// Usage notes: 
//
//===================================================================
//
// August 2010  Creation: XCZ
//===================================================================

#ifndef CATPolyBodyObject_H
#define CATPolyBodyObject_H

#include "CATBaseUnknown.h"
#include "CATListPV.h"
#include "PolyVizObject.h"


class CATPolyBody;
class CATPolyCell;
class CATPolyCellObject;
class CATGraphicMaterial;
class CAT3DBagRep;
class CAT3DRep;
class CATMapOfPtrToPtr;
class CATGraphicPrimitive;
class CATVizPrimitive;
class CATMathTransformation;
class CATPolyBodyImportVizLayer;
class CATBody;
class CAT4x4Matrix;
class CATMathTransformation;
class CATPolyFace;
class CATRepWeakRef;

class ExportedByPolyVizObject CATPolyBodyObject : public CATBaseUnknown
{
  CATDeclareClass;

public:
  CATPolyBodyObject();
  virtual ~CATPolyBodyObject();

public:


  // Set/Get attached polyBody
  void UnSetPolyBody();
  CATPolyBody *GetPolyBody();
  const CATPolyBody *GetPolyBody() const;

  // Build associated Rep
  void BuildRep();

  // Get rep
  CAT3DRep *GiveBagRep();
  const CAT3DRep *GiveBagRep()const;

  // Get/Set graphic material
  void SetGraphicMaterial(CATGraphicMaterial *iGraphicMaterial);
  CATGraphicMaterial *GetGraphicMaterial();
  const CATGraphicMaterial *GetGraphicMaterial() const;

  // Get/Set position
  void SetPosition(const CAT4x4Matrix &iPosition);
  const CAT4x4Matrix *GetPosition() const;

  // Get (or create) CATPolyCellObject object from CATPolyCell
  void GetPolyCellObject(CATPolyCell *iCell, CATPolyCellObject *&ioPolyCellObject);

  // Get CATPolyCellObject from visu primitive key 
  CATPolyCellObject *GetPolyCellObjectFromVP(int iVP);

  HRESULT UpdateFromPolyBody(CATPolyBody *iPolyBody, CATPolyBodyImportVizLayer *iVizLayer, CATGraphicMaterial *iGM = NULL);

  HRESULT UpdateVisuFromPolyCell(const CATPolyFace *PolyFace);

  HRESULT RemovePolyCellInVisu(const CATPolyFace *PolyFace);

  void UpdatePolyCellFromVisu(const CATPolyFace *PolyFace, CAT3DRep *iRep, void *iPrimitiveKey);

  void SetNewSG(int iNewSG) { _NewSG = iNewSG; }



private:
  void SetPolyBody(CATPolyBody *iPolyBody);
  CAT3DRep *BuildModelRepNewSG();
  void RemoveAllCells();



private:
  CATPolyBody *_PolyBody;
  CATGraphicMaterial *_GraphicMaterial;
  CATMapOfPtrToPtr *_PolyCellPolyCellObjectMap;
  CATMapOfPtrToPtr *_VPPolyCellObjectMap;
  CATListPV _PolyCellObjects;

  //bag rep of the polybody (with position)
  CATRepWeakRef *_WeakRefToBodyBagRep;

  CAT4x4Matrix *_Position;
  int _NewSG;


};

#endif
