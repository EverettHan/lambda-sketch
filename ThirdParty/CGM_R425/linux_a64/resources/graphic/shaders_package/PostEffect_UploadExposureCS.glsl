layout (local_size_x = 1, local_size_y = 1) in;

void main()
{
  float exposure = cb_Exposure.u_Exposure;
  vImageStore(i_ExposureMap, ivec2(0, 0), vec4(exposure));
}
