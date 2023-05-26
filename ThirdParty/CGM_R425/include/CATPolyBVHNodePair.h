//=============================================================================
// COPYRIGHT Dassault Systemes 2009
//=============================================================================
//
// CATPolyBVHNodePair.h
//
//=============================================================================
// 2009-03-12   JXO
//      * New
// 2015-04-23   JXO
//      * Warning correction
//=============================================================================
#ifndef CATPolyBVHNodePair_H
#define CATPolyBVHNodePair_H

#include "PolyBVH.h"

#include "CATErrorDef.h"
#include "CATMathTransformation.h"


class CATBVHNodeConst;
class CATIPolyMesh;
class CATCellId;

/**
 * Clash couple. Manages BVH Node, Mesh and Position.
 */

class ExportedByPolyBVH CATPolyBVHNodePair
{
public:
  CATPolyBVHNodePair(const CATPolyBVHNodePair & iCopy);
  CATPolyBVHNodePair();
  ~CATPolyBVHNodePair();

public:

  HRESULT SetFirst(void * pNode1, CATIPolyMesh * pMesh1, const CATMathTransformation * pPos1 = NULL);
  HRESULT SetSecond(void * pNode2, CATIPolyMesh * pMesh2, const CATMathTransformation * pPos2 = NULL);

  inline void * GetFirstNode() const {return _pNode1;}
  inline void * GetSecondNode() const {return _pNode2;}
  inline CATIPolyMesh * GetFirstMesh() const {return _pMesh1;}
  inline CATIPolyMesh * GetSecondMesh() const {return _pMesh2;}
  inline const CATMathTransformation & GetFirstTransformation() const {return _Pos1;}
  inline const CATMathTransformation & GetSecondTransformation() const {return _Pos2;}
  inline void GetFirst(void * &pNode1, CATIPolyMesh * &pMesh1, CATMathTransformation & Pos1) const
  {
    pNode1 = _pNode1;
    pMesh1 = _pMesh1;
    Pos1 = _Pos1;
  }
  inline void GetSecond(void * &pNode2, CATIPolyMesh * &pMesh2, CATMathTransformation & Pos2) const
  {
    pNode2 = _pNode2;
    pMesh2 = _pMesh2;
    Pos2 = _Pos2;
  }

  CATPolyBVHNodePair & operator = (const CATPolyBVHNodePair & iCopy)
  {
    return Copy(iCopy);
  }

  /**
   * Face ids. To be released after use.
   */
  CATCellId * GetAssociatedFaceId1();
  /**
   * Face ids. To be released after use.
   */
  CATCellId * GetAssociatedFaceId2();


  const void * GetFirstUserData() const;
  const void * GetSecondUserData() const;
  void SetFirstUserData(const CATBVHNodeConst *);
  void SetSecondUserData(const CATBVHNodeConst *);
  const CATIPolyMesh * GetFirstUserMesh() const;
  const CATIPolyMesh * GetSecondUserMesh() const;

  int GetIndex1();
  int GetIndex2();
  void SetIndex1(int i);
  void SetIndex2(int i);

private:
  CATPolyBVHNodePair & Copy(const CATPolyBVHNodePair & iCopy);

private:
  CATMathTransformation _Pos1;
  CATMathTransformation _Pos2;
  void * _pNode1;
  void * _pNode2;
  CATIPolyMesh * _pMesh1;
  CATIPolyMesh * _pMesh2;
  const CATBVHNodeConst * _userdata1;
  const CATBVHNodeConst * _userdata2;
  int _index1;
  int _index2;

};

#endif // !CATPolyBVHNodePair_H
