#ifndef CATDLGMENUITEM_H
#define CATDLGMENUITEM_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U2
 */

#include "CATDialog.h"
class CATString;

#ifndef CATDlgMenuItem_ADD
/** @nodoc */
#define CATDlgMenuItem_ADD
#endif

#ifndef CATDlgMenuItem_LateADD
/** @nodoc */
#define CATDlgMenuItem_LateADD
#endif

/**
 * Base class to create a menu item.
 * <br>
 * This class can not be instantiated.
 * @see CATDlgPushItem, CATDlgRadioItem, CATDlgCheckItem
 */
class ExportedByDI0PANV2 CATDlgMenuItem : public CATDialog
{
 public:
   /**
   * @nodoc
   * Requests the ClassName, IsA, and IsAKindOf methods to be created.
   */
   CATDeclareClass ;

 protected:

   /**
   * Constructs a menu item object.
   * @param iParent
   * The parent widget.
   * @param iObjectName
   * The internal name of the menu item.
   * @param iStyle
   * The style of the menu item . 
   */
   CATDlgMenuItem( CATDialog *iParent, const CATString& iObjectName, CATDlgStyle iStyle=NULL);
   virtual ~CATDlgMenuItem();

   /** @nodoc */
   CATDlgMenuItem_ADD
};


/** @nodoc */
CATDlgMenuItem_LateADD

#endif
