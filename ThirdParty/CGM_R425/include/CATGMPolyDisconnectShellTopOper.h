/* -*-C++-*-*/
#ifndef CATGMPolyDisconnectShellTopOper_H
#define CATGMPolyDisconnectShellTopOper_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2017
//
// CATGMPolyDisconnectShellTopOper
//
// DESCRIPTION :
// Disconnect a shell body by a wire body
//
//
// History
//
// October 2017 DPS Creation
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
class CATGMPolyDisconnectShellTopExt;
class CATGMPolyDisconnectVolumeTopExt;

/** @nodoc @nocgmitf (do not create any specific interface) */
class ExportedByGMPolyBoolean CATGMPolyDisconnectShellTopOper : public CATGMPolyTopOperator
{
  CATCGMVirtualDeclareClass(CATGMPolyDisconnectShellTopOper);

public:


  /**
  * Destructor
  */
  virtual ~CATGMPolyDisconnectShellTopOper();


  /** @nodoc 
  * cannot be called
  */
  // Please, call CATCreatePolyBodyJoinTopOper() method to create an instance
  static CATGMPolyDisconnectShellTopOper * New(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyOperTopExt & iExtension);


  //=============================================================================
  // Settings
  //=============================================================================  

  /** 
  * Option activating the computation of the map between the new edges and their original cells from iDisconnectingBody
  * see also GetMapOfDisconnectingEdges()
  */  
  void ActivateMapping();

  /** 
  * Option activating the separation of the result faces in packs 
  * see also GetSeparateLists()
  */
  void ActivateCellPacks(CATBoolean iComputePackSides=FALSE);

  
  /** 
  * @param iContactThreshold
  * Contact tolerance value greater than the resolution (0.001mm in NormalScale) and smaller than the LargeResolution(0.1mm in NS)
  * The default threshold value is the factory resolution (0.001mm in NormalScale)
  */
  void SetContactThreshold(double iContactThreshold);

  /**
  * @nodoc
  * To be called before the <tt>Run</tt> method.
  * Activate cutting edges report (internal use only).
  */
  void ReportInternalEdges();

  ///**
  //* @nodoc
  //* To be called before the <tt>Run</tt> method.
  //* Activate complete journal (internal use only).
  //*/
  //void SetCompleteJournal(CATCGMJournalList& ioCompleteJournal);


  //=============================================================================
  // Get Method
  //=============================================================================

  /** 
  * Return a Map of the new created edges to their original disconnecting cells from iDisconnectingBody
  * To call after the Run
  * returns an empty map if ActivateMapping() hasn't been called before the Run
  */
  void GetBackwardMapOfDisconnectingEdges(CATMapOfPtrToPtr & oNewEdgesToInputEdges);


  /**
  * Return a list of result cells and parallel information : 
  *          associated orientation in the Result Body, pack number and pack side (unknown, left, right or full)
  * To call after the Run
  * returns empty lists if ActivateCellPacks() hasn't been called before the Run
  * oPackSides will be filled only if the PackSideComputation has been enabled through ActivateCellPacks(TRUE)
  */
  void GetSeparateLists (ListPOfCATCell & oResultCells, 
                         CATListOfInt   & oCellsOri,
                         CATListOfInt   & oPackNumbers, 
                         CATListOfInt   * oPackSides=NULL);


  /**
  * Return all output list
  */
  void GetAllOutputList(ListPOfCATCell & oPackCells,
                        CATListOfInt   & oCellsOri,
                        CATListOfInt   & oPackSizes,
                        CATListOfInt   & oPackSides,
                        ListPOfCATCell & oImageIntersectionCells,
                        ListPOfCATCell & oSourceIntersectionCells);



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
  CATGMPolyDisconnectShellTopOper(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyOperTopExt & iExtension);


private:

  //===========================================================================
  // COPY-CONSTRUCTOR et OPERATOR =   Not DEFINED
  //===========================================================================
  
  CATGMPolyDisconnectShellTopOper();
  CATGMPolyDisconnectShellTopOper(const CATGMPolyDisconnectShellTopOper& iOneOf); 
  CATGMPolyDisconnectShellTopOper& operator =(const CATGMPolyDisconnectShellTopOper& iOneOf);

};

/**
 * @nodoc @nocgmitf (do not create a specific interface)
 * Creates a CATCreatePolyDisconnectShellByWire operator.
 * @param iFactory
 * The factory of the geometry. 
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt> 
 * is <tt>NULL</tt>, it is not filled. 
 * @param iShellBodyToDisconnect
 * The pointer to the Body 2D to disconnect
 * @param iDisconnectingWireBody
 * The pointer to the cutting body 1D
 * @return [out, IUnknown#Release]
 * The pointer to the created operator. To be released with the <tt>Release</tt> method after use.
 */
ExportedByGMPolyBoolean CATGMPolyDisconnectShellTopOper * CATCreatePolyDisconnectShellTopOper(CATGeoFactory * iFactory, CATTopData * iTopData, 
                                                                                              CATBody * iShellBodyToDisconnect, CATBody * iDisconnectingWireBody);

#endif
