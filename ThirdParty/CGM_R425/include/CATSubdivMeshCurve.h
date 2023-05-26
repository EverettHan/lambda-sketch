/*-*-c++-*-*/
//=======================================================================
//  Interface representing a CATSubdivMeshCurve for subdivision
//=======================================================================
// Jan,   2023 : MPS : Creation
//=======================================================================
#include "CATIACGMLevel.h"
#include "CATIAV5Level.h"

#ifdef CATIACGMR426CAA
#ifndef CATSubdivMeshCurve_H
#define CATSubdivMeshCurve_H

#include "CATMathDef.h"
#include "ExportedByCATGMGeometricInterfaces.h"
#include "IUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATGMGeometricInterfaces IID IID_CATSubdivMeshCurve ;
#else
extern "C" const IID IID_CATSubdivMeshCurve ;
#endif

//#include "CATGeometry.h"
#include "CATSubdivMeshBase.h"


class CATSobMeshCurve;
class CATSobVertex;
class CATBody;



class ExportedByCATGMGeometricInterfaces CATSubdivMeshCurve: public CATSubdivMeshBase
{
CATDeclareInterface;

public:

/**
 * Retrieves the mesh object aggregated in 'this'
 * @return
 * The mesh object
 */
  virtual CATSobMeshCurve* GetMeshCurve() = 0;

/**
 * Specifies that the mathematical mesh must not be deleted
 * when 'this' will be deleted. The deletion is the external.
 */

  virtual void DontEraseMeshCurve() = 0;

/**
 * Erases all the edges  under each CATSobEdge 
 * @return
 * 0 if successful
 */
  virtual int RemoveGeometry() = 0;



  //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<//
  //                                                                                //
  //               N O N - C A A             M E T H O D S    DO NOT USED EXTERNALLY//
  //                                                                                //
  //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<//

  //-------------------------------------------------------------------------
	// Gestion des attributs, cf: CATSubdivisionTopOperators\ProtectedInterfaces\CATStoSubdivMeshProperties.h
	//-------------------------------------------------------------------------
  
  //********** DO NOT USE - Type de PCCM
  virtual void SetPCCMCommonType() = 0;
  virtual CATBoolean IsPCCMCommonType() const = 0;

  //********** DO NOT USE - Type de raccords pour le PCCM
  virtual void SetPCCMContinuityType(const CATBoolean iG0, const CATBoolean iG1, const CATBoolean iG2) = 0;
  virtual void GetPCCMContinuityType(CATBoolean& oG0, CATBoolean& oG1, CATBoolean& oG2) const = 0;


  //********** DO NOT USE - Gestion lien CATSubdivMesh -> CATBody
  virtual void SetLinkedBodyTag(const CATULONG32 iLinkedBodyTag) = 0;
  virtual CATULONG32 GetLinkedBodyTag() const = 0;


  //Niveau de subdivision utilisé pour l'appel au PCCM
  virtual void SetSubdivisionLevelForPCCM(const int iLevel) = 0;
  virtual int GetSubdivisionLevelForPCCM() const = 0;
 
  virtual CATULONG32 GetObjectVersion() const = 0;


};
CATDeclareHandler(CATSubdivMeshCurve,CATSubdivMeshBase);

#endif
#endif


