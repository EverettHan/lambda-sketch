/* -*-C++-*-*/
#ifndef CATSmartDuplicateImplicitBodyTopOper_H
#define CATSmartDuplicateImplicitBodyTopOper_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2021
//
// CATSmartDuplicateImplicitBodyTopOper
//
// DESCRIPTION:
// Operator that generate a lattice structure within specified
// immersed cavity.
//
//
// History
//
// Nov. 2021 WZC Creation
//=============================================================================

#include "GMScalarFieldsOperators.h"

#include "CATImplicitTopOperator.h" // derivation
#include "CATErrorDef.h"

// STD
#include <list>

// Fuzzy
#include "CATVRepType.h"

class CATFace;
class CATGeoFactory;
class CATTopData;
class CATBody;

/**
* Class defining an operator that creates an approximate rolling-ball offset of a polyhedral body
* <ul>
*     <li> A <tt>CATICGMPolyhedralRoughOffset</tt> operator is created with the <tt>CATCGMCreatePolyhedralRoughOffset</tt> global function.
*     <li> It is the user's responsibility to release the operator after it has been used.
*     <li> The results are retrieved by the <tt>Get</tt> methods.
* </ul>
*/
class ExportedByGMScalarFieldsOperators CATSmartDuplicateImplicitBodyTopOper : public CATImplicitTopOperator
{
  CATCGMVirtualDeclareClass(CATSmartDuplicateImplicitBodyTopOper);

public:

  /**
  * Destructor
  */
  virtual ~CATSmartDuplicateImplicitBodyTopOper();


  //=============================================================================
  // Settings
  //=============================================================================

  //=============================================================================
  // Get additional information after Run
  //=============================================================================

protected:

  /*
  * @nodoc
  * @nocgmitf
  * cannot be called, constructor for derived classes only
  */
  CATSmartDuplicateImplicitBodyTopOper(CATGeoFactory & iFactory, const CATTopData & iTopData, CATImplicitOperTopExt &iExtensible);

private:

  //===========================================================================
  // COPY-CONSTRUCTOR et OPERATOR =   Not DEFINED
  //===========================================================================
  
  CATSmartDuplicateImplicitBodyTopOper();
  CATSmartDuplicateImplicitBodyTopOper(const CATSmartDuplicateImplicitBodyTopOper& iOneOf);
  CATSmartDuplicateImplicitBodyTopOper& operator =(const CATSmartDuplicateImplicitBodyTopOper& iOneOf);
};

/**
 * Creates a CATSmartDuplicateImplicitBodyTopOper operator
 * @param iFactory
 * The factory of the geometry. 
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
 * is <tt>NULL</tt>, it is not filled. 
 * @param iBodyWithCavityToLattice
 * The pointer to the 2D body to offset (under progress, not yet available) or the 3D body to thick
 * @return [out, IUnknown#Release]
 * The pointer to the created operator. To be released with the <tt>Release</tt> method after use.
 */
ExportedByGMScalarFieldsOperators CATSmartDuplicateImplicitBodyTopOper * CATCreateSmartDuplicateImplicitBodyTopOper(CATGeoFactory * iFactory, CATTopData * iTopData, CATBody * iBodyWithCavityToLattice);

#endif /* CATSmartDuplicateImplicitBodyTopOper_H */
