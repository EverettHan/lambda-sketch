//====================================================================
// Copyright Dassault Systemes Provence 2003, all rights reserved 
//====================================================================
//
// CATSobMeshCurve
//
//====================================================================
//
// Usage notes:
//
//====================================================================
// April, 2021 : RJY1 : Creation
//====================================================================
#ifndef CATSobMeshCurve_H
#define CATSobMeshCurve_H

#include "CATSobMeshBase.h"

class CATSobEdge;

class ExportedByCATSobObjects CATSobMeshCurve : public CATSobMeshBase
{
public:
	//Destructeur
	virtual ~CATSobMeshCurve() ;
protected:

  // Constructeur
  CATSobMeshCurve();

 
 

private:

  // Copy constructor and equal operator
  CATSobMeshCurve(CATSobMeshCurve&);
  CATSobMeshCurve& operator=(CATSobMeshCurve&);

};

/**
 * Subdivision mesh constructor
 *
 * @return
 * A pointer to a CATSobMesh object
 */
ExportedByCATSobObjects CATSobMeshCurve* CATSobCreateMeshCurve();

/**
 * Subdivision mesh copy constructor
 *
 * @param iMeshToCopy
 * A pointer to an existing mesh to copy
 *
 * @param iCopyCellsFlags
 * DO NOT USE, only default value must be used
 * if iCopyCellsFlags is TRUE, the method copies flags associated to each cell.
 *
 * @return
 * A pointer to a CATSobMesh object. The new mesh has the same
 * topology that the input mesh, details, sharpness and weights are
 * also copied.
 */
ExportedByCATSobObjects CATSobMeshCurve* CATSobCreateMeshCurve(CATSobMeshCurve* iMeshToCopy,
  const CATBoolean iCopyCellsFlags = FALSE);

/**
 * Builds a mesh from a set of faces, cells tags, details, weights... are reported.
 *
 * @param iInputFaces
 * The faces to copy in 'this' new mesh.
 *
 * @return
 * A pointer to the new mesh if copy is successful.
 **/
ExportedByCATSobObjects CATSobMeshCurve* CATSobCreateMeshCurve(const CATLISTP(CATSobEdge)& iInputEdges);

#endif

