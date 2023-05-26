#ifndef CATDLGCALENDAR_H
#define CATDLGCALENDAR_H

// COPYRIGHT DASSAULT SYSTEMES 2019

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATDlgStandard.h"
#include "CATDlgDialog.h"
class CATTime;
class l_CATDlgCalendar;

/** 
 * popup windows to choose a date.
 * <b>Role</b>:
 * This dialog windows enables a end user to conveniently choose a date
 */

class ExportedByCATDlgStandard CATDlgCalendar : public CATDlgDialog
{
  DeclareResource(CATDlgCalendar,CATDlgDialog)

  public:
  /** 
   * Constructs a CATDlgCalendar.
   * @param iParent
   *   The parent of the object.
   * @param iObjectName
   *   The internal name of the object. Default is "Calendar"
   * @param iStyle
   *   The style of the object
   * The style can be :
   *   <dl>
   *   <dt><tt>NULL</tt><dd> Then the style is CATDlgWndBtnOKCancel.
   *   <dt><tt>CATDlgWndModal</tt><dd> for a modal window ; no interaction is possible outside this window 
   *   as long as it is displayed. The cursor changes to prevent from doing anything outside of the window.
   *   <dt><tt>CATDlgWndBtnOKCancel</tt><dd> for a standard dialog window with the OK and Cancel push buttons.
   *   <dt><tt>CATDlgWndBtnOKApplyClose</tt><dd> for a standard dialog window with the OK, Apply and Close push buttons.
   *   <dt><tt>CATDlgWndBtnClose</tt><dd> for a standard dialog window with the Close push button.
   *   <dt><tt>CATDlgWndPointerLocation</tt><dd> for a dialog window created at the mouse cursor location.
   *   <dt><tt>CATDlgWndTitleBarHelp</tt><dd> for a dialog window with the help button located in the title bar, as a question mark.
   *   This is possible with Windows only and has no effect with UNIX
   *   <dt><dd>Default value is CATDlgWndBtnOKCancel | CATDlgWndModal  
   *   </dl>
   */
  CATDlgCalendar(CATDialog *iFather,
    const CATString &iId = (char *)"Calendar",
    CATDlgStyle iStyle=CATDlgWndBtnOKCancel|CATDlgWndModal);

  virtual ~CATDlgCalendar();

  /**
   * @nodoc
   * Requests the ClassName, IsA, and IsAKindOf methods to be created.
   */
  CATDeclareClass ;

  /**
   * Returns the current value of the date in CATTime format.
   */
  CATTime GetDate();
  /**
   * Returns the current value of the year.
   */
  short GetYear();
  /**
   * Returns the current value of the month.
   */
  short GetMonth();
  /**
   * Returns the current value of the day.
   */
  short GetDay();

  /**
   * Modifies the current date in CATTime format.
   * @param iDate
   * The new value.
   */
  void SetDate(const CATTime& iDate);
  /**
   * Modifies the current year.
   * @param iYear
   * The new value.
   * @param iRefresh
   * Specifies if the sensitivity of the controls inside the CATDlgCalendar will be updated. Default value is 1 (true).
   */
  void SetYear(const short iYear, const short iRefresh=1);
  /**
   * Modifies the current month.
   * @param iMonth
   * The new value.
   * @param iRefresh
   * Specifies if the sensitivity of the controls inside the CATDlgCalendar will be updated. Default value is 1 (true).
   */
  void SetMonth(const short iMonth, const short iRefresh=1);
  /**
   * Modifies the current day.
   * @param iDay
   * The new value.
   * @param iRefresh
   * Specifies if the sensitivity of the controls inside the CATDlgCalendar will be updated. Default value is 1 (true).
   */
  void SetDay(const short iDay);

  private:
  /**
   * @nodoc
   */
  l_CATDlgCalendar* _frameCalendarWindow;
};
#endif

