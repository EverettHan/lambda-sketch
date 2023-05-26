
// COPYRIGHT DASSAULT SYSTEMES 2011, ALL RIGHTS RESERVED.
//===================================================================
//
// CATTessBVHAttribute
//
//===================================================================
// 2011-03-15   DPS
//      * New
// 2018-02-08 JXO: Monocell for IR 574664
//===================================================================

#ifndef CATTessBVHAttribute_H
#define CATTessBVHAttribute_H

#include "BVHTools.h"     // ExportedBy

#include "CATPolyBVHAttribute.h"
#include "CATPolyPool.h"
#include <stddef.h>

#include "CATDataType.h"
#include "CATSysBoolean.h"


class CATCGMTessBody;
class CATFace;
class CATEdge;
class CATTessBodyBVHAttribute;
class CATCell;

/**
 * This defines a CATCGMTessBody attribute (with an optional position) to a CATBVHNode.
 * It implements @CATPolyBVHAttribute.
 * You can set a Body and Position.
 * Bonus: if the input Body has only one face it can also return it.
 */

/** @nodoc @nocgmitf (do not create any specific interface) */
class ExportedByBVHTools CATTessBVHAttribute : public CATPolyBVHAttribute
{
  CATPolyDeclarePooledNew;

public:

  virtual ~CATTessBVHAttribute();

  CATTessBVHAttribute* CastAsTessAttribute ();
  const CATTessBVHAttribute* CastAsTessAttribute () const;


  virtual CATULONG32 GetCGMTag() const=0;
  virtual CATTessBodyBVHAttribute * GetRootTessBVHAttribute() const=0;


  // Default implementations
  // -----------------------

  virtual CATBoolean HasTessBody() const;
  virtual CATBoolean HasFace() const;
  virtual CATBoolean HasEdge() const;

  virtual CATCGMTessBody * GetTessBody() const;
  virtual CATFace * GetFace() const;
  virtual CATEdge * GetEdge() const;

  // JXO for IR 574664
  virtual CATCell * GetMonoCell() {return 0;}
  virtual void SetMonoCell(CATCell * iCell) {}

protected :

  CATTessBVHAttribute();
};


#endif

