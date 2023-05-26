/* -*-c++-*- */
#ifndef CATBasicBodyFactory2CGM_H
#define CATBasicBodyFactory2CGM_H

// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
//
// CATBasicBodyFactory2CGM:
// Base class for implementations of the CATBasicBodyFactory basic CATBody
//
//=============================================================================
// Usage notes:
//
// this is an implementation of the CATGeoFactory which uses
// internal container facilities for performances reasons.
//
// Every Object able to create CXR2 geometric objects should inherit from me.
//=============================================================================
// Mar. 98   Creation                                     M. Prince
//=============================================================================

#include "YJ000GSM.h"                  // For Windows
#include "CATMathDef.h"                // CATLength, CATPositiveLength
#include "CATCGMJournalList.h"
#include "CATTopDef.h"
#include "CATIBasicBodyFactory.h"
#include "CATBaseUnknown.h"
#include "ListPOfCATVertex.h"
#include "ListPOfCATEdge.h"
#include "ListPOfCATFace.h"
#include "ListPOfCATBody.h"
#include "CATMathDirection.h"
#include "CATMathPoint.h"


class CATBody;
class CATShell;
class CATWire;
class CATLoop;
class CATVertexInFace;
class CATVertexInVolume;
class CATCGMJournalList;
class CATSoftwareConfiguration;

class CATFace;
class CATEdge;
class CATVertex;

class CATCrvParam;
class CATSurParam;
class CATPoint;
class CATCurve;
class CATSurface;
class CATGeoFactory;
class CATPlane;
class CATBasicBodyCGM;

class CATMathSetOfPoints;

class ExportedByYJ000GSM CATBasicBodyFactory2CGM : public CATIBasicBodyFactory
{
public :
  
  //-------------------------------------------------------------------------
  // Object Modeler declaration
  //-------------------------------------------------------------------------
  CATDeclareClass;
  
  //-------------------------------------------------------------------------
  // Object Management
  //-------------------------------------------------------------------------
  CATBasicBodyFactory2CGM();
  ~CATBasicBodyFactory2CGM();
  
  //-------------------------------------------------------------------------
  CATBody * CreateBasicBody( CATTopData* iTopData,
    const CATIBasicBodyFactory::CATIBasicBodyType     Type,
    const CATIBasicBodyFactory::CATIBasicBodySubType  SubType,
    const CATVertex                                 *Origin,
    const CATEdge                                   *Curve,
    const CATFace                                   *Support,
    const CATLength                                 *ParamValue,
    const CATLength                                 *Start,
    const CATLength                                 *End,
    const CATOrientation                             Orientation,
    const CATIBasicBodyFactory::CATIBasicBodyGeoType  GeoType,
    CATIBasicBodyFactory::CATIBasicBodyResultType    *ResultType );
  
  //-------------------------------------------------------------------------
  CATBody * CreateBasicBody( CATTopData* iTopData,
    const CATIBasicBodyFactory::CATIBasicBodyType     Type,
    const CATIBasicBodyFactory::CATIBasicBodySubType  SubType,
    const CATVertex                                 *StartPoint,
    const CATVertex                                 *EndPoint,
    const CATFace                                   *Support,
    const CATLength                                 *ParamValue,
    const CATLength                                 *Start,
    const CATLength                                 *End,
    const CATOrientation                             Orientation,
    const CATIBasicBodyFactory::CATIBasicBodyGeoType  GeoType,
    CATIBasicBodyFactory::CATIBasicBodyResultType    *ResultType );
  
  //-------------------------------------------------------------------------
  CATBody * CreateBasicBody( CATTopData* iTopData,
    const CATIBasicBodyFactory::CATIBasicBodyType     Type,
    const CATIBasicBodyFactory::CATIBasicBodySubType  SubType,
    const CATVertex           *FirstPoint,
    const CATVertex           *SecondPoint,
    const CATVertex           *ThirdPoint,
    const CATFace             *Support,
    const CATLength           *ParamValue,
    const CATLength           *Start,
    const CATLength           *End,
    const CATOrientation       Orientation,
    const CATIBasicBodyFactory::CATIBasicBodyGeoType  GeoType,
    CATIBasicBodyFactory::CATIBasicBodyResultType    *ResultType );
  
  //-------------------------------------------------------------------------
  CATBody * CreateBasicBody( CATTopData* iTopData,
    const CATIBasicBodyFactory::CATIBasicBodyType     Type,
    const CATIBasicBodyFactory::CATIBasicBodySubType  SubType,
    const CATVertex           *Origin,
    const CATEdge             *FirstCurve,
    const CATEdge             *SecondCurve,
    const CATLength           *ParamValue,
    const CATOrientation       Orientation,
    CATIBasicBodyFactory::CATIBasicBodyResultType    *ResultType );
  
  //-------------------------------------------------------------------------
  CATBody * CreateBasicBody( CATTopData* iTopData,
    const CATIBasicBodyFactory::CATIBasicBodyType     Type,
    const CATIBasicBodyFactory::CATIBasicBodySubType  SubType,
    const CATBody             *FirstBody,
    const CATBody             *SecondBondy,
    const CATBody             *ThirdBody,
    const CATBody             *FourthBody,
    const CATBody             *Support,
    const CATOrientation       FirstOrientation,
    const CATOrientation       SecondOrientation,
    const CATIBasicBodyFactory::CATIBasicBodyGeoType  GeoType,
    CATIBasicBodyFactory::CATIBasicBodyResultType    *ResultType );
  
  //-------------------------------------------------------------------------
  CATBody * CreateBasicBody( CATTopData* iTopData,
    const CATIBasicBodyFactory::CATIBasicBodyType     Type,
    const CATIBasicBodyFactory::CATIBasicBodySubType  SubType,
    const CATBody             *FirstBody,
    const CATBody             *SecondBody,
    const CATBody             *ThirdBody,
    const CATBody             *Support,
    const CATLength           *ParamValue,
    const CATLength           *Start,
    const CATLength           *End,
    const CATOrientation       Orientation,
    const CATIBasicBodyFactory::CATIBasicBodyGeoType  GeoType,
    CATIBasicBodyFactory::CATIBasicBodyResultType    *ResultType );
  
  //-------------------------------------------------------------------------
  CATBody * CreateBasicBody( CATTopData* iTopData,
    const CATIBasicBodyFactory::CATIBasicBodyType     Type,
    const CATIBasicBodyFactory::CATIBasicBodySubType  SubType,
    const CATLISTP(CATVertex) *Points,
    const CATMathSetOfVectors *Vectors,
    const CATFace             *Support,
    const CATIBasicBodyFactory::CATIBasicBodyGeoType  GeoType,
    CATIBasicBodyFactory::CATIBasicBodyResultType    *ResultType );
  
  //-------------------------------------------------------------------------
  CATBody * CreateBasicBody( CATTopData* iTopData,
    const CATIBasicBodyFactory::CATIBasicBodyType     Type,
    const CATIBasicBodyFactory::CATIBasicBodySubType  SubType,
    const CATLISTP(CATBody)   *Points,
    const CATMathSetOfVectors *Vectors,
    const CATBody             *Support,
    const CATIBasicBodyFactory::CATIBasicBodyGeoType  GeoType,
    CATIBasicBodyFactory::CATIBasicBodyResultType    *ResultType );
  
  //-------------------------------------------------------------------------
  CATBody * CreateBasicBody( CATTopData* iTopData,
    const CATIBasicBodyFactory::CATIBasicBodyType     Type,
    const CATIBasicBodyFactory::CATIBasicBodySubType  SubType,
    const CATLength            A,
    const CATLength            B,
    const CATLength            C,
    const CATLength            D,
    const CATOrientation       Orientation,
    CATIBasicBodyFactory::CATIBasicBodyResultType    *ResultType );
  
  ///**
  // * @nodoc
  // * Deprecated
  // */
/*  CATBody * CreateBasicBody( const CATIBasicBodyFactory::CATIBasicBodyType     Type,
    const CATIBasicBodyFactory::CATIBasicBodySubType  SubType,
    const CATVertex                                 *Origin,
    const CATEdge                                   *Curve,
    const CATFace                                   *Support,
    const CATLength                                 *ParamValue,
    const CATLength                                 *Start,
    const CATLength                                 *End,
    const CATOrientation                             Orientation,
    const CATIBasicBodyFactory::CATIBasicBodyGeoType  GeoType,
    CATCGMJournalList                               *Journal,
    CATIBasicBodyFactory::CATIBasicBodyResultType    *ResultType );*/
  
  //-------------------------------------------------------------------------
  /*CATBody * CreateBasicBody( const CATIBasicBodyFactory::CATIBasicBodyType     Type,
    const CATIBasicBodyFactory::CATIBasicBodySubType  SubType,
    const CATVertex                                 *StartPoint,
    const CATVertex                                 *EndPoint,
    const CATFace                                   *Support,
    const CATLength                                 *ParamValue,
    const CATLength                                 *Start,
    const CATLength                                 *End,
    const CATOrientation                             Orientation,
    const CATIBasicBodyFactory::CATIBasicBodyGeoType  GeoType,
    CATCGMJournalList                               *Journal,
    CATIBasicBodyFactory::CATIBasicBodyResultType    *ResultType );*/
  
  //-------------------------------------------------------------------------
  /*CATBody * CreateBasicBody( const CATIBasicBodyFactory::CATIBasicBodyType     Type,
    const CATIBasicBodyFactory::CATIBasicBodySubType  SubType,
    const CATVertex           *FirstPoint,
    const CATVertex           *SecondPoint,
    const CATVertex           *ThirdPoint,
    const CATFace             *Support,
    const CATLength           *ParamValue,
    const CATLength           *Start,
    const CATLength           *End,
    const CATOrientation       Orientation,
    const CATIBasicBodyFactory::CATIBasicBodyGeoType  GeoType,
    CATCGMJournalList         *Journal,
    CATIBasicBodyFactory::CATIBasicBodyResultType    *ResultType );*/
  
  //-------------------------------------------------------------------------
  /*CATBody * CreateBasicBody( const CATIBasicBodyFactory::CATIBasicBodyType     Type,
    const CATIBasicBodyFactory::CATIBasicBodySubType  SubType,
    const CATVertex           *Origin,
    const CATEdge             *FirstCurve,
    const CATEdge             *SecondCurve,
    const CATLength           *ParamValue,
    const CATOrientation       Orientation,
    CATCGMJournalList         *Journal,
    CATIBasicBodyFactory::CATIBasicBodyResultType    *ResultType );*/
  
  //-------------------------------------------------------------------------
  /*CATBody * CreateBasicBody( const CATIBasicBodyFactory::CATIBasicBodyType     Type,
    const CATIBasicBodyFactory::CATIBasicBodySubType  SubType,
    const CATBody             *FirstBody,
    const CATBody             *SecondBondy,
    const CATBody             *ThirdBody,
    const CATBody             *FourthBody,
    const CATBody             *Support,
    const CATOrientation       FirstOrientation,
    const CATOrientation       SecondOrientation,
    const CATIBasicBodyFactory::CATIBasicBodyGeoType  GeoType,
    CATCGMJournalList         *Journal,
    CATIBasicBodyFactory::CATIBasicBodyResultType    *ResultType );*/
  
  //-------------------------------------------------------------------------
  CATBody * CreateBasicBody( const CATIBasicBodyFactory::CATIBasicBodyType     Type,
    const CATIBasicBodyFactory::CATIBasicBodySubType  SubType,
    const CATBody             *FirstBody,
    const CATBody             *SecondBody,
    const CATBody             *ThirdBody,
    const CATBody             *Support,
    const CATLength           *ParamValue,
    const CATLength           *Start,
    const CATLength           *End,
    const CATOrientation       Orientation,
    const CATIBasicBodyFactory::CATIBasicBodyGeoType  GeoType,
    CATCGMJournalList         *Journal,
    CATIBasicBodyFactory::CATIBasicBodyResultType    *ResultType );
  
  //-------------------------------------------------------------------------
  /*CATBody * CreateBasicBody( const CATIBasicBodyFactory::CATIBasicBodyType     Type,
    const CATIBasicBodyFactory::CATIBasicBodySubType  SubType,
    const CATLISTP(CATVertex) *Points,
    const CATMathSetOfVectors *Vectors,
    const CATFace             *Support,
    const CATIBasicBodyFactory::CATIBasicBodyGeoType  GeoType,
    CATCGMJournalList         *Journal,
    CATIBasicBodyFactory::CATIBasicBodyResultType    *ResultType );*/
  
  //-------------------------------------------------------------------------
  /*CATBody * CreateBasicBody( const CATIBasicBodyFactory::CATIBasicBodyType     Type,
    const CATIBasicBodyFactory::CATIBasicBodySubType  SubType,
    const CATLISTP(CATBody)   *Points,
    const CATMathSetOfVectors *Vectors,
    const CATBody             *Support,
    const CATIBasicBodyFactory::CATIBasicBodyGeoType  GeoType,
    CATCGMJournalList         *Journal,
    CATIBasicBodyFactory::CATIBasicBodyResultType    *ResultType );*/
  
  //-------------------------------------------------------------------------
  /*CATBody * CreateBasicBody( const CATIBasicBodyFactory::CATIBasicBodyType     Type,
    const CATIBasicBodyFactory::CATIBasicBodySubType  SubType,
    const CATLength            A,
    const CATLength            B,
    const CATLength            C,
    const CATLength            D,
    const CATOrientation       Orientation,
    CATCGMJournalList         *Journal,
    CATIBasicBodyFactory::CATIBasicBodyResultType    *ResultType );*/
  
  
    /** 
    * @nodoc
    * Defines the Software configuration to be taken 
    * into acccount by <tt>this</tt> operator.
    * @param iConfig
    * The Software configuration.
  */
  virtual void SetSoftwareConfiguration(CATSoftwareConfiguration* iConfig);
  
  /** 
  * @nodoc
  * Returns the Software configuration to be taken 
  * into acccount by <tt>this</tt> operator.
  * @return
  * The Software configuration.
  */
  virtual CATSoftwareConfiguration* GetSoftwareConfiguration() const;
  
  /** 
  * @nodoc
  * Defines the CATMathVector that must be normal 
  * Should be called before CreateBasicBody to be taken into account
  * @param oVector
  * The Software configuration.
  */
  virtual void SetNormalePlane(const CATMathVector & iVector);
  
  /** 
  * @nodoc
  * Returns the normale to the built plane 
  * should be used after CreateBasicBody
  * @return
  * The Vector normal to the plane
  */
  virtual void GetNormalePlane(CATMathVector & oVector) const;

  //-------------------------------------------------------------------------
  CATBoolean GetCircularData( CATMathPoint &oCenter, double &oRadius,
    CATMathDirection &oFirst, CATMathDirection &oSecond,
    double &oStartAngle, double &oEndAngle ) const;
  
  //-------------------------------------------------------------------------
  //- Internal methodes
  //-------------------------------------------------------------------------
  // surcharge de release pour detecter la fin d'utilisation de cette chain-extension
  virtual ULONG           __stdcall Release();  
  
  protected:
    void            CleanInternalData();
    
    CATGeoFactory * GetTheGeoFactory() const;
    void            InitFactory();
    CATGeoFactory*  _Factory;
    
    void InitCircularData( CATBasicBodyCGM *BasicBody );
    

    CATLONG32 _IsNormaleComputed;
    CATMathVector _NormalePlane;
    //- Donnee du cercle associe
    CATBoolean       _IsDataCreated;
    CATMathPoint     _DataCenter;
    double           _DataRadius;
    CATMathDirection _DataFirstDir;
    CATMathDirection _DataSecondDir;
    double           _StartAngle;
    double           _EndAngle;
    CATSoftwareConfiguration * _CodeVersion;
    /** @nodoc */
    CATLONG32 _ImposedVersion;
    /** @nodoc */
    virtual CATSoftwareConfiguration* GetConfig();
    
};


#endif

