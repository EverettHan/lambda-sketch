/* -*-c++-*- */
#ifndef CAT3DFixedPlanGP_H
#define CAT3DFixedPlanGP_H

// COPYRIGHT DASSAULT SYSTEMES 2000

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATDynamicGP.h"
#include "CATMathPointf.h"
#include "CATMathDirectionf.h"

class CATStreamer;

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
class ExportedBySGInfra CAT3DFixedPlanGP : public CATDynamicGP
{
  // macros
  friend class CATMarshallable3DFixedPlaneGP;
  friend class SGCGRStreamerFor3DFixedPlanGP;
  friend class SGCGRNodesFactoryA;
  CATDeclareClass;

public:
  /**
   * Default constructor
   */
  CAT3DFixedPlanGP();

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
  CAT3DFixedPlanGP(const CATMathPointf     iOrigin,
                   const CATMathDirectionf iDirection1,
                   const CATMathDirectionf iDirection2,
                   const float             iLengthInMM);

  /**
   * @nodoc
   */
  virtual void Stream   (CATStreamer & oStream, int iSaveType = 0);

  /**
   * @nodoc
   */
  virtual void UnStream (CATStreamer & iStream);

#ifdef CATIAR426
  /** @nodoc */
  virtual void Draw(CATRender& iRender) override final;

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
                             const CATViewport  * iViewport) override final;
#else
  virtual void ImmediateDraw(CATRender& iRender,
    const CATViewpoint* iViewpoint,
    const CATViewport* iViewport);
#endif

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
           CATMathDirectionf & oDirection2);

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
  
  /**
  * @nodoc
  */
  virtual CATVizPrimitive * GetVizPrimitive(int &oAllocateMode);
  
  /**
  * @nodoc
  */
  virtual void SetVizPrimitive(CATVizPrimitive * iPrimitive, int iAllocateMode);

protected :
  virtual ~CAT3DFixedPlanGP();

private :
  int                  _mode;        // visualization mode
  CATMathPointf        _ori;         // origin
  CATMathDirectionf    _direction1;  // first direction
  CATMathDirectionf    _direction2;  // second direction
  float                _fixedLength; // dimension of gp
};

inline void CAT3DFixedPlanGP::SetVisuMode(const int iVisuMode)
{
  _mode = iVisuMode;
}

inline int  CAT3DFixedPlanGP::GetVisuMode() const
{
  return _mode;
}

inline void CAT3DFixedPlanGP::SetLengthInMM(const int iLengthInMM)
{
   _fixedLength = (float) iLengthInMM;
}

#endif // CAT3DFixedPlanGP_H
