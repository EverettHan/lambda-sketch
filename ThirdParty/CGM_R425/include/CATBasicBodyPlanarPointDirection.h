/* -*-c++-*- */
#ifndef CATBasicBodyPlanarPointDirection_H
#define CATBasicBodyPlanarPointDirection_H

// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
//
// CATBasicBodyPlanarPointDirection:
// Base class for implementations of the PlanarPointDirection basic CATBody
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
//class CATLength;
//class CATAngle;
//class CATOrientation
class CATSurface;
class CATPlane;

class CATCGMJournalList;


class ExportedByYJ000GSM CATBasicBodyPlanarPointDirection : public CATBasicBodyPlanar
{
  public:

  CATBasicBodyPlanarPointDirection( const CATGeoFactory                     *iFactory,
                            const CATVertex                                 *iOrigin,
                            const CATEdge                                   *iCurve,
                            const CATFace                                   *iSupport,
                            const CATLength                                 *iParamValue,
                            const CATLength                                 *iStart,
                            const CATLength                                 *iEnd,
                            const CATOrientation                             iOrientation,
                            const CATIBasicBodyFactory::CATIBasicBodyGeoType iGeoType );

  CATBasicBodyPlanarPointDirection( const CATGeoFactory                     *iFactory,
                            const CATVertex                                 *iStartPoint,
                            const CATVertex                                 *iEndPoint,
                            const CATFace                                   *iSupport,
                            const CATLength                                 *iParamValue,
                            const CATLength                                 *iStart,
                            const CATLength                                 *iEnd,
                            const CATOrientation                             iOrientation,
                            const CATIBasicBodyFactory::CATIBasicBodyGeoType iGeoType );

/*  CATBasicBodyPlanarPointDirection( const CATGeoFactory                     *iFactory,
                            const CATBody                                   *iOrigin,
                            const CATBody                                   *iCurve,
                            const CATBody                                   *iSupport,
                            const CATLength                                 *iParamValue,
                            const CATLength                                 *iStart,
                            const CATLength                                 *iEnd,
                            const CATOrientation                             iOrientation,
                            const CATIBasicBodyFactory::CATIBasicBodyGeoType iGeoType );*/

  CATBasicBodyPlanarPointDirection( const CATGeoFactory                     *iFactory,
                            const CATBody                                   *iFirstBody,
                            const CATBody                                   *iSecondBody,
                            const CATBody                                   *iThirdBody,
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
};


#endif

