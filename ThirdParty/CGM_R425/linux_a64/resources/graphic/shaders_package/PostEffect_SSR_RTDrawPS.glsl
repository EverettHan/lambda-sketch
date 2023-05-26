
void main()
{
  vec4 fallbackColor = GetColor(vTexCoord.xy);
  vec4 reflContrib =  GetEffectTexture(ReflRadianceMap, vTexCoord.xy);
  vec4 iblContrib = GetEffectTexture(IBLSpecContribMap, vTexCoord.xy);
  vec4 f0Rough = GetEffectTexture(F0RoughnessMap, vTexCoord.xy);
  vec3 f0 = f0Rough.rgb;
  vec3 normal = GetNormal(vTexCoord.xy).xyz;

  #ifdef PROJECTION_CONIC
	vec4 clipSpaceVect;
	clipSpaceVect.xy = 2.0 * vTexCoord.xy - 1.0;
	clipSpaceVect.zw = vec2(0.0, 1.0);
	vec3 viewVect = vNormalize((cb_PostEffectAuto.u_ProjectionInverseMatrix * clipSpaceVect).xyz);
  #else
   vec3 viewVect =  vec3(0.0,0.0,-1.0);
  #endif

  vec3 F = OptimizedSchlickFresnel(f0, vec3(1.0), vAbs(vDot(normal, viewVect)));

  vec3 diff = vMax(vec3(0.0), fallbackColor.rgb - iblContrib.rgb);

  vec3 reflColor = reflContrib.rgb * F;

  vec3 finalColor = vec3(0.0);

  #ifdef SO_TRANSP_REFLECTIONS
    finalColor = vMix(fallbackColor.rgb, diff + reflColor, reflContrib.a);
  #else
    finalColor = vMix(fallbackColor.rgb, diff + reflColor, iblContrib.a * reflContrib.a);
  #endif

  FRAGCOLOR = vec4(finalColor, fallbackColor.a);
}
