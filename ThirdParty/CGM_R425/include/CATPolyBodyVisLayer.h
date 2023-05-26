// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyVisLayer.h
//
//===================================================================
// October 2012 Creation: NDO, ZFI
// January 2015 Modification JXO: Sharpness
//===================================================================
#ifndef CATPolyBodyVisLayer_H
#define CATPolyBodyVisLayer_H

#include "PolyVizLayers.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "CATMapOfPtrToInt.h"

class CATPolyBody;
class CATPolyCell;
class CATPolyFace;

class CATRep;
class CAT3DGeomRep;
class CAT3DCustomRep;
class CATGraphicMaterial;
class CATGraphicPrimitive;
class CATGraphicAttributeSet;
class CATMapOfPtrToPtr;


/**
 * A layer that encapsulates all the graphic attributes and material that are associated to a CATPolyBody.
 * @see CATMapOfVisAttributes
 */
class ExportedByPolyVizLayers CATPolyBodyVisLayer
{

public:

  CATPolyBodyVisLayer ();
  ~CATPolyBodyVisLayer ();

public:

/** @name Enumerator defining the type of primitives associated to the rep.
    @{ */

    enum PrimitiveType
    {
      eUndefined          = 0,
      eGraphicPrimitive,
      //eVisPrimitive,
      ePrimitiveKey
    };

/** @} */

public:

  /**
   * Flushes the layer of all the attributes it contains.
   */
  void Flush ();

  /**
   * Flushes the graphic materials.
   */
  void FlushGraphicMaterials ();

  /**
   * Flushes all the graphic attributes that have been set in the layer,
   * including the graphic attributes for the cells.
   */
  void FlushGraphicAttributes ();

  /**
   * Flushes all the primitives that have been set in the layer.
   */
  void FlushPrimitives ();

public:

/** @name Global CATPolyBody Graphic Attributes
    @{ */

  /**
   * Sets a rep as an attribute to a CATPolyBody.
   * This method does not manage the lifecycle of the rep.
   */
  void Set (const CATRep* iRep);

  inline const CATRep* GetRep () const;

  /**
   * Sets the graphic material as an attribute to a CATPolyBody.
   * This method keeps a reference (with lifecycle management) to the graphic material (no copy.)
   */
  void Set (CATGraphicMaterial* iGM);

  inline CATGraphicMaterial* GetGraphicMaterial () const;

  /**
   * Sets the graphic attribute set as an attribute to a CATPolyBody.
   * This method keeps a copy of the graphic attributes.
   */
  void Set (const CATGraphicAttributeSet* iGA);

  inline const CATGraphicAttributeSet* GetGraphicAttributes () const;

/** @} */

public:

/** @name Default Graphic Attributes for CATPolyVertex, CATPolyEdge and CATPolyFace
    @{ */

  void SetDefaultGraphicAttributesForVertices (const CATGraphicAttributeSet* iGA);
  void SetDefaultGraphicAttributesForEdges (const CATGraphicAttributeSet* iGA);
  void SetDefaultGraphicAttributesForFaces (const CATGraphicAttributeSet* iGA);

  inline const CATGraphicAttributeSet* GetDefaultGraphicAttributesForVertices () const;
  inline const CATGraphicAttributeSet* GetDefaultGraphicAttributesForEdges () const;
  inline const CATGraphicAttributeSet* GetDefaultGraphicAttributesForFaces () const;

/** @} */

public:

/** @name Graphic Attributes for CATPolyCell.
    @{ */

  /**
   * Sets the graphic material as an attribute to a CATPolyFace.
   * This method keeps a reference (with lifecycle management) to the graphic material (no copy.)
   */
  void Set (const CATPolyFace* iFace, CATGraphicMaterial* iGM);

  CATGraphicMaterial* GetGraphicMaterial (const CATPolyFace* iFace) const;

  /**
   * Sets the graphic attribute set as an attribute to a CATPolyCell.
   * This method keeps a copy of the graphic attributes.
   */
  void Set (const CATPolyCell* iCell, const CATGraphicAttributeSet* iGA);

  const CATGraphicAttributeSet* GetGraphicAttributes (const CATPolyCell* iCell) const;

  /** Sharpness - don't use */
  int GetSharpness(const CATPolyCell* iPolyCell) const;
  void SetSharpness(const CATPolyCell* iPolyCell, int sharpness);


  /**
   * Sets the graphic attributes for each cell of a CATPolyBody constructed from a CAT3DGeomRep.
   * This method calls the Set () method for each CATPolyCell of the CATPolyBody.
   */
  HRESULT AddGraphicAttributesForEachPolyCell (CATPolyBody& iPolyBody, CAT3DGeomRep& iRep);

  HRESULT AddGraphicAttributesForEachPolyCell(CATPolyBody& iPolyBody, CAT3DCustomRep& iRep);

  /**
   * Overrides the transparency of each CATPolyFace attributes.
   */
  HRESULT ApplyAlphaToFaceAttributes (const int iAlpha);

  /**
   * Overrides the transparency by applying alpha.
   */
  HRESULT ApplyAlpha (const int iAlpha);

/** @} */

public:

/** @name Primitives for CATPolyCell.
    @{ */

  /**
   * Returns the type of primitives associated to the CATPolyCell.
   * The type of primitives associated to the CATPolyCell should be the same for all cells.
   */
  inline PrimitiveType GetTypeOfPrimitive () const;

  /**
   * Sets a CATGraphicPrimitive instance as an attribute to a CATPolyCell.
   * @return
   *   <ul>
   *     <li> <tt>S_FALSE</tt> if the primitive cannot be associated to the cell (wrong type).
   *     <li> <tt>S_OK</tt> otherwise.
   *    </ul>
   */
  HRESULT Set (const CATPolyCell* iCell, const CATGraphicPrimitive* iGP);

  /**
   * Returns the CATGraphicPrimitive instance associated to a CATPolyCell.
   */
  const CATGraphicPrimitive* GetGraphicPrimitive (const CATPolyCell* iCell) const;

  /**
   * Sets a primitive key as an attribute to a CATPolyCell.
   * @return
   *   <ul>
   *     <li> <tt>S_FALSE</tt> if the primitive key cannot be associated to the cell (wrong type).
   *     <li> <tt>S_OK</tt> otherwise.
   *    </ul>
   */
  HRESULT Set (const CATPolyCell* iCell, void* iPrimitiveKey);

  /**
   * Returns the primitive key instance associated to a CATPolyCell.
   */
  void* GetPrimitiveKey (const CATPolyCell* iCell) const;

/** @} */

public:

/** @name Copy operators.
    @{ */

  /**
   * Assignement operator.
   */
  CATPolyBodyVisLayer& operator = (const CATPolyBodyVisLayer& iRHS);

  /**
   * Copies the CATGraphicAttributeSet and CATGraphicMaterial from the input vis layer iVisLayer.
   * The method also copies the attributes for the cells if the mapping iMapOutputToInputCells is not null.
   * This mapping maps an output cell (a cell associated to this vis layer) to an input cell (a cell associated to
   * the iVisLayer vis layer.)
   */
  HRESULT CopyGraphicAttributesAndMaterial (const CATPolyBodyVisLayer& iVisLayer, const CATMapOfPtrToPtr* iMapOutputToInputCells);

/** @} */

  static void AddRefGM (CATGraphicMaterial* gm);
  static void ReleaseGM (CATGraphicMaterial* gm);

private:

  const CATRep* _Rep;

  // CATPolyBody Vis Attributes.
  CATGraphicMaterial* _GM;
  CATGraphicAttributeSet* _GA;

  // Default Vis Attributes.
  CATGraphicAttributeSet* _DefaultGAVertex;
  CATGraphicAttributeSet* _DefaultGAEdge;
  CATGraphicAttributeSet* _DefaultGAFace;

  // CATPolyCell Vis Attributes.
  CATMapOfPtrToPtr* _MapFaceToGM;
  CATMapOfPtrToPtr* _MapCellToGA;
  CATMapOfPtrToInt  _PolyCell2SharpMap;

  // CATPolyCell Vis Primitives.
  CATMapOfPtrToPtr* _MapCellToPrimitive;

  PrimitiveType _PrimitiveType;

private:

  HRESULT AddGraphicAttributesForPolyFace (CATPolyBody& iPolyBody, CAT3DGeomRep& iRep);
  HRESULT AddGraphicAttributesForPolyEdge (CATPolyBody& iPolyBody, CAT3DGeomRep& iRep);

};

inline const CATRep* CATPolyBodyVisLayer::GetRep () const
{
  return _Rep;
}

inline CATGraphicMaterial* CATPolyBodyVisLayer::GetGraphicMaterial () const
{
  return _GM;
}

inline const CATGraphicAttributeSet* CATPolyBodyVisLayer::GetGraphicAttributes () const
{
  return _GA;
}

inline const CATGraphicAttributeSet* CATPolyBodyVisLayer::GetDefaultGraphicAttributesForVertices () const
{
  return _DefaultGAVertex;
}

inline const CATGraphicAttributeSet* CATPolyBodyVisLayer::GetDefaultGraphicAttributesForEdges () const
{
  return _DefaultGAEdge;
}

inline const CATGraphicAttributeSet* CATPolyBodyVisLayer::GetDefaultGraphicAttributesForFaces () const
{
  return _DefaultGAFace;
}

inline CATPolyBodyVisLayer::PrimitiveType CATPolyBodyVisLayer::GetTypeOfPrimitive () const
{
  return _PrimitiveType;
}

#endif
