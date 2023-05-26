// COPYRIGHT DASSAULT SYSTEMES 2013, ALL RIGHTS RESERVED.
//===================================================================
//
// CATMapOfIntToGraphicAttributeSet.h
//
//===================================================================
// March 2013 Creation: NDO
//===================================================================
#ifndef CATMapOfIntToGraphicAttributeSet_H
#define CATMapOfIntToGraphicAttributeSet_H

#include "PolyVizLayers.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "CATMapOfIntToPtr.h"
#include "CATMapOfIntToInt.h"
#include "CATMapOfPtrToPtr.h"

class CATGraphicAttributeSet;
class CATGraphicMaterial;


/**
 * A map of integer to CATGraphicAttributeSet.
 * Can also store the graphic material.
 * @see CATPolyBodyVisLayer
 */
class ExportedByPolyVizLayers CATMapOfIntToGraphicAttributeSet
{

public:

  CATMapOfIntToGraphicAttributeSet () : _HasFaceGM(FALSE), _RepGMCount(0) {}
  inline ~CATMapOfIntToGraphicAttributeSet ();

public:

  /**
   * Associates a CATGraphicAttributeSet to a tag.
   * This method keeps a copy of the graphic attributes.
   */
  void SetGraphicAttributes (const int iTag, const CATGraphicAttributeSet* iGA);

  /**
   * Returns the CATGraphicAttributeSet associated to a tag.
   */
  const CATGraphicAttributeSet* GetGraphicAttributes (const int iTag) const;

  /**
  * Associates a CATGraphicMaterial to a tag.
  * This increases the reference counter.
  */
  void SetGraphicMaterial(const int iTag, const CATGraphicMaterial* iGM, CATBoolean isFaceGM);

  /**
  * Returns the CATGraphicMaterial associated to a tag.
  */
  CATGraphicMaterial* GetGraphicMaterial(const int iTag) const;

  /**
   * Flushes the map from all tags and graphic attributes.
   */
  void RemoveAll ();

  /** Sharpness */
  int GetSharpness(const int iTag) const;
  /** Sharpness */
  void SetSharpness(const int iTag, int sharpness);

  /** CGMId */
  unsigned int GetCGMId(const int iTag) const;
  /** CGMId */
  void SetCGMId(const int iTag, unsigned int iCGMId);


private:

  CATMapOfIntToPtr _MapTagToGA;
  CATMapOfIntToInt _MapTagToSharpness;
  CATMapOfIntToInt _MapTagToCGMId;
  CATMapOfIntToPtr _MapTagToGM;
  CATMapOfPtrToPtr _MapOriginalGMToClone;
  CATBoolean _HasFaceGM;
  int _RepGMCount;
};


inline CATMapOfIntToGraphicAttributeSet::~CATMapOfIntToGraphicAttributeSet ()
{
  RemoveAll ();
}

#endif
