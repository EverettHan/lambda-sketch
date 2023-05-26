/* -*-c++-*- */
#ifndef CATBasicBodyPlanarOffset_H
#define CATBasicBodyPlanarOffset_H

// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
//
// CATBasicBodyPlanarOffset:
// Base class for implementations of the PlanarOffset basic CATBody
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


class ExportedByYJ000GSM CATBasicBodyPlanarOffset : public CATBasicBodyPlanar
{
  public:

  CATBasicBodyPlanarOffset( const CATGeoFactory                             *iFactory,
                            const CATVertex                                 *iOrigin,
                            const CATEdge                                   *iCurve,
                            const CATFace                                   *iSupport,
                            const CATLength                                 *iOffset,
                            const CATLength                                 *iStart,
                            const CATLength                                 *iEnd,
                            const CATOrientation                             iOrientation,
                            const CATIBasicBodyFactory::CATIBasicBodyGeoType iGeoType );

  CATBasicBodyPlanarOffset( const CATGeoFactory                             *iFactory,
                            const CATVertex                                 *iStartPoint,
                            const CATVertex                                 *iEndPoint,
                            const CATFace                                   *iSupport,
                            const CATLength                                 *iOffset,
                            const CATLength                                 *iStart,
                            const CATLength                                 *iEnd,
                            const CATOrientation                             iOrientation,
                            const CATIBasicBodyFactory::CATIBasicBodyGeoType iGeoType );

  /*CATBasicBodyPlanarOffset( const CATGeoFactory                             *iFactory,
                            const CATBody                                   *iOrigin,
                            const CATBody                                   *iCurve,
                            const CATBody                                   *iSupport,
                            const CATLength                                 *iOffset,
                            const CATLength                                 *iStart,
                            const CATLength                                 *iEnd,
                            const CATOrientation                             iOrientation,
                            const CATIBasicBodyFactory::CATIBasicBodyGeoType iGeoType );*/

  CATBasicBodyPlanarOffset( const CATGeoFactory                             *iFactory,
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
  CATBody * CreateBasicBody( CATCGMJournalList *oJournal = NULL,
                             CATIBasicBodyFactory::CATIBasicBodyResultType *oResultType = NULL);
  
  CATBody * CreateBasicBody( CATTopData * iTopData,
                             CATIBasicBodyFactory::CATIBasicBodyResultType *oResultType );
};


#endif

