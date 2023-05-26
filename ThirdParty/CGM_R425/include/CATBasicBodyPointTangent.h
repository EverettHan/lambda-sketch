/* -*-c++-*- */
#ifndef CATBasicBodyPointTangent_H
#define CATBasicBodyPointTangent_H

// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
//
// CATBasicBodyPointTangent:
// Base class for implementations of the PointTangent basic CATBody
//
//=============================================================================
// Usage notes:
//
//=============================================================================
// Novembre 98   Creation                                     V St-Amour
//=============================================================================
#include "YJ000GSM.h"                  // For Windows
#include "CATBasicBodyCGM.h"
#include "CATBasicBodyPoint.h"
#include "CATIBasicBodyFactory.h"
#include "CATTopDef.h"
#include "CATBaseUnknown.h"

#include "ListPOfCATVertex.h"
#include "ListPOfCATEdge.h"
#include "ListPOfCATFace.h"
#include "ListPOfCATBody.h"
#include "CATListOfCATCartesianPoints.h"
#include "CATCartesianPoint.h"
#include "CATMathDirection.h"

class CATBody;
class CATShell;
class CATWire;
class CATLoop;
class CATVertexInFace;
class CATVertexInVolume;
class CATCGMJournalList;

class CATFace;
class CATEdge;
class CATVertex;

class CATGeoFactory;
//- class CATPoint;

class CATCurve;
class CATSurface;
class CATPlane;

class CATError;

class CATCGMJournalList;
class CATTopData;

typedef struct NP NearPoint;


class ExportedByYJ000GSM CATBasicBodyPointTangent : public CATBasicBodyPoint
{
  public:

/*  CATBasicBodyPointTangent( const CATGeoFactory                             *iFactory,
                            const CATVertex                                 *iOrigin,
                            const CATEdge                                   *iCurve,
                            const CATFace                                   *iSupport,
                            const CATLength                                 *iParamValue,
                            const CATLength                                 *iStart,
                            const CATLength                                 *iEnd,
                            const CATOrientation                             iOrientation,
                            const CATIBasicBodyFactory::CATIBasicBodyGeoType iGeoType );*/

  //-------------------------------------------------------------------------
  /*CATBasicBodyPointTangent ( const CATGeoFactory       *Factory,
			     const CATVertex           *Origin,
			     const CATEdge             *FirstCurve,
			     const CATEdge             *SecondCurve,
			     const CATLength           *ParamValue,
			     const CATOrientation       Orientation );*/
  
  /*CATBasicBodyPointTangent( const CATGeoFactory                             *iFactory,
                            const CATBody                                   *iOrigin,
                            const CATBody                                   *iCurve,
                            const CATBody                                   *iSupport,
                            const CATLength                                 *iParamValue,
                            const CATLength                                 *iStart,
                            const CATLength                                 *iEnd,
                            const CATOrientation                             iOrientation,
                            const CATIBasicBodyFactory::CATIBasicBodyGeoType iGeoType );*/

  CATBasicBodyPointTangent( const CATGeoFactory                             *iFactory,
                            const CATBody                                   *iFirstPoint,
                            const CATBody                                   *iSecondPoint,
                            const CATBody                                   *iThirdPoint,
                            const CATBody                                   *iSupport,
                            const CATLength                                 *iOffset,
                            const CATLength                                 *iStart,
                            const CATLength                                 *iEnd,
                            const CATOrientation                             iOrientation,
                            const CATIBasicBodyFactory::CATIBasicBodyGeoType iGeoType );

  //-------------------------------------------------------------------------
  /*CATBody * CreateBasicBody( CATCGMJournalList *oJournal = NULL,
                             CATIBasicBodyFactory::CATIBasicBodyResultType *oResultType = NULL);*/

  CATBody * CreateBasicBody( CATTopData * iTopData,
                             CATIBasicBodyFactory::CATIBasicBodyResultType *oResultType );

  private :

   //- methode interne pour decomposer le probleme.
  void ComputeTangentData(CATTopData * iData);
  /*void CreateBodyFromPoints( CATBody *&oBody , CATCGMJournalList* Journal);*/
  void CreateBodyFromPoints( CATBody *&oBody , CATTopData* iTopData);
  void ComputePointsOnOneWire( int         iIndex, CATTopData* iTopData );
  void SameVertex(NearPoint *first, NearPoint *second);
  
  //- data.
  CATMathDirection               _Tangent;
  CATLISTP( CATCartesianPoint )  _ListOfPoints;
  CATLISTP( CATEdge )            _ListOfEdgesForReport;
  CATError **                    _ListOfError;

};


#endif

