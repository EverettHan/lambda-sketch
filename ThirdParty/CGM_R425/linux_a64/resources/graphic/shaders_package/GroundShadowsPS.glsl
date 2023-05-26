//---------------------------------------------
// Shadow
#ifdef GROUND_SHADOW

in vec4 vShadowTexCoord;
#ifdef MultiGroundShadow
float groundShadowIntensity[8] =
{
  cb_Ground_Shadow_Auto.u_ShadowsIntensity.x,
  cb_Ground_Shadow_Auto.u_ShadowsIntensity.y,
  cb_Ground_Shadow_Auto.u_ShadowsIntensity.z,
  cb_Ground_Shadow_Auto.u_ShadowsIntensity.w,
  cb_Ground_Shadow_Auto.u_ShadowsIntensity2.x,
  cb_Ground_Shadow_Auto.u_ShadowsIntensity2.y,
  cb_Ground_Shadow_Auto.u_ShadowsIntensity2.z,
  cb_Ground_Shadow_Auto.u_ShadowsIntensity2.w
};

float groundShadowBlur[8] =
{
  cb_Ground.u_ShadowsBlurDelta.x,
  cb_Ground.u_ShadowsBlurDelta.y,
  cb_Ground.u_ShadowsBlurDelta.z,
  cb_Ground.u_ShadowsBlurDelta.w,
  cb_Ground.u_ShadowsBlurDelta2.x,
  cb_Ground.u_ShadowsBlurDelta2.y,
  cb_Ground.u_ShadowsBlurDelta2.z,
  cb_Ground.u_ShadowsBlurDelta2.w
};
#endif

vec4 GetShadowMapCoord(int iLightID, int iShadowID)
{
  vec4 coord;

#if defined(MultiGroundShadow) || defined(MultiShadow)
  mat4 passageMatrix = _sbcbMultiShadow.PassageMatrix;
  mat4 projMatrix = g_shadowBuffer[GROUND_FIRST_SHADOW + iShadowID].ObjectViewToLightProjMatrix * passageMatrix;
#else
  mat4 projMatrix = _sbcbShadow.ObjectViewToLightProjMatrix;
#endif

#ifdef UsePassThroughTransition
  coord = projMatrix * _vPrivGetViewInverseTransition() * vShadowTexCoord;
#else
  coord = projMatrix * vShadowTexCoord;
#endif

  coord.xyz = coord.xyz / coord.w;

#ifdef MultiGroundShadow
  coord.xy = vFma(coord.xy, vec2(groundShadowBlur[iLightID] * 0.5), vec2(0.5));
#else
  coord.xy = vFma(coord.xy, vec2(cb_Ground.u_ShadowsBlurDelta.x*0.5), vec2(0.5));
#endif

  return coord;
}

vec4 ComputeGroundShadowColor(int iLightID, int iShadowID, int iLayer, bool iClampToBorder)
{
#ifdef MultiGroundShadow
  float intensity = groundShadowIntensity[iLightID];
#else
  float intensity = cb_Ground_Shadow_Auto.u_ShadowsIntensity.x;
#endif

#ifdef GROUND_SHADOW_ARRAY
  vec3 coord;
  coord.z = iShadowID;
#else
  vec2 coord;
#endif
  vec4 shadowCoord = GetShadowMapCoord(iLightID, iShadowID + iLayer);

  if (shadowCoord.w <= 0) return vec4(0.0, 0.0, 0.0, 0.0);

  coord.xy = shadowCoord.xy;

  // Manual ClampToBorder
  // In Multishadows, xml samplerstate doesn't work
  if (iClampToBorder == true)
  {
    // Clamp To Border
    if (coord.x<0.001 || coord.x>0.999 || coord.y<0.001 || coord.y>0.999)
      return vec4(0.0, 0.0, 0.0, 0.0);
  }
  else
  {
    // Clamp for point shadow
    if (coord.x <= -0.001 || coord.x >= 1.001 || coord.y <= -0.001 || coord.y >= 1.001)
      return vec4(0.0, 0.0, 0.0, 0.0);

    // small clamp to edge on edge
    coord.xy = vClamp(coord.xy, vec2(0.001), vec2(0.999));
  }

#ifdef TransparentShadow
  vec4 shadowCol      = vTexture(shadowMapTex2, coord);
#else
  float shadowOpacity = vTexture(shadowMapTex2, coord).x;
  vec4 shadowCol      = vec4(0, 0, 0, shadowOpacity);
#endif

  shadowCol.w *= intensity;


  return shadowCol;
}


vec4 GetGroundShadow()
{
  vec4  shadowColor;

#ifdef MultiGroundShadow

  int lightID = 0;
  int shadowID = 0;

#ifdef NonPointGroundShadows
  for (int i = 0; i < NonPointGroundShadows; i++)
  {
    shadowColor += ComputeGroundShadowColor(i, i, 0, true);
  }

  lightID   = NonPointGroundShadows;
  shadowID  = NonPointGroundShadows;
#endif

  int layer = 0;

#ifdef NB_CASCADES
  layer += NB_CASCADES - 1;
#endif

#ifdef PointGroundShadows
  for (int i = 0; i < PointGroundShadows; i++)
  {
    vec4 pointShadow = vec4(0, 0, 0, 0);
    for (int j = 0; j < 6; j++) //for 6 faces of point light
    {
      if (pointShadow.w == 0)
      {
        pointShadow = ComputeGroundShadowColor(lightID, shadowID, layer, false);
      }

      shadowID++;
    }
    shadowColor += pointShadow;
    lightID++;
  }
#endif 

#ifdef MultiGroundShadow
  shadowColor.xyz = vClamp(shadowColor.xyz, vec3(0.0), vec3(1.0));
#endif

#else 
  shadowColor = ComputeGroundShadowColor(0, 0, 0, true);
#endif

  return shadowColor;
}

vec3 ApplyGroundShadow(vec3 iColor)
{
  vec3 col        = iColor;
  vec4 shadowCol  = GetGroundShadow();
  if (shadowCol.w > 0)
  {
    shadowCol.xyz = vec3(1.0) - (vec3(1.0) - shadowCol.xyz) * shadowCol.w;
    col *= shadowCol.xyz;
  }
  return col;
}

#endif

#ifdef SO_HRTAO

float GetRTAOValue(in int i, in vec3 iWorldNormal)
{
#ifdef SO_HRTAO_AS_ARRAY
  ivec3 coords = ivec3(gl_FragCoord.xy, i);
#else
  ivec2 coords = ivec2(gl_FragCoord.xy);
#endif

#ifdef IS_MSAA
  vec3 val = vec3(vTexelFetch(RTAOOutput, coords, gl_SampleID));
#else
  vec3 val = vec3(vTexelFetch(RTAOOutput, coords, 0));
#endif

#ifdef SO_HRTAO_ENABLE_AO_IBL
  vec3 lumCoef = vec3(0.2126, 0.7152, 0.0722);
  if(i==0)
  {
    // As SO_HRTAO_ENABLE_AO_IBL is defined, the value val for i=0 is the diffuse part of HQAO+IBL.
    // This value represents the irradiance received from the IBL, taking into account occlusion from the geometry of the scene.
    // But for ground, we do not compute lighting.
    // We just want some arbitrary occlusion estimate between 0 and 1, to attenuate the color value of the ground,
    // and somehow approximate some shadowing effects.
    // So we divide occluded irradiance by unoccluded irradiance (which we get by fetching the "diffuse IBL") to get a value between 0 and 1
    // which gives us some kind of measure of occlusion, taking into account the variations of lighting in the IBL
    // (strong occlusion if the occluded portions of the IBL are the ones with most energy)
    float occludedIBLIrradianceLuminance = dot(lumCoef, val);
    vec3 unoccludedIBLIrradiance = ComputeDiffuseIBL(iWorldNormal);
    float unoccludedIBLIrradianceLuminance = dot(lumCoef, unoccludedIBLIrradiance);
    // occludedIBLIrradianceLuminance is actually clamped to [0;1] (see PostEffect_HRTAO_Finalize_Color) so we need to clamp unoccludedIBLIrradianceLuminance too
    unoccludedIBLIrradianceLuminance = clamp(unoccludedIBLIrradianceLuminance, 0, 1);
    float visibilityRatio = 0;
    if(unoccludedIBLIrradianceLuminance > 0)
      visibilityRatio = clamp(occludedIBLIrradianceLuminance / unoccludedIBLIrradianceLuminance, 0, 1);
    return visibilityRatio;
  }
  else
  {
    // else, the values are measures of occlusion from area lights.
    return dot(lumCoef, val); // I let this old code but I think val.x=val.y=val.z and we could just return val.x.
  }

#else
  return val.x;
#endif
}

float GetGroundRTAORatio(vec3 iWorldNormal)
{
  float result = 1.0;
  int n = 1;
  
  //minAttenuationFactor
  //More area lights means each indivudual light will produce less attenuation.
  //Color will be 100% black only when all shadows intersect
  float meanAttenuationFactor = 0.0;

#if defined(HASH_SLOT_COUNT) && HASH_SLOT_COUNT > 1
  n = HASH_SLOT_COUNT;
  for (int i = 0; i < HASH_SLOT_COUNT; i++)
#else
  int i = 0;
#endif
  {
#if defined(HASH_SLOT_COUNT) && HASH_SLOT_COUNT > 1 && defined(SO_HRTAO_ENABLE_SPECULAR_SHADOWS)
    if(i == 1) // specular part of HQAO+IBL is hard-coded in slot 1 (slot 0 = diffuse part)
      continue; // we do not want to take into account specular part of HQAO+IBL for the attenuation
#endif
    meanAttenuationFactor += GetRTAOValue(i, iWorldNormal);
  }
  
  result *= meanAttenuationFactor / n;

  return result;
}
#endif
