#ifndef CATMshMeshAssociativityPriv_h
#define CATMshMeshAssociativityPriv_h

//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2022
//=============================================================================
//
// CATMshMeshAssociativityPriv :
// Object to store mesh associativity with input geometry
//
//=============================================================================
// March 2022  Creation                          Fabien Noblet (FNT1)
//=============================================================================

#include "ExportedByCATMshMesherCore.h"

#include "CATIMshMesh.h"
#include "CATMshMeshAssociativity.h"
#include "CATIMshVertexLocationPriv.h"
#include "CATIMshElementLocationPriv.h"

class ExportedByCATMshMesherCore CATMshMeshAssociativityPriv : public CATMshMeshAssociativity
{

public:

  /* Constructeur */
  CATMshMeshAssociativityPriv(CATIMshMesh *iMsh);

  /* Destructeur */
  virtual ~CATMshMeshAssociativityPriv();
  
  /**
   * Add a location for the i-th mesh vertex
   */
  CATIMshVertexLocationPriv * CreateVertexLocation(CATMshVertexIndex &iVtx, CATMshVertexLocationType iType);

  /**
   * Add a location on vertex to the i-th mesh vertex
   */
  CATIMshElementLocationPriv * CreateElementLocation(CATMshElementIndex &iElem, CATMshElementLocationType iType);

private:

  /* Constructeur recopie */
  CATMshMeshAssociativityPriv(const CATMshMeshAssociativityPriv & Source);

  /* Operateur d'affectation */
  CATMshMeshAssociativityPriv& operator=(const CATMshMeshAssociativityPriv & Source);

  HRESULT VertexLocationMore(CATMshVl *vl);
  HRESULT ElementLocationMore(CATMshFl *fl);
  HRESULT Initialize();

  /* Constructeur */
  CATMshMeshAssociativityPriv();

};

#endif
