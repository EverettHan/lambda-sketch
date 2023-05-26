// COPYRIGHT DASSAULT SYSTEMES 2021, ALL RIGHTS RESERVED.
//=============================================================================
//
// RESPONSIBLE  : VB7
//
// DESCRIPTION  : 
//
// INPUT DATA   : 
//                                     
//
// OPTIONS      : 
//
//=============================================================================
// Creation VB7 June 2021
//=============================================================================

#ifndef CATGMVolumeMergerOpe_H
#define CATGMVolumeMergerOpe_H

#include "AdvTrimOpe.h"
#include "CATPersistentOperator.h"

class CATGMVolumeMergerImpl;
class CATVolume;
class CATFaceHashTable;
class CATCellHashTable;

class ExportedByAdvTrimOpe CATGMVolumeMergerOpe : public CATPersistentOperator
{
  CATCGMVirtualDeclareClass(CATGMVolumeMergerOpe);

public:

  /**
  * Destructor
  */
  virtual ~CATGMVolumeMergerOpe();

  //------------------
  // Set methods
  //------------------
  void SetVolumeJournalList(CATCGMJournalList * iVolumeJournalList);

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

  CATGMVolumeMergerImpl * GetGMVolumeMergerImpl();

  /**
  * Protected constructor : Do not call directly.
  * Use CATCreateGMVolumeMergeOpe() instead.
  */
  CATGMVolumeMergerOpe( CATGeoFactory        * iFactory,
                        CATTopData           * iTopData,
                        CATGMVolumeMergerImpl * iImpl );

  //------------------------------------------------------------------------------
  // Forbidden (Declared but not Defined) : Copy constructor & assignment operator
  //------------------------------------------------------------------------------
  CATGMVolumeMergerOpe ( const CATGMVolumeMergerOpe & );            // Not Implemented
  CATGMVolumeMergerOpe & operator=( const CATGMVolumeMergerOpe & ); // Not Implemented

  //-----------------
  // Friend functions
  //-----------------
  friend ExportedByAdvTrimOpe CATGMVolumeMergerOpe * CATCreateGMVolumeMergerOpe( CATGeoFactory    & iFactory, 
                                                                                 CATTopData       & iTopData, 
                                                                                 CATBody          & iBody,
                                                                                 CATVolume        & iFirstVolume,
                                                                                 CATVolume        & iSecondVolume);

  friend ExportedByAdvTrimOpe CATGMVolumeMergerOpe * CATCreateGMVolumeMergerOpe( CATGeoFactory    & iFactory, 
                                                                                 CATTopData       & iTopData, 
                                                                                 CATBody          & iBody,
                                                                                 ListPOfCATCell   & iVolumeList);

  friend ExportedByAdvTrimOpe CATGMVolumeMergerOpe * CATCreateGMVolumeMergerOpe( CATGeoFactory    & iFactory, 
                                                                                 CATTopData       & iTopData, 
                                                                                 CATBody          & iBody,
                                                                                 CATCellHashTable & iVolumeHT);

  friend ExportedByAdvTrimOpe CATGMVolumeMergerOpe * CATCreateGMVolumeMergerOpe( CATGeoFactory    & iFactory, 
                                                                                 CATTopData       & iTopData, 
                                                                                 CATBody          & iBody,
                                                                                 CATCellHashTable & iVolumeHT,
                                                                                 CATFaceHashTable & iInterfaceHT);

  //With persistentInfra
  friend ExportedByAdvTrimOpe CATGMVolumeMergerOpe * CATCreateGMVolumeMergerOpe( CATGeoFactory          & iFactory, 
                                                                                 CATTopData             & iTopData, 
                                                                                 CATPersistentBody      & iPBody,
                                                                                 CATCellHashTable       & iVolumeHT,
                                                                                 CATPersistentCellInfra & iPInfra);

  friend ExportedByAdvTrimOpe CATGMVolumeMergerOpe * CATCreateGMVolumeMergerOpe( CATGeoFactory          & iFactory, 
                                                                                 CATTopData             & iTopData, 
                                                                                 CATPersistentBody      & iPBody,
                                                                                 CATCellHashTable       & iVolumeHT,
                                                                                 CATFaceHashTable       & iInterfaceHT,
                                                                                 CATPersistentCellInfra & iPInfra);

  //For CGMReplay only
  // @nocgmitf
  friend ExportedByAdvTrimOpe CATGMVolumeMergerOpe * CATCreateGMVolumeMergerOpe( CATGeoFactory    & iFactory, 
                                                                                 CATTopData       & iTopData, 
                                                                                 CATBody          & iBody);

};

  ExportedByAdvTrimOpe CATGMVolumeMergerOpe * CATCreateGMVolumeMergerOpe( CATGeoFactory    & iFactory, 
                                                                          CATTopData       & iTopData, 
                                                                          CATBody          & iBody,
                                                                          CATVolume        & iFirstVolume,
                                                                          CATVolume        & iSecondVolume);

  ExportedByAdvTrimOpe CATGMVolumeMergerOpe * CATCreateGMVolumeMergerOpe( CATGeoFactory    & iFactory, 
                                                                          CATTopData       & iTopData, 
                                                                          CATBody          & iBody,
                                                                          ListPOfCATCell   & iVolumeList);

  ExportedByAdvTrimOpe CATGMVolumeMergerOpe * CATCreateGMVolumeMergerOpe( CATGeoFactory    & iFactory, 
                                                                          CATTopData       & iTopData, 
                                                                          CATBody          & iBody,
                                                                          CATCellHashTable & iVolumeHT);

  ExportedByAdvTrimOpe CATGMVolumeMergerOpe * CATCreateGMVolumeMergerOpe( CATGeoFactory    & iFactory, 
                                                                          CATTopData       & iTopData, 
                                                                          CATBody          & iBody,
                                                                          CATCellHashTable & iVolumeHT,
                                                                          CATFaceHashTable & iInterfaceHT);

  ExportedByAdvTrimOpe CATGMVolumeMergerOpe * CATCreateGMVolumeMergerOpe( CATGeoFactory          & iFactory, 
                                                                          CATTopData             & iTopData, 
                                                                          CATPersistentBody      & iPBody,
                                                                          CATCellHashTable       & iVolumeHT,
                                                                          CATPersistentCellInfra & iPInfra);

  ExportedByAdvTrimOpe CATGMVolumeMergerOpe * CATCreateGMVolumeMergerOpe( CATGeoFactory          & iFactory, 
                                                                          CATTopData             & iTopData, 
                                                                          CATPersistentBody      & iPBody,
                                                                          CATCellHashTable       & iVolumeHT,
                                                                          CATFaceHashTable       & iInterfaceHT,
                                                                          CATPersistentCellInfra & iPInfra);

  // @nocgmitf
  ExportedByAdvTrimOpe CATGMVolumeMergerOpe * CATCreateGMVolumeMergerOpe( CATGeoFactory    & iFactory, 
                                                                          CATTopData       & iTopData, 
                                                                          CATBody          & iBody);


#endif /* CATGMVolumeMergerOpe_H */
