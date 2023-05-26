/* -*-C++-*-*/
#ifndef CATGMPolyTrimWiresOnSupportTopOper_H
#define CATGMPolyTrimWiresOnSupportTopOper_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2015
//
// CATGMPolyTrimWiresOnSupportTopOper
//
// DESCRIPTION :
// Trim two 1D-body by each other, Side depending on normal to support input
//
//
// History
//
// April. 2018 CLO2 Creation
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
class CATGMPolyTrimWiresOnSupportTopExt;


/** @nodoc @nocgmitf (do not create any specific interface) */
class ExportedByGMPolyBoolean CATGMPolyTrimWiresOnSupportTopOper : public CATGMPolyTopOperator
{
  CATCGMVirtualDeclareClass(CATGMPolyTrimWiresOnSupportTopOper);

public:


  /**
  * Destructor
  */
  virtual ~CATGMPolyTrimWiresOnSupportTopOper();


  /** @nodoc 
  * cannot be called
  */
  // Please, call CATCreateGMPolyBodyBooleanTopOper() method to create an instance
  static CATGMPolyTrimWiresOnSupportTopOper * New(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyTrimWiresOnSupportTopExt & iExtension);


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
  CATGMPolyTrimWiresOnSupportTopOper(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyTrimWiresOnSupportTopExt & iExtension);


private:

  //===========================================================================
  // COPY-CONSTRUCTOR et OPERATOR =   Not DEFINED
  //===========================================================================
  
  CATGMPolyTrimWiresOnSupportTopOper();
  CATGMPolyTrimWiresOnSupportTopOper(const CATGMPolyTrimWiresOnSupportTopOper& iOneOf); 
  CATGMPolyTrimWiresOnSupportTopOper& operator =(const CATGMPolyTrimWiresOnSupportTopOper& iOneOf);

};

/**
 * @nodoc @nocgmitf (do not create a specific interface)
 * Creates a CATGMPolyTrimWiresOnSupportTopOper operator.
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
ExportedByGMPolyBoolean CATGMPolyTrimWiresOnSupportTopOper * CATCreatePolyTrimWiresOnSupportTopOper(CATGeoFactory * iFactory, CATTopData * iTopData, 
                                                                                    CATBody * iShellBody1, CATBody * iShellBody2, CATBody * iSupportBody,
                                                                                    CATSide  iSideToKeep1=CATSideUnknown, CATSide iSideToKeep2=CATSideUnknown); 

#endif
