// COPYRIGHT DASSAULT SYSTEMES 2022
//=============================================================================
//
// CATTopIntersectByMultiBodies
//
//
//=============================================================================
//
// Usage notes: 
//
//
//=============================================================================
//  August 2022  CLO2 Creation													                            
//=============================================================================

#ifndef CATTopIntersectByMultiBodies_H
#define CATTopIntersectByMultiBodies_H

#include "CATThrowForNullPointer.h"
#include "ListPOfCATBody.h"
#include "CATTopMultiResult.h"
#include "CATMathInline.h"
#include "ExportedByPBELight.h"


class CATGeoFactory;
class CATTopData;
class CATExtTopIntersectByMultiBodies;
class CATBody;

class CATTopIntersectByMultiBodies : public CATTopMultiResult
{
  CATCGMVirtualDeclareClass(CATTopIntersectByMultiBodies);

  //-------------------------------------------------------
  //              Creation and destruction methods
  //-------------------------------------------------------
protected:

  /**
  * Constructor. Do not use.
  * Use <tt>Create()</tt> to create a <tt>CATTopIntersectByMultiBodies</tt>.
  *   @param ipFactory
  *     the pointer to the factory of the geometry.
  *   @param ipTopdata
  *     the pointer to the data defining the software configuration and the journal.
  *     If the journal inside the configuration is <tt>NULL</tt>, it is not filled.
  *   @param ipExtensible
  *     The pointer to the operator implementation.
  */
  CATTopIntersectByMultiBodies(CATGeoFactory* ipFactory, CATTopData* ipTopdata, CATExtTopIntersectByMultiBodies* ipExtensible);

public:

  /** @nodoc
  * cannot be called
  */
  // Please, call CATTopIntersectByMultiBodies() method to create an instance
  /** @nodoc @nocgmitf */
  static CATTopIntersectByMultiBodies* New(CATGeoFactory* ipFactory, CATTopData* ipTopdata, CATExtTopIntersectByMultiBodies* ipExtensible);


  /**
  * Destructor
  */
  virtual ~CATTopIntersectByMultiBodies();

protected:
  //-------------------------------------------------------
  //                   Internal methods
  //-------------------------------------------------------

  /**
  * Implementation
  *   @return a pointer to the operator implementation.
  */
  /** @nodoc @nocgmitf */
  INLINE CATExtTopIntersectByMultiBodies* GetExtTopIntersectByMultiBodies() const;

  /**
  * Run operator.
  */
  int RunOperator();

};

INLINE CATExtTopIntersectByMultiBodies* CATTopIntersectByMultiBodies::GetExtTopIntersectByMultiBodies() const
{
  if (!_Extensible)
    CATThrowForNullPointerReturnValue(NULL);
  return (CATExtTopIntersectByMultiBodies*)_Extensible;
}

/**
* External method that creates an instance of CATTopIntersectByMultiBodies.
*   @param ipFactory
*     the pointer to the factory of the geometry.
*   @param ipTopdata
*     the pointer to the data defining the software configuration and the journal.
*     If the journal inside the configuration is <tt>NULL</tt>, it is not filled.
*   @param iBodyToIntersect
*     1D (curve), 2D (surface)
*   @param iListOfIntersectingBodies
*     2D (surfaces) bodies to intersect with iBodyToIntersect
* The dimension of each result body will depend on the dimension of its 2 operands
* curve       by     surface       ->     point
* surf        by     surface       ->     curve
* =>   result dimension     =      iBodyToIntersect dimension – 1  
*/
ExportedByPBELight CATTopIntersectByMultiBodies* CATCreateTopIntersectByMultiBodies(CATGeoFactory* ipFactory, CATTopData* ipTopdata,
  CATBody* iBodyToIntersect, const ListPOfCATBody& iListOfIntersectingBodies);

#endif
