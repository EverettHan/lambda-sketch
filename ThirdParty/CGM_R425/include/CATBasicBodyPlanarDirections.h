/* -*-c++-*- */
#ifndef CATBasicBodyPlanarDirections_H
#define CATBasicBodyPlanarDirections_H

// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
//
// CATBasicBodyPlanarDirections:
// Base class for implementations of the PlanarDirections basic CATBody
//
//=============================================================================
// Usage notes:
//
//=============================================================================
// June 98   Creation                                     M. Prince
//=============================================================================
#include "YJ000GSM.h"                  // For Windows
#include "CATBasicBodyCGM.h"
#include "CATBasicBodyPlanar.h"
#include "CATIBasicBodyFactory.h"
#include "CATTopDef.h"

#include "ListPOfCATVertex.h"
#include "ListPOfCATEdge.h"
#include "ListPOfCATFace.h"
#include "ListPOfCATBody.h"

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
class CATPoint;
class CATCurve;
class CATSurface;
class CATPlane;

class CATCGMJournalList;


class ExportedByYJ000GSM CATBasicBodyPlanarDirections : public CATBasicBodyPlanar
{
  public:

  CATBasicBodyPlanarDirections( const CATGeoFactory                             *iFactory,
                            const CATVertex                                 *iOrigin,
                            const CATEdge                                   *iFirstCurve,
                            const CATEdge                                   *iSecondCurve,
                            const CATLength                                 *iParamValue,
                            const CATOrientation                             iOrientation );

  /*CATBasicBodyPlanarDirections( const CATGeoFactory                         *iFactory,
                            const CATBody                                   *iOrigin,
                            const CATBody                                   *iCurve,
                            const CATBody                                   *iSupport,
                            const CATLength                                 *iParamValue,
                            const CATLength                                 *iStart,
                            const CATLength                                 *iEnd,
                            const CATOrientation                             iOrientation,
                            const CATIBasicBodyFactory::CATIBasicBodyGeoType iGeoType );
*/
  CATBasicBodyPlanarDirections( const CATGeoFactory                         *iFactory,
                            const CATBody                                   *iOrigin,
                            const CATBody                                   *iFirstCurve,
                            const CATBody                                   *iSeconCurve,
                            const CATBody                                   *iSupport,
                            const CATLength                                 *iParamValue,
                            const CATLength                                 *iStart,
                            const CATLength                                 *iEnd,
                            const CATOrientation                             iOrientation,
                            const CATIBasicBodyFactory::CATIBasicBodyGeoType iGeoType );

  //-------------------------------------------------------------------------
  /*CATBody * CreateBasicBody( CATCGMJournalList *oJournal = NULL,
                             CATIBasicBodyFactory::CATIBasicBodyResultType *oResultType = NULL);*/
  
  CATBody * CreateBasicBody( CATTopData * iTopData,
                             CATIBasicBodyFactory::CATIBasicBodyResultType *oResultType );

  private:

  void ExtractNearestPointFromOrigin ( CATTopData   * iTopData ,
                                       CATEdge      * iEdge    ,
                                       CATMathPoint & oOrigin  );

};


#endif

