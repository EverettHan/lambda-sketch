// COPYRIGHT DASSAULT SYSTEMES 2003
#ifndef CATSHADOWENUM_H
#define CATSHADOWENUM_H
/** @CAA2Required */
/**********************************************************************/
/* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS */
/* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME */
/**********************************************************************/

enum CATVisShadowMode { CATVisSMNormal, CATVisSMDrawShadowMap, CATVisSMDrawProjectedShadowMap, CATVisSMDrawProjectedZRange, CATVisSMDualTexture, CATVisSMHardware};
enum CATVisShadowVersion {CATVisShadowDrawShadowMap, CATVisShadowDrawProjectedShadowMap, CATVisShadowDrawProjectedZRange, CATVisShadowDualTexture, CATVisShadowHardware, CATVisShadowFx};
enum CATVisLightViewFittingMode { CATVisLightViewBS, CATVisLightViewBB, CATVisLightViewEyeViewpointBased};

#endif
