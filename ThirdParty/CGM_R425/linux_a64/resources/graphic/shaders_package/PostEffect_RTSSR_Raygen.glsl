
// Ray payload, which will be set to false if no geometry is hit
layout(location = 0) rayPayloadEXT Payload_t g_Payload;

vec3 getPosition(ivec2 pixel
#ifdef IS_MSAA
, int iSample
#endif
)
{
#ifdef IS_MSAA
  return uintBitsToFloat(imageLoad(positionNormals, pixel, iSample).xyz);
#else
  return uintBitsToFloat(imageLoad(positionNormals, pixel).xyz);
#endif
}

vec3 getNormal(ivec2 pixel
#ifdef IS_MSAA
, int iSample
#endif
)
{
  //uint compressedNormal = floatBitsToUint(imageLoad(positionNormals, pixel).y);
#ifdef IS_MSAA
  uint compressedNormal = imageLoad(positionNormals, pixel, iSample).w;
#else
  uint compressedNormal = imageLoad(positionNormals, pixel).w;
#endif

  if (compressedNormal == 0)
    return vec3(0);

  return decompress_unit_vec(compressedNormal);
} 

// the value returned by the following method is meant to avoid self intersection artifacts
// in the case of world matrix with a big scaling factor
float getRTLocalOffsetInWorldSpace(ivec2 pixel
#ifdef IS_MSAA
, int iSample
#endif
)
{
#ifdef SO_USE_LEGACY_RAY_ORIGIN_OFFSET
  return 0.0;
#else

float localOffset = 0.0;
#ifdef IS_MSAA
  #ifndef SO_TRANSP_REFLECTIONS
    localOffset =  imageLoad(gBufferAdditionalData, pixel, iSample).x;
  #else
    localOffset =  imageLoad(gBufferAdditionalDataTransp, pixel, iSample).x;
  #endif // SO_TRANSP_REFLECTIONS
#else
  #ifndef SO_TRANSP_REFLECTIONS
    localOffset =  imageLoad(gBufferAdditionalData, pixel).x;
  #else
    localOffset =  imageLoad(gBufferAdditionalDataTransp, pixel).x;
  #endif //SO_TRANSP_REFLECTIONS
#endif //IS_MSAA

return localOffset;

#endif // ifdef SO_USE_LEGACY_RAY_ORIGIN_OFFSET
}

int traceRays(in vec3 origin, in vec3 direction)
{
  g_Payload.isHit = false;
  uint mask = 0xFF;
  
  float rayDist = cb_PostEffect_RTReflections.rayDistance;
  traceRayEXT(topLevelAS, gl_RayFlagsOpaqueEXT, mask, 0, 1, 0, origin, 0.0, direction, rayDist, 0);
  
  if(g_Payload.isHit)
    return 1;

  return 0;
}

#define vpX (_sbCbCamera.EyeWorldPos.x)
#define vpY (_sbCbCamera.EyeWorldPos.y)
#define vpZ (_sbCbCamera.EyeWorldPos.z)

float getFeatureSizeInWorldUnits(float distance, uint featureSizeInPixels, float minFeatureSize, uint lodOffset)
{
  float featureSize = tan(cb_PostEffect_HRTAO_Auto.pixelAngle*featureSizeInPixels) * distance;
  float log2Size = log2(featureSize/minFeatureSize)+lodOffset;
  float featureSizeRound = exp2(floor(log2Size))*minFeatureSize;

  return featureSizeRound;
}

void raygen()
{
  uvec3 launchSize = vGetLaunchSize();
  uvec3 launchID = vGetLaunchID();

  vec3 pos, normal;

  float localOffsetInWorldSpace = 0.0;

  #ifdef IS_MSAA
    pos = getPosition( ivec2(launchID.xy), int(launchID.z));
    normal = getNormal(ivec2(launchID.xy), int(launchID.z));
    localOffsetInWorldSpace = getRTLocalOffsetInWorldSpace(ivec2(launchID.xy), int(launchID.z));
  #else
    pos = getPosition( ivec2(launchID.xy));
    normal = getNormal(ivec2(launchID.xy));
    localOffsetInWorldSpace = getRTLocalOffsetInWorldSpace(ivec2(launchID.xy));
  #endif

  if(all(equal(normal, vec3(0.0, 0.0, 0.0))))
  {
    #ifdef IS_MSAA
      imageStore(reflectionsOutput, ivec2(launchID.xy), int(launchID.z), vec4(0.0));
    #else
      imageStore(reflectionsOutput, ivec2(launchID.xy), vec4(0.0));
    #endif

    return;
  }
  
  // Move origin slightly away from the surface to avoid self-occlusion
  vec3 origin = offset_ray_origin(pos, normal); 

  #ifndef SO_USE_LEGACY_RAY_ORIGIN_OFFSET
  {
    float worldOffset = distance(pos, origin);
    if(worldOffset < localOffsetInWorldSpace) // we want the max of the two offsets (one computed in world space and one computed previously in local space)
      origin = pos + localOffsetInWorldSpace * normal;
  }
  #endif // ifndef SO_USE_LEGACY_RAY_ORIGIN_OFFSET

  const vec2 pixelCenter = vec2(vGetLaunchID().xy) + vec2(0.5);
  const vec2 inUV = pixelCenter/vec2(vGetLaunchSize().xy);
  vec4 ssr_reflDir = texture(reflVectData, inUV);

  uint hit = 0;

  #ifdef SO_TRANSP_REFLECTIONS
    vec3 eye = vec3(vpX, vpY, vpZ);
    vec3 viewDir = normalize(origin - eye);
    ssr_reflDir.xyz = reflect(viewDir, normal);
  #endif

  hit = traceRays(origin, ssr_reflDir.xyz);

  vec4 value;

  if(hit == 1)
  {
    vec3 finalColor = g_Payload.color;
    vec3 LUMINANCE = vec3(0.3, 0.6, 0.1);
    float lumi = dot(LUMINANCE, finalColor);
    finalColor.rgb /= 1 + lumi; //to reduce fireflies in reflection
    value = vec4(finalColor, 1.0);
  }
  else
    value = vec4(0.0);
     
  #ifdef IS_MSAA
    imageStore(reflectionsOutput, ivec2(launchID.xy), int(launchID.z), value);
  #else
    imageStore(reflectionsOutput, ivec2(launchID.xy), value);
  #endif
}

void main()
{
  raygen();
}
