/* -*-C++-*-*/
#ifndef CATCloneImplicitBodyTopOper_H
#define CATCloneImplicitBodyTopOper_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2021
//
// CATCloneImplicitBodyTopOper
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
* Class defining an operator that clone a body with implicit body information attached to it.
* Journal is written in Modification mode (see the clone manager itself for more on this).
* Please check CATSmartDuplicateImplicitBodyTopOper instead which is used everywhere, refrain
* from using this operator unless you are sure the smart duplicate doesn't do what you want
* and you are familiar with when you should really use the CATCloneManager instead and this operator
* for bodies that would have implicit specs attached.
* <ul>
*     <li> A <tt>CATCloneImplicitBodyTopOper</tt> operator is created with the <tt>CATCreateCloneImplicitBodyTopOper</tt> global function.
*     <li> It is the user's responsibility to release the operator after it has been used.
*     <li> The results are retrieved by the <tt>Get</tt> methods.
* </ul>
*/
class ExportedByGMScalarFieldsOperators CATCloneImplicitBodyTopOper : public CATImplicitTopOperator
{
  CATCGMVirtualDeclareClass(CATCloneImplicitBodyTopOper);

public:

  /**
  * Destructor
  */
  virtual ~CATCloneImplicitBodyTopOper();


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
  CATCloneImplicitBodyTopOper(CATGeoFactory & iFactory, const CATTopData & iTopData, CATImplicitOperTopExt &iExtensible);

private:

  //===========================================================================
  // COPY-CONSTRUCTOR et OPERATOR =   Not DEFINED
  //===========================================================================
  
  CATCloneImplicitBodyTopOper();
  CATCloneImplicitBodyTopOper(const CATCloneImplicitBodyTopOper& iOneOf);
  CATCloneImplicitBodyTopOper& operator =(const CATCloneImplicitBodyTopOper& iOneOf);
};

/**
 * Creates a CATCloneImplicitBodyTopOper operator
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
ExportedByGMScalarFieldsOperators CATCloneImplicitBodyTopOper * CATCreateCloneImplicitBodyTopOper(CATGeoFactory * iFactory, CATTopData * iTopData, CATBody * iBodyWithCavityToLattice);

#endif /* CATCloneImplicitBodyTopOper_H */
