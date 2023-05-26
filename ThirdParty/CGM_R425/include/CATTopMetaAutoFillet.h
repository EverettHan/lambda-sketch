// COPYRIGHT Dassault Systemes 2002
//===================================================================
/*
=============================================================================

 DESCRIPTION : Automatic fillet operator

=============================================================================
*/

//=============================================================================
//
// <ClassName>: CATTopMetaAutoFillet
//
//=============================================================================
// Usage Notes:
//	none
//=============================================================================
// Jul 2003   Creation                  JHG
//=============================================================================

#ifndef CATTopMetaAutoFillet_H
#define CATTopMetaAutoFillet_H

#include "AutoBase.h"		// exported by
#include "CATTopODTAutoFillet.h"
#include "ListPOfCATFace.h"

#include "CATGeoDef.h"

class CATFace;
class CATEdge;
class CATAutoFilletScan;
class CATTopMetaAutoFilletImpl;
class CATTopAutoFilletParting;

class ExportedByAutoBase CATTopMetaAutoFillet : public CATTopODTAutoFillet
{
  CATCGMVirtualDeclareClass(CATTopMetaAutoFillet);
public:
	
/** @nodoc 
  * cannot be called
  * use CATCreateTopAutoFillet to create the operator
  */

	// Constructor
  CATTopMetaAutoFillet(CATGeoFactory *        iFactory,
                    CATTopData    *        iTopData, CATTopMetaAutoFilletImpl *iImpl);
	
  // Destructor
	virtual ~CATTopMetaAutoFillet();

protected:
  CATTopMetaAutoFilletImpl *GetMetaAutoFilletImpl();
};

// Global Create functions, use them to create the operator

	// iFactory:        Input factory
  // iTopData:        Top Data
  // iBody:           Input Body
  // iConvexRadius    Radius applied to all convex edges
  // iConcaveRadius   Radius applied to all concave edges

ExportedByAutoBase CATTopMetaAutoFillet * CATCreateTopMetaAutoFillet(CATGeoFactory * iFactory,
                                                                   CATTopData * iTopData,
                                                                   CATBody* iBody, double iConvexRadius,
                                             double iConcaveRadius, CATTopAutoFilletImpl *iCopySettings);

#endif
