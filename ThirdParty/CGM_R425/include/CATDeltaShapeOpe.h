// COPYRIGHT DASSAULT SYSTEMES 2014, ALL RIGHTS RESERVED.
//=============================================================================
//
// RESPONSIBLE  : UF9
//
// DESCRIPTION  : Delta Operator
// /!\  /!\  /!\       DO NOT USE    /!\  /!\  /!\              
// /!\  /!\  /!\   UNDER DEVELOPMENT /!\  /!\  /!\                 
//                
//                
//
//=============================================================================
// Creation UF9 January 2014
//=============================================================================

#ifndef NULL
#define NULL 0
#endif

#ifndef CATDeltaShapeOpe_H
#define CATDeltaShapeOpe_H

#include "AdvTrimOpe.h"
#include "CATPersistentOperator.h"
#include "ListPOfCATFace.h"

class CATDeltaShapeImpl;
class CATBody;
class CATString;
class CATCGMJournalList;

class ExportedByAdvTrimOpe CATDeltaShapeOpe : public CATPersistentOperator
{
  CATCGMVirtualDeclareClass(CATDeltaShapeOpe);

public:


  /**
  * Destructor
  */
  virtual ~CATDeltaShapeOpe();

  /**
  * @nocgmitf
  * Runs <tt>this</tt> operator.
  */
  int RunOperator();

  void SetInputBody2(CATBody & iBody2,  CATCGMJournalList* ioJournal=NULL);
  //------------------
  // CGMREPLAY METHODS
  //------------------

  /** @nocgmitf ID for CGMReplay */
  static const CATString * GetDefaultOperatorId();

  /** @nocgmitf ID for CGMReplay */
  const CATString * GetOperatorId();

  /** @nocgmitf for  CGMReplay */
  CATExtCGMReplay * IsRecordable( short & oLevelOfRuntime, short & oVersionOfStream );

  /** @nocgmitf for CGMReplay */
  void WriteInput( CATCGMStream  & oStr );

  /** @nocgmitf for CGMReplay */
  void ReadInput( CATCGMStream  & iStr, int iVersionOfStream,  CATCGMJournalList*& ioJournal );

  /** @nocgmitf for CGMReplay */
  void Dump( CATCGMOutput & oStr ) ;

  /** @nocgmitf for CGMReplay */
  void RequireDefinitionOfInputAndOutputObjects();


protected:


      /**
  * Protected constructor: use the CATCreateDeltaOpe instead
  */
  CATDeltaShapeOpe( CATGeoFactory    * iFactory,
    CATTopData       * iTopData,
    CATDeltaShapeImpl * iImpl );

  CATDeltaShapeImpl * GetDeltaImpl() const;



  //------------------------------------------------------------------------------
  // Forbidden (Declared but not Defined) : Copy constructor & assignment operator
  //------------------------------------------------------------------------------
  CATDeltaShapeOpe ( const CATDeltaShapeOpe & );            // Not Implemented
  CATDeltaShapeOpe & operator=( const CATDeltaShapeOpe & ); // Not Implemented

  //-----------------
  // FRIEND FUNCTIONS
  //-----------------
  friend ExportedByAdvTrimOpe CATDeltaShapeOpe * CATCreateDeltaShapeOpe( CATGeoFactory * iFactory, CATTopData * iTopData, CATBody * iBody1, CATBody * iBody2, CATCGMJournalList *iJournal);
};

// ---------------------
// CATCreateDeltaOpe
// ---------------------
ExportedByAdvTrimOpe CATDeltaShapeOpe * CATCreateDeltaShapeOpe( CATGeoFactory            * iFactory,
                                                                CATTopData               * iTopData,
                                                                CATBody                  * iBody1,
                                                                CATBody                  * iBody2,
                                                                CATCGMJournalList        * iJournal = NULL);

#endif /* CATDeltaShapeOpe_H */
