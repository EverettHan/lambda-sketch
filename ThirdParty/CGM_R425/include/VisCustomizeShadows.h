#ifndef VISCUSTOMIZESHADOWS
#define VISCUSTOMIZESHADOWS

#include "SGInfra.h"

class CATSupport;

class ExportedBySGInfra VisCustomizeShadows
{

public :

  struct Filtering
  {
    enum Mode
    {
      ePCF,
      eESM,
      ePCSS
    };
  };

  struct Quality
  {
    enum Mode
    {
      eLow,
      eMedium,
      eHigh,
      eUltra
    };
  };


  struct Split
  {
    enum Mode
    {
      eUniform,
      eLog,
      ePractical,
      eManual
    };
  };

  struct Occluder
  {
    enum Mode
    {
      eBoundToScene,
      eExtendedFrustum
    };
  };


  /** This is an advanced function. It is a very dangerous function, please contact visualization team before calling this function.
   *  The function changes the shadows quality. It overloads ALL shadows settings.
   *  The function can be used to change shadow filtering and/or bias. 
   *  @deprecated Do not use this function, use CustomizeShadowFiltering and CustomizeShadowBias.
   *  @param iSupport the support to modify the shadows preset.
   *  @param iFilteringMode is the new filtering algorithm.
   *  @param iQualityMode sets the quality for the filtering. Do not influence shadow map size.
   *  @param iUseAdvancedBias enables or disables the use of GPU bias. Only have impact for PCF and PCSS.
   *  @param iFixedBias sets the bias. Only have impact for PCF and PCSS.
   */
  static void CustomizeShadows(CATSupport * iSupport, Filtering::Mode iFilteringMode, Quality::Mode iQualityMode, bool iUseAdvancedBias = true, float iFixedBias = 0.0f);

  /** This is an advanced function. It is a very dangerous function, please contact visualization team before calling this function.
   *  The function changes the shadows quality. It overloads ALL shadows settings.
   *  The function can be used to change shadow filtering. 
   *  @param iSupport the support to modify the shadows preset.
   *  @param iFilteringMode is the new filtering algorithm.
   *  @param iQualityMode sets the quality for the filtering. Do not influence shadow map size.
   */
  static void CustomizeShadowFiltering(CATSupport * iSupport, Filtering::Mode iFilteringMode, Quality::Mode iQualityMode);

  /** This is an advanced function. It is a very dangerous function, please contact visualization team before calling this function.
   *  The function changes the shadows quality. It overloads ALL shadows settings.
   *  The function can be used to change shadow bias. 
   *  Each algorithm has his own bias, that's why you need to specify the filtering mode. But it doesn't change the filtering mode just the bias for that mode !
   *  @param iSupport the support to modify the shadows preset.
   *  @param iFilteringMode is the filtering algorithm you want to change bias. Do not change the filtering technique used.
   *  @param iUseAdvancedBias enables or disables the use of GPU bias. Only have impact for PCF and PCSS.
   *  @param iFixedBias sets the bias. Only have impact for PCF and PCSS.
   */
  static void CustomizeShadowBias(CATSupport * iSupport, Filtering::Mode iFilteringMode, bool iUseAdvancedBias, float iBiasPerCascade[8]);

  /** This is an advanced function. It is a very dangerous function, please contact visualization team before calling this function.
   *  Only apply for PCF filtering.
   *  If the optimized mode is used, not all the Filtering::Mode iFilteringMode is used.
   *  @param iSupport the support to modify the shadows preset.
   *  @param iUseOptimizedPCF if set to true, we switch to the optimized mode else with use a normal version (box sampling).
   */
  static void CustomizePCF(CATSupport * iSupport, bool iUseOptimizedPCF);

  /** This is an advanced function. It is a very dangerous function, please contact visualization team before calling this function.
   *  The function changes the cascaded shadows parameters.
   *  @param iSupport the support to modify the shadows preset.
   *  @param iNbCascade is the number of cascade. Must be between 1 and 8.
   *  @param iMaxFarDistance is the max distance of the view frustum used to compute light split.
   *  @param iFadeLastCascadeCoef is a percentage that tells when the fading start in the last cascade. The coef must be between 0 and 100. 0 disable the feature. The fading is linear after the starting point.
   */
  static void CustomizeCascade(CATSupport * iSupport, unsigned int iNbCascade, float iMaxFarDistance = 1e6f, unsigned int iFadeLastCascadeCoef = 0);

  /** This is an advanced function. It is a very dangerous function, please contact visualization team before calling this function.
  *   The function changes the cascaded shadows split parameters.
  *   @param iSupport the support to modify the shadows preset.
  *   @param iSplitMode The Split mode.
  *   @param iPracticalFactor is only used in case of practical split mode. The falue must be between 0 and 1.
  */
  static void CustomizeCascadeSplit(CATSupport * iSupport, Split::Mode iSplitMode, float iPracticalFactor = 0.8f);

  /** This is an advanced function. It is a very dangerous function, please contact visualization team before calling this function.
  *   The function fix the split position for the cascades. The splitMode must be set to eManual to have an effect (set it with CustomizeCascadeSplit)
  *   @param iSupport the support to modify the shadows preset.
  *   @param iManualSplit distance for the split position.
  */
  static void CustomizeCascadeManualSplit(CATSupport * iSupport, float iManualSplit[8]);

  /** This is an advanced function. It is a very dangerous function, please contact visualization team before calling this function.
  *   The function modifies the Occluder detection.
  *   @param iSupport the support to modify the shadows preset.
  *   @param iOccluderMode The occluder mode.
  *   @param iExtendedFactor is only used in case of eExtendedFrustum mode. The factor is multiplied with the (far-near) distance of the split to extend this frustum.
  */
  static void CustomizeCascadeExtendedFrustum(CATSupport * iSupport, Occluder::Mode iOccluderMode, float iExtendedFactor[8]);

};




#endif //VISCUSTOMIZESHADOWS
