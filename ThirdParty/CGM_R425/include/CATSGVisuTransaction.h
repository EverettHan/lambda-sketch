#pragma once

#include "SGInfra.h"

#include "CATSGTransaction.h"
#include "CATStdLib.h"
#include "CATBoolean.h"

// Rep API
class CATSGVisuRepTransaction;
class CATRep;

// Scene API
class CATSGVisuSceneTransaction;

// To remove once migration done
#include "CATVisScene.h"
#include "CATVisActorProperties.h"
#include "CAT4x4Matrix.h"
class CAT3DRep;

class CATSceneGraphImpl;
class CATSGVisuTransactionImpl;


class ExportedBySGInfra CATSGVisuTransaction : public CATSGTransaction
{
public:

  /* *****************************************************************
  REP API
  ***************************************************************** */

  /**
  Creates a sub transaction to access to visualization properties on representations
  */
  HRESULT	CreateRepTransaction(CATSGVisuRepTransaction *& oTrx, CATRep* iRep = NULL);

  /**
  Destroy a sub transaction which allow access to visualization properties on representations
  */
  HRESULT CloseRepTransaction(CATSGVisuRepTransaction *& oTrx);


  /* *****************************************************************
  SCENE API
  ***************************************************************** */

  /**
  Creates a sub transaction to access to visualization scene
  */
  HRESULT	CreateSceneTransaction(CATSGVisuSceneTransaction *& oTrx);

  /**
  Destroy a sub transaction which allow access to visualization scene
  */
  HRESULT CloseSceneTransaction(CATSGVisuSceneTransaction *& oTrx);


  /* *****************************************************************
  SCENE API DEPRECATED
  ***************************************************************** */

  /** @return TRUE if the given iActorID is valid */
  CATBoolean IsValidActorID(const CATVisActorID& iActorID) const;

  /*
  Creates a new actor and add it to the scene.
  The returned ID can be checked with "IsValidActorID" to see if the actor creation succeeded.
  */
  CATVisActorID RegisterActor(CAT3DRep* iGeom);
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

private:
	// all ctor/dtor are private: this cannot be instantiated by anything but a CATSceneGraphImpl
  CATSGVisuTransaction();
  CATSGVisuTransaction(CATSceneGraphImpl * iSG);
  CATSGVisuTransaction(const CATSGVisuTransaction &);
	virtual ~CATSGVisuTransaction();

	friend class CATSceneGraphImpl;

  CATSGVisuTransactionImpl* _Impl;
};
