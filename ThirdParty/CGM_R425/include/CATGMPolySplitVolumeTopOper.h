/* -*-C++-*-*/
#ifndef CATGMPolySplitVolumeTopOper_H
#define CATGMPolySplitVolumeTopOper_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2016
//
// CATGMPolySplitVolumeTopOper
//
// DESCRIPTION :
// Split a 3D polyhedral body & relimit it by a 2D polyhedral body
// see also the CGM interface CATIPGMDynSplit for both exact & polyhedral data
//
// History
//
// March. 2016 DPS Creation
//
//=============================================================================

// For Windows NT export
#include "CATGMPolyTopOperator.h" // derivation
#include "GMPolyBoolean.h"        // ExportedBy
#include "CATDynOperatorDef.h"    // CATDynSplitType / CATDynSelectionMode

#include "CATDataType.h"          // HRESULT
#include "CATMathInline.h"        // inline Methods
#include "CATBoolean.h"
#include "CATSysBoolean.h"
#include "CATTopDefine.h"         // CATSide

#include "CATListOfCATCells.h"

class CATGeoFactory;
class CATTopData;
class CATBody;
class CATGMPolySplitVolumeTopExt;


/** @nodoc @nocgmitf (do not create any specific interface) */
class ExportedByGMPolyBoolean CATGMPolySplitVolumeTopOper : public CATGMPolyTopOperator
{
  CATCGMVirtualDeclareClass(CATGMPolySplitVolumeTopOper);

public:


  /**
  * Destructor
  */
  virtual ~CATGMPolySplitVolumeTopOper();


  /** @nodoc 
  * cannot be called
  */
  // Please, call CATCreateGMPolyBodyBooleanTopOper() method to create an instance
  static CATGMPolySplitVolumeTopOper * New(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolySplitVolumeTopExt & iExtension);


  //=============================================================================
  // Settings
  //=============================================================================

  /**
  * Sets Selection Mode.
  * Allows to decide among 3 possible behaviors for the split operator
  * (CATDynKeepMode, CATDynRemoveMode, CATDynPositionVsPlaneMode)
  * @param iSelectionMode
  * The selection mode. CATDynKeepMode by default here.
  */
  void SetSelectionMode(CATDynSelectionMode iSelectionMode);


  // Has the volume been cut by the CuttingBody ?
  CATBoolean GetCutVolumeDiagnosis();

  void GetUnknownPositionCells(ListPOfCATCell & oListOfUnknownPositionCells);

  void DisableSimplifMode();

  /** @nodoc @nocgmitf */
  void DisableOperandsPersistency();

  /** @nodoc @nocgmitf */
  void EnableCopyModeForCutting();


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
  CATGMPolySplitVolumeTopOper(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolySplitVolumeTopExt & iExtension);


private:

  //===========================================================================
  // COPY-CONSTRUCTOR et OPERATOR =   Not DEFINED
  //===========================================================================
  
  CATGMPolySplitVolumeTopOper();
  CATGMPolySplitVolumeTopOper(const CATGMPolySplitVolumeTopOper& iOneOf); 
  CATGMPolySplitVolumeTopOper& operator =(const CATGMPolySplitVolumeTopOper& iOneOf);

};

/**
 * @nodoc @nocgmitf (do not create a specific interface)
 * Creates a CATGMPolySplitVolumeTopOper operator.
 * @param iFactory
 * The factory of the geometry. 
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
 * is <tt>NULL</tt>, it is not filled. 
 * @param iBodyToSplit
 * The pointer to the 3D body to split & relimit
 * @param iCuttingBody
 * The pointer to the 3D body disconnecting iBodyToSplit in several parts
 * @param iSplitType
 * The side { CATSplitBothSides, CATSplitPositiveSideOnly, CATSplitNegativeSideOnly} of the disconnected parts to keep, according to the orientation of iCuttingBody
 * @return [out, IUnknown#Release]
 * The pointer to the created operator. To be released with the <tt>Release</tt> method after use.
 */
ExportedByGMPolyBoolean CATGMPolySplitVolumeTopOper * CATCreatePolySplitVolumeTopOper(CATGeoFactory * iFactory, CATTopData * iTopData, 
                                                                                      CATBody * iBodyToSplit, CATBody * iCuttingBody,
                                                                                      CATDynSplitType iSplitType); 

#endif
