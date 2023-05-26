// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATVidLayGridConstraints.h
// Header definition of CATVidLayGridConstraints
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Oct 2005  Creation: Code generated by the CAA wizard  jov
//===================================================================
#ifndef CATVidLayGridConstraints_H
#define CATVidLayGridConstraints_H

#include "VisuDialog.h"
#include "CATVidLayConstraints.h"
#include "CATBoolean.h"
#include "CATUnicodeString.h"
#include "UIVCoreToolsInline.h"
//#include "CATSYPFactoryResult.h"


/**
 * This class is used to <b>specify placement properties of a cell relatively to the grid whom it is the child</b>.
 *
 * @par In CAPSYPStyle files
 * <p>%CATVidLayGridConstraints are used on the child of the grid to position them.<br>
 * CATVidLayGrid uses a %CATVidLayGridConstraints as an
 * <a href="http://codewiki/codewiki/index.php/VID_:_Introspection#AttachedProperty"><b>attached property</b></a>,
 * named <b>IndexedConstraints</b></p>
 * @code
 * <CATVidLayGrid ...........>
 *   <MyWidget ........... CATVidLayGrid.IndexedConstraints="x=3 y=1 xSpan=2 ySpan=2 attach=RLTB" />
 * </CATVidLayGrid>
 * @endcode
 *
 * <p> @c xSpan, @c ySpan, @c attach are facultative<br>
 * @c attach= allows to specify the attachements you want.<br>
 * Ex : @c attach=RT will attach at top and right sides.<br>
 * The style processor will then create a %CATVidLayGridConstraints and set it on the grid : 
 * @code
 * // For the above example :
 * CATVidLayGridConstraints(3, 1, 2, 2, TRUE, TRUE, TRUE, TRUE)
 * @endcode
 * 
 * @see CATVidLayGrid
 * @see <a href="http://codewiki/codewiki/index.php/VID_:_Style_Processor"><b>CodeWiki -> Style processor</b></a>
 * @ingroup VIDLayout
 */
class ExportedByVisuDialog CATVidLayGridConstraints: public CATVidLayConstraints
{
  CATDeclareClass;

public:
  /**
  * Increments the reference count for the given interface. 
  * @return The reference count value.
  * <br>This information is meant to be used for diagnostic/testing purposes only, because, in certain situations, the value may be unstable.
  */
  virtual ULONG   __stdcall AddRef();
  /**
  * Decrements the reference count for the given interface. 
  * @return The reference count value.
  * <br>This information is meant to be used for diagnostic/testing purposes only, because, in certain situations, the value may be unstable.
  */
  virtual ULONG   __stdcall Release();
  /**
  * Standard constructor
  */
  CATVidLayGridConstraints ();
  /**
  * Constructor and intialization of all constraints properties of a cell.
  * @see SetPosition
  * @see SetSpan
  * @see SetAttachmentFlags
  */
  CATVidLayGridConstraints (int i_x, int i_y , int i_xSpan, int i_ySpan ,CATBoolean i_leftAttachFlag, CATBoolean i_rightAttachFlag, CATBoolean i_topAttachFlag, CATBoolean i_bottomAttachFlag);
  /**
  * Standard destructor
  */
  virtual ~CATVidLayGridConstraints ();
  /**
  * Clone function
  */
  virtual CATVidLayConstraints* Clone() const; 
  /**
  * @nodoc
  */
  virtual CATBoolean IsEqualTo(const CATVidLayConstraints& i_constraints) const;
  /**
   * Copy the given constraints values.
   */
  virtual void CopyFrom(const CATVidLayConstraints& i_constraints);
  /**
  * Copy constructor
  */
  CATVidLayGridConstraints (const CATVidLayGridConstraints & i_original);
  CATVidLayGridConstraints& operator=(const CATVidLayGridConstraints& i_original);
  /**
  * Sets the position of the cell in the grid.
  * @param i_x the index of the column (starting at 0)
  * @param i_y the index of the row (starting at 0)
  */
  void SetPosition(int i_x, int i_y);
  /**
  * Retrieves the position of the cell in the grid.
  * @param o_x the index of the column (starting at 0)
  * @param o_y the index of the row (starting at 0)
  */
  INLINE void GetPosition(int& o_x, int& o_y) const
  {
    o_x = _x;
    o_y = _y;
  }
  /**
   * Returns the index of the column (starting at 0)
   */
  INLINE int GetX() const {return _x;}
  /**
   * Returns the index of the row (starting at 0)
   */
  INLINE int GetY() const {return _y;}
  /**
  * Sets the span of the cell inside the grid, i.e. on how much columns/rows it will expand.
  * Default is 1 : single cell.<br/>
  * Beware of conflicts when spanning on existant cells.
  * If you want complex layouts, it can be better to place a new grid inside a cell,
  * to simplify the comprehension of the layout.
  * @param i_xSpan the span on columns (horizontal)
  * @param i_ySpan the span on rows (vertical)
  */
  void SetSpan(int i_xSpan, int i_ySpan);
  /**
  * Sets the span of the cell inside the grid, i.e. on how much columns/rows it will expand.
  * Default is 1 : single cell.
  * @param o_xSpan the span on columns (horizontal)
  * @param o_ySpan the span on rows (vertical)
  */
  void GetSpan(int& o_xSpan, int& o_ySpan) const;
  /**
   * Returns the span on columns (horizontal)
   */
  INLINE int GetXSpan() const {return _xSpan;}
  /**
   * Returns the span on rows (vertical)
   */
  INLINE int GetYSpan() const {return _ySpan;}
  /** Sets attachment flag of the content of the cell.
  * Defines how the widget will be attach in its cell.<br>
  * A widget in a grid takes the full siez of the cell it is in <b>if and only if</b> it si attached on four sides.<br>
  * If it's attached left and right, it will be streched horzontally.<br>
  * If it's attached top and bottom, it will be streched vertically.<br>
  * If it's attached neither left nor right, it will be located in the middle width of the cell.<br>
  * If it's attached neither top nor bottom, it will be located in the middle height of the cell.<br>
  * @param i_leftAttachFlag attachement of the content of the cell to the left side of the cell.
  * @param i_rightAttachFlag attachement of the content of the cell to the right side of the cell.
  * @param i_topAttachFlag attachement of the content of the cell to the top of the cell.
  * @param i_bottomAttachFlag attachement of the content of the cell to the bottom of the cell.
  */
  void SetAttachmentFlags(CATBoolean i_leftAttachFlag, CATBoolean i_rightAttachFlag, CATBoolean i_topAttachFlag, CATBoolean i_bottomAttachFlag);
  /**
  * @param i_leftAttachFlag attachement of the content of the cell to the left side of the cell.
  * @param i_rightAttachFlag attachement of the content of the cell to the right side of the cell.
  * @param i_topAttachFlag attachement of the content of the cell to the top of the cell.
  * @param i_bottomAttachFlag attachement of the content of the cell to the bottom of the cell.
  * @see SetAttachmentFlags
  */
  void GetAttachmentFlags(CATBoolean& o_leftAttachFlag, CATBoolean& o_rightAttachFlag, CATBoolean& o_topAttachFlag, CATBoolean& o_bottomAttachFlag) const;

  /**
   * Returns TRUE if the grid constraints contains the given cell, FALSE otherwise.
   */
  CATBoolean ContainsCell(int i_x, int i_y) const;

private:
  int _x, _y;
  int _xSpan, _ySpan;

  CATBoolean _leftAttachFlag;
  CATBoolean _rightAttachFlag;
  CATBoolean _topAttachFlag;
  CATBoolean _bottomAttachFlag;
  friend inline int operator == (const CATVidLayGridConstraints &i_constaints1, const CATVidLayGridConstraints &i_constaints2);
};

//-----------------------------------------------------------------------
#ifndef VID_DEPRECATED
#define CATVidGridConstraints CATVidLayGridConstraints
#endif

extern "C" ExportedByVisuDialog 
HRESULT CATSYPCATVidLayGridConstraintsSerializer(const CATBaseUnknown_var& i_spCBU, CATUnicodeString& o_string);

inline int operator == (const CATVidLayGridConstraints &i_constaints1, const CATVidLayGridConstraints &i_constaints2)
{
  return (i_constaints1._x == i_constaints2._x && i_constaints1._y == i_constaints2._y && i_constaints1._xSpan == i_constaints2._xSpan && i_constaints1._ySpan == i_constaints2._ySpan && 
    i_constaints1._leftAttachFlag == i_constaints2._leftAttachFlag && i_constaints1._rightAttachFlag == i_constaints2._rightAttachFlag && 
    i_constaints1._topAttachFlag == i_constaints2._topAttachFlag && i_constaints1._bottomAttachFlag == i_constaints2._bottomAttachFlag); 
}

#endif