#ifndef CATDLGRADIOITEM_H
#define CATDLGRADIOITEM_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


#include "CATDlgMenuItem.h"

class l_CATDlgRadioItem;

#ifndef CATDlgRadioItem_ADD
/** @nodoc */
#define CATDlgRadioItem_ADD
#endif

#ifndef CATDlgRadioItem_LateADD
/** @nodoc */
#define CATDlgRadioItem_LateADD
#endif

/**
 * Base class for radio menu items.
 * <b>Role</b>:
 * A radio menu item is used for selecting mutually exclusive options.
 * <br>
 * Use radio items whenever you propose to the end user a choice among several mutually exclusive options, 
 * that is when one option only can be selected among all the options proposed.
 */
class ExportedByDI0PANV2 CATDlgRadioItem : public CATDlgMenuItem
{

 public:
/**
 * Constructs a CATDlgRadioItem.
 * @param iParent
 *   The parent of the radio item.
 * @param iObjectName
 *   The name of the radio item.
 * @param iStyle
 *   The style of the radio item. Only the default value is allowed.
 */
        CATDlgRadioItem( CATDialog *iParent, const CATString& iObjectName, CATDlgStyle iStyle=NULL);

        virtual ~CATDlgRadioItem();
/**
 * Returns the state of the radio item.
 *   <br>
 * The state of the radio item can be:
 *   <dl>
 *   <dt><tt>CATDlgCheck</tt><dd> if the radio item is checked,
 *   <dt><tt>CATDlgUncheck</tt><dd> if it is unchecked.
 *   </dl>
 */
        CATULong  GetState();

/**
 * Sets the state of the radio item.
 * @param iState
 * The state of the radio item to set.
 *   <br>
 *   <b>Legal values</b> : It can be set to either :
 *   <dl>
 *   <dt><tt>CATDlgCheck</tt><dd> to check the radio item,
 *   <dt><tt>CATDlgUncheck</tt><dd> to uncheck it.
 *   </dl>
 * @param iNotify
 * Set this parameter to a non null value if you want the corresponding notification to be sent.
 * Otherwise set it to 0, so no notification will be sent.
 */
        void SetState( CATULong iState, int iNotify=1);

/**
 * Returns the event notification sent whenever the radio item is checked or unchecked.
 */
        CATNotification *GetRadIModifyNotification() const;

/**
 * @nodoc
 * Returns the internal object.
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

/**
 * @nodoc
 */
        l_CATDlgRadioItem* _frameExclusive;

        /** @nodoc */
        CATDlgRadioItem_ADD
};

/** @nodoc */
CATDlgRadioItem_LateADD

#endif
