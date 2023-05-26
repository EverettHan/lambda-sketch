/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
//
// CATBasicBodyPlanarCurve:
// Class implementation for operator that creates CATShell with a CATPlane
// defined by a planr CATCurve.
//
//=============================================================================
// Jun. 98   Creation                                   M. Prince
// Jun. 99   Cleaning + RI 231599                       L. Mahe
//=============================================================================
#ifndef CATBasicBodyPlanarCurve_H
#define CATBasicBodyPlanarCurve_H

#include "YJ000GSM.h"
#include "CATBasicBodyPlanar.h"
#include "CATIBasicBodyFactory.h"
#include "CATTopDef.h"

class CATBody;
class CATFace;
class CATEdge;
class CATVertex;
class CATGeoFactory;
class CATCGMJournalList;
class CATCurveAffineSupport;

//-----------------------------------------------------------------------------
class ExportedByYJ000GSM CATBasicBodyPlanarCurve : public CATBasicBodyPlanar
{
  public:
    //-------------------------------------------------------------------------
    // Constructor/Detructor
    //-------------------------------------------------------------------------
    CATBasicBodyPlanarCurve( const CATGeoFactory                              *iFactory,
                             const CATVertex                                 *iOrigin,
                             const CATEdge                                   *iCurve,
                             const CATFace                                   *iSupport,
                             const CATLength                                 *iParamValue,
                             const CATLength                                 *iStart,
                             const CATLength                                 *iEnd,
                             const CATOrientation                             iOrientation,
                             const CATIBasicBodyFactory::CATIBasicBodyGeoType iGeoType );

    /*CATBasicBodyPlanarCurve( const CATGeoFactory                              *iFactory,
                             const CATBody                                   *iOrigin,
                             const CATBody                                   *iCurve,
                             const CATBody                                   *iSupport,
                             const CATLength                                 *iParamValue,
                             const CATLength                                 *iStart,
                             const CATLength                                 *iEnd,
                             const CATOrientation                             iOrientation,
                             const CATIBasicBodyFactory::CATIBasicBodyGeoType iGeoType );*/

    CATBasicBodyPlanarCurve( const CATGeoFactory                              *iFactory,
                             const CATBody                                   *iFirstBody,
                             const CATBody                                   *iSecondBody,
                             const CATBody                                   *iThirdBody,
                             const CATBody                                   *iSupport,
                             const CATLength                                 *iParamValue,
                             const CATLength                                 *iStart,
                             const CATLength                                 *iEnd,
                             const CATOrientation                             iOrientation,
                             const CATIBasicBodyFactory::CATIBasicBodyGeoType iGeoType );

    virtual ~CATBasicBodyPlanarCurve();

    //-------------------------------------------------------------------------
    // Result Access
    //-------------------------------------------------------------------------
    /*CATBody * CreateBasicBody( CATCGMJournalList *oJournal = NULL,
                               CATIBasicBodyFactory::CATIBasicBodyResultType *oResultType = NULL);*/

    CATBody * CreateBasicBody( CATTopData * iTopData,
                               CATIBasicBodyFactory::CATIBasicBodyResultType *oResultType );

  private:

    // Private Data
    CATCurveAffineSupport *_Op; 
};
#endif

