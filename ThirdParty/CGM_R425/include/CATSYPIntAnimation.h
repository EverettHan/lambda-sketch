// COPYRIGHT Dassault Systemes 2008
//===================================================================
//
// CATSYPIntAnimation.h
// Header definition of CATSYPIntAnimation
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Aug 2008  Creation: jov
//===================================================================
#ifndef CATSYPIntAnimation_H
#define CATSYPIntAnimation_H

#include <IntroInfra.h>
#include <CATSYPAnimationTimeline.h>


//----------------------------------------------------------------
// Class CATSYPIntAnimation             
//----------------------------------------------------------------
/**
 * Animation class for integers.
 * C++ code example :
 * @code
 * // int animation example
 * CATSYPIntAnimation* pIntAnimation = new CATSYPIntAnimation();
 * pIntAnimation->SetDuration(CATSYPDuration(20.0f));
 * pIntAnimation->SetBeginTime(CATSYPDuration(0.0f));
 * pIntAnimation->SetFrom_int(0);
 * pIntAnimation->SetTo_int(1000);
 * @endcode
 *
 * @c CATSYPStyle example :
 * @code
 * <CATSYPIntAnimation Duration="0:0:0.2" From="0" To="20"/>
 * @endcode
 *
 * This animation can then be appended to a @c CATSYPStoryboard.
 *
 * <b>Wiki article :</b>
 * <a href="http://codewiki/codewiki/index.php/New_V6_Animation_Infrastructure#Animate_a_variable"><b>CodeWiki -> Animations -> Animate a variable</b></a>
 *
 * @see CATSYPStoryboard
 * @see CATSYPAnimationTimeline
 * @ingroup groupCIDIntrospection
 * @htmlinclude CATSYPIntAnimation.sypintro.html
 */
class ExportedByIntroInfra CATSYPIntAnimation: public CATSYPAnimationTimeline
{
  CATDeclareClass;

public:
  /**
  * Standard constructor.
  */
  CATSYPIntAnimation ();
  /**
  * Allows to specify the "From" value as an int.
  * @param i_from the "From" value as an int.
  */
  void SetFrom_int (int i_from);
  /**
  * @return the "From" value as an int.
  */
  int GetFrom_int () const;
  /**
  * Allows to specify the "To" value as an int.
  * @param i_to the "To" value as an int.
  */
  void SetTo_int (int i_to);
  /**
  * @return the "To" value as an int.
  */
  int GetTo_int () const;
  /**
  * @return the current value as an int.
  */
  int GetCurrentValue_int () const;
protected:
  /** @copydoc CATSYPTimeline::~CATSYPTimeline */
  virtual ~CATSYPIntAnimation ();
  /**
  * Copy constructor
  */
  CATSYPIntAnimation (CATSYPIntAnimation &);
  /**
  * Equal operator
  */
  CATSYPIntAnimation& operator=(CATSYPIntAnimation&);
  /**
  * @copydoc CATSYPAnimationTimeline::UpdateCurrentValue
  */
  void UpdateCurrentValue();
};
//-----------------------------------------------------------------------

#endif
