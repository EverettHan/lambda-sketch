/* -*-C++-*- */

#ifndef CATCVMDef_H
#define CATCVMDef_H

// COPYRIGHT DASSAULT SYSTEMES 2006

//===================================================================
//===================================================================
//
// CATCVMDef
//
// Definitions for Collaborative Variational Modelling (CVM) objects
//
//===================================================================


//===================================================================
// Usage notes:
//
//===================================================================

//===================================================================
// Feb. 2006    Creation                         Alex State
//===================================================================

#include "CATBoolean.h"

//------------------------------------------------------------------------------
// Object type definition
// WARNING: New types must be appended at the end of the list, not inserted within the list.
// This is necessary for CGMReplay compatibility.
//------------------------------------------------------------------------------
enum CATCVMObjectType
{
   CATCVMSystemType
  ,CATCVMComponentType
  ,CATCVMHandleType
  ,CATCVMPortType
  ,CATCVMAtomType
  ,CATCVMGeometryType
  ,CATCVMVariableType
  ,CATCVMDoubleType
  ,CATCVMRelationType
  ,CATCVMConstraintType
  ,CATCVMGeoConstraintType
  ,CATCVMDistanceType
  ,CATCVMAngleType
  ,CATCVMCoincidenceType
  ,CATCVMFixType
  ,CATCVMSymmetryType
  ,CATCVMEquationType
  ,CATCVMWBEquationType
  ,CATCVMBBEquationType
  ,CATCVMBodyType
  ,CATCVMContainerType
  ,CATCVMGeoContainerType
  ,CATCVMRadiusType
  ,CATCVMGeoDimConstraintType
  ,CATCVMApplicationDataType
  ,CATCVMDEBUGApplicationDataType
  ,CATCVMGeoRepType
  ,CATCVMInstanceType
  ,CATCVMReferenceType
  ,CATCVMOccurrenceType
  ,CATCVMGeoMeshType
  ,CATCVMInstancePathType
  ,CATCVMPSContainerType
  ,CATCVMGeoClayType
  ,CATCVMGeoMeshNatureType
  ,CATCVMGeoSmoothyType
};
#endif
