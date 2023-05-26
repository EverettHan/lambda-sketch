#ifndef CATExtIMshElementLocationPriv_h
#define CATExtIMshElementLocationPriv_h

//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2022
//=============================================================================
//
// CATExtIMshElementLocationPriv :
// Parametric coordinates of the vertices of a mesh element
//
//=============================================================================
// April 2022  Creation                          Fabien Noblet (FNT1)
//=============================================================================

#include "CATIMshMesh.h"
#include "CATIMshElementLocationPriv.h"


class ExportedByCATMshMesherCore CATExtIMshElementLocationPriv : public CATIMshElementLocationPriv
{

public:

  /* Constructeur */
  CATExtIMshElementLocationPriv();

  /* Destructeur */
  virtual ~CATExtIMshElementLocationPriv();

  virtual HRESULT SetSupport(int iGeomID);

  virtual HRESULT GetSupport(int & oGeomID);

  virtual void Available();

  virtual int IsAvailable();

  virtual HRESULT SetVerticesParametric2DCoordinates(double *iUVs, int iSize);

  virtual HRESULT GetVerticesParametric2DCoordinates(double *ioUVs, int & oSize);

};

#endif
