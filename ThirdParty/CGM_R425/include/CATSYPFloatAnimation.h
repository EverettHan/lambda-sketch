// COPYRIGHT Dassault Systemes 2008
//===================================================================
//
// CATSYPFloatAnimation.h
// Header definition of CATSYPFloatAnimation
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Aug 2008  Creation: jov
//===================================================================
#ifndef CATSYPFloatAnimation_H
#define CATSYPFloatAnimation_H

#include <IntroInfra.h>
#include <CATSYPAnimationTimeline.h>


//----------------------------------------------------------------
// Class CATSYPFloatAnimation             
//----------------------------------------------------------------
/**
 * Animation class for floats.
 * C++ code example :
 * @code
 * // float animation example
 * CATSYPFloatAnimation* pFloatAnimation = new CATSYPFloatAnimation();
 * pFloatAnimation->SetDuration(CATSYPDuration(20.0f));
 * pFloatAnimation->SetBeginTime(CATSYPDuration(0.0f));
 * pFloatAnimation->SetFrom("0.8");
 * pFloatAnimation->SetTo("15.5");
 * @endcode
 * This animation can then be appended to a @c CATSYPStoryboard.
 * @c CATSYPStyle example :
 * @code
 * <CATSYPFloatAnimation Duration="0:0:0.2" From="0" To="20"/>
 * @endcode
 *
 * <b>Wiki article :</b>
 * <a href="http://codewiki/codewiki/index.php/New_V6_Animation_Infrastructure#Animate_a_variable"><b>CodeWiki -> Animations -> Animate a variable</b></a>
 *
 * @see CATSYPStoryboard
 * @see CATSYPAnimationTimeline
 * @see <a href="http://codewiki/codewiki/index.php/New_V6_Animation_Infrastructure"><b>CodeWiki -> Animations</b></a>
 * @ingroup groupCIDIntrospection
 */
class ExportedByIntroInfra CATSYPFloatAnimation: public CATSYPAnimationTimeline
{
  CATDeclareClass;

public:
  /**
  * Standard constructor.
  */
  CATSYPFloatAnimation();
 /**
  * Allows to specify the "From" value as a float.
  * @param i_from the "From" value as a float.
  */
  void SetFrom_float(float i_from);
  /**
  * @return the "From" value as a float.
  */
 float GetFrom_float() const;
  /**
  * Allows to specify the "To" value as a float.
  * @param i_to the "To" value as a float.
  */
  void SetTo_float(float i_to);
  /**
  * @return the "To" value as a float.
  */
 float GetTo_float() const;
  /**
  * @return the current value as a float.
  */
 float GetCurrentValue_float() const;

protected:
  /** @copydoc CATSYPTimeline::~CATSYPTimeline */
  virtual ~CATSYPFloatAnimation ();
  /**
  * Copy constructor
  */
  CATSYPFloatAnimation (CATSYPFloatAnimation &);
  /**
  * Equal operator
  */
  CATSYPFloatAnimation& operator=(CATSYPFloatAnimation&);
  /**
  * @copydoc CATSYPAnimationTimeline::UpdateCurrentValue
  */
  void UpdateCurrentValue();
};
//-----------------------------------------------------------------------

#endif
