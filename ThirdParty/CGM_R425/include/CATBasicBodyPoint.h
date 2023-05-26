/* -*-c++-*- */
#ifndef CATCreatePointBody_H
#define CATCreatePointBody_H

// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
//
// CATCreatePointBody:
// Base class for implementations of the Planar basic CATBody
//
//=============================================================================
// Usage notes:
//
//=============================================================================
// Novembre 98   Creation                                     V St-Amour
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
class CATEdge;

class ExportedByYJ000GSM CATBasicBodyPoint : public CATBasicBodyCGM
{
  public:

  //-------------------------------------------------------------------------
  //- Constructors
  //-------------------------------------------------------------------------
  CATBasicBodyPoint();
  
/*  CATBasicBodyPoint ( const CATGeoFactory                             *Factory,
		      const CATVertex                                 *Origin,
		      const CATEdge                                   *Curve,
		      const CATFace                                   *Support,
		      const CATLength                                 *ParamValue,
		      const CATLength                                 *Start,
		      const CATLength                                 *End,
		      const CATOrientation                             Orientation,
		      const CATIBasicBodyFactory::CATIBasicBodyGeoType GeoType );*/
  
  //-------------------------------------------------------------------------
  /*CATBasicBodyPoint ( const CATGeoFactory                             *Factory,
		      const CATVertex                                 *StartPoint,
		      const CATVertex                                 *EndPoint,
		      const CATFace                                   *Support,
		      const CATLength                                 *ParamValue,
		      const CATLength                                 *Start,
		      const CATLength                                 *End,
		      const CATOrientation                             Orientation,
		      const CATIBasicBodyFactory::CATIBasicBodyGeoType GeoType );*/
  
  //-------------------------------------------------------------------------
  /*CATBasicBodyPoint ( const CATGeoFactory                             *Factory,
		      const CATVertex                                 *FirstPoint,
		      const CATVertex                                 *SecondPoint,
		      const CATVertex                                 *ThirdPoint,
		      const CATFace                                   *Support,
		      const CATLength                                 *ParamValue,
		      const CATLength                                 *Start,
		      const CATLength                                 *End,
		      const CATOrientation                             Orientation,
		      const CATIBasicBodyFactory::CATIBasicBodyGeoType GeoType );*/
  
  //-------------------------------------------------------------------------
  /*CATBasicBodyPoint ( const CATGeoFactory       *Factory,
		      const CATVertex           *Origin,
		      const CATEdge             *FirstCurve,
		      const CATEdge             *SecondCurve,
		      const CATLength           *ParamValue,
		      const CATOrientation       Orientation );*/
  
  //-------------------------------------------------------------------------
  CATBasicBodyPoint ( const CATGeoFactory                              *Factory,
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
  /*CATBasicBodyPoint ( const CATGeoFactory                              *Factory,
		      const CATBody                                    *FirstBody,
		      const CATBody                                    *SecondBondy,
		      const CATBody                                    *ThirdBody,
		      const CATLength                                  *ParamValue,
		      const CATLength                                  *Start,
		      const CATLength                                  *End,
		      const CATOrientation                              Orientation,
		      const CATIBasicBodyFactory::CATIBasicBodyGeoType  GeoType );*/
  
  //-------------------------------------------------------------------------
  /*CATBasicBodyPoint ( const CATGeoFactory                              *Factory,
		      const CATLISTP(CATVertex)                        *Points,
		      const CATMathSetOfVectors                        *Vectors,
		      const CATFace                                    *Support,
		      const CATIBasicBodyFactory::CATIBasicBodyGeoType  GeoType );*/
  
  //-------------------------------------------------------------------------
  /*CATBasicBodyPoint ( const CATGeoFactory                              *Factory,
		      const CATLISTP(CATBody)                          *Points,
		      const CATMathSetOfVectors                        *Vectors,
		      const CATBody                                    *Support,
		      const CATIBasicBodyFactory::CATIBasicBodyGeoType  GeoType );*/
  
  //-------------------------------------------------------------------------
  /*CATBasicBodyPoint ( const CATGeoFactory       *Factory,
		      const CATLength            A,
		      const CATLength            B,
		      const CATLength            C,
		      const CATLength            D,
		      const CATOrientation       Orientation );*/
  
  //-------------------------------------------------------------------------
  //- CreateBasicBody
  //-------------------------------------------------------------------------
  CATBody * CreateBasicBodyPoint (  const CATMathPoint      &iOrigin,
				    const CATMathDirection  &iLineDirection,
				    const CATMathDirection  &iLineDirection2,
				    const CATAngle           iAngle,
				    const CATMathPoint      &AxisOrigin,
				    const CATMathDirection  &AxisDirection,
				    //  const CATMathLine       &Axis,
				    CATCGMJournalList       *oJournal         );
  
};


#endif

