#ifndef CATDLGSEPARATOR_H
#define CATDLGSEPARATOR_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */


#include "CATDlgControl.h"

class CATString;
class l_CATDlgSeparator;

#ifndef CATDlgSeparator_ADD
/** @nodoc */
#define CATDlgSeparator_ADD
#endif

#ifndef CATDlgSeparator_LateADD
/** @nodoc */
#define CATDlgSeparator_LateADD
#endif

/** 
 * Base class for separators.
 * <b>Role</b>:
 * The separator is used to leave thin vertical or horizontal empty areas between different
 * controls to help better visualize the different parts of a window or box.
 * <br>
 * Use separators whenever you want to clearly separate groups of controls in a dialog box.
 */
class ExportedByDI0PANV2 CATDlgSeparator : public CATDlgControl
{

 public:

     /** 
     * Constructs a CATDlgSeparator.
     * @param iParent
     *   The parent of the separator.
     * @param iObjectName
     *   The name of the separator.
     * @param iStyle
     *   The style of the separator.
     * The style can be :
     *   <dl>
     *   <dt><tt>CATDlgCtrHorizontal</tt><dd> : the separator is horizontal (this is the default, if no value is passed),
     *   <dt><tt>CATDlgCtrVertical</tt><dd> : the separator is vertical.
     *   </dl>
     */
     CATDlgSeparator( CATDialog *iParent, const CATString& iObjectName, CATDlgStyle iStyle=NULL);

     virtual ~CATDlgSeparator();

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
    * Address of the internal object.
    */
    l_CATDlgSeparator *_frameSeparator;

    /** @nodoc */
    CATDlgSeparator_ADD
};

/** @nodoc */
CATDlgSeparator_LateADD

#endif
