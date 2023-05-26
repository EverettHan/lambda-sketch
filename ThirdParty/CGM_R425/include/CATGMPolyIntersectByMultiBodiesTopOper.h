#pragma once
/* -*-C++-*-*/
#ifndef CATGMPolyIntersectByMultiBodiesTopOper_H
#define CATGMPolyIntersectByMultiBodiesTopOper_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2016
//
// CATGMPolyIntersectByMultiBodiesTopOper
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
#include "CATListOfCATCGMJournals.h" 


class CATGeoFactory;
class CATTopData;
class CATBody;
class CATGMPolyIntersectByMultiBodiesTopExt;


/** @nodoc @nocgmitf (do not create any specific interface) */
class ExportedByGMPolyBoolean CATGMPolyIntersectByMultiBodiesTopOper : public CATGMPolyTopOperator
{
  CATCGMVirtualDeclareClass(CATGMPolyIntersectByMultiBodiesTopOper);

public:


  /**
  * Destructor
  */
  virtual ~CATGMPolyIntersectByMultiBodiesTopOper();

  //=============================================================================
// Settings
//=============================================================================

/** @nodoc @nocgmitf */
// Enable/Disable the "Disassemble" of final result in one result per intersecting body
// Default mode is FALSE (disabled)
  void EnableDisassembleResult();

  HRESULT GetAllSeparatedResults(ListPOfCATBody & oListOfSeparatedResults, CATListPtrCATCGMJournal & oListOfSeparatedJournals);


  /** @nodoc
  * cannot be called
  */
  // Please, call CATCreateGMPolyBodyBooleanTopOper() method to create an instance
  static CATGMPolyIntersectByMultiBodiesTopOper* New(CATGeoFactory& iFactory, const CATTopData& iTopData, CATGMPolyIntersectByMultiBodiesTopExt& iExtension);


  // ------------------
  // CGMReplay Methods
  // ------------------
  /** @nodoc
   * @nocgmitf
  */
  static const CATString* GetDefaultOperatorId();


protected:

  /** @nodoc
  * cannot be called
  */
  // Constructor
  // Please, call CATCreateGMPolyBodyBooleanTopOper() method to create an instance
  CATGMPolyIntersectByMultiBodiesTopOper(CATGeoFactory& iFactory, const CATTopData& iTopData, CATGMPolyIntersectByMultiBodiesTopExt& iExtension);


private:

  //===========================================================================
  // COPY-CONSTRUCTOR et OPERATOR =   Not DEFINED
  //===========================================================================

  CATGMPolyIntersectByMultiBodiesTopOper();
  CATGMPolyIntersectByMultiBodiesTopOper(const CATGMPolyIntersectByMultiBodiesTopOper& iOneOf);
  CATGMPolyIntersectByMultiBodiesTopOper& operator =(const CATGMPolyIntersectByMultiBodiesTopOper& iOneOf);

};

/**
 * @nodoc @nocgmitf (do not create a specific interface)
 * Creates a CATGMPolyIntersectByMultiBodiesTopOper operator.
 * @param iFactory
 * The factory of the geometry.
 * @param iTopData
 * The pointer to the data defining the software configuration and the journal. If the journal inside <tt>iTopData</tt>
 * is <tt>NULL</tt>, it is not filled.
 * @param iBodyToIntersect
 * The pointer to the operand body to intersect
 * @param iIntersectingBodies
 * the list of intersecting bodies
 * @return [out, IUnknown#Release]
 * The pointer to the created operator. To be released with the <tt>Release</tt> method after use.
 */
ExportedByGMPolyBoolean CATGMPolyIntersectByMultiBodiesTopOper* CATCreatePolyIntersectByMultiBodiesTopOper(CATGeoFactory* iFactory, CATTopData* iTopData,
  CATBody* iBodyToIntersect, ListPOfCATBody& iIntersectingBodies);

#endif
