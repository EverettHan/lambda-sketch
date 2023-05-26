#ifndef CATDlgIndexedConstraints_H
#define CATDlgIndexedConstraints_H

#include "DialogAPILevel.h"

#ifdef DialogAPI_DECLARATIVE_DIALOG_SUPPORT

#include "DI0PANV2.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATDlgGridConstraints.h"
#include <CATSYPFactoryResult.h>
#include <CATBasicTypeFactory.h>

extern "C" ExportedByDI0PANV2
  CATSYPFactoryResult CATSYPCATDlgIndexedConstraintsFactory(const CATUnicodeString& i_string);
extern "C" ExportedByDI0PANV2
  HRESULT CATSYPCATDlgIndexedConstraintsSerializer(const CATBaseUnknown_var& i_spCBU, CATUnicodeString& o_string);

/**
 * This class defines instrospectable grid constraints for 
 * layouting Dialog objects inside a collection in a declarative file.
 * It is used as an attached property in Dialog Collections. Factory and serializer functions 
 * are also defined in this file, next to the CATDlgIndexedConstraints implementation.
 * The following attributes can be used for this type inside a serialized string : Row, Column, xSpan, ySpan, Justification
 * Required attributes : Row, Column
 *    Example : 
 *    <CATDlgPushButton CATDlgFrame.IndexedConstraints="Row=0 Column=1 xSpan=1 ySpan=2 Justification=4Sides"/>
*/

class ExportedByDI0PANV2 CATDlgIndexedConstraints : public CATBaseUnknown
{
CATDeclareClass;

public:

  /** Constructor */
  CATDlgIndexedConstraints ();

  /** Constructor
   * A CATDlgIndexedConstraints instance on the basis of a CATDlgGridConstraints
   * @param i_GC is the CATDlgGridConstraints to import.
   */
  CATDlgIndexedConstraints(const CATDlgGridConstraints & GC);

  /** Constructor
   * @param i_row is the objects's row in the grid
   * @param i_column is the objects's column in the grid
   * @param i_xSpan is the horizontal span
   * @param i_ySpan is the vertical span
   * @param i_justification  The initial position of the object in its cell.
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
   */
  CATDlgIndexedConstraints(int i_row,int i_column,int i_xSpan,int i_ySpan, int i_justification);

  /** Destructor */
  virtual ~CATDlgIndexedConstraints ();

  /** 
   * Simple conversion method, from a CATDlgGridConstraints to a CATDlgIndexedConstraints.
   * @param i_GC is the CATDlgGridConstraints to import.
   */
  void Import(const CATDlgGridConstraints & i_GC);

  /** 
   * Simple conversion method, from a CATDlgIndexedConstraints to a CATDlgGridConstraints.
   * @return a CATDlgGridConstraints export.
   */
  const CATDlgGridConstraints Export();

  /** 
   * Sets the position.
   * @param i_row is the row.
   * @param i_column is the column.
   */
  void SetPosition(int i_row,int i_column);

  /** 
   * Sets the span.
   * @param i_xSpan is the horizontal span
   * @param i_ySpan is the vertical span
   */
  void SetSpan(int i_xSpan,int i_ySpan);

  /** 
   * Sets the initial position of the object in its cell.
   * @param i_justification  The initial position of the object in its cell.
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
   */
  void SetJustification(unsigned int i_justification);

  /** 
   * Get the row.
   * @return the objects's row in the grid
   */
  int GetRow();

  /** 
   * Get the column.
   * @return the objects's column in the grid
   */
  int GetColumn();

  /** 
   * Get the horizontal span.
   * @return the object's horizontal span.
   */
  int GetxSpan();

  /** 
   * Get the vertical span.
   * @return the object's vertical span.
   */
  int GetySpan();

  /** 
   * Get the justification.
   * @return the initial position of the object in its cell.
   */
  unsigned int GetJustification();

private: 

  CATDlgGridConstraints _GC;
  int _row;
  int _column;
  int _xSpan;
  int _ySpan;
  unsigned int _justification;

};

#endif

#endif
