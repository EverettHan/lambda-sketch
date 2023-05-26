/* -*-c++-*-*/
// COPYRIGHT DASSAULT SYSTEMES 2014
//======================================================================
// CREATED  16 Jun 2014 BY U69
// This header contains methods is the interface between visualisation infrastructure and knowledge from RND team on PLM Material
//======================================================================
#ifndef CATVisTranslateRNDMaterialServices_h
#define CATVisTranslateRNDMaterialServices_h

#include <CATBaseUnknown.h>
#include <SGInfra.h>

/// Visualization - Material
class CATIShaderDesc;
class CATPhysicalMaterialHolder;

/**
 * Test if the given identifier corresponds to a known PLM Material with a Rendering Domain configuration.
 * @param iShaderIdentifier [in] - Identifier to test
 * @returns operation sucess status: 
 *      S_XXX : Success
 *      E_XXX : Failure
 */
ExportedBySGInfra
HRESULT IsPLMRenderingMaterial( const char * const iShaderIdentifier );

/**
 * Build a physical material based on the shader identifier and its parameters
 * @param iShaderDescription [in]  - Shader's description (i.e name & parameters)
 * @param oVizMaterial       [out] - Currently build material
 * @returns operation sucess status: 
 *      S_XXX : Success
 *      E_XXX : Failure
 */
ExportedBySGInfra
HRESULT Translate( const CATIShaderDesc& iShaderDescription, CATPhysicalMaterialHolder& oVizMaterial );



#endif
