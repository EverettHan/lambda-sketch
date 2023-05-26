#ifndef CATEnvMapGeneratorDesc_H
#define CATEnvMapGeneratorDesc_H

#include "CATVisItf.h"

//System
#include "CATUnicodeString.h"

class CATPixelImage;

class ExportedByCATVisItf CATEnvMapGeneratorDesc
{
public:
  CATEnvMapGeneratorDesc();

  enum Type
  {
    eTypeUnknown,

    /*
    ** This convolution corresponds to the diffuse layer of a material.
    ** This requires a very high number of samples to compute, especially with HDR input maps,
    **  although it works well with a low resolution output.
    */
    eTypeDiffuse,

    /*
    ** This convolution corresponds to the specular layer of a standard material (dielectric/metal).
    ** Output resolution is much more important here than for the diffuse layer.
    */
    eTypeSpecular,

    /*
    ** This convolution corresponds to the specular layer of a velvet-based material.
    ** Output resolution is much more important here than for the diffuse layer.
    */
    eTypeSpecular1,

    /*
    ** This convolution corresponds to the specular layer of a cotton- or silk-based material.
    ** Output resolution is much more important here than for the diffuse layer.
    */
    eTypeSpecular2,

    /*
    ** DSPBR 2019x sheen
    */
    eTypeSpecularDSPBR19x,

    /*
    ** DSPBR 2021x sheen
    */
    eTypeSpecularDSPBR21x
  };

  enum Mode
  {
    eModeUnknown,

    /*
    ** This mode uses the real-time visualization capabilities of the GPU to reduce compute time.
    */
    eModeHardware,
    eModeSoftware, // old slow implementation
    eModeSoftware2 // new fast implementation (WIP)
  };

  /*
  ** This should point to image file representing the environment lighting.
  ** Can be any cylindrical map or cube map, LDR or HDR.
  */
  CATString m_InputFile;

  /*
  ** This is where the generated file will be saved (including file name.)
  */
  CATString m_OutputFile;

  /*
  ** false - use the m_InputFile file as input
  ** true - use the m_InputImage image as input
  */
  bool m_UseImage;

  /*
  ** false - use produce cubemap output
  ** true - produce latlong output
  */
  bool m_OutLatlong;

  /*
  ** true - write output file
  ** false - do not write the output file
  */
  bool m_WriteOutputFile;

  /*
  ** true - swap +Y and -Y faces at the import of the input image
  */
  bool m_SwapYfaces;

  /*
  ** Input image
  */
  const CATPixelImage* m_InputImage;

  /*
  ** Type of computation to perform (see enum Type).
  */
  Type m_Type;

  /*
  ** What kind of compute architecture to use (see enum Mode).
  */
  Mode m_Mode;

  /*
  ** The desired output map size (the pixel width and height of each cube map face.)
  ** A bigger output means relatively higher quality but much longer compute time.
  */
  unsigned int m_Size;

  /*
  ** The desired number of samples to take per pixel.
  ** Too few samples means there will be visible artifacts in the output (especially as HDR values go higher and higher.)
  ** Too many samples means compute time will go up without any visible gain in quality.
  */
  unsigned int m_Samples;

  /*
  ** Number of LODs.
  ** 0 - calculate from the input map
  */
  unsigned int m_nLods;

  /*
  ** Especially useful with HDR maps, this forces the input intensities to be clamped to [0 ; m_MaxIntensity].
  ** This allows to avoid artifacts when the number of samples per pixel is low.
  */
  float m_MaxIntensity;

  /*
  ** Set this to true if you want output intensities to go over 1.0.
  */
  bool m_HDR;

  /*
  ** Limit on the number of threads to use.
  ** 0 - no limit, the actual number of threads is asked from the system.
  */
  unsigned int m_MaxThreads;
};

#endif // CATEnvMapGeneratorDesc_H
