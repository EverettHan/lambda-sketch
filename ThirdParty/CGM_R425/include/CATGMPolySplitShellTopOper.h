/* -*-C++-*-*/
#ifndef CATGMPolySplitShellTopOper_H
#define CATGMPolySplitShellTopOper_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2015
//
// CATGMPolySplitShellTopOper
//
// DESCRIPTION :
// Split a 2D body by another body (1D or 2D)
//
//
// History
//
// November. 2015 DPS Creation
//
//=============================================================================

// For Windows NT export
#include "CATGMPolyTopOperator.h"     // derivation
#include "GMPolyBoolean.h"      // ExportedBy

#include "CATDataType.h"        // HRESULT
#include "CATMathInline.h"      // inline Methods
#include "CATBoolean.h"
#include "CATSysBoolean.h"
#include "CATTopDefine.h"       // CATSide

#include "CATListOfCATCells.h"

class CATGeoFactory;
class CATTopData;
class CATBody;
class CATGMPolyOperTopExt;

/** @nodoc @nocgmitf (do not create any specific interface) */
class ExportedByGMPolyBoolean CATGMPolySplitShellTopOper : public CATGMPolyTopOperator
{
  CATCGMVirtualDeclareClass(CATGMPolySplitShellTopOper);

public:


  /**
  * Destructor
  */
  virtual ~CATGMPolySplitShellTopOper();


  /** @nodoc 
  * cannot be called
  */
  // Please, call CATCreateGMPolyBodyBooleanTopOper() method to create an instance
  static CATGMPolySplitShellTopOper * New(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyOperTopExt & iExtension);


  //=============================================================================
  // Settings
  //=============================================================================

  /** @nodoc @nocgmitf */
  void SetSelectedCells(CATLISTP(CATCell) &iCellsToRemove, CATLISTP(CATCell) &iCellsToKeep);

  /** @nodoc @nocgmitf */
  // Enable/Disable the extrapolation for the case the intersection wire is not fully disconnecting the body to split
  // Default mode is FALSE (disabled)
  void SetExtrapolationMode(CATBoolean iExtrapolMode);

  /** @nodoc @nocgmitf */
  // Enable/Disable the "LyingOn" links on the result cells coming from CuttingBody (input wire in contact or intersection edges & vertices)
  // Default mode is FALSE (disabled)
  void SetLyingOnMode(CATBoolean iKeepLyingOnCuttingBody);

  /** @nodoc @nocgmitf */
  // A threshold of contact is useful only if the cutting body is a wire to lay down on the body to plit.
  // In this case, the input threshold has to be greater than the resolution (0.001mm in NormalScale) and smaller than the LargeResolution(0.1mm in NS)
  // The default threshold value is the factory resolution (0.001mm in NormalScale)
  void SetContactThreshold(double iContactThreshold);

  /** @nodoc @nocgmitf */
  void SetKeepHalfSpaceMode(CATBoolean iMode_SemiSpace);

  /** @nodoc @nocgmitf */
  void DisableOperandsPersistency();

  /** @nodoc @nocgmitf */
  // The default behavior of the SplitShellsTopOper consists in keeping untouched domains of BodyToSplit
  // This option allows the caller to pilot explicitely the keep/remove behavior of untouched shells of this first operand.
  void SetUntouchedDomainsRemoveMode(CATBoolean iRemoveUntouchedShells);


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
  CATGMPolySplitShellTopOper(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyOperTopExt & iExtension);


private:

  //===========================================================================
  // COPY-CONSTRUCTOR et OPERATOR =   Not DEFINED
  //===========================================================================
  
  CATGMPolySplitShellTopOper();
  CATGMPolySplitShellTopOper(const CATGMPolySplitShellTopOper& iOneOf); 
  CATGMPolySplitShellTopOper& operator =(const CATGMPolySplitShellTopOper& iOneOf);

};

/**
 * @nodoc @nocgmitf (do not create a specific interface)
 * Creates a CATGMPolySplitShellTopOper operator.
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
ExportedByGMPolyBoolean CATGMPolySplitShellTopOper * CATCreatePolySplitShellTopOper(CATGeoFactory * iFactory, CATTopData * iTopData, 
                                                                                    CATBody * iBodyToSplit, CATBody * iCuttingBody,
                                                                                    CATSide  iSideToKeep=CATSideUnknown); 

/**
 * @nodoc @nocgmitf (do not create a specific interface)
 * Creates a CATGMPolySplitShellTopOper operator.
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
ExportedByGMPolyBoolean CATGMPolySplitShellTopOper * CATCreatePolySplitShellWithExtrapolTopOper(CATGeoFactory * iFactory, CATTopData * iTopData, 
                                                                                                CATBody * iBodyToSplit, CATBody * iCuttingBody,
                                                                                                CATSide  iSideToKeep=CATSideUnknown); 

#endif
