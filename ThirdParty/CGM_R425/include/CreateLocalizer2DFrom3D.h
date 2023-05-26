// COPYRIGHT DASSAULT SYSTEMES 2001
//==========================================================================
// CreateCATLocalizer2DFrom3D
//==========================================================================
// Usage notes:
//  to instanciate the implementation
//  actually, it is necessary for the test program
//  In the case of the CleanCrv, the constructor CATLocalizer2DFrom3DCx7
//  can be used directly since it is in the same module as the CleanCrv.
//========================================================================== 
// 03/10/17      NLD  CATCreateLocalizer2DFrom3D() recoit optionnellement une liste de PCurves
// October 2005  RNO  Vure vieux CATIAV5Rxx
// April 2003    RNO  Add New Creator
// March 2001    PRG. cf CATLocalizer2DFrom3D.h interface .
//========================================================================== 
#ifndef CreateLocalizer2DFrom3D_H
#define CreateLocalizer2DFrom3D_H
// Niveau CATIA
#include "CATIAV5Level.h"

#include "FrFTopologicalOpe.h"

#include "CATLocalizer2DFrom3D.h"
#include "CATSoftwareConfiguration.h"
class CATGeoFactory;

class CATCell;
#include "ListPOfCATCell.h"
class CATCurve;
#include <CATListOfCATCurves.h>


//-----------------------------------------------------------------------------

ExportedByFrFTopologicalOpe CATLocalizer2DFrom3D* 
 CATCreateLocalizer2DFrom3D(CATGeoFactory            * factory    ,
                            CATSoftwareConfiguration * iSoftConfig,
                            CATLISTP(CATCell)        * faces      ,
                            CATLISTP(CATCurve)       * PCurveList = NULL);



//Do Not Use this one anymore !
ExportedByFrFTopologicalOpe CATLocalizer2DFrom3D* 
CreateLocalizer2DFrom3D    (CATGeoFactory            * factory,
                            CATLISTP(CATCell)        * faces  );


#endif








