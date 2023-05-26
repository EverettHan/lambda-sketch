// COPYRIGHT Dassault Systemes 2004, all rights reserved
//===================================================================
//
// CATPolyGetFreeBarsOper.h
// Header definition of CATPolyGetFreeBarsOper
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  jun 2004 Creation: dhp
//===================================================================
#ifndef CATPolyGetFreeBarsOper_h
#define CATPolyGetFreeBarsOper_h

#include "CATPolyAnalyzeOperators.h"
#include "CATPolyAnalyzeOper.h"
#include "CATBoolean.h"
#include "CATListOfInt.h"

class CATIPolyMesh;


class ExportedByCATPolyAnalyzeOperators CATPolyGetFreeBarsOper : public CATPolyAnalyzeOper
{

public :

	CATPolyGetFreeBarsOper (CATIPolyMesh * polyMesh);

	~CATPolyGetFreeBarsOper (void);

	HRESULT Run (CATListOfInt& oVertices0, CATListOfInt& oVertices1,
               CATListOfInt* oBoundaryTriangles = NULL);

	HRESULT Run (int& oNbFreeBars);

};

#endif
