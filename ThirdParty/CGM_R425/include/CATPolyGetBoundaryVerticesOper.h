// COPYRIGHT Dassault Systemes 2004, all rights reserved
//===================================================================
//
// CATPolyGetBoundaryVerticesOper.h
// Header definition of CATPolyGetBoundaryVerticesOper
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  jun 2004 Creation: dhp
//===================================================================
#ifndef CATPolyGetBoundaryVerticesOper_h
#define CATPolyGetBoundaryVerticesOper_h

#include "CATPolyAnalyzeOperators.h"
#include "CATPolyAnalyzeOper.h"
#include "CATBoolean.h"

class CATIPolyMesh;
class CATPolyTopoUtil;

#include "CATListOfInt.h"

class ExportedByCATPolyAnalyzeOperators CATPolyGetBoundaryVerticesOper : public CATPolyAnalyzeOper
{

public :

	CATPolyGetBoundaryVerticesOper (CATIPolyMesh * polyMesh);

	~CATPolyGetBoundaryVerticesOper (void);

	HRESULT Run (CATListOfInt & vertices);

	HRESULT Run (int & numBoundaryVertices);

private :

};

#endif
