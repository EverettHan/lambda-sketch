#ifndef CATIMshMesh_H
#define CATIMshMesh_H

// CATIMshMesh -*- C++ -*-

//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2021-2022
//=============================================================================
/**
 * @CAA2Level L0
 * @CAA2Usage U3
 */

//=============================================================================
//
// CATIMshMesh :
// Interface of the minimal mesh
//
//=============================================================================

#include "CATMshBase.h"
#include "ExportedByCATMshMesherCore.h"

#include <vector>

/**
 * Class holding any entity base tag
 * Tags are essentially unsigned integers
 */
class ExportedByCATMshMesherCore CATMshBaseTag{
public:
	/**
	 * Constructor for an empty base tag
	 */
	explicit CATMshBaseTag() noexcept : _tag(0) {}

	/**
	 * Constructor for a given unsigned integer
	 * @param tag
	 *   the value of the tag
	 */
	explicit CATMshBaseTag(const unsigned int tag) noexcept : _tag(tag) {};

	/**
	 * Copy constructor
	 * @param tag
	 *   the tag
	 */
	CATMshBaseTag(const CATMshBaseTag& tag) noexcept {_tag = tag._tag;};

	/**
	 * Destructor
	 */
	~CATMshBaseTag() = default;

	/**
	 * Returns whether the tag is empty or not
	 */
	bool IsEmpty() const{
		if(!_tag)
			return true;
		return false;
	}

	/**
	 * Returns the value of the tag
	 */
	unsigned int Get() const{
		return _tag;
	}

	/**
	 * Ordering operator
	 */
	bool operator<(const CATMshBaseTag &tag) const
		{return _tag < tag.Get();}

	/**
	 * Equality operator
	 */
	bool operator==(const CATMshBaseTag &tag) const
		{return _tag == tag.Get();}

	/**
	 * Inequality operator
	 */
	bool operator!=(const CATMshBaseTag &tag) const
			{return !operator==(tag);}

private:
	unsigned int _tag;

};

/**
 * Class holding any entity tag
 * A CATMshTag is a CATMshBaseTag that can be made from other CATMshBaseTags
 */
class ExportedByCATMshMesherCore CATMshTag final : public CATMshBaseTag{
public:
	/**
	 * Constructor for an empty tag
	 */
	explicit CATMshTag() noexcept : CATMshBaseTag() {}

	/**
	 * Constructor for a given unsigned integer
	 * @param tag
	 *   the value of the tag
	 */
	explicit CATMshTag(const unsigned int tag) noexcept : CATMshBaseTag(tag) {}

	/**
	 * Destructor
	 */
	~CATMshTag() = default;
};

/**
 * Class holding any entity index
 * Indices are essentially unsigned integers
 */
class ExportedByCATMshMesherCore CATMshIndex{
public:
	/**
	 * Constructor for an empty index
	 */
	explicit CATMshIndex() noexcept : CATMshIndex(0) {}

	/**
	 * Constructor for a given unsigned integer
	 * @param idx
	 *   the value of the index
	 */
	explicit CATMshIndex(const unsigned int idx) noexcept : _index(idx) {}

	/**
	 * Destructor
	 */
	~CATMshIndex() = default;

	/**
	 * Returns whether the index is empty or not
	 */
	bool IsEmpty() const{
		if(!_index)
			return true;
		return false;
	}

	/**
	 * Returns the value of the index
	 */
	unsigned int Get() const {return _index;}

	/**
	 * Ordering operator forbidden
	 */
	bool operator<(const CATMshIndex &idx) const = delete;

	/**
	 * Equality operator forbidden
	 */
	friend bool operator==(const CATMshIndex &a, const CATMshIndex &b) = delete;

	/**
	 * Inequality operator forbidden
	 */
	friend bool operator!=(const CATMshIndex &a, const CATMshIndex &b) = delete;

private:
	unsigned int _index;
};

/**
 * Class holding a vertex index
 */
class ExportedByCATMshMesherCore CATMshVertexIndex final : public CATMshIndex{
public:
	/**
	 * Constructor for an empty vertex index
	 */
	explicit CATMshVertexIndex() noexcept : CATMshVertexIndex(0) {}

	/**
	 * Constructor for a given unsigned integer
	 * @param idx
	 *   the value of the index
	 */
	explicit CATMshVertexIndex(const unsigned int idx) noexcept : CATMshIndex(idx) {}

	/**
	 * Destructor
	 */
	~CATMshVertexIndex() = default;

	/**
	 * Ordering operator
	 */
	bool operator<(const CATMshVertexIndex &vertexIndex) const
		{return Get() < vertexIndex.Get();}

	/**
	 * Equality operator
	 */
	ExportedByCATMshMesherCore friend bool operator==(
			const CATMshVertexIndex &a, const CATMshVertexIndex &b)
		{return a.Get() == b.Get();}

	/**
	 * Inequality operator
	 */
	ExportedByCATMshMesherCore friend bool operator!=(
			const CATMshVertexIndex &a, const CATMshVertexIndex &b)
		{return a.Get() != b.Get();}
};

/**
 * Class holding an element index
 */
class ExportedByCATMshMesherCore CATMshElementIndex final : public CATMshIndex{
public:
	/**
	 * Constructor for an empty element index
	 */
	explicit CATMshElementIndex() noexcept : CATMshElementIndex(0) {}

	/**
	 * Constructor for a given unsigned integer
	 * @param idx
	 *   the value of the index
	 */
	explicit CATMshElementIndex(const unsigned int idx) noexcept : CATMshIndex(idx) {}

	/**
	 * Destructor
	 */
	~CATMshElementIndex() = default;

	/**
	 * Ordering operator
	 */
	bool operator<(const CATMshElementIndex &elementIndex) const
		{return Get() < elementIndex.Get();}

	/**
	 * Equality operator
	 */
	ExportedByCATMshMesherCore friend bool operator==(
			const CATMshElementIndex &a, const CATMshElementIndex &b)
		{return a.Get() == b.Get();}

	/**
	 * Inequality operator
	 */
	ExportedByCATMshMesherCore friend bool operator!=(
			const CATMshElementIndex &a, const CATMshElementIndex &b)
		{return a.Get() != b.Get();}
};

/**
 * Class holding a domain index
 */
class ExportedByCATMshMesherCore CATMshDomainIndex final : public CATMshIndex{
public:
	/**
	 * Constructor for an empty domain index
	 */
	explicit CATMshDomainIndex() noexcept : CATMshDomainIndex(0) {}

	/**
	 * Constructor for a given unsigned integer
	 * @param idx
	 *   the value of the index
	 */
	explicit CATMshDomainIndex(const unsigned int idx) noexcept : CATMshIndex(idx) {}

	/**
	 * Destructor
	 */
	~CATMshDomainIndex() = default;

	/**
	 * Equality operator
	 */
	ExportedByCATMshMesherCore friend bool operator==(
			const CATMshDomainIndex &a, const CATMshDomainIndex &b)
		{return a.Get() == b.Get();}

	/**
	 * Inequality operator
	 */
	ExportedByCATMshMesherCore friend bool operator!=(
			const CATMshDomainIndex &a, const CATMshDomainIndex &b)
		{return a.Get() != b.Get();}
};

/**
 * Class holding a mesh vertex
 */
class ExportedByCATMshMesherCore CATMshVertex final{
public:
	/**
	 * Constructor for an empty vertex
	 */
	explicit CATMshVertex() noexcept :
		_vertexIndex(CATMshVertexIndex(0)),
		_tag(CATMshTag(0)) {}

	/**
	 * Constructor
	 * @param vertexIndex
	 *   the corresponding vertex index
	 * @param xyz[3]
	 *   vertex coordinates
	 */
	explicit CATMshVertex(const CATMshVertexIndex &vertexIndex,
			const double (&xyz)[3]) noexcept :
			CATMshVertex(vertexIndex, xyz, CATMshTag(0)) {}

	/**
	 * Constructor
	 * @param vertexIndex
	 *   the corresponding vertex index
	 * @param xyz[3]
	 *   vertex coordinates
	 * @param tag
	 *   vertex tag
	 */
	explicit CATMshVertex(const CATMshVertexIndex &vertexIndex,
			const double (&xyz)[3], const CATMshTag &tag) noexcept :
			_vertexIndex(vertexIndex),
			_xyz{xyz[0], xyz[1], xyz[2]},
			_tag(tag) {}

	/**
	 * Destructor
	 */
	~CATMshVertex() = default;

	/**
	 * Returns whether the vertex is empty or not
	 */
	bool IsEmpty() const {return _vertexIndex.IsEmpty();}

	/**
	 * Returns the corresponding vertex index
	 */
	CATMshVertexIndex GetIndex() const {return _vertexIndex;}

	/**
	 * Returns the X coordinate as double
	 */
	double GetX() const {return _xyz[0];}

	/**
	 * Returns the Y coordinate as double
	 */
	double GetY() const {return _xyz[1];}

	/**
	 * Returns the Z coordinate as double
	 */
	double GetZ() const {return _xyz[2];}

	/**
	 * Returns the vertex tag
	 */
	CATMshTag GetTag() const {return _tag;}

private:
	CATMshVertexIndex _vertexIndex;
	double _xyz[3];
	CATMshTag _tag;
};

/**
 * Class holding a mesh element
 */
class ExportedByCATMshMesherCore CATMshElement final{
public:

	/**
	 * maximum number of possible vertices per element
	 */
	static const int maxNumberOfVertices = 27;

	/**
	 * Possible types of an element
	 */
	enum class Type{
		Unknown,
		Edge2,
		Edge3,
		Triangle3,
		Triangle6,
		Quadrangle4,
		Quadrangle9,
		Tetrahedron4,
		Tetrahedron10,
		Hexahedron8,
		Hexahedron27,
		Prism6,
		Prism18,
		Pyramid5,
		Pyramid14,
	};

	/**
	 * Possible orientations of an element
	 */
	enum class Orientation{
		Unknown,
		Forward,
		Reverse,
		Full,
	};

	/**
	 * Iterator that allows to iterate through the vertices of an element
	 */
	class ExportedByCATMshMesherCore Iterator{
	public:
		using value_type = CATMshVertexIndex;
		explicit Iterator(value_type *ptr) noexcept : _ptr(ptr) {};
		value_type operator*() const {return *_ptr;};
		Iterator& operator++() {_ptr++;return *this;};
		ExportedByCATMshMesherCore friend bool operator==(const Iterator& a, const Iterator& b)
				{return a._ptr == b._ptr;}
		ExportedByCATMshMesherCore friend bool operator!=(const Iterator& a, const Iterator& b)
				{return a._ptr != b._ptr;}
	private:
		value_type *_ptr;
	};

	/**
	 * Const Iterator that allows to iterate through the vertices of an element
	 */
	class ExportedByCATMshMesherCore ConstIterator{
	public:
		using value_type = const CATMshVertexIndex;
		explicit ConstIterator(value_type *ptr) noexcept : _ptr(ptr) {};
		value_type operator*() const {return *_ptr;};
		ConstIterator& operator++() {_ptr++;return *this;};
		ExportedByCATMshMesherCore friend bool operator==(const ConstIterator& a, const ConstIterator& b)
				{return a._ptr == b._ptr;}
		ExportedByCATMshMesherCore friend bool operator!=(const ConstIterator& a, const ConstIterator& b)
				{return a._ptr != b._ptr;}
	private:
		value_type *_ptr;
	};

	/**
	 * Constructor for an empty element
	 */
	explicit CATMshElement() noexcept  :
			_elementType(Type::Unknown),
			_elementOrientation(Orientation::Unknown),
			_elementIndex(CATMshElementIndex(0)),
			_tag(CATMshTag(0)) {}

	/**
	 * Constructor
	 * @param elementType
	 * 	the type of the element
	 * @param elementIndex
	 * 	the index of the element
	 * @param vertexIndices
	 * 	the list of vertices of the element
	 */
	explicit CATMshElement(const Type elementType,
			const CATMshElementIndex &elementIndex,
			const CATMshVertexIndex (&vertexIndices)[maxNumberOfVertices]) noexcept :
			CATMshElement(elementType, Orientation::Unknown,
			elementIndex, vertexIndices, CATMshTag(0)) {}

	/**
	 * Constructor
	 * @param elementType
	 * 	the type of the element
	 * @param elementIndex
	 * 	the index of the element
	 * @param vertexIndices
	 * 	the list of vertices of the element
	 * @param tag
	 * 	the tag of the element
	 */
	explicit CATMshElement(const Type elementType,
			const Orientation orientation,
			const CATMshElementIndex &elementIndex,
			const CATMshVertexIndex (&vertexIndices)[maxNumberOfVertices],
			const CATMshTag &tag) noexcept :
			_elementType(elementType),
			_elementOrientation(orientation),
			_elementIndex(elementIndex),
			_tag(tag){
		auto n = GetNumberOfVertices();
		for(auto i = 1; i <= n; i++)
			_vertexIndices[i-1] = vertexIndices[i-1];
	}
	/**
	 * Destructor
	 */
	~CATMshElement() = default;

	/**
	 * Returns an iterator pointing to the first vertex of the element
	 */
	Iterator begin() {return Iterator(&_vertexIndices[0]);}

	/**
	 * Returns a const iterator pointing to the first vertex of the element
	 */
	ConstIterator begin() const {return cbegin();}

	/**
	 * Returns a const iterator pointing to the first vertex of the element
	 */
	ConstIterator cbegin() const {return ConstIterator(&_vertexIndices[0]);}

	/**
	 * Returns an iterator pointing to past the last vertex of the element
	 */
	Iterator end() {return Iterator(&_vertexIndices[GetNumberOfVertices()]);}

	/**
	 * Returns an iterator pointing to past the last vertex of the element
	 */
	ConstIterator end() const {return cend();}

	/**
	 * Returns an iterator pointing to past the last vertex of the element
	 */
	ConstIterator cend() const {return ConstIterator(&_vertexIndices[GetNumberOfVertices()]);}

	/**
	 * Returns whether the element is empty or not
	 */
	bool IsEmpty() const {return _elementIndex.IsEmpty();}

	/**
	 * Returns the corresponding element index
	 */
	CATMshElementIndex GetIndex() const {return _elementIndex;}

	/**
	 * Returns the element type
	 */
	Type GetType() const {return _elementType;}

	/**
	 * Returns the element orientation
	 */
	Orientation GetOrientation() const noexcept {return _elementOrientation;}

	/**
	 * Returns the number of vertices of the element
	 */
	int GetNumberOfVertices() const{
		if(_elementType == CATMshElement::Type::Edge2){
			return 2;
		}else if (_elementType == CATMshElement::Type::Edge3){
			return 3;
		}else if (_elementType == CATMshElement::Type::Triangle3){
			return 3;
		}else if (_elementType == CATMshElement::Type::Triangle6){
			return 6;
		}else if (_elementType == CATMshElement::Type::Quadrangle4){
			return 4;
		}else if (_elementType == CATMshElement::Type::Quadrangle9){
			return 9;
		}else if (_elementType == CATMshElement::Type::Tetrahedron4){
			return 4;
		}else if (_elementType == CATMshElement::Type::Tetrahedron10){
			return 10;
		}else if (_elementType == CATMshElement::Type::Pyramid5){
			return 5;
		}else if (_elementType == CATMshElement::Type::Pyramid14){
			return 14;
		}else if (_elementType == CATMshElement::Type::Prism6){
			return 6;
		}else if (_elementType == CATMshElement::Type::Prism18){
			return 18;
		}else if (_elementType == CATMshElement::Type::Hexahedron8){
			return 8;
		}else if (_elementType == CATMshElement::Type::Hexahedron27){
			return 27;
		}else{
			return 0;
		}
	}

	/**
	 * Returns the element tag
	 */
	CATMshTag GetTag() const {return _tag;}

	/**
	 * Returns whether the element belongs to a line or not
	 */
	bool IsOnLine() const{
		if(_elementType == CATMshElement::Type::Edge2 ||
				_elementType == CATMshElement::Type::Edge3){
			return true;
		}
		return false;
	}

	/**
	 * Returns whether the element belongs to the surface or not
	 */
	bool IsOnSurface() const{
		if(_elementType == CATMshElement::Type::Triangle3 ||
				_elementType == CATMshElement::Type::Triangle6 ||
				_elementType == CATMshElement::Type::Quadrangle4 ||
				_elementType == CATMshElement::Type::Quadrangle9){
			return true;
		}
		return false;
	}

	/**
	 * Returns whether the element belongs to the volume or not
	 */
	bool IsInVolume() const{
		if(_elementType == CATMshElement::Type::Tetrahedron4 ||
				_elementType == CATMshElement::Type::Tetrahedron10 ||
				_elementType == CATMshElement::Type::Pyramid5 ||
				_elementType == CATMshElement::Type::Pyramid14 ||
				_elementType == CATMshElement::Type::Prism6 ||
				_elementType == CATMshElement::Type::Prism18 ||
				_elementType == CATMshElement::Type::Hexahedron8 ||
				_elementType == CATMshElement::Type::Hexahedron27){
			return true;
		}
		return false;
	}

	/**
	 * Returns whether the element is linear or not
	 */
	bool IsLinear() const{
		if(_elementType == CATMshElement::Type::Edge2 ||
				_elementType == CATMshElement::Type::Triangle3 ||
				_elementType == CATMshElement::Type::Quadrangle4 ||
				_elementType == CATMshElement::Type::Tetrahedron4 ||
				_elementType == CATMshElement::Type::Pyramid5 ||
				_elementType == CATMshElement::Type::Prism6 ||
				_elementType == CATMshElement::Type::Hexahedron8){
			return true;
		}
		return false;
	}

	/**
	 * Returns whether the element is quadratic or not
	 */
	bool IsQuadratic() const{
		if(_elementType == CATMshElement::Type::Edge3 ||
				_elementType == CATMshElement::Type::Triangle6 ||
				_elementType == CATMshElement::Type::Quadrangle9 ||
				_elementType == CATMshElement::Type::Tetrahedron10 ||
				_elementType == CATMshElement::Type::Pyramid14 ||
				_elementType == CATMshElement::Type::Prism18 ||
				_elementType == CATMshElement::Type::Hexahedron27){
			return true;
		}
		return false;
	}

private:
	Type _elementType;
	Orientation _elementOrientation;
	CATMshElementIndex _elementIndex;
	CATMshTag _tag;
	CATMshVertexIndex _vertexIndices[maxNumberOfVertices];
};

/**
 * Class holding a container of objects
 * It provides accessor and iterator through the container content
 */
template<class _MeshObject, class _MeshObjectIndex>
class CATMshMeshContainer : public CATMshBase{
public:

	/**
	 * Constructor
	 */
	explicit CATMshMeshContainer() noexcept {};

	/**
	 * Destructor
	 */
	virtual ~CATMshMeshContainer() = default;

	/**
	 * Iterator that allows to iterate through the container content
	 */
	class Iterator{
	public:
		/**
		 * Iterator default constructor
		 * @param parent
		 *   the parent container
		 */
		explicit Iterator(CATMshMeshContainer &parent) : Iterator(parent, _MeshObjectIndex(0)) {}

		/**
		 * Iterator constructor at starting index
		 * @param parent
		 *   the parent container
		 * @param objectIndex
		 *   starting object index
		 */
		explicit Iterator(CATMshMeshContainer &parent, _MeshObjectIndex objectIndex) :
			_objectIndex(objectIndex), _parent(parent) {}

		/**
		 * Operator to get the object
		 */
		_MeshObject operator*() const {return _parent.Get(_objectIndex);}

		/**
		 * Operator to move to the next index
		 */
		Iterator& operator++() {_objectIndex = _parent.Next(_objectIndex);return *this;}

		/**
		 * Equality means iterators are at same index
		 */
		friend bool operator==(const Iterator& a, const Iterator& b)
				{return a._objectIndex == b._objectIndex;}

		/**
		 * Inequality means iterators are not at same index
		 */
		friend bool operator!=(const Iterator& a, const Iterator& b)
				{return a._objectIndex != b._objectIndex;}
	private:
		_MeshObjectIndex _objectIndex;
		CATMshMeshContainer &_parent;
	};

	/**
	 * Returns an iterator pointing to the first object in the container
	 */
	virtual Iterator begin() = 0;

	/**
	 * Returns an iterator pointing to past the last object in the container
	 */
	virtual Iterator end() = 0;

	/*
	 * Returns the number of objects in the container
	 */
	virtual unsigned int Size(){
		auto i = 0;
		for(const auto &x : *this)
			i++;
		return i;
	}

	/**
	 * Returns the contained object corresponding to the given index
	 * @param objectIndex
	 *   the object index
	 */
	virtual _MeshObject Get(const _MeshObjectIndex &objectIndex) const = 0;

	/**
	 * Returns the next index for a given index
	 * @param objectIndex
	 *   the object index
	 */
	virtual _MeshObjectIndex Next(const _MeshObjectIndex &objectIndex) const = 0;
};

/**
 * Class holding a clonable container of objects
 */
template<class _MeshObject, class _MeshObjectIndex>
class CATMshMeshCloneableContainer : public CATMshMeshContainer<_MeshObject, _MeshObjectIndex>{
public:

	/**
	 * Default constructor of container
	 */
	explicit CATMshMeshCloneableContainer() noexcept {}

	/**
	 * Class destructor (no dynamic storage so nothing special to be done)
	 */
	virtual ~CATMshMeshCloneableContainer() = default;

	/**
	 * Clones the container
	 */
	virtual CATMshMeshCloneableContainer* Clone() const = 0;
};

/**
 * Class holding a mesh domain
 * It contains a container of elements
 */
class ExportedByCATMshMesherCore CATMshDomain final{
public:

	/**
	 * Clonable container of elements
	 */
	using container = CATMshMeshCloneableContainer<CATMshElement, CATMshElementIndex>;

	/**
	 * Constructor
	 * @param domainIndex
	 * 	the domain index
	 * @param domainTag
	 * 	the domain tag
	 * @param elementContainer
	 * 	the container of elements in the domain
	 * @return
	 *   a mesh domain
	 */
	explicit CATMshDomain(const CATMshDomainIndex &domainIndex,
			const CATMshTag &domainTag, const container& elementContainer) :
			_domainIndex(domainIndex),
			_domainTag(domainTag){
		_localContainer = elementContainer.Clone();
	}

	/**
	 * Destructor
	 */
	~CATMshDomain() noexcept {
		if(_localContainer)
			_localContainer->Release(), _localContainer = nullptr;
	}

	/**
	 * Uses the container iterator
	 */
	using Iterator = container::Iterator;

	/**
	 * Returns an iterator pointing to the first object in the container
	 */
	Iterator begin(){
		return _localContainer->begin();
	}

	/**
	 * Returns an iterator pointing to past the last object in the container
	 */
	Iterator end(){
		return _localContainer->end();
	}

	/**
	 * Returns the domain index
	 */
	CATMshDomainIndex Get() const{
		return _domainIndex;
	}

	/**
	 * Returns the domain tag
	 */
	CATMshTag GetTag() const{
		return _domainTag;
	}

private:
	CATMshDomainIndex _domainIndex;
	CATMshTag _domainTag;
	container* _localContainer;
};

/**
 * Class holding a tag system
 */
class ExportedByCATMshMesherCore CATMshTagSystem : public CATMshBase{
public:

	/**
	 * Constructor
	 */
	explicit CATMshTagSystem() noexcept {}

	/**
	 * Destructor
	 */
	virtual ~CATMshTagSystem() = default;

	/**
	 * Iterator that allows to iterate through the base tags of a tag
	 */
	class ExportedByCATMshMesherCore Iterator{
	public:
		explicit Iterator(CATMshTagSystem &parent, const CATMshTag tag, unsigned int iBaseTag) :
		_parent(parent), _tag(tag), _iBaseTag(iBaseTag) {}
		CATMshBaseTag operator*() const {return _parent.GetBaseTag(_tag, _iBaseTag);}
		Iterator& operator++() {_iBaseTag++;return *this;}
		ExportedByCATMshMesherCore friend bool operator==(const Iterator& a, const Iterator& b){
			if(a._tag == b._tag && a._iBaseTag == b._iBaseTag)
				return true;
			return false;
		}
		ExportedByCATMshMesherCore friend bool operator!=(const Iterator& a, const Iterator& b){
			return !(a==b);
		}
	private:
		unsigned int _iBaseTag;
		const CATMshTag _tag;
		CATMshTagSystem &_parent;
	};

	/**
	 * Returns an iterator pointing to the first base tag for a given tag
	 * @param tag
	 * 	the tag
	 */
	Iterator begin(const CATMshTag& tag) {return Iterator(*this, tag, 1);}

	/**
	 * Returns an iterator pointing to the last base tag for a given tag
	 * @param tag
	 * 	the tag
	 */
	Iterator end(const CATMshTag& tag) {return Iterator(*this, tag, GetBaseTagCount(tag)+1);}

	/**
	 * Returns whether the tag is composite or not
	 * @param tag
	 * 	the tag
	 */
	bool IsComposite(const CATMshTag& tag) {return GetBaseTagCount(tag) > 1;}

	/**
	 * Returns the number of base tags for a given tag
	 * @param tag
	 * 	the tag
	 */
	virtual unsigned int GetBaseTagCount(const CATMshTag& tag) = 0;

	/**
	 * Returns the i-th base tag for a given tag
	 * @param tag
	 * 	the tag
	 * @param iBaseTag
	 *  the i-th base
	 */
	virtual CATMshBaseTag GetBaseTag(const CATMshTag& tag, const unsigned int iBaseTag) = 0;
};

/**
 * Class holding a mesh
 */
class ExportedByCATMshMesherCore CATIMshMesh : public CATMshBase{
public:

	/**
	 * Container of vertices
	 */
	using verticesContainer = CATMshMeshContainer<CATMshVertex, CATMshVertexIndex>;

	/**
	 * Container of elements
	 */
	using elementsContainer = CATMshMeshContainer<CATMshElement, CATMshElementIndex>;

	/**
	 * Container of domains
	 */
	using domainsContainer = CATMshMeshContainer<CATMshDomain, CATMshDomainIndex>;

	/*
	 * Tag system
	 */
	using tagSystem = CATMshTagSystem;

	/**
	 * Constructor
	 */
	explicit CATIMshMesh() noexcept {}

	/**
	 * Destructor
	 */
	virtual ~CATIMshMesh() = default;

	/**
	 * Returns a new container of vertices
	 */
	virtual verticesContainer* NewVerticesContainer() = 0;

	/**
	 * Returns a new container of elements
	 */
	virtual elementsContainer* NewElementsContainer() = 0;

	/**
	 * Returns a new container of domains
	 */
	virtual domainsContainer* NewDomainsContainer() {return nullptr;}

	/*
	 * Returns a new tag system
	 */
	virtual CATMshTagSystem* NewTagSystem() {return nullptr;}
};

#endif
