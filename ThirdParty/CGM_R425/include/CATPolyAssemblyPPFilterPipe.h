// COPYRIGHT DASSAULT SYSTEMES 2014, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyAssemblyPPFilterPipe.h
//
//===================================================================
//
// Usage notes: In the context of the nD Path Planning solver, filter
// that restrains the scope of valid configurations into a pipe
// defined by a radius and a polyline as a list of points.
//
//===================================================================
//
// 2014-11-14 XXC: Creation
//===================================================================

#ifndef CATPolyAssemblyPPFilterPipe_HH
#define CATPolyAssemblyPPFilterPipe_HH

#include "PolyBodyBVHOperators.h"

class CATMathTranformation;

// Math
#include "CATBoolean.h"
#include "CATMathPoint.h"
#include "CATPolyPPConfigurationFilter.h"

//std
#include <vector>

/** Class defining the Configuration Filter interface for Pipe shaped
 *  filter. Allows to restrain the scope of valid configurations
 *  inside a pipe defined by a radius and a polyline.
 */
class ExportedByPolyBodyBVHOperators CATPolyAssemblyPPFilterPipe : public CATPolyPPConfigurationFilter
{
public:
  CATPolyAssemblyPPFilterPipe(const CATMathPoint& iAnchor, double iRadius);

  CATPolyAssemblyPPFilterPipe(const CATPolyAssemblyPPFilterPipe& iOther);

  virtual ~CATPolyAssemblyPPFilterPipe() {}

  void AppendPoint(const CATMathPoint& iPoint);
  int GetNbPoint() const;
  CATMathPoint GetPoint(int i) const ;
  double GetRadius() const;
  CATMathPoint GetAnchor()const;

  virtual CATBoolean Filter(const CATMathTransformation& iPosition);

  /**
  *	@todo TO BE CHANGED INTO VIRTUAL PURE
  */
  virtual CATPolyAssemblyPPFilterPipe* Clone() const;

  /**
   *  @brief set the current valid segment 
   *  @param iSegment the segment index (all other segment will be ignore )
   *
   *  @remarks set to -1 => look all segment, SetLookBackSearch can be used to look into previous segment
   */
  virtual void SetGuidingSegment(const int iSegment);


  /**
   * @brief set the distance max from the start point of current segment that will not be filter
   * 
   * a point will be filter if the path lenght from the position to test to the current segment start point is >=  iMaxDistLookDistance
   * 
   * the path lenght is the sum of :
   *  - the distance from the current position to the end of this segment 
   *  - the lenght of the intermediate segment
   * 
   *  @param[in] iMaxDistLookDistance the max distance allowed (if negative  or 0 no max distance )
   */
  void SetLookBackDistanceMax(const double iMaxDistLookDistance = -1);
  double GetLookBackDistanceMax() const;

    FilterTypeEnum GetType() const override;

private:
  CATMathPoint _Anchor;

  double _SqRadius;
  std::vector<CATMathPoint> _Polyline;
  std::vector<double> _SegmentLength; //< precompute lenght of segment
  double _PathLengh = 0;              //< precompute lenght of all segment
  int m_GuidingSegment;
  
  double _lookBackDistance = 0;
};

#endif
