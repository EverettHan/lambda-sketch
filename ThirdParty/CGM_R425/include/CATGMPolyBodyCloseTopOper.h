/* -*-C++-*-*/
#ifndef CATGMPolyBodyCloseTopOper_H
#define CATGMPolyBodyCloseTopOper_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2016
//
// CATGMPolyBodyCloseTopOper
// idem CATCloseOperator/CATCloseOperatorImp but dedicated to polyhedral implementation of CATBody
//
// DESCRIPTION :
// Class representing the operator that closes a skin body.
// If the body is a closed shell (set of faces), it simply creates a volume body out of it. 
// If it is an open shell, it will try to close it with as many planar faces as possible.
// <br>The close operator can not create new edges. For instance, trying to
// close a half-cylinder surface face will fail, because, even if it may
// be closed by three planes, two new edges need to be created (at the
// intersection of those planes).
//
//
// History
//
// Oct. 2016 DPS Creation
//
//=============================================================================

// For Windows NT export
#include "CATGMPolyTopOperator.h"     // derivation
#include "GMPolyBasicOper.h"    // ExportedBy

#include "CATCollec.h"
#include "ListPOfCATFace.h"
#include "CATListOfInt.h"

#include "CATDataType.h"        // HRESULT
#include "CATMathInline.h"      // inline Methods
#include "CATDynOperatorDef.h"  // define CATDynBoolean


class CATGeoFactory;
class CATTopData;
class CATBody;
class CATDomain;
class CATCell;
class CATGMPolyBodyCloseTopExt;


/** @nodoc @nocgmitf (do not create any specific interface) */
class ExportedByGMPolyBasicOper CATGMPolyBodyCloseTopOper : public CATGMPolyTopOperator
{
  CATCGMVirtualDeclareClass(CATGMPolyBodyCloseTopOper);

public:


  /**
  * Destructor
  */
  virtual ~CATGMPolyBodyCloseTopOper();


  /** @nodoc 
  * cannot be called
  */
  // Please, call CATCreate...TopOper functions to create an instance
  static CATGMPolyBodyCloseTopOper * New(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyBodyCloseTopExt & iExtension);


  //=============================================================================
  // Settings
  //=============================================================================
    
  // Set a tolerance value for closing plane creation, and curve merge. This
  // tolerance may not be smaller than modeler resolution (0.001 mm for NormalScale), which is the default value, 
  // neither greater than the large resolution (100 times the resolution)
  /**  @nodoc */
  void SetToleranceValue(double iTolValue);

  /** 
  * Asks for a boolean operation with the output of the operator
  * (the so called closed skin) and <tt>iOperandBody</tt>.
  * @param iReport
  * The pointer to the journal to fill, if not <tt>NULL</tt>.
  * It can be different from the operator journal given in CATTopData.
  */
  void SetBooleanOperation(CATDynBooleanType iOpType, CATBody *iOperandBody, CATCGMJournalList *iReport = 0);

   

  // ----------------------------------------------------------------------------
  /**
  * Returns the body created from the Boolean operation between a given body and the thickened body.
  * @return
  * The pointer to the Boolean result.
  * If you do not want to keep the resulting body, 
  * use the @href CATICGMContainer#Remove method to remove it from the 
  * geometric factory, after the operator deletion.
  */
  CATBody * GetBooleanResult();


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
  // Please, call CATCreatePolyBoundaryTopOper() method to create an instance
  CATGMPolyBodyCloseTopOper(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyBodyCloseTopExt & iExtension);


private:

  //===========================================================================
  // COPY-CONSTRUCTOR et OPERATOR =   Not DEFINED
  //===========================================================================
  
  CATGMPolyBodyCloseTopOper();
  CATGMPolyBodyCloseTopOper(const CATGMPolyBodyCloseTopOper& iOneOf); 
  CATGMPolyBodyCloseTopOper& operator =(const CATGMPolyBodyCloseTopOper& iOneOf);

};


/**
 * @nodoc @nocgmitf (do not create any interface)
 * Creates an operator that closes a polyhedral skin body.
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iTopData
 * The pointer to the data defining the configuration and the journal. If the journal inside <tt>iData</tt> 
 * is <tt>NULL</tt>, it is not filled.
 * @param iBodyToClose
 * The pointer to the polyhedral skin body to close.
 * @return [out, IUnknown#Release]
 * The pointer to the created operator.
 */
ExportedByGMPolyBasicOper CATGMPolyBodyCloseTopOper * CATCreatePolyBodyCloseTopOper(CATGeoFactory           * iFactory,
                                                                                    CATTopData              * iTopData,
                                                                                    CATBody                 * iBodyToClose);

#endif





