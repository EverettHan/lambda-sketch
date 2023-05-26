#ifndef CATMshMeshMG2D_h
#define CATMshMeshMG2D_h

//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2021-2022
//=============================================================================
//
// CATMshMeshMG2D :
// Interface of the minimal mesh from a surface mesh_t
//
//=============================================================================
// February 2022 Modification                       Fabien Noblet (FNT1)
//=============================================================================

#include "CATMshCSMCommonExport.h"

#include "CATIMshMesh.h"
#include <map>

extern "C" {
#include <meshgems/meshgems.h>
}

#define ELEMENT_MAX_VERTEX 8

class CATMshMeshMG2D;

class CATMshMeshMG2DDomain :
  public CATMshMeshCloneableContainer<CATMshElement, CATMshElementIndex> {
public:
  explicit CATMshMeshMG2DDomain(CATMshMeshMG2D &mesh,
    const CATMshDomainIndex &domainIndex) noexcept;
  virtual ~CATMshMeshMG2DDomain() = default;

  virtual Iterator begin() override;
  virtual Iterator end() override;
  virtual CATMshElement Get(const CATMshElementIndex &elementIndex) const override;
  virtual CATMshElementIndex Next(const CATMshElementIndex &elementIndex) const override;
  virtual CATMshMeshMG2DDomain* Clone() const override;

  CATMshTag GetTag() const;
private:
  CATMshMeshMG2D &_mesh;
  CATMshDomainIndex _index;
  CATMshTag _tag;
  CATMshElement _seed;
};


class CATMshMeshMG2DContainerVertices :
  public CATMshMeshContainer<CATMshVertex, CATMshVertexIndex> {
public:
  explicit CATMshMeshMG2DContainerVertices(CATMshMeshMG2D &mesh) noexcept;
  virtual ~CATMshMeshMG2DContainerVertices();

  virtual Iterator begin() override;
  virtual Iterator end() override;
  virtual CATMshVertex Get(const CATMshVertexIndex &vertexIndex) const override;
  virtual CATMshVertexIndex Next(const CATMshVertexIndex &vertexIndex) const override;
private:
  CATMshMeshMG2D &_mesh;
  int *_BasicTags;
};

class CATMshMeshMG2DContainerElements :
  public CATMshMeshContainer<CATMshElement, CATMshElementIndex> {
public:
  explicit CATMshMeshMG2DContainerElements(CATMshMeshMG2D &mesh) noexcept;
  virtual ~CATMshMeshMG2DContainerElements();

  virtual Iterator begin() override;
  virtual Iterator end() override;
  virtual CATMshElement Get(const CATMshElementIndex &elementIndex) const override;
  virtual CATMshElementIndex Next(const CATMshElementIndex &elementIndex) const override;
private:
  CATMshMeshMG2D &_mesh;
  int *_BasicTags;
};

class CATMshMeshMG2DContainerDomains :
  public CATMshMeshContainer<CATMshDomain, CATMshDomainIndex> {
public:
  explicit CATMshMeshMG2DContainerDomains(CATMshMeshMG2D &mesh) noexcept;
  virtual ~CATMshMeshMG2DContainerDomains() = default;

  virtual Iterator begin() override;
  virtual Iterator end() override;
  virtual CATMshDomain Get(const CATMshDomainIndex &domainIndex) const override;
  virtual CATMshDomainIndex Next(const CATMshDomainIndex &domainIndex) const override;
private:
  CATMshMeshMG2D &_mesh;
};

class CATMshMeshMG2DTagSystem : public CATMshTagSystem {
public:
  explicit CATMshMeshMG2DTagSystem(CATMshMeshMG2D &mesh) noexcept;
  virtual ~CATMshMeshMG2DTagSystem();

  virtual unsigned int GetBaseTagCount(const CATMshTag& tag) override;
  virtual CATMshBaseTag GetBaseTag(const CATMshTag& tag, const unsigned int iBaseTag) override;

private:
  CATMshMeshMG2D &_mesh;
  integer *_baseTags;
  integer _nMax;
};

class ExportedByCATMshCSMCommon CATMshMeshMG2D : public CATIMshMesh {
public:
  explicit CATMshMeshMG2D(mesh_t *legacyMesh);
  virtual ~CATMshMeshMG2D();

  virtual verticesContainer* NewVerticesContainer() override;
  virtual elementsContainer* NewElementsContainer() override;
  virtual domainsContainer* NewDomainsContainer() override;
  virtual CATMshTagSystem* NewTagSystem() override;

  friend class CATMshMeshMG2DDomain;
  friend class CATMshMeshMG2DContainerVertices;
  friend class CATMshMeshMG2DContainerElements;
  friend class CATMshMeshMG2DContainerDomains;
  friend class CATMshMeshMG2DTagSystem;

  HRESULT GetConversionTables(CATMshElementIndex **edgTab, CATMshElementIndex **triTab, CATMshElementIndex **quaTab);

private:

  HRESULT BuildConversionTable();

  mesh_t *_iMsht;

  integer _nVertex;
  integer _nEdge;
  integer _nTri;
  integer _nQuad;
  integer _nTotal;
  integer _nDomain;

  int _Converted;
  CATMshElementIndex *_edgTab;
  CATMshElementIndex *_triTab;
  CATMshElementIndex *_quaTab;

};

#endif

