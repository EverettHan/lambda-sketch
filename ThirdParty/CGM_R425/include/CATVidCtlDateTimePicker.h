// COPYRIGHT Dassault Systemes 2018
//===================================================================
//  March 2018  Creation: Dassault Systemes
//===================================================================

#ifndef CATVidCtlDateTimePicker_H
#define CATVidCtlDateTimePicker_H

#include <VisuDialog.h>
#include <CATVidCtlLineEditor.h>
#include "CATVidCtl.h"
#include "CATUnicodeString.h"
#include "CATTime.h"
//#include "CATVidCtlCalendar.h"

class CATVidCtlCalendar;

/**
* Date Time Editor.
* <b>Role</b>:
* This widget will display the calendar and time picker view on click into the calendar button. By Default only Calendar View is visible.
* It is used to select a date in the Calendar or write it in the input.
*/

class ExportedByVisuDialog CATVidCtlDateTimePicker : public CATVidCtl
{
	CATDeclareClass;

public:
	/**
	* Constructs a CATVidCtlDateTimePicker with standard style.
	* @param i_pParent The parent of the widget.
	* @param i_pIdentifier The name of the widget.
	* @param i_template Name of the template.
	* @param i_variation Variation name.
	*/
	static CATVidCtlDateTimePicker* CreateDateTimePickerEditor(CATCommand *i_pParent, const CATString & i_pIdentifier, const CATUnicodeString &i_template, const CATUnicodeString &i_variation);

	/**
	* Constructor
	*/
	CATVidCtlDateTimePicker();
	/**
	* Destructor
	*/
	virtual ~CATVidCtlDateTimePicker();

	/**
	* Set date of the editor
	* @param iDate
	*   The Date to be set
	*/
	int SetDate(const CATTime &iDate);
	/**
	* Returns Date of the editor
	*/
	CATTime GetDate();

	/**
	* This Event is emitted when DateTimePicker value is changed by editing in DateTime Editor or by changing the value from calendar (on close of calendar popup)
	*/
	static CATSYPEvent* DateTimeChange();
	/**
	* This Event is emitted when calendar popup is opened
	*/
	static CATSYPEvent* Show();
	/**
	* This Event is emitted when calendar popup is closed
	*/
	static CATSYPEvent* Hide();

	/**
	* Event handler for EditingFinished event. This event is emitted whenever the editor lose focus.
	*/
	void OnEditingFinished(CATBaseUnknown* i_pSender, CATSYPEventArgs* i_pArgs);
	/**
	* Event handler for TextActivated event. This event is  emitted whenever the editor receives focus. The input mode will have the date in MM/DD/YYYY format
	*/
	void OnTextActivated(CATBaseUnknown* i_pSender, CATSYPEventArgs* i_pArgs);
	/**
	* Event handler for Font Icon Button Pressed in Line Editor. This event is  emitted whenever the font icon button in Line Editor is pressed.
	*/
	void OnCalendarButtonPressed(CATBaseUnknown* i_pSender, CATSYPEventArgs* i_pArgs);
	/**
	* Event handler on hiding of calendar pop up. This event is  emitted whenever the popup is hidden.
	*/
	void OnCalendarPopupAutoHide(CATBaseUnknown* i_pSender, CATSYPEventArgs* i_pArgs);
	/**
	* Event handler for selection of dates in calendar. This event is emitted whenever there is a change in selected date .
	*/
	void CalendarSelectionChangeEventCB(CATBaseUnknown* i_pSender, CATSYPEventArgs* i_pArgs);

	/**
	* Gets the maximum value of the Date Time Editor.
	*/
	CATTime GetMaximumValue();
	/**
	* Sets the maximum value of the Date Time Editor. For default maximum value, refer CATTime Specification
	* @param i_maxVal
	*  The value to set.
	*/
	void SetMaximumValue(const CATTime& i_maxVal);
	/**
	* Gets the minimum value of the Date Time Editor.
	*/
	CATTime GetMinimumValue();
	/**
	* Sets the minimum value of the Date Time Editor. For default minimum value, refer CATTime Specification
	* @param i_minVal
	*  The value to set.
	*/
	void SetMinimumValue(const CATTime& i_minVal);

	/**
	* Gets the disable flag Date Time Editor.
	*/
	CATBoolean GetReadOnlyFlag();
	/**
	* Sets the disable flag for Date Time Editor. DateTime Editor can be used in Read Only Mode.
	* @param i_Val
	*  The value to set.
	*/
	void SetReadOnlyFlag(const CATBoolean i_Val);

	/**
	* Gets the Default Calender Value Flag for DateTimePicker.
	*/
	CATBoolean GetDefaultToTodayFlag();

	/**
	* Sets the Default Calender Value Flag for DateTimePicker. Defualt DateTime Editor value can be set to Current Date.
	* @param i_calenderDefaultValueFlag
	*  The value to set.
	*/
	void SetDefaultToTodayFlag(const CATBoolean i_calenderDefaultValueFlag);

	/**
	* Gets whether Time Picker Flag is On/Off.
	*/
	CATBoolean GetTimePickerFlag();

	/**
	* Set Time Picker Flag as On/Off. The value set for TimePickerFlag will be used for the entire lifespan of a DateTimePicker Object.
	* It is recommended to set the value of TimePickerFlag just after the creation of DateTimePicker Object. Default value is FALSE.
	*/
	void SetTimePickerFlag(const CATBoolean i_Val);

	/**
	* Sets the range of Date Time Picker
	* @param i_minVal
	* Minimum Valuse to be set
	* @param i_maxValue
	* Maximum value to be set
	*/
	void SetRange(const CATTime& i_minValue, const CATTime& i_maxValue);

protected:
	virtual void TemplateDataUpdated();

private:
	// Copy constructor and assignment operator
	// ----------------------------------------
	CATVidCtlDateTimePicker(CATVidCtlDateTimePicker &);
	CATVidCtlDateTimePicker& operator=(CATVidCtlDateTimePicker&);

	enum CATVidDateTimePickerEvents
	{
		DateTimePicker_DateTimeChange,
		DateTimePicker_Show,
		DateTimePicker_Hide
	};

	CATVidCtlLineEditor* _pLineEditor;
	CATVidCtlPopup* _pCalendarPopup;
	CATVidCtlCalendar* _pCalendar;
	CATBoolean _bReadOnlyFlag;
	CATBoolean _bTimePickerFlag;
	CATBoolean _bInitializeTimePickerFlag;
	CATBoolean _bDisplayCalendarView;
	CATBoolean _bDefaultToTodayFlag;

	CATVidCtlLineEditor* _GetEditor();
	void SwitchToDisplayMode(const CATTime& iDate);
	void RaiseEvent(CATVidDateTimePickerEvents i_eventType);
	void BuildCalendarView();

	/**
	* Validate().
	* Returns TXT_VALID if the string input contains a date that is within the valid range according to CATTime (Between CATTimeTypes::YEAR_MIN and CATTimeTypes::YEAR_MAX)
	* and is in the correct format. It is to validate the input entered by the user in the editor is valid date or not.
	* Returns TXT_INTERMEDIATE if input contains a date that is outside the range
	* Returns TXT_INVALID if the input is not a date and is in wrong format.
	*/
	CATVidTextValidationState Validate(const CATUnicodeString& i_strInputString) const;

	CATTime GetDateFromText(const CATUnicodeString& i_text);
	
	CATUnicodeString GetTextFromDate(const CATTime& i_value);

	friend class CATVidTstDateTimePicker;

};
//-----------------------------------------------------------------------

#endif
