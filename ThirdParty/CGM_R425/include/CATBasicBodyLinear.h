/* -*-c++-*- */
#ifndef CATCreateLinearBody_H
#define CATCreateLinearBody_H

// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
//
// CATCreateLinearBody:
// Base class for implementations of the Linear basic CATBody
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
class CATSurParam;
class CATMathDirection2D;
class CATFace;
class CATCGMJournalList;
//class CATOrientation;

class ExportedByYJ000GSM CATBasicBodyLinear : public CATBasicBodyCGM
{
  public:
  virtual ~CATBasicBodyLinear();
  //-------------------------------------------------------------------------
  //- Constructors
  //-------------------------------------------------------------------------
  CATBasicBodyLinear ();

  CATBasicBodyLinear ( const CATGeoFactory                             *Factory,
                       const CATVertex                                 *Origin,
                       const CATEdge                                   *Curve,
                       const CATFace                                   *Support,
                       const CATLength                                 *ParamValue,
                       const CATLength                                 *Start,
                       const CATLength                                 *End,
                       const CATOrientation                             Orientation,
                       const CATIBasicBodyFactory::CATIBasicBodyGeoType GeoType );

  //-------------------------------------------------------------------------
  CATBasicBodyLinear ( const CATGeoFactory                             *Factory,
                       const CATVertex                                 *StartPoint,
                       const CATVertex                                 *EndPoint,
                       const CATFace                                   *Support,
                       const CATLength                                 *ParamValue,
                       const CATLength                                 *Start,
                       const CATLength                                 *End,
                       const CATOrientation                             Orientation,
                       const CATIBasicBodyFactory::CATIBasicBodyGeoType GeoType );

  //-------------------------------------------------------------------------
  CATBasicBodyLinear ( const CATGeoFactory                             *Factory,
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
  CATBasicBodyLinear ( const CATGeoFactory       *Factory,
                       const CATVertex           *Origin,
                       const CATEdge             *FirstCurve,
                       const CATEdge             *SecondCurve,
                       const CATLength           *ParamValue,
                       const CATOrientation       Orientation );

  //-------------------------------------------------------------------------
  CATBasicBodyLinear ( const CATGeoFactory                              *Factory,
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
  /*CATBasicBodyLinear ( const CATGeoFactory                              *Factory,
                       const CATBody                                    *FirstBody,
                       const CATBody                                    *SecondBondy,
                       const CATBody                                    *ThirdBody,
                       const CATLength                                  *ParamValue,
                       const CATLength                                  *Start,
                       const CATLength                                  *End,
                       const CATOrientation                              Orientation,
                       const CATIBasicBodyFactory::CATIBasicBodyGeoType  GeoType );
*/
  //-------------------------------------------------------------------------
  CATBasicBodyLinear ( const CATGeoFactory                              *Factory,
                       const CATLISTP(CATVertex)                        *Points,
                       const CATMathSetOfVectors                        *Vectors,
                       const CATFace                                    *Support,
                       const CATIBasicBodyFactory::CATIBasicBodyGeoType  GeoType );

  //-------------------------------------------------------------------------
  CATBasicBodyLinear ( const CATGeoFactory                              *Factory,
                       const CATLISTP(CATBody)                          *Points,
                       const CATMathSetOfVectors                        *Vectors,
                       const CATBody                                    *Support,
                       const CATIBasicBodyFactory::CATIBasicBodyGeoType  GeoType );

  //-------------------------------------------------------------------------
  //- CreateBasicBody
  //-------------------------------------------------------------------------
  CATBody * CreateBasicBodyLinear(const CATMathPoint     &iOrigin,
                                  const CATMathDirection &iLineDirection,
                                  const double           &iStart,
                                  const double           &iEnd,
                                  const CATMathDirection *iTransfoDirection,
                                  CATTopData* iTopData);

  CATBody * CreateBasicBodyLinearOnSupport ( const CATSurParam        &iOrigin,
                                             const CATMathDirection2D &iLineDirection,
                                             const CATFace            *iFaceOn,
                                             const double             &iStart,
                                             const double             &iEnd,
                                             CATTopData* iTopData);

  CATBody * CreateBasicBodyLinearGeodesic ( const CATMathPoint       &iOrigin,
                                            const CATSurParam        &iOriginParam,
                                            const CATMathDirection   &iLineDirection,
                                            const CATFace            *iFaceOn,
                                            const double             &iStart,
                                            const double             &iEnd,
                                            CATTopData* iTopData);


  CATBody * CreateBasicBodyLinear(const CATMathPoint     &iOrigin,
                                  const CATMathDirection &iLineDirection,
                                  const double           &iStart,
                                  const double           &iEnd,
                                  const CATMathDirection *iTransfoDirection,
                                  CATCGMJournalList      *oJournal );

  CATBody * CreateBasicBodyLinearOnSupport ( const CATSurParam        &iOrigin,
                                             const CATMathDirection2D &iLineDirection,
                                             const CATFace            *iFaceOn,
                                             const double             &iStart,
                                             const double             &iEnd,
                                             CATCGMJournalList        *oJournal );

  CATBody * CreateBasicBodyLinearGeodesic ( const CATMathPoint       &iOrigin,
                                            const CATSurParam        &iOriginParam,
                                            const CATMathDirection   &iLineDirection,
                                            const CATFace            *iFaceOn,
                                            const double             &iStart,
                                            const double             &iEnd,
                                            CATCGMJournalList        *oJournal );


};


#endif

