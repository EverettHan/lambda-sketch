#ifndef CATDLGBAR_H
#define CATDLGBAR_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATDialog.h"

#ifndef CATDlgBar_ADD
/** @nodoc */
#define CATDlgBar_ADD
#endif

#ifndef CATDlgBar_LateADD
/** @nodoc */
#define CATDlgBar_LateADD
#endif

/** 
 * Base class for status bars and toolbars.
 * <b>Role</b>:
 * This class is the bar object base class to gather a set of controls without needing 
 * to arrange them. Controls appear in their instantiation order.<br>
 * This class cannot be instantiated.<br>
 * Its derived classes are @href CATDlgStatusBar and @href CATDlgToolBar.<br>
 * The parent of an instance of a class that derives from CATDlgBar must be an instance 
 * of a class that derives from the @href CATDlgDocument class.
 */
class ExportedByDI0PANV2 CATDlgBar : public CATDialog
{
 public:
       /**
        * @nodoc
        * Requests the ClassName, IsA, and IsAKindOf methods to be created.
        */
        CATDeclareClass ;

 protected:

/** 
 * Constructs a CATDlgBar.
 * @param iParent
 *   The parent of the bar.
 * @param iObjectName
 *   The name of the bar.
 * @param iStyle
 *   The style of the bar.
 */
        CATDlgBar( CATDialog *iParent, const CATString& iObjectName, CATDlgStyle iStyle=NULL);

        virtual ~CATDlgBar();

    /** @nodoc */
    CATDlgBar_ADD
};

/** @nodoc */
CATDlgBar_LateADD

#endif
