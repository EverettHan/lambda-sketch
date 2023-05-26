vec3 ComputeNormal()
{
  return vWorldNormal.xyz;
}

vec4 ComputeLighting(vec3 iWorldNormal)
{   
  vec4 col = cb_Ground.u_GroundColor;

#ifdef GROUND_MIRRORING
  vec4 mirrorCol = GetGroundMirrorColor(iWorldNormal);
  col.xyz = vMix(col.xyz, mirrorCol.xyz, cb_Ground.u_MirrorCoef);
#else
  vec4 mirrorCol = vec4(0.0);
#endif
    
#if defined(GROUND_SHADOW) 
  col.xyz = ApplyGroundShadow(col.xyz);
#endif

#if defined(SO_HRTAO)
  col.xyz *= GetGroundRTAORatio(iWorldNormal);
#endif

#ifdef OutputIBLReflMap
  FRAGREFLECT.xyz = cb_Ground.u_MirrorCoef * mirrorCol.xyz;
  FRAGREFLECT.a = col.a;
#endif
    
  return col;
}
