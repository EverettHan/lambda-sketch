/* -*-c++-*- */
#ifndef CATViz3DFixedPlan_H
#define CATViz3DFixedPlan_H

// COPYRIGHT DASSAULT SYSTEMES 2004

#include "CATVizDynamicPrimitive.h"
#include "CATMathPointf.h"
#include "CATMathDirectionf.h"
#include "CATVisMacroForInterfaces.h"

class CATStreamer;

class IVisSG3DPrimitive;
class CATViz3DFixedPlanIVisSG3DPrimitiveBOAImpl;

/**
 * @nodoc 
 * The graphic primitive is a full square
 */
#define FULL_SQUARE_PLANE 0

/**
 * @nodoc 
 * The graphic primitive is an 'L'
 */
#define HALF_SQUARE_PLANE 1


#include "SGInfra.h"

/**
 * Class to create the graphic primitive of a 3D fixed plan.
 * <b>Role</b>: Graphic primitive to display a 3D square which size
 * remains constant on the screen (i.e, does not change with zoom, etc..)
 */
class ExportedBySGInfra CATViz3DFixedPlan : public CATVizDynamicPrimitive
{

public:

  CATVisDeclarePublicInterfaceAdhesion(CATViz3DFixedPlan, IVisSG3DPrimitive, CATViz3DFixedPlanIVisSG3DPrimitiveBOAImpl);

  /**
   * Default constructor
   */
  CATViz3DFixedPlan();

  /**
   * Constructs a 3D fixed plan from an origin, two directions,
   * and a lenght expressed in millimeters.
   * <pre>
   *
   *                         -----------------------------      ^
   *                        |                             |     |
   *                        |          iDirection1        |     |     
   *                        |              ^              |     |
   *                        |              |              |     |
   *                        |              |  iDirection2 |     |
   *                        |              x --->         |     | iLenghtInMM
   *                        |           iOrigin           |     |
   *                        |                             |     |
   *                        |                             |     |
   *                        |                             |     |
   *                        |                             |     |
   *                        |                             |     |
   *                         -----------------------------      v
   *
   *                         <--------------------------->
   *                                  iLenghtInMM
   *       
   *
   * </pre>
   * @param iOrigin
   *   The square center. 
   * @param iDirection1
   *   The first direction which
   *   is parallel to two of the edges.
   * @param iDirection2
   *   The second direction which is parallel
   *   to the two other edges.
   * @param iLengthInMM
   *   The square length expressed in millimeters.
   */
  CATViz3DFixedPlan(const CATMathPointf     iOrigin,
                   const CATMathDirectionf iDirection1,
                   const CATMathDirectionf iDirection2,
                   const float             iLengthInMM,
                   const int               mode = FULL_SQUARE_PLANE);

  /** @nodoc */
  CATViz3DFixedPlan(const CATViz3DFixedPlan & toCopy);

  /** @nodoc */
  virtual CATVizPrimitive * Duplicate();

  /**
   * @nodoc
   */
  virtual void Stream   (CATStreamer & oStream, int iSaveType = 0);
  INLINE virtual unsigned char GetStreamId() const;

  /**
   * @nodoc
   */
  virtual void UnStream (CATStreamer & iStream);

  /**
   * Draws the 3D fixed plan.
   * @param iRender
   *   The render through which the plan is drawn.
   * @param iViewpoint
   *   The viewpoint through which the plan is seen.
   * @param iViewport
   *   The viewport in which the plan is located.
   */
  virtual void ImmediateDraw(CATRender          & iRender,
                             const CATViewpoint * iViewpoint,
                             const CATViewport  * iViewport);   

  /**
   * Retrieves the 3D fixed plan parameters.
   * @param oOrigin
   *   The center of the square.
   * @param oDirection1
   *   The first square direction. (Direction
   *   parallel to two of the square edges)
   * @param oDirection2
   *   The second square direction. (Direction
   *   parallel to the two other edges)
   */
  void Get(CATMathPointf     & oOrigin,
           CATMathDirectionf & oDirection1,
           CATMathDirectionf & oDirection2,
           int   &oMode,
           float &oLenthInMM);

  /** @nodoc */
  inline void SetVisuMode(const int iVisuMode);

  /** @nodoc */
  inline int  GetVisuMode() const;
    
  /** @nodoc */
  inline void SetLengthInMM(const int iLengthInMM);
    
  /**
   * @nodoc
   */
  virtual int DetailCulling(CATRender *render);

  CATVizDeclareTinyRefCount(7); // 7 bits refCount

protected :

  /** @nodoc */
  virtual ~CATViz3DFixedPlan();

private :
  unsigned int         _mode : 1;   // visualization mode
  //----- 7 bits reserved for RefCount
  CATMathPointf        _ori;         // origin
  CATMathDirectionf    _direction1;  // first direction
  CATMathDirectionf    _direction2;  // second direction
  float                _fixedLength; // dimension of gp
};

inline void CATViz3DFixedPlan::SetVisuMode(const int iVisuMode)
{
  _mode = static_cast<unsigned int>(iVisuMode);
}

inline int  CATViz3DFixedPlan::GetVisuMode() const
{
  return static_cast<int>(_mode);
}

inline void CATViz3DFixedPlan::SetLengthInMM(const int iLengthInMM)
{
   _fixedLength = static_cast<float>(iLengthInMM);
}

INLINE unsigned char CATViz3DFixedPlan::GetStreamId() const
{
	return VIZFIXEDPLAN;
}

#endif // CATViz3DFixedPlan_H
