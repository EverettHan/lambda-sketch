/* -*-C++-*-*/
#ifndef CATGMPolyExtractCellsTopOper_H
#define CATGMPolyExtractCellsTopOper_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2016
//
// CATGMPolyExtractCellsTopOper
//
// DESCRIPTION :
// Class defining the operator that computes a new CATBody from a subset of cells (with a common dimension)
// This operator allows two ways to define Domains : adding Cells or removing Cells from an initial body.
// This operator follows the general frame of all operators and satisfies to the smart mechanism: 
// the input bodies are not modified. A new resulting body is created, sharing Cells with the input bodies.
//
//
// History
//
// April. 2016 DPS Creation
//
//=============================================================================

// For Windows NT export
#include "CATGMPolyTopOperator.h" // derivation
#include "GMPolyBasicOper.h"      // ExportedBy

#include "CATCollec.h"
#include "ListPOfCATCell.h"
#include "CATListOfInt.h"

#include "CATDataType.h"        // HRESULT
#include "CATMathInline.h"      // inline Methods
#include "CATHybDef.h"          // define CATHybPropagateMode


class CATGeoFactory;
class CATTopData;
class CATBody;
class CATDomain;
class CATCell;
class CATGMPolyExtractCellsTopExt;


/** @nodoc @nocgmitf (do not create any specific interface) */
class ExportedByGMPolyBasicOper CATGMPolyExtractCellsTopOper : public CATGMPolyTopOperator
{
  CATCGMVirtualDeclareClass(CATGMPolyExtractCellsTopOper);

public:


  /**
  * Destructor
  */
  virtual ~CATGMPolyExtractCellsTopOper();


  /** @nodoc 
  * cannot be called
  */
  // Please, call CATCreate...TopOper functions to create an instance
  static CATGMPolyExtractCellsTopOper * New(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyExtractCellsTopExt & iExtension);

  //=============================================================================
  // Settings
  //=============================================================================
    


  // ------------------
  // CGMReplay Methods
  // ------------------
  /** @nodoc * @nocgmitf */
  static const CATString * GetDefaultOperatorId();
	

protected:

  /** @nodoc 
  * cannot be called
  */
  // Constructor
  // Please, call CATCreatePolyBoundaryTopOper() method to create an instance
  CATGMPolyExtractCellsTopOper(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyExtractCellsTopExt & iExtension);


private:

  //===========================================================================
  // COPY-CONSTRUCTOR et OPERATOR =   Not DEFINED
  //===========================================================================
  
  CATGMPolyExtractCellsTopOper();
  CATGMPolyExtractCellsTopOper(const CATGMPolyExtractCellsTopOper& iOneOf); 
  CATGMPolyExtractCellsTopOper& operator =(const CATGMPolyExtractCellsTopOper& iOneOf);

};


/**
 * @nodoc @nocgmitf (do not create a specific interface)
 * Constructs an operator that creates a new CATBody from a subset of cells (with a common dimension)
 *            to keep in (or remove from) an input CATBody
 * @param iFactory
 * A pointer to the factory of the resulting body.
 * @param iTopData
 * A pointer to the topological data with the SoftwareConfiguration to drive the versionning behavior and the Journal to fill.
 * @param iInputBody
 * A pointer to the body with which the result body will share the subset of remaining Cells
 * @param iSpecCells
 * The list of Cells to keep/remove from the input body in order to build the result
 * @param iKeepMode
 * The mode driving the behavior of the operator : Keeping (default) of Removing the list of specified Cells
 */
ExportedByGMPolyBasicOper CATGMPolyExtractCellsTopOper * CATCreatePolyExtractCellsTopOper(CATGeoFactory           * iFactory,
                                                                                          CATTopData              * iTopData,
                                                                                          CATBody                 * iInputBody,
                                                                                          const CATLISTP(CATCell) & iSpecCells,
                                                                                          CATBoolean                iKeepMode=TRUE);


/**
 * @nodoc @nocgmitf (do not create a specific interface)
 * Constructs an operator that creates a new CATBody from a subset of cells (with a common dimension) to keep
 * @param iFactory
 * A pointer to the factory of the resulting body.
 * @param iTopData
 * A pointer to the topological data with the SoftwareConfiguration to drive the versionning behavior and the Journal to fill.
 * @param iInputBody
 * A pointer to the body with which the result body will share the subset of remaining Cells
 * @param iCellsToKeep
 * The list of Cells to keep from the input body in order to build the result
 * @param iSpecOrientations
 * The list of expected orientations associated to the cells to keep
 * This option may be useful only in case of faces or edges, but ignored in case of vertices
 */
ExportedByGMPolyBasicOper CATGMPolyExtractCellsTopOper * CATCreatePolyExtractCellsTopOper(CATGeoFactory           * iFactory,
                                                                                          CATTopData              * iTopData,
                                                                                          CATBody                 * iInputBody,
                                                                                          const CATLISTP(CATCell) & iCellsToKeep,
                                                                                          const CATListOfInt      & iSpecOrientations);

#endif





