/* -*-C++-*- */

#ifndef CATCVMAttributeDef_H
#define CATCVMAttributeDef_H

// COPYRIGHT DASSAULT SYSTEMES 2007

//===================================================================
//===================================================================
//
// CATCVMDef
//
// Definitions for attributes of Collaborative Variational Modelling (CVM) objects
//
//===================================================================


//===================================================================
// Usage notes:
//
//===================================================================

//===================================================================
// Feb. 2007    Creation                         Francois Dujardin
//===================================================================

#include "CATBoolean.h"

//------------------------------------------------------------------------------
// Attribute type definition
// WARNING: New types must be appended at the end of the list, not inserted within the list.
// This is necessary for CGMReplay compatibility.
//------------------------------------------------------------------------------
enum CATCVMAttributeType
{
  CATCVMAttrUnknownType, //0
  CATCVMAttrColorType, //1
  CATCVMAttrTextureType, //2
  CATCVMAttrImageType //3
};
#endif
