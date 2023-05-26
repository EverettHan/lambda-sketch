// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyInertiaBoundingBox.h
//
//===================================================================
//
// January 2010  Creation: TL1
//===================================================================
#ifndef CATPolyBodyInertiaBoundingBox_H
#define CATPolyBodyInertiaBoundingBox_H

#include "PolyBodyMeasures.h"

#include "CATErrorDef.h"
#include "CATMathBox.h"
#include "CATMathVector.h"
#include "CATMathPoint.h"

#include "CATMath.h"

#include "CATPolyBody.h"
#include "CATPolyFace.h"
#include "CATIPolySurface.h"
#include "CATIPolyMesh.h"

#include "CATPolyBoundingVolumeCompute.h"
#include "CATBoolean.h"

/**
* This class provide a static method to compute an OOBB along polybody inertia axis 
* <br><b>Role</b>: Provide an OOB along @href CATPolyBody inertia axis 
*/
class ExportedByPolyBodyMeasures CATPolyBodyInertiaBoundingBox
{

public:

  /** 
  * Short role of the method.
  *
  * <br><b>Role</b>: Compute bounding box of CATPolyBody on given axis.
  * The method takes into account all its Polyfaces
  * @param iPolyBody [in]
  *   The CATPolyBody.
  * @param iAxis [in]
  *  3 axis defineing space where bounding box is expressed 
  * @param iCenter [in]
  *  Center Of Gravity of iPolyBody
  * @param oPolyBodyBB [OUT]
  * The Output Bounding Box. it can be NOT empty as input. 
  * New poitns will be added to the existing box.
  * @return
  * <code>S_OK</code>   : if OK.
  * <code>E_FAIL</code> : if FAIL.
  */

  static HRESULT Compute( const CATPolyBody   &iPolyBody,
                          const CATMathVector iAxis[3],
                          const CATMathPoint  &iCenter,
                          CATMathBox          &oPolyBodyBB,
                          const CATBoolean    &iGlobalSpace=TRUE);
};

#endif // !CATPolyBodyInertiaBoundingBox
