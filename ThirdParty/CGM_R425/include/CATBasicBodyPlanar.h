/* -*-c++-*- */
#ifndef CATCreatePlanarBody_H
#define CATCreatePlanarBody_H

// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
//
// CATCreatePlanarBody:
// Base class for implementations of the Planar basic CATBody
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
#include "CATMathVector.h"

#include "ListPOfCATVertex.h"
#include "ListPOfCATEdge.h"
#include "ListPOfCATFace.h"
#include "ListPOfCATBody.h"

class CATGeoFactory;
class CATMathPoint;
class CATMathDirection;
class CATCGMJournalList;
class CATMathPlane;
class CATEdge;

class ExportedByYJ000GSM CATBasicBodyPlanar : public CATBasicBodyCGM
{
  public:

  //-------------------------------------------------------------------------
  //- Constructors
  //-------------------------------------------------------------------------
  CATBasicBodyPlanar();

  CATBasicBodyPlanar ( const CATGeoFactory                             *Factory,
                       const CATVertex                                 *Origin,
                       const CATEdge                                   *Curve,
                       const CATFace                                   *Support,
                       const CATLength                                 *ParamValue,
                       const CATLength                                 *Start,
                       const CATLength                                 *End,
                       const CATOrientation                             Orientation,
                       const CATIBasicBodyFactory::CATIBasicBodyGeoType GeoType );

  //-------------------------------------------------------------------------
  CATBasicBodyPlanar ( const CATGeoFactory                             *Factory,
                       const CATVertex                                 *StartPoint,
                       const CATVertex                                 *EndPoint,
                       const CATFace                                   *Support,
                       const CATLength                                 *ParamValue,
                       const CATLength                                 *Start,
                       const CATLength                                 *End,
                       const CATOrientation                             Orientation,
                       const CATIBasicBodyFactory::CATIBasicBodyGeoType GeoType );

  //-------------------------------------------------------------------------
  CATBasicBodyPlanar ( const CATGeoFactory                             *Factory,
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
  CATBasicBodyPlanar ( const CATGeoFactory       *Factory,
                       const CATVertex           *Origin,
                       const CATEdge             *FirstCurve,
                       const CATEdge             *SecondCurve,
                       const CATLength           *ParamValue,
                       const CATOrientation       Orientation );

  //-------------------------------------------------------------------------
  CATBasicBodyPlanar ( const CATGeoFactory                              *Factory,
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
  /*CATBasicBodyPlanar ( const CATGeoFactory                              *Factory,
                       const CATBody                                    *FirstBody,
                       const CATBody                                    *SecondBondy,
                       const CATBody                                    *ThirdBody,
                       const CATLength                                  *ParamValue,
                       const CATLength                                  *Start,
                       const CATLength                                  *End,
                       const CATOrientation                              Orientation,
                       const CATIBasicBodyFactory::CATIBasicBodyGeoType  GeoType );*/

  //-------------------------------------------------------------------------
  CATBasicBodyPlanar ( const CATGeoFactory                              *Factory,
                       const CATLISTP(CATVertex)                        *Points,
                       const CATMathSetOfVectors                        *Vectors,
                       const CATFace                                    *Support,
                       const CATIBasicBodyFactory::CATIBasicBodyGeoType  GeoType );

  //-------------------------------------------------------------------------
  CATBasicBodyPlanar ( const CATGeoFactory                              *Factory,
                       const CATLISTP(CATBody)                          *Points,
                       const CATMathSetOfVectors                        *Vectors,
                       const CATBody                                    *Support,
                       const CATIBasicBodyFactory::CATIBasicBodyGeoType  GeoType );

  //-------------------------------------------------------------------------
  CATBasicBodyPlanar ( const CATGeoFactory       *Factory,
                       const CATLength            A,
                       const CATLength            B,
                       const CATLength            C,
                       const CATLength            D,
                       const CATOrientation       Orientation );

  //-------------------------------------------------------------------------
  //- CreateBasicBody
  //-------------------------------------------------------------------------

  CATBoolean GetOrientedDirection ( CATTopData * iData, const CATEdge *iEdge, const CATSide iEdgeSide,
                                    CATMathDirection &oLineDirection );

  void SetNormale(const CATMathVector & NormalePlane);
  void GetNormale(CATMathVector & NormalePlane);
  protected : 
    CATBody * ComputePlane(CATTopData * iData, CATMathPlane & RefPlane);
    CATBody * ComputePlane(CATCGMJournalList * iJourn, CATMathPlane & RefPlane);
      
  private :
    CATLONG32 _IsNormaleComputed;
    CATMathVector _NormalePlane;
};


#endif

