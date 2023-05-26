// COPYRIGHT DASSAULT SYSTEMES 2015, ALL RIGHTS RESERVED.
//===================================================================
//
// CAT2DRepHierarchyIterator.h
//
//===================================================================
// October 2012 - Creation NDO
//===================================================================
#ifndef CAT2DRepHierarchyIterator_H
#define CAT2DRepHierarchyIterator_H

#include "PolyVizUtils.h"

#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "CATListPV.h"

class CATRep;
class CAT2DBagRep;
class CAT3x3Matrix;
class CATGraphicAttributeSet;
class CATGraphicMaterial;
class CATMathTransformation2D;


/**
 * Iterates through all the terminal CATRep (leaf rep) from a CATRep hierarchy consisting of a nested set of CAT2DBagRep.
 * This class parses recursively the CAT2DBagRep and returns the reps they contain.
 * Various filters can be set to skip some of the reps.
 */
class ExportedByPolyVizUtils CAT2DRepHierarchyIterator
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
   * An iterator through the full path of CAT2DBagRep starting from the input CAT2DBagRep 
   * and ending at the CAT2DBagRep containing the current terminal rep.
   */
  class ExportedByPolyVizUtils PathIterator
  {

  public:

    PathIterator (const CAT2DRepHierarchyIterator& iHierarchyIterator);
    ~PathIterator () {}

  public:

    PathIterator& Begin () {_StackIndex = 0; _Count = _HierarchyIterator._Stack.Size (); return *this;}
    CATBoolean End () const {return _StackIndex < _Count ? FALSE : TRUE;}
    PathIterator& operator++ () {++_StackIndex; return *this;}

  public:

    /** 
     * Returns a CAT2DBagRep from the path.
     */
    CAT2DBagRep* GetRep () const;

  private:

    const CAT2DRepHierarchyIterator& _HierarchyIterator;
    unsigned int _StackIndex;
    unsigned int _Count;

  };

public:

  CAT2DRepHierarchyIterator (CATRep& iRep, Filter* iFilter = 0);
  ~CAT2DRepHierarchyIterator ();

public:

  CAT2DRepHierarchyIterator& Begin ();
  inline CATBoolean End () const;
  CAT2DRepHierarchyIterator& operator++ ();

public:

  inline CATRep* GetRep () const;

  inline const CATMathTransformation2D* GetPositionMat () const;

  inline const CAT3x3Matrix* GetPositionMatrix () const;

  inline const CATGraphicAttributeSet* GetGraphicAttributeSet () const;
  inline const CATGraphicMaterial* GetGraphicMaterial () const;

  inline const int* GetAlpha () const;

private:

  CATRep& _Rep;
  Filter* _Filter;

private:

  CATListPV _Stack;

  CATRep* _CurrentRep;
  const CATMathTransformation2D* _PositionTransfo;
  const CAT3x3Matrix* _PositionMatrix;
  CATGraphicAttributeSet & _ga;
  const CATGraphicAttributeSet* _GraphicAttributes;
  const CATGraphicMaterial* _GraphicMaterial;
  const int* _Alpha;  // Pointer to transparency if set.

private:

  void Flush ();
  void ParseToNext ();

  // Update the member variable _GraphicAttributes for a leaf rep iRep given a parent graphic attribute set (may be null.)
  void UpdateGraphicAttributes (const CATGraphicAttributeSet* iParentGA, CATRep& iRep);

  // Update the member variable _GraphicMaterial for a leaf rep iRep given a parent graphic material (may be null.)
  void UpdateGraphicMaterial (const CATGraphicMaterial* iParentGM, const int iParentInherit, CATRep& iRep);

  friend class PathIterator;

};

inline CATBoolean CAT2DRepHierarchyIterator::End () const
{
  return _CurrentRep == 0;
}

inline CATRep* CAT2DRepHierarchyIterator::GetRep () const
{
  return _CurrentRep;
}

inline const CATMathTransformation2D* CAT2DRepHierarchyIterator::GetPositionMat () const
{
  return _PositionTransfo;
}

inline const CAT3x3Matrix* CAT2DRepHierarchyIterator::GetPositionMatrix () const
{
  return _PositionMatrix;
}

inline const CATGraphicAttributeSet* CAT2DRepHierarchyIterator::GetGraphicAttributeSet () const
{
  return _GraphicAttributes;
}

inline const CATGraphicMaterial* CAT2DRepHierarchyIterator::GetGraphicMaterial () const
{
  return _GraphicMaterial;
}

inline const int* CAT2DRepHierarchyIterator::GetAlpha () const
{
  return _Alpha;
}

#endif
