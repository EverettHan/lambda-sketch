#ifndef CATDLGBLACKBOX_H
#define CATDLGBLACKBOX_H

// COPYRIGHT DASSAULT SYSTEMES 2004

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATDialog.h"

/**
 * @deprecated R425 Use CATSysWidgetEx
 */
#include "CATSysWidget.h"
#include "CATSysWidgetEx.h"

class l_CATDlgBlackBox;
class CATDlgContextualMenu;

#ifndef CATDlgBlackBox_ADD
/** @nodoc */
#define CATDlgBlackBox_ADD
#endif

#ifndef CATDlgBlackBox_LateADD
/** @nodoc */
#define CATDlgBlackBox_LateADD
#endif

/** 
 * Neutral window providing some interoperability capability with non V6 Dialog objects.
 * <br>
 * <b>Role</b>:
 * Creates an empty frame without any border.
 * <br>
 * It is targeted for very specific usages. Most application developers do not have to deal with this object.
 */

class ExportedByDI0PANV2 CATDlgBlackBox : public CATDialog
{
  CATDeclareClass;

public:
  /** 
   * Constructs a CATDlgNative
   * @param iParent
   *   The parent of the object
   * @param iName
   *   The name of the object
   * @param iStyle
   *   The style of the object
   */
  CATDlgBlackBox(CATDialog * iParent, const CATString& iName, CATDlgStyle iStyle = NULL);

  /**
   * Destructor
   */
   virtual ~CATDlgBlackBox();

  /** 
   * @deprecated R425 Use GetNativeWidgetEx
   * Gets a pointer to the native widget of the underlying window
   */ 
  CATSysWidget GetNativeWidget();

  /** 
   * Gets a pointer to the native widget of the underlying window
   */ 
  CATSysWidgetEx GetNativeWidgetEx();

  /**
   * Returns the contextual menu of the box if any.
   */
  CATDlgContextualMenu* GetContextualMenu();


  /**
   * @nodoc
   */
  virtual l_CATDialog * GetLetterObject();

  /**
   * Resets internal object. Internal use only
   */
  virtual void ResetLetterObject();

  CATDeclareCBEvent(WindowCreated);

private:
  l_CATDlgBlackBox * _frameWindow;

  /** @nodoc */
  CATDlgBlackBox_ADD
};

/** @nodoc */
CATDlgBlackBox_LateADD

#endif
