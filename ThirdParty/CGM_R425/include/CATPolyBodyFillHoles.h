#include "CATIAV5Level.h"
#if defined(CATIAR420) && !defined(CATPolyBodyFillHoles_h)
#define CATPolyBodyFillHoles_h

// COPYRIGHT DASSAULT SYSTEMES 2018, ALL RIGHTS RESERVED.
//===================================================================
// CATPolyBodyFixNonManifoldBars.h
//===================================================================
// Fills holes where possible in the input mesh via a
// Delaunay triangulation of a 2D projection.
//===================================================================
// Jan 2018 Creation: WE1.
//===================================================================
#include "PolyBodyCheckedEditor.h"
#include "CATSysErrorDef.h"
#include "CATPolyBodyCheckedEditor.h"
class CATIPolyMesh;
class CATPolyBody;
class CATProgressCallback;

/**
* Fills holes where possible in the input mesh via a 
* Delaunay triangulation of a 2D projection.
**/
class ExportedByPolyBodyCheckedEditor CATPolyBodyFillHoles
{
public:
	CATPolyBodyFillHoles(CATPolyBodyCheckedEditor& iEditor);

	typedef CATPolyBodyCheckedEditor::Iterator<CATPolyBodyCheckedEditor::Bar> BarIterator;
	typedef CATPolyBodyCheckedEditor::Iterator<CATPolyBodyCheckedEditor::Triangle> TriangleIterator;
	/**
	* Get the list of all open cobars on the input editor.  Client is responsible
	* for releasing oBarItr
	**/
	HRESULT GetOpenBarIterator(BarIterator*& oBarItr) const;

	typedef CATPolyBodyCheckedEditor::Iterator<CATPolyBodyCheckedEditor::Point> PointIterator;
	typedef CATPolyBodyCheckedEditor::Iterator<PointIterator*> HoleIterator;

  /**
  Sets the type of holes that GetHolesIterator will retrieve:
    eAny : all holes
    eClosedBorder: holes whose boundary is a single closed loop
    eOpenBorder: holes with non-closed boundaries
  **/
  enum HoleTopology
  {
    eAny,
    eClosedBorder,
    eOpenBorder
  };

	/**
	* Get the list of all holes on the input editor.  Each hole is a list
	* of Points from the editor; the first and last points are different.
	* Client is responsible for releasing oHoleItr and any of the iterators obtained from it.
	**/
  HRESULT GetHolesIterator(HoleIterator *&oHoleItr,
                           HoleTopology iHoleType = eAny) const;

	/**
	* Given a bar bordering a hole, get the points bounding the hole. 
	* Client is responsible for releasing oHole and any of the iterators obtained from it.
	**/
	HRESULT GetHoleIterator(CATPolyBodyCheckedEditor::Bar iBarBorderingHole,
		PointIterator*& oPointItr) const;

	/**
	* This method returns S_OK if all holes were filled, S_FALSE if
	* the some but not all holes where filled.  E_FAIL is
	* reserved for cases where the operator completely failed.
	* oTrianglesAdded is an optional pointer to a triangle iterator
	* containtnig the added triangles.  Client is responsible for releasing
	* the iterator
	**/
	HRESULT FillAllHoles(TriangleIterator** oTrianglesAdded = nullptr) const;

	/**
	* This method returns S_OK if the hole was filled.
	* oTrianglesAdded is an optional pointer to a triangle iterator
	* containtnig the added triangles.  Client is responsible for releasing
	* the iterator
	**/
	HRESULT FillHole(CATPolyBodyCheckedEditor::Bar iBarBorderingHole, TriangleIterator** oTrianglesAdded = nullptr);

	/**
	* Allows clients to set a progress callback for the operator.
	**/
	HRESULT SetProgressCallback(CATProgressCallback* iProgressCallback);

  /**
  * Set intersection checking mode. If true (default) the hole will not be
  * filled if new intersections are created
  */
  HRESULT SetIntersectionCheckMode(bool doCheck);

	~CATPolyBodyFillHoles();
	class Impl;
private:

	Impl* _impl;
};
#endif

