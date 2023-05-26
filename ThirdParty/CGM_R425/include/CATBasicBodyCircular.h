/* -*-c++-*- */
#ifndef CATBasicBodyCircular_H
#define CATBasicBodyCircular_H

// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
//
// CATBasicBodyCircular:
// Base class for implementations of the Circular basic CATBody
//
//=============================================================================
// Usage notes:
//
//=============================================================================
// June 98   Creation                                     M. Prince
//=============================================================================

#include "YJ000GSM.h"                  // For Windows
#include "CATBasicBodyCGM.h"
#include "CATIBasicBodyFactory.h"
#include "CATTopDef.h"

#include "ListPOfCATVertex.h"
#include "ListPOfCATEdge.h"
#include "ListPOfCATFace.h"
#include "ListPOfCATBody.h"

class CATGeoFactory;
class CATMathPoint;
class CATMathDirection;
class CATCGMJournalList;
class CATTopData;
class CATPCircle;

class ExportedByYJ000GSM CATBasicBodyCircular : public CATBasicBodyCGM
{
  public:

  enum CircularType { Complete,
                      Direct,
                      Complementary };

  CATBasicBodyCircular ();

  //-------------------------------------------------------------------------
  CATBasicBodyCircular ( const CATGeoFactory                             *Factory,
                    const CATVertex                                 *Origin,
                    const CATEdge                                   *Curve,
                    const CATFace                                   *Support,
                    const CATLength                                 *ParamValue,
                    const CATLength                                 *Start,
                    const CATLength                                 *End,
                    const CATOrientation                             Orientation,
                    const CATIBasicBodyFactory::CATIBasicBodyGeoType GeoType );

  //-------------------------------------------------------------------------
  CATBasicBodyCircular ( const CATGeoFactory                             *Factory,
                    const CATVertex                                 *StartPoint,
                    const CATVertex                                 *EndPoint,
                    const CATFace                                   *Support,
                    const CATLength                                 *ParamValue,
                    const CATLength                                 *Start,
                    const CATLength                                 *End,
                    const CATOrientation                             Orientation,
                    const CATIBasicBodyFactory::CATIBasicBodyGeoType GeoType );

  //-------------------------------------------------------------------------
  CATBasicBodyCircular ( const CATGeoFactory                             *Factory,
                    const CATVertex                                 *FirstPoint,
                    const CATVertex                                 *SecondPoint,
                    const CATVertex                                 *ThirdPoint,
                    const CATFace                                   *Support,
                    const CATLength                                 *ParamValue,
                    const CATLength                                 *Start,
                    const CATLength                                 *End,
                    const CATOrientation                             Orientation,
                    const CATIBasicBodyFactory::CATIBasicBodyGeoType GeoType );

  //-------------------------------------------------------------------------
  CATBasicBodyCircular ( const CATGeoFactory       *Factory,
                    const CATVertex           *Origin,
                    const CATEdge             *FirstCurve,
                    const CATEdge             *SecondCurve,
                    const CATLength           *ParamValue,
                    const CATOrientation       Orientation );

  //-------------------------------------------------------------------------
  CATBasicBodyCircular ( const CATGeoFactory                              *Factory,
                    const CATBody                                    *FirstBody,
                    const CATBody                                    *SecondBondy,
                    const CATBody                                    *ThirdBody,
                    const CATBody                                    *Support,
                    const CATLength                                  *ParamValue,
                    const CATLength                                  *Start,
                    const CATLength                                  *End,
                    const CATOrientation                              Orientation,
                    const CATIBasicBodyFactory::CATIBasicBodyGeoType  GeoType );

  //-------------------------------------------------------------------------
  CATBasicBodyCircular ( const CATGeoFactory                              *Factory,
                    const CATBody                                    *FirstBody,
                    const CATBody                                    *SecondBondy,
                    const CATBody                                    *ThirdBody,
                    const CATLength                                  *ParamValue,
                    const CATLength                                  *Start,
                    const CATLength                                  *End,
                    const CATOrientation                              Orientation,
                    const CATIBasicBodyFactory::CATIBasicBodyGeoType  GeoType );

  //-------------------------------------------------------------------------
  void SetLimitationType( CircularType Type );


  CATBoolean GetCircularData( CATMathPoint &oCenter,
                              double &oRadius,
                              CATMathDirection &oFirst,
                              CATMathDirection &oSecond,
                              double &oStartMinAngle,
                              double &oEndMinAngle,
                              double *oStartMaxAngle = NULL,
                              double *oEndMaxAngle   = NULL ) const;

  protected:

  //-------------------------------------------------------------------------
 /* CATBody * CreateBasicBodyCircular (  const CATMathPoint      &iOrigin,
                                       const CATMathDirection  *iLineDirection1,
                                       const CATMathDirection  *iLineDirection2,
                                       const CATLength         &iRadius,
                                       const CATLength         *Start,
                                       const CATLength         *End,
                                       CATTopData* iTopData);*/


  //-------------------------------------------------------------------------
  /*CATBody * CreateBasicBodyCircular (  CATTopData* iTopData,
                                       CATIBasicBodyFactory::CATIBasicBodyResultType *oResultType );*/

  /** 
  * @nodoc
  * Deprecated
  */
  /*CATBody * CreateBasicBodyCircular (  const CATMathPoint      &iOrigin,
                                       const CATMathDirection  *iLineDirection1,
                                       const CATMathDirection  *iLineDirection2,
                                       const CATLength         &iRadius,
                                       const CATLength         *Start,
                                       const CATLength         *End,
                                       CATCGMJournalList       *oJournal         );
*/

  /** 
  * @nodoc
  * Deprecated
  */
/*  CATBody * CreateBasicBodyCircular (  CATCGMJournalList       *oJournal,
                                       CATIBasicBodyFactory::CATIBasicBodyResultType *oResultType );*/


  //-------------------------------------------------------------------------
  //   int CheckParametres();

  //-------------------------------------------------------------------------
  void SetLimits( CATPCircle *PCircle, CATMathPoint *StartPoint=NULL,
                  CATMathPoint *EndPoint=NULL , CATTopData * iTopData=NULL);

  //- Donnee contenant le type de limitation Direct, Complementary ou Complete.
  CircularType _LimitationType;

  //- Donnee du cercle associe
  CATBoolean       _IsDataCreated;
  CATMathPoint     _DataCenter;
  double           _DataRadius;
  CATMathDirection _DataFirstDir;
  CATMathDirection _DataSecondDir;
  double           _StartMinAngle;
  double           _EndMinAngle;
  double           _StartMaxAngle;
  double           _EndMaxAngle;
};


#endif

