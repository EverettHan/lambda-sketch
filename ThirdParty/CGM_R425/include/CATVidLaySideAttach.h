#ifndef CATVidLaySideAttach_h
#define CATVidLaySideAttach_h

// COPYRIGHT Dassault Systemes 2005

#include "VisuDialog.h"
#include "CATVidLayCollection.h"
#include "CATVidLaySideAttachConstraints.h"
#include "CATMathPoint2Df.h"
#include "CATBoolean.h"

class CATVidTabPage;
class CAT3DCustomRep;
class CAT3DPointRep;
class CATVidRectangle;


/**
 * This class defines a layout that allows to lace controls with pixel or percent positionning
 * 
 * @par In CAPSYPStyle files
 * @code
 * <CATVidLaySideAttach ...........>
 *   <MyWidgetA ........... CATVidLaySideAttach.IndexedConstraints="..." />
 *   <MyWidgetB ........... CATVidLaySideAttach.IndexedConstraints="..." />
 *   ....
 * </CATVidLaySideAttach>
 * @endcode
 * IndexedConstraints is a CATVidLaySideAttachConstraints.
 *
 *
 * @see CATVidLaySideAttachConstraints
 * @see CATVidLayCollection
 * @see CATISYPCollection
 * @ingroup VIDLayout
 */
class ExportedByVisuDialog CATVidLaySideAttach : public CATVidLayCollection
{
  CATDeclareClass;

public:
  // Standard constructor
  // --------------------
  CATVidLaySideAttach();
  CATVidLaySideAttach(CATCommand *i_pParent, const CATString & i_pIdentifier);

  /**
   * Retrieves the side attach constraints associated to the given widget.
   * @return 1 if the constraints have been found for the given widget, 0 otherwise.
   */
  int GetConstraints(const CATVidWidget* i_pWidget, CATVidLaySideAttachConstraints& o_constraints) const;

  /**
   * Specifies the restricted area used by the layout. 
   * This area limits the position of the embedded widgets whose CATVidLayConstraints has 
   * the property UseRestrictedAreaFlag set to TRUE.
   *
   * @see CATVidLayConstraints::SetUseRestrictedAreaFlag
   * @param i_restrictedArea
   * The area, in coordinates relative to the CATVidLaySideAttach, that limits the position of the constrained embedded widgets.
   */
  void SetRestrictedArea(const CATVidRectangle & i_restrictedArea);
  const CATVidRectangle& GetRestrictedArea() const;

  /**
   * Specifies whether the minimum dimension of the children must be ignored for 
   * the computing of the collection minimum dimension (in which case this minimum dimension
   * is always null), or not.
   * By default, the IgnoreChildrenMinimumDimensionFlag is set to TRUE.
   */
  void SetIgnoreChildrenMinimumDimensionFlag(CATBoolean i_ignoreFlag);

  /**
   * Returns TRUE if the minimum dimension of the children must be ignored for 
   * the computing of the collection minimum dimension (in which case this minimum dimension
   * is always null), FALSE otherwise.
   * By default, the IgnoreChildrenMinimumDimensionFlag is set to TRUE.
   */
  CATBoolean GetIgnoreChildrenMinimumDimensionFlag() const;

  /**
   * @param a position or dimension in physical pixels
   *
   * @return the corresponding position or dimension in the 
   * @c CATVidLaySideAttach density-independant space, ie. the input divided by 
   * the density of the @ CATVidLaySideAttach.
   */
  CATMathPoint2Df PhysicalPixelsToLayoutDensityPixels(const CATMathPoint2Df & i_pos) const;
  /**
   * Allow to clip content to the dimension of the layout. This will avoid issue where a content 
   * is outside of the bounds of the layout, visible, but not pickable.
   */
  void SetAllowClippingFlag(int i_clippingFlag);
  /** @return the allowClippingFlag*/
  int GetAllowClippingFlag() const;

protected:
  virtual ~CATVidLaySideAttach ();
  // Copy constructor and equal operator
  // -----------------------------------
  CATVidLaySideAttach (CATVidLaySideAttach &);
  CATVidLaySideAttach& operator=(CATVidLaySideAttach&);

  virtual void Layout();
  virtual void UpdateComputedMinimumDimension();
  virtual CATVidLayConstraints* CreateConstraints();
  /** @deprecated The order of the draw of the children is now the same than the order of children in the collection*/
  void SetKeepOrderFlag(CATBoolean i_keepOrderFlag);
};

#endif // CATVidLaySideAttach_h
