/* -*-C++-*-*/
#ifndef CATGMPolySplitWireTopOper_H
#define CATGMPolySplitWireTopOper_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2015
//
// CATGMPolySplitWireTopOper
//
// DESCRIPTION :
// Split a 1D body by a body made of vertices
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
#include "CATTopDefine.h"         // CATSide

#include "CATListOfCATCells.h"

class CATGeoFactory;
class CATTopData;
class CATBody;
class CATGMPolyOperTopExt;

/** @nodoc @nocgmitf (do not create any specific interface) */
class ExportedByGMPolyBoolean CATGMPolySplitWireTopOper : public CATGMPolyTopOperator
{
  CATCGMVirtualDeclareClass(CATGMPolySplitWireTopOper);

public:


  /**
  * Destructor
  */
  virtual ~CATGMPolySplitWireTopOper();


  /** @nodoc 
  * cannot be called
  */
  // Please, call CATCreateGMPolyBodyBooleanTopOper() method to create an instance
  static CATGMPolySplitWireTopOper * New(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyOperTopExt & iExtension);


  //=============================================================================
  // Settings
  //=============================================================================

  /** @nodoc @nocgmitf */
  void SetSelectedCells(CATLISTP(CATCell) &iCellsToRemove, CATLISTP(CATCell) &iCellsToKeep);

  /** @nodoc @nocgmitf */
  // A threshold of contact is useful only if the cutting body is a wire to lay down on the body to plit.
  // In this case, the input threshold has to be greater than the resolution (0.001mm in NormalScale) and smaller than the LargeResolution(0.1mm in NS)
  // The default threshold value is the factory resolution (0.001mm in NormalScale)
  void SetContactThreshold(double iContactThreshold);

  /** @nodoc @nocgmitf */
  void SetKeepHalfSpaceMode(CATBoolean iMode_SemiSpace);

  ///** @nodoc @nocgmitf */
  //// In some cases, we want to keep the vertex splitter in the body result
  //// By default the splitter will not be kept
  //void SetKeepSplitterVertexInResult(CATBoolean iKeepVtx);

  /** @nodoc @nocgmitf */
  // In some cases, we want to split a closed wire by stopping at closure vertex
  void AuthorizeStopAtClosure(CATBoolean iStopAtClosure);


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
  CATGMPolySplitWireTopOper(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyOperTopExt & iExtension);


private:

  //===========================================================================
  // COPY-CONSTRUCTOR et OPERATOR =   Not DEFINED
  //===========================================================================
  
  CATGMPolySplitWireTopOper();
  CATGMPolySplitWireTopOper(const CATGMPolySplitWireTopOper& iOneOf); 
  CATGMPolySplitWireTopOper& operator =(const CATGMPolySplitWireTopOper& iOneOf);

};

/**
 * @nodoc @nocgmitf (do not create a specific interface)
 * Creates a CATGMPolySplitWireTopOper operator.
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
ExportedByGMPolyBoolean CATGMPolySplitWireTopOper * CATCreatePolySplitWireByShellTopOper(CATGeoFactory * iFactory, CATTopData * iTopData, 
                                                                                    CATBody * iBodyToSplit, CATBody * iCuttingBody,
                                                                                    CATSide  iSideToKeep=CATSideUnknown); 

ExportedByGMPolyBoolean CATGMPolySplitWireTopOper * CATCreatePolySplitWireByVtxTopOper(CATGeoFactory * iFactory, CATTopData * iTopData, 
                                                                                    CATBody * iBodyToSplit, CATBody * iCuttingBody,
                                                                                    CATSide  iSideToKeep=CATSideUnknown); 

ExportedByGMPolyBoolean CATGMPolySplitWireTopOper * CATCreatePolySplitWireByWireTopOper(CATGeoFactory * iFactory, CATTopData * iTopData, 
                                                                                    CATBody * iBodyToSplit, CATBody * iCuttingBody,
                                                                                    CATSide  iSideToKeep=CATSideUnknown); 

ExportedByGMPolyBoolean CATGMPolySplitWireTopOper * CATCreatePolySplitWireTopOper(CATGeoFactory * iFactory, CATTopData * iTopData, 
                                                                                    CATBody * iBodyToSplit, CATBody * iCuttingBody,
                                                                                    CATSide  iSideToKeep=CATSideUnknown); 

ExportedByGMPolyBoolean CATGMPolySplitWireTopOper * CATCreatePolySplitWireOnSupportTopOper( CATGeoFactory * iFactory, CATTopData * iTopData,
                                                                                            CATBody * iBodyToSplit, CATBody * iCuttingBody,
                                                                                            CATBody * iBodySupport,
                                                                                            CATSide  iSideToKeep=CATSideUnknown); 

ExportedByGMPolyBoolean CATGMPolySplitWireTopOper * CATCreatePolyClipWireTopOper(CATGeoFactory * iFactory, CATTopData * iTopData, 
                                                                                 CATBody * iBodyToSplit, CATBody * iCuttingBody,
                                                                                 CATSide  iSideToKeep=CATSideUnknown); 

#endif
