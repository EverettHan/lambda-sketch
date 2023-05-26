/* -*-C++-*-*/
#ifndef CATSmartImplicitBodyFusionTopOper_H
#define CATSmartImplicitBodyFusionTopOper_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2021
//
// CATSmartImplicitBodyFusionTopOper
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

// CGM
#include "ListPOfCATBody.h"
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
class ExportedByGMScalarFieldsOperators CATSmartImplicitBodyFusionTopOper : public CATImplicitTopOperator
{
  CATCGMVirtualDeclareClass(CATSmartImplicitBodyFusionTopOper);

public:

  /**
  * Destructor
  */
  virtual ~CATSmartImplicitBodyFusionTopOper();


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
  CATSmartImplicitBodyFusionTopOper(CATGeoFactory & iFactory, const CATTopData & iTopData, CATImplicitOperTopExt &iExtensible);

private:

  //===========================================================================
  // COPY-CONSTRUCTOR et OPERATOR =   Not DEFINED
  //===========================================================================
  
  CATSmartImplicitBodyFusionTopOper();
  CATSmartImplicitBodyFusionTopOper(const CATSmartImplicitBodyFusionTopOper& iOneOf);
  CATSmartImplicitBodyFusionTopOper& operator =(const CATSmartImplicitBodyFusionTopOper& iOneOf);
};

// ----------------------------------------------------------------------------------------------------------------------
/**
 * Creates a CATSmartImplicitBodyFusionTopOper operator
 * @param iFactory
 * The factory of the geometry.
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt>
 * is <tt>NULL</tt>, it is not filled.
 * @param iInputBodies
 * List of CATBody* to be processed
 * @return [out, IUnknown#Release]
 * The pointer to the created operator. To be released with the <tt>Release</tt> method after use.
 */
 // ----------------------------------------------------------------------------------------------------------------------
ExportedByGMScalarFieldsOperators CATSmartImplicitBodyFusionTopOper* CATCreateSmartImplicitBodyFusionTopOper(CATGeoFactory* iFactory,
  CATTopData* iTopData,
  const ListPOfCATBody& iInputBodies);


#endif /* CATSmartImplicitBodyFusionTopOper_H */
