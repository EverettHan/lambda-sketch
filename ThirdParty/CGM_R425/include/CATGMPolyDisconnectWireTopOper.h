/* -*-C++-*-*/
#ifndef CATGMPolyDisconnectWireTopOper_H
#define CATGMPolyDisconnectWireTopOper_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2016
//
// CATGMPolyDisconnectWireTopOper
//
// DESCRIPTION :
// Disconnect Operation of a wireframe polyhedral body by a list of vertices
//
//
// History
//
// February 2017 CLO2 Creation
//
//=============================================================================

// For Windows NT export
#include "CATGMPolyTopOperator.h" // derivation
#include "CATVertex.h"
#include "GMPolyBoolean.h"        // ExportedBy

#include "CATDataType.h"          // HRESULT
#include "CATMathInline.h"        // inline Methods
#include "ListPOfCATBody.h"       // aggregation

#include "CATBoolean.h"
#include "CATSysBoolean.h"
#include "CATMapOfPtrToPtr.h"             
#include "ListPOfCATDomain.h"
#include "CATListOfInt.h"

class CATGeoFactory;
class CATTopData;
class CATBody;
class CATGMPolyDisconnectWireByVtxTopExt;


/** @nodoc @nocgmitf (do not create any specific interface) */
class ExportedByGMPolyBoolean CATGMPolyDisconnectWireTopOper : public CATGMPolyTopOperator
{
  CATCGMVirtualDeclareClass(CATGMPolyDisconnectWireTopOper);

public:


  /**
  * Destructor
  */
  virtual ~CATGMPolyDisconnectWireTopOper();


  /** @nodoc 
  * cannot be called
  */
  // Please, call CATCreatePolyBodyJoinTopOper() method to create an instance
  static CATGMPolyDisconnectWireTopOper * New(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyDisconnectWireByVtxTopExt & iExtension);


  //=============================================================================
  // Get Method
  //=============================================================================

  //return: list of domains of the disconnected body
  //        list of splitters number per domain
  //        list of rank for each splitter
  void GetResultedLists (ListPOfCATDomain& DisconnectedWires, CATListOfInt& NbWireSplitters, CATListOfInt& SplittersRanks);

  //Return a Map of the created vertices and the input Splitter used for their creation
  void GetMapOfNewVertices (CATMapOfPtrToPtr& MapNewVertices);

  // ------------------------------------------------------------------------
  //return: a list of Separate Pack Numbers
  //        a list of Separate Sides
  //        a list of Separate Cells
  // ------------------------------------------------------------------------
  void GetSeparateLists (CATListOfInt& SeparatePackNumbers, 
                         CATListOfInt& SeparateSides, 
                         ListPOfCATCell& SeparateCells, 
                         CATListOfInt& SeparateOris);

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
  // Please, call CATCreatePolyBodyJoinTopOper() method to create an instance
  CATGMPolyDisconnectWireTopOper(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyDisconnectWireByVtxTopExt & iExtension);


private:

  //===========================================================================
  // COPY-CONSTRUCTOR et OPERATOR =   Not DEFINED
  //===========================================================================
  
  CATGMPolyDisconnectWireTopOper();
  CATGMPolyDisconnectWireTopOper(const CATGMPolyDisconnectWireTopOper& iOneOf); 
  CATGMPolyDisconnectWireTopOper& operator =(const CATGMPolyDisconnectWireTopOper& iOneOf);

};

/**
 * @nodoc @nocgmitf (do not create a specific interface)
 * Creates a CATCreatePolyDisconnectWireByVtx operator.
 * @param iFactory
 * The factory of the geometry. 
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
 * is <tt>NULL</tt>, it is not filled. 
 * @param iBodyToDisconnect
 * The pointer to the Wireframe Body to disconnect
 * @param iCuttingBody
 * The pointer to the cutting body - made of vertices
 * @return [out, IUnknown#Release]
 * The pointer to the created operator. To be released with the <tt>Release</tt> method after use.
 */
ExportedByGMPolyBoolean CATGMPolyDisconnectWireTopOper * CATCreatePolyDisconnectWireByVtx(CATGeoFactory * iFactory, CATTopData * iTopData, 
                                                                                          CATBody * iBodyToDisconnect, CATBody * iCuttingBody);

#endif
