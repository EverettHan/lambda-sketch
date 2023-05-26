#pragma once

#include "SGInfra.h"

#include "CATStdLib.h"
#include "CATBoolean.h"

#include "CATVisScene.h"
#include "CATVisActorProperties.h"
#include "CAT4x4Matrix.h"

class CATSGVisuTransactionImpl;
class CATSceneGraphImpl;
class CAT3DRep;
class CATVisCamera;
class CATVisAmbiance;
class IVisTexturePtr;
class CATVisLight;
class CATVisReflectionSystem;


class ExportedBySGInfra CATSGVisuSceneTransaction
{
public:
  /** @return TRUE if the given iCameraID is valid */
  CATBoolean IsValidCameraID(const CATVisCameraID& iCameraID) const;

  /*
  Registers a camera into the scene.
  The returned ID can be checked with "IsValidCameraID" to see if the camera registration succeeded.
  */
  CATVisCameraID RegisterCamera(CATVisCamera* iCamera);
  /*
  Unregister a camera from the scene.
  */
  HRESULT UnregisterCamera(const CATVisCameraID& iCameraID);

  /*
  Activates a camera.
  It will deactivate previous activated camera.
  */
  HRESULT SetActiveCamera(const CATVisCameraID& iCameraID);
  /*
  Deactivates current camera.
  */
  HRESULT DeactivateCamera();


  /** @return TRUE if the given iAmbianceID is valid */
  CATBoolean IsValidAmbianceID(const CATVisAmbianceID& iAmbianceID) const;

  /*
  Registers an ambiance into the scene.
  The returned ID can be checked with "IsValidAmbianceID" to see if the ambiance registration succeeded.
  */
  CATVisAmbianceID RegisterAmbiance(CATVisAmbiance* iAmbiance);
  /*
  Unregister an ambiance from the scene.
  */
  HRESULT UnregisterAmbiance(const CATVisAmbianceID& iAmbianceID);

  /*
  Activates an ambiance.
  It will deactivate previous activated ambiance.
  */
  HRESULT SetActiveAmbiance(const CATVisAmbianceID& iAmbianceID);
  /*
  Deactivates current ambiance.
  */
  HRESULT DeactivateAmbiance();


  /** @return TRUE if the given iActorID is valid */
  CATBoolean IsValidActorID(const CATVisActorID& iActorID) const;

  /*
  Creates a new actor and add it to the scene.
  The returned ID can be checked with "IsValidActorID" to see if the actor creation succeeded.
  */
  CATVisActorID RegisterActor(CAT3DRep* iGeom);

  /*
  Creates a new actor according to a PhysicalID and add it to the scene.
  The returned ID can be checked with "IsValidActorID" to see if the actor creation succeeded.
  */
  CATVisActorID RegisterActor(const CATUnicodeString& iPhysicalID);
  
  /*
  Creates a new actor according to a PhysicalID and add it to the scene.
  The returned ID can be checked with "IsValidActorID" to see if the actor creation succeeded.
  */
  CATVisActorID RegisterActor(CAT3DRep* iGeom, const CATUnicodeString& iPhysicalID);

  /*
  Removes an actor from the scene and deletes it.
  */
  HRESULT UnregisterActor(const CATVisActorID& iActorID);

  /*
  Sets properties for an actor.
  */
  HRESULT SetActorProperties(const CATVisActorID& iActorID, const CATVisActorProperties& iProperties);
  /*
  Gets properties from an actor.
  */
  HRESULT GetActorProperties(const CATVisActorID& iActorID, CATVisActorProperties& oProperties);

  /*
  Attaches an actor to another actor.
  An actor can only have one parent and there cannot be cycles.
  */
  HRESULT AttachActor(const CATVisActorID& iActorID, const CATVisActorID& iParentActorID);
  /*
  Detaches an actor from its parent.
  */
  HRESULT DetachActor(const CATVisActorID& iActorID);

  /*
  Sets a transformation (position, rotation and scaling) on an actor.
  If the actor is not attached to another one, the transformation is global (otherwise, it's local).
  WARNING: Avoid non-uniform scaling!
  */
  HRESULT SetActorTransform(const CATVisActorID& iActorID, const CAT4x4Matrix& iMatrix);
  /*
  Gets an actor transformation matrix.
  */
  HRESULT GetActorTransform(const CATVisActorID& iActorID, CAT4x4Matrix& oMatrix);


  /** @return TRUE if the given iMapID is valid */
  CATBoolean IsValidMapID(const CATVisMapID& iMapID) const;

  /*
  Registers a texture as a map into the scene.
  The returned ID can be checked with "IsValidMapID" to see if the map registration succeeded.
  */
  CATVisMapID RegisterMap(const IVisTexturePtr &iTexture, const CATVisMapUsage::Type& iUsage);
  /*
  Unregister a map from the scene.
  */
  HRESULT UnregisterMap(const CATVisMapID& iMapID);

  /*
  Attaches a map to an actor.
  The map usage will determine how it must be applied to the actor's materials.
  */
  HRESULT AttachMap(const CATVisActorID& iActorID, const CATVisMapID& iMapID);
  /*
  Detaches a map from an actor.
  */
  HRESULT DetachMap(const CATVisActorID& iActorID, const CATVisMapID& iMapID);


  /** @return TRUE if the given iLightID is valid */
  CATBoolean IsValidLightID(const CATVisLightID& iLightID) const;

  /*
  Registers a light into the scene.
  The returned ID can be checked with "IsValidLightID" to see if the light registration succeeded.
  */
  CATVisLightID RegisterLight(CATVisLight* iLight);
  /*
  Unregister a light from the scene.
  */
  HRESULT UnregisterLight(const CATVisLightID& iLightID);

  /*
  Attaches a light to an actor.
  If the actor is not visible, the light will be disabled.
  */
  HRESULT AttachLightToActor(const CATVisLightID& iLightID, const CATVisActorID& iParentActorID);
  /*
  Attaches a light to a camera.
  If the camera is not active, the light will be disabled.
  */
  //HRESULT AttachLightToCamera(const CATVisLightID& iLightID, const CATVisCameraID& iParentCameraID);
  /*
  Detaches a light from its parent.
  */
  HRESULT DetachLight(const CATVisLightID& iLightID);


  /*
  Attaches a reflection system to the scene, there can only be one reflection system on a scene.
  If the reflection system is not manually detached from the scene, scene will hold its lifecycle.
  */
  //HRESULT AttachReflectionSystem(CATVisReflectionSystem* iSystem);
  /*
  Detaches the current scene reflection system.
  This call will release the scene lifecycle hold on the reflection system, it should be destroyed by the user.
  */
  //HRESULT DetachReflectionSystem();

  CAT3DRep* GetRepFromID(CATVisActorID iActorID);
  CATUnicodeString GetPhysicalID(CATVisActorID iActorID);

private:
	// all ctor/dtor are private: this cannot be instantiated by anything but a CATSGVisuTransactionImpl
  CATSGVisuSceneTransaction();
  CATSGVisuSceneTransaction(CATSceneGraphImpl * iSG, CATVisSceneImpl * iScene);
  CATSGVisuSceneTransaction(const CATSGVisuSceneTransaction &);
	virtual ~CATSGVisuSceneTransaction();

	friend class CATSGVisuTransactionImpl;

  CATSceneGraphImpl* _SceneGraph;
  CATVisSceneImpl* _SceneImpl;
};
