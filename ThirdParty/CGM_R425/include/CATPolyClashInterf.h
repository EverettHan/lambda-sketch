// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyClashInterf.h
//
//===================================================================
//
// Usage notes:
// Interface describing a clash.
//
//===================================================================
//
// Jul 2009 Creation: JS9
// Dec 2013 Modif   : JXO, caching curve iterator
// Aug 2016 Modif   : JXO, GetIntersectionVolume, GetIntersectionCenterOfGravity, GetIntersection
//===================================================================

#ifndef CATPolyClashInterf_h
#define CATPolyClashInterf_h

#include "CATPolyBoundingVolumeOperators.h"

// Polyhedral
class CATIPolyCurveIterator;
class CATIPolyMesh;

// Interference
#include "CATPolyInterferenceImpl.h"

// Math
#include "CATMathPoint.h"
#include "CATLISTV_CATMathPoint.h"

// System
#include "CATBoolean.h"

//#define CATPOLYCLASHINTERF_DEBUG

/**
 * Interface describing a clash.
 */
class ExportedByCATPolyBoundingVolumeOperators CATPolyClashInterf : public CATPolyInterferenceImpl
{
public:

  /**
   * Constructor and destructor
   */
  CATPolyClashInterf(int firstObjId, int secondObjId,
                     double firstObjectAccuracy, double secondObjectAccuracy);
  virtual ~CATPolyClashInterf();

  /**
   * Get the type of interference. Might be used to cast the interference to its actual
   * implementing class.
   */
  virtual InterferenceType GetInterferenceType() const;

  /**
   * Add an intersection segment into the interference
   */
  void AddIntersectionSegment(const CATMathPoint & start, const CATMathPoint & end);

  /**
   * Get the intersection curves.
   * @return Iterator on the intersections curves (CATIPolyCurve).
   * A new iterator is created each time the function is called.
   * It must be deleted afterwards.
   */
  CATIPolyCurveIterator * GetIntersectionCurve();

  /**
   * Direct iterator on the segment of the intersection curve.
   */
  class ExportedByCATPolyBoundingVolumeOperators SegmentIterator
  {
  public:

    SegmentIterator(const CATPolyClashInterf & interf);
    SegmentIterator(const SegmentIterator & copy);
    ~SegmentIterator();

    void Begin();
    void operator++();
    CATBoolean End() const;

    void GetSegment(CATMathPoint & start, CATMathPoint & end) const;
  private:
    const CATPolyClashInterf & _rIteratedInterf;
    int _iCurSegment;
  };

  friend class SegmentIterator;

  /**
   * Get an iterator on the intersection segments.
   */
  SegmentIterator GetSegmentIterator() const;

  /**
   * List of different cases of inclusion.
   */
  enum InclusionStatus
  {
    NONE = 0,
    OBJECT1_IN_OBJECT2 = 1,
    OBJECT2_IN_OBJECT1 = 2
  };

  /**
   * Set whether the clash is caused by an inclusion
   * or a surfacic clash.
   */
  void SetIsInclusionClash(InclusionStatus isInclusion);

  /**
   * To know whether the clash is due to an inclusion
   * or because surfaces intersect.
   * @return NONE if there is no inclusion between the two object, the surfaces of both objects intersects.
   *         OBJECT1_IN_OBJECT2 if the first object is included in the second.
   *         OBJECT2_IN_OBJECT1 if the second object is included in the first.
   */
  InclusionStatus IsInclusion() const;

  /**
   * To know whether the clash is due to an inclusion
   * or because surfaces intersect.
   */
  CATBoolean IsInclusionClash();

  /**
   * Get Penetration values
   */
  void GetPenetrationData(double &oDepthPenetrationValue,double oDepthPenetrationVector[3],double oGravityCenter[3]);

  /**
   * Enum describing the direction of the penetration vector.
   * It might give either the direction to remove the obejct from the second or the second from the first.
   */
  enum DepthPenetrationDirection
  {
    REMOVE_OBJECT1_FROM_OBJECT2 = 0,
    REMOVE_OBJECT2_FROM_OBJECT1
  };

  /**
   * Set Penetration values
   */
  void SetPenetrationData(double iDepthPenetrationValue,
                          double iDepthPenetrationVector[3],
                          double iGravityCenter[3],
                          DepthPenetrationDirection direction);

  /**
   * To know whether the penetration vector gives the direction that must be applied to first object
   * to remove it from the second or to remove the second from the first.
   * Knowing one of the direction, the other one can be obtained by reversing the penetration vector.
   * @return SEPARATE_OBJECT1_FROM_OBJECT2 for the first case, SEPARATE_OBJECT2_FROM_OBJECT1
   *         for the second case.
   */
  DepthPenetrationDirection GetDepthPenetrationDirection() const;

  /** 
   * In case ComputeIntersectionVolumes has been activated on the operator, returns the computed 
   * volume of the intersection.
   * @return a negative value if the volume could not be computed.
   */
  double GetIntersectionVolume() const;

  /**
   * In case ComputeIntersectionVolumes has been activated on the operator, returns the computed 
   * center of gravity of the intersection volume.
   * The positioning of this point is in the absolute referential.
   */
  const CATMathPoint & GetIntersectionCenterOfGravity() const;

  /** 
   * In case ComputeIntersectionVolumes has been activated on the operator, returns the computed 
   * intersection volume, as a result of a boolean intersection of the watertight solid operands.
   * The positioning of this mesh is in the absolute referential.
   * @return to be released by caller after use.
   */
  CATIPolyMesh * GetIntersection() const;


  /**
   * Swap the data of the two interfering objects.
   * First object id become second object id, accuracy are inverted and
   * so are the associated data.
   */
  virtual void SwapInterferingObjects();

  /**
   * Remove all previously added intersection curves.
   */
  void RemoveIntersectionCurves();

  /** This interference takes ownership of the iterator. */
  void SetCurveIterator(CATIPolyCurveIterator * iCurveIterator);

  /** This interference addrefs iMesh and will release it in destructor */
  void SetIntersection(CATIPolyMesh * iMesh);

private:
  CATIPolyCurveIterator * GetIntersectionCurvePrivate();
private:

  //--------------------------------------------------------
  CATLISTV(CATMathPoint) _oSegmentList;
  InclusionStatus _eIsInclusion;

  /**
   * Depth penetration values.
   */
  double _DepthPenetrationValue;
  double _DepthPenetrationVector[3];
  double _GravityCenter[3];
  DepthPenetrationDirection _DPDirection;
  CATIPolyCurveIterator * m_curves;

  double m_volume;
  CATMathPoint m_center;
  CATIPolyMesh * m_intersection;

  //--------------------------------------------------------
#ifdef CATPOLYCLASHINTERF_DEBUG
  static int s_iClashInterfsize;
#endif
};

#endif // CATPolyClashInterf_h

