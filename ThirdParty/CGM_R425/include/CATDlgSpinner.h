#ifndef CATDLGSPINNER_H
#define CATDLGSPINNER_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


#include "CATDlgControl.h"

class CATString;
class l_CATDlgSpinner;
class CATDlgSYPInterval;

#ifndef CATDlgSpinner_ADD
/** @nodoc */
#define CATDlgSpinner_ADD
#endif

#ifndef CATDlgSpinner_LateADD
/** @nodoc */
#define CATDlgSpinner_LateADD
#endif

/** 
 * Base class for spinner counters.
 * <b>Role</b>:
 * The spinner allows the end user to select a numerical value among a discrete list of values,
 * ranging from a start value to an end value. The value can be incremented or decremented by clicking the arrows.
 * The up arrow is dedicated to incrementing while the down arrow is for decrementing.
 * You set the start and end values as floats, while you set the step number either as an int or as a float.
 * The step value is the difference between start and end values, divided by the number of steps.
 * The default values ranges from 1 to 10 with 10 steps.
 * <br>
 * Use spinner whenever you propose to the end user to enter a numerical value selected from a discrete list.
 */
class ExportedByDI0PANV2 CATDlgSpinner : public CATDlgControl
{

 public:

        /** 
         * Constructs a CATDlgSpinner.
         * @param iParent
         *   The parent of the spinner.
         * @param iObjectName
         *   The name of the spinner.
         * @param iStyle
         *   The style of the spinner. Styles can be concatenated using the "|" character.
         * The style can be :
         *   <dl>
         *   <dt><tt>NULL</tt><dd> : for the default spinner (if no value is passed) ; the spinner field can not be edited.
         *   <dt><tt>CATDlgSpnEntry</tt><dd> : the spinner field can be edited. 
         * If the user keys in a value out of the spinner range, this value is not accepted and the previous valid value is used instead.
         *   <dt><tt>CATDlgSpnUserIncrement</tt><dd> : prevents from automatically incrementing or decrementing the displayed value 
         * when the user selects the arrows. You need to provide your own methods instead, for example to increment or decrement
         * with a parameter different from the step.
         *   <dt><tt>CATDlgSpnDouble</tt><dd> : the entered number must be a double precision floating number.
         *   </dl>
         */
        CATDlgSpinner( CATDialog *iParent, const CATString& iObjectName, CATDlgStyle iStyle=NULL);

        virtual ~CATDlgSpinner();

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
         * Sets the current text (for free increment spinners only).
         * @param iText
         * The text to set.
         * @param iNotify
         * Set this parameter to a non null value if you want the corresponding notification to be sent.
         * Otherwise set it to 0, so no notification will be sent. 
         */
        void SetCurrentText(const CATUnicodeString &iText,	int iNotify = 1);

        /**
         * Returns the current text (for free increment spinners only).
         */
        const CATUnicodeString &GetCurrentText();

        /**
         * Sets the minimum, the maximum values and the int number of steps for the range (except with double precision and free increment spinners).
         * For double precision spinners, use SetMinMaxStep instead.
         * @param iMin
         * The minimum value to set for the range.
         * @param iMax
         * The maximum value to set for the range.
         * @param iStepCount
         * The number of steps to set for the range.
         * @param iNotify
         * Set this parameter to a non null value if you want the corresponding notification to be sent.
         * Otherwise set it to 0, so no notification will be sent. 
         */
        void  SetRange( float iMin, float iMax, int iStepCount = 10, int iNotify = 1 );

        /**
         * Sets the minimum, the maximum values and the float number of steps for the range (except with double precision and free increment spinners).
         * For double precision spinners, use SetMinMaxStep instead.
         * @param iMin
         * The minimum value to set for the range.
         * @param iMax
         * The maximum value to set for the range.
         * @param iStepCount
         * The number of steps to set for the range.
         * @param iNotify
         * Set this parameter to a non null value if you want the corresponding notification to be sent.
         * Otherwise set it to 0, so no notification will be sent. 
         */
        void  SetRange( float iMin, float iMax, float iStepCount = 10.f, int iNotify = 1 );

        /**
         * Retrieves the minimum, the maximum values and the int number of steps for the range (except with double precision and free increment spinners).
         * For double precision spinners, use GetMinMaxStep instead.
         * @param oMin
         * The returned minimum value for the range.
         * @param oMax
         * The returned maximum value for the range.
         * @param oStepCount
         * The returned number of steps for the range.
         */
        void  GetRange( float& oMin, float& oMax, int& oStepCount);

        /**
         * Retrieves the minimum, the maximum values and the float number of steps for the range (except with double precision and free increment spinners).
         * For double precision spinners, use GetMinMaxStep instead.
         * @param oMin
         * The returned minimum value for the range.
         * @param oMax
         * The returned maximum value for the range.
         * @param oStepCount
         * The returned number of steps for the range.
         */
        void  GetRange( float& oMin, float& oMax, float& oStepCount);

        /**
         * Sets the minimum, the maximum values and the number of steps for the range for double precision spinners.
         * @param iMin
         * The minimum value to set for the range.
         * @param iMax
         * The maximum value to set for the range.
         * @param iStep
         * The step value.
         * @param iNotify
         * Set this parameter to a non null value if you want the corresponding notification to be sent.
         * Otherwise set it to 0, so no notification will be sent. 
         */
        void  SetMinMaxStep(double iMin, double iMax, double iStep, int iNotify = 1);

        /**
         * Retrieves the minimum, the maximum values and the number of steps for the range for double precision spinners.
         * @param oMin
         * The returned minimum value for the range.
         * @param oMax
         * The returned maximum value for the range.
         * @param oStepCount
         * The returned step value.
         */
        void  GetMinMaxStep(double &oMin, double &oMax, double &oStep);

        /**
         * Sets the current double value (for double precision spinners only).
         * @param iValue
         * The value to set.
         * @param iNotify
         * Set this parameter to a non null value if you want the corresponding notification to be sent.
         * Otherwise set it to 0, so no notification will be sent. 
         */
        void  SetValue(double iValue, int iNotify=1);

        /**
         * Returns the current double value (for double precision spinners only).
         */
        double GetValue();

        /**
         * Sets the format of the displayed value as a character string (except with double precision and free increment spinners).
         * Advice : use %g instead of %f.
         * @param iFormat
         * The format to set for the displayed value.
         */
        void  SetFormat( char * iFormat);

        /**
         * Returns the format of the displayed value as a character string (except with double precision and free increment spinners).
         */
        char* GetFormat();

        /**
         * Sets the number of visible characters.
         * @param iWidth
         * The number of visible characters to set.
         */
        void  SetVisibleTextWidth( int iWidth);

        /**
         * Returns the number of visible characters.
         */
        int   GetVisibleTextWidth();

        /**
         * Returns the event notification sent whenever the current value is modified.
         * It is sent whatever the means used to modify the value, such as arrows or field edition.
         */
        CATNotification *GetSpinnerModifyNotification() const;

        /**
         * Returns the event notification sent whenever the down (decrement) arrow  is clicked.
         * It is available with CATDlgSpnUserIncrement style only.
         */
        CATNotification *GetSpinnerBtnDownNotification() const;

        /**
         * Returns the event notification sent whenever the up (increment) arrow  is clicked.
         * It is available with CATDlgSpnUserIncrement style only.
         */
        CATNotification *GetSpinnerBtnUpNotification() const;

        /**
         * Sets the up arrow button sensitivity.(for free increment spinners only).
         * @param iState
         * The sensitivity to set for the up arrow button.
         * The sensitivity can be :
         *   <dl>
         *   <dt><tt>CATDlgEnable</tt><dd> : the arrow button is sensitive to the user action.
         *   <dt><tt>CATDlgDisable</tt><dd> : the arrow button is not sensitive to the user action.
         *   </dl>
         */
        void SetButtonUpSensitivity(CATULong iState);

        /**
         * Returns the up arrow sensitivity.
         * The sensitivity can be :
         *   <dl>
         *   <dt><tt>CATDlgEnable</tt><dd> : the arrow button is sensitive to the user action.
         *   <dt><tt>CATDlgDisable</tt><dd> : the arrow button is not sensitive to the user action.
         *   </dl>
             */
        CATULong GetButtonUpSensitivity();

        /**
         * Sets the down arrow button sensitivity.(for free increment spinners only).
         * @param iState
         * The sensitivity to set for the down arrow button.
         * The sensitivity can be :
         *   <dl>
         *   <dt><tt>CATDlgEnable</tt><dd> : the arrow button is sensitive to the user action.
         *   <dt><tt>CATDlgDisable</tt><dd> : the arrow button is not sensitive to the user action.
         *   </dl>
         */
        void SetButtonDownSensitivity(CATULong iState);

        /**
         * Returns the down arrow sensitivity.
         * The sensitivity can be :
         *   <dl>
         *   <dt><tt>CATDlgEnable</tt><dd> : the arrow button is sensitive to the user action.
         *   <dt><tt>CATDlgDisable</tt><dd> : the arrow button is not sensitive to the user action.
         *   </dl>
         */
        CATULong GetButtonDownSensitivity();

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
        l_CATDlgSpinner *_frameSpinner;

        /** @nodoc */
        CATDlgSpinner_ADD
};

/** @nodoc */
CATDlgSpinner_LateADD

#endif
