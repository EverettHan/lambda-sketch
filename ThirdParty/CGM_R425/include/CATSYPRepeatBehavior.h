// COPYRIGHT Dassault Systemes 2008
//===================================================================
//
// CATSYPRepeatBehavior.h
// Header definition of CATSYPRepeatBehavior
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Aug 2008  Creation: jov
//===================================================================
#ifndef CATSYPRepeatBehavior_H
#define CATSYPRepeatBehavior_H

#include <IntroInfra.h>
#include <CATBoolean.h>

/**
 * Descriptor class for repeat behaviors of animation timeline or groups of timelines.
 *
 * @par Use in sypstyle
 * Example of use in a sypstyle file :
 * <code>
 *   <CATSYPIntAnimation ... RepeatBehavior="Count=5"/>
 * </code>
 * or :
 * <code>
 *   <CATSYPIntAnimation ... RepeatBehavior="Forever"/>
 * </code>
 *
 * <b>Wiki article :</b>
 * <a href="http://codewiki/codewiki/index.php/New_V6_Animation_Infrastructure#Repeat_Behaviour"><b>CodeWiki -> Animations -> Repeat Behaviour</b></a>
 *
 * @ingroup groupCIDIntrospection
 */
class ExportedByIntroInfra CATSYPRepeatBehavior
{
public:
  /**
  * Standard constructor
  */
  CATSYPRepeatBehavior ();
  /**
  * Destructor.
  */
  virtual ~CATSYPRepeatBehavior ();
  /**
  * Copy constructor.
  */
  CATSYPRepeatBehavior (const CATSYPRepeatBehavior & i_repeatBehavior);
  /**
  * Equal operator
  */
  CATSYPRepeatBehavior& operator=(const CATSYPRepeatBehavior& i_repeatBehavior);
  /**
   * Equality operator
   */
  CATBoolean operator==(const CATSYPRepeatBehavior& i_repeatBehavior) const;
  /**
  * Sets whether the animation cycles forever.
  * @param i_foreverFlag TRUE or FALSE
  */
  void SetForeverFlag (CATBoolean i_foreverFlag);
  /**
  * @return whether the animation cycles forever.
  * @see SetForeverFlag
  */
  CATBoolean GetForeverFlag ()const;
  /**
  * @param i_count the number of times the animation will cycle.
  */
  void SetCount (unsigned int i_count);
  /**
  * @return the number of times the animation will cycle.
  * @see SetCount
  */
  unsigned int GetCount ()const;
  /**
  * @return whether the repeat count has been defined.
  * @see SetCount
  */
  CATBoolean GetHasCountFlag() const;

private:
  CATBoolean _foreverFlag;
  unsigned int _count;
};
//-----------------------------------------------------------------------

#endif
