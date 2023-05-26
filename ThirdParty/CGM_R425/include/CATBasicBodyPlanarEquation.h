/* -*-c++-*- */
#ifndef CATBasicBodyPlanarEquation_H
#define CATBasicBodyPlanarEquation_H

// COPYRIGHT DASSAULT SYSTEMES 1998
//=============================================================================
//
// CATBasicBodyPlanarEquation:
// Base class for implementations of the PlanarEquation basic CATBody
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


class ExportedByYJ000GSM CATBasicBodyPlanarEquation : public CATBasicBodyPlanar
{
  public:

  ~CATBasicBodyPlanarEquation() { 
    if ( _ParamValue ) { delete _ParamValue; _ParamValue = 0; }
    if ( _Start ) { delete _Start; _Start = 0; }
    if ( _End ) { delete _End; _End = 0; }
    if ( _D ) { delete _D; _D = 0; }
  }

  //---------------------------------------------------------------------------
  CATBasicBodyPlanarEquation ( const CATGeoFactory       *Factory,
                               const CATLength            A,
                               const CATLength            B,
                               const CATLength            C,
                               const CATLength            D,
                               const CATOrientation       Orientation );

  //-------------------------------------------------------------------------
  /*CATBody * CreateBasicBody( CATCGMJournalList *oJournal = NULL,
                             CATIBasicBodyFactory::CATIBasicBodyResultType *oResultType = NULL);*/
  
  CATBody * CreateBasicBody( CATTopData * iTopData,
                             CATIBasicBodyFactory::CATIBasicBodyResultType *oResultType );
};


#endif

