#ifndef CATDLGPROGRESS_H
#define CATDLGPROGRESS_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATDlgControl.h"

class CATString;
class CATUnicodeString;
class l_CATDialog;
class l_CATDlgProgress;
class CATDlgSYPInterval;

#ifndef CATDlgProgress_ADD
/** @nodoc */
#define CATDlgProgress_ADD
#endif

#ifndef CATDlgProgress_LateADD
/** @nodoc */
#define CATDlgProgress_LateADD
#endif

/**
 * Base class for progress controls.
 * <b>Role:</b>Progress controls provide a graphic gauge which give feedback to 
 * the user about the completion percentage of a given task.
 */
class ExportedByDI0PANV2 CATDlgProgress : public CATDlgControl {
	public:

		/**
		 * Constructor.
		 * @param iParent
		 * The parent widget.
		 * @param iObjectName
		 * The internal name of the menu item.
		 * @param iStyle
		 * The style of the progress control.
		 * <b>Legal values:</b>Only the current default value is available.
		 */
		CATDlgProgress( CATDialog *pParent, const CATString& rObjectName, CATDlgStyle nStyle=NULL);

		/**
		 * Destructor.
		 */
		virtual ~CATDlgProgress();

		/**
		 * Specifies the interval displayed by the progress control.
		 * @param iMin
		 *  the lower bound of the interval displayed by the progress control.
		 * @param iMax
 		 *  the upper bound of the interval displayed by the progress control.
		 */
		void SetRange( int iMin, int iMax);

		/**
		 * Retrieves the interval displayed by the progress control.
		 * @param oMin
		 *  the lower bound of the interval displayed by the progress control.
		 * @param oMax
 		 *  the upper bound of the interval displayed by the progress control.
		 */
		void GetRange( int* oMin, int* oMax);

		/**
		 * Sets the current value of the progress control.
		 * @param iVal
		 *  the current progress value.
		 */
		void SetPos( int iVal);

		/**
		 * Gets the current value of the progress control.
		 * @return
		 *  the current progress value.
		 */
		int  GetPos();

		/**
		 * Augments the value of the progress control.
		 * @param iPos
		 *  the amount by which the value of the progress control must be increased.
		 */
		void OffsetPos(int iPos);

		/**
		 * Set the step (the amount by which the current value will augment every time the <tt>StepIt</tt>
		 * method is invoked).
		 * @param iStep
		 *  the step value.
		 */
		void SetStep(int iStep); 

		/**
		 * Get the step (the amount by which the current value will augment every time the <tt>StepIt</tt>
		 * method is invoked).
		 * @return
		 *  the step value.
		 */
		int GetStep();

		/**
		 * Augments the value of the progress control by a fixed step.
		 */
		void StepIt();

		/** @nodoc
		 * Get internal object.
		 */
		virtual l_CATDialog* GetLetterObject();

		/** @nodoc 
		 * Resets internal object.
		 */
		virtual void ResetLetterObject();

       /**
        * @nodoc
        * Requests the ClassName, IsA, and IsAKindOf methods to be created.
        */
        CATDeclareClass ;
	private:

		/** @nodoc
		 * Address of internal object.
		 */
		l_CATDlgProgress* _frameProgress;

    /** @nodoc */
    CATDlgProgress_ADD
};

/** @nodoc */
CATDlgProgress_LateADD

#endif
