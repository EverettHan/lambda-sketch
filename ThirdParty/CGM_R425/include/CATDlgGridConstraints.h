#ifndef CATDlgGridConstraints_h
#define CATDlgGridConstraints_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "DI0PANV2.h"

/**
 * @nodoc 
 */
#define CATGRID_LEFT       (1 << 1)
/**
 * @nodoc 
 */
#define CATGRID_RIGHT      (1 << 2)
/**
 * @nodoc 
 */
#define CATGRID_TOP        (1 << 3)
/**
 * @nodoc 
 */
#define CATGRID_BOTTOM     (1 << 4)
/**
 * @nodoc 
 */
#define CATGRID_4SIDES     (CATGRID_LEFT|CATGRID_RIGHT|CATGRID_TOP|CATGRID_BOTTOM)
/**
 * @nodoc 
 */
#define CATGRID_CST_WIDTH  (1 << 5)
/**
 * @nodoc 
 */
#define CATGRID_CST_HEIGHT (1 << 6)
/**
 * @nodoc 
 */
#define CATGRID_CST_SIZE   (CATGRID_CST_WIDTH|CATGRID_CST_HEIGHT)
/**
 * @nodoc 
 */
#define CATGRID_CENTER     (CATGRID_4SIDES|CATGRID_CST_SIZE)

/** 
 * Class to specify the layout constraints of a dialog object in its cell.
 * <b>Role</b>:
 * Grid constraints are dedicated to the grid layout. Each dialog object can 
 * be positioned thanks to a grid made of cells located at the intersections of
 * rows and columns.
 * <p>
 * The grid constraints instance assigned to a given dialog object determines 
 * the cell in which the top left corner of the dialog object lies, the number 
 * of rows  and columns on which the dialog object is spread, and the way the 
 * dialog object is attached to the cell sides, this determining its behavior 
 * when it, or its container, is resized. 
 */
class ExportedByDI0PANV2 CATDlgGridConstraints {

public:

/**
 * Constructs an empty CATDlgGridConstraints object. 
 */   
  CATDlgGridConstraints();

/**
 * Copy constructor. 
 * @param iCopy 
 *   The CATDlgGridConstraints to copy.
 */
  CATDlgGridConstraints(const CATDlgGridConstraints& iCopy);

/** 
 * Constructs a grid constraint for the dialog object using its top left anchor cell,
 * row and column extents, and justification.
 * @param iTopRow
 *   The initial row index under the upper left corner of the object.
 * @param iLeftColumn
 *   The initial column index under the upper left corner of the object.
 * @param iRowSpan
 *   The initial horizontal span (in number of columns) of the object. 
 * @param iColumnSpan
 *   The initial vertical span (in number of rows) of the object. 
 * @param iJustification
 *   The initial position of the object in its cell.
 *   <br>
 *   <b>Legal values</b> : It can be set to either :
 *   <dl>
 *   <dt><tt>CATGRID_LEFT</tt><dd> to attach the object to the left side of its cell,
 *   <dt><tt>CATGRID_RIGHT</tt><dd> to attach the object to the right side of its cell,
 *   <dt><tt>CATGRID_TOP</tt><dd> to attach the object to the upper side of its cell,
 *   <dt><tt>CATGRID_BOTTOM</tt><dd> to attach the object to the lower side of its cell,
 *   <dt><tt>CATGRID_4SIDES</tt><dd> to set the object size equal to the size of its cell,
 *   <dt><tt>CATGRID_CST_WIDTH</tt><dd> to keep the object width constant, independently of its cell width,
 *   <dt><tt>CATGRID_CST_HEIGHT</tt><dd> to keep the object height constant, independently of its cell height,
 *   <dt><tt>CATGRID_CST_SIZE</tt><dd> to keep the object size constant, independently of its cell size,
 *   <dt><tt>CATGRID_CENTER</tt><dd> to center the object.
 *   </dl>
 */
  CATDlgGridConstraints(short int iTopRow, short int iLeftColumn,
                        short int iRowSpan, short int iColumnSpan,
                        unsigned int iJustification);

/**
 * The column index under the top left corner of the dialog object.
 */
  short int Column;

/**
 * The row index under the top left corner of the dialog object.
 */
  short int Row;

/**
 * The horizontal span (in number of columns) of the dialog object. 
 */
  short int H_Span;

/**
 * The vertical span (in number of rows) of the dialog object. 
 */
  short int V_Span;

/**
 * The position of the object in its cell.
 *   <br>
 *   <b>Legal values</b> : It can be set to either :
 *   <dl>
 *   <dt><tt>CATGRID_LEFT</tt><dd> to attach the object to the left side of its cell,
 *   <dt><tt>CATGRID_RIGHT</tt><dd> to attach the object to the right side of its cell,
 *   <dt><tt>CATGRID_TOP</tt><dd> to attach the object to the upper side of its cell,
 *   <dt><tt>CATGRID_BOTTOM</tt><dd> to attach the object to the lower side of its cell,
 *   <dt><tt>CATGRID_4SIDES</tt><dd> to set the object size equal to the size of its cell,
 *   <dt><tt>CATGRID_CST_WIDTH</tt><dd> to keep the object width constant, independently of its cell width,
 *   <dt><tt>CATGRID_CST_HEIGHT</tt><dd> to keep the object height constant, independently of its cell height,
 *   <dt><tt>CATGRID_CST_SIZE</tt><dd> to keep the object size constant, independently of its cell size,
 *   <dt><tt>CATGRID_CENTER</tt><dd> to center the object.
 *   </dl>
 */
  unsigned int Justification;

};

#endif
