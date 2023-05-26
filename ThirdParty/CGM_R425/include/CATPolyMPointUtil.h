// COPYRIGHT DASSAULT SYSTEMES 2005, all rights reserved
//===================================================================
//
// CATPolyMPointUtil.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// Apr 2005 Creation: ndo
//===================================================================
#ifndef CATPolyMPointUtil_h
#define CATPolyMPointUtil_h

#include "CATPolyMiscellaneous.h"
#include "CATErrorDef.h"     // HRESULT definition

class CATIPolyMesh;
class CATPolyMPoint;
class CATMathVector;


class ExportedByCATPolyMiscellaneous CATPolyMPointUtil
{

public :

  /**
  * Constructor.
  */
	CATPolyMPointUtil (CATIPolyMesh * polyMesh);

  /**
  * Destructor.
  */
	~CATPolyMPointUtil (void);

  /**
  * Returns a normal associated with a mesh point.
  * @param meshPoint
  *   The mesh point for which a normal is computed.
  * @param normal
  *   The resulting normal.
  * @return
  *   TRUE if the operation succeeded and FALSE otherwise.
  */
  HRESULT GetMeshPointNormal (const CATPolyMPoint & meshPoint,
                              CATMathVector & normal);

private :

  CATIPolyMesh * _PolyMesh;

};

#endif
