/* -*-C++-*-*/
#ifndef CATGMPolyTopOperator_H
#define CATGMPolyTopOperator_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2017
//
// CATGMPolyTopOperator
//
// DESCRIPTION :
// virtual mother class for all polyhedral CATTopOperator derivations
//
//
// History
//
// Sept. 2017 DPS Creation
//
//=============================================================================

// For Windows NT export
#include "CATTopOperator.h"     // derivation
#include "GMPolyBasicOper.h"    // ExportedBy
#include "CATBodyFreezeMode.h"

#include "CATMathInline.h"      // inline Methods

#include "CATBoolean.h"
#include "CATSysBoolean.h"
#include "CATSysErrorDef.h"     // HRESULT


class CATGeoFactory;
class CATTopData;
class CATBody;
class CATGMPolyOperTopExt;
class CATExtCGMReplay;
class CATCGMStream;
class CATCGMOutput;
class CATString;



class ExportedByGMPolyBasicOper CATGMPolyTopOperator : public CATTopOperator
{
  CATCGMVirtualDeclareClass(CATGMPolyTopOperator);

public:


  /**
  * Destructor
  */
  virtual ~CATGMPolyTopOperator();

    
  /**
  * Settings
  * @nodoc @nocgmitf 
  */
  // Manages the type of the result body : exact instead of polyhedral (default)
  // This service is limited to bodies whose the cells have a basic geometry : vertex in space, linear edges, planar faces whose the bounding edges are linear
  // iBasicBodyMaxDimTrigger allows the caller to pilot the conversion to exact data according to the dimension of the result Body
  // 0 : Only Vertex Bodies can be converted to exact (default)
  // 1 : Vtx & Wires Bodies can be converted to exact
  // 2 : Vtx, Wires, Shells can be converted to exact
  // >= 3 : all poly Bodies can be converted to exact
  // returns TRUE if the request is authorized by the operator, else returns FALSE
  // A returned value equal to TRUE doesn't mean that the conversion is possible.
  // The user has to call GetExactResultStatus after RunOperator to know if the conversion succeeded or not
  CATBoolean SetConversionToExactResult(int iBasicBodyMaxDimTrigger=0);

  /** @nodoc @nocgmitf */
  void SetPersistencyTransactionMode(CATBoolean iEnablePersistencyTransaction);

  /**
  * @nodoc @nocgmitf 
  * returns oConvertedToExact equal to TRUE if the Result Body has been converted to exact, else FALSE
  */
  void GetResultConversionStatus(CATBoolean &oConvertedToExact);


  /**
  * Computation method returning the result Body (may be null), including CATTry/CATCatch mechanism
  * This method guarantees that the potential error is caught
  */
  HRESULT RunAndGetResult(CATBody * &oResultBody, CATError * &oResultError, CATBodyFreezeMode iFreezeMode=CATBodyFreezeOff, CATBoolean iPersistencyTransactionMode=FALSE);

  /**
  * @nodoc @nocgmitf 
  */
  INLINE CATGMPolyOperTopExt & GetPolyOperExtension();


  /**
  * internal use only
  * ioCompleteJournal
  * Need to call it after run if succeeded
  */
  CATBoolean DuplicateJournalForCellTracker(CATCGMJournalList*& ioComplteJournal);

protected:

  /**
  * Constructor
  * @nodoc @nocgmitf 
  */
  CATGMPolyTopOperator(CATGeoFactory & iFactory, const CATTopData & iTopData, CATGMPolyOperTopExt & iPolyExtension);


  /**
  * Runs the operator
  * @nodoc @nocgmitf 
  */
  virtual int RunOperator();

protected:
  
  // ------------------
  // CGMReplay Methods
  // ------------------
  /* @nodoc @nocgmitf */
  virtual const CATString * GetOperatorId();
  virtual void RequireDefinitionOfInputAndOutputObjects();


private:

  //===========================================================================
  // COPY-CONSTRUCTOR et OPERATOR =   Not DEFINED
  //===========================================================================
  
  CATGMPolyTopOperator();
  CATGMPolyTopOperator(const CATGMPolyTopOperator& iOneOf); 
  CATGMPolyTopOperator& operator =(const CATGMPolyTopOperator& iOneOf);


protected:
   
  CATGMPolyOperTopExt &             _PolyOperExtension;

};

// INLINE methods
// ==============

INLINE CATGMPolyOperTopExt & CATGMPolyTopOperator::GetPolyOperExtension() {
  return _PolyOperExtension; }

#endif
