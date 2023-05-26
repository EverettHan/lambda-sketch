// COPYRIGHT Dassault Systemes 2003
//===================================================================
// CATGeomFeQuickMesh
//===================================================================
// April 2003 - ALA - Creation
//===================================================================



#ifndef CATGeomFeQuickMesh_H
#define CATGeomFeQuickMesh_H

#include "MathGeomFe.h"

class ExportedByMathGeomFe CATGeomFeQuickMesh 
	{
	public :
		int _NumberOfVertices;
		float *_Vertices;
		float *_Normals;
		int _NbTriangles;
		int *_TriangleIndices;
        float *_ObjectiveNormals;
		float *_MiddlePoint;
        CATGeomFeQuickMesh();
		CATGeomFeQuickMesh(int iNumberOfVertices, int iNbTriangles);
		~CATGeomFeQuickMesh();
	} ;



# endif
