// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//===================================================================
//
// CAT3DRepHierarchyIterator.h
//
//===================================================================
// October 2012 - Creation NDO
//===================================================================
#ifndef CAT3DRepHierarchyIterator_H
#define CAT3DRepHierarchyIterator_H

#include "PolyVizUtils.h"

#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "CATListPV.h"

#include "CATIAV5Level.h"
#ifdef CATIACGMR215Code
#include "CATCGMScaleCategoryDef.h"
#else
#include "CATTolerance.h"
#endif

class CATRep;
class CAT3DBagRep;
class CAT4x4Matrix;
class CATGraphicAttributeSet;
class CATGraphicMaterial;
class CATMathTransformation;


/**
 * Iterates through all the terminal CATRep (leaf rep) from a CATRep hierarchy consisting of a nested set of CAT3DBagRep.
 * This class parses recursively the CAT3DBagRep and returns the reps they contain.
 * Various filters can be set to skip some of the reps.
 */
class ExportedByPolyVizUtils CAT3DRepHierarchyIterator
{

public:

  /**
   * A filter interface which can be implemented for selection of the reps.
   */
  class Filter
  {

  public:

    /** 
     * Returns <tt>TRUE</tt> if the rep should be selected in the parsing.
     */
    virtual CATBoolean Select (const CATRep& iRep) = 0;

  };

public:

/** @name Filters
    @{ */

  /**
   * Returns a reference to a filter for selection of the reps
   * that are in the shown state (excluding the reps in the hidden state.)
   * The instance returned should not be deleted.
   */
  static Filter* SelectRepsInShownState ();

/** @} */

public:

  /**
   * An iterator through the full path of CAT3DBagRep starting from the input CAT3DBagRep 
   * and ending at the CAT3DBagRep containing the current terminal rep.
   */
  class ExportedByPolyVizUtils PathIterator
  {

  public:

    PathIterator (const CAT3DRepHierarchyIterator& iHierarchyIterator);
    ~PathIterator () {}

  public:

    PathIterator& Begin () {_StackIndex = 0; _Count = _HierarchyIterator._Stack.Size (); return *this;}
    CATBoolean End () const {return _StackIndex < _Count ? FALSE : TRUE;}
    PathIterator& operator++ () {++_StackIndex; return *this;}

  public:

    /** 
     * Returns a CAT3DBagRep from the path.
     */
    CAT3DBagRep* GetRep () const;

  private:

    const CAT3DRepHierarchyIterator& _HierarchyIterator;
    unsigned int _StackIndex;
    unsigned int _Count;

  };

public:

  CAT3DRepHierarchyIterator (CATRep& iRep, Filter* iFilter = 0);
  ~CAT3DRepHierarchyIterator ();

  /**
   * Sets a flag to process the texture matrices in the parsing of the CATRep hierarchy.
   * By default the texture matrices (stored as attributes of Vis3DNodeGroupRep) are not processed.
   */
  inline void DoParseTextureMatrices (const CATBoolean iParse);

public:

  CAT3DRepHierarchyIterator& Begin ();
  inline CATBoolean End () const;
  CAT3DRepHierarchyIterator& operator++ ();

public:

  inline CATRep* GetRep () const;

  inline const CATMathTransformation* GetPositionMat () const;
  inline const CATMathTransformation* GetTextureMat () const;

  inline const CAT4x4Matrix* GetPositionMatrix () const;
  inline const CAT4x4Matrix* GetTextureMatrix () const;

  inline const CATGraphicAttributeSet* GetGraphicAttributeSet () const;
  inline const CATGraphicMaterial* GetGraphicMaterial () const;

  inline const int* GetAlpha () const;

  inline const CATCGMScaleCategory& GetScaleCategory() const;

  inline CATBoolean HasVis3DNodeGroupRep() const;

private:

  CATRep& _Rep;
  Filter* _Filter;

  CATBoolean _DoParseTextureMatrix;

private:

  CATListPV _Stack;

  CATRep* _CurrentRep;
  const CATMathTransformation* _PositionTransfo;
  const CATMathTransformation* _TextureTransfo;
  const CAT4x4Matrix* _PositionMatrix;
  const CAT4x4Matrix* _TextureMatrix;
  CATGraphicAttributeSet & _ga;
  const CATGraphicAttributeSet* _GraphicAttributes;
  const CATGraphicMaterial* _GraphicMaterial;
  const int* _Alpha;  // Pointer to transparency if set.
  CATCGMScaleCategory _ScaleCategory;

  CATBoolean m_HasVis3DNodeGroupRep;
private:

  void Flush ();
  void ParseToNext ();

  // Update the member variable _GraphicAttributes for a leaf rep iRep given a parent graphic attribute set (may be null.)
  void UpdateGraphicAttributes (const CATGraphicAttributeSet* iParentGA, CATRep& iRep);

  // Update the member variable _GraphicMaterial for a leaf rep iRep given a parent graphic material (may be null.)
  void UpdateGraphicMaterial (const CATGraphicMaterial* iParentGM, const int iParentInherit, CATRep& iRep);

  friend class PathIterator;

};


inline void CAT3DRepHierarchyIterator::DoParseTextureMatrices (const CATBoolean iParse)
{
  _DoParseTextureMatrix = iParse;
}

inline CATBoolean CAT3DRepHierarchyIterator::End () const
{
  return _CurrentRep == 0;
}

inline CATRep* CAT3DRepHierarchyIterator::GetRep () const
{
  return _CurrentRep;
}

inline const CATMathTransformation* CAT3DRepHierarchyIterator::GetPositionMat () const
{
  return _PositionTransfo;
}

inline const CATMathTransformation* CAT3DRepHierarchyIterator::GetTextureMat () const
{
  return _TextureTransfo;
}

inline const CAT4x4Matrix* CAT3DRepHierarchyIterator::GetPositionMatrix () const
{
  return _PositionMatrix;
}

inline const CAT4x4Matrix* CAT3DRepHierarchyIterator::GetTextureMatrix () const
{
  return _TextureMatrix;
}

inline const CATGraphicAttributeSet* CAT3DRepHierarchyIterator::GetGraphicAttributeSet () const
{
  return _GraphicAttributes;
}

inline const CATGraphicMaterial* CAT3DRepHierarchyIterator::GetGraphicMaterial () const
{
  return _GraphicMaterial;
}

inline const int* CAT3DRepHierarchyIterator::GetAlpha () const
{
  return _Alpha;
}

inline const CATCGMScaleCategory& CAT3DRepHierarchyIterator::GetScaleCategory () const
{
  return _ScaleCategory;
}

inline CATBoolean CAT3DRepHierarchyIterator::HasVis3DNodeGroupRep() const
{
  return m_HasVis3DNodeGroupRep;
}

#endif
