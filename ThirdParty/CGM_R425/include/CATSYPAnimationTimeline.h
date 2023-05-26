// COPYRIGHT Dassault Systemes 2008
//===================================================================
//
// CATSYPAnimationTimeline.h
// Header definition of CATSYPAnimationTimeline
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Aug 2008  Creation: jov
//===================================================================
#ifndef CATSYPAnimationTimeline_H
#define CATSYPAnimationTimeline_H

#include <IntroInfra.h>
#include <CATSYPTimeline.h>
#include <CATUnicodeString.h>
#include <CATBoolean.h>
#include <CATSYPEasingController.h>

//----------------------------------------------------------------
// Class CATSYPTimeline             
//----------------------------------------------------------------
/**
 * Base class for animations.
 * <b>Role</b>:
 * <p>Provides base function used by animations : ("From" value, "To" value, acceleration/deceleration, ...).<br/>
 * <b>An animation is a timeline that can make vary a variable "CurrentValue", from "From" value to "To" value</b>.<br/>
 * If the "From" value is not specified, then the current value of the introspected variable on the target object is used,
 * at the time the animation is initialized, and this value is then called <b>Initial Value</b>.
 * <br/><br/>
 * This class can't be used on its own, it has to be inherited for each type you want to animate.<br/>
 * You then have to redefine InitFromStrings() and UpdateCurrentValue() to fit your needs.<br/>
 * Basic types animation classes are provided  : int, float, CATVidColor, CATMathPoint2Df, ...
 * <br/><br/>
 * Each time the value is a CATBaseUnknown_var, it's because it is a boxing of the actual value (<a href="http://codewiki/codewiki/index.php/VID_:_Introspection#Boxing_in_CID"><b>Codewiki -> Introspection -> Boxing</b></a>).
 </p>
 *
 * <b>Wiki article :</b>
 * <a href="http://codewiki/codewiki/index.php/New_V6_Animation_Infrastructure"><b>CodeWiki -> Animations</b></a>
 *
 * @see CATSYPTimeline
 * @see CATSYPFloatAnimation
 * @see CATSYPIntAnimation
 * @see CATSYPStoryboard
 * @see <a href="http://codewiki/
 codewiki/index.php/VID_:_Introspection#Animable_type"><b>Codewiki -> Introspection -> Animable type</b></a>
 * @see <a href="http://codewiki/codewiki/index.php/New_V6_Animation_Infrastructure"><b>Codewiki -> Animations</b></a>
 * @ingroup groupCIDIntrospection
 */
class ExportedByIntroInfra CATSYPAnimationTimeline: public CATSYPTimeline
{
  CATDeclareClass;

public:
  /**
  * Standard constructor.
  */
  CATSYPAnimationTimeline ();
 /**
  * Sets the acceleration ratio.
  * The acceleration ratio is a float between 0 and 1, that manages the way the animation will accelerate at its beginning.<br/>
  * It is a ratio of the duration, for example an acceleration ratio of 0.3 will make the animation accelerate for the first 30% of its duration.<br/>
  * Default is 0 : the animation doesn't accelerate at its beginning.<br/>
  * @attention @c AccelerationRatio + @c DecelerationRatio mustn't exceed @c 1.
  * @param i_accelerationRatio the acceleration ratio, between 0 and 1.
  * @see <a href="http://codewiki/codewiki/index.php/New_V6_Animation_Infrastructure#Acceleration.2FDeceleration_Ratio"><b>CodeWiki -> Animations -> Acceleration</b></a>
  */
  void SetAccelerationRatio(float i_accelerationRatio);
  /**
  * @return the acceleration ratio, a float between 0 and 1.
  * @see SetAccelerationRatio
  */
  float GetAccelerationRatio () const;
  /**
  * Sets the deceleration ratio.
  * The deceleration ratio is a float between 0 and 1, that manages the way the animation will decelerate at its end.<br/>
  * It is a ratio of the duration, for example a deceleration ratio of 0.2 will make the animation decelerate for the last 20% of its duration.<br/>
  * Default is 0 : the animation doesn't decelerate at its end.<br/>
  * @attention @c AccelerationRatio + @c DecelerationRatio mustn't exceed @c 1.
  * @param i_decelerationRatio the deceleration ratio, between 0 and 1.
  * @see <a href="http://codewiki/codewiki/index.php/New_V6_Animation_Infrastructure#Acceleration.2FDeceleration_Ratio"><b>CodeWiki -> Animations -> Deceleration</b></a>
  * </p>
  */
  void SetDecelerationRatio(float i_decelerationRatio);
  /**
  * @return the deceleration ratio, a float between 0 and 1.
  * @see SetDecelerationRatio
  */
  float GetDecelerationRatio () const;
  /**
  * @return the current value as a CATBaseUnknown_var (at least, the last computed)
  * @see UpdateCurrentValue
  */
  const CATBaseUnknown_var & GetCurrentValue() const;
  /**
  * Internal, sets the initial value.
  * The initial value is retrieved when the user didn't specify a "From" value.
  */
  void SetInitialValue(const CATBaseUnknown_var &i_initialValue);
  /**
  * Returns whether the "From" value has been set by the user.
  * @return TRUE or FALSE.
  * @see CATSYPStoryboard::InitAnimations
  */
  CATBoolean GetFromValueSpecifiedFlag(){return _fromValueSpecifiedFlag;};
  /**
  * Sets the "From" value.
  * No default value.<br/>
  * @param i_spPropertyValue the "From" value.
  */
  void SetFromValue (const CATBaseUnknown_var &i_spPropertyValue);
  /**
  * @return the "From" value as a CATBaseUnknown_var
  */
  const CATBaseUnknown_var & GetFromValue() const;
  /**
  * Sets the "To" value.
  * No default value.<br/>
  * @param i_spPropertyValue the "To" value.
  */
  void SetToValue (const CATBaseUnknown_var &i_spPropertyValue);
  /**
  * Returns the "To" value as a CATBaseUnknown_var
  * @return the "To" value as a CATBaseUnknown_var
  */
  const CATBaseUnknown_var & GetToValue() const;
   /**
  * Sets the "Easing" value.
  * No default value.<br/>
  * @param i_spPropertyValue the "Easing" value.
  */
  void SetEasing(CATSYPEasingController::EasingMode i_easingMode);
   /**
  * @return the easing mode (BackIn, BounceOut for instance )
  * @see SetEasing
  */
  CATSYPEasingController::EasingMode  GetEasing () const;

   /**
  * Returns whether the "Easing" value has been set by the user.
  * @return TRUE or FALSE.
  * @see CATSYPStoryboard::InitAnimations
  */
  CATBoolean GetEasingValueSpecifiedFlag() { return _easingValueSpecifiedFlag;};

protected:
  /** @copydoc CATSYPTimeline::~CATSYPTimeline */
  virtual ~CATSYPAnimationTimeline ();
  /**
  * @copydoc CATSYPTimeline::CATSYPTimeline
  */
  CATSYPAnimationTimeline (CATSYPAnimationTimeline &);
  CATSYPAnimationTimeline& operator=(CATSYPAnimationTimeline&);
 /**
  * This function has to be called by the updateCurrentValue() of inheriting animation classes.
  * @param i_spPropertyValue the current value.
  */
  void SetCurrentValue (const CATBaseUnknown_var &i_spPropertyValue); 
  /**
  * deprecated, returns nothing
  */
  const CATBaseUnknown_var & GetInitialValue() const;
  /**
  * @copydoc CATSYPTimeline::UpdateCurrentValue
  * @see ComputeValueWithAccelelerationsAndLimits
  */
  virtual void UpdateCurrentValue() = 0;
  /**
  * Computes a float value between two float values, proportionally to the elapsed time.
  * When the animation is OnGoing, i.e. it has been started and the begin time is elapsed,
  * this function computes a float value between to float values, considering the time elapsed
  * and the duration of the animation.<br/>
  * This function uses internally two different functions depending on the mode used.<br/>
  * This mode could be the default one that uses a curve that takes into account an acceleration ratio and/or deceleration ratio or 
  * an "easing" mode that use an easing function (bounce, elastic...)<br/> 
  * This function has to be <b>called by inheriting animation classes</b>, in their implementation of UpdateCurrentValue, as many times as needed.<br/>
  * For example, the color animation classes could call it 4 times for computing each channel (red, green, blue, alpha).<br/>
  * @see ComputeValueWithAccelelerationsAndLimits
  * @see ComputeValueWithEasing
  */
  float ComputeValue(float i_vMin, float i_vMax); 
  /**
  * Computes a float value between two float values, proportionally to the elapsed time.
  * It takes into account an acceleration ratio and/or a deceleration ratio. 
  * This method is usually used internally in the ComputeValue method so for the most part, you don't have to use it. 
  * @see ComputeValue
  */
  float ComputeValueWithAccelelerationsAndLimits(float i_vMin, float i_vMax);
  /**
  * Computes a float value between two float values, proportionally to the elapsed time and to an easing method.
  * Easing modes are the one exposed by the enum CATSYPEasingController::EasingMode (BounceIn, ElasticOut for instance).  
  * This method is usually used internally in the ComputeValue method so for the most part, you don't have to use it. 
  * @see ComputeValue
  */
  float ComputeValueWithEasing(float i_vMin, float i_vMax, CATSYPEasingController::EasingMode i_easingMode); 
 
private:
  float _accelerationRatio;
  float _decelerationRatio;
  CATUnicodeString _fromValueString;
  CATUnicodeString _toValueString;
  CATBoolean _fromValueSpecifiedFlag;
  CATBoolean _toValueSpecifiedFlag;
  CATBaseUnknown_var _spFromValue;
  CATBaseUnknown_var _spToValue;
  CATBaseUnknown_var _spInitialValue;
  CATBaseUnknown_var _spCurrentValue;
  CATSYPEasingController::EasingMode _easingMode; 
  CATBoolean _easingValueSpecifiedFlag;
};
//-----------------------------------------------------------------------

#endif
