/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 1999
//
//==============================================================================
// Inheritance
// -----------
// CATBodyIdentificators
//    
//
//==============================================================================
// Abstract
// --------
// Store the body's sub-element identificators
//
//==============================================================================
// Usage
// -----
//  For a Normal Body :
//  -----------------
//
//  Each CATIdentType represents a type of elements the body
//  For each CATIdentType we have a list of ident
//  For each CATIdentType there is a list of GP in the CATSurfacicRep
//  the rang in the GP list is the same as in the Ident list
//
//  For the BodySimple : 
//  ------------------
//
//  we use the CATInfiniteFaceIdent or the CATFreePointIdent 
//  the rang (=0) is the first GP of the CAT3DCustomRep
//
//
//  The order in the enum CATIdentType is important : it's the same 
//  as the ordre of sub-elt indices in the CATSurfacicRep::DrawShading 
//  This analogy allows to simplify the code of GetIndex and GetIdent
//  methods. 
//
//  the ident stored is an implementation,but in the method you give
//  object by there interface
//
//     AddIdent      : nouvel elt dans la liste demandee
//     GetIdentCount : nombre d'elt dans la liste demandee
//     GetIdent      : identificateur a partir de son numero d'ordre 
//     GetIndex      : numero d'ordre d'un ident 

//==============================================================================
// History
// -------
//     - ??? ??, ????: Created.
//==============================================================================
#ifndef CATBodyIdentificators_H
#define CATBodyIdentificators_H

#include "CATIdentType.h"
#include "CATBaseUnknown.h"

#include "CATVisItf.h"

class CATVisHashTable;

/**
 * Class to keep a link between the topological cells of a CATCXBody
 * and their graphic primitive.
 * <b>Role</b>: This class manages 12 lists of pointers to topological cells. Each list
 * corresponds to a specific sub-type :
 * <ol>
 * <li> face</li>
 * <li> boundary edge : edge that is neighbor to one and only one face </li>
 * <li> internal sharp edge : edge that is neighbor to two or more faces, with C1 continuity </li>
 * <li> internal smooth edge : edge that is neighbor to two or more faces, with C2 continuity </li>
 * <li> boundary point : extremity of a wire edge </li>
 * <li> internal sharp point : internal point of a wire edge, with C1 continuity </li>
 * <li> internal smooth point : internal point od a wire edge, with C2 continuity </li>
 * <li> surfacic point : point that is indirectly neighbor to a face </li>
 * <li> free point : point that has no neighboring edge or face </li>
 * <li> wire edge : edge that has no neighboring face </li>
 * <li> infinite face : infinite face neighborto four edges and fours points </li>
 * <li> isopars : set of edges associated to a face </li>
 * </ol>
 * This class is closely associated to the CATSurfacicRep. Each one of the previous lists
 * corresponds to a list of graphic primitives managed by the CATSurfacicRep. The order
 * in each pair of lists is important, as it allows to make the link between a cell and
 * its graphic primitive.
 */

class ExportedByCATVisItf CATBodyIdentificators
{
public:

  // 'tors
  /** @nodoc */
  virtual ~CATBodyIdentificators();

  /** Constructs an empty CATBodyIdentificators. */
  CATBodyIdentificators();

  /** Empties all the managed lists. */
  virtual void Empty();

  /** Returns the number of cells in given list.
   * @param iType
   * list identificator.
   */
  virtual int GetIdentCount(CATIdentType iType) const;

  /** Appends <tt>iIdent</tt> (pointer to a cell) to the list <tt>iType</tt>.
   * It is up to the user to decide in which list to place the cell.
   * @param iType
   * sub-type of cell (list identificator)
   * @param iCell
   * topological cell to be added (if NULL, return 0)
   * @return
   * 1 of OK, 0 if KO.
   */
  virtual int AddIdent(CATIdentType iType, CATBaseUnknown * iCell);

  /** Returns a cell from a specified list.
   * @param iType
   * list identificator.
   * @param iIndex
   * index of cell in list.
   * If index is out of bounds, NULL is returned.
   */
  virtual CATBaseUnknown * GetIdent(CATIdentType iType, const int iIndex) const;

  /** Returns a cell.
   * @param iIndex
   * This index global to all the lists, as if they were put together end-to-end.
   * If index is out of bounds, NULL is returned.
   */
  virtual CATBaseUnknown * GetIdent(const int iIndex) const;

  /** Returns the index of a cell in a specified list
   * @param iType
   * sub-type of cell (list identificator)
   * @param iCell
   * cell for which we search the index.
   * If the cell is not in the list, -1 is returned.
   */
  virtual int GetIndex(CATIdentType iType,CATBaseUnknown * iCell) const;

  /** Returns the global index of a cell
   * @param iCell
   * cell for which we search the global index.
   * If the cell is not in any of the lists, -1 is returned.
   * For a face, which can appear in the list of faces and the list of isopars, the index of
   * the list of faces is returned.
   */
  virtual int GetIndex(CATBaseUnknown * iCell) const;

  /** @nodoc */
  virtual int GetEdgeIndex(CATBaseUnknown * iCell) const;

};

#endif // CATBodyIdentificators_H






