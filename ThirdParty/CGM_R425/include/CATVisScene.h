#ifndef CATVisScene_H
#define CATVisScene_H

#include "SGInfra.h"

#include "CATSysErrorDef.h"

#include <list>

class CATVisSceneImpl;
class CATSceneGraphImpl;

typedef unsigned int CATVisCameraID;
typedef unsigned int CATVisAmbianceID;
typedef unsigned int CATVisActorID;
typedef unsigned int CATVisMapID;
typedef unsigned int CATVisLightID;

struct CATVisMapUsage
{
  enum Type
  {
    eNone = -1,
    eLight = 0,
    eCount
  };
};


class ExportedBySGInfra CATVisScene
{
  friend class CATSceneGraphImpl;

public:
  /*
  Gets identifiers from all registered cameras
  */
  std::list<CATVisCameraID> GetCameraIDs() const;
  /*
  Gets identifier from current active camera
  */
  CATVisCameraID GetActiveCameraID() const;
  /*
  Gets identifiers from all registered ambiances
  */
  std::list<CATVisAmbianceID> GetAmbianceIDs() const;
  /*
  Gets identifier from current active ambiance
  */
  CATVisAmbianceID GetActiveAmbianceID() const;
  /*
  Gets identifiers from all registered actors
  */
  std::list<CATVisActorID> GetActorIDs() const;
  /*
  Gets identifiers from all registered maps
  */
  std::list<CATVisMapID> GetMapIDs() const;
  /*
  Gets identifiers from all registered lights
  */
  std::list<CATVisLightID> GetLightIDs() const;

  /** @nodoc */
  CATVisSceneImpl* GetImpl() const;

private:
	CATVisScene(CATSceneGraphImpl* iSG);
	~CATVisScene(); // Not virtual: final class
  
  // Lock copy
  CATVisScene(const CATVisScene&);
  CATVisScene& operator = (const CATVisScene&);
  
  CATVisSceneImpl* m_Impl;
};

#endif
