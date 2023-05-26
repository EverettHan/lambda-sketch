/* -*-c++-*- */
#ifndef _CATIFmuDocChooser_h
#define _CATIFmuDocChooser_h
// COPYRIGHT DASSAULT SYSTEMES 2002, All rights reserved
#ifndef CATFmuBasicDocChooser_H
#define CATFmuBasicDocChooser_H

#define CATFmuBasicDocChooser_SetOptions() \
  virtual HRESULT SetOptions(const CATFmuDocChooserOptions &iOptions) = 0

#define CATFmuBasicDocChooser_GetOptions() \
  virtual HRESULT GetOptions(CATFmuDocChooserOptions &oOptions) const = 0

#include "CATInteractiveInterfaces.h"
#include "CATBaseUnknown.h"

class CATListPtrCATIDocId;
class CATFmuDocChooserOptions;
class CATUnicodeString;
class CATString;

/**
 * WARNING : this abstract super-class never is to be used as is, 
 * but refer to its derivation : @href CATIFmuDocChooser .
 */

///**
// * Class with the methods common to @href CATIFmuDocChooser and @href CATIFmuBlockedDocChooser.
// * <b>Role</b>: This class provides the methods common to @href CATIFmuDocChooser or a @href CATIFmuBlockedDocChooser.
// * NOTICE: it's not an interface, and it's not supposed to be used beyond FileMenu.
// */
class ExportedByCATInteractiveInterfaces CATFmuBasicDocChooser: public CATBaseUnknown
{
public:
  /**
   * Gets the count of the selected documents.
   * See @href CATIFmuDocChooser#GetSelectionCount
   */
  virtual HRESULT GetSelectionCount(int &oSelectionCount) const = 0;

  /**
   * Gets the selected documents identifiers.
   * See @href CATIFmuDocChooser#GetSelectedDocId
   */
  virtual HRESULT GetSelectedDocId(CATListPtrCATIDocId &oListOfDocId) const = 0;

  /**
   * Gets the selection's options.
   * See @href CATIFmuDocChooser#SetOptions.
   */
  CATFmuBasicDocChooser_SetOptions();
  
  /**
   * Gets the selection's options.
   * See @href CATIFmuDocChooser#GetOptions.
   */
  CATFmuBasicDocChooser_GetOptions();
  
  /**
   * Sets the type filter combo strings.
   * See @href CATIFmuDocChooser#SetFilterStrings
   */
  virtual HRESULT SetFilterStrings(CATUnicodeString *iTypeDescriptionList, CATString *iTypeExtensionsList, int iTypeFilterCount) = 0;

  /**
   * Set the active item in the type filter combo.
   * See @href CATIFmuDocChooser#SetActiveFilterIndex
   */
  virtual HRESULT SetActiveFilterIndex(int iActiveFilter) = 0;

  /**
   * Get the active item in the type filter combo.
   * See @href CATIFmuDocChooser#GetActiveFilterIndex.
   */
  virtual HRESULT GetActiveFilterIndex(int& oActiveFilter) const = 0;

  /**
   * Sets the title of the dialog object to the specified character string.
   * See @href CATIFmuDocChooser#SetTitle
   */
  virtual HRESULT SetTitle(const CATUnicodeString &iTitle) = 0;
};

//-----------------------------------------------------------------------

#endif


#define CATIFmuDocChooser_declaration() \
class ExportedByCATInteractiveInterfaces CATIFmuDocChooser : public CATFmuBasicDocChooser

//--------------------------------------------------------------------------
// Document Acquisition Method
//--------------------------------------------------------------------------

//#include "CATFmuBasicDocChooser.h"

class CATCommand;
class CATNotification;
class CATUnicodeString;
class CATString;
class CATListPtrCATIDocId;
class CATFmuDocChooserOptions;
class CATDialog;

/**
 * User interface for document selection.
 * <b>Role</b>: The user can choose one or many documents in an environment.
 * The document chooser is hidden until you call @href #SetVisibility <tt>(CATDlgShow)</tt>.
 * Please call @href #SetFilterStrings, @href #SetActiveFilterIndex, @href #SetTitle before calling @href #SetVisibility <tt>(CATDlgShow)</tt>.<br>
 * If the caller is a @href CATCommand and not a @href CATDialog, you should call<pre>
 *    CATCommand *pCmd = NULL;
 *    HRESULT hr = pDocChooser->GetEventPublisher(pCmd);
 *    if (SUCCEEDED(hr) && CATSysCheckExpression(pCmd != NULL))
 *      pCmd->SetFather(<the caller>);</pre>
 * in order to let the caller recieve the notifications.<br>
 * WARNING for modal window opened during the event OK or CANCEL:<br>
 * You may open a pop-up window in order to warn the user or ask him what to do. For example, you may explain why the selected
 * document is refused with an error window. Take care to parent your modal window with the one returned by
 * @href #GetActiveWindow. If you don't, the window hierarchy may be broken (known Dialog limitation).
 */
// Note for implementation
// -----------------------
// It's recommended to implement this interface by deriving CATEFmuDocChooser.
// Nevertheless, if you implement this interface with an object that derives from CATCommand (Dialog...) whose destruction is performed by
// CATCommand::RequestDelayedDestruction(), you have:
// - to call AddRef() in the constructor -> m_cRef = 2
// - to derive the method Release():
//   ULONG xxx::Release()
//   {
//     int NbRef = yyy::Release(); // Call the superclass's method (class xxx : public yyy)
//     if (NbRef == 1)
//       RequestDelayedDestruction(); // -> When the destruction will occur, a release will be run -> m_cRef == 0 -> destruction.
//   }

#include "CATInteractiveInterfaces.h"
#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATInteractiveInterfaces IID IID_CATIFmuDocChooser;
#else
extern "C" const IID IID_CATIFmuDocChooser;
#endif
CATIFmuDocChooser_declaration()
{
public:
  CATDeclareInterface;

#ifdef COMPILO_TIE_OK // The TIE compiler aggregates CATFmuBasicDocChooser and CATIFmuDocChooser !

  /**
   * Gets the count of the selected documents.
   * @param oSelectionCount
   *   The number of selected documents.
   * @return
   *   Error code.
   */
  virtual HRESULT GetSelectionCount(int &oSelectionCount) const = 0;

  /**
   * Gets the selected documents identifiers.
   * @param oListOfDocId
   *   The list of the documents identifiers the user chooses (<tt>CATIDocId</tt>).<br>
   *   The input list must be empty.<br>
   *   No element of the output list can be NULL.<br>
   *   Before destroying the list, you have to call <tt>Release</tt> on each element of the list.
   * @return
   *   Error code.
   */
  virtual HRESULT GetSelectedDocId(CATListPtrCATIDocId &oListOfDocId) const = 0;

  /**
   * Sets the selection's available options.
   * @param iOptions
   *   The options definition or restriction
   * @return
   *   Error code.
   */
  virtual HRESULT SetOptions(const CATFmuDocChooserOptions &iOptions) = 0;

  /**
   * Gets the selection's options.
   * @param oOptions
   *   The returned options (ReadOnly...).
   * @return
   *   Error code.
   */
  virtual HRESULT GetOptions(CATFmuDocChooserOptions &oOptions) const = 0;

  /**
   * Sets the type filter combo strings.
   * @param iTypeDescriptionList
   *   The type filter descriptions array.
   * @param iTypeExtensionsList
   *   The type filter extensions array.
   * @param iTypeFilterCount
   *   The type filter count.
   * @return
   *   Error code.
   */
  virtual HRESULT SetFilterStrings(
    CATUnicodeString *iTypeDescriptionList,
    CATString *iTypeExtensionsList,
    int iTypeFilterCount) = 0;

  /**
   * Set the active item in the type filter combo.
   * @param iActiveFilter
   *   The active filter.
   * @return
   *   Error code.
   */
  virtual HRESULT SetActiveFilterIndex(int iActiveFilter) = 0;

  /**
   * Get the active item in the type filter combo.
   * @param oActiveFilter
   *   The currently active filter.
   * @return
   *   Error code.
   */
  virtual HRESULT GetActiveFilterIndex(int& oActiveFilter) const = 0;

  /**
   * Sets the title of the dialog object to the specified character string.
   * @param iTitle
   *   The title to be displayed.
   * @return
   *   Error code.
   */
  virtual HRESULT SetTitle(const CATUnicodeString &iTitle) = 0;

#endif // COMPILO_TIE_OK

  /**
   * Returns the current display state of the dialog object.
   * @param oState
   *   The visibility state can be:
   *   <dl>
   *   <dt><tt>CATDlgShow</tt><dd> if the dialog object is shown,
   *   <dt><tt>CATDlgHide</tt><dd> if the dialog object is hidden.
   *   </dl>
   * @return
   *   Error code.
   */
  virtual HRESULT GetVisibility(unsigned long &oState) const = 0;

  /**
   * Sets the display state of the dialog object.
   * @param iState
   * The visibility state to set.
   *   <br>
   *   <b>Legal values</b> : It can be set to either :
   *   <dl>
   *   <dt><tt>CATDlgShow</tt><dd> to show the dialog object,
   *   <dt><tt>CATDlgHide</tt><dd> to hide the dialog object.
   *   </dl>
   * @return
   *   Error code.
   */
  virtual HRESULT SetVisibility(unsigned long iState) = 0;

  /**
   * Gets the event publisher.
   * @param opEventPublisher
   *   The event publisher.<br>
   *   Call neither <tt>Release</tt> nor delete.
   * @return
   *   Error code.
   */
  virtual HRESULT GetEventPublisher(CATCommand *&opEventPublisher) const = 0;

  /**
   * Gets the ok notification.
   * @param opDiaOKNotification
   *   The ok notification.w<br>
   *   Call neither <tt>Release</tt> nor delete.
   * @return
   *   Error code.
   */
  virtual HRESULT GetDiaOKNotification(CATNotification *&opDiaOKNotification) const = 0;

  /**
   * Gets the cancel notification.
   * @param opDiaCANCELNotification
   *   The cancel notification.<br>
   *   Call neither <tt>Release</tt> nor delete.
   * @return
   *   Error code.
   */
  virtual HRESULT GetDiaCANCELNotification(CATNotification *&opDiaCANCELNotification) const = 0;

  /**
   * Gets the active window.
   * @param opActiveWindow
   *   The document chooser's active window. You may use it to parent a modal window for the OK or CANCEL event.
   * @return
   *   Error code
   */
  virtual HRESULT GetActiveWindow(CATDialog *&opActiveWindow) const = 0;
};

#endif
