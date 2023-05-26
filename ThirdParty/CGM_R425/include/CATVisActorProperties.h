#ifndef CATVisActorProperties_H
#define CATVisActorProperties_H

#include "SGInfra.h"

#include "CATDataType.h"
#include "CATMathOBB.h"
#include "CATMaterialApplicationOperations.h"


/** @class This class describes an actor properties.
 *  It can be set on an actor from the visualization scene through CATSGVisuSceneTransaction.
 *  @see CATSceneGraph, CATSGVisuSceneTransaction
 *  @warning This is only managed by NRE.
 */
class ExportedBySGInfra CATVisActorProperties
{
  friend class CATVisActor;

public:

  CATVisActorProperties();
  ~CATVisActorProperties();
  CATVisActorProperties(const CATVisActorProperties& iSrc);
  CATVisActorProperties& operator=(const CATVisActorProperties& iSrc);

  enum EGeometryMode
  {
    eStatic,  // The geometry won't be edited and the actor won't move.
    eMovable, // The geometry won't be edited and the actor could move.
    eDynamic  // The geometry could be edited and the actor could move.
  };

  /** Sets the actor geometry mode
   *  The geometry mode will be used to determine some optimizations.
   *  Declared geometry mode is a user commitment, we do not guaranty wrong actions will be checked.
   *  @warning: If actions which go against the geometry mode are performed, it could lead to visual bugs!
   *  @param iMode The geometry mode
   */
  void SetGeometryMode(const EGeometryMode iMode);
  /** Gets the actor geometry mode
   *  @return The geometry mode
   */
  const EGeometryMode GetGeometryMode() const;

  /** Creates a material application which will override all actor's materials and return it
   *  If there was already an available material override, simply gets it
   *  @return the created or available material override
   */
  CATMaterialApplicationOperations::ApplicationId CreateOrGetMaterialOverride();
  /** Gets the material override available on those properties
   *  @return the available material override (or null if it's not available)
   */
  CATMaterialApplicationOperations::ApplicationId GetMaterialOverride() const;
  /** Removes currently available material override
   *  @return true if there was an available material override
   */
  bool RemoveMaterialOverride();

  /** Sets specific IBL parameters for the actor 
   *  @param iParams The IBL parameters
   */
  void SetIBLParameters(const CATMaterialIBLParameters* iParams);
  /** Gets actor's specific IBL parameters
   *  @return the IBL parameters
   */
  const CATMaterialIBLParameters* GetIBLParameters() const;

  /** Sets actor's visibility
   *  @param iSet The visibility
   */
  void SetVisible(bool iSet);
  /** Gets actor's visibility
   *  @return the visibility
   */
  bool IsVisible() const;

  /** Activates lights from a specific channel to illuminate this object
   *  There is a maximum of 7 supported channels.
   *  @param iChannelIndex The channel index (from 1 to 7)
   *  @return true if the light can be activated for asked channel
   */
  bool ActivateOnLightChannel(const unsigned int iChannelIndex);
  /** Deactivates lights from a specific channel (they won't illuminate this object)
   *  There is a maximum of 8 supported channels.
   *  @param iChannelIndex The channel index (from 1 to 7)
   *  @return true if the light can be deactivated for asked channel
   */
  bool DeactivateOnLightChannel(const unsigned int iChannelIndex);
  /** Deactivates all channels lighting for this object
   *  By default, this object is lighted by all channels.
   */
  void DeactivateOnAllLightChannels();
  /** Sets channels which lights this object
   *  There is a maximum of 8 supported channels which are given through the 8 first bits of iChannels.
   *  @param iChannels The channels list (by flags field)
   */
  void SetLightChannels(const CATULONG32 iChannels);
  /** Gets channels which lights this object
   *  @return The channels list (by flags field)
   */
  const CATULONG32 GetLightChannels() const;

  static const unsigned int kLightChannelsCount;
  static const CATULONG32 kAllLightChannels;

  /** Sets modes for shadow cast/receive
   *  @param iCaster The object can cast shadows
   *  @param iReceiver The object can receive shadows
   */
  void SetShadowMode(bool iCaster, bool iReceiver);
  /** Gets the shadow cast mode
   *  @return true if the object can cast shadows
   */
  bool IsShadowCaster() const;
  /** Gets the shadow receive mode
   *  @return true if the object can receive shadows
   */
  bool IsShadowReceiver() const;

  /** Sets modes for reflection cast/receive
   *  @param iCaster The object can cast shadows
   *  @param iReceiver The object can receive shadows
   */
  void SetReflectionMode(bool iCaster, bool iReceiver);
  /** Gets the reflection cast mode
   *  @return true if the object can cast reflections
   */
  bool IsReflectionCaster() const;
  /** Gets the reflection receive mode
   *  @return true if the object can receive reflections
   */
  bool IsReflectionReceiver() const;

private:
  static const CATULONG32 kLegacyLightChannel;
  static const CATULONG32 kInternalAllLightChannels;

  enum FFlags
  {
    fVisible = (1 << 0),
    fFastPicking = (1 << 1),
    fCastShadows = (1 << 2),
    fReceiveShadows = (1 << 3),
    fCastReflections = (1 << 4),
    fReceiveReflections = (1 << 5)
  };

  CATMaterialApplication* m_MatApp;
  const CATMaterialIBLParameters* m_IBL;
  CATMathOBB    m_BoundingBox;
  EGeometryMode m_GeomMode;
  unsigned int  m_Flags;
  CATULONG32    m_LightChannels;
};

#endif
