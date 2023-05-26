#ifndef CATVisuTextureType_H
#define CATVisuTextureType_H

enum CATVisuTextureType
{
  CATVisUndefinedTexture=0,
  CATVisEyeMap,
  CATVisSpriteMap,
  CATVisRTMap,        // map pour le raytracing en full mode
  CATVisZMap,  
  CATVisNormalMap,
  CATVisShadowMap,
  CATVisAmbientOcclusionMap,
  CATVisHighlightMap,
  CATVisPreHighlightMap,
  CATVisBlendShadowMap,
  CATVisPlanarShadowMap,
  CATVisSpecularMap,
  CATVisGlowMap,
  CATVisEnvGlowMap,
  CATVisMirroringMap,
  CATVisAlphaColorMap,  //Weigthed Average algo : accumulate color
  CATVisAlphaDepthMap,  //Weigthed Average algo : accumulate the number of layer : n in NVIDIA paper
  CATVisAlphaZMap,      //Weigthed Average algo : Map that will contain the Z-buffer for the FBO
  CATVisAlphaZMapScene  //Weighted Average algo : Map that will contain the Z of the Scene (Volume & skin)
};

#endif // CATVisuTextureType_H
