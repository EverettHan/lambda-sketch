#ifndef DynCreateTopoOperators_h_
#define DynCreateTopoOperators_h_

// COPYRIGHT DASSAULT SYSTEMES 1999

#include "BODYNOPE.h"

#include "CATListOfCATCurves.h"
#include "CATMathDef.h"

class CATGeoFactory;
class CATCurve;
class CATSurface;
class CATDistanceMinPtCrv;
class CATMathDirection;
class CATBody;
class CATPlane;


/**
 * Do not use. Use now the <tt>CATDynCreatePrism</tt> global function.
 */
ExportedByBODYNOPE
CATBody*  CATDynPrismOffsets(CATGeoFactory *           iGeoFactory,
                            const CATLISTP(CATCurve)* iProfBody,
                            CATPlane*                 iSupport, 
                            const CATMathDirection&   iDir,
                            CATLength                 iStartOffset, 
                            CATLength                 iEndOffset);

   
// Boolean Operations
// Union=1 Intersection=2 Removal=3
/**
 * Do not use. Use now the <tt>CATDynCreateBoolean</tt> global function.
 */
ExportedByBODYNOPE
CATBody*  CATDynBoolean(CATGeoFactory *        iGeoFactory,
                           CATBody*               iBody1,
                           CATBody*               iBody2,
                           int                    iModeOperation);

//-----------------------------------------------------------------------------




#endif
