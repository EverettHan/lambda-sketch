/* -*-c++-*- */
#ifndef CATTopCheckType_H
#define CATTopCheckType_H
// COPYRIGHT DASSAULT SYSTEMES 1999
//=============================================================================
//===================================================================
// Author : JHN , from CATTopBasicBodyTools
// Date   : 06/05/2000
// CATTopCheckType : basic exploration services on topological objects :
//
// - general check services on body, throwing standard topological errors
//
//=============================================================================
// HISTORIQUE
// 06/05/00 JHN creation
// 13 09 05 ALV Nouvelles méthodes avec ThrowMode intégré -> 
//              IsBodyOneDimensionValid et IsBodyOneDomainNotNull
//              
//=============================================================================
// Usage notes:
// all methods are static.
//=============================================================================
#include "AnalysisToolsLight.h"
#include "CATTopDefine.h"
#include "CATBoolean.h"

class CATBody;
class CATPlane;
class CATError;

class CATGeoFactory;

class ExportedByAnalysisToolsLight CATTopCheckType
{
private :
  static int ThrowMode;
public:
  //-------------------------------------------------------------------------
  //- static methods
  //-------------------------------------------------------------------------
  static void SetThrowMode(int throwmode);  // set throw used if error to 1 or 0
                                            // default value is 1
  // REGLE : Quand le throw mode est change, il doit etre remis au throw mode initial par
  // defaut afin que le suivqntn'ait pas trop de surprise.
  static void GetThrowMode(int & throwmode);  // set throw used if error to 1 or 0

  //=========================================================================
  // Check body content
  // Throw error on : 1/ NULL pointer
  //                  2/ Number of domains != 1
  //                  3/ incorrect GetLowDimension() value
  //=========================================================================

  // Check if the body is a shell
//  static CATError * IsBodyShellValid(CATBody* iShellBody);
  
  // Check if the body is a Face
//  static CATError * IsBodyShellSingleFace(CATBody* iBodyShell);

  // Check if the body is Mono Planar ces
	// iBody : Body to check the propriete
	// oPlane is the result plane ffom th iBody
	// oOrient is the orientation of the plane against th orientation of th shell of the body
  static CATError * IsBodyShellMonoPlanar(CATBody* iBodyShell, CATPlane *& oPlane, CATOrientation  * Orient);

  // check if the body is a wire
//  static CATError * IsBodyWireValid(CATBody* iWireBody);

  // check if the body is a vertex (or vertexinvolume)
  static CATError * IsBodyVIVValid(CATBody* iBody);

  // check if the body is monodomain and have a dimension between iDimMin and iDimMax(include)
  // Exemple  : for a vertex use IsBodyOneDimensionValid(iBody, 0, 0, iThrowMode, oCheckError, iBuildError)
  //          : for a wire or a vertex use IsBodyOneDimensionValid(iBody, 0, 1, iThrowMode, oCheckError, iBuildError)
  // iThrowMode replace ThrowMode but don't modify it
  // Return a CATBoolean TRUE if the iBody is monodomain with the good dimension.
  static CATBoolean IsBodyOneDimensionValid(CATBody* iBody, int iDimMin, int iDimMax, int iThrowMode);

  // Check if the body is Monodomain (and this domain is not null).
  // iThrowMode replace ThrowMode but don't modify it
  static CATBoolean IsBodyOneDomainNotNull(CATBody* iBody, int iThrowMode);

  // Idem IsBodyOneDimensionValid + Check if the only domain have one cell
  // iThrowMode replace ThrowMode but don't modify it
  static CATBoolean IsBodyOneDimensionSingleCell( CATBody* iBody, int iDimMin, int iDimMax, int iThrowMode);

  // Check if the body is Mono Planar ces
	// iBodyShell : Body to check the propriete
	// oPlane is the result plane from the iBody
	// oOrient is the orientation of the plane against the orientation of the shell of the body
  // iThrowMode replace ThrowMode but don't modify it
  static CATBoolean IsBodyShellMonoPlanar(CATBody* iBodyShell, CATPlane *& oPlane, CATOrientation * oOrient, int iThrowMode);

  // Check if the body is Mono Planar (But can have different CATPlane with the same orientation and NormalVector)
	// iBodyShell : Body to check the propriete
	// oBodyPlane is the result body plane from the iBodyShell
  // iThrowMode replace ThrowMode but don't modify it
  static CATBoolean IsBodyShellIsAPlane(CATGeoFactory * iFactory, CATTopData * iData, 
                                        CATBody* iBodyShell, CATBody *& oBodyPlane, int iThrowMode);
 
};

#endif
