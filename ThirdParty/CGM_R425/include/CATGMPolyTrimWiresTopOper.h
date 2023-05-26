/* -*-C++-*-*/
#ifndef CATGMPolyTrimWiresTopOper_H
#define CATGMPolyTrimWiresTopOper_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2015
//
// CATGMPolyTrimWiresTopOper
//
// DESCRIPTION :
// Trim two 1D-body by each other
//
//
// History
//
// February. 2017 CLO2 Creation
//
//=============================================================================

// For Windows NT export
#include "CATGMPolyTopOperator.h" // derivation
#include "GMPolyBoolean.h"        // ExportedBy
#include "CATDynOperatorDef.h"    // CATDynBooleanType

#include "CATDataType.h"          // HRESULT
#include "CATMathInline.h"        // inline Methods
#include "CATBoolean.h"
#include "CATSysBoolean.h"
#include "CATTopDefine.h"       // CATSide

#include "CATListOfCATCells.h"

class CATGeoFactory;
class CATTopData;
class CATBody;
class CATGMPolyTrimWiresTopExt;


/** @nodoc @nocgmitf (do not create any specific interface) */
class ExportedByGMPolyBoolean CATGMPolyTrimWiresTopOper : public CATGMPolyTopOperator
{
  CATCGMVirtualDeclareClass(CATGMPolyTrimWiresTopOper);

public:


  /**
  * Destructor
  */
  virtual ~CATGMPolyTrimWiresTopOper();


  /** @nodoc 
  * cannot be called
  */
  // Please, call CATCreateGMPolyBodyBooleanTopOper() method to create an instance
  static CATGMPolyTrimWiresTopOper * New(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyTrimWiresTopExt & iExtension);


  //=============================================================================
  // Settings
  //=============================================================================

  void SetSelectedCells(CATLISTP(CATCell) &iCellsToRemove, CATLISTP(CATCell) &iCellsToKeep);



  // ------------------
  // CGMReplay Methods
  // ------------------
  /** @nodoc
   * @nocgmitf
  */
  static const CATString * GetDefaultOperatorId();
	

protected:

  /** @nodoc 
  * cannot be called
  */
  // Constructor
  // Please, call CATCreateGMPolyBodyBooleanTopOper() method to create an instance
  CATGMPolyTrimWiresTopOper(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyTrimWiresTopExt & iExtension);


private:

  //===========================================================================
  // COPY-CONSTRUCTOR et OPERATOR =   Not DEFINED
  //===========================================================================
  
  CATGMPolyTrimWiresTopOper();
  CATGMPolyTrimWiresTopOper(const CATGMPolyTrimWiresTopOper& iOneOf); 
  CATGMPolyTrimWiresTopOper& operator =(const CATGMPolyTrimWiresTopOper& iOneOf);

};

/**
 * @nodoc @nocgmitf (do not create a specific interface)
 * Creates a CATGMPolyTrimWiresTopOper operator.
 * @param iFactory
 * The factory of the geometry. 
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
 * is <tt>NULL</tt>, it is not filled. 
 * @param iShellBody1
 * The pointer to the first operand body
 * @param iShellBody2
 * The pointer to the second operand body
 * @param iSideToKeep1 (resp. 2)
 * The side of the disconnected parts to keep, according to the orientation of iShellBody2 (resp. iShellBody1)
 * @return [out, IUnknown#Release]
 * The pointer to the created operator. To be released with the <tt>Release</tt> method after use.
 */
ExportedByGMPolyBoolean CATGMPolyTrimWiresTopOper * CATCreatePolyTrimWiresTopOper(CATGeoFactory * iFactory, CATTopData * iTopData, 
                                                                                    CATBody * iShellBody1, CATBody * iShellBody2,
                                                                                    CATSide  iSideToKeep1=CATSideUnknown, CATSide iSideToKeep2=CATSideUnknown); 

#endif
