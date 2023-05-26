/* -*-C++-*-*/
#ifndef CATCreateLatticeNBTopOper_H
#define CATCreateLatticeNBTopOper_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2021
//
// CATCreateLatticeNBTopOper
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

#include "DSYString.h"
#include "CATErrorDef.h"

// STD
#include <list>

// Fuzzy
#include "CATVRepType.h"

// Lattice
#include "LatticeNBModel.h"

// ScalarFields
#include "SFTypes.h"
#include "ScalarFieldsOperatorsCommon.h"

class CATFace;
class CATGeoFactory;
class CATTopData;
class CATBody;
class CATVolume;

/**
* Class defining an operator that put implicit specifications for a bar graph lattice on the specified volume,
* with the provided LatticeNBModel (the bar graph that was previously given to old Lattice APIs in LatticeGMOperaots
* (i.e the bar graph might need to be trimmed previously)
* <ul>
*     <li> A <tt>CATCreateLatticeNBTopOper</tt> operator is created with the <tt>CATCreateCreateLatticeNBTopOper</tt> global function.
*     <li> It is the user's responsibility to release the operator after it has been used.
*     <li> The results are retrieved by the <tt>Get</tt> methods.
* </ul>
*/
class ExportedByGMScalarFieldsOperators CATCreateLatticeNBTopOper : public CATImplicitTopOperator
{
  CATCGMVirtualDeclareClass(CATCreateLatticeNBTopOper);

public:

  /**
  * Destructor
  */
  virtual ~CATCreateLatticeNBTopOper();


  //=============================================================================
  // Settings
  //=============================================================================

  /**
  * Volume to which attach implicit specs.
  * @param a CATVolume specifying the cavity to which we need to attach specs.
  */
  virtual void SetVolume(CATVolume* iCavityVolume) = 0;

  /**
  * The whole bar graph(not just a unit cell) for the lattice you want to create.
  * It should already be trimmed to fit cavity.
  * By passing a latticeNBModel you transfer it's ownership, don't delete or
  * release it on your side.
  * @param iLatticeNBModel a LatticeNBModel specifying the bars of the lattice 
  */
  virtual void SetLatticeNBModel(SF::LatticeNBModelPtr iLatticeNBModel) = 0;

  //=============================================================================
  // Get additional information after Run
  //=============================================================================

protected:

  /*
  * @nodoc
  * @nocgmitf
  * cannot be called, constructor for derived classes only
  */
  CATCreateLatticeNBTopOper(CATGeoFactory & iFactory, const CATTopData & iTopData, CATImplicitOperTopExt &iExtensible);

private:

  //===========================================================================
  // COPY-CONSTRUCTOR et OPERATOR =   Not DEFINED
  //===========================================================================
  
  CATCreateLatticeNBTopOper();
  CATCreateLatticeNBTopOper(const CATCreateLatticeNBTopOper& iOneOf);
  CATCreateLatticeNBTopOper& operator =(const CATCreateLatticeNBTopOper& iOneOf);
};

/**
 * Creates a CATCreateLatticeNBTopOper operator
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
ExportedByGMScalarFieldsOperators CATCreateLatticeNBTopOper * CATCreateCreateLatticeNBTopOper(CATGeoFactory * iFactory, CATTopData * iTopData, CATBody * iInputBody);

#endif /* CATCreateLatticeNBTopOper_H */
