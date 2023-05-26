#ifndef CATDLGPUSHBUTTON_H
#define CATDLGPUSHBUTTON_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATDlgControl.h"


class CATString;
class l_CATDialog;
class l_CATDlgPushButton;
class CATDlgSYPColor;

#ifndef CATDlgPushButton_ADD
/** @nodoc */
#define CATDlgPushButton_ADD
#endif

#ifndef CATDlgPushButton_LateADD
/** @nodoc */
#define CATDlgPushButton_LateADD
#endif

/**
 * Base class for simple push buttons.
 * <b>Role:</b>Like any control, assign CATDlgPushButton to any container or window.
 */
class ExportedByDI0PANV2 CATDlgPushButton : public CATDlgControl {
  public:

    /**
     * Constructor.
     * @param iParent
     * The parent widget.
     * @param iObjectName
     * The internal name of the push button.
     * @param iStyle
     * The style of the push button.
     * <b>Legal values:</b>
     * <dl>
     * <dt><tt>CATDlgPusRepetitive</tt><dd> Creates a button which will trigger a specific event when maintained pressed. </dd></dt>
     * <dt><tt>CATDlgPusNoShadow</tt><dd> Button without 3D look. This style is effective only if an icon is defined for the button. </dd></dt>
     * <dt><tt>CATDlgBtnIconAndText</tt><dd> When they are defined, both its icon and its title will be displayed on the button face.
     *                                       This style is ignored if CATDlgPusNoShadow is specified.
     *                                       </dd></dt>
     * </dl>
     */
    CATDlgPushButton( CATDialog *iParent, const CATString& iObjectName, CATDlgStyle iStyle=NULL);

    /**
     * Destructor.
     */
    virtual ~CATDlgPushButton();

    /**
     * @nodoc
     * Sets the color the push button.
     * @param iRed
     *  the red component of the color, in the <tt>0-255</tt> range.
     * @param iGreen
     *  the green component of the color, in the <tt>0-255</tt> range.
     * @param iBlue
     *  the blue component of the color, in the <tt>0-255</tt> range.
     */
    void SetColor(unsigned char iRed, unsigned char iGreen, unsigned char iBlue);

    /**
     * Returns the event notification sent whenever the pushed button is pressed.
     */
    CATNotification *GetPushBActivateNotification() const;

    /**
     * Returns the event notification repeatedly sent as long as the pushed 
     * button is kept pressed.
     */
    CATNotification *GetPushBRepetitiveNotification() const;

    /** @nodoc
     * Sets the monochrome icon associated to the state of the dialog object.
     * @param iBitmap
     * The monochrome bitmap representing the icon.
     * The length expected is (iWidth+7)/8 * iHeight
     * @param iWidth
     * The width of the icon.
     * @param iHeight
     * The height of the icon.
     */
    void SetPixelImage(const char* iBitmap, int iWidth, int iHeight);

    /** @nodoc
     * Get internal object.
     */
    virtual l_CATDialog* GetLetterObject();

    /** @nodoc 
     * Resets internal object.
     */
    virtual void ResetLetterObject();

    /** @nodoc 
     */
    virtual void OnImmediate (CATNotification *);

    /**
     * @nodoc
     * Requests the ClassName, IsA, and IsAKindOf methods to be created.
     */
    CATDeclareClass ;

  private:

    /** @nodoc
     * Address of internal object.
     */
    l_CATDlgPushButton* _framePushButton;
    
    /** @nodoc */
    CATDlgPushButton_ADD
};

/** @nodoc */
CATDlgPushButton_LateADD

#endif
