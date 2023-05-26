/* -*-C++-*-*/
#ifndef CATGMPolyTrimShellsTopOper_H
#define CATGMPolyTrimShellsTopOper_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2015
//
// CATGMPolyTrimShellsTopOper
//
// DESCRIPTION :
// Trim two 2D-body by each other
//
//
// History
//
// December. 2015 DPS Creation
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
#include "CATTopDefine.h"         // CATSide

#include "CATListOfCATCells.h"

class CATGeoFactory;
class CATTopData;
class CATBody;
class CATGMPolyTrimShellsTopExt;


/** @nodoc @nocgmitf (do not create any specific interface) */
class ExportedByGMPolyBoolean CATGMPolyTrimShellsTopOper : public CATGMPolyTopOperator
{
  CATCGMVirtualDeclareClass(CATGMPolyTrimShellsTopOper);

public:


  /**
  * Destructor
  */
  virtual ~CATGMPolyTrimShellsTopOper();


  /** @nodoc 
  * cannot be called
  */
  // Please, call CATCreateGMPolyBodyBooleanTopOper() method to create an instance
  static CATGMPolyTrimShellsTopOper * New(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyTrimShellsTopExt & iExtension);


  //=============================================================================
  // Settings
  //=============================================================================

  void SetSelectedCells(CATLISTP(CATCell) &iCellsToRemove, CATLISTP(CATCell) &iCellsToKeep);

  /** @nodoc @nocgmitf */
  // Enable/Disable the extrapolation for the case the intersection wire is not fully disconnecting the bodies to trim
  // Default mode is FALSE (disabled)
  void SetExtrapolationMode(CATBoolean iExtrapolMode);

  /** @nodoc @nocgmitf */
  // The default behavior of the TrimShellsTopOper consists in keeping untouched domains of both operands
  // This option allows the caller to pilot explicitely the keep/remove behavior of untouched shells for each operand.
  void SetUntouchedDomainsRemoveMode(CATBoolean iRemoveUntouchedShellsFromOperand1, CATBoolean iRemoveUntouchedShellsFromOperand2);


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
  CATGMPolyTrimShellsTopOper(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyTrimShellsTopExt & iExtension);


private:

  //===========================================================================
  // COPY-CONSTRUCTOR et OPERATOR =   Not DEFINED
  //===========================================================================
  
  CATGMPolyTrimShellsTopOper();
  CATGMPolyTrimShellsTopOper(const CATGMPolyTrimShellsTopOper& iOneOf); 
  CATGMPolyTrimShellsTopOper& operator =(const CATGMPolyTrimShellsTopOper& iOneOf);

};

/**
 * @nodoc @nocgmitf (do not create a specific interface)
 * Creates a CATGMPolyTrimShellsTopOper operator.
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
ExportedByGMPolyBoolean CATGMPolyTrimShellsTopOper * CATCreatePolyTrimShellsTopOper(CATGeoFactory * iFactory, CATTopData * iTopData, 
                                                                                    CATBody * iShellBody1, CATBody * iShellBody2,
                                                                                    CATSide  iSideToKeep1=CATSideUnknown, CATSide iSideToKeep2=CATSideUnknown); 

#endif
