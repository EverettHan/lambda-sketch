/* -*-c++-*- */
#ifndef CATBasicBodyLinearPointDirection_H
#define CATBasicBodyLinearPointDirection_H

// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
//
// CATBasicBodyLinearPointDirection:
// Base class for implementations of the LinearPointDirection basic CATBody
//
//=============================================================================
// Usage notes:
//
//=============================================================================
// June 98   Creation                                     M. Prince
//=============================================================================
#include "YJ000GSM.h"                  // For Windows
#include "CATBasicBodyCGM.h"
#include "CATBasicBodyLinear.h"
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


class ExportedByYJ000GSM CATBasicBodyLinearPointDirection : public CATBasicBodyLinear
{
  public:
  virtual ~CATBasicBodyLinearPointDirection();
  CATBasicBodyLinearPointDirection( const CATGeoFactory                             *iFactory,
                                    const CATVertex                                 *iOrigin,
                                    const CATEdge                                   *iCurve,
                                    const CATFace                                   *iSupport,
                                    const CATLength                                 *iParamValue,
                                    const CATLength                                 *iStart,
                                    const CATLength                                 *iEnd,
                                    const CATOrientation                             iOrientation,
                                    const CATIBasicBodyFactory::CATIBasicBodyGeoType iGeoType );

  /*CATBasicBodyLinearPointDirection( const CATGeoFactory                             *iFactory,
                                    const CATBody                                   *iOrigin,
                                    const CATBody                                   *iCurve,
                                    const CATBody                                   *iSupport,
                                    const CATLength                                 *iParamValue,
                                    const CATLength                                 *iStart,
                                    const CATLength                                 *iEnd,
                                    const CATOrientation                             iOrientation,
                                    const CATIBasicBodyFactory::CATIBasicBodyGeoType iGeoType );
*/
  CATBasicBodyLinearPointDirection( const CATGeoFactory                             *iFactory,
                                    const CATBody                                   *iOrigin,
                                    const CATBody                                   *iFirstCurve,
                                    const CATBody                                   *iSecondCurve,
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
