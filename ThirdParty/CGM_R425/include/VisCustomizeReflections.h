#ifndef VISCUSTOMIZEREFLECTIONS
#define VISCUSTOMIZEREFLECTIONS

#include "SGInfra.h"

class CATVisSSRData;

class ExportedBySGInfra VisCustomizeReflections
{
public :
  struct Quality
  {
    enum Mode
    {
      eLow,
      eHigh,
      ePreserve
    };
  };

  /** The function changes the screen space reflection presets.
   *  Calling this method with the quality "ePreserve" is pointless.
   *  @param iData the screen space reflection parameters to modify
   *  @param iQualityMode sets the quality for screen space reflections
   */
  static void CustomizeScreenSpaceReflectionsQuality(CATVisSSRData& ioData, Quality::Mode iQualityMode);

  /** The function changes the screen space reflection presets.
   *  @param iData the screen space reflection parameters to modify
   *  @param iUseOnGround enables or disables reflections on the ground
   *  @param iUseOnObjects enables or disables reflections on opaque objects (transparent objects are currently ignored)
   */
  static void CustomizeScreenSpaceReflectionsApplication(CATVisSSRData& ioData, bool iUseOnGround, bool iUseOnObjects);

  /** The function changes the screen space reflection presets by degrading them.
   *  @param iData the screen space reflection parameters to modify
   *  @param iQualityMode sets the quality for screen space reflections
   *  @param iUseOnGround enables or disables reflections on the ground
   *  @param iUseOnObjects enables or disables reflections on opaque objects (transparent objects are currently ignored)
   */
  static void DegradeScreenSpaceReflections(CATVisSSRData& ioData, Quality::Mode iQualityMode = Quality::eLow, bool iUseOnGround = false, bool iUseOnObjects = false);
};

#endif //VISCUSTOMIZEREFLECTIONS
