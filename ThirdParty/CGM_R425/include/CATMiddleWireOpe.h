//
//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2023, ALL RIGHTS RESERVED.
//=============================================================================
//
// RESPONSIBLE  : L5K
//
// DESCRIPTION  : Middle Wire Operator
// This operator computes a wire that is equidistant to two wires given in input
//
//=============================================================================
// Creation L5K April 2033
//=============================================================================
//
#ifndef CATMiddleWireOpe_H
#define CATMiddleWireOpe_H

#include "CATDRepOperator.h"
#include "MultiWireCoupling.h"

class CATTopData;
class CATBody;
class CATCGMStream;
class CATCGMOutput;
class CATMiddleWireImpl;
class CATSoftwareConfiguration;
class CATListPtrCATEdge;

class ExportedByMultiWireCoupling CATMiddleWireOpe : public CATDRepOperator
{
  CATCGMVirtualDeclareClass(CATMiddleWireOpe);

public : 
  
  // ---------------------------------------------------
  // Destructor
  // ---------------------------------------------------
  virtual ~CATMiddleWireOpe();
  
  // ---------------------------------------------------
  // Setters
  // ---------------------------------------------------

  /**
  * Appends the lists of edges defining the two input wires
  * (use only if a unique input body has been provided)
  * (The edges must belong to that body)
  * @param iListEdges1
  * First list of edges 
  * @param iListEdges2
  * Second List Of edges
  */
  void AppendEdgeSets(CATLISTP(CATEdge) & iListEdges1, CATLISTP(CATEdge) & iListEdges2 );


  //------------------
  // CGMREPLAY METHODS
  //------------------

  /** @nocgmitf ID for CGMReplay */
  static const CATString * GetDefaultOperatorId();
  /** @nocgmitf ID for CGMReplay */
  const CATString * GetOperatorId();
  /** @nocgmitf for  CGMReplay */
  CATExtCGMReplay * IsRecordable(short & oLevelOfRuntime, short & oVersionOfStream);
  /** @nocgmitf for CGMReplay */
  void WriteInput(CATCGMStream  & oStr);
  /** @nocgmitf for CGMReplay */
  void ReadInput(CATCGMStream  & iStr, int iVersionOfStream);
  /** @nocgmitf for CGMReplay */
  void WriteOutput(CATCGMStream & oStr);
  /** @nocgmitf for CGMReplay */
  CATBoolean ValidateOutput(CATCGMStream & iStr, CATCGMOutput & oStr, int iVersionNumber = 1);
  /** @nocgmitf for CGMReplay */
  void Dump(CATCGMOutput & oStr);
  /** @nocgmitf for CGMReplay */
  void DumpOutput(CATCGMOutput & oStr);
  /** @nocgmitf for CGMReplay */
  void RequireDefinitionOfInputAndOutputObjects();
  /** @nocgmitf for CGMReplay */
  void SetCGMMode(short iCGMMode);


protected :

  // ---------------------------------------------------
  // Constructor
  // Do not use, use methods CATCreateMiddleCurveOpe()
  // ---------------------------------------------------
  CATMiddleWireOpe(CATGeoFactory * iFactory, CATTopData  * iTopData, CATMiddleWireImpl * iImpl);


  // ---------------------------------------------------
  // Accessors 
  // ---------------------------------------------------
  CATMiddleWireImpl * GetMiddleWireImpl() const;


  // ---------------------------------------------------
  // Friend functions
  // ---------------------------------------------------
  friend ExportedByMultiWireCoupling CATMiddleWireOpe* CATCreateMiddleWireOpe(CATGeoFactory * iFactory, CATTopData  * iTopData, CATBody * iInputBody);
  friend ExportedByMultiWireCoupling CATMiddleWireOpe* CATCreateMiddleWireOpe(CATGeoFactory * iFactory, CATTopData  * iTopData, CATBody * iInputBody1, CATBody * iInputBody2);
};

// ----------------------
// CATCreateMiddleWireOpe
// ----------------------
ExportedByMultiWireCoupling CATMiddleWireOpe * CATCreateMiddleWireOpe(CATGeoFactory * iFactory, CATTopData * iTopData, CATBody * iInputBody);
ExportedByMultiWireCoupling CATMiddleWireOpe * CATCreateMiddleWireOpe(CATGeoFactory * iFactory, CATTopData * iTopData, CATBody * iInputBody, CATBody * iInputBody2);

#endif /* CATMiddleWireOpe_H */
