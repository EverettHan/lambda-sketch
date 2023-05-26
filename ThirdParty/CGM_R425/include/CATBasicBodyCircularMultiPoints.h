/* -*-c++-*- */
#ifndef CATBasicBodyCircularMultiPoints_H
#define CATBasicBodyCircularMultiPoints_H

// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
//
// CATBasicBodyCircularMultiPoints:
// Base class for implementations of the CircularMultiPoints basic CATBody
//
//=============================================================================
// Usage notes:
//
//=============================================================================
// June 98   Creation                                     M. Prince
//=============================================================================
#include "YJ000GSM.h"                  // For Windows
#include "CATBasicBodyCGM.h"
#include "CATBasicBodyCircular.h"
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


class ExportedByYJ000GSM CATBasicBodyCircularMultiPoints : public CATBasicBodyCircular
{
  public:


  CATBasicBodyCircularMultiPoints( const CATGeoFactory                             *iFactory,
                            const CATVertex                                 *iPoint1,
                            const CATVertex                                 *iPoint2,
                            const CATVertex                                 *iPoint3,
                            const CATFace                                   *iSupport,
                            const CATLength                                 *iRadius,
                            const CATLength                                 *iStartAngle,
                            const CATLength                                 *iEndAngle,
                            const CATOrientation                             iOrientation,
                            const CATIBasicBodyFactory::CATIBasicBodyGeoType iGeoType );

  /*CATBasicBodyCircularMultiPoints( const CATGeoFactory                             *iFactory,
                            const CATBody                                   *iCenter,
                            const CATBody                                   *iAxis,
                            const CATBody                                   *iSupport,
                            const CATLength                                 *iRadius,
                            const CATLength                                 *iStartAngle,
                            const CATLength                                 *iEndAngle,
                            const CATOrientation                             iOrientation,
                            const CATIBasicBodyFactory::CATIBasicBodyGeoType iGeoType );*/

  CATBasicBodyCircularMultiPoints( const CATGeoFactory                             *iFactory,
                            const CATBody                                   *iPoint1,
                            const CATBody                                   *iPoint2,
                            const CATBody                                   *iPoint3,
                            const CATBody                                   *iSupport,
                            const CATLength                                 *iRadius,
                            const CATLength                                 *iStartAngle,
                            const CATLength                                 *iEndAngle,
                            const CATOrientation                             iOrientation,
                            const CATIBasicBodyFactory::CATIBasicBodyGeoType iGeoType );

  //-------------------------------------------------------------------------
  /*CATBody * CreateBasicBody( CATCGMJournalList *oJournal = NULL,
                             CATIBasicBodyFactory::CATIBasicBodyResultType *oResultType = NULL);*/
  
  CATBody * CreateBasicBody( CATTopData * iTopData,
                             CATIBasicBodyFactory::CATIBasicBodyResultType *oResultType );
};


#endif

