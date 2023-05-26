#ifndef CATVidLay2DSyncToViewpointConstraints_h
#define CATVidLay2DSyncToViewpointConstraints_h

// COPYRIGHT Dassault Systemes 2011

// Local framework
#include "VisuDialog.h"
#include "CATVidLayConstraints.h"
#include "CATBoolean.h"
#include "CATMathPointf.h"
#include "CATMathPoint2Df.h"

class CATViewpoint;

/**
 * Constraints used to specify the attachment properties of a Label window.
 * @see CATVidFraLabel
 * @ingroup VIDLayout
 */
class ExportedByVisuDialog CATVidLay2DSyncToViewpointConstraints : public CATVidLayConstraints
{
  CATDeclareClass;

public:

  // Standard constructors and destructors
  CATVidLay2DSyncToViewpointConstraints();
  virtual ~CATVidLay2DSyncToViewpointConstraints();

  virtual CATBoolean IsEqualTo(const CATVidLayConstraints& i_constraints) const;

  /**
   * Copy the given constraints values.
   */
  virtual void CopyFrom(const CATVidLayConstraints& i_constraints);

  // Copy constructor and equal operator
  CATVidLay2DSyncToViewpointConstraints(const CATVidLay2DSyncToViewpointConstraints & i_original);
  const CATVidLay2DSyncToViewpointConstraints& operator=(const CATVidLay2DSyncToViewpointConstraints& i_original);

  /**
   * Sets the anchor point, that is a 3D point (Z=0 for 2D point) used to link the specified 
   * viewpoint and the window, in dp (device independant pixels = pixels divided by density). 
   * @see SetSpecifiedViewpoint
   */
  void SetAnchorPoint(const CATMathPointf& i_anchorPoint);
  const CATMathPointf& GetAnchorPoint() const;

  /**
   * Sets the link offset, that is the 2D offset starting from the window position to its anchor point.
   * This offset is used to initially display the window at the desired position.
   * For example, if you want to display your window on the bottom right of its anchor point, you can 
   * write the following line :
   * @code
   * constraints.SetConnectionPoint(CATMathPoint2Df(-100.0f, -100.0f));
   * @endcode
   *
   * This offset is in dp (device independant pixels = pixels divided
   * by density). 
   *
   * @see SetAnchorPoint
   */
  void SetConnectionPoint(const CATMathPoint2Df& i_connectionPoint);
  const CATMathPoint2Df& GetConnectionPoint() const;

  /**
   * Sets the viewpoint (2D or 3D) corresponding to the anchor point.
   * If not scpecified, or if NULL, the main viewpoint will be used.
   * @see SetAnchorPoint
   */
  void SetSpecifiedViewpoint(CATViewpoint* i_pSpecificViewpoint);
  CATViewpoint * GetSpecifiedViewpoint() const;

  virtual CATVidLayConstraints* Clone() const; 

private:

  CATMathPointf _anchorPoint;
  CATMathPoint2Df _connectionPoint;
  CATViewpoint* _pSpecificViewpoint;
};

#endif // CATVidLay2DSyncToViewpointConstraints_h
