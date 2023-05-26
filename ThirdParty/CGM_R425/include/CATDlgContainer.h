#ifndef CATDLGCONTAINER_H
#define CATDLGCONTAINER_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U2
 */

#include "CATDlgBox.h"

class CATString;
class CATDlgControl;
class CATDlgFrame;
class l_CATDlgContainer;

#ifndef CATDlgContainer_ADD
/** @nodoc */
#define CATDlgContainer_ADD
#endif

#ifndef CATDlgContainer_LateADD
/** @nodoc */
#define CATDlgContainer_LateADD
#endif

/** 
 * Base class for scrollable containers.
 * <b>Role</b>:
 * A container defines a scrollable area that can contain a single object. 
 * this object could be a frame itself containing as many objects as you want. 
 * If the container contents does not fit in the displayable area, horizontal 
 * and/or vertical scroll bars are automatically created to allow scrolling 
 * through this contents.
 * <br>
 * Use containers whenever you want to gather many objects in a small window area with scrollbars.
 * The container can have only one child object. This is usually a @href CATDlgFrame instance.
 * <br>
 * You can give a CATDlgContainer the dimensions of its contents for the first display
 * by using the method :   
 * (CATDialog::)SetRectDimensions(1,1,-1,-1);
 *
 */
class ExportedByDI0PANV2 CATDlgContainer : public CATDlgBox
{

 public:

			/** 
			 * Constructs a CATDlgContainer.
			 * @param iParent
			 *   The parent of the container.
			 * @param iObjectName
			 *   The name of the container.
			 * @param iStyle
			 *   The style of the container.
			 */
        CATDlgContainer( CATDialog *iParent, const CATString& iObjectName, CATDlgStyle iStyle=NULL);

        virtual ~CATDlgContainer();

			/**
			 * @nodoc
			 * Returns the internal object.
			 */
        virtual l_CATDialog* GetLetterObject();

			/**
			 * @nodoc 
			 * Resets the internal object.
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
        l_CATDlgContainer *_frameContainer;

        /** @nodoc */
        CATDlgContainer_ADD
};

/** @nodoc */
CATDlgContainer_LateADD

#endif
