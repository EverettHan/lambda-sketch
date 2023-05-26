#ifndef VISVIDEOSHOOTER_H_
#define VISVIDEOSHOOTER_H_

#include <vector>

#include "VisSphericalVideo.h"

#include "CATUnicodeString.h"

class VisVideoShooterImpl;
class CATSupport;
class CATEvent;
class CATPixelImage;
class CAT2DViewpoint;

/** This class is used to shoot video. This can be 360 or normal video. */
class ExportedByVisSphericalVideo VisVideoShooter
{
public :

  /*
    Images to be manually composited over the rendering result. Used in Parameters::manualCompositingLayers.
    The offset members are the offset on the pixel grid of the destination image
    They must be properly dimensioned, according the the dimensions of the support (width and height in Parameters::Video).
    These layers will be composited *after* the RasterizerCompositingData layers.
  */
  struct ExportedByVisSphericalVideo ManualCompositingLayer {
    ManualCompositingLayer(CATPixelImage* image, unsigned int offsetX = 0, unsigned int offsetY = 0);
    CATPixelImage* image;
    unsigned int offsetX;
    unsigned int offsetY;
  };

  struct ExportedByVisSphericalVideo Parameters
  {
    Parameters();

    /** @struct This struct contains parameters for Video360 only */
    struct Video360
    {
      enum EEncodingProfile 
      {
        f4096x2160_30     = 1 << 0,
        f4096x2160_60     = 1 << 1,
        f3840x2160_30     = 1 << 2,
        f3840x2160_60     = 1 << 3,
        f1920x1080_30     = 1 << 4,
        f1920x1080_60     = 1 << 5,
        fGearVR30         = 1 << 6,
        fGearVR60         = 1 << 7,
        fIOS              = 1 << 8
      };

      unsigned int encodingProfileMask; ///< This is a bitfield : ie f4096x2160_30 | fGearVR30
    }video360;

    /** @struct This struct contains parameters for classical Video only */
    struct Video
    {
      unsigned int width;  ///< Shoot resolution
      unsigned int height;

      enum EEncodingProfile
      {
        fLossless_60    = 1 << 0,
        fLossless_30    = 1 << 1,
        fHigh_60        = 1 << 2,
        fHigh_30        = 1 << 3,
        fMedium_60      = 1 << 4,
        fMedium_30      = 1 << 5,
        fLow_60         = 1 << 6,
        fLow_30         = 1 << 7,
        fTiffPictures   = 1 << 8
      };

      unsigned int encodingProfileMask;

      // Flag to optimize video generation performance
      // if this flag is set to true, only one CATSupport is created and used for all frames
      // It means, ambiance, viewmode,  ... won't be updated between frames. 
      // Only scenegraph and camera modification are taken into account.
      // Ambiance, viewmode, ... are freezed at the first frame and keep for all the video in this mode
      bool keepSameSupport;

      // number of draw to converge one frame
      // this functionality is only available when keepSameSupport is set to true
      unsigned int convergenceNumber; 
    }video;

    CATSupport * support; ///< This support will be used for the shoot. Set correct viewpoint, environment...

    CATUnicodeString videoOutputPath;   ///< The path of the video. Must finish with a /
    CATUnicodeString videoOutputName;   ///< The video name
    unsigned int     firstFrame;        ///< The first frame to shoot (only usefull to initialize framecounter

    enum EFPS
    {
      e30,
      e60,
      e90,
      e120
    } fps; ///< The FPS you will call the ShootFrame method.

    bool mode360; ///< Set to true if you want 360 video.
    bool useX265; ///< Set to true to use x265 codec.  /!\ /!\ /!\ Warning ! do not use it for now. /!\ /!\ /!\		

    float forcedFPSvalue = 0;  ///< Arbitrary FPS value that will overwrite the value determined by encoding profile (xxx_.30, xxx_60). Set to less than 1 to use FPS of encoding.

    /*
      Data for compositing over the rendering result using NRE.
      2D Viewpoints will be composited by NRE over the result image. They will be applied in order of appearance in the vector.
      If ray tracing is used, they will be composited *before* the ManualCompositingData layers.
    */
    std::vector<CAT2DViewpoint*> rasterizerCompositingLayers;

    /*
      Data for manually compositing over the rendering result.
      Some elements cannot be composited by NRE and thus will be composited manually over the rendering result.
      Layers will be applied in order of appearance in the vector below.
    */
    std::vector<ManualCompositingLayer> manualCompositingLayers;

    struct RayTracingSettings  ///< Ray tracing quality API, only useful if enableRayTracing is true.
    {  
        bool enableRayTracing = false;  ///< Enables/disables ray tracing
        enum class ImageQualityPreset   ///< Sets the quality of the rendering. At the moment (23/05/2019) only the number of iterations for each frame
        {  
            LOW,      ///< 16 iterations
            MEDIUM,   ///< 128 iterations
            HIGH      ///< 2048 iterations
        } imageQualityPreset = ImageQualityPreset::LOW;
        unsigned int maxTimePerFrameInSeconds = 0;  ///< Timeout parameter for each frame, if set to 0 no timeout is set
        bool enableDenoiser = false;  ///< Enables/disables denoising
        bool useGPU = true;
        [[deprecated("Use VisVideoShooter::Parameters::forcedFPSvalue")]]
        float forcedFPSvalue = 0;  // Deprecated. Use VisVideoShooter::Parameters::forcedFPSvalue
    } rayTracingSettings;
  };

  /** Construct the objects with all the parameters. */
	VisVideoShooter(const Parameters & iParameters);

  ~VisVideoShooter();

  /** Used to shoot a single new frame. We use the support set in the parameters.
    * So, tou have to move the viewpoint of that support to see a difference.
    * You have to compute camera/animations with the right framerate you asked.
    */
  void ShootFrame();

  /** Use all previously shot frames to generate a video.
   *  @param iSignal If set to NULL, the video generation will be blocking. If you set an Event, the video generation
   *                 is asynchronous. iSignal will be signaled when video generation is complete.
   */
  void GenerateVideo(CATEvent * iSignal = NULL);

  /** Set compositing data for VideoShooter implementation.
   *  Returns E_FAIL if the VideoShooter implementation could not be instanciated.
   *  @param data The input data for rasterizer compositing
  */
  HRESULT SetRasterizerCompositingLayers(const std::vector<CAT2DViewpoint*> &layers);

  /** Set compositing data for VideoShooter implementation.
      *Returns E_FAIL if the VideoShooter implementation could not be instanciated.
   *  @param data The input data for manual compositing
  */
  HRESULT SetManualCompositingLayers(const std::vector<ManualCompositingLayer> &layers);

private :	

  VisVideoShooterImpl * m_impl;

};

#endif //VISVIDEOSHOOTER_H_
