#include "CATIAV5Level.h"
#if defined(CATIAR420) && !defined(CATPolyBodyCheckedEditor_h)
#define CATPolyBodyCheckedEditor_h

// COPYRIGHT DASSAULT SYSTEMES 2017, ALL RIGHTS RESERVED.
//===================================================================
// CATPolyCheckedEditor.h
//===================================================================
// This class provides services for safely editing polyhedral data.
//
// Each edit is checked and will fail if it adds new auto-intersections,
// or other prohibited configurations.
//
//
//===================================================================
// Oct 2017 Creation: OZK.
//===================================================================

#include "PolyBodyCheckedEditor.h"
#include "CATPolyExactArithmetic.h"
#include "CATDataType.h"
#include "CATPolyRefCounted.h"
#include "CATSysErrorDef.h"

class CATIPolyMesh;
class CATPolyExactArithmetic;
class CATPolyBody;
class CATTolerance;
class CATPolyCell;
class CATIPolyObject;
class CATPolyBodyUnaryObserver;
class CATPolyFace;

class ExportedByPolyBodyCheckedEditor CATPolyBodyCheckedEditor
{
public:
	/**
	* Construct a CATPolyBodyCheckedEditor from a CATIPolyMesh.
	* The input mesh will not be modified.  A body will be created which
	* allows efficent edits on the result
	**/
	CATPolyBodyCheckedEditor(CATIPolyMesh const& iMesh,
		CATTolerance const& tol, // used for clearance checking etc.
		CATPolyExactArithmetic::Mode arithMode = CATPolyExactArithmetic::eDouble);

	/**
	* Construct a CATPolyBodyCheckedEditor from a CATPolyBody.
	* The input will not be modified.  A new body will be created
	* which allows efficent edts on the result.
	**/

	CATPolyBodyCheckedEditor(CATPolyBody const& iBody,
		CATTolerance const& tol, // used for clearance checking etc.
		CATPolyBodyUnaryObserver* pObserver = NULL,
		CATPolyExactArithmetic::Mode arithMode = CATPolyExactArithmetic::eDouble);

	/**
	*@name Point and Triangle Handles.
	{
	**/
	/**
	* A handle is an opaque 64 bit unsigned int.  0 is used to indicate
	* an invalid handle.
	**/
	template <int tag>
	struct Handle
	{
		CATULONG64 _index;

		Handle():_index(0){}
		explicit Handle(CATULONG64 index) :_index(index) {}
		explicit operator bool() const
		{
			return _index != 0;
		}
		bool operator==(const Handle<tag> other) const
		{
			return _index == other._index;
		}
		bool operator!=(const Handle<tag> other) const
		{
			return _index != other._index;
		}
		bool operator<(const Handle<tag> other) const
		{
			return _index < other._index;
		}
		bool operator>(const Handle<tag> other) const
		{
			return _index > other._index;
		}
	};
	typedef Handle<0> Point;
	typedef Handle<2> Triangle;
	struct Bar
	{
		Bar(){}
		Bar(Point pt1, Point pt2) : first(pt1), second(pt2)
		{}

		Point first;
		Point second;
		inline bool operator==(const Bar& other) const;
		inline bool operator!=(const Bar& other) const;
		inline bool operator<(const Bar& other) const;
		inline bool operator>(const Bar& other) const;
		inline explicit operator bool() const;
	};
	/* } */

	/**
	*@name Iterators
	{
	**/
	class IteratorBase : public CATPolyRefCounted
	{
	public:
		virtual void Begin() = 0;
		virtual bool End() const= 0;
		virtual void Increment() = 0;
		virtual void operator++() final
		{
			Increment();
		}
	};
	template<typename T>
	class Iterator : public IteratorBase
	{
	public:
		typedef T ValueType;
		virtual T Get() const=0;
	};

	/**
	* Gets iterator to points currently in the mesh.
	* On failure, it returns a null Iterator
	**/
	void GetPointIterator(Iterator<Point>*& oItr) const;
	/**
	* Gets iterator to bars currently in the mesh.
	* On failure, it returns a null Iterator
	**/
	void GetBarIterator(Iterator<Bar>*& oItr) const;
	/**
	* Gets iterator to open bars (a bar with a single  triangle neighbor) 
	* currently in the mesh.
	**/
	void GetOpenBarIterator(Iterator<Bar>*& oItr) const;
	/**
	* Gets iterator to triangles currently in the mesh.
	* On failure, it returns a null Iterator
	**/
	void GetTriangleIterator(Iterator<Triangle>*& oItr) const;
	/**
	* Destructor.
	**/
	~CATPolyBodyCheckedEditor();

	/**
	* This method returns a pointer to the CATPolyBody currently being edited.
	* It allows you to, e.g., draw the CATPolyBody on a screen.
	*
	* No ownership transfer happening.  If you want to keep the body alive,
	* AddRef it.  Otherwise, the lifecycle is linked to this.
	*
	* Also: note that the polymesh geometry within the CATPolyBody may
	* note have contigious vertex indices (i.e, vertices aren't necessarily 
	* numbered 1,2,3,...Nvert).  Negative numbers may also be used as vertex ids
	* within the polymeshes in this body.
	*
	* Also note: there is a current limitation where CATPolyBodyToCATBodyChecker::Check doesn't
	* work well with bodies that have CATPolyEditableMesh as geometry.  Please copy the body
	* if you want to do more than render it.
	**/
	CATPolyBody const* GetBody() const;

	/**
	*@name Point Services
	{
	**/

	/**
	* Get the position associated with a mesh point
	*/
	HRESULT GetPointPosition(Point p, CATMathPoint& oPosition) const;
	/**
	* Set the position associated with a mesh point.  This will
	* fail if the new point position would cause auto intersections
	* between mesh triangles.
	*/
	HRESULT SetPointPosition(Point p, CATMathPoint const& iPosition);

	/**
	 * @brief Gets iterator to all triangles neighboring input point.  Client owns the iterator and must release it.
	 * @param p 
	 * @param oNbrTriangles 
	 * @return 
	*/
	HRESULT GetTriangleNeighbors(Point p, Iterator<Triangle>*& oNbrTriangles) const;

	/**
	 * @brief Gets the polycell and index associated with a given point
	 * @param p 
	 * @param oCell 
	 * @param oIdx 
	 * @return 
	*/
	HRESULT GetCellAndIndex(Point p, CATPolyCell*& oCell, int& oIdx) const;

	Point GetPoint(CATPolyCell const& iCell, int iIdx) const;

	/*}*/

	/**
	*@name Triangle Services
	{
	**/
	/*
	* Get the points which make up the triangle.
	*/
	HRESULT GetTrianglePoints(Triangle t, Point oPoints[3]) const;
	/*
	* Get the positions of the points which make up the triangle.
	*/
	HRESULT GetTrianglePositions(Triangle t, CATMathPoint oPoints[3]) const;
	/*
	* Remove a triangle
	*/
	HRESULT RemoveTriangle(Triangle t);
	/*
	* Add a triangle.  This can fail if the new triangle would cause 
	* auto-intersections.
	*/
	HRESULT AddTriangle(Point const iPoints[3], Triangle& oTriangle);
	/*}*/
	/*
	* Add a triangle.  Does not check for intersections
	*/
	HRESULT ForceAddTriangle(Point const iPoints[3], Triangle& oTriangle);
	/*}*/
	/*
	* Returns an iterator to triangles intersecting  a sphere centered at center\
	* with a radius of radius
	*/
	void GetTrianglesInSphere(CATMathPoint const& center, double radius, Iterator<Triangle>*& oItr);

	/*
	* Returns the Triangle id for a given CATPolyFace* and triangle index.
	*/
	Triangle GetTriangle(CATPolyFace const& iFace, int iTriangleIdx) const;

	/**
	 * @brief Gets polyface and triangle index associated with given triangle.
	 * @param t 
	 * @param oFace 
	 * @param oTriangleIdx 
	 * @return 
	*/
	HRESULT GetFaceAndIndex(Triangle t, CATPolyFace*& oFace, int& oTriangleIdx) const;
	/*}*/

  /**
  *@name Bar Services
  {
  **/

  /**
  * Flips a bar in the mesh.  I.e., if Bar(a,b) is in triangles a,b,c and b,a,d, flipping
  * will result in triangles a,d,c and c,d,b.
  *
  * This operation will fail if flipping causes new self intersections, if the input bar
  * is adjacent to some number of triangles != 2, or if the input bar lies on a CATPolyEdge.
  **/
  HRESULT FlipBar(Bar b);

  /**
  * Merges two points in the mesh.  I.e., all triangles containing the point from (such as a,b,iFrom) are 
  * revised so that Point iFrom is replaced with Point iTo (e.g., a,b, iTo).
  *
  * This operation will fail if it causes new self intersections or new nonmanifold bars to be created.
  **/
  HRESULT MergePoints(Point iFrom, Point iTo);
  /*}*/

	/**
	*@name BVH Related Queries
	{
	**/
	struct ExportedByPolyBodyCheckedEditor PositionOnTriangle
	{
		double barycentricCoords[3];
		CATMathPoint P;
		Triangle t;
		PositionOnTriangle();
		PositionOnTriangle(PositionOnTriangle const&);
		PositionOnTriangle& operator=(PositionOnTriangle const&);
	};
	HRESULT Pick(
		CATMathPoint const& root, CATMathVector const& direction, 
		Iterator<PositionOnTriangle>*& oPositionsOnRay) ;

	/*}*/

	/**
	*@name Simple repair services
	{
	**/
	/**
	* Scans the meshes to remove any duplicate Points (i.e., Points with the same position)
	* or duplicate triangles (multiple Triangles with the same Points).
	*
	* Assuming there is no duplicated topology this operation doesn't do anything.
	*
	* Average time performance should be O(NbTriangles + NbPoints).
	**/
	HRESULT RemoveDuplicateMicroTopology();
	/*}*/

	/**
	*@name Observer
	{
	**/
	class ExportedByPolyBodyCheckedEditor Observer :public CATPolyRefCounted
	{
	public:
		virtual ~Observer();
		/**
		* Called when the position of a points has been set. p is the Point whose position has been set to iPosition.
		**/
		virtual void ReactToSetPointPosition(Point p, CATMathPoint const& oldPosition, CATMathPoint const& newPosition);
		/**
		* Called when a triangle is removed. oTriangle is the index of the new triangle and PointsOfTriangle holds the 3 Points of the triangle.
		**/
		virtual void ReactToRemoveTriangle(Triangle t, Point const PointsOfTriangle[3]);
		/**
		* Called when a triangle is added. oTriangle is the index of the new triangle and iPoints holds the 3 Points of the triangle.
		**/
		virtual void ReactToAddTriangle(Point const iPoints[3], Triangle& oTriangle);
		/**
		* Called when a bar has been flipped. b is the bar that has been flipped and no longer exists.
		* 
		* Bar flipping is implemented by removing and adding triangles, so the calls from a bar flip will be two
		* calls to ReactToRemoveTriangle, followed by two calls to ReactToAddTriangle, followed a call to ReactToFlipBar
		**/
		virtual void ReactToFlipBar(Bar b);
		/**
		* Called when two points are merged. Point iFrom has been merged into iTo.
		*
		* Bar Collapses are implemented by first removing all of the triangles connected to iFrom and then adding
		* the corresponding triangles connected to iTo where they would not become degenerate. The observer calls
		* from a bar collapse will be one call to ReactToRemoveTriangle for each triangle connected to iFrom, followed
		* by one call to ReactToAddTriangle for each new triangle (generally fewer than the number of removed triangles),
		* followed by a call to ReactToMergePoints
		**/
		virtual void ReactToMergePoints(Point iFrom, Point iTo);
		virtual void ReactToRenameTriangle(Triangle oldName, Triangle newName);
	};
	/**
	* Adds an observer to the mesh
	**/
	HRESULT RegisterObserver(Observer& iObserver);
	/**
	* Removes an observer from the mesh
	**/
	HRESULT UnRegisterObserver(Observer& iObserver);
	/*}*/

	HRESULT CheckValidity();

  /**
  * Enables (true) or disables (false) caching in internal datastructures
  **/
  virtual void SetCachingStatus(bool status);

	class Impl;
  friend class CATPolyBodyCheckedEditorFriend;
private:
	CATPolyBodyCheckedEditor(CATPolyBodyCheckedEditor const&);
	CATPolyBodyCheckedEditor& operator=(CATPolyBodyCheckedEditor const&);

	Impl* _impl;
};


bool CATPolyBodyCheckedEditor::Bar::operator==(const CATPolyBodyCheckedEditor::Bar& other) const
{
	return first == other.first && second == other.second;
}
bool CATPolyBodyCheckedEditor::Bar::operator!=(const CATPolyBodyCheckedEditor::Bar& other) const
{
	return !(*this == other);
}
bool CATPolyBodyCheckedEditor::Bar::operator<(const CATPolyBodyCheckedEditor::Bar& other) const
{
	// lex order by first and second.
	if (first < other.first)return true;
	if (first > other.first)return false;
	return second < other.second;
}
bool CATPolyBodyCheckedEditor::Bar::operator>(const CATPolyBodyCheckedEditor::Bar& other) const
{
	return other < *this;
}
CATPolyBodyCheckedEditor::Bar::operator bool() const
{
	return first && second;
}
#endif
