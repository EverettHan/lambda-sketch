/* -*-C++-*-*/
#ifndef CATGMPolyUnfoldWireTopOper_H
#define CATGMPolyUnfoldWireTopOper_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2020
//
// CATGMPolyUnfoldWireTopOper
//
// DESCRIPTION :
// Generate a planar polyhedral wire by transferring a 3D polyhedral wire,
// from a 3D (exact) surfacic body to its unfolded image (planar surfacic exact body),
// thanks to the knowledge of the faces mapping before/after the Shell unfold
//
//=============================================================================
//
// History
//
// July 2020 DPS Creation
//
//=============================================================================

// For Windows NT export
#include "CATGMPolyTopOperator.h"     // derivation
#include "GMPolyProject.h"            // ExportedBy

#include "CATDataType.h"              // HRESULT
#include "CATTopDefine.h"             // CATSide
#include "CATMathInline.h"            // inline Methods

#include "ListPOfCATFace.h"

#include "CATBoolean.h"
#include "CATSysBoolean.h"

class CATGeoFactory;
class CATTopData;
class CATBody;
class CATFace;
class CATWire;
class CATMathTransformation2D;
class CATGMPolyUnfoldWireTopExt;


/** @nodoc @nocgmitf (do not create any specific interface) */
class ExportedByGMPolyProject CATGMPolyUnfoldWireTopOper : public CATGMPolyTopOperator
{
  CATCGMVirtualDeclareClass(CATGMPolyUnfoldWireTopOper);

public:


  /**
  * Destructor
  */
  virtual ~CATGMPolyUnfoldWireTopOper();


  /** @nodoc 
  * cannot be called
  */
  // Please, call CATCreatePolyUnfoldWireTopOper() method to create an instance
  static CATGMPolyUnfoldWireTopOper * New(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyUnfoldWireTopExt & iExtension);


  //=============================================================================
  // Settings
  //=============================================================================

  // Sets the mathematical plane as target for the unfold operation
  void SetUnfoldMathPlane(const CATMathPlane & iTargetMathPlane);


  // Sets the knowledge of mapping between faces of iShellBodySupport and their associated images in iTargetFlattenedBody
  // The 2 lists are supposed to have the same size (bijection)
  void SetUnfoldMappingOfFaces(const CATLISTP(CATFace) &iListOf3DFaces, const CATLISTP(CATFace) &iListOfFlattenedFaces, const CATMathTransformation2D * iTransfo2DTable);


  // Sets the tolerance value in order to drive the projection of the wire on its support
  void SetToleranceValue(double iTolValue);



  //=============================================================================
  // Get
  //=============================================================================



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
  // Please, call CATCreatePolyUnfoldWireTopOper() method to create an instance
  CATGMPolyUnfoldWireTopOper(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyUnfoldWireTopExt & iExtension);


private:

  //===========================================================================
  // COPY-CONSTRUCTOR et OPERATOR =   Not DEFINED
  //===========================================================================
  
  CATGMPolyUnfoldWireTopOper();
  CATGMPolyUnfoldWireTopOper(const CATGMPolyUnfoldWireTopOper& iOneOf); 
  CATGMPolyUnfoldWireTopOper& operator =(const CATGMPolyUnfoldWireTopOper& iOneOf);

};

/**
 * @nodoc @nocgmitf (do not create a specific interface)
 * Creates a CATGMPolyUnfoldWireTopOper operator.
 * @param iFactory
 * The factory of the geometry. 
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
 * is <tt>NULL</tt>, it is not filled. 
 * @param iWireBodyToUnfold
 * The pointer to the polyhedral 1D body to unfold
 * @param iShellBodySupport
 * The pointer to the (exact) surfacic body on which iWireBodyToUnfold is (numerically) lying on
 * @param iTargetFlattenedBody
 * The target (exact) planar body on which the unfold wire result will be (numerically) lying on
 * This body is the unfolded image of iShellBodySupport
 * @return [out, IUnknown#Release]
 * The pointer to the created operator. To be released with the <tt>Release</tt> method after use.
 */
ExportedByGMPolyProject CATGMPolyUnfoldWireTopOper * CATCreatePolyUnfoldWireTopOper(CATGeoFactory * iFactory, 
                                                                                    CATTopData    * iTopData, 
                                                                                    CATBody       * iWireBodyToUnfold, 
                                                                                    CATBody       * iShellBodySupport, 
                                                                                    CATBody       * iTargetFlattenedBody); 

#endif
