// COPYRIGHT DASSAULT SYSTEMES 2011, ALL RIGHTS RESERVED.
//===================================================================
//
// CATCGMUVVertexWTData.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// Nov 2016  Creation: TPG
//===================================================================

#ifndef CATCGMUVVertexWTData_H
#define CATCGMUVVertexWTData_H

#include "ExportedByTessellateCommon.h"
#include "CATMapOfPtrToInt.h"
#include "CATVertex.h"
#include "CATPoint.h"

class CATCell;

class ExportedByTessellateCommon CATCGMUVVertexWTData
{
public:
  CATCGMUVVertexWTData();
  virtual ~CATCGMUVVertexWTData();

public:
  //Geometry  
	const double* GetVertexPosition () const
	{
		//int Tag = _Vertex ? _Vertex->GetPersistentTag() : 0;
		//if (_Vertex && _Position) //dbg
		//{
		//	CATPoint * point;
		//	point = _Vertex->GetPoint();
		//	if (point) 
		//	{
		//		double Coord[3];  
		//		point->GetCoord(Coord[0], Coord[1], Coord[2]);
		//		if (_Position[0] != Coord[0] || _Position[1] != Coord[1] || _Position[2] != Coord[2])
		//		{
		//			int NOT_WATERTIGTH = 1;
		//		}
		//	}
		//}
		return _Position;
	}

	double* GetVertexPosition_ForUpdate ()
	{
		//int Tag = _Vertex ? _Vertex->GetPersistentTag() : 0;
		if (_Position) // already filled
			return 0;
		_Position = new double [3];
		memset(_Position, 0, 3 * sizeof (double)); // avoid UMR
		return _Position;
	}

  //topo
	// iType = 1 : start of edge
	//         2 : end of edge
	//         0 : 3D vertex or face vertex full
  void AddBoundedCells(CATCell* iBoundedCell, int iType=0)
	{
		//int Tag = _Vertex ? _Vertex->GetPersistentTag() : 0;
		if (iBoundedCell)
			_BoundedCells.Insert(iBoundedCell,iType);
	}

	const CATMapOfPtrToInt* GetBoundedCells() const
	{
		return &_BoundedCells;
	}

  CATVertex* GetVertex(){return _Vertex;}
  void SetVertex(CATVertex* iVertex)
	{
		//int Tag = iVertex ? iVertex->GetPersistentTag() : 0;
		_Vertex=iVertex;
	}

private:
  CATVertex* _Vertex;
  double* _Position;
  //topo
  CATMapOfPtrToInt _BoundedCells;
};

#endif
