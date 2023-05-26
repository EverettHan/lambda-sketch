// COPYRIGHT DASSAULT SYSTEMES 2011, ALL RIGHTS RESERVED.
//===================================================================
//
// CATExactCellId
//
//===================================================================
// 2011-03-25   JXO
//      * New
//===================================================================
#ifndef CATExactCellId_H
#define CATExactCellId_H

// Poly
#include "BVHTools.h"     // ExportedBy
#include "CATCellId.h"

// Math
class CATCell;
class CATFace;
class CATEdge;
class CATVertex;

/**
 * This defines an id for cells in a CATBody.
 */

/** @nodoc @nocgmitf (do not create any specific interface) */
class ExportedByBVHTools CATExactCellId : public CATCellId
{
public:
  /**
   * Constructor.
   */
  CATExactCellId (CATCell & cell);

public:
  /**
   * Cast to priviledged type: const CATExactCellId.
   */
  const CATExactCellId * CastAsExactCellId() const{return this;}
  /**
   * Cast to priviledged type: const CATExactCellId.
   */
  CATExactCellId * CastAsExactCellId(){return this;}

  /**
   * Return CATCell pointed by this id.
   */
  CATCell & GetCell();

  /**
   * Return CATFace pointed by this id.
   */
  CATFace * GetFace();
  /**
   * Return CATEdge pointed by this id.
   */
  CATEdge * GetEdge();
  /**
   * Return CATVertex pointed by this id.
   */
  CATVertex * GetVertex();


  CATPolyCellId * CastAsPolyCellId(){return 0;}
  const CATPolyCellId * CastAsPolyCellId() const{return 0;}

  /**
   * Check wether this id is equal to another id.
   */
  virtual CATBoolean operator == (CATCellId & id){return id.IsEqualTo(*this);}
  virtual CATBoolean IsEqualTo(CATExactCellId & eid){return (&m_cell == &eid.m_cell);}

protected:
  ~CATExactCellId();

private:
  CATCell & m_cell;

};



#endif

