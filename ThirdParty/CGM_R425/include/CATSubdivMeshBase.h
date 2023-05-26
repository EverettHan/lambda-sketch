/*-*-c++-*-*/
//=======================================================================
//  Interface representing a CATSubdivMeshBase for CATSubdivMesh  and CATSubdivMeshCurve 
//=======================================================================
// Janv,   2023 : MPS : Creation
//=======================================================================
#include "CATIACGMLevel.h"
#include "CATIAV5Level.h"

#ifdef CATIACGMR426CAA
#ifndef CATSubdivMeshBase_H
#define CATSubdivMeshBase_H

#include "CATMathDef.h"
#include "ExportedByCATGMGeometricInterfaces.h"
#include "IUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATGMGeometricInterfaces IID IID_CATSubdivMeshBase ;
#else
extern "C" const IID IID_CATSubdivMeshBase ;
#endif

#include "CATGeometry.h"


class ExportedByCATGMGeometricInterfaces CATSubdivMeshBase: public CATGeometry
{
CATDeclareInterface;

public:

};
CATDeclareHandler(CATSubdivMeshBase,CATGeometry);

#endif
#endif

