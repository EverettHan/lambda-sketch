// COPYRIGHT DASSAULT SYSTEMES 2019, ALL RIGHTS RESERVED.
//=============================================================================
//
// RESPONSIBLE  : ZUT
//
// DESCRIPTION  : FacePairingAnalyzer operator
//
//=============================================================================
// Creation ZUT September 2019
//=============================================================================

#ifndef CATFacePairingAnalyzerOpe_H
#define CATFacePairingAnalyzerOpe_H

#include "CATFacePairingTypeDef.h"
#include "CATDRepOperator.h"
#include "AdvOpeInfra.h"

class CATTopData;
class CATBody;
class CATFace;
class CATMathPlane;
class CATCGMStream;
class CATCGMOutput;
class CATFacePairingAnalyzerImpl;
class CATSoftwareConfiguration;

class ExportedByAdvOpeInfra CATFacePairingAnalyzerOpe : public CATDRepOperator
{
  CATCGMVirtualDeclareClass(CATFacePairingAnalyzerOpe);

public:

  /**
  * Destructor
  */
  virtual ~CATFacePairingAnalyzerOpe();

  /**
  * @nodoc
  * Default : CATFacePairingComputationNormal
  */
  void SetComputationMode( CATFacePairingComputationMode iComputationMode );

  /**
  * @nodoc
  * Default : CATFacePairingAllTypes
  */
  void SetEnabledPairingTypes( CATFacePairingTypes iEnabledPairingType );

  /**
  * @ nodoc
  * Set the mininimum ratio iMinFacingRatio wanted to accept a pairing of type iType.
  * if iType == CATFacePairingUnknown : Applies minimum ratio on all pairing types on which the option is available
  * Currently only available for exact pairings
  */
  void SetInputMinFacingRatio(double iMinFacingRatio, CATFacePairingType iType = CATFacePairingUnknown);

  /**
  * Returns the recognized pairing type between the two faces
  */
  HRESULT GetRecognizedPairingType( CATFacePairingType & oPairingType, CATFacePairingMode & oPairingMode ) const;

  /**
  * Returns the offset distance between the pairing faces in case of an exact offset
  */
  HRESULT GetOffsetValue( double & oOffsetValue ) const;

  /**
  * Returns the computed distance between the pairing faces
  */
  HRESULT GetMinMaxDistance( double & oMinDistance, double & oMaxDistance ) const;

  /**
  * Returns the computed distance between the pairing faces
  */
  HRESULT GetAverageDistance( double & oAverageDistance ) const;
  
  /**
  * Returns the side preference for a futur offset on one of the faces analyzed
  */
  HRESULT GetOffsetReference( short & oOffsetReference ) const;

  /**
  * Returns the ratio of the faces that overlaps.
  */
  HRESULT GetMaxFacingRatio(double & oMaxFacingRatio) const;

  /**
  * GetSideFacingRatios
  * Returns each side proportion of the face facing the other one
  * oSideRatio1 : part of the first face that is facing the second
  * oSideRatio2 : part of the second face that is facing the first
  */
  HRESULT GetSideFacingRatios(double & oFacingRatioSide1, double & oFacingRatioSide2) const;

  /**
  * @nodoc
  * NOT IMPLEMENTED
  */
  HRESULT GetMirrorPlane( CATMathPlane & oMirrorPlane ) const;

  /** @nocgmitf DO NOT USE */
  void SetUseLegacyWFA( unsigned short iUseWFA );

  void SetForceComputeBothSides(short iForceComputeBothSides);

  //------------------
  // STATIC METHODS
  //------------------

  /** @nocgmitf */
  static HRESULT IsExactOffset( CATGeoFactory * iFactory, CATTopData * iTopData, CATBody * iBody, CATFace * iFaces[2], double iMaxThickness,  double & oOffsetValue, CATFacePairingMode & oPairingMode );

  /** @nocgmitf */
  static HRESULT IsMirror( CATGeoFactory * iFactory, CATTopData * iTopData, CATBody * iBody, CATFace * iFaces[2], double iMaxThickness,  CATMathPlane & oMirrorPlane );

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

  CATFacePairingAnalyzerImpl * GetFacePairingAnalyzerImpl() const;

  /**
  * Protected constructor: use the CATCreateFacePairingAnalyzerOpe instead
  */
  CATFacePairingAnalyzerOpe( CATGeoFactory              * iFactory,
                             CATTopData                 * iTopData,
                             CATFacePairingAnalyzerImpl * iImpl );

  void SetInputFaces( CATFace * iFaces[2] );
  void AddFacePairingType( CATFacePairingType iFacePairingType );

  //------------------------------------------------------------------------------
  // Forbidden (Declared but not Defined) : Copy constructor & assignment operator
  //------------------------------------------------------------------------------
  CATFacePairingAnalyzerOpe ( const CATFacePairingAnalyzerOpe & );            // Not Implemented
  CATFacePairingAnalyzerOpe & operator=( const CATFacePairingAnalyzerOpe & ); // Not Implemented

  //-----------------
  // FRIEND FUNCTIONS
  //-----------------
  friend ExportedByAdvOpeInfra CATFacePairingAnalyzerOpe * CATCreateFacePairingAnalyzerOpe( CATGeoFactory       * iFactory,
                                                                                            CATTopData          * iTopData,
                                                                                            CATBody             * iBody,
                                                                                            CATFace             * iFaces[2],
                                                                                            double                iMaxThickness );
};

// ---------------------
// CATCreateFacePairingAnalyzerOpe
// ---------------------
ExportedByAdvOpeInfra CATFacePairingAnalyzerOpe * CATCreateFacePairingAnalyzerOpe( CATGeoFactory       * iFactory,
                                                                                   CATTopData          * iTopData,
                                                                                   CATBody             * iBody,
                                                                                   CATFace             * iFaces[2],
                                                                                   double                iMaxThickness );



#endif /* CATFacePairingAnalyzerOpe_H */
