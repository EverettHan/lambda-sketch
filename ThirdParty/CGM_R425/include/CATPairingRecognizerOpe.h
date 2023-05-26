// COPYRIGHT DASSAULT SYSTEMES 2021, ALL RIGHTS RESERVED.
//=============================================================================
//
// RESPONSIBLE  : ZUT
//
// DESCRIPTION  : CATPairingRecognizerOpe
//
//=============================================================================
// Creation ZUT April 2021
//=============================================================================

#ifndef CATPairingRecognizerOpe_H
#define CATPairingRecognizerOpe_H

// ++++ Includes ++++
#include "CATFacePairingTypeDef.h"
#include "CATDRepOperator.h"
#include "AdvOpeInfra.h"
#include "ListPOfCATFace.h"
#include "CATCGMNewArray.h"

// ++++ Predeclarations ++++
class CATGeoFactory;
class CATSoftwareConfiguration;
class CATBody;
class CATPairingRecognizerImpl;

class ExportedByAdvOpeInfra CATPairingRecognizerOpe : public CATDRepOperator
{
  CATCGMVirtualDeclareClass(CATPairingRecognizerOpe);

public:

  /**
  * Destructor
  */
  virtual ~CATPairingRecognizerOpe();

  /**
  * SetSubsetOfFaces
  */
  void SetSubsetOfFaces( const CATLISTP(CATFace) & iSubsetOfFaces );

  /**
  * @nocgmitf
  * Default : CATFacePairingComputationNormal
  */
  void SetComputationMode( CATFacePairingComputationMode iComputationMode );

  /**
  * @nocgmitf
  * Default : CATFacePairingAllTypes
  */
  void SetEnabledPairingTypes( CATFacePairingTypes iEnabledPairingType );

  /**
  * Default : FALSE
  */
  void SetKeepFacePairingAttributes( CATBoolean iKeepFacePairingAttributes );

  /**
  * @nocgmitf
  * GetAllPairingFaces
  */
  void GetAllPairingFaces( CATFacePairingTypes iPairingTypes, CATLISTP(CATFace) & oListOfPairingFaces );

  /**
  * @nocgmitf
  * Runs <tt>this</tt> operator.
  */
  int RunOperator();

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
  void ReadInput( CATCGMStream  & iStr, int iVersionOfStream );
  /** @nocgmitf for CGMReplay */
  void WriteOutput( CATCGMStream & oStr );
  /** @nocgmitf for CGMReplay */
  CATBoolean ValidateOutput( CATCGMStream & iStr, CATCGMOutput & oStr, int iVersionNumber=1 );
  /** @nocgmitf for CGMReplay */
  void Dump( CATCGMOutput & oStr ) ;
  /** @nocgmitf for CGMReplay */
  void DumpOutput( CATCGMOutput & oStr );
  /** @nocgmitf for CGMReplay */
  void DumpOutput( CATCGMStream & iStr, CATCGMOutput & oStr, int iVersionNumber=1 );
  /** @nocgmitf for CGMReplay */
  void RequireDefinitionOfInputAndOutputObjects();
  /** @nocgmitf for CGMReplay */
  void SetCGMMode( short iCGMMode );

protected:

  CATPairingRecognizerImpl * GetPairingRecognizerImpl() const;

  /**
  * Protected constructor: use the CATCreatePairingRecognizerOpe instead
  */
  CATPairingRecognizerOpe(CATGeoFactory            * iFactory,
                          CATTopData               * iTopData,
                          CATPairingRecognizerImpl * iImpl);

  //------------------------------------------------------------------------------
  // Forbidden (Declared but not Defined) : Copy constructor & assignment operator
  //------------------------------------------------------------------------------
  CATPairingRecognizerOpe (const CATPairingRecognizerOpe &);            // Not Implemented
  CATPairingRecognizerOpe & operator=(const CATPairingRecognizerOpe &); // Not Implemented

  //-----------------
  // FRIEND FUNCTIONS
  //-----------------
  friend ExportedByAdvOpeInfra CATPairingRecognizerOpe * CATCreatePairingRecognizerOpe(CATGeoFactory * iFactory,
                                                                                       CATTopData    * iTopData,
                                                                                       CATBody       * iBody,
                                                                                       double          iMaxThickness);
};

ExportedByAdvOpeInfra CATPairingRecognizerOpe * CATCreatePairingRecognizerOpe(CATGeoFactory * iFactory,
                                                                              CATTopData    * iTopData,
                                                                              CATBody       * iBody,
                                                                              double          iMaxThickness);

#endif /* CATPairingRecognizerOpe */
