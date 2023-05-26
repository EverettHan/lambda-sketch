#ifndef CATICAfrWindow_H
#define CATICAfrWindow_H

// COPYRIGHT DASSAULT SYSTEMES 2012/06/20

#include "CATAfrItf.h"
#include "CATBaseUnknown.h"
#include "CATCAfrEnum.h"
#include "CATUnicodeString.h"

extern ExportedByCATAfrItf  IID IID_CATICAfrWindow ;

//-----------------------------------------------------------------------------
/**
* Interface representing The CAfrWindow Component.
*/
class ExportedByCATAfrItf CATICAfrWindow: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

    /**
    * Possible standard buttons for a CATCAfrWindow with AfrVIDFraDialog representation type.
    */
    enum StandardButton 
    {
      /** An invalid button */
      NoButton          = 1,
      /** An "OK" button defined*/
      Ok                = 1<<1,
      /** A "Open" button defined*/
      Open              = 1<<2,
      /** A "Save" button defined*/
      Save              = 1<<3,
      /** A "Cancel" button defined*/
      Cancel            = 1<<4,
      /** A "Close" button defined*/
      Close             = 1<<5,
      /** A "Discard" button defined*/
      Discard           = 1<<6,
      /** An "Apply" button defined*/
      Apply             = 1<<7,
      /** A "Reset" button defined  */
      Reset             = 1<<8,
      /** A "Restore Defaults" button defined  */
      RestoreDefaults   = 1<<9,
      /** A "Help" button defined  */
      Help              = 1<<10,
      /** A "Save All" button defined*/
      SaveAll           = 1<<11,
      /** A "Yes" button defined */
      Yes               = 1<<12,
      /** A "Yes to All" button */
      YesToAll          = 1<<13,
      /** A "No" button defined */
      No                = 1<<14,
      /** A "No to All" button */
      NoToAll           = 1<<15,
      /** An "Abort" button defined*/
      Abort             = 1<<16,
      /** A "Retry" button defined*/
      Retry             = 1<<17,
      /** An "Ignore" button defined*/
      Ignore            = 1<<18
    };

    /**
    * Ensures that the window content is visible to the user.
    * @li if the window is minimized, this method restores it
    * @li if the window is collapsed, this method expands it
    * @li if the window is docked, this method ensures that the docking window is expanded
    * and it activates the tab page containing the window
    */
    virtual void EnsureVisible() = 0;

    /**
    * Attaches the window to the given area of the given target window.
    * This method will fail if the window cannot be a snapping source for the given 
    * target window and the given area.
    * This method will available for the representation type: AfrVIDFraPanel and AfrVIDFraLabel
    */
    virtual HRESULT AttachToWindow( CATBaseUnknown* ipTargetWindow, CATCAfrEnum::SnapArea i_targetArea) = 0;

    /**
    * Sets the label of the given default button.
    * By default, the label of the standard buttons is retrieved in the CATVidFraDialog.CATNls file
    */
    virtual void SetButtonLabel( CATICAfrWindow::StandardButton iStandardButton, const CATUnicodeString& i_label) = 0;

    /**
    * Sets the EnableFlag property of the given default button.
    * By default, each standard button is enabled.
    */
    virtual void SetButtonEnableFlag( CATICAfrWindow::StandardButton iStandardButton, const CATBoolean& i_enableFlag) = 0;

    /**
    * display the window in the current drawing area.
    */
    virtual void Display() = 0;
};
#endif
