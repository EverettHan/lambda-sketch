// COPYRIGHT DASSAULT SYSTEMES 2014, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyAssemblyPPFilterBox.h
//
//===================================================================
//
// Usage notes: Filter that restrains the scope of valid
// configurations into a box.
//
//===================================================================
//
// 2014-11-14 XXC: Creation
// 2015-12-07 JXO: CATPolyOBB
//===================================================================

#ifndef CATPolyAssemblyPPFilterBox_HH
#define CATPolyAssemblyPPFilterBox_HH

#include "PolyBodyBVHOperators.h"

// Poly
#include "CATPolyOBB.h"

// Math
#include "CATPolyPPConfigurationFilter.h"
#include "CATBoolean.h"
#include "CATMathPoint.h"
#include "CATMathBox.h"
#include "CATMathTransformation.h"

/** 
 * Class defining the Configuration Filter interface for the box shaped filter.
 *  Allows to restrain the scope of valid configurations inside a box.
 * The anchor point should be a point inside the moving object (the center of rotation for example).
 * For each possible configuration, it will be multiplied by the corresponding position matrix, and
 * tested against the box (that should be described in the world referential)
 * 
 * @remarks : The Filter is exact on the box size if you want some tolerance use the CATMathBox::Inflate method:
 * @code
 *  CATMathBox BoxWitTolerance = GetUserBoxFilter(); // here it is the exact box
 *  BoxWitTolerance.inflate(wantedTolerance); // now the box is bigger of the tolerance
 *  CATPolyAssemblyPPFilterBox filter(anchor, BoxWitTolerance);
 * @endcode
 */
class ExportedByPolyBodyBVHOperators CATPolyAssemblyPPFilterBox : public CATPolyPPConfigurationFilter
{
 public:
  /** Constructs a filter from an axis aligned box */
  CATPolyAssemblyPPFilterBox(const CATMathPoint & iAnchor, const CATMathBox & iBox);
  /** Constructs a filter from an oriented box */
  CATPolyAssemblyPPFilterBox(const CATMathPoint & iAnchor, const CATPolyOBB & iBox);

  CATPolyAssemblyPPFilterBox( const CATPolyAssemblyPPFilterBox& iOther );

  virtual ~CATPolyAssemblyPPFilterBox() {}

  virtual CATBoolean Filter(const CATMathTransformation & iPosition);

  const CATPolyOBB & GetBox() const;

  const CATMathPoint & GetAnchor() const;

  /**
   *	@todo TO BE CHANGED INTO VIRTUAL PURE
   */
  virtual CATPolyAssemblyPPFilterBox* Clone() const;

  FilterTypeEnum GetType() const override;

 private:
  CATMathPoint _Anchor;
  CATPolyOBB _Box;

};

#endif
