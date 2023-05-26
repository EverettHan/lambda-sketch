// Creation: January 2023 - TCT5

#ifndef CATPolyEdgeBreakerOptimizedVertexCollections
#define CATPolyEdgeBreakerOptimizedVertexCollections

#include <unordered_map>
#include <unordered_set>
#include <vector>

// Compact map/set optimization
class CATPolyEdgeBreakerOptimizedVertexSet
{
public:
  CATPolyEdgeBreakerOptimizedVertexSet(unsigned char iCollectionType, unsigned int iMaxVertexIndex) :
    m_CollectionType(iCollectionType)
  {
    if (m_CollectionType == 0)
      m_VectorSet.resize(iMaxVertexIndex + 1, 0u);
  }

  CATPolyEdgeBreakerOptimizedVertexSet() : CATPolyEdgeBreakerOptimizedVertexSet(1u, 0u) {}

  virtual ~CATPolyEdgeBreakerOptimizedVertexSet() {}

public:
  bool Insert(int iVertex)
  {
    switch (m_CollectionType)
    {
    case 0:
      if (m_VectorSet[iVertex])
        return false;
      else
      {
        m_VectorSet[iVertex] = 1;
        return true;
      }
      break;
    case 1:
      return m_HashSet.insert(iVertex).second;
      break;
    default:
      return false;
      break;
    }
  }

  void Flush()
  {
    m_HashSet = std::unordered_set<int>();
    m_VectorSet = std::vector<unsigned char>();
  }

  void Reserve(unsigned int iNbVertices)
  {
    if (m_CollectionType == 1)
      m_HashSet.reserve(iNbVertices);
  }

private:
  unsigned char m_CollectionType;

  std::unordered_set<int> m_HashSet;
  std::vector<unsigned char> m_VectorSet;
};

template <typename T>
class CATPolyEdgeBreakerOptimizedVertexMap
{
public:
  CATPolyEdgeBreakerOptimizedVertexMap(unsigned char iCollectionType, unsigned int iMaxVertexIndex) :
    m_CollectionType(iCollectionType)
  {
    if (m_CollectionType == 0)
      m_VectorMap.resize(iMaxVertexIndex + 1, 0u);
  }

  CATPolyEdgeBreakerOptimizedVertexMap() : CATPolyEdgeBreakerOptimizedVertexMap(1u, 0u) {}

  virtual ~CATPolyEdgeBreakerOptimizedVertexMap() {}

public:
  T& operator [] (const int& iVertex)
  {
    switch (m_CollectionType)
    {
    case 0:
      return m_VectorMap[iVertex];
      break;
    default: // case 1:
      return m_HashMap[iVertex];
      break;
    }
  }

  void Flush()
  {
    m_HashMap = std::unordered_map<int, T>();
    m_VectorMap = std::vector<T>();
  }

  void Reserve(unsigned int iNbVertices)
  {
    if (m_CollectionType == 1)
      m_HashMap.reserve(iNbVertices);
  }

private:
  unsigned char m_CollectionType;

  std::unordered_map<int, T> m_HashMap;
  std::vector<T> m_VectorMap;
};

#endif // !CATPolyEdgeBreakerOptimizedVertexCollections
