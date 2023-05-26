// COPYRIGHT DASSAULT SYSTEMES 2018, ALL RIGHTS RESERVED.
//=============================================================================
//
// RESPONSIBLE  : VB7
//
// DESCRIPTION  : 
//
// INPUT DATA   : 
//                
//
//=============================================================================
// Creation VB7 September 2018
//=============================================================================

#ifndef CATlsoMultiShellBodyExploderOpe_H
#define CATlsoMultiShellBodyExploderOpe_H

#include "AdvTrimOpe.h"
#include "CATPersistentOperator.h"

class CATlsoMultiShellBodyExploderImpl;

class ExportedByAdvTrimOpe CATlsoMultiShellBodyExploderOpe : public CATPersistentOperator
{
  CATCGMVirtualDeclareClass(CATlsoMultiShellBodyExploderOpe);

public:

  /**
  * Destructor
  */
  virtual ~CATlsoMultiShellBodyExploderOpe();

  //------------------
  // Set methods
  //------------------
  void SetLinearExplosionMode();
  void SetStarExplosionMode();
  void SetNaturalExplosionMode();

  //------------------
  // CGMReplay methods
  //------------------
  // @nocgmitf
  static const CATString * GetDefaultOperatorId();

  // @nocgmitf
  const CATString * GetOperatorId();

  // @nocgmitf
  CATExtCGMReplay * IsRecordable( short & LevelOfRuntime, short &VersionOfStream );

  // @nocgmitf
  void WriteInput( CATCGMStream  & Str );

  // @nocgmitf
  void ReadInput( CATCGMStream  & ioStr, int VersionOfStream);

  // @nocgmitf
  void Dump( CATCGMOutput& os ) ;

  // @nocgmitf
  void DumpOutput( CATCGMOutput &os );

  // @nocgmitf
  void RequireDefinitionOfInputAndOutputObjects();

protected:

  CATlsoMultiShellBodyExploderImpl * GetlsoMultiShellBodyExploderImpl();

  /**
  * Protected constructor : Do not call directly.
  * Use CATCreatelsoMultiShellBodyExploderOpe() instead.
  */
  CATlsoMultiShellBodyExploderOpe( CATGeoFactory                    * iFactory,
                                   CATTopData                       * iTopData,
                                   CATlsoMultiShellBodyExploderImpl * iImpl );

  //------------------------------------------------------------------------------
  // Forbidden (Declared but not Defined) : Copy constructor & assignment operator
  //------------------------------------------------------------------------------
  CATlsoMultiShellBodyExploderOpe ( const CATlsoMultiShellBodyExploderOpe & );            // Not Implemented
  CATlsoMultiShellBodyExploderOpe & operator=( const CATlsoMultiShellBodyExploderOpe & ); // Not Implemented

  
  friend ExportedByAdvTrimOpe CATlsoMultiShellBodyExploderOpe * CATCreatelsoMultiShellBodyExploderOpe( CATGeoFactory    & iFactory, 
                                                                                                       CATTopData       & iTopData, 
                                                                                                       CATBody          & iBody);

};

// ----------------------
// CATCreatelsoMultiShellBodyExploderOpe
// ----------------------
ExportedByAdvTrimOpe CATlsoMultiShellBodyExploderOpe * CATCreatelsoMultiShellBodyExploderOpe( CATGeoFactory    & iFactory, 
                                                                                              CATTopData       & iTopData, 
                                                                                              CATBody          & iBody);
#endif /* CATlsoMultiShellBodyExploderOpe */
