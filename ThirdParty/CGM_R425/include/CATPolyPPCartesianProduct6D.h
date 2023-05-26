// COPYRIGHT DASSAULT SYSTEMES 2017, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPPCartesianProduct6D.h
//
//===================================================================
//
// Usage notes: Specializes cartesian product for 6D space
//
//===================================================================
//
// 2017-02-06 JXO: Creation
//===================================================================

#ifndef CATPolyPPCartesianProduct6D_HH
#define CATPolyPPCartesianProduct6D_HH

#if 0

#include "PolyPathPlanning.h"
#include "CATPolyPPCartesianProduct.h"

class CATPolyPPTopologicalSpaceR3;
class CATPolyPPTopologicalSpaceSO3;
class CATPolyConcentricIterator;

/** 
 *
 */
class ExportedByPolyPathPlanning CATPolyPPCartesianProduct6D : public CATPolyPPCartesianProduct
{
public:
  CATPolyPPCartesianProduct6D(CATListPV & iListOfTopoSpaces, CATPolyPPTopologicalSpaceR3 & iR3, CATPolyPPTopologicalSpaceSO3 & iSO3, CATPolyPPConfigurationDistance * pDistance);

  /**
   * Get a random position in the sphere crust from a given reference, for the uniform random extractor
   * @param iRotationMode
   *        0.  no rotation
   *        0.5 share rotation with translation
   *        1.  expand rotation from translation
   */
  virtual CATPolyPPPosition * GetRandomPosition(CATPolyPPPosition * iRef, double iMinimumRadius, double iMaximumRadius, CATPolyConcentricIterator* Iterator, double iRotationMode) const;
  /**
   * Get a random position on a sphere of radius  from a given reference, for the uniform random extractor
   * @param iRotationMode
   *        0.  no rotation
   *        0.5 share rotation with translation
   *        1.  expand rotation from translation
   */
  virtual CATPolyPPPosition * GetPosition(CATPolyPPPosition  * iRef, double iRadius, CATPolyConcentricIterator* Iterator, double iRotationMode) const;

  INLINE void SetMaximumRadius(double iRadiusMaxX, double iRadiusMaxY, double iRadiusMaxZ)
  {
    m_RadiusMaxX = iRadiusMaxX;
    m_RadiusMaxY = iRadiusMaxY;
    m_RadiusMaxZ = iRadiusMaxZ;
    m_jEquiX = CATSqrt(m_RadiusMaxZ*m_RadiusMaxZ+m_RadiusMaxY*m_RadiusMaxY);
    m_jEquiY = CATSqrt(m_RadiusMaxZ*m_RadiusMaxZ+m_RadiusMaxX*m_RadiusMaxX);
    m_jEquiZ = CATSqrt(m_RadiusMaxX*m_RadiusMaxX+m_RadiusMaxY*m_RadiusMaxY);
  }
protected:
  virtual ~CATPolyPPCartesianProduct6D();
  CATPolyPPTopologicalSpaceR3 & m_R3;
  CATPolyPPTopologicalSpaceSO3 & m_SO3;
  double m_RadiusMaxX;
  double m_RadiusMaxY;
  double m_RadiusMaxZ;
  // Necessary for uniform extraction
  double m_jEquiX;
  double m_jEquiY;
  double m_jEquiZ;
};

#endif
#endif
