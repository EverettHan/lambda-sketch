/* -*-c++-*- */
#ifndef CATBasicBodyPlanarMeanOfPoints_H
#define CATBasicBodyPlanarMeanOfPoints_H

// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
//
// CATBasicBodyPlanarMeanOfPoints:
// Base class for implementations of the PlanarMeanOfPoints basic CATBody
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


class ExportedByYJ000GSM CATBasicBodyPlanarMeanOfPoints : public CATBasicBodyPlanar
{
  public:

  CATBasicBodyPlanarMeanOfPoints ( const CATGeoFactory                   *Factory,
                       const CATLISTP(CATVertex)                        *Points,
                       const CATMathSetOfVectors                        *Vectors,
                       const CATFace                                    *Support,
                       const CATIBasicBodyFactory::CATIBasicBodyGeoType  GeoType );

  //-------------------------------------------------------------------------
  CATBasicBodyPlanarMeanOfPoints ( const CATGeoFactory                   *Factory,
                       const CATLISTP(CATBody)                          *Points,
                       const CATMathSetOfVectors                        *Vectors,
                       const CATBody                                    *Support,
                       const CATIBasicBodyFactory::CATIBasicBodyGeoType  GeoType );

  //-------------------------------------------------------------------------
  /*CATBody * CreateBasicBody( CATCGMJournalList *oJournal = NULL,
                             CATIBasicBodyFactory::CATIBasicBodyResultType *oResultType = NULL);*/
  
  CATBody * CreateBasicBody( CATTopData * iTopData,
                             CATIBasicBodyFactory::CATIBasicBodyResultType *oResultType );
};


#endif

