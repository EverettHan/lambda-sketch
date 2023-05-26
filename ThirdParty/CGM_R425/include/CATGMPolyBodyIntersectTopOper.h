/* -*-C++-*-*/
#ifndef CATGMPolyBodyIntersectTopOper_H
#define CATGMPolyBodyIntersectTopOper_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2016
//
// CATGMPolyBodyIntersectTopOper
//
// DESCRIPTION :
// Intersect two 2D-body by each other
//
//
// History
//
// February. 2016 DPS Creation
//
//=============================================================================

// For Windows NT export
#include "CATGMPolyTopOperator.h" // derivation
#include "GMPolyBoolean.h"        // ExportedBy
#include "CATDynOperatorDef.h"    // CATDynBooleanType

#include "CATDataType.h"        // HRESULT
#include "CATMathInline.h"      // inline Methods
#include "CATBoolean.h"
#include "CATSysBoolean.h"
#include "CATTopDefine.h"       // CATSide


class CATGeoFactory;
class CATTopData;
class CATBody;
class CATGMPolyBodyIntersectTopExt;


/** @nodoc @nocgmitf (do not create any specific interface) */
class ExportedByGMPolyBoolean CATGMPolyBodyIntersectTopOper : public CATGMPolyTopOperator
{
  CATCGMVirtualDeclareClass(CATGMPolyBodyIntersectTopOper);

public:


  /**
  * Destructor
  */
  virtual ~CATGMPolyBodyIntersectTopOper();


  /** @nodoc 
  * cannot be called
  */
  // Please, call CATCreateGMPolyBodyBooleanTopOper() method to create an instance
  static CATGMPolyBodyIntersectTopOper * New(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyBodyIntersectTopExt & iExtension);


  //=============================================================================
  // Settings
  //=============================================================================

  /** @nodoc
  * @nocgmitf
  * Specification to choose the orientation of the intersection wire Vs the vectorial product of the 2 surfacic normals
  * TRUE means (N1, N2, Tw) is direct for each point of the intersection
  * This setting is internally initialized to FALSE to be compliant with the exact behaviour.
  */
  void SetDirectAxisSystem(CATBoolean iIsDirect=TRUE);

  /** @nodoc @nocgmitf */
  // Enable/Disable the extrapolation for the case the intersection wire is not fully disconnecting an operand
  // Default mode is FALSE (disabled)
  void SetExtrapolOnOperand(CATBoolean iExtrapolMode, int iOperandID12);

  /** @nodoc @nocgmitf */
  // Enable/Disable the "LyingOn" links on the result cells coming from an operand (input wire in contact or intersection edges & vertices)
  // Default mode is FALSE (disabled)
  void SetLyingOnOperand(CATBoolean iKeepLyingOn, int iOperandID12);

  // Enable the generation of GeoPolyCurveOnPlane instead of simple 3D GeoPolyCurve, 
  // associating UV parameters to the 3D points of the curves if the target body is an infinite planar body
  // Default mode is FALSE (disabled)
  void EnablePlanarModeling();

  //Enable generation of non ready body
  // Default mode is FALSE (disabled)
  void AuthorizeNotReadyBody();


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
  CATGMPolyBodyIntersectTopOper(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyBodyIntersectTopExt & iExtension);


private:

  //===========================================================================
  // COPY-CONSTRUCTOR et OPERATOR =   Not DEFINED
  //===========================================================================
  
  CATGMPolyBodyIntersectTopOper();
  CATGMPolyBodyIntersectTopOper(const CATGMPolyBodyIntersectTopOper& iOneOf); 
  CATGMPolyBodyIntersectTopOper& operator =(const CATGMPolyBodyIntersectTopOper& iOneOf);

};

/**
 * @nodoc @nocgmitf (do not create a specific interface)
 * Creates a CATGMPolyBodyIntersectTopOper operator.
 * @param iFactory
 * The factory of the geometry. 
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
 * is <tt>NULL</tt>, it is not filled. 
 * @param iShellBody1
 * The pointer to the first operand body
 * @param iShellBody2
 * The pointer to the second operand body
 * @return [out, IUnknown#Release]
 * The pointer to the created operator. To be released with the <tt>Release</tt> method after use.
 */
ExportedByGMPolyBoolean CATGMPolyBodyIntersectTopOper * CATCreatePolyBodyIntersectTopOper(CATGeoFactory * iFactory, CATTopData * iTopData, 
                                                                                          CATBody * iShellBody1, CATBody * iShellBody2); 

#endif
