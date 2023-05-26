#ifndef CATGMPolyParamTools_H
#define CATGMPolyParamTools_H

// COPYRIGHT DASSAULT SYSTEMES  2017
//=============================================================================
//
//
//=============================================================================
// Usage Notes:
//
//=============================================================================
// January 2017 Creation                                              DPS
//=============================================================================

#include "CATIAV5Level.h"

#include "GMPolyTopTools.h"   // ExportedBy
#include "CATErrorDef.h"        


class CATFace;
class CATEdge;
class CATGeoPolySurface;
class CATGeoPolyCurve;

class CATPolySurfParam;
class CATSurParam;
class CATSurParamReference;
class CATCrvParamReference;


/** @nodoc @nocgmitf (do not create any specific interface) */
class ExportedByGMPolyTopTools CATGMPolyParamTools
{

public:

  static HRESULT ConvertParamOnPolyFace(CATFace * iPolyFace, const CATPolySurfParam &iPolySurfParam, CATSurParam &oSurParam);
  static HRESULT ConvertParamOnPolyFace(CATFace * iPolyFace, const CATSurParam &iSurParam, CATPolySurfParam &oPolySurfParam);

  static HRESULT ConvertParamOnGeoPolySurface(CATGeoPolySurface * iPolySurface, const CATPolySurfParam &iPolySurfParam, CATSurParam &oSurParam);
  static HRESULT ConvertParamOnGeoPolySurface(CATGeoPolySurface * iPolySurface, const CATSurParam &iSurParam, CATPolySurfParam &oPolySurfParam);

  static const CATSurParamReference * GetSurParamReference(CATFace * iFace);
  static const CATSurParamReference * GetPolySurParamReference(CATGeoPolySurface * iPolySurface);

  static const CATCrvParamReference * GetCrvParamReference(CATEdge * iEdge);
  static const CATCrvParamReference * GetPolyCrvParamReference(CATGeoPolyCurve * iPolyCurve);

};

#endif


