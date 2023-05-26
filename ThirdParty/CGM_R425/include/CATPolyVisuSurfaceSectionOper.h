// COPYRIGHT DASSAULT SYSTEMES 2016, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyVisuSurfaceSectionOper.h
//
//===================================================================
// March 2016  Creation: JXO
//===================================================================
#ifndef CATPolyVisuSurfaceSectionOper_H
#define CATPolyVisuSurfaceSectionOper_H

#include "PolyVisuClash.h"

// Poly math
#include "CATMapOfPtrToPtr.h"
#include "CATPolyExactArithmetic.h"
#include "CATPolyVisuBVHTreeSet.h"

// System
#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "CATIAV5Level.h"


class CAT3DRep;
class CATBVHNodeConst;
class CATPolyBody;
class CATMathPlane;
class CATPolyVisuSurfaceSectionObserver;
class CATMathTransformation;
class CATPolyBoundingVolume;
class CATBVHTreeSetObserverForSurfaceSection;
class CATPolyVisuSurfaceSectionResult;
class CATTolerance;


/**
 * This operator calculates a surface section of a rep given its spatial hierarchy (CATBVHTreeSet) and 
 * returns the result in the form of an observer.
 */
class ExportedByPolyVisuClash CATPolyVisuSurfaceSectionOper
{
public:
  /**
   * Constructs a surface section operator given an operand consisting of
   * <ul>
   *   <li> The BVH tree set associated to a set of reps and positions.
   * </ul>
   */
  CATPolyVisuSurfaceSectionOper (CATBVHTreeSet& iBVHTreeSet, const CATTolerance & itol);

  /** Destructor */
  ~CATPolyVisuSurfaceSectionOper ();

  /**
   * Computes a section of the rep (given its spatial hierarchy) instances by the cutting surface.
   * The result is given to the implementation of CATPolyVisuSurfaceSectionResult.
   */
  HRESULT Run(CAT3DRep & iCuttingSurface, CATPolyVisuSurfaceSectionResult & oResult, const CATMathTransformation * iCuttingSurfacePosition = 0);


  /**
   * Sets the number of threads for running the section in parallel.
   * By default, the operator is mono-thread.  
   * If the number of threads is set to -1, then the operator will determine 
   * an optimal number of threads automatically.
   */
  void SetNbThreads (const int iNbThreads);

  /**
   * Flushes any data the section operator has stored in the cache.
   */
  void Flush ();

private:

  CATPolyVisuSurfaceSectionObserver * m_Observer;

  CATBVHTreeSet & m_BVHTreeSet;
  CATBVHTreeSetObserverForSurfaceSection * m_BVHTreeSetObs;
  
  
  CAT3DRep * m_CuttingRep;
  CATPolyVisuBVHTreeSet m_SurfaceBVHTreeSet;
  CATBVHTreeSetObserverForSurfaceSection * m_SurfaceBVHTreeSetObs;
  CATMathTransformation * m_PositionMatrix;

  CATPolyExactArithmetic m_ExactArithmetic;

  // Mapping of nodes from the BVH tree to the section data.
  // (Toggle between the two maps.)
  CATMapOfPtrToPtr m_NodeToSectionData[2];

  int m_CurrentIndex;  // Index of the current map.

  unsigned int m_NbThreads;

  const double m_LargeEpsgForRelativeTest;
  const double m_LargeEpsgForLengthTest;

protected:

  inline const CATPolyExactArithmetic& GetExactArithmetic () const;

public:

  /**
   * Reserved for Phoenix capture.
   * Sets an observer with the operator.
   */
  inline void SetCaptureObserver (CATPolyVisuSurfaceSectionObserver* iObserver);

  /**
   * Reserved for Phoenix capture.
   * Returns the observer of the operator.
   */
  inline CATPolyVisuSurfaceSectionObserver* GetCaptureObserver () const;

};


inline const CATPolyExactArithmetic& CATPolyVisuSurfaceSectionOper::GetExactArithmetic () const
{
  return m_ExactArithmetic;
}

inline void CATPolyVisuSurfaceSectionOper::SetCaptureObserver (CATPolyVisuSurfaceSectionObserver* iObserver)
{
  m_Observer = iObserver;
}

inline CATPolyVisuSurfaceSectionObserver* CATPolyVisuSurfaceSectionOper::GetCaptureObserver () const
{
  return m_Observer;
}

#endif
