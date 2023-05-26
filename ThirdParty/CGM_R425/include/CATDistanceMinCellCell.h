/* -*-C++-*- */
#ifndef CATDistanceMinCellCell_h
#define CATDistanceMinCellCell_h
//	COPYRIGHT DASSAULT SYSTEMES 1999
//===================================================================
//  CATDistanceMinCellCell : 
//	Computes minimal distance between two CATCell. 
//-------------------------------------------------------------------
//	Usage Notes : see CreateDistanceMinTopo.h
//===================================================================
#include "CATIACGMLevel.h" // automatic treatment EB_2014_04_16
#include "CATDistanceMinDomDom.h"
//#include "ExportedByCATTopImpl.h"
#include "ExportedByBOOLight.h"


///////////////////////////////////////////////////////////////
// This API has been deprecated. 
// Please use the new API instead:
//    CATICGMDistanceBodyBody (created using CATCGMCreateDistanceBodyBodyOp)
///////////////////////////////////////////////////////////////

/**
 * @deprecated V5R27-R419 CATICGMDistanceBodyBody
 */
class ExportedByBOOLight CATDistanceMinCellCell : public CATDistanceMinDomDom
{
//-------------------------------------------------------------------
public :
//-------------------------------------------------------------------
#ifndef CATIACGMV5R17 
CATDistanceMinCellCell(CATGeoFactory  *iFactory,
                       CATCell        *iCell1,
                       CATCell        *iCell2);
#endif

CATDistanceMinCellCell(CATGeoFactory  *iFactory,CATTopData * iData,
                       CATCell        *iCell1,
                       CATCell        *iCell2);

virtual ~CATDistanceMinCellCell();     

virtual int  Run();

//-------------------------------------------------------------------
private:
//-------------------------------------------------------------------
CATCell   *_Cell1;
CATCell   *_Cell2;
};


#endif










