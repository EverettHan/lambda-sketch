/* -*-c++-*- */
#ifndef CATBasicBodySplineWilsonFohler_H
#define CATBasicBodySplineWilsonFohler_H

// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
//
// CATBasicBodySplineWilsonFohler:
// Base class for implementations of the SplineWilsonFohler basic CATBody
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
//class CATLength;
//class CATAngle;
//class CATOrientation
class CATSurface;
class CATPlane;

class CATCGMJournalList;


class ExportedByYJ000GSM CATBasicBodySplineWilsonFohler : public CATBasicBodyLinear
{
  public:

  // Changer Interface pour Spline!
    
  CATBasicBodySplineWilsonFohler ( const CATGeoFactory                   *Factory,
                       const CATLISTP(CATVertex)                        *Points,
                       const CATMathSetOfVectors                        *Vectors,
                       const CATFace                                    *Support,
                       const CATIBasicBodyFactory::CATIBasicBodyGeoType  GeoType );

  //-------------------------------------------------------------------------
  CATBasicBodySplineWilsonFohler ( const CATGeoFactory                   *Factory,
                       const CATLISTP(CATBody)                          *Points,
                       const CATMathSetOfVectors                        *Vectors,
                       const CATBody                                    *Support,
                       const CATIBasicBodyFactory::CATIBasicBodyGeoType  GeoType );

  //-------------------------------------------------------------------------

  CATBody * CreateBasicBody( CATTopData * iTopData,
                             CATIBasicBodyFactory::CATIBasicBodyResultType *oResultType );

  /**
   * @nodoc
   * Deprecated
   */
  /*CATBody * CreateBasicBody( CATCGMJournalList *oJournal = NULL,
                             CATIBasicBodyFactory::CATIBasicBodyResultType *oResultType = NULL);*/
  
  //- Convert a tangent from a Wilson-Fohler to a Cubic C2 at a control point
  //- WF stands for Wilson-Fohler and CC2 stands for Cubic with C2 continuity
  //- The origin of the Support is the control point of the tangent to evaluate
  void ConvertVector( CATMathPoint  &iPoint,
                      CATMathPoint  &iNextPoint,
                      CATMathPoint  &iSuppPoint,
                      CATMathVector &oCC2NextTangent,
                      CATMathVector &oCC2SuppTangent );


};


#endif

