#ifndef CATVISREPADJACENCYCOMPUTER_H
#define CATVISREPADJACENCYCOMPUTER_H

/*
 * tool to compute the adjacency between rep pathes
 */

// VisualizationFoundation Framework
#include "SGInfra.h"
class CATPickPathList;
// System Framework
#include "CATListOfInt.h"
#include "CATBoolean.h"
#include "IUnknown.h"

class CATPickPath;

	HRESULT ExportedBySGInfra ComputeRepPathesAdjacency(CATPickPathList& iPickPathList, const CATListOfInt& iInitialPickPathIndexList, const CATListOfInt& iOtherPickPathIndexList, CATListOfInt& oInitialAndAdjoiningPickPathIndexList);

    CATBoolean ExportedBySGInfra CheckForContiguity(CATPickPath* ipFstPath, CATPickPath* ipSndPath);

#endif
