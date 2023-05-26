#ifndef CATDLGSLIDER_H
#define CATDLGSLIDER_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATDlgControl.h"

class CATString;
class l_CATDlgSlider;
class CATDlgSYPInterval;

#ifndef CATDlgSlider_ADD
/** @nodoc */
#define CATDlgSlider_ADD
#endif

#ifndef CATDlgSlider_LateADD
/** @nodoc */
#define CATDlgSlider_LateADD
#endif

/** 
 * Base class for scale control.
 * <b>Role</b>:
 * The slider enables the end user to select a value among a discrete list of values ranging
 * from a start value to an end value. The value can be incremented or decremented by dragging
 * along with the mouse, or clicking in the sliding area. You set the start and end values as floats,
 * while you set the step number as an int. The step value is the difference between start and
 * end values, divided by the number of steps. A slider can be horizontal or vertical.
 * <br>
 * Use sliders whenever you propose to the end user to select a numerical value from a discrete list in a given range.
 */
class ExportedByDI0PANV2 CATDlgSlider : public CATDlgControl
{

 public:

				/** 
				 * Constructs a CATDlgSlider.
				 * @param iParent
				 *   The parent of the scale control.
				 * @param iObjectName
				 *   The name of the scale control.
				 * @param iStyle
				 *   The style of the scale control.
				 * The style can be :
				 *   <dl>
				 *   <dt><tt>CATDlgCtrHorizontal</tt><dd> : the slider is horizontal (this is the default),
				 *   <dt><tt>CATDlgCtrVertical</tt><dd> : the slider is vertical,
				 *   <dt><tt>CATDlgSldNoValue</tt><dd> : the slider doesn't display the current value.
				 *   </dl>
				 */
        CATDlgSlider( CATDialog *iParent, const CATString& iObjectName, CATDlgStyle iStyle=NULL);

        virtual ~CATDlgSlider();

        /**
         * Sets the current float value.
         * @param iValue
         * The value to set.
				 * @param iNotify
				 * Set this parameter to a non null value if you want the corresponding notification to be sent.
				 * Otherwise set it to 0, so no notification will be sent. 
         */
        float SetCurrentValue( float iValue, int iNotify = 1 );

        /**
         * Returns the current float value.
         */
        float GetCurrentValue();

        /**
         * Sets the minimum, the maximum values and the int number of steps for the range.
         * @param iMin
         * The minimum value to set for the range.
         * @param iMax
         * The maximum value to set for the range.
         * @param iStepCount
         * The number of steps to set for the range.
         */
        void  SetRange( float iMin, float iMax, int iStepCount = 10 );

        /**
         * Retrieves the minimum, the maximum values and the int number of steps for the range.
         * @param oMin
         * The returned minimum value for the range.
         * @param oMax
         * The returned maximum value for the range.
         * @param oStepCount
         * The returned number of steps for the range.
         */
        void  GetRange( float& oMin, float& oMax, int& oStepCount);

        /**
         * Sets the number of displayed decimals.
         * @param iDecimals
         * The number of displayed decimals to set.
         */
        void  SetDecimalPoint(int iDecimals);

        /**
         * Returns the number of displayed decimals.
         */
        int   GetDecimalPoint();

				/**
				 * Returns the event notification sent whenever the end user clicks in the scrollable field.
				 * If the click is right or above the slider, the value increments of one step, and decrements of one step otherwise.
				 * The end user can press the left mouse key continuously and then the current value increments or decrements
				 * accordingly as long as the left mouse key is pressed, or the start or end value is reached.
				 */
        CATNotification *GetSliderModifyNotification() const;

				/**
				 * Returns the event notification sent as long as the slider is dragged.
				 */
        CATNotification *GetSliderDragNotification() const;

				/**
				 * @nodoc 
				 * Returns the internal object.
				 */
        virtual l_CATDialog* GetLetterObject();

				/** @nodoc 
				 * Resets the internal object.
				 */
        virtual void ResetLetterObject();

       /**
        * @nodoc
        * Requests the ClassName, IsA, and IsAKindOf methods to be created.
        */
        CATDeclareClass ;
 private:

				/**
				 * @nodoc 
		     * Address of the internal object.
				 */
        l_CATDlgSlider *_frameSlider;

        /** @nodoc */
        CATDlgSlider_ADD
};

/** @nodoc */
CATDlgSlider_LateADD

#endif
