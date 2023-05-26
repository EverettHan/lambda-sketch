/* -*-C++-*-*/
#ifndef CATGMPolyShellFromClosedWireTopOper_H
#define CATGMPolyShellFromClosedWireTopOper_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2015
//
// CATGMPolyShellFromClosedWireTopOper
//
// DESCRIPTION :
// Create a planar shell body from a PH planar closed wire 
//
//
// History
//
//  March. 2017 CLO2 Creation
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

#include "ListPOfCATBody.h"
#include "CATListOfCATSurfaces.h"

class CATGeoFactory;
class CATTopData;
class CATBody;
class CATGMPolyOperTopExt;

/** @nodoc @nocgmitf (do not create any specific interface) */
class ExportedByGMPolyBoolean CATGMPolyShellFromClosedWireTopOper : public CATGMPolyTopOperator
{
  CATCGMVirtualDeclareClass(CATGMPolyShellFromClosedWireTopOper);

public:


  /**
  * Destructor
  */
  virtual ~CATGMPolyShellFromClosedWireTopOper();


  /** @nodoc 
  * cannot be called
  */
  // Please, call CATCreateGMPolyBodyBooleanTopOper() method to create an instance
  static CATGMPolyShellFromClosedWireTopOper * New(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyOperTopExt & iExtension);


  //=============================================================================
  // Settings
  //=============================================================================
  /**
  * By default we don't keep all created faces. 
  * @param iKeepAllFaces
  */
  void SetKeepAllFaces(CATBoolean iKeepAllFaces);

  /** To be called before run for modelisation organisation.
  *
  * It allows the computation of input wire bodies clashes during the Run method. 
  * It can repair the result
  * if this activated, the number of autocrossing can get after run
  * @param iInputClashMode =  3 check and use checked and optimized result
  *                           2 check and use checked result without optimization
  *                           1 check only
  *                           0 inactivated 
  *                           else error
  */
  void SetInputClashMode(int iInputClashMode);

  /**
  * By default Wires Input are in Creation Mode. 
  * @param iWiresCreationMode
  */
  void SetWiresCreationMode(CATBoolean iWiresCreationMode);

  
  //=============================================================================
  // Output information to get
  //=============================================================================

  //
  // To be called after run .
  // Get the number of autocrossing detected if SetInputClashMode is activated
  //
  int GetNbAutoCrossing();


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
  CATGMPolyShellFromClosedWireTopOper(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyOperTopExt & iExtension);


private:

  //===========================================================================
  // COPY-CONSTRUCTOR et OPERATOR =   Not DEFINED
  //===========================================================================
  
  CATGMPolyShellFromClosedWireTopOper();
  CATGMPolyShellFromClosedWireTopOper(const CATGMPolyShellFromClosedWireTopOper& iOneOf); 
  CATGMPolyShellFromClosedWireTopOper& operator =(const CATGMPolyShellFromClosedWireTopOper& iOneOf);

};

/**
 * @nodoc @nocgmitf (do not create a specific interface)
 * Creates a CATGMPolyShellFromClosedWireTopOper operator.
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
ExportedByGMPolyBoolean CATGMPolyShellFromClosedWireTopOper * CATCreatePolyShellFromClosedWireTopOper(CATGeoFactory        * iFactory,
                                                                                                      CATTopData           * iTopDataCATGeoFactory, 
                                                                                                      ListPOfCATBody       & inputBodies, 
                                                                                                      CATPlane             & iPlane); 

/**
 * @nodoc @nocgmitf (do not create a specific interface)
 * Creates a CATGMPolyShellFromClosedWireTopOper operator.
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
ExportedByGMPolyBoolean CATGMPolyShellFromClosedWireTopOper * CATCreatePolyShellFromClosedWireTopOper(CATGeoFactory        * iFactory,
                                                                                                      CATTopData           * iTopDataCATGeoFactory, 
                                                                                                      CATBody              & inputBody, 
                                                                                                      CATPlane             & iPlane);

#endif
