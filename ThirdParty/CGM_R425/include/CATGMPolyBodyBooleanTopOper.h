/* -*-C++-*-*/
#ifndef CATGMPolyBodyBooleanTopOper_H
#define CATGMPolyBodyBooleanTopOper_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2015
//
// CATGMPolyBodyBooleanTopOper
//
// DESCRIPTION :
// Boolean operation (Union, Intersection of Substraction) between 2 volumic polyhedral bodies
//
//
// History
//
// March. 2015 DPS Creation
//
//=============================================================================

// For Windows NT export
#include "CATGMPolyTopOperator.h"     // derivation
#include "GMPolyBoolean.h"      // ExportedBy
#include "CATDynOperatorDef.h"  // CATDynBooleanType
#include "CATTopDefine.h"       // CATSide

#include "CATDataType.h"        // HRESULT
#include "CATMathInline.h"      // inline Methods
#include "CATBoolean.h"
#include "CATSysBoolean.h"


class CATGeoFactory;
class CATTopData;
class CATBody;
class CATGMPolyBodyBooleanTopExt;


/** @nodoc @nocgmitf (do not create any specific interface) */
class ExportedByGMPolyBoolean CATGMPolyBodyBooleanTopOper : public CATGMPolyTopOperator
{
  CATCGMVirtualDeclareClass(CATGMPolyBodyBooleanTopOper);

public:


  /**
  * Destructor
  */
  virtual ~CATGMPolyBodyBooleanTopOper();


  /** @nodoc 
  * cannot be called
  */
  // Please, call CATCreateGMPolyBodyBooleanTopOper() method to create an instance
  static CATGMPolyBodyBooleanTopOper * New(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyBodyBooleanTopExt & iExtension);


  //=============================================================================
  // Settings
  //=============================================================================

  void DisableSimplifyMode();

  /** @nodoc @nocgmitf */
  void DisableOperandsPersistency();

  /** @nodoc @nocgmitf */
  void ForcePartitioningMode();

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
  CATGMPolyBodyBooleanTopOper(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyBodyBooleanTopExt & iExtension);


private:

  //===========================================================================
  // COPY-CONSTRUCTOR et OPERATOR =   Not DEFINED
  //===========================================================================
  
  CATGMPolyBodyBooleanTopOper();
  CATGMPolyBodyBooleanTopOper(const CATGMPolyBodyBooleanTopOper& iOneOf); 
  CATGMPolyBodyBooleanTopOper& operator =(const CATGMPolyBodyBooleanTopOper& iOneOf);

};

/**
 * @nodoc @nocgmitf (do not create a specific interface)
 * Creates a CATGMPolyBodyBooleanTopOper operator.
 * @param iFactory
 * The factory of the geometry. 
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
 * is <tt>NULL</tt>, it is not filled. 
 * @param iBooleanOperationType
 * The type of boolean operation among { CATBoolUnion, CATBoolIntersection, CATBoolRemoval }
 * @param iOperand0
 * The pointer to the first body of the boolean operation
 * @param iOperand1
 * The pointer to the second body of the boolean operation 
 * @return [out, IUnknown#Release]
 * The pointer to the created operator. To be released with the <tt>Release</tt> method after use.
 */
ExportedByGMPolyBoolean CATGMPolyBodyBooleanTopOper * CATCreatePolyBooleanTopOper(CATGeoFactory * iFactory, CATTopData * iTopData, 
                                                                                  CATDynBooleanType iBooleanOperationType, CATBody * iOperand0, CATBody * iOperand1); 
/**
 * @nodoc @nocgmitf (do not create a specific interface)
 * Creates a CATGMPolyBodyClippingTopOper operator.
 * @param iFactory
 * The factory of the geometry. 
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
 * is <tt>NULL</tt>, it is not filled. 
 * @param iCatSide
 * The side to keep (inside or outside ClippingBody) {CATSideRight (outside), CATSideLeft (inside)}
 * @param iBodyToClip
 * The pointer to the body to clip - dimension 2 or 3
 * @param iClippingBody
 * The pointer to the clipping body - dimension 3 
 * @return [out, IUnknown#Release]
 * The pointer to the created operator. To be released with the <tt>Release</tt> method after use.
 */
ExportedByGMPolyBoolean CATGMPolyBodyBooleanTopOper * CATCreatePolyClippingTopOper(CATGeoFactory * iFactory, CATTopData * iTopData, 
                                                                                   CATSide iSideToKeep, CATBody * iBodyToClip, CATBody * iClippingBody); 

#endif
