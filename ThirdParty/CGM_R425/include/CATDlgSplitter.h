#ifndef CATDLGSPLITTER_H
#define CATDLGSPLITTER_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U2
 */


#include "CATDlgBox.h"

class CATString;
class l_CATDialog;
class l_CATDlgSplitter;
class CATDlgControl;
class CATDlgBlackBox;

#ifndef CATDlgSplitter_ADD
/** @nodoc */
#define CATDlgSplitter_ADD
#endif

#ifndef CATDlgSplitter_LateADD
/** @nodoc */
#define CATDlgSplitter_LateADD
#endif

/** 
 * Base class for splitters.
 * <b>Role</b>:
 * The splitter consists in an area split into two resizeable subareas by a sash that can be dragged along to resize,
 * decreasing one subarea while increasing the other. The split between the two subareas can be vertical or horizontal.
 * Each subarea can contain boxes and controls.
 * <br>
 * Use a splitter whenever you want to split an area into two resizable subareas.
 */
class ExportedByDI0PANV2 CATDlgSplitter : public CATDlgBox
{

 public:

				/** 
				 * Constructs a CATDlgSplitter.
				 * @param iParent
				 *   The parent of the splitter.
				 * @param iObjectName
				 *   The name of the splitter.
				 * @param iStyle
				 *   The style of the splitter.
				 * The style can be :
				 *   <dl>
				 *   <dt><tt>CATDlgCtrHorizontal</tt><dd> : the two subareas are horizontally aligned. The separator is then vertical.
				 *   <dt><tt>CATDlgCtrVertical</tt><dd> : the two subareas are vertically aligned. The separator is then horizontal.
				 *   <dt><tt>CATDlgSplResizeFirstPane</tt><dd> : the splitter shows the first subarea when first displayed.
				 *   </dl>
				 */
        CATDlgSplitter( CATDialog *iParent, const CATString& iObjectName, CATDlgStyle iStyle=NULL);

        virtual ~CATDlgSplitter();

        /**
         * Switches the splitter children.
         * The child that occupied the first subarea occupies the second one, and conversely,
         * the child that occupied the second subarea occupies the first one.
         */
        void SwitchChildren();

        /**
         * Retrieves the splitter position.
         * @param oPosition
         * The returned position.
         */
        void GetSashPosition ( double &oPosition );

        /**
         * Sets the splitter position.
         * @param iPosition
         * The position to set.
         */
        void SetSashPosition ( double iPosition );

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
        l_CATDlgSplitter* _frameSplitter;

        /** @nodoc */
        CATDlgSplitter_ADD
};

/** @nodoc */
CATDlgSplitter_LateADD

#endif
