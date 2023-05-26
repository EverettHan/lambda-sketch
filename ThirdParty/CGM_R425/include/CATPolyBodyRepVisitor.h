// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyRepVisitor.h
//
//===================================================================
// November 2009  Creation: NDO
//===================================================================
#ifndef CATPolyBodyRepVisitor_H
#define CATPolyBodyRepVisitor_H

#include "PolyVizAdapters.h"
#include "CATErrorDef.h"
#include "CATPolyVisServices.h"

class CATPolyBody;
class CATRep;


/**
 * DEPRECATED
 * @see CATPolyVisServices.h
 * Use CATPolyGetRep ()
 */
class ExportedByPolyVizAdapters CATPolyBodyRepVisitor /* : public CATPolyBodyConstVisitor */
{

public:

  CATPolyBodyRepVisitor () {}
  ~CATPolyBodyRepVisitor () {}

public:

/**
 * Returns a CATRep that is associated to the CATPolyBody.
 * @param iPolyBody
 *   The input CATPolyBody.
 * @param oRep
 *   A pointer to a CATRep. 
 * @return
 * <ul>
 *   <tt>S_OK</tt> if a CATRep is returned.
 *   <tt>S_FALSE</tt> if there is no CATRep associated to the CATPolyBody.
 *   <tt>E_FAIL</tt> or another error code if an error occurs.
 * </ul>
 * @see CATPolyVisServices.h
 */
  inline HRESULT GetRep (const CATPolyBody& iBody, CATRep*& oRep);

};


inline HRESULT CATPolyBodyRepVisitor::GetRep (const CATPolyBody& iBody, CATRep*& oRep)
{
  return CATPolyGetRep (iBody, oRep);
}

#endif // !CATPolyBodyRepVisitor_H
