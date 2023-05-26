/* -*-C++-*-*/
#ifndef CATGMPolyBodyExtremumTopOper_H
#define CATGMPolyBodyExtremumTopOper_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2017
//
// CATGMPolyBodyExtremumTopOper
// Polyhedral implementation of CATTopBodyExtremum operator
//
// DESCRIPTION :
// 
// History
//
// Mar. 2017 WMN Creation
//
//=============================================================================

// For Windows NT export
#include "CATGMPolyTopOperator.h" // derivation
#include "GMPolyBasicOper.h"      // ExportedBy

#include "CATCollec.h"
#include "ListPOfCATFace.h"
#include "CATListOfInt.h"

#include "CATDataType.h"          // HRESULT
#include "CATMathInline.h"        // inline Methods
#include "CATDynOperatorDef.h"    // define CATDynBoolean

// Extremum includes
#include "CATMinMax.h"

class CATGeoFactory;
class CATTopData;
class CATBody;
class CATDomain;
class CATCell;
class CATGMPolyBodyExtremumTopExt;


/** @nodoc @nocgmitf (do not create any specific interface) */
class ExportedByGMPolyBasicOper CATGMPolyBodyExtremumTopOper : public CATGMPolyTopOperator
{
  CATCGMVirtualDeclareClass(CATGMPolyBodyExtremumTopOper);

public:


  /**
  * Destructor
  */
  virtual ~CATGMPolyBodyExtremumTopOper();


  /** @nodoc 
  * cannot be called
  */
  // Please, call CATCreate...TopOper functions to create an instance
  static CATGMPolyBodyExtremumTopOper * New(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyBodyExtremumTopExt & iExtension);


  //=============================================================================
  // Settings
  //=============================================================================
    
  // None

  //=============================================================================
  // Results
  //=============================================================================

  double GetDistanceFromOriginAlongDirection();

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
  CATGMPolyBodyExtremumTopOper(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyBodyExtremumTopExt & iExtension);


private:

  //===========================================================================
  // COPY-CONSTRUCTOR et OPERATOR =   Not DEFINED
  //===========================================================================
  
  CATGMPolyBodyExtremumTopOper();
  CATGMPolyBodyExtremumTopOper(const CATGMPolyBodyExtremumTopOper& iOneOf); 
  CATGMPolyBodyExtremumTopOper& operator =(const CATGMPolyBodyExtremumTopOper& iOneOf);

};


/**
 * @nodoc @nocgmitf (do not create any interface)
 * Description
 * @param iFactory
 * The pointer to the factory of the geometry.
 * @param iTopData
 * The pointer to the data defining the configuration and the journal. If the journal inside <tt>iData</tt> 
 * is <tt>NULL</tt>, it is not filled.
 * @param iBody
 * The pointer to the polyhedral body.
 * @return [out, IUnknown#Release]
 * The pointer to the created operator.
 */
ExportedByGMPolyBasicOper CATGMPolyBodyExtremumTopOper * CATCreatePolyBodyExtremumTopOper(CATGeoFactory           * iFactory,
                                                                                          CATTopData              * iTopData,
                                                                                          CATBody                 * iBody,
                                                                                          CATMinMax                 iTypeOfExtremum,
                                                                                          const CATMathVector     & iDir,
                                                                                          const CATMathPoint      & iOrigPt);

#endif
