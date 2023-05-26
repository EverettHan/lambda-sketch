// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyVisLayerSet.h
//
//===================================================================
// October 2012 Creation: ndo
//===================================================================
#ifndef CATPolyBodyVisLayerSet_H
#define CATPolyBodyVisLayerSet_H

#include "PolyVizLayers.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "CATMapOfPtrToPtr.h"

class CATPolyBody;
class CATPolyBodyVisLayer;
class CATRep;
class CAT3DGeomRep;
class CAT4x4Matrix;
class CATGraphicAttributeSet;
class CATGraphicMaterial;
class CATMathTransformation;


class ExportedByPolyVizLayers CATPolyBodyVisLayerSet
{

public:

  CATPolyBodyVisLayerSet ();
  ~CATPolyBodyVisLayerSet ();

public:

  /**
   * Constructs a new CATPolyBodyVisLayerSet containing the CATPolyBody for all the children of a CATRep.
   */
  static HRESULT Make (CATRep& iRep, CATPolyBodyVisLayerSet*& oSet);

public:

  /**
   * Inserts a CATPolyBody in the set with optional visualization attributes including:
   * <ul>
   *   <li> A math transformation;
   *   <li> A rep associated to the CATPolyBody;
   *   <li> A graphic attribute set for this CATPolyBody;
   *   <li> A transparency value (if different from NULL) to override the transparency from the graphic attributes;
   *   <li> A graphic material for this CATPolyBody.
   * </ul>
   * If requested, the method returns a pointer to a CATPolyBodyVisLayer instance for further setting of the cell attributes.
   * This object should not be deleted.
   */
  //HRESULT Insert (CATPolyBody& iPolyBody, CATMathTransformation* iPositionMatrix, 
                  //CATRep* iRep, const CATGraphicAttributeSet* ga, const int* iAlpha, CATGraphicMaterial* gm,
                  //CATPolyBodyVisLayer** oBodyVisLayer = 0);

  /**
   * Inserts a CATPolyBody in the set and absorbs the position matrix and the vis layer.
   * @param iPolyBody
   *   The CATPolyBody to insert.
   * @param iPositionMatrix
   *   The position of the CATPolyBody.  The instance is absorbed by the class and should not be deleted.
   * @param iVisLayer
   *   The visualization layer.  The instance is absorbed by the class and should not be deleted.
   */
  HRESULT Insert (CATPolyBody& iPolyBody, CATMathTransformation* iPositionMatrix, CATPolyBodyVisLayer* iVisLayer);

  /**
   * Returns the CATPolyBodyVisLayer associated to a CATPolyBody.
   */
  const CATPolyBodyVisLayer* GetVisLayer (const CATPolyBody* iPolyBody) const;

  /**
   * Removes all references to the CATRep.  
   * It keeps the graphic attributes and graphic materials (no change to these data.)
   */
  void FlushReps ();

  /**
   * Removes all elements from the set.
   */
  void RemoveAll ();

public:

  inline unsigned int Size () const;

  /**
   * Iterator returning all the CATPolyBody contained in the CATPolyBodyVisLayerSet and their associated attributes.
   */
  class ExportedByPolyVizLayers Iterator
  {
  public:

    Iterator (const CATPolyBodyVisLayerSet& iSet) : _Iterator (iSet._PolyBodyMap) {}
    ~Iterator () {}

  public:

    Iterator& Begin () {_Iterator.Begin (); return *this;}
    CATBoolean End () const {return _Iterator.End ();}
    Iterator& operator++ () {++_Iterator; return *this;}

  public:

    CATPolyBody* GetPolyBody ();
    const CATMathTransformation* GetPositionMatrix ();

    const CATPolyBodyVisLayer* GetVisLayer ();

  private:

    CATMapOfPtrToPtr::Iterator _Iterator;

  };

private:

  CATMapOfPtrToPtr _PolyBodyMap;

private:
//public: // erreur de build solaris

  friend class Iterator;

};

inline unsigned int CATPolyBodyVisLayerSet::Size () const
{
  return _PolyBodyMap.Size ();
}

#endif // CATPolyBodyVisLayerSet_H
