// COPYRIGHT Dassault Systemes 2002
//===================================================================
/*
=============================================================================

 DESCRIPTION : Topological Shell Unfold operator

=============================================================================
*/

//=============================================================================
//
// <ClassName>: CATTopSingleAutoFillet
//
//=============================================================================
// Usage Notes:
//	Develop a multi-patch and mono-cell body 
//	The Surface under the body must be a ruled surface.
//=============================================================================
// Jul 2003   Creation                  JHG
//=============================================================================

#ifndef CATTopSingleAutoFillet_H
#define CATTopSingleAutoFillet_H

#include "CATTopODTAutoFillet.h"
#include "ListPOfCATPersistentFaces.h"

class CATTopSingleAutoFilletImpl;
class CATPersistentCellFactory;
class CATPersistentBody;
class CATAutoBaseThreadContext;

class ExportedByAutoBase CATTopSingleAutoFillet : public CATTopODTAutoFillet
{
public:
	
/** @nodoc 
  * cannot be called
  * use CATCreateTopAutoFillet to create the operator
  */

	// Constructor
  CATTopSingleAutoFillet(CATGeoFactory *        iFactory,
                    CATTopData    *        iTopData, CATTopSingleAutoFilletImpl *iImpl);
	
  // Destructor
	virtual ~CATTopSingleAutoFillet();

  CATPersistentBody *GetResultPersistentBody();

  CATTopSingleAutoFilletImpl *GetSingleAutoFilletImpl();

  void SetFullSuccessOnly(CATBoolean iFullSuccessOnly);
  void SetMute(int iMute);

protected:
};

// Global Create functions, use them to create the operator

	// iFactory:        Input factory
  // iTopData:        Top Data
  // iBody:           Input Body
  // iConvexRadius    Radius applied to all convex edges
  // iConcaveRadius   Radius applied to all concave edges

CATTopSingleAutoFillet * CATCreateTopSingleAutoFillet(CATGeoFactory * iFactory,
                                                                   CATTopData * iTopData,
                                                                   CATBody* iBody, 
                                             double iConvexRadius,
                                             double iConcaveRadius, CATTopAutoFilletImpl *iCopySettings);

CATTopSingleAutoFillet *CreatePersistentTopSingleAutoFillet(CATGeoFactory * iFactory,
                                             CATTopData * iTopData,
                                             CATPersistentBody &iPersistentBody,
                                             CATPersistentCellFactory &iPersistentCellFactory, 
                                             double iConvexRadius,
                                             double iConcaveRadius,
                                             ListPOfCATPersistentFaces &iKeepFaces,
                                             ListPOfCATPersistentFaces &iRemoveFaces,
                                             ListPOfCATPersistentFaces &iOnlyFaces,
                                             const CATAutoBaseThreadContext &iThreadContext);

#endif
