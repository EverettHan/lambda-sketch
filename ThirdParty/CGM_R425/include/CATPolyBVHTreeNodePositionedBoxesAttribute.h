//=============================================================================
// COPYRIGHT Dassault Systemes 2009
//=============================================================================
//
// CATPolyBVHTreeNodePositionedBoxesAttribute.h
//
//=============================================================================
// 2009-01-07   JXO
//      * New
//=============================================================================
#ifndef CATPolyBVHTreeNodePositionedBoxesAttribute_H
#define CATPolyBVHTreeNodePositionedBoxesAttribute_H

#include "PolyBVH.h"

#include "CATMathTransformation.h"
#include "CATIPolyMesh.h"
#include "CATBVHAttribute.h"
#include "CATIPolySurfaceVertexPositionConstLayer.h"
#include "CATIPolyMeshTriangleIterator.h"
#include "CATPolyPool.h"

// We can make this class thread safe
#include "CATMutex.h"

#include "CATMathBox.h"
#include "CATMathPoint.h"

class ExportedByPolyBVH CATPolyBVHTreeNodePositionedBoxesAttribute: public CATBVHAttribute
{
  CATPolyDeclarePooledNew;

public:
  CATPolyBVHTreeNodePositionedBoxesAttribute(CATIPolyMesh * pMesh, const CATMathTransformation * pPos = NULL):
      _PolyMesh(pMesh),
      _boxes(NULL),
      _trianglepoints(NULL),
      _verticeslayer(NULL),
      _it(NULL)
      {
        _nbTriangles = 0;
        _rebuildboxes = TRUE;
        _rebuildpoints = TRUE;
        if(NULL != pPos)_pos=(*pPos);
        if(NULL != _PolyMesh)
        {
          _PolyMesh->AddRef();
          _PolyMesh->GetVertexPositionLayer(_verticeslayer);
          _PolyMesh->GetTriangleIterator(_it);
          _nbTriangles = _PolyMesh->GetNbTriangles();
          if(_nbTriangles > 0)
          {
            _boxes = new CATMathBox[_nbTriangles];
            _trianglepoints = new CATMathPoint[3 * _nbTriangles];
          }
        }
      }
  ~CATPolyBVHTreeNodePositionedBoxesAttribute();

  inline CATIPolyMesh * GetMesh(){return _PolyMesh;}

  inline const CATMathTransformation & GetPosition() const {return _pos;}
  inline void SetPosition(CATMathTransformation & Pos)
  {
    _mutexPos.Lock();
    _pos = Pos;
    _mutexPos.Unlock();
    _mutexBoxes.Lock();
    _rebuildboxes = TRUE;
    _mutexBoxes.Unlock();
    _mutexPoints.Lock();
    _rebuildpoints = TRUE;
    _mutexPoints.Unlock();
  }
  
  CATMathBox * GetBoxes(CATMathBox & oGlobalBox);
  // Size is 3 x nbtriangles
  CATMathPoint * GetTrianglesBuffer();

  int GetNbTriangles(){return _nbTriangles;}

protected:
  CATIPolyMesh * _PolyMesh;
  CATIPolySurfaceVertexPositionConstLayer * _verticeslayer;
  CATIPolyMeshTriangleIterator * _it;
  CATMathTransformation _pos;
  CATMathBox * _boxes;
  CATMathBox _GlobalBox;
  CATMathPoint * _trianglepoints;
  CATMutex _mutexPoints;
  CATMutex _mutexBoxes;
  CATMutex _mutexPos;
  CATBoolean _rebuildboxes;
  CATBoolean _rebuildpoints;
  int _nbTriangles;
};

#endif // !CATPolyBVHTreeNodePositionedBoxesAttribute_H

