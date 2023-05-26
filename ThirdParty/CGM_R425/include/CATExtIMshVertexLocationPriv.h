#ifndef CATExtIMshVertexLocationPriv_h
#define CATExtIMshVertexLocationPriv_h

//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2022
//=============================================================================
//
// CATIMshVertexLocationPriv :
// Parametric coordinates of a Mesh vertex
//
//=============================================================================
// February 2022  Creation                          Fabien Noblet (FNT1)
//=============================================================================

#include "CATIMshMesh.h"
#include "CATIMshVertexLocationPriv.h"

/*
* Adapter of the interface CATIMshSpec, for mesh specification
*/
class ExportedByCATMshMesherCore CATExtIMshVertexLocationPriv : public CATIMshVertexLocationPriv
{

public:

  /* Constructeur */
  CATExtIMshVertexLocationPriv();

  /* Destructeur */
  virtual ~CATExtIMshVertexLocationPriv();

  virtual HRESULT SetSupport(int iGeomID) ;

  virtual HRESULT GetSupport(int & oGeomID);

  virtual HRESULT SetParametric2DCoordinates(double iUV[2]);

  virtual HRESULT GetParametric2DCoordinates(double oUV[2]);

  virtual HRESULT SetParametric1DCoordinates(double iT);

  virtual HRESULT GetParametric1DCoordinates(double & oT);

  virtual void Exact();

  virtual int IsExact();

  virtual HRESULT SetSourceElement(CATMshElementIndex &iElem);

  virtual HRESULT GetSourceElement(CATMshElementIndex & oElem);

  virtual HRESULT SetSourceEdge(CATMshVertexIndex &iV0, CATMshVertexIndex &iV1);

  virtual HRESULT GetSourceEdge(CATMshVertexIndex & oV0, CATMshVertexIndex & oV1);

private:

  int _GeomID;

};

#endif
