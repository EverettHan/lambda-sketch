/* -*-C++-*-*/
#ifndef CATGMPolyBodyIntersectWireTopOper_H
#define CATGMPolyBodyIntersectWireTopOper_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2015
//
// CATGMPolyBodyIntersectWireTopOper
//
// DESCRIPTION :
// Intersect a 1D body by a shell or a wireframe body
//
//
// History
//
// November. 2016 CLO2 Creation
//
//=============================================================================

// For Windows NT export
#include "CATGMPolyTopOperator.h" // derivation
#include "GMPolyBoolean.h"        // ExportedBy

#include "CATDataType.h"          // HRESULT
#include "CATMathInline.h"        // inline Methods
#include "CATBoolean.h"
#include "CATSysBoolean.h"

class CATGeoFactory;
class CATTopData;
class CATBody;
class CATGMPolyOperTopExt;

/** @nodoc @nocgmitf (do not create any specific interface) */
class ExportedByGMPolyBoolean CATGMPolyBodyIntersectWireTopOper : public CATGMPolyTopOperator
{
  CATCGMVirtualDeclareClass(CATGMPolyBodyIntersectWireTopOper);

public:


  /**
  * Destructor
  */
  virtual ~CATGMPolyBodyIntersectWireTopOper();


  /** @nodoc 
  * cannot be called
  */
  // Please, call CATCreateGMPolyBodyBooleanTopOper() method to create an instance
  static CATGMPolyBodyIntersectWireTopOper * New(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyOperTopExt & iExtension);


  //=============================================================================
  // Settings
  //=============================================================================

  /** @nodoc @nocgmitf */
  // Enable/Disable the "LyingOn" links on the result cells coming from an operand (input wire in contact or intersection edges & vertices)
  // Default mode is FALSE (disabled)
  void SetLyingOnOperand(CATBoolean iKeepLyingOn, int iOperandID12);

  
  // Enable the generation of GeoPolyCurveOnPlane instead of simple 3D GeoPolyCurve, 
  // associating UV parameters to the 3D points of the curves if the target body is an infinite planar body
  // Default mode is FALSE (disabled)
  void Enable2DModelingOnInfinitePlane();


  // ------------------
  // CGMReplay Methods
  // ------------------
  /** @nodoc
   * @nocgmitf
  */
  static const CATString * GetDefaultOperatorId();
  /** @nodoc
   * @nocgmitf
  */

protected:

  /** @nodoc 
  * cannot be called
  */
  // Constructor
  // Please, call CATCreateGMPolyIntersectWireTopOper() method to create an instance
  CATGMPolyBodyIntersectWireTopOper(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyOperTopExt & iExtension);


private:

  //===========================================================================
  // COPY-CONSTRUCTOR et OPERATOR =   Not DEFINED
  //===========================================================================
  
  CATGMPolyBodyIntersectWireTopOper();
  CATGMPolyBodyIntersectWireTopOper(const CATGMPolyBodyIntersectWireTopOper& iOneOf); 
  CATGMPolyBodyIntersectWireTopOper& operator =(const CATGMPolyBodyIntersectWireTopOper& iOneOf);

};

/**
 * @nodoc @nocgmitf (do not create a specific interface)
 * Creates a CATGMPolyBodyIntersectWireTopOper operator.
 * @param iFactory
 * The factory of the geometry. 
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
 * is <tt>NULL</tt>, it is not filled. 
 * @param iBodyToSplit
 * The pointer to the body to split
 * @param iCuttingBody
 * The pointer to the body disconnecting iBodyToSplit in several parts
 * @param iSideToKeep
 * The side of the disconnected parts to keep, according to the orientation of iCuttingBody
 * @return [out, IUnknown#Release]
 * The pointer to the created operator. To be released with the <tt>Release</tt> method after use.
 */
ExportedByGMPolyBoolean CATGMPolyBodyIntersectWireTopOper * CATCreatePolyBodyIntersectWiresByShellTopOper(CATGeoFactory * iFactory, CATTopData * iTopData, 
                                                                                    CATBody * iBody1, CATBody * iBody2); 

ExportedByGMPolyBoolean CATGMPolyBodyIntersectWireTopOper * CATCreatePolyBodyIntersectWireWireTopOper(CATGeoFactory * iFactory, CATTopData * iTopData, 
                                                                                    CATBody * iBody1, CATBody * iBody2); 

ExportedByGMPolyBoolean CATGMPolyBodyIntersectWireTopOper * CATCreatePolyBodyIntersectWireTopOper(CATGeoFactory * iFactory, CATTopData * iTopData, 
                                                                                    CATBody * iBody1, CATBody * iBody2); 

#endif
