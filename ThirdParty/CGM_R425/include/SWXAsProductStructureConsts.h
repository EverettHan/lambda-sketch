#ifndef SWXAsProductStructureConsts_H
#define SWXAsProductStructureConsts_H

#include "CATUnicodeString.h"

//   template, BOM const definition
enum SWXBOMType_e {NotBOM = -1, TopLevel = 0, PartsOnly = 1, IndentedBOM = 2, NotSpecified = 3};

const CATUnicodeString  SWX_COMPONENT("COMPONENT");
const CATUnicodeString  SWX_NAME("PLM_ExternalID");
const CATUnicodeString	SWX_SEPARATOR("</>");
//const CATUnicodeString	SWX_LOCAL_DATA("SWX_LOCAL_DATA"); We don't allow local data in a BOM, everything needs to be store in an product structure or EBOM.
const CATUnicodeString  SWX_PLM_PROP("PLMProperty");
const CATUnicodeString  SWX_CUSTOM_PROP("CustomProperty");
const CATUnicodeString  SWX_CUSTOM_TYPE("Type");
const CATUnicodeString  SWX_CUSTOM_NAME("Name");
const CATUnicodeString  SWX_MASS_PROP("MassProperty");
const CATUnicodeString  SWX_MASS_MATERIAL("Material");
const CATUnicodeString  SWX_MASS_DENSITY("Density");
const CATUnicodeString  SWX_MASS("Mass");
const CATUnicodeString  SWX_TYPE_PRODUCT_REF("VPMReference");
const CATUnicodeString  SWX_TYPE_MATERIAL("CATMatReference");
const CATUnicodeString  SWX_V_DESCRIPTION("V_description");
const CATUnicodeString  SWX_TYPE_SKETCH_MECHANISM("SWXSketchMechanismRepresentation");
#endif 
