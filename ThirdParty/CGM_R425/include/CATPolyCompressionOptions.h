#ifndef CATPolyCompressionOptions_h
#define CATPolyCompressionOptions_h

#include "CATDataType.h"

/* Polyhedral compression options. Create a CATULONG32 and combine the flags below. */

class CATPolyCompressionOptions
{
public:
  /* Compression methods.
  * 
  * eNoCompression: do not attempt to compress (default value).
  * eDeflate: use DEFLATE (zip) compression algorithm.
  * eEdgeBreaker: *Attempt* to compress using the edge breaker algorithm. If the input data is not supported by
  *  edge breaker, the streamer will fall back on either eNoCompression or eDeflate according to user preferences.
  * 
  * Note: Edge breaker and DEFLATE can be combined (eDeflate | eEdgeBreaker). In this case, everything that is not
  *  supported by edge breaker (unsupported layers, incompatible meshes) will be handled by DEFLATE.
  */
  struct Methods
  {
    static const CATULONG32 eNoCompression = 0x0000;
    static const CATULONG32 eDeflate = 0x0001;
    static const CATULONG32 eEdgeBreaker = 0x0002;
  };

  /*
  * Edge breaker specific options. They will be taken into account only if edge breaker has been turned on.
  * The persist/noPersist property overrides the index persistence option (eFacetIndices, eVertexIndices) in 
  * the layerFilter.
  * if no edge breaker specific option is provided, a lossless compression will be attempted, and the index 
  * persistence option encoded in the layerFilter will be used.
  * 
  * eLosslessPersist: In this mode, positions and normals are compressed with no information loss. Vertex and
  *  triangle indices are preserved as well. This compression mode is the least effective, since persistence
  *  of indices has a significant memory cost.
  * eLosslessNoPersist: In this mode, positions and normals are compressed with no information loss, but vertex
  *  and triangle indices will not be preserved. This is the recommended mode for lossless compression which
  *  fully takes advantage of the edge breaker algorithm.
  * 
  * Note: These flags can not be combined, these options are mutually exclusive.
  * Note: At the moment, the edge breaker module only supports the compression of the position and normal layers.
  *  Other layer (e.g. textures) will be streamed with either no compression (eEdgeBreaker only) or with DEFLATE
  *  compression (eEdgeBreaker | eDeflate).
  */
  struct EdgeBreakerOptions
  {
    static const CATULONG32 eLosslessPersist = 0x0010;
    static const CATULONG32 eLosslessNoPersist = 0x0020;
  };

public:
  static void UpdateLayerFilter(CATULONG32 iCompressionOptions, unsigned int& ioLayerFilter)
  {
    if (CATPolyCompressionOptions::RequiresNonPersistence(iCompressionOptions))
    {
      ioLayerFilter &= ~CATPolyStreamOptions::eVertexIndices;
      ioLayerFilter &= ~CATPolyStreamOptions::eFacetIndices;
    }
    else if (CATPolyCompressionOptions::RequiresPersistence(iCompressionOptions))
    {
      ioLayerFilter |= CATPolyStreamOptions::eVertexIndices;
      ioLayerFilter |= CATPolyStreamOptions::eFacetIndices;
    }
  }

private:
  static bool RequiresPersistence(CATULONG32 iCompressionOptions)
  {
    return (iCompressionOptions & Methods::eEdgeBreaker) && ((iCompressionOptions & 0x00F0) == EdgeBreakerOptions::eLosslessPersist);
  }

  static bool RequiresNonPersistence(CATULONG32 iCompressionOptions)
  {
    return (iCompressionOptions & Methods::eEdgeBreaker) && ((iCompressionOptions & 0x00F0)) && ((iCompressionOptions & 0x00F0) != EdgeBreakerOptions::eLosslessPersist);
  }
};

#endif // CATPolyCompressionOptions
