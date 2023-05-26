/* -*-C++-*- */
#ifndef CATDistanceMinDomDom_h
#define CATDistanceMinDomDom_h
//	COPYRIGHT DASSAULT SYSTEMES 1999
//===================================================================
//  CATDistanceMinDomDom : 
//	Computes minimal distance between two CATDomain. 
//-------------------------------------------------------------------
//	Usage Notes : see CreateDistanceMinTopo.h
//===================================================================
#include "CATIACGMLevel.h" // automatic treatment EB_2014_04_16
#include "CATDistanceMinBodyBodyImpl.h"
//#include "ExportedByCATTopImpl.h"
#include "ExportedByBOOLight.h"
//

///////////////////////////////////////////////////////////////
// This API has been deprecated. 
// Please use the new API instead:
//    CATICGMDistanceBodyBody (created using CATCGMCreateDistanceBodyBodyOp)
///////////////////////////////////////////////////////////////

class CATTopology;

/**
 * @deprecated V5R27-R419 CATICGMDistanceBodyBody
 */
class ExportedByBOOLight CATDistanceMinDomDom : public CATDistanceMinBodyBodyImpl
{
//-------------------------------------------------------------------
public :
//-------------------------------------------------------------------
#ifndef CATIACGMV5R17 
CATDistanceMinDomDom(CATGeoFactory  *iFactory,
                     CATDomain      *iDomain1,
                     CATDomain      *iDomain2);
#endif
CATDistanceMinDomDom(CATGeoFactory  *iFactory,
                     CATTopData     *iData,
                     CATTopology    *iTopo1,
                     CATTopology    *iTopo2,
                     CATBoolean iHasInfiniteGeometry = FALSE);

//WMN20190219 Now taking CATTopology here instead of CATDomain.
//WMN20190219 Indeed, DistMinCellCell used to create DistMinDomDom with NULL pointers,
//WMN20190219 rendering impossible the creation of appropriate CATBodies for DistMinBodyBodyImpl.
//WMN20190219 CATCXBodies created by default are not acceptable if CATCells are polyhedral.
//WMN20190219 From now on, a CATTopology will be provided.
//WMN20190219 If CellCell, a correct CATBody will be provided and passed on to BodyBodyImpl.
//WMN20190219 If DomDom called directly, then domains should be given.

virtual ~CATDistanceMinDomDom();     

virtual int  Run();

//-------------------------------------------------------------------
protected :
//-------------------------------------------------------------------
CATDomain   *_Domain1;
CATDomain   *_Domain2;
};
#endif










